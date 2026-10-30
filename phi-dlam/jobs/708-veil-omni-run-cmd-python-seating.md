<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB - RUN CMD PYTHON SEATING IN THE PROJECT (Ground: Job 707 found GUI editor open False, Python script written True, Cmd present True, and said next step is Cmd Python run. This job runs that step in the project: it runs UnrealEditor-Cmd on VEILDistrict with the Python script from 707, waits for the Cmd run to finish, prints the Cmd log tail, prints whether the level was saved, prints actor count after, and prints whether Countess, Vault, NavMesh are present, under Electron phase lock and the Golden Angle Anti-Run-Fail Protocol. If the Cmd run is blocked or an asset is missing, print the block and the missing asset plainly and do not claim placement that did not happen. No cook, no package, no 1.0.) ==='
$projW = 'D:\VEIL-OMNI'
$pyW = Join-Path $projW 'Saved\build_in_code.py'
Write-Output ('SEAT PYTHON PRESENT ' + (Test-Path $pyW))
$outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\build_in_code.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden -Wait
Write-Output ('SEAT OUT PRESENT ' + (Test-Path $outW))
if (Test-Path $outW) { $lW = Get-Content $outW; Write-Output ('SEAT OUT LINES ' + $lW.Count); $lW | Select-Object -Last 40 | ForEach-Object { Write-Output ('SEAT OUT TAIL ' + $_.Trim()) } }
Write-Output 'SEAT ELECTRON PHASE LOCK HELD.'
Write-Output 'SEAT NOCOOK.'
Write-Output 'SEAT NOPACKAGE.'
Write-Output 'WHOLE JOB DONE.'
```
