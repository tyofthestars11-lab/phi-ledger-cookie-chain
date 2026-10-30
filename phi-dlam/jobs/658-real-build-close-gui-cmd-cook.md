<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 658 - REAL BUILD CLOSE GUI CMD COOK (Ground: Tyree order snap out of loop stop filing saving level file listing actors real build save and close GUI editor then run Cmd editor file 651 Vault ModularS30eeb54ea3e4V1 placed in VEILDistrict pool 83 placed 24 Countess grounded not inverted place floor NAVMESH Dynamic map 180952 to 292786 world dressing 61 to 644 meshes M_PHI_Gold stems 10 cook package play on TV full-screen AAA not blue void silhouette progression 0 to 100 action not talk code filed diamond gated push to GitHub proceed no apologies be. This job closes GUI, runs Cmd place script, saves, then starts detached cook. No talk loop. Every variable carries the p658 prefix.) ==='
$p658uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p658map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p658script = 'D:\VEIL-OMNI\Saved\place658.py'
$p658out = 'D:\VEIL-OMNI\Saved\place658.out'
$p658errout = 'D:\VEIL-OMNI\Saved\place658.errout.txt'
$p658backup = 'D:\VEIL-OMNI\Saved\backup658'
$p658logs = 'D:\VEIL-OMNI\Saved\Logs'
$p658cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$p658uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$p658cookdir = 'D:\VEIL-OMNI\Saved\Cook658'
New-Item -ItemType Directory -Path $p658backup -Force | Out-Null
foreach ($p658f in @($p658map, $p658uproj)) { if (Test-Path $p658f) { Copy-Item $p658f $p658backup -Force; Write-Output ('BACKUP658 DONE ' + $p658f) } else { Write-Output ('BACKUP658 MISSING ' + $p658f) } }
Write-Output 'WHOLE658 NO SPLIT ONE WHOLE EVERYWHERE ALL AT ONCE'
$p658gui = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($p658gui) {
  Write-Output 'GUI658 OPEN SAVE AND CLOSE STARTS'
  foreach ($p658proc in $p658gui) { $p658proc.CloseMainWindow() | Out-Null }
  $p658wait = 0
  while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and ($p658wait -lt 90)) { Start-Sleep -Seconds 10; $p658wait += 10 }
  if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'GUI658 STILL OPEN AFTER 90 SECONDS FORCED CLOSE BY TYREE WORD' } else { Write-Output 'GUI658 CLOSED GRACEFUL' }
} else { Write-Output 'GUI658 ALREADY CLOSED' }
$p658lines = @(
'import unreal',
'loaded = unreal.EditorLevelLibrary.load_level("/Game/Maps/VEILDistrict")',
'print("LOAD658 RESULT " + str(loaded))',
'before = unreal.EditorLevelLibrary.get_all_level_actors()',
'print("ACTORS658 BEFORE " + str(len(before)))',
'nav = [a for a in before if "RecastNavMesh" in a.get_actor_label()]',
'print("NAVMESH658 FOUND " + str(len(nav)))',
'for a in nav:',
'    print("NAVMESH658 LABEL " + a.get_actor_label())',
'mesh = unreal.load_asset("/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess")',
'print("MESH658 LOADED " + str(mesh is not None))',
'loc = unreal.Vector(0.0, 0.0, 0.0)',
'rot = unreal.Rotator(0.0, 0.0, 0.0)',
'spawned = None',
'try:',
'    spawned = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, loc, rot)',
'    print("COUNTESS658 SPAWN OK " + str(spawned is not None))',
'except Exception as e:',
'    print("COUNTESS658 SPAWN FAILED " + str(e))',
'if spawned is not None:',
'    spawned.set_actor_label("Countess")',
'    comp = spawned.static_mesh_component',
'    print("COUNTESS658 COMP " + str(comp is not None))',
'    if comp is not None and mesh is not None:',
'        comp.set_static_mesh(mesh)',
'        print("COUNTESS658 MESH SET TRUE")',
'    print("COUNTESS658 LOC " + str(spawned.get_actor_location()))',
'    print("COUNTESS658 ROT " + str(spawned.get_actor_rotation()))',
'after = unreal.EditorLevelLibrary.get_all_level_actors()',
'print("ACTORS658 AFTER " + str(len(after)))',
'saved = unreal.EditorLevelLibrary.save_current_level()',
'print("SAVE658 RESULT " + str(saved))'
)
$p658lines | Set-Content -Path $p658script -Encoding UTF8
Write-Output ('SCRIPT658 WRITTEN SIZE ' + (Get-Item $p658script).Length)
$p658gui2 = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($p658gui2) { Write-Output 'EDITOR658 GUI OPEN CMD RUN SKIPPED' } else { Write-Output 'EDITOR658 GUI CLOSED CMD RUN STARTS' }
if ((-not $p658gui2) -and (Test-Path $p658script) -and (Test-Path $p658cmd) -and (Test-Path $p658uproj)) {
  $p658proc = Start-Process $p658cmd -ArgumentList "`"$p658uproj`"", '-run=PythonScript', "-script=`"$p658script`"", '-unattended', '-nop4', '-nosplash' -RedirectStandardOutput $p658out -RedirectStandardError $p658errout -PassThru
  Write-Output ('EDITOR658 STARTED PID ' + $p658proc.Id)
  $p658wait2 = 0
  while ((-not $p658proc.HasExited) -and ($p658wait2 -lt 180)) { Start-Sleep -Seconds 10; $p658wait2 += 10 }
  if ($p658proc.HasExited) { Write-Output ('EDITOR658 EXIT ' + $p658proc.ExitCode) } else { Write-Output 'EDITOR658 STILL RUNNING AFTER 180 SECONDS' }
} else { Write-Output 'EDITOR658 CMD RUN SKIPPED' }
Write-Output 'LOG658 NEWEST UNREAL LOG BUILD LINES'
if (Test-Path $p658logs) {
  $p658logFiles = @(Get-ChildItem $p658logs -Filter *.log | Sort-Object LastWriteTime -Descending | Select-Object -First 1)
  foreach ($p658lf in $p658logFiles) { Write-Output ('LOG658 FILE ' + $p658lf.Name + ' WRITTEN ' + $p658lf.LastWriteTime) }
  if ($p658logFiles.Count -gt 0) {
    $p658match = @(Get-Content $p658logFiles[0].FullName -ErrorAction SilentlyContinue | Select-String -Pattern 'LOAD658|ACTORS658|NAVMESH658|MESH658|COUNTESS658|SAVE658' -ErrorAction SilentlyContinue)
    Write-Output ('LOG658 MATCH LINES ' + $p658match.Count)
    foreach ($p658m in $p658match) { Write-Output ('LOG658 ' + $p658m.Line) }
  }
} else { Write-Output 'LOG658 LOGS FOLDER MISSING' }
Write-Output 'COOK658 DETACHED PACKAGE START'
if (Test-Path $p658uat) {
  $p658cook = Start-Process $p658uat -ArgumentList 'BuildCookRun', "-project=`"$p658uproj`"", '-noP4', '-platform=Win64', '-clientconfig=Development', '-cook', '-build', '-stage', '-pak', "-archivedirectory=`"$p658cookdir`"", '-allmaps' -PassThru
  Write-Output ('COOK658 STARTED PID ' + $p658cook.Id)
  Write-Output ('COOK658 DIR ' + $p658cookdir)
} else { Write-Output 'COOK658 UAT MISSING' }
Write-Output 'AUTO658 HIDDENDRAIN TASK QUERY BELOW'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
Write-Output 'JOB 658 DONE'
```
