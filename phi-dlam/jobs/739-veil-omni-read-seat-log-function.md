<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 739 - READ SEAT LOG FUNCTION AND REST (Ground: Job 738 read seat719 lines 60 to 130 showing main logs START, WORLD, ACTORS BEFORE, FLOOR, VAULT, yet the seat736 log searched Vault lines 0, Countess lines 2 Rig warnings only, SEAT lines 6 metadata and warnings only, SAVED lines 9 path matches only, map 626984 unchanged. No script log prints stood in the seat736 log. This job reads only: the seat719 script lines 1 to 59 to find where log writes, the script lines 131 to end, the seat736 log searched for START, WORLD, ACTORS, FLOOR prints, and a list of seat log files under Saved Logs. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$pyW = Join-Path $projW 'Saved\seat719.py'
Write-Output ('SCRIPT739 PRESENT ' + (Test-Path $pyW))
if (Test-Path $pyW) {
  Write-Output 'SCRIPT739 LINES 1 TO 59'
  Get-Content $pyW | Select-Object -First 59
  $totalLines = @(Get-Content $pyW).Count
  Write-Output ('SCRIPT739 TOTAL LINES ' + $totalLines)
  Write-Output 'SCRIPT739 LINES 131 TO END'
  Get-Content $pyW | Select-Object -Skip 130
}
$seatOut = Join-Path $projW 'Saved\Logs\VEIL_SEAT736_cmd_out.log'
Write-Output ('SEAT739 OUT PRESENT ' + (Test-Path $seatOut))
if (Test-Path $seatOut) {
  foreach ($term in @('START','WORLD','ACTORS','FLOOR')) {
    $found = @(Select-String -Path $seatOut -Pattern $term)
    Write-Output ('SEAT739 TERM ' + $term + ' LINES ' + $found.Count)
    foreach ($foundLine in $found) { Write-Output ('SEAT739 LINE ' + $foundLine.Line) }
  }
}
$logsDir = Join-Path $projW 'Saved\Logs'
Write-Output ('LOGS739 DIR PRESENT ' + (Test-Path $logsDir))
if (Test-Path $logsDir) {
  $seatFiles = @(Get-ChildItem $logsDir -File -ErrorAction SilentlyContinue | Where-Object { $_.Name -match 'SEAT' })
  Write-Output ('LOGS739 SEAT FILES ' + $seatFiles.Count)
  foreach ($seatFile in $seatFiles) { Write-Output ('LOGS739 FILE ' + $seatFile.Name + ' SIZE ' + $seatFile.Length + ' WRITE ' + $seatFile.LastWriteTime) }
}
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP739 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
