#!/usr/bin/env python3
"""LUCAS STABILIZER (TYREE, 2026-10-28) - the filing gate in Lucas form.

Lucas numbers L_n = phi^n + psi^n are the integer shadow of the phi ladder:
irrational rungs, exact integer landings. The stabilizer holds every queued
job to that form before it ships - exact integer checks only, nothing
approximate, nothing drifting:

  1. pure ASCII (byte-exact)
  2. header single-quote count == 2 (exact integer)
  3. no cross-language leaks (raw-string prefixes, stale tokens, __B64)
  4. the REAL PowerShell parser accepts the body (validate-job.ps1, pwsh)
  5. Lucas address of the job number printed beside the verdict

A job prints STABLE only when every integer check lands. Anything else
prints UNSTABLE with the failing check named - and does not ship.
"""
import re, subprocess, sys, os

PWSH = os.path.expanduser('~/workspace/tools/pwsh/pwsh')
VALIDATOR = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'validate-job.ps1')

def lucas(n):
    a, b = 2, 1
    for _ in range(n):
        a, b = b, a + b
    return a

def check(path):
    raw = open(path, 'rb').read()
    fails = []
    try:
        text = raw.decode('ascii')
    except UnicodeDecodeError:
        text = raw.decode('utf-8', 'replace')
        fails.append('non-ascii')
    hdr = [l for l in text.splitlines() if l.startswith("Write-Output '===")]
    if not hdr or hdr[0].count("'") != 2:
        fails.append('header-quotes!=%d' % (hdr[0].count("'") if hdr else -1))
    if '__B64' in text:
        fails.append('unsubstituted-token')
    if 'r"' in text or "r'" in text:
        fails.append('raw-string-leak')
    r = subprocess.run([PWSH, '-NoProfile', '-File', VALIDATOR, path],
                       capture_output=True, text=True)
    parse_ok = r.stdout.startswith('PARSE OK')
    if not parse_ok:
        fails.append('powershell-parse')
    m = re.match(r'(\d+)-', os.path.basename(path))
    num = int(m.group(1)) if m else 0
    verdict = 'STABLE' if not fails else 'UNSTABLE(' + ','.join(fails) + ')'
    print('%s job=%d lucas_addr=L%d=%d bytes=%d %s' % (
        verdict, num, num, lucas(num), len(raw), os.path.basename(path)))
    if not parse_ok:
        print(r.stdout.strip())
    return not fails

if __name__ == '__main__':
    ok = all([check(p) for p in sys.argv[1:]])
    sys.exit(0 if ok else 1)
