<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 655 - LIST ACTORS HUNT ANIMBLUEPRINT (Ground: Tyree order file 655 list all 92 actor labels and hunt Countess AnimBlueprint plus 654 result load true world 92 actors save true Vault missing AnimBlueprint 0 SM_Countess 12. This job loads VEILDistrict, prints every actor label, then hunts AnimBlueprint assets, then reads the Unreal log where those prints land. No build, no package, no ledger edit. Every variable carries the p655 prefix.) ==='
$p655uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p655map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p655script = 'D:\VEIL-OMNI\Saved\place655.py'
$p655out = 'D:\VEIL-OMNI\Saved\place655.out'
$p655errout = 'D:\VEIL-OMNI\Saved\place655.errout.txt'
$p655backup = 'D:\VEIL-OMNI\Saved\backup655'
$p655logs = 'D:\VEIL-OMNI\Saved\Logs'
$p655content = 'D:\VEIL-OMNI\Content'
$p655cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
New-Item -ItemType Directory -Path $p655backup -Force | Out-Null
foreach ($p655f in @($p655map, $p655uproj)) { if (Test-Path $p655f) { Copy-Item $p655f $p655backup -Force; Write-Output ('BACKUP655 DONE ' + $p655f) } else { Write-Output ('BACKUP655 MISSING ' + $p655f) } }
Write-Output 'WHOLE655 NO SPLIT ONE WHOLE EVERYWHERE ALL AT ONCE'
if (Test-Path $p655map) { Write-Output 'MAP655 PRESENT VEILDISTRICT' } else { Write-Output 'MAP655 MISSING VEILDISTRICT' }
$p655lines = @(
'import unreal',
'loaded = unreal.EditorLevelLibrary.load_level("/Game/Maps/VEILDistrict")',
'print("LOAD655 RESULT " + str(loaded))',
'actors = unreal.EditorLevelLibrary.get_all_level_actors()',
'print("ACTORS655 COUNT " + str(len(actors)))',
'for a in actors:',
'    label = a.get_actor_label()',
'    loc = a.get_actor_location()',
'    rot = a.get_actor_rotation()',
'    print("ACTOR655 " + label + " loc " + str(loc) + " rot " + str(rot))',
'print("SAVE655 DONE NO EDIT")'
)
$p655lines | Set-Content -Path $p655script -Encoding UTF8
Write-Output ('SCRIPT655 WRITTEN SIZE ' + (Get-Item $p655script).Length)
$p655gui = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($p655gui) { Write-Output 'EDITOR655 GUI OPEN CMD RUN SKIPPED GUI BLOCKS CMD RUN' } else { Write-Output 'EDITOR655 GUI CLOSED CMD RUN STARTS WITH CAPTURE' }
if ((-not $p655gui) -and (Test-Path $p655script) -and (Test-Path $p655cmd) -and (Test-Path $p655uproj)) {
  $p655proc = Start-Process $p655cmd -ArgumentList "`"$p655uproj`"", '-run=PythonScript', "-script=`"$p655script`"", '-unattended', '-nop4', '-nosplash' -RedirectStandardOutput $p655out -RedirectStandardError $p655errout -PassThru
  Write-Output ('EDITOR655 STARTED PID ' + $p655proc.Id)
  $p655wait = 0
  while ((-not $p655proc.HasExited) -and ($p655wait -lt 180)) { Start-Sleep -Seconds 10; $p655wait += 10 }
  if ($p655proc.HasExited) { Write-Output ('EDITOR655 EXIT ' + $p655proc.ExitCode) } else { Write-Output 'EDITOR655 STILL RUNNING AFTER 180 SECONDS' }
} else { Write-Output 'EDITOR655 CMD RUN SKIPPED GUI OPEN OR PREREQUISITE MISSING' }
Write-Output 'LOG655 NEWEST UNREAL LOG ACTOR LINES'
if (Test-Path $p655logs) {
  $p655logFiles = @(Get-ChildItem $p655logs -Filter *.log | Sort-Object LastWriteTime -Descending | Select-Object -First 1)
  foreach ($p655lf in $p655logFiles) { Write-Output ('LOG655 FILE ' + $p655lf.Name + ' WRITTEN ' + $p655lf.LastWriteTime) }
  if ($p655logFiles.Count -gt 0) {
    $p655match = @(Get-Content $p655logFiles[0].FullName -ErrorAction SilentlyContinue | Select-String -Pattern 'LOAD655|ACTORS655|ACTOR655|SAVE655' -ErrorAction SilentlyContinue)
    Write-Output ('LOG655 MATCH LINES ' + $p655match.Count)
    foreach ($p655m in $p655match) { Write-Output ('LOG655 ' + $p655m.Line) }
  }
} else { Write-Output 'LOG655 LOGS FOLDER MISSING' }
Write-Output 'ANIM655 HUNT IN PROJECT CONTENT'
foreach ($p655pat in @('*Countess_AnimBlueprint*', '*AnimBlueprint*', '*Countess*Animation*')) {
  $p655found = @(Get-ChildItem -Path $p655content -Recurse -File -Filter $p655pat -ErrorAction SilentlyContinue)
  Write-Output ('HUNT655 PATTERN ' + $p655pat + ' COUNT ' + $p655found.Count)
  foreach ($p655f in ($p655found | Select-Object -First 20)) { Write-Output ('HUNT655 FILE ' + $p655f.FullName) }
}
Write-Output 'AUTO655 HIDDENDRAIN TASK QUERY BELOW'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
Write-Output 'NOPACKAGE655 NO PACKAGE UNTIL 100 PERCENT DONE'
Write-Output 'JOB 655 DONE'
```
