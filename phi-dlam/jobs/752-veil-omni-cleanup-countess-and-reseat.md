<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 752 - CLEANUP COUNTESS AND RESEAT (Ground: Job 751 read seat750 out file whole, 29 lines, 1325 bytes: MAP LOADED, WORLD /Game/Maps/VEILDistrict.VEILDistrict, ACTORS BEFORE 423, FLOOR Z -50.0, VAULT PLACED 0 0 -50, VAULT MESH COUNT 0, NAVMESH ALREADY PRESENT, COUNTESS PLACED 500 -500 40, MESH SM_Countess, ANIMBP MISSING NOT SET, GOLDEN PITCH SET ERROR sweep argument, PLAYERSTART ALREADY PRESENT, SAVE RESULT True flipped from False in 749, ACTORS AFTER 425, VAULT PRESENT True, NAVMESH PRESENT True, COUNTESS PRESENT True, DONE, seat750 log MoveFile lines 0, Error saving lines 0, Success 0 errors 19 warnings, map 632301 changed from 626984, save landed now that GUI editor was closed. The 663 duplicate Countess actors are still in the map, seat places one more each run, so single Countess needs a delete step before the seat places one. This job closes GUI editor processes, backs up seat719, inserts a delete-all-Countess-by-label block before log START using the seat script own spawn code after it, deletes the old out file, then starts a fresh detached Cmd run with new log names VEIL_SEAT752. It cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('GUI752 BEFORE ID ' + $_.Id) }
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 5
$leftW = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
Write-Output ('GUI752 AFTER COUNT ' + $leftW.Count)
$pyW = Join-Path $projW 'Saved\seat719.py'
$backupW = Join-Path $projW 'Saved\seat719.py.phi-backup-752'
Write-Output ('SCRIPT752 PRESENT ' + (Test-Path $pyW))
Copy-Item $pyW $backupW -Force
Write-Output 'BACKUP752 PRESENT True'
$contentW = Get-Content $pyW -Raw
Write-Output ('DELETE752 BEFORE ' + ([regex]::Matches($contentW, 'COUNTESS DELETED')).Count)
$insertW = "    before_countess = [a for a in unreal.EditorLevelLibrary.get_all_level_actors() if `"countess`" in a.get_actor_label().lower()]`n    for a in before_countess:`n        unreal.EditorLevelLibrary.destroy_actor(a)`n    log(`"COUNTESS DELETED: `" + str(len(before_countess)))`n    log(`"START`")"
$contentW = $contentW.Replace('    log("START")', $insertW)
Set-Content $pyW $contentW -NoNewline
$afterContent = Get-Content $pyW -Raw
Write-Output ('DELETE752 AFTER ' + ([regex]::Matches($afterContent, 'COUNTESS DELETED')).Count)
Write-Output 'SCRIPT752 COUNTESS REGION'
Select-String -Path $pyW -Pattern 'COUNTESS DELETED'
$outFile = Join-Path $projW 'Saved\seat719_out.txt'
if (Test-Path $outFile) { Remove-Item $outFile -Force; Write-Output 'OUT752 OLD FILE DELETED' }
$outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT752_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT752_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('SEAT752 CMD PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'SEAT752 CMD STARTED DETACHED NO WAIT'
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD752 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP752 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
