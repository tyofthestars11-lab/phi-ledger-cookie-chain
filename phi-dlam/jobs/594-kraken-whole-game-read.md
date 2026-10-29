<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 594 - KRAKEN WHOLE GAME READ (Ground: Tyree ordered do not stop until the game is whole not parts, so this one job reads the whole game at once, quest system, GameState, music, attack, controls, dialogue, Warden, Vault, world map, no patch, no build, no package, no map placement, no terminal work, Cyberpunk parked, so the whole finish lands from a whole read not parts. Every variable carries the p594 prefix.) ==='
$p594src = 'D:\VEIL-OMNI\Source\VEIL'
$p594pats = @('OMNIQuestSystem', 'PHI_GameState', 'PHI_DynamicMusic', 'PHI BOLT', 'BindKey', 'DT_Dialogue', 'WakeWarden', 'PHI_WorldDress_Vault', 'VEILDistrict', 'ToggleGodMode')
foreach ($p594pat in $p594pats) {
  $p594hits = @(Get-ChildItem -Path $p594src -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern $p594pat | Select-Object -First 5)
  Write-Output ('WHOLE594 COUNT ' + $p594hits.Count + ' ' + $p594pat)
  foreach ($p594h in $p594hits) { Write-Output ('WHOLE594 ' + $p594pat + ' ' + $p594h.Path + ' ' + $p594h.LineNumber) }
}
$p594map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
if (Test-Path $p594map) { $p594size = (Get-Item $p594map).Length; Write-Output ('MAP594 SIZE ' + $p594size) } else { Write-Output 'MAP594 MISSING' }
Write-Output 'PHI P594 VERDICT: KRAKEN WHOLE GAME READ ABOVE'
Write-Output 'JOB 594 DONE'
```
