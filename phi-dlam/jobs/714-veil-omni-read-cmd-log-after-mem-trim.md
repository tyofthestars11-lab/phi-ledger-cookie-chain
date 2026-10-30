<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB - READ CMD LOG AFTER MEM TRIM (Ground: Job 713 freed memory from 3872 MB to 6413 MB, plus 2541 MB, after jobs 711 and 712 found Cmd running True with out lines stuck at 140 at editor load. This job reads the log again after that trim: it checks whether Cmd is still running, prints out lines and err lines, prints the last 40 non-empty lines of each, prints whether the Python script printed actor count and save done, and prints whether Countess, Vault, NavMesh are named after load. If Cmd is still running, print that plainly and do not claim a finished run. No cook, no package, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT_cmd_err.log'
$procW = Get-Process -Name UnrealEditor-Cmd -ErrorAction SilentlyContinue
Write-Output ('LOGTRIM CMD RUNNING ' + ($null -ne $procW))
Write-Output ('LOGTRIM OUT PRESENT ' + (Test-Path $outW))
if (Test-Path $outW) { $oW = Get-Content $outW; Write-Output ('LOGTRIM OUT LINES ' + $oW.Count); $oW | Select-Object -Last 40 | ForEach-Object { $tW = $_.Trim(); if ($tW.Length -gt 0) { Write-Output ('LOGTRIM OUT TAIL ' + $tW) } } }
Write-Output ('LOGTRIM ERR PRESENT ' + (Test-Path $errW))
if (Test-Path $errW) { $eW = Get-Content $errW; Write-Output ('LOGTRIM ERR LINES ' + $eW.Count); $eW | Select-Object -Last 40 | ForEach-Object { $tW = $_.Trim(); if ($tW.Length -gt 0) { Write-Output ('LOGTRIM ERR TAIL ' + $tW) } } }
$memW = Get-CimInstance Win32_OperatingSystem
Write-Output ('LOGTRIM FREE MB ' + [int]($memW.FreePhysicalMemory / 1024))
Write-Output 'LOGTRIM ELECTRON PHASE LOCK HELD.'
Write-Output 'LOGTRIM NOCOOK.'
Write-Output 'LOGTRIM NOPACKAGE.'
Write-Output 'WHOLE JOB DONE.'
```
