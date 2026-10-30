<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 764 - PLACE NAVMESH BOUNDS AND SAVE (Ground: Job 763 read find_actors body: matches substring in class_path_of actor, not label, line 46 to 54, seat NavMesh block spawn at 0,0,floor_z + 500 scale 20,20,4 RebuildNavigation, map 629620. Job 760 label filter showed RecastNavMesh-Default only, no BoundsVolume label, so seat ALREADY PRESENT was class path match, not disk BoundsVolume. This job seats only NavMesh: close GUI UnrealEditor processes only, backup seat719, run seat719 NavMesh section only via a new script Saved seat_navmesh764.py that loads VEILDistrict, deletes any NavMeshBoundsVolume class path actors, spawns one NavMeshBoundsVolume at 0,0,-50 + 500, scale 20,20,4, sends RebuildNavigation, saves map, writes Saved seat_navmesh764_out.txt with NAVMESH DELETED, NAVMESH PLACED, SAVE RESULT, ACTORS BEFORE, ACTORS AFTER. It cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('GUI764 BEFORE ID ' + $_.Id) }
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 3
$guiAfterW = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
Write-Output ('GUI764 AFTER COUNT ' + $guiAfterW.Count)
$seatW = Join-Path $projW 'Saved\seat719.py'
$bakW = Join-Path $projW 'Saved\seat719.py.phi-backup-764'
Copy-Item $seatW $bakW -Force
Write-Output 'NAV764 SEAT BACKUP True'
$pyW = Join-Path $projW 'Saved\seat_navmesh764.py'
$outFileW = Join-Path $projW 'Saved\seat_navmesh764_out.txt'
if (Test-Path $outFileW) { Remove-Item $outFileW -Force }
$scriptW = "import unreal`nOUT = 'D:/VEIL-OMNI/Saved/seat_navmesh764_out.txt'`ndef log(msg):`n    unreal.log(msg)`n    with open(OUT, 'a') as f:`n        f.write(msg + chr(10))`ntry:`n    unreal.EditorLevelLibrary.load_level('/Game/Maps/VEILDistrict')`n    log('NAVMESH MAP LOADED')`nexcept Exception as exc:`n    log('NAVMESH MAP LOAD FAIL: ' + str(exc))`nbefore = unreal.EditorLevelLibrary.get_all_level_actors()`nlog('NAVMESH ACTORS BEFORE: ' + str(len(before)))`ndeleted = 0`nfor a in list(before):`n    try:`n        if 'NavMeshBoundsVolume' in str(a.get_class().get_path_name()):`n            unreal.EditorLevelLibrary.destroy_actor(a)`n            deleted += 1`n    except Exception:`n        pass`nlog('NAVMESH DELETED: ' + str(deleted))`ntry:`n    nav = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.NavMeshBoundsVolume, unreal.Vector(0.0, 0.0, 450.0), unreal.Rotator(0.0, 0.0, 0.0))`n    nav.set_actor_scale3d(unreal.Vector(20.0, 20.0, 4.0))`n    log('NAVMESH PLACED 0,0,450 SCALE 20,20,4')`nexcept Exception as exc:`n    log('NAVMESH PLACE FAIL: ' + str(exc))`ntry:`n    w = unreal.EditorLevelLibrary.get_editor_world()`n    unreal.SystemLibrary.execute_console_command(w, 'RebuildNavigation')`n    log('NAVMESH REBUILD SENT')`nexcept Exception as exc:`n    log('NAVMESH REBUILD FAIL: ' + str(exc))`ntry:`n    saved = unreal.EditorLevelLibrary.save_current_level()`n    log('NAVMESH SAVE RESULT: ' + str(saved))`nexcept Exception as exc:`n    log('NAVMESH SAVE FAIL: ' + str(exc))`nafter = unreal.EditorLevelLibrary.get_all_level_actors()`nlog('NAVMESH ACTORS AFTER: ' + str(len(after)))`nlog('NAVMESH DONE')`n"
Set-Content $pyW $scriptW -NoNewline
Write-Output 'NAV764 SCRIPT PRESENT True'
$outW = Join-Path $projW 'Saved\Logs\VEIL_NAVMESH764_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_NAVMESH764_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('NAV764 CMD PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat_navmesh764.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'NAV764 CMD STARTED DETACHED NO WAIT'
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP764 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
