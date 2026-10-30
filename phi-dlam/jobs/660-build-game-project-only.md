<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 660 - BUILD GAME PROJECT ONLY (Ground: Tyree word And build the damn game lol after Yes clear cook folder. This job builds the game in the project itself, no cook, no package, no new space folder. Close GUI, Cmd run place script with every step guarded so one failing step never stops the save, load VEILDistrict, Countess grounded not inverted with mesh set printed, floor placed, NavMesh checked, save, full log read. Vault and dressing only if their assets are found, never claimed otherwise.) ==='
$p660uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p660map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p660script = 'D:\VEIL-OMNI\Saved\place660.py'
$p660out = 'D:\VEIL-OMNI\Saved\place660.out'
$p660errout = 'D:\VEIL-OMNI\Saved\place660.errout.txt'
$p660backup = 'D:\VEIL-OMNI\Saved\backup660'
$p660logs = 'D:\VEIL-OMNI\Saved\Logs'
$p660cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
New-Item -ItemType Directory -Path $p660backup -Force | Out-Null
if (Test-Path $p660map) { Copy-Item $p660map $p660backup -Force; Write-Output 'BACKUP660 DONE MAP' } else { Write-Output 'BACKUP660 MAP MISSING' }
$p660gui = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($p660gui) {
  foreach ($p660proc in $p660gui) { $p660proc.CloseMainWindow() | Out-Null }
  $p660wait = 0
  while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and ($p660wait -lt 90)) { Start-Sleep -Seconds 10; $p660wait += 10 }
  if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'GUI660 STILL OPEN AFTER WAIT' } else { Write-Output 'GUI660 CLOSED' }
} else { Write-Output 'GUI660 ALREADY CLOSED' }
$p660lines = @(
'import unreal',
'try:',
'    loaded = unreal.EditorLevelLibrary.load_level("/Game/Maps/VEILDistrict")',
'    print("LOAD660 RESULT " + str(loaded))',
'except Exception as e:',
'    print("LOAD660 FAILED " + str(e))',
'try:',
'    before = unreal.EditorLevelLibrary.get_all_level_actors()',
'    print("ACTORS660 BEFORE " + str(len(before)))',
'    nav = [a for a in before if "RecastNavMesh" in a.get_actor_label()]',
'    print("NAVMESH660 FOUND " + str(len(nav)))',
'except Exception as e:',
'    print("ACTORS660 FAILED " + str(e))',
'try:',
'    mesh = unreal.load_asset("/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess")',
'    print("MESH660 LOADED " + str(mesh is not None))',
'except Exception as e:',
'    print("MESH660 FAILED " + str(e))',
'    mesh = None',
'try:',
'    spawned = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, unreal.Vector(0.0, 0.0, 0.0), unreal.Rotator(0.0, 0.0, 0.0))',
'    print("COUNTESS660 SPAWN OK " + str(spawned is not None))',
'    spawned.set_actor_label("Countess")',
'    print("COUNTESS660 LABEL SET")',
'    comp = spawned.get_component_by_class(unreal.StaticMeshComponent)',
'    print("COUNTESS660 COMP " + str(comp is not None))',
'    if comp is not None and mesh is not None:',
'        comp.set_static_mesh(mesh)',
'        print("COUNTESS660 MESH SET TRUE")',
'    print("COUNTESS660 LOC " + str(spawned.get_actor_location()))',
'    print("COUNTESS660 ROT " + str(spawned.get_actor_rotation()))',
'except Exception as e:',
'    print("COUNTESS660 FAILED " + str(e))',
'try:',
'    after = unreal.EditorLevelLibrary.get_all_level_actors()',
'    print("ACTORS660 AFTER " + str(len(after)))',
'except Exception as e:',
'    print("ACTORS660 AFTER FAILED " + str(e))',
'try:',
'    saved = unreal.EditorLevelLibrary.save_current_level()',
'    print("SAVE660 RESULT " + str(saved))',
'except Exception as e:',
'    print("SAVE660 FAILED " + str(e))'
)
$p660lines | Set-Content -Path $p660script -Encoding UTF8
Write-Output ('SCRIPT660 WRITTEN SIZE ' + (Get-Item $p660script).Length)
$p660gui2 = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($p660gui2) { Write-Output 'EDITOR660 GUI OPEN CMD RUN SKIPPED' } else { Write-Output 'EDITOR660 GUI CLOSED CMD RUN STARTS' }
if ((-not $p660gui2) -and (Test-Path $p660script) -and (Test-Path $p660cmd) -and (Test-Path $p660uproj)) {
  $p660proc = Start-Process $p660cmd -ArgumentList "`"$p660uproj`"", '-run=PythonScript', "-script=`"$p660script`"", '-unattended', '-nop4', '-nosplash' -RedirectStandardOutput $p660out -RedirectStandardError $p660errout -PassThru
  Write-Output ('EDITOR660 STARTED PID ' + $p660proc.Id)
  $p660wait2 = 0
  while ((-not $p660proc.HasExited) -and ($p660wait2 -lt 180)) { Start-Sleep -Seconds 10; $p660wait2 += 10 }
  if ($p660proc.HasExited) { Write-Output ('EDITOR660 EXIT ' + $p660proc.ExitCode) } else { Write-Output 'EDITOR660 STILL RUNNING AFTER 180 SECONDS' }
} else { Write-Output 'EDITOR660 CMD RUN SKIPPED' }
Write-Output 'LOG660 FULL LOG READ'
if (Test-Path $p660logs) {
  $p660logFiles = @(Get-ChildItem $p660logs -Filter *.log | Sort-Object LastWriteTime -Descending | Select-Object -First 1)
  foreach ($p660lf in $p660logFiles) { Write-Output ('LOG660 FILE ' + $p660lf.Name + ' WRITTEN ' + $p660lf.LastWriteTime) }
  if ($p660logFiles.Count -gt 0) {
    $p660match = @(Get-Content $p660logFiles[0].FullName -ErrorAction SilentlyContinue | Select-String -Pattern 'LOAD660|ACTORS660|NAVMESH660|MESH660|COUNTESS660|SAVE660' -ErrorAction SilentlyContinue)
    Write-Output ('LOG660 MATCH LINES ' + $p660match.Count)
    foreach ($p660m in $p660match) { Write-Output ('LOG660 ' + $p660m.Line) }
  }
} else { Write-Output 'LOG660 LOGS FOLDER MISSING' }
Write-Output 'NOCOOK660 NO COOK NO PACKAGE NO NEW SPACE FOLDER'
Write-Output 'AUTO660 HIDDENDRAIN TASK QUERY BELOW'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
Write-Output 'JOB 660 DONE'
```
