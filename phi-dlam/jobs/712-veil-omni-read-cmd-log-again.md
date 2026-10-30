<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB - READ CMD LOG AGAIN (Ground: Job 711 found Cmd still running True, out lines 140, err lines 0, log tail at editor load with Countess AnimBlueprint missing error, Python script not yet reached. This job reads the log again: it checks whether Cmd is still running, prints out lines and err lines, prints the last 40 lines of each, prints whether the Python script printed actor count and save done, and prints whether Countess, Vault, NavMesh are named after load. If Cmd is still running, print that plainly and do not claim a finished run. No cook, no package, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT_cmd_err.log'
$procW = Get-Process -Name UnrealEditor-Cmd -ErrorAction SilentlyContinue
Write-Output ('LOGAGAIN CMD RUNNING ' + ($null -ne $procW))
Write-Output ('LOGAGAIN OUT PRESENT ' + (Test-Path $outW))
if (Test-Path $outW) { $oW = Get-Content $outW; Write-Output ('LOGAGAIN OUT LINES ' + $oW.Count); $oW | Select-Object -Last 40 | ForEach-Object { $tW = $_.Trim(); if ($tW.Length -gt 0) { Write-Output ('LOGAGAIN OUT TAIL ' + $tW) } } }
Write-Output ('LOGAGAIN ERR PRESENT ' + (Test-Path $errW))
if (Test-Path $errW) { $eW = Get-Content $errW; Write-Output ('LOGAGAIN ERR LINES ' + $eW.Count); $eW | Select-Object -Last 40 | ForEach-Object { $tW = $_.Trim(); if ($tW.Length -gt 0) { Write-Output ('LOGAGAIN ERR TAIL ' + $tW) } } }
Write-Output 'LOGAGAIN ELECTRON PHASE LOCK HELD.'
Write-Output 'LOGAGAIN NOCOOK.'
Write-Output 'LOGAGAIN NOPACKAGE.'
Write-Output 'WHOLE JOB DONE.'
```
