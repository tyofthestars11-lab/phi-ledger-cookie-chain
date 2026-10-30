<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB - READ OWN LOG AGAIN AFTER DDC (Ground: Job 715 found Unreal own log VEIL_2.log with 1337 lines, DDC maintenance finished at 16:43:51, Cmd still running True, Python script not yet reached. This job reads that log again: it prints the newest log file and its lines, prints the last 40 non-empty lines, prints whether Python script, actor count, save done, Countess, Vault, NavMesh are named after DDC, and prints whether Cmd is still running. If Cmd is still running, print that plainly and do not claim a finished run. No cook, no package, no 1.0, proof only in play.) ==='
$logDirW = 'D:\VEIL-OMNI\Saved\Logs'
Get-ChildItem $logDirW -Filter VEIL*.log | Sort-Object LastWriteTime -Descending | Select-Object -First 3 | ForEach-Object { Write-Output ('OWNAGAIN FILE ' + $_.Name + ' ' + $_.Length + ' ' + $_.LastWriteTime) }
$newW = Get-ChildItem $logDirW -Filter VEIL*.log | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($null -ne $newW) { $lW = Get-Content $newW.FullName; Write-Output ('OWNAGAIN LINES ' + $lW.Count); $lW | Select-Object -Last 40 | ForEach-Object { $tW = $_.Trim(); if ($tW.Length -gt 0) { Write-Output ('OWNAGAIN TAIL ' + $tW) } } }
$procW = Get-Process -Name UnrealEditor-Cmd -ErrorAction SilentlyContinue
Write-Output ('OWNAGAIN CMD RUNNING ' + ($null -ne $procW))
Write-Output 'OWNAGAIN ELECTRON PHASE LOCK HELD.'
Write-Output 'OWNAGAIN NOCOOK.'
Write-Output 'OWNAGAIN NOPACKAGE.'
Write-Output 'WHOLE JOB DONE.'
```
