<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 744 - READ SEAT OUT FILE AND SEAT743 LOG (Ground: Job 743 backed up seat719, unreal log before 1 after 1, file write after 1, log line at seat719.py line 36 verified, seat Cmd started detached with new log names VEIL_SEAT743, new Cmd 89876, map 626984 unchanged at that read. This job reads only: Saved seat719_out.txt whole if present, its line count and size, the seat743 log searched for SEAT719, VAULT, COUNTESS, NAVMESH, SAVE, DONE, GOLDEN PITCH, the seat743 log tail 20, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$outFile = Join-Path $projW 'Saved\seat719_out.txt'
Write-Output ('OUT744 PRESENT ' + (Test-Path $outFile))
if (Test-Path $outFile) {
  $outLines = Get-Content $outFile
  Write-Output ('OUT744 LINES ' + $outLines.Count + ' SIZE ' + (Get-Item $outFile).Length)
  Write-Output 'OUT744 WHOLE FILE'
  Get-Content $outFile
}
$seatOut = Join-Path $projW 'Saved\Logs\VEIL_SEAT743_cmd_out.log'
Write-Output ('SEAT744 OUT PRESENT ' + (Test-Path $seatOut))
if (Test-Path $seatOut) {
  foreach ($term in @('SEAT719','VAULT','COUNTESS','NAVMESH','SAVE','DONE','GOLDEN PITCH')) {
    $found = @(Select-String -Path $seatOut -Pattern $term)
    Write-Output ('SEAT744 TERM ' + $term + ' LINES ' + $found.Count)
    foreach ($foundLine in $found) { Write-Output ('SEAT744 LINE ' + $foundLine.Line) }
  }
  Write-Output 'SEAT744 OUT TAIL 20'
  Get-Content $seatOut | Select-Object -Last 20
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD744 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP744 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
