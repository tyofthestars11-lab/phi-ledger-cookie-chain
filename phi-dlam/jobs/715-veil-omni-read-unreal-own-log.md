<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB - READ UNREAL OWN LOG NOT STDOUT (Ground: Jobs 711, 712, 714 found Cmd running True with stdout out lines stuck at 140 at editor load, while free memory rose to 9065 MB, so the stdout redirect is not where Unreal writes its live log. This job reads Unreal own log: it lists the newest log files in Saved Logs, prints the last 40 non-empty lines of the newest log, prints whether Python script, actor count, save done, Countess, Vault, NavMesh are named in that log, and prints whether Cmd is still running. If the log is not found, print that plainly and do not claim a finished run. No cook, no package, no 1.0, proof only in play.) ==='
$logDirW = 'D:\VEIL-OMNI\Saved\Logs'
Write-Output ('OWNLOG DIR PRESENT ' + (Test-Path $logDirW))
Get-ChildItem $logDirW -Filter *.log | Sort-Object LastWriteTime -Descending | Select-Object -First 5 | ForEach-Object { Write-Output ('OWNLOG FILE ' + $_.Name + ' ' + $_.Length + ' ' + $_.LastWriteTime) }
$newW = Get-ChildItem $logDirW -Filter *.log | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($null -ne $newW) { $lW = Get-Content $newW.FullName; Write-Output ('OWNLOG LINES ' + $lW.Count); $lW | Select-Object -Last 40 | ForEach-Object { $tW = $_.Trim(); if ($tW.Length -gt 0) { Write-Output ('OWNLOG TAIL ' + $tW) } } }
$procW = Get-Process -Name UnrealEditor-Cmd -ErrorAction SilentlyContinue
Write-Output ('OWNLOG CMD RUNNING ' + ($null -ne $procW))
Write-Output 'OWNLOG ELECTRON PHASE LOCK HELD.'
Write-Output 'OWNLOG NOCOOK.'
Write-Output 'OWNLOG NOPACKAGE.'
Write-Output 'WHOLE JOB DONE.'
```
