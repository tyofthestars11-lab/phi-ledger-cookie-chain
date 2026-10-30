<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 763 - READ FIND ACTORS BODY (Ground: Job 762 read seat719 lines: line 46 def find_actors substring, line 162 nav_actors = find_actors NavMeshBoundsVolume, line 164 ALREADY PRESENT, line 168 spawn NavMeshBoundsVolume at 0,0,floor_z + 500, scale 20,20,4, RebuildNavigation, map 629620. Job 760 out file showed RecastNavMesh-Default only, no NavMeshBoundsVolume label. This job reads only: seat719.py lines 40 to 110 whole, find_actors body and its matching rule, no edits, no save, no map load. It cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$seatW = Join-Path $projW 'Saved\seat719.py'
Write-Output ('NAV763 SEAT PRESENT ' + (Test-Path $seatW))
if (Test-Path $seatW) {
  $linesW = Get-Content $seatW
  Write-Output ('NAV763 SEAT LINES ' + $linesW.Count)
  Write-Output 'NAV763 BLOCK 40 TO 110'
  for ($iW = 39; $iW -lt 110; $iW++) {
    if ($iW -lt $linesW.Count) { Write-Output ('NAV763 BLOCK ' + ($iW + 1) + ' ' + $linesW[$iW]) }
  }
}
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP763 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
