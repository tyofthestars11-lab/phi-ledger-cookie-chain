<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 766 - CLOSE CMD AND RESEAT NAVMESH (Ground: Job 765 read seat_navmesh764_out.txt 197 bytes: MAP LOADED, ACTORS BEFORE 423, DELETED 1, PLACED 0,0,450 SCALE 20,20,4, REBUILD SENT, SAVE RESULT False, ACTORS AFTER 423, DONE, Cmd out tail MoveFile unable to move VEILDistrict.umap Error Code 32, Failed to move, Error saving, Failure 2 errors 30 warnings 5.88 seconds, Recast warning again, map 629620 unchanged, MUSE LOCAL 764 NAVMESH AWAKE. Save failed again with file in use, despite GUI count 0 in 764, old Cmd processes 76260 76760 79224 86576 were listed in 765. This job closes GUI and Cmd processes only, verifies none remain, deletes old NavMesh out file, starts seat_navmesh764 Cmd detached again, no other edits. It cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('GUI766 BEFORE ID ' + $_.Id) }
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD766 BEFORE ID ' + $_.Id) }
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 5
$guiAfterW = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
$cmdAfterW = @(Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue)
Write-Output ('GUI766 AFTER COUNT ' + $guiAfterW.Count)
Write-Output ('CMD766 AFTER COUNT ' + $cmdAfterW.Count)
$outFileW = Join-Path $projW 'Saved\seat_navmesh764_out.txt'
if (Test-Path $outFileW) { Remove-Item $outFileW -Force }
Write-Output 'NAV766 OLD OUT DELETED True'
$outW = Join-Path $projW 'Saved\Logs\VEIL_NAVMESH766_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_NAVMESH766_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('NAV766 CMD PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat_navmesh764.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'NAV766 CMD STARTED DETACHED NO WAIT'
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP766 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
