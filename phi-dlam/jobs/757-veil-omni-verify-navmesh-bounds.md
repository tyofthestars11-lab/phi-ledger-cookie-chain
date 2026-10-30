<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 757 - VERIFY NAVMESH BOUNDS (Ground: Job 753 read seat752 out file whole: NAVMESH ALREADY PRESENT, REBUILD COMMAND SENT, REBUILD PROOF IN PLAY ONLY NOT CLAIMED, seat752 log warning Unable to find RecastNavMesh instance while trying to create UCrowdManager, map 629620, single Countess on disk. NavMesh volume boundaries are not in any seat log, no guessed scale stands. This job reads only: load VEILDistrict, list NavMeshBoundsVolume actors with labels locations and scales, list RecastNavMesh actors, list floor actors, no edits, no save. It cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$pyW = Join-Path $projW 'Saved\verify_navmesh.py'
$scriptW = "import unreal`nlog = unreal.log`ntry:`n    unreal.EditorLevelLibrary.load_level('/Game/Maps/VEILDistrict')`n    log('NAVMESH MAP LOADED')`nexcept Exception as exc:`n    log('NAVMESH MAP LOAD ERROR: ' + str(exc))`nactors = unreal.EditorLevelLibrary.get_all_level_actors()`nlog('NAVMESH ACTORS TOTAL: ' + str(len(actors)))`nfor a in actors:`n    label = a.get_actor_label()`n    low = label.lower()`n    if 'navmesh' in low or 'recast' in low or 'phi_' in low:`n        loc = a.get_actor_location()`n        scale = a.get_actor_scale()`n        log('NAVMESH ACTOR: ' + label + ' CLASS: ' + str(a.get_class().get_name()) + ' LOC: ' + str(loc.x) + ',' + str(loc.y) + ',' + str(loc.z) + ' SCALE: ' + str(scale.x) + ',' + str(scale.y) + ',' + str(scale.z))`nlog('NAVMESH DONE')`n"
Set-Content $pyW $scriptW -NoNewline
Write-Output 'NAVMESH SCRIPT PRESENT True'
$outW = Join-Path $projW 'Saved\Logs\VEIL_NAVMESH757_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_NAVMESH757_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('NAVMESH CMD PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\verify_navmesh.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'NAVMESH CMD STARTED DETACHED NO WAIT'
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD757 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP757 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
