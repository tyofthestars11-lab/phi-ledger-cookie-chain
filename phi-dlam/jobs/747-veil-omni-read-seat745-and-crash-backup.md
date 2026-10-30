<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 747 - READ SEAT745 OUT AND CRASH BACKUP LOG (Ground: Job 745 backed up seat719, load before 0 after 1, seat Cmd started detached with new log names VEIL_SEAT745, new Cmd 86576, map 626984 unchanged at that read. Job 746 read GPU crash log, dump file present False, VEIL log GPU lines 18, D3D lines 17, Crash lines 7, Fatal lines 0, newest VEIL log at 16.09, crash backup log VEIL_2-backup-2026.10.30-22.06.53.log size 372291 not yet searched. This job reads only: Saved seat719_out.txt whole if present, the seat745 log searched for SEAT719, MAP LOAD, VAULT, COUNTESS, NAVMESH, SAVE, DONE, GOLDEN PITCH, the crash backup log searched for GPU, D3D, Crash, Fatal, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$outFile = Join-Path $projW 'Saved\seat719_out.txt'
Write-Output ('OUT747 PRESENT ' + (Test-Path $outFile))
if (Test-Path $outFile) {
  $outLines = Get-Content $outFile
  Write-Output ('OUT747 LINES ' + $outLines.Count + ' SIZE ' + (Get-Item $outFile).Length)
  Write-Output 'OUT747 WHOLE FILE'
  Get-Content $outFile
}
$seatOut = Join-Path $projW 'Saved\Logs\VEIL_SEAT745_cmd_out.log'
Write-Output ('SEAT747 OUT PRESENT ' + (Test-Path $seatOut))
if (Test-Path $seatOut) {
  foreach ($term in @('SEAT719','MAP LOAD','VAULT','COUNTESS','NAVMESH','SAVE','DONE','GOLDEN PITCH')) {
    $found = @(Select-String -Path $seatOut -Pattern $term)
    Write-Output ('SEAT747 TERM ' + $term + ' LINES ' + $found.Count)
    foreach ($foundLine in $found) { Write-Output ('SEAT747 LINE ' + $foundLine.Line) }
  }
  Write-Output 'SEAT747 OUT TAIL 20'
  Get-Content $seatOut | Select-Object -Last 20
}
$crashLog = Join-Path $projW 'Saved\Logs\VEIL_2-backup-2026.10.30-22.06.53.log'
Write-Output ('CRASH747 LOG PRESENT ' + (Test-Path $crashLog))
if (Test-Path $crashLog) {
  foreach ($term in @('GPU','D3D','Crash','Fatal')) {
    $found = @(Select-String -Path $crashLog -Pattern $term)
    Write-Output ('CRASH747 TERM ' + $term + ' LINES ' + $found.Count)
    foreach ($foundLine in $found | Select-Object -Last 15) { Write-Output ('CRASH747 LINE ' + $foundLine.Line) }
  }
  Write-Output 'CRASH747 LOG TAIL 40'
  Get-Content $crashLog | Select-Object -Last 40
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD747 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP747 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
