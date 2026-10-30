<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 761 - READ SEAT NAVMESH SECTION (Ground: Job 760 landed NavMesh out file 5641 bytes: MAP LOADED, ACTORS TOTAL 423, RecastNavMesh-Default CLASS RecastNavMesh LOC 0,0,0, PHI_FLOOR_PAD 0,0,-50, PHI_GROUND 127.98,-416.29,-50, PHI_GROUND Hub Nest Spire OmniDistrict MegastructureDeep all -50, PHI_WORLD 00 to 23, PHI_DRESS2 00 to 23, DONE, Success 0 errors 13 warnings 0.70 seconds, Recast warning again, map 629620 unchanged. No NavMeshBoundsVolume actor listed in 760, only RecastNavMesh-Default. This job reads only: seat719.py NavMesh section lines, how it checks and seats NavMesh, no edits, no save, no map load. It cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$seatW = Join-Path $projW 'Saved\seat719.py'
Write-Output ('NAV761 SEAT PRESENT ' + (Test-Path $seatW))
if (Test-Path $seatW) {
  $linesW = Get-Content $seatW
  Write-Output ('NAV761 SEAT LINES ' + $linesW.Count)
  for ($iW = 0; $iW -lt $linesW.Count; $iW++) {
    if ($linesW[$iW] -match 'NAVMESH|NavMesh|Recast|BoundsVolume') {
      Write-Output ('NAV761 LINE ' + ($iW + 1) + ' ' + $linesW[$iW])
    }
  }
}
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP761 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
