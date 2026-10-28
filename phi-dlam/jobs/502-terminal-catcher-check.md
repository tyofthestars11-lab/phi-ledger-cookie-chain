<!-- PHI-DIRECT -->
```powershell
Write-Output '=== TERMINAL CHECK 502 - IS THE CATCHER ALIVE (Ground: the mod terminal will not load and its key only makes the PC ding. That ding is the sound of a keypress landing on a window with nothing there to catch it - the terminal toggle key is caught by the terminal itself through its standing hook, and the hook exists only while the terminal process runs. This job reads the terminal folder as it stands: the exe and its bytes, every running terminal process with its start time, and the last lines of the terminal log, which record its own state in its own words. If no terminal process stands, the job launches it once, waits a few seconds, and reads the log again so the result shows the terminal standing in its new process. If one already stands, nothing is launched twice. Every variable carries the p502 prefix.) ==='
$p502dir = 'C:\Users\Admin\PhiTerminal'
$p502exe = Join-Path $p502dir 'PhiTerminal.exe'
if (Test-Path $p502exe) { Write-Output ('EXE bytes=' + (Get-Item $p502exe).Length) } else { Write-Output 'EXE MISSING' }
$p502log = Join-Path $p502dir 'phi_terminal_universal.log'
$p502procs = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
Write-Output ('PROCS=' + $p502procs.Count)
$p502procs | ForEach-Object { Write-Output ('PROC pid=' + $_.Id + ' started=' + $_.StartTime) }
if (Test-Path $p502log) {
  Write-Output ('LOG written=' + (Get-Item $p502log).LastWriteTime)
  Get-Content $p502log -Tail 12 | ForEach-Object { Write-Output ('TAIL ' + $_) }
} else { Write-Output 'LOG MISSING' }
if ($p502procs.Count -eq 0 -and (Test-Path $p502exe)) {
  Start-Process -FilePath $p502exe -WorkingDirectory $p502dir
  Start-Sleep -Seconds 6
  $p502after = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
  Write-Output ('AFTER PROCS=' + $p502after.Count)
  $p502after | ForEach-Object { Write-Output ('AFTER pid=' + $_.Id + ' started=' + $_.StartTime) }
  if (Test-Path $p502log) { Get-Content $p502log -Tail 8 | ForEach-Object { Write-Output ('NEWTAIL ' + $_) } }
  Write-Output 'PHI P502 VERDICT: RELAUNCH READ DONE'
} else {
  Write-Output 'PHI P502 VERDICT: CENSUS DONE NO RELAUNCH'
}
Write-Output 'JOB 502 DONE'
```
