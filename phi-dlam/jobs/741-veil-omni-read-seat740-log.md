<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 741 - READ SEAT740 LOG (Ground: Job 740 backed up seat719, replaced the log print with unreal log, print after 0, unreal log after 1, seat Cmd started detached with new log names VEIL_SEAT740, map 626984 unchanged at that read. This job reads only: the seat740 log searched for SEAT719 prints, START, WORLD, ACTORS, VAULT, COUNTESS, NAVMESH, SAVE, DONE, GOLDEN PITCH, the seat740 log tail 40, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$seatOut = Join-Path $projW 'Saved\Logs\VEIL_SEAT740_cmd_out.log'
Write-Output ('SEAT741 OUT PRESENT ' + (Test-Path $seatOut))
if (Test-Path $seatOut) {
  foreach ($term in @('SEAT719','VAULT','COUNTESS','NAVMESH','SAVE','DONE','GOLDEN PITCH')) {
    $found = @(Select-String -Path $seatOut -Pattern $term)
    Write-Output ('SEAT741 TERM ' + $term + ' LINES ' + $found.Count)
    foreach ($foundLine in $found) { Write-Output ('SEAT741 LINE ' + $foundLine.Line) }
  }
  Write-Output 'SEAT741 OUT TAIL 40'
  Get-Content $seatOut | Select-Object -Last 40
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD741 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP741 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
