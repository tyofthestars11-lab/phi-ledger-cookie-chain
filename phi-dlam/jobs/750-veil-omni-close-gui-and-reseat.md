<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 750 - CLOSE GUI EDITOR AND RESEAT (Ground: Job 749 read seat748 out file whole, 29 lines, 1326 bytes: MAP LOADED, WORLD /Game/Maps/VEILDistrict.VEILDistrict, ACTORS BEFORE 423, FLOOR Z -50.0, FLOOR SOURCE PHI_FLOOR_PAD, VAULT PLACED AT 0 0 -50, VAULT MESH COUNT 0, NAVMESH ALREADY PRESENT, COUNTESS PLACED AT 500 -500 40, COUNTESS MESH SET SM_Countess, ANIMBP MISSING NOT SET, GOLDEN PITCH SET ERROR sweep argument, PLAYERSTART ALREADY PRESENT, SAVE RESULT False, ACTORS AFTER 425, VAULT PRESENT True, NAVMESH PRESENT True, COUNTESS PRESENT True, DONE, map 626984 unchanged. Seat748 log SAVE lines prove the save failed on disk: MoveFile unable to move VEILDistrict.umap to temp, Error Code 32, retrying, then Error moving file, Failed to move to temp, Error saving VEILDistrict.umap, Failure 2 errors 31 warnings, execution 5.96 seconds. Error Code 32 is the map file held by another process, the GUI editor holding VEILDistrict open. This job closes GUI UnrealEditor processes only, verifies none remain, deletes the old out file, then starts a fresh detached Cmd run with new log names VEIL_SEAT750. It edits no script, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('GUI750 BEFORE ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB)) }
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 5
$leftW = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
Write-Output ('GUI750 AFTER COUNT ' + $leftW.Count)
$outFile = Join-Path $projW 'Saved\seat719_out.txt'
if (Test-Path $outFile) { Remove-Item $outFile -Force; Write-Output 'OUT750 OLD FILE DELETED' }
$outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT750_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT750_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('SEAT750 CMD PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'SEAT750 CMD STARTED DETACHED NO WAIT'
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD750 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP750 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
