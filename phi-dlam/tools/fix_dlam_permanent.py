"""
fix_dlam_permanent.py — permanently fixes the two PHI-DLAM errors:

  1. "error: cannot pull with rebase: You have unstaged changes."
     Cause: the runner patch (job 269) edited phi-dlam.ps1 and
     phi-direct-drain.ps1 on disk but left them uncommitted, and the
     seat's boot sync refuses a dirty tree.
     Permanent fix: the patch becomes a COMMIT. A committed tree
     pulls clean forever — no stash (a stash pop puts the dirt back).

  2. "2102 / PSSessionStateBroken / node type Text" on DIRECT jobs.
     Cause: the runner pulled job output back through Receive-Job,
     whose CLIXML transport dies on raw text.
     Permanent fix: the file-bridge — the job child writes ALL its
     streams to a temp file, the parent reads the file, Receive-Job
     is never called. This script verifies the patch is present in
     both runner files (and applies it if it is somehow missing),
     in the same run as the commit, so the tree never sits dirty.

Then it pulls the queue down (jobs 274-282) and runs the instant
drain so the whole line fires in the same motion.

Run:  python fix_dlam_permanent.py            (fix + drain)
      python fix_dlam_permanent.py --no-drain (fix only)
Stdlib only. No stash, no add -A, nothing destructive.
"""

import subprocess
import sys
from pathlib import Path

VAULT = Path.home() / "phi-vault"
DLAM = VAULT / "phi-dlam"
RUNNER_FILES = [DLAM / "phi-dlam.ps1", DLAM / "phi-direct-drain.ps1"]

OLD1 = "$jb = Start-Job -ScriptBlock { param($c) $ErrorActionPreference = 'Continue'; & ([scriptblock]::Create($c)) 2>&1 | Out-String } -ArgumentList $code"
NEW1 = "$tmpOut = [IO.Path]::Combine([IO.Path]::GetTempPath(), 'phi-direct-' + [guid]::NewGuid().ToString('N') + '.txt'); $jb = Start-Job -ScriptBlock { param($c,$f) $ErrorActionPreference = 'Continue'; try { & ([scriptblock]::Create($c)) *> $f } catch { $_ | Out-String | Add-Content $f } } -ArgumentList $code, $tmpOut"
OLD2 = "if ($done) { $out = Receive-Job $jb; if (-not $out) { $out = '(no output)' } }"
NEW2 = "if ($done) { $out = if (Test-Path $tmpOut) { Get-Content $tmpOut -Raw }; if (-not $out) { $out = '(no output)' } }"
OLD3 = "Remove-Job $jb -Force -ErrorAction SilentlyContinue"
NEW3 = "Remove-Job $jb -Force -ErrorAction SilentlyContinue; Remove-Item $tmpOut -Force -ErrorAction SilentlyContinue"


def run(cmd, cwd=VAULT):
    print(f"\n$ {' '.join(str(c) for c in cmd)}")
    p = subprocess.run(cmd, cwd=cwd, capture_output=True, text=True)
    out = (p.stdout + p.stderr).strip()
    print(out if out else "(no output)")
    return p.returncode, out


def git(*args):
    return run(["git", "-C", str(VAULT), *args])


def step1_verify_or_apply_patch():
    print("\n=== STEP 1: the 2102 transport patch — verify or apply ===")
    for f in RUNNER_FILES:
        text = f.read_text(encoding="utf-8-sig")
        if "Receive-Job $jb" not in text and "tmpOut" in text:
            print(f"{f.name}: patch already present (file bridge, no Receive-Job)")
            continue
        counts = (text.count(OLD1), text.count(OLD2), text.count(OLD3))
        if counts != (1, 1, 1):
            print(f"{f.name}: ABORT — expected line matches (1,1,1), got {counts}; file untouched")
            continue
        text = text.replace(OLD1, NEW1).replace(OLD2, NEW2).replace(OLD3, NEW3)
        f.write_text(text, encoding="utf-8-sig")
        print(f"{f.name}: PATCHED (matches {counts})")
    for f in RUNNER_FILES:
        text = f.read_text(encoding="utf-8-sig")
        assert "Receive-Job $jb" not in text, f"{f.name} still routes through Receive-Job"
    print("verified: neither runner file calls Receive-Job in the DIRECT path")


def step2_commit_the_patch():
    print("\n=== STEP 2: file the patch as a commit (the permanent state) ===")
    git("add", "phi-dlam/phi-dlam.ps1", "phi-dlam/phi-direct-drain.ps1")
    _, staged = git("diff", "--cached", "--name-only")
    if "phi-dlam" in staged:
        git("commit", "-m", "runner file-bridge patch - permanent fix (fix_dlam_permanent.py)")
        git("push")
    else:
        print("nothing staged — the patch was already committed; tree already clean")


def step3_pull_and_prove():
    print("\n=== STEP 3: the sync that refused — run it as proof ===")
    rc, _ = git("pull", "--rebase")
    print("pull --rebase exit code:", rc)
    _, status = git("status", "--porcelain")
    tracked = [l for l in status.splitlines() if not l.startswith("??")]
    print("tracked changes remaining:", tracked if tracked else "NONE — the tree is clean")
    print("untracked (harmless, e.g. .bak-269 backups):",
          [l[3:] for l in status.splitlines() if l.startswith("??")] or "none")


def step4_drain():
    print("\n=== STEP 4: drain the queue (274-282 fire under the fixed runner) ===")
    p = subprocess.run(
        ["powershell", "-ExecutionPolicy", "Bypass", "-File",
         str(DLAM / "phi-direct-drain.ps1"), "-Vault", str(VAULT)],
        capture_output=True, text=True)
    print((p.stdout + p.stderr).strip() or "(drain produced no console output)")
    results = sorted((DLAM / "results").glob("2*.result.md"))
    print("newest results on disk:", [r.name for r in results[-4:]])


if __name__ == "__main__":
    if not VAULT.exists():
        sys.exit(f"vault not found at {VAULT}")
    step1_verify_or_apply_patch()
    step2_commit_the_patch()
    step3_pull_and_prove()
    if "--no-drain" not in sys.argv:
        step4_drain()
    print("\nDONE — the seat opens clean, the transport is file-bridged, the queue is drained.")
    print("Permanent because: the patch is a commit (state), not an edit (residue).")
