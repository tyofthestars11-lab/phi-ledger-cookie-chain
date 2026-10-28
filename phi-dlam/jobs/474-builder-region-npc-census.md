<!-- PHI-DIRECT -->
```powershell
Write-Output '=== BUILDER REGION AND NPC CENSUS 474 - THE GROUND THE LIFE TRANCHE STANDS ON (Ground: Tyree holds the full game explanation and his Pi adds a witness read pointing at population, quests, streaming and campaign wiring, and the accepted kernel is the Nest populated with living NPCs and its first quest. Before that tranche is authored, its ground gets read whole, because the population seat must stand on the builder real region list and the real Paragon mesh paths, never on a generic shape. One, this job prints every builder function signature in VEILWorldBuilder h and cpp, the Build family whole, so the record names which regions the builder already knows, Hub and any Nest or Spire among them. Two, it prints the GameMode spawn region, forty lines from the builder spawn down through the givers, fragments and cache, the exact seat where population already rides. Three, it censuses the Paragon mesh shelves: for Greystone, Murdock, Revenant and the Minions, the skeletal mesh uasset names under each pack, first entries each, so the NPC bodies get cited by their true paths. The verdict in one line: REGION CENSUS with the builder function count. Read only, and every variable carries the rc474 prefix.) ==='
$rc474bh = 'D:\VEIL-OMNI\Source\VEIL\Public\World\VEILWorldBuilder.h'
$rc474bc = 'D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp'
$rc474gm = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp'
$rc474sigs = @()
foreach ($rc474f in @($rc474bh, $rc474bc)) {
  if (Test-Path $rc474f) {
    $rc474lines = @(Get-Content $rc474f)
    for ($rc474i = 0; $rc474i -lt $rc474lines.Count; $rc474i++) {
      if ($rc474lines[$rc474i] -match 'Build[A-Z]\w*\s*\(') { $rc474sigs += ($rc474i + 1); Write-Output ('SIG ' + (Split-Path $rc474f -Leaf) + ' ' + ($rc474i + 1) + ' ' + $rc474lines[$rc474i].Trim()) }
    }
  }
}
$rc474gl = @(Get-Content $rc474gm)
Write-Output ('GM LINES=' + $rc474gl.Count)
for ($rc474s = 69; $rc474s -lt [Math]::Min(140, $rc474gl.Count); $rc474s++) { Write-Output ('GM ' + ($rc474s + 1) + ' ' + $rc474gl[$rc474s].Trim()) }
$rc474packs = @('ParagonGreystone', 'ParagonMurdock', 'ParagonRevenant', 'ParagonMinions')
foreach ($rc474p in $rc474packs) {
  $rc474root = 'D:\VEIL-OMNI\Content\' + $rc474p
  if (Test-Path $rc474root) {
    $rc474meshes = @(Get-ChildItem $rc474root -Recurse -Filter 'SK_*.uasset' -ErrorAction SilentlyContinue | Select-Object -First 6)
    Write-Output ('PACK ' + $rc474p + ' sk=' + $rc474meshes.Count)
    foreach ($rc474mm in $rc474meshes) { Write-Output ('SK ' + $rc474mm.FullName.Replace('D:\VEIL-OMNI\Content\', '/Game/').Replace('\', '/').Replace('.uasset', '')) }
  } else { Write-Output ('PACK ' + $rc474p + ' ABSENT') }
}
Write-Output ('PHI RC474 VERDICT: REGION CENSUS sigs=' + $rc474sigs.Count)
Write-Output 'JOB 474 DONE'
```
