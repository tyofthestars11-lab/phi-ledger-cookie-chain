<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 760 - READ NAVMESH759 OUT FILE (Ground: Job 759 rewrote verify_navmesh.py to append to Saved verify_navmesh_out.txt, backup True, old out deleted True, script present True, Cmd started detached, map 629620 unchanged at that read. This job reads only: verify_navmesh_out.txt whole, NavMesh759 Cmd out log tail, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$outFileW = Join-Path $projW 'Saved\verify_navmesh_out.txt'
Write-Output ('NAV760 OUT PRESENT ' + (Test-Path $outFileW))
if (Test-Path $outFileW) {
  Write-Output ('NAV760 OUT BYTES ' + (Get-Item $outFileW).Length)
  Get-Content $outFileW
}
$cmdOutW = Join-Path $projW 'Saved\Logs\VEIL_NAVMESH759_cmd_out.log'
Write-Output ('NAV760 CMD OUT PRESENT ' + (Test-Path $cmdOutW))
if (Test-Path $cmdOutW) {
  Write-Output 'NAV760 CMD OUT TAIL 20'
  Get-Content $cmdOutW | Select-Object -Last 20
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD760 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB)) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP760 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
