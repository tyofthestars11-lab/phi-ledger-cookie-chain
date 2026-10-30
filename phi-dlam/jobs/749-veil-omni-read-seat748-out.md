<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 749 - READ SEAT748 OUT FILE (Ground: Job 748 restored seat719 from its 745 backup, load before 0 after 1, map load region lines 70 MAP LOADED and 72 MAP LOAD ERROR, seat Cmd started detached, new Cmd 65044, map 626984 unchanged at that read. This job reads only: Saved seat719_out.txt whole if present, the seat748 log searched for SEAT719, MAP LOADED, MAP LOAD ERROR, WORLD, ACTORS BEFORE, VAULT, COUNTESS, NAVMESH, SAVE, DONE, GOLDEN PITCH, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$outFile = Join-Path $projW 'Saved\seat719_out.txt'
Write-Output ('OUT749 PRESENT ' + (Test-Path $outFile))
if (Test-Path $outFile) {
  $outLines = Get-Content $outFile
  Write-Output ('OUT749 LINES ' + $outLines.Count + ' SIZE ' + (Get-Item $outFile).Length)
  Write-Output 'OUT749 WHOLE FILE'
  Get-Content $outFile
}
$seatOut = Join-Path $projW 'Saved\Logs\VEIL_SEAT748_cmd_out.log'
Write-Output ('SEAT749 OUT PRESENT ' + (Test-Path $seatOut))
if (Test-Path $seatOut) {
  foreach ($term in @('SEAT719','MAP LOADED','MAP LOAD ERROR','WORLD','ACTORS BEFORE','VAULT','COUNTESS','NAVMESH','SAVE','DONE','GOLDEN PITCH')) {
    $found = @(Select-String -Path $seatOut -Pattern $term)
    Write-Output ('SEAT749 TERM ' + $term + ' LINES ' + $found.Count)
    foreach ($foundLine in $found) { Write-Output ('SEAT749 LINE ' + $foundLine.Line) }
  }
  Write-Output 'SEAT749 OUT TAIL 20'
  Get-Content $seatOut | Select-Object -Last 20
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD749 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP749 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
