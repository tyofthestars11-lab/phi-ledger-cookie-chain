<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB - CHECK CMD PROCESS STATE (Ground: Jobs 715 and 716 found Unreal own log VEIL_2.log stuck at 1337 lines with last timestamp 16:43:51 DDC finished, Cmd running True, no new lines for minutes, Python script not yet reached. This job checks the Cmd process itself: it prints Cmd process id, CPU time, working set MB, start time, and prints the newest Saved Logs files with times, so we know if Cmd is working, idle, or stalled. If Cmd is gone, print that plainly. No kill, no package, no 1.0, proof only in play.) ==='
Get-Process -Name UnrealEditor-Cmd -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMDPROC ID ' + $_.Id); Write-Output ('CMDPROC CPU ' + $_.CPU); Write-Output ('CMDPROC WS MB ' + [int]($_.WorkingSet / 1MB)); Write-Output ('CMDPROC START ' + $_.StartTime) }
if ($null -eq (Get-Process -Name UnrealEditor-Cmd -ErrorAction SilentlyContinue)) { Write-Output 'CMDPROC NONE RUNNING.' }
Get-ChildItem 'D:\VEIL-OMNI\Saved\Logs' -Filter *.log | Sort-Object LastWriteTime -Descending | Select-Object -First 5 | ForEach-Object { Write-Output ('CMDPROC LOGFILE ' + $_.Name + ' ' + $_.Length + ' ' + $_.LastWriteTime) }
Write-Output 'CMDPROC ELECTRON PHASE LOCK HELD.'
Write-Output 'CMDPROC NOCOOK.'
Write-Output 'CMDPROC NOPACKAGE.'
Write-Output 'WHOLE JOB DONE.'
```
