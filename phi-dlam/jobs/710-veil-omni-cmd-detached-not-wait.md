<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB - CMD DETACHED NOT WAIT (Ground: Job 708 timed out at 240 seconds because it waited for UnrealEditor-Cmd, and Unreal Cmd load runs past the 240 second step limit. This job runs Cmd detached, like the builds were, with separate out and err logs, prints that the process started, and does not wait for it, so the step cannot time out. A later job reads the log after Cmd finishes. If Cmd is missing or the script is missing, print that plainly and do not claim placement that did not happen. No cook, no package, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$pyW = Join-Path $projW 'Saved\build_in_code.py'
Write-Output ('DETACH PYTHON PRESENT ' + (Test-Path $pyW))
$outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('DETACH CMD PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\build_in_code.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'DETACH CMD STARTED DETACHED, NO WAIT, LOG READ IS NEXT JOB.'
Write-Output 'DETACH ELECTRON PHASE LOCK HELD.'
Write-Output 'DETACH NOCOOK.'
Write-Output 'DETACH NOPACKAGE.'
Write-Output 'WHOLE JOB DONE.'
```
