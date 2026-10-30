<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 758 - READ NAVMESH757 LOG (Ground: Job 757 wrote NavMesh script, Cmd present, Cmd started detached, map 629620 unchanged at that read. This job reads only: the NavMesh757 log searched for NAVMESH MAP LOADED, NAVMESH MAP LOAD ERROR, NAVMESH ACTORS TOTAL, NAVMESH ACTOR, NAVMESH DONE, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$navOut = Join-Path $projW 'Saved\Logs\VEIL_NAVMESH757_cmd_out.log'
Write-Output ('NAV758 OUT PRESENT ' + (Test-Path $navOut))
if (Test-Path $navOut) {
  foreach ($term in @('NAVMESH MAP LOADED','NAVMESH MAP LOAD ERROR','NAVMESH ACTORS TOTAL','NAVMESH ACTOR','NAVMESH DONE')) {
    $found = @(Select-String -Path $navOut -Pattern $term)
    Write-Output ('NAV758 TERM ' + $term + ' LINES ' + $found.Count)
    foreach ($foundLine in $found) { Write-Output ('NAV758 LINE ' + $foundLine.Line) }
  }
  Write-Output 'NAV758 OUT TAIL 30'
  Get-Content $navOut | Select-Object -Last 30
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD758 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP758 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
