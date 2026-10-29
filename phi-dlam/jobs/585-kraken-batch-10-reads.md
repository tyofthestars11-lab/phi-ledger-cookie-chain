<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 585 - KRAKEN BATCH 10 READS (Ground: Tyree counted in 1s for a while and ordered 10 to 1 something kraken them, so this one job kraken packs 10 reads into 1 job, Vault Dress class, Dynamic Music state, Attack Bolt, Controls Binding, World Actors, Quest Givers, Warden Spawn, Dialogue Table, Editor Plugins, Quest Screen, no patch, no build, no package, no map placement, no terminal work, Cyberpunk parked, so the next patch lands from a read not a guess. Every variable carries the p585 prefix.) ==='
$p585src = 'D:\VEIL-OMNI\Source\VEIL'
$p585pats = @('PHI_WorldDress_Vault', 'DynamicMusic', 'PHI BOLT', 'BindKey', 'PHI_WORLD', 'Quest', 'WakeWarden', 'DT_Dialogue', 'AllToolsets', 'PhiQuestScreen')
foreach ($p585pat in $p585pats) {
  $p585hits = @(Get-ChildItem -Path $p585src -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern $p585pat | Select-Object -First 10)
  foreach ($p585h in $p585hits) { Write-Output ('KRAKEN585 ' + $p585pat + ' ' + $p585h.Path + ' ' + $p585h.LineNumber + ' ' + $p585h.Line.Trim()) }
}
Write-Output 'PHI P585 VERDICT: KRAKEN BATCH 10 READS ABOVE'
Write-Output 'JOB 585 DONE'
```
