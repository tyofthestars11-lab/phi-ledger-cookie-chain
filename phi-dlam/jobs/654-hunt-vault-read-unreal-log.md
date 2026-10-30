<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 654 - HUNT VAULT READ UNREAL LOG (Ground: Tyree order file 654 hunt Vault asset and read actor lines from Unreal log plus 653 result load and save now work script executed successfully no filename error but actor print lines not in stdout capture and Vault asset found 0 times in Content by job 648. This job hunts the Vault asset in project Content and reads the newest Unreal log for the place653 actor lines. No editor run, no build, no package, no ledger edit. Every variable carries the p654 prefix.) ==='
$p654content = 'D:\VEIL-OMNI\Content'
$p654logs = 'D:\VEIL-OMNI\Saved\Logs'
$p654map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
Write-Output 'WHOLE654 NO SPLIT ONE WHOLE EVERYWHERE ALL AT ONCE'
if (Test-Path $p654map) { Write-Output 'MAP654 PRESENT VEILDISTRICT' } else { Write-Output 'MAP654 MISSING VEILDISTRICT' }
Write-Output 'VAULT654 HUNT IN PROJECT CONTENT'
foreach ($p654pat in @('*ModularS30*', '*Vault*', '*Countess_AnimBlueprint*', '*SM_Countess*')) {
  $p654found = @(Get-ChildItem -Path $p654content -Recurse -File -Filter $p654pat -ErrorAction SilentlyContinue)
  Write-Output ('HUNT654 PATTERN ' + $p654pat + ' COUNT ' + $p654found.Count)
  foreach ($p654f in ($p654found | Select-Object -First 20)) { Write-Output ('HUNT654 FILE ' + $p654f.FullName) }
}
Write-Output 'LOG654 NEWEST UNREAL LOG ACTOR LINES'
if (Test-Path $p654logs) {
  $p654logFiles = @(Get-ChildItem $p654logs -Filter *.log | Sort-Object LastWriteTime -Descending | Select-Object -First 2)
  foreach ($p654lf in $p654logFiles) { Write-Output ('LOG654 FILE ' + $p654lf.Name + ' WRITTEN ' + $p654lf.LastWriteTime) }
  if ($p654logFiles.Count -gt 0) {
    $p654match = @(Get-Content $p654logFiles[0].FullName -ErrorAction SilentlyContinue | Select-String -Pattern 'LOAD653|WORLD653|ACTORS653|ACTOR653|VAULT653|COUNTESS653|SAVE653|Load Level|VEILDistrict' -ErrorAction SilentlyContinue)
    Write-Output ('LOG654 MATCH LINES ' + $p654match.Count)
    foreach ($p654m in $p654match) { Write-Output ('LOG654 ' + $p654m.Line) }
    $p654save = @(Get-Content $p654logFiles[0].FullName -ErrorAction SilentlyContinue | Select-String -Pattern 'SaveCurrentLevel|save the level|Saved' -ErrorAction SilentlyContinue | Select-Object -Last 10)
    foreach ($p654s in $p654save) { Write-Output ('LOG654 SAVE ' + $p654s.Line) }
  }
} else { Write-Output 'LOG654 LOGS FOLDER MISSING' }
Write-Output 'AUTO654 HIDDENDRAIN TASK QUERY BELOW'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
Write-Output 'NOPACKAGE654 NO PACKAGE UNTIL 100 PERCENT DONE'
Write-Output 'JOB 654 DONE'
```
