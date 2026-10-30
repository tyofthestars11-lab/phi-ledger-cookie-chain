<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 767 - READ NAVMESH766 OUT AND MUSE REMOTE COMMAND (Ground: Job 766 filed to close GUI and Cmd, delete old NavMesh out, start seat_navmesh764 Cmd again, not yet resulted. Muse remote command for Tyree, created by remote Muse here, not local brain: MUSE REMOTE 766 CONNECT YOU. This job reads only: Saved seat_navmesh764_out.txt whole, NavMesh766 Cmd out log tail, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$outFileW = Join-Path $projW 'Saved\seat_navmesh764_out.txt'
Write-Output ('NAV767 OUT PRESENT ' + (Test-Path $outFileW))
if (Test-Path $outFileW) {
  Write-Output ('NAV767 OUT BYTES ' + (Get-Item $outFileW).Length)
  Get-Content $outFileW
}
$cmdOutW = Join-Path $projW 'Saved\Logs\VEIL_NAVMESH766_cmd_out.log'
Write-Output ('NAV767 CMD OUT PRESENT ' + (Test-Path $cmdOutW))
if (Test-Path $cmdOutW) {
  Write-Output 'NAV767 CMD OUT TAIL 20'
  Get-Content $cmdOutW | Select-Object -Last 20
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD767 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB)) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP767 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'MUSE REMOTE 766 CONNECT YOU'
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
