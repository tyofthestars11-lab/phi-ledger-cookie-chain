<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 513 - THE BLACK WORLD READ AT ITS ADDRESS (Ground: his hands closed the controller question in the game own window - the pad arrives there; the editor was the wall. What stands open in his photo is the world itself: the runner, the monument, the ground all render as black shapes against a blue sky, for hours. Everything stands and nothing is lit or textured. This job reads the two witnesses that name the fault: the fresh log the standalone window just wrote, pulled for its pad proof, its body check, and every material or load warning line; and the world builder source at the exact lines where blocks take their material and tint. Nothing is patched here - the print names the address and the fix files from it in the same motion. Every variable carries the p513 prefix.) ==='
$p513logs = 'D:\VEIL-OMNI\Saved\Logs'
$p513new = Get-ChildItem $p513logs -Filter '*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($p513new) {
  Write-Output ('LOG ' + $p513new.Name + ' at ' + $p513new.LastWriteTime)
  $p513hits = Select-String -Path $p513new.FullName -Pattern 'PAD PROOF|BODY CHECK' -ErrorAction SilentlyContinue | Select-Object -Last 4
  foreach ($p513h in $p513hits) { Write-Output ('PROOF ' + $p513h.Line) }
  $p513warn = Select-String -Path $p513new.FullName -Pattern 'material|Failed to load|Missing' -ErrorAction SilentlyContinue | Select-Object -First 25
  foreach ($p513w in $p513warn) { Write-Output ('WARN ' + $p513w.Line) }
  Write-Output ('WARN COUNT SHOWN=' + ($p513warn | Measure-Object).Count)
}
$p513src = 'D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp'
$p513lines = Get-Content $p513src -ErrorAction SilentlyContinue
Write-Output ('BUILDER LINES=' + ($p513lines | Measure-Object).Count)
$p513i = 0
foreach ($p513line in $p513lines) {
  $p513i = $p513i + 1
  if ($p513line -match 'SpawnBlock|Material|Tint|SetMaterial|Dynamic|Emissive') { Write-Output ('B513 ' + $p513i + ': ' + $p513line.Trim()) }
}
Write-Output 'PHI P513 VERDICT: BLACK WORLD READ PRINTED ABOVE'
Write-Output 'JOB 513 DONE'
```
