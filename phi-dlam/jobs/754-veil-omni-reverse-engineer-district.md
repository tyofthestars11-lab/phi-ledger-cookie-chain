<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 754 - REVERSE ENGINEER VEIL DISTRICT (Ground: Job 753 read seat752 out file whole, 29 lines, 1206 bytes: MAP LOADED, COUNTESS DELETED 3, WORLD /Game/Maps/VEILDistrict.VEILDistrict, ACTORS BEFORE 422, FLOOR Z -50.0, VAULT ALREADY PRESENT, VAULT MESH COUNT 0, NAVMESH ALREADY PRESENT, COUNTESS PLACED 500 -500 40, MESH SM_Countess, ANIMBP MISSING NOT SET, PLAYERSTART ALREADY PRESENT, SAVE RESULT True, ACTORS AFTER 423, map 629620, single Countess on disk. Visual world building needs a read of what is actually in the level, not a tutorial: actor classes, lighting, landscape, materials, floor, Vault, Countess, NavMesh, PlayerStart. This job reads only: load VEILDistrict, get all actors, count by class, list lighting actors, landscape actors, floor actors, Vault actors, Countess actors, NavMesh actors, PlayerStart actors, with labels and locations, no edits, no save. It cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$pyW = Join-Path $projW 'Saved\reverse_district.py'
$scriptW = "import unreal`nlog = unreal.log`ntry:`n    unreal.EditorLevelLibrary.load_level('/Game/Maps/VEILDistrict')`n    log('REVERSE MAP LOADED')`nexcept Exception as exc:`n    log('REVERSE MAP LOAD ERROR: ' + str(exc))`nactors = unreal.EditorLevelLibrary.get_all_level_actors()`nlog('REVERSE ACTORS TOTAL: ' + str(len(actors)))`nfrom collections import Counter`ncounts = Counter()`nfor a in actors:`n    counts[str(a.get_class().get_name())] += 1`nfor name, count in counts.items():`n    log('REVERSE CLASS: ' + name + ' COUNT: ' + str(count))`nfor a in actors:`n    label = a.get_actor_label()`n    low = label.lower()`n    if 'light' in low or 'sky' in low or 'fog' in low or 'post' in low or 'landscape' in low or 'vault' in low or 'countess' in low or 'navmesh' in low or 'playerstart' in low or 'phi_' in low:`n        loc = a.get_actor_location()`n        log('REVERSE ACTOR: ' + label + ' CLASS: ' + str(a.get_class().get_name()) + ' LOC: ' + str(loc.x) + ',' + str(loc.y) + ',' + str(loc.z))`nlog('REVERSE DONE')`n"
Set-Content $pyW $scriptW -NoNewline
Write-Output 'REVERSE SCRIPT PRESENT True'
$outW = Join-Path $projW 'Saved\Logs\VEIL_REVERSE754_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_REVERSE754_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('REVERSE CMD PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\reverse_district.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'REVERSE CMD STARTED DETACHED NO WAIT'
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD754 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP754 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
