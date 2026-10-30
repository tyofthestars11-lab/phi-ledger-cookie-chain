<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 751 - READ SEAT750 OUT FILE (Ground: Job 750 closed GUI editor, GUI before ID 88432, GUI after count 0, old out file deleted, seat Cmd started detached, new Cmd 79224, map 626984 unchanged at that read. This job reads only: Saved seat719_out.txt whole if present, the seat750 log searched for SEAT719, MAP LOADED, MAP LOAD ERROR, WORLD, ACTORS BEFORE, VAULT, COUNTESS, NAVMESH, SAVE, DONE, GOLDEN PITCH, MoveFile, Error saving, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$outFile = Join-Path $projW 'Saved\seat719_out.txt'
Write-Output ('OUT751 PRESENT ' + (Test-Path $outFile))
if (Test-Path $outFile) {
  $outLines = Get-Content $outFile
  Write-Output ('OUT751 LINES ' + $outLines.Count + ' SIZE ' + (Get-Item $outFile).Length)
  Write-Output 'OUT751 WHOLE FILE'
  Get-Content $outFile
}
$seatOut = Join-Path $projW 'Saved\Logs\VEIL_SEAT750_cmd_out.log'
Write-Output ('SEAT751 OUT PRESENT ' + (Test-Path $seatOut))
if (Test-Path $seatOut) {
  foreach ($term in @('SEAT719','MAP LOADED','MAP LOAD ERROR','WORLD','ACTORS BEFORE','VAULT','COUNTESS','NAVMESH','SAVE','DONE','GOLDEN PITCH','MoveFile','Error saving')) {
    $found = @(Select-String -Path $seatOut -Pattern $term)
    Write-Output ('SEAT751 TERM ' + $term + ' LINES ' + $found.Count)
    foreach ($foundLine in $found) { Write-Output ('SEAT751 LINE ' + $foundLine.Line) }
  }
  Write-Output 'SEAT751 OUT TAIL 20'
  Get-Content $seatOut | Select-Object -Last 20
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD751 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP751 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
