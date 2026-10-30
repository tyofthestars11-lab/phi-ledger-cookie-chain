<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 663 - COPILOT TYPE CHECK COUNTESS MESH (Ground: Copilot answer to 660 failure, Tyree pasted whole. Copilot proved SetStaticMesh failed because the loaded object is not a StaticMesh at call time, even though load printed true, and a saved actor with null mesh renders empty in play. This job prints the asset class first, then spawns the correct actor type for that class, assigns the mesh, prints the assigned mesh back, and saves. No cook, no package, no new space folder.) ==='
$p663uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p663map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p663script = 'D:\VEIL-OMNI\Saved\place663.py'
$p663out = 'D:\VEIL-OMNI\Saved\place663.out'
$p663errout = 'D:\VEIL-OMNI\Saved\place663.errout.txt'
$p663backup = 'D:\VEIL-OMNI\Saved\backup663'
$p663logs = 'D:\VEIL-OMNI\Saved\Logs'
$p663cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
New-Item -ItemType Directory -Path $p663backup -Force | Out-Null
if (Test-Path $p663map) { Copy-Item $p663map $p663backup -Force; Write-Output 'BACKUP663 DONE MAP' } else { Write-Output 'BACKUP663 MAP MISSING' }
$p663gui = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($p663gui) {
  foreach ($p663proc in $p663gui) { $p663proc.CloseMainWindow() | Out-Null }
  $p663wait = 0
  while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and ($p663wait -lt 90)) { Start-Sleep -Seconds 10; $p663wait += 10 }
  if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'GUI663 STILL OPEN AFTER WAIT' } else { Write-Output 'GUI663 CLOSED' }
} else { Write-Output 'GUI663 ALREADY CLOSED' }
$p663lines = @(
'import unreal',
'try:',
'    loaded = unreal.EditorLevelLibrary.load_level("/Game/Maps/VEILDistrict")',
'    print("LOAD663 RESULT " + str(loaded))',
'except Exception as e:',
'    print("LOAD663 FAILED " + str(e))',
'try:',
'    before = unreal.EditorLevelLibrary.get_all_level_actors()',
'    print("ACTORS663 BEFORE " + str(len(before)))',
'except Exception as e:',
'    print("ACTORS663 BEFORE FAILED " + str(e))',
'mesh = None',
'try:',
'    mesh = unreal.load_asset("/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess")',
'    print("MESH663 LOADED " + str(mesh is not None))',
'    print("MESH663 CLASS " + str(mesh.get_class().get_name() if mesh else "NONE"))',
'    print("MESH663 IS STATIC " + str(isinstance(mesh, unreal.StaticMesh)))',
'    print("MESH663 IS SKELETAL " + str(isinstance(mesh, unreal.SkeletalMesh)))',
'except Exception as e:',
'    print("MESH663 FAILED " + str(e))',
'try:',
'    if mesh is not None and isinstance(mesh, unreal.StaticMesh):',
'        spawned = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, unreal.Vector(0.0, 0.0, 0.0), unreal.Rotator(0.0, 0.0, 0.0))',
'        spawned.set_actor_label("Countess")',
'        comp = spawned.get_component_by_class(unreal.StaticMeshComponent)',
'        comp.set_static_mesh(mesh)',
'        print("COUNTESS663 STATIC SET TRUE")',
'        print("COUNTESS663 ASSIGNED " + str(comp.get_editor_property("static_mesh")))',
'    elif mesh is not None and isinstance(mesh, unreal.SkeletalMesh):',
'        spawned = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.SkeletalMeshActor, unreal.Vector(0.0, 0.0, 0.0), unreal.Rotator(0.0, 0.0, 0.0))',
'        spawned.set_actor_label("Countess")',
'        comp = spawned.get_component_by_class(unreal.SkeletalMeshComponent)',
'        comp.set_skeletal_mesh(mesh)',
'        print("COUNTESS663 SKELETAL SET TRUE")',
'        print("COUNTESS663 ASSIGNED " + str(comp.get_editor_property("skeletal_mesh")))',
'    else:',
'        print("COUNTESS663 NO VALID MESH CLASS TO ASSIGN")',
'    print("COUNTESS663 LOC " + str(spawned.get_actor_location()))',
'    print("COUNTESS663 ROT " + str(spawned.get_actor_rotation()))',
'except Exception as e:',
'    print("COUNTESS663 FAILED " + str(e))',
'try:',
'    after = unreal.EditorLevelLibrary.get_all_level_actors()',
'    print("ACTORS663 AFTER " + str(len(after)))',
'    for a in after:',
'        if a.get_actor_label() == "Countess":',
'            print("COUNTESS663 IN MAP LABEL FOUND")',
'except Exception as e:',
'    print("ACTORS663 AFTER FAILED " + str(e))',
'try:',
'    saved = unreal.EditorLevelLibrary.save_current_level()',
'    print("SAVE663 RESULT " + str(saved))',
'except Exception as e:',
'    print("SAVE663 FAILED " + str(e))'
)
$p663lines | Set-Content -Path $p663script -Encoding UTF8
Write-Output ('SCRIPT663 WRITTEN SIZE ' + (Get-Item $p663script).Length)
$p663gui2 = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($p663gui2) { Write-Output 'EDITOR663 GUI OPEN CMD RUN SKIPPED' } else { Write-Output 'EDITOR663 GUI CLOSED CMD RUN STARTS' }
if ((-not $p663gui2) -and (Test-Path $p663script) -and (Test-Path $p663cmd) -and (Test-Path $p663uproj)) {
  $p663proc = Start-Process $p663cmd -ArgumentList "`"$p663uproj`"", '-run=PythonScript', "-script=`"$p663script`"", '-unattended', '-nop4', '-nosplash' -RedirectStandardOutput $p663out -RedirectStandardError $p663errout -PassThru
  Write-Output ('EDITOR663 STARTED PID ' + $p663proc.Id)
  $p663wait2 = 0
  while ((-not $p663proc.HasExited) -and ($p663wait2 -lt 180)) { Start-Sleep -Seconds 10; $p663wait2 += 10 }
  if ($p663proc.HasExited) { Write-Output ('EDITOR663 EXIT ' + $p663proc.ExitCode) } else { Write-Output 'EDITOR663 STILL RUNNING AFTER 180 SECONDS' }
} else { Write-Output 'EDITOR663 CMD RUN SKIPPED' }
Write-Output 'LOG663 FULL LOG READ'
if (Test-Path $p663logs) {
  $p663logFiles = @(Get-ChildItem $p663logs -Filter *.log | Sort-Object LastWriteTime -Descending | Select-Object -First 1)
  foreach ($p663lf in $p663logFiles) { Write-Output ('LOG663 FILE ' + $p663lf.Name + ' WRITTEN ' + $p663lf.LastWriteTime) }
  if ($p663logFiles.Count -gt 0) {
    $p663match = @(Get-Content $p663logFiles[0].FullName -ErrorAction SilentlyContinue | Select-String -Pattern 'LOAD663|ACTORS663|MESH663|COUNTESS663|SAVE663' -ErrorAction SilentlyContinue)
    Write-Output ('LOG663 MATCH LINES ' + $p663match.Count)
    foreach ($p663m in $p663match) { Write-Output ('LOG663 ' + $p663m.Line) }
  }
} else { Write-Output 'LOG663 LOGS FOLDER MISSING' }
Write-Output 'NOCOOK663 NO COOK NO PACKAGE'
Write-Output 'JOB 663 DONE'
```
