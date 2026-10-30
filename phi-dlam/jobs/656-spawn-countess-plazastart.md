<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 656 - SPAWN COUNTESS PLAZASTART (Ground: Tyree order Continue after 655 result world is dressing only 92 actors no Countess actor no Vault actor no player actor AnimBlueprint 0. This job spawns a Countess mesh actor at PlazaStart, saves VEILDistrict, then reads the Unreal log where the prints land. Vault is not spawned because its asset is absent. No build, no package, no ledger edit. Every variable carries the p656 prefix.) ==='
$p656uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p656map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p656script = 'D:\VEIL-OMNI\Saved\place656.py'
$p656out = 'D:\VEIL-OMNI\Saved\place656.out'
$p656errout = 'D:\VEIL-OMNI\Saved\place656.errout.txt'
$p656backup = 'D:\VEIL-OMNI\Saved\backup656'
$p656logs = 'D:\VEIL-OMNI\Saved\Logs'
$p656cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
New-Item -ItemType Directory -Path $p656backup -Force | Out-Null
foreach ($p656f in @($p656map, $p656uproj)) { if (Test-Path $p656f) { Copy-Item $p656f $p656backup -Force; Write-Output ('BACKUP656 DONE ' + $p656f) } else { Write-Output ('BACKUP656 MISSING ' + $p656f) } }
Write-Output 'WHOLE656 NO SPLIT ONE WHOLE EVERYWHERE ALL AT ONCE'
if (Test-Path $p656map) { Write-Output 'MAP656 PRESENT VEILDISTRICT' } else { Write-Output 'MAP656 MISSING VEILDISTRICT' }
$p656lines = @(
'import unreal',
'loaded = unreal.EditorLevelLibrary.load_level("/Game/Maps/VEILDistrict")',
'print("LOAD656 RESULT " + str(loaded))',
'before = unreal.EditorLevelLibrary.get_all_level_actors()',
'print("ACTORS656 BEFORE " + str(len(before)))',
'mesh = unreal.load_asset("/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess")',
'print("MESH656 LOADED " + str(mesh is not None))',
'loc = unreal.Vector(0.0, 0.0, 120.0)',
'rot = unreal.Rotator(0.0, 0.0, 0.0)',
'spawned = None',
'try:',
'    spawned = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, loc, rot)',
'    print("SPAWN656 CLASS OK " + str(spawned is not None))',
'except Exception as e:',
'    print("SPAWN656 CLASS FAILED " + str(e))',
'if spawned is not None:',
'    spawned.set_actor_label("Countess")',
'    comp = spawned.static_mesh_component',
'    print("COMP656 PRESENT " + str(comp is not None))',
'    if comp is not None and mesh is not None:',
'        comp.set_static_mesh(mesh)',
'        print("MESH656 SET TRUE")',
'    print("COUNTESS656 LABEL " + spawned.get_actor_label())',
'    print("COUNTESS656 LOC " + str(spawned.get_actor_location()))',
'after = unreal.EditorLevelLibrary.get_all_level_actors()',
'print("ACTORS656 AFTER " + str(len(after)))',
'saved = unreal.EditorLevelLibrary.save_current_level()',
'print("SAVE656 RESULT " + str(saved))'
)
$p656lines | Set-Content -Path $p656script -Encoding UTF8
Write-Output ('SCRIPT656 WRITTEN SIZE ' + (Get-Item $p656script).Length)
$p656gui = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($p656gui) { Write-Output 'EDITOR656 GUI OPEN CMD RUN SKIPPED GUI BLOCKS CMD RUN' } else { Write-Output 'EDITOR656 GUI CLOSED CMD RUN STARTS WITH CAPTURE' }
if ((-not $p656gui) -and (Test-Path $p656script) -and (Test-Path $p656cmd) -and (Test-Path $p656uproj)) {
  $p656proc = Start-Process $p656cmd -ArgumentList "`"$p656uproj`"", '-run=PythonScript', "-script=`"$p656script`"", '-unattended', '-nop4', '-nosplash' -RedirectStandardOutput $p656out -RedirectStandardError $p656errout -PassThru
  Write-Output ('EDITOR656 STARTED PID ' + $p656proc.Id)
  $p656wait = 0
  while ((-not $p656proc.HasExited) -and ($p656wait -lt 180)) { Start-Sleep -Seconds 10; $p656wait += 10 }
  if ($p656proc.HasExited) { Write-Output ('EDITOR656 EXIT ' + $p656proc.ExitCode) } else { Write-Output 'EDITOR656 STILL RUNNING AFTER 180 SECONDS' }
} else { Write-Output 'EDITOR656 CMD RUN SKIPPED GUI OPEN OR PREREQUISITE MISSING' }
Write-Output 'LOG656 NEWEST UNREAL LOG SPAWN LINES'
if (Test-Path $p656logs) {
  $p656logFiles = @(Get-ChildItem $p656logs -Filter *.log | Sort-Object LastWriteTime -Descending | Select-Object -First 1)
  foreach ($p656lf in $p656logFiles) { Write-Output ('LOG656 FILE ' + $p656lf.Name + ' WRITTEN ' + $p656lf.LastWriteTime) }
  if ($p656logFiles.Count -gt 0) {
    $p656match = @(Get-Content $p656logFiles[0].FullName -ErrorAction SilentlyContinue | Select-String -Pattern 'LOAD656|ACTORS656|MESH656|SPAWN656|COMP656|COUNTESS656|SAVE656' -ErrorAction SilentlyContinue)
    Write-Output ('LOG656 MATCH LINES ' + $p656match.Count)
    foreach ($p656m in $p656match) { Write-Output ('LOG656 ' + $p656m.Line) }
  }
} else { Write-Output 'LOG656 LOGS FOLDER MISSING' }
Write-Output 'AUTO656 HIDDENDRAIN TASK QUERY BELOW'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
Write-Output 'NOPACKAGE656 NO PACKAGE UNTIL 100 PERCENT DONE'
Write-Output 'JOB 656 DONE'
```
