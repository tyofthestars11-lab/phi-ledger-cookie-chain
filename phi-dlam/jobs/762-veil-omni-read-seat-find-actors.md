<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 762 - READ SEAT FIND ACTORS (Ground: Job 761 read seat719 NavMesh lines: line 162 nav_actors = find_actors NavMeshBoundsVolume, line 164 NAVMESH ALREADY PRESENT, line 168 spawn NavMeshBoundsVolume at 0,0,floor_z + 500, line 297 NAVMESH PRESENT len find_actors NavMeshBoundsVolume > 0, map 629620. Job 760 out file showed RecastNavMesh-Default only, no NavMeshBoundsVolume label. This job reads only: seat719.py find_actors definition lines and its NavMesh block lines 155 to 190 whole, no edits, no save, no map load. It cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$seatW = Join-Path $projW 'Saved\seat719.py'
Write-Output ('NAV762 SEAT PRESENT ' + (Test-Path $seatW))
if (Test-Path $seatW) {
  $linesW = Get-Content $seatW
  Write-Output ('NAV762 SEAT LINES ' + $linesW.Count)
  for ($iW = 0; $iW -lt $linesW.Count; $iW++) {
    if ($linesW[$iW] -match 'def find_actors|find_actors') {
      Write-Output ('NAV762 LINE ' + ($iW + 1) + ' ' + $linesW[$iW])
    }
  }
  Write-Output 'NAV762 BLOCK 155 TO 190'
  for ($iW = 154; $iW -lt 190; $iW++) {
    if ($iW -lt $linesW.Count) { Write-Output ('NAV762 BLOCK ' + ($iW + 1) + ' ' + $linesW[$iW]) }
  }
}
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP762 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
