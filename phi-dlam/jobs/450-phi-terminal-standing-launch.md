<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PHI TERMINAL STANDING LAUNCH 450 - THE TERMINAL STANDS BY THE LANE HAND, NEVER HIS (Ground corrected by Tyree, 2026-10-28: he does not use exes, and his Cyberpunk is the Xbox digital edition, a package that runs through the Xbox app under its package identity, the same identity his saves and the Vortex door already honor. The terminal as placed by job 437 waited for him to launch an exe by hand, which is not his road, so Tab had nothing to answer with. The fix is the lane own shape: this job starts the terminal itself, detached, in his session, so it simply stands running on his PC with its keyboard hook seated, and Tab is live whenever the game opens, today and every session after, with no exe in his hands at any point. One, the job checks whether the terminal process already stands and does not double launch it. Two, if it does not stand, the job starts it with Start-Process from its standing folder and waits three seconds. Three, it verifies the process stands and prints its pid. Four, it prints the tail of the terminal log, capped at 20 lines, so the hook seat stands read in the terminal own words. The verdict in one line: TERMINAL STANDS with the pid or the already standing state. Every variable carries the pt450 prefix.) ==='
$pt450folder = 'C:\Users\Admin\PhiTerminal2077'
$pt450exe = Join-Path $pt450folder 'PhiTerminal2077.exe'
$pt450existing = @(Get-Process -Name 'PhiTerminal2077' -ErrorAction SilentlyContinue)
$pt450state = 'ABSENT'
$pt450pid = 0
if ($pt450existing.Count -gt 0) { $pt450state = 'ALREADY'; $pt450pid = $pt450existing[0].Id }
elseif (Test-Path $pt450exe) {
  $pt450proc = Start-Process -FilePath $pt450exe -WorkingDirectory $pt450folder -PassThru
  Start-Sleep -Seconds 3
  $pt450check = Get-Process -Id $pt450proc.Id -ErrorAction SilentlyContinue
  if ($pt450check) { $pt450state = 'LAUNCHED'; $pt450pid = $pt450proc.Id } else { $pt450state = 'EXITED' }
} else { $pt450state = 'EXE-MISSING' }
Write-Output ('TERMINAL STATE=' + $pt450state + ' pid=' + $pt450pid)
$pt450log = Join-Path $pt450folder 'phi_terminal.log'
if (Test-Path $pt450log) { Get-Content $pt450log -Tail 20 | ForEach-Object { Write-Output ('TLOG ' + $_) } } else { Write-Output 'TLOG: log absent' }
Write-Output ('PHI PT450 VERDICT: TERMINAL STANDS state=' + $pt450state + ' pid=' + $pt450pid)
Write-Output 'JOB 450 DONE'
```
