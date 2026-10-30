<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 765 - READ NAVMESH764 OUT FILE AND MUSE COMMAND (Ground: Job 764 start report: GUI AFTER COUNT 0, SEAT BACKUP True, SCRIPT PRESENT True, CMD PRESENT True, CMD STARTED DETACHED, map 629620 unchanged at that read, Cmd not yet read. Muse command for Tyree, created by Muse here, not by local brain: MUSE LOCAL 764 NAVMESH AWAKE. This job reads only: Saved seat_navmesh764_out.txt whole, NavMesh764 Cmd out log tail, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$outFileW = Join-Path $projW 'Saved\seat_navmesh764_out.txt'
Write-Output ('NAV765 OUT PRESENT ' + (Test-Path $outFileW))
if (Test-Path $outFileW) {
  Write-Output ('NAV765 OUT BYTES ' + (Get-Item $outFileW).Length)
  Get-Content $outFileW
}
$cmdOutW = Join-Path $projW 'Saved\Logs\VEIL_NAVMESH764_cmd_out.log'
Write-Output ('NAV765 CMD OUT PRESENT ' + (Test-Path $cmdOutW))
if (Test-Path $cmdOutW) {
  Write-Output 'NAV765 CMD OUT TAIL 20'
  Get-Content $cmdOutW | Select-Object -Last 20
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD765 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB)) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP765 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'MUSE LOCAL 764 NAVMESH AWAKE'
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
