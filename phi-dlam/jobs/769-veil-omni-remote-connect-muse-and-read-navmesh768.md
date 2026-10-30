<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 769 - REMOTE CONNECT MUSE AND READ NAVMESH768 (Ground: Tyree whole: REMOTE CONNECT MUSE IS THE COMMAND, not local, not MUSE REMOTE 766 CONNECT YOU, not MUSE LOCAL 764 NAVMESH AWAKE. Remote Muse is in control, not local assumptions, anti hallucination protocol job 768 filed. Job 766 closed GUI and Cmd, Cmd after 0, Cmd started, map 629620. Job 767 read too early, out False, Cmd 90200 running. This job reads only: Saved anti_hallucination_protocol_dlam.txt present, Saved seat_navmesh764_out.txt whole, NavMesh766 Cmd out log tail, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$protoW = Join-Path $projW 'Saved\anti_hallucination_protocol_dlam.txt'
Write-Output ('PROTO769 PRESENT ' + (Test-Path $protoW))
$outFileW = Join-Path $projW 'Saved\seat_navmesh764_out.txt'
Write-Output ('NAV769 OUT PRESENT ' + (Test-Path $outFileW))
if (Test-Path $outFileW) {
  Write-Output ('NAV769 OUT BYTES ' + (Get-Item $outFileW).Length)
  Get-Content $outFileW
}
$cmdOutW = Join-Path $projW 'Saved\Logs\VEIL_NAVMESH766_cmd_out.log'
Write-Output ('NAV769 CMD OUT PRESENT ' + (Test-Path $cmdOutW))
if (Test-Path $cmdOutW) {
  Write-Output 'NAV769 CMD OUT TAIL 20'
  Get-Content $cmdOutW | Select-Object -Last 20
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD769 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB)) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP769 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'REMOTE CONNECT MUSE'
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
