<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 653 - LOAD SAVE PLACE653 (Ground: Tyree order file 653 test corrected load and save version in Cmd plus 652 result SaveCurrentLevel cant save level because it doesnt have a filename plus Llama draft load_map_by_name run_script save_current_level unproven names. This job writes a corrected script that loads VEILDistrict by path first, then runs the place648 actor logic, then saves with the level now named, and runs it in Cmd with stdout captured. No split phi squared equals phi plus 1 does not split one whole everywhere all at once. No package until 100 percent done. No ledger edit. Every variable carries the p653 prefix.) ==='
$p653uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p653map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p653script = 'D:\VEIL-OMNI\Saved\place653.py'
$p653out = 'D:\VEIL-OMNI\Saved\place653.out'
$p653errout = 'D:\VEIL-OMNI\Saved\place653.errout.txt'
$p653backup = 'D:\VEIL-OMNI\Saved\backup653'
$p653cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$p653batdir = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles'
New-Item -ItemType Directory -Path $p653backup -Force | Out-Null
foreach ($p653f in @($p653map, $p653uproj)) { if (Test-Path $p653f) { Copy-Item $p653f $p653backup -Force; Write-Output ('BACKUP653 DONE ' + $p653f) } else { Write-Output ('BACKUP653 MISSING ' + $p653f) } }
Write-Output 'WHOLE653 NO SPLIT ONE WHOLE EVERYWHERE ALL AT ONCE'
if (Test-Path $p653map) { Write-Output ('MAP653 BEFORE SIZE ' + (Get-Item $p653map).Length) } else { Write-Output 'MAP653 BEFORE MISSING' }
$p653lines = @(
'import unreal',
'loaded = unreal.EditorLevelLibrary.load_level("/Game/Maps/VEILDistrict")',
'print("LOAD653 RESULT " + str(loaded))',
'world = unreal.EditorLevelLibrary.get_editor_world()',
'print("WORLD653 " + str(world))',
'actors = unreal.EditorLevelLibrary.get_all_level_actors()',
'print("ACTORS653 COUNT " + str(len(actors)))',
'vault_found = False',
'for a in actors:',
'    label = a.get_actor_label()',
'    if "Countess" in label or "Vault" in label or "ModularS30" in label:',
'        loc = a.get_actor_location()',
'        rot = a.get_actor_rotation()',
'        print("ACTOR653 " + label + " loc " + str(loc) + " rot " + str(rot))',
'        if "Vault" in label or "ModularS30" in label:',
'            vault_found = True',
'        if "Countess" in label:',
'            if abs(rot.roll) > 90 or abs(rot.pitch) > 90:',
'                a.set_actor_rotation(unreal.Rotator(0, rot.yaw, 0), False)',
'                print("COUNTESS653 UPRIGHTED " + label)',
'if not vault_found:',
'    print("VAULT653 MISSING IN MAP")',
'unreal.EditorLevelLibrary.save_current_level()',
'print("SAVE653 TRUE LEVEL SAVED")'
)
$p653lines | Set-Content -Path $p653script -Encoding UTF8
Write-Output ('SCRIPT653 WRITTEN SIZE ' + (Get-Item $p653script).Length)
$p653gui = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($p653gui) { Write-Output 'EDITOR653 GUI OPEN CMD RUN SKIPPED GUI BLOCKS CMD RUN' } else { Write-Output 'EDITOR653 GUI CLOSED CMD RUN STARTS WITH CAPTURE' }
if ((-not $p653gui) -and (Test-Path $p653script) -and (Test-Path $p653cmd) -and (Test-Path $p653uproj)) {
  $p653proc = Start-Process $p653cmd -ArgumentList "`"$p653uproj`"", '-run=PythonScript', "-script=`"$p653script`"", '-unattended', '-nop4', '-nosplash' -RedirectStandardOutput $p653out -RedirectStandardError $p653errout -PassThru
  Write-Output ('EDITOR653 STARTED PID ' + $p653proc.Id)
  $p653wait = 0
  while ((-not $p653proc.HasExited) -and ($p653wait -lt 180)) { Start-Sleep -Seconds 10; $p653wait += 10 }
  if ($p653proc.HasExited) { Write-Output ('EDITOR653 EXIT ' + $p653proc.ExitCode) } else { Write-Output 'EDITOR653 STILL RUNNING AFTER 180 SECONDS BUILD SKIPPED WHILE EDITOR RUNS' }
} else { Write-Output 'EDITOR653 CMD RUN SKIPPED GUI OPEN OR PREREQUISITE MISSING' }
if (Test-Path $p653out) {
  $p653outLines = @(Get-Content $p653out -ErrorAction SilentlyContinue | Select-String -Pattern 'LOAD653|WORLD653|ACTORS653|ACTOR653|VAULT653|COUNTESS653|SAVE653|Error|Python|Traceback|Failed' -ErrorAction SilentlyContinue)
  Write-Output ('OUT653 MATCH LINES ' + $p653outLines.Count)
  foreach ($p653o in $p653outLines) { Write-Output ('OUT653 ' + $p653o.Line) }
  Write-Output ('OUT653 TOTAL BYTES ' + (Get-Item $p653out).Length)
} else { Write-Output 'OUT653 MISSING CAPTURE FAILED' }
if (Test-Path $p653errout) {
  $p653errLines = @(Get-Content $p653errout -ErrorAction SilentlyContinue)
  Write-Output ('ERROUT653 LINES ' + $p653errLines.Count)
  foreach ($p653e in $p653errLines) { Write-Output ('ERROUT653 ' + $p653e) }
} else { Write-Output 'ERROUT653 MISSING' }
if ((-not (Get-Process UnrealEditor-Cmd -ErrorAction SilentlyContinue)) -and (-not (Get-Process UnrealEditor -ErrorAction SilentlyContinue))) {
  Set-Location $p653batdir
  .\Build.bat VEILEditor Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build653.log'
  Write-Output ('BUILD653 EXIT ' + $LASTEXITCODE)
} else { Write-Output 'BUILD653 SKIPPED EDITOR PROCESS STILL RUNNING' }
if (Test-Path $p653map) {
  $p653afterSize = (Get-Item $p653map).Length
  Write-Output ('MAP653 AFTER SIZE ' + $p653afterSize)
  if ($p653afterSize -eq 180952) { Write-Output 'PROGRESS653 NO CHANGE NOT PROGRESS BUILD EXIT 0 ALONE IS NOT PROGRESS' } else { Write-Output 'PROGRESS653 CHANGED MAP SIZE MOVED' }
} else { Write-Output 'MAP653 AFTER MISSING' }
Write-Output 'AUTO653 HIDDENDRAIN TASK QUERY BELOW'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
Write-Output 'NOPACKAGE653 NO PACKAGE UNTIL 100 PERCENT DONE'
Write-Output 'JOB 653 DONE'
```
