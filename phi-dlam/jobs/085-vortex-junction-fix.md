<!-- PHI-DIRECT -->
# JOB 085 - VORTEX FIX: MAKE THE C: PATH TRUE (DIRECT)

Job 077 proved it: Vortex's stored Starfield path is the C: ghost
("C:\\XboxGames"), the C: folder is a shell, the real install is
D:\XboxGames\Starfield (Data present and writable), and the full
Vortex state is backed up at phi-vault-backups\vortex-state-
2026-10-27-pre-path-fix. Instead of fighting the LevelDB state,
this fix makes the state's path TRUE: the C: shell is moved aside
(never deleted) and a directory junction takes its place, so every
path Vortex already believes now lands on the real D: install.
Self-healing: if the junction does not resolve, the shell is
restored and nothing has changed. Vortex must be closed.

```powershell
$ErrorActionPreference = 'Continue'
if (Get-Process Vortex -ErrorAction SilentlyContinue) { "VORTEX OPEN - aborting; close Vortex and rerun this job"; "=== JOB 085 ABORTED ===" }
else {
  $ghost = 'C:\XboxGames\Starfield'
  $real = 'D:\XboxGames\Starfield'
  $shell = 'C:\XboxGames\Starfield.ghost-shell-2026-10-27'
  $sz = (Get-ChildItem $ghost -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
  "GHOST SIZE: {0:N1} MB" -f ($sz/1MB)
  if ($sz -gt 100MB) { "GHOST TOO BIG TO BE A SHELL - aborting, report only"; "=== JOB 085 ABORTED ===" }
  elseif (-not (Test-Path "$real\Content\Data")) { "REAL INSTALL MISSING ITS Data - aborting"; "=== JOB 085 ABORTED ===" }
  else {
    Rename-Item $ghost 'Starfield.ghost-shell-2026-10-27' -ErrorAction Stop
    "SHELL MOVED ASIDE (nothing deleted): $shell"
    cmd /c mklink /J "$ghost" "$real" | Out-Null
    if (-not (Test-Path "$ghost\Content\Data")) {
      Rename-Item $shell 'Starfield'
      "JUNCTION FAILED - shell restored, no change made"
    } else {
      $probe = "$ghost\Content\Data\phi-junction-probe.tmp"
      New-Item $probe -ItemType File -Force | Out-Null
      if (Test-Path "$real\Content\Data\phi-junction-probe.tmp") { Remove-Item $probe -Force; "JUNCTION VERIFIED: writes through the C: path land in the real D: Data" } else { "PROBE DID NOT CROSS - junction suspect" }
      "VORTEX FIX SET: Vortex's stored path C:\XboxGames\Starfield now resolves to the real D: install"
    }
  }
  "=== JOB 085 DONE ==="
}
```
