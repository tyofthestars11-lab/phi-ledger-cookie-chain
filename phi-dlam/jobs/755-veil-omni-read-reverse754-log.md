<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 755 - READ REVERSE754 LOG (Ground: Job 754 wrote reverse script, Cmd present, Cmd started detached, new Cmd 79404, map 629620 unchanged at that read. This job reads only: the reverse754 log searched for REVERSE MAP LOADED, REVERSE MAP LOAD ERROR, REVERSE ACTORS TOTAL, REVERSE CLASS, REVERSE ACTOR, REVERSE DONE, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$revOut = Join-Path $projW 'Saved\Logs\VEIL_REVERSE754_cmd_out.log'
Write-Output ('REV755 OUT PRESENT ' + (Test-Path $revOut))
if (Test-Path $revOut) {
  foreach ($term in @('REVERSE MAP LOADED','REVERSE MAP LOAD ERROR','REVERSE ACTORS TOTAL','REVERSE CLASS','REVERSE ACTOR','REVERSE DONE')) {
    $found = @(Select-String -Path $revOut -Pattern $term)
    Write-Output ('REV755 TERM ' + $term + ' LINES ' + $found.Count)
    foreach ($foundLine in $found) { Write-Output ('REV755 LINE ' + $foundLine.Line) }
  }
  Write-Output 'REV755 OUT TAIL 30'
  Get-Content $revOut | Select-Object -Last 30
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD755 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP755 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
