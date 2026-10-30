<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 732 - READ NEW SEAT LOG (Ground: Job 731 read the 728 build as Result Succeeded in 91.77 seconds with VEILCharacter.cpp compiled and VEIL.exe linked, then started a fresh detached Cmd run of the seat719 seating script on VEILDistrict with new log names. This job reads only: the seat731 log for SEAT719 proof lines and golden pitch lines, its tail, its error log, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$seatOut = Join-Path $projW 'Saved\Logs\VEIL_SEAT731_cmd_out.log'
$seatErr = Join-Path $projW 'Saved\Logs\VEIL_SEAT731_cmd_err.log'
Write-Output ('SEAT732 OUT PRESENT ' + (Test-Path $seatOut))
if (Test-Path $seatOut) {
  $seatLines = @(Select-String -Path $seatOut -Pattern 'SEAT719')
  Write-Output ('SEAT732 LINES ' + $seatLines.Count)
  foreach ($seatLine in $seatLines) { Write-Output ('SEAT732 LINE ' + $seatLine.Line) }
  $pitchLines = @(Select-String -Path $seatOut -Pattern 'GOLDEN PITCH')
  Write-Output ('PITCH732 LINES ' + $pitchLines.Count)
  foreach ($pitchLine in $pitchLines) { Write-Output ('PITCH732 LINE ' + $pitchLine.Line) }
  Write-Output 'SEAT732 OUT TAIL 40'
  Get-Content $seatOut | Select-Object -Last 40
}
Write-Output ('SEAT732 ERR PRESENT ' + (Test-Path $seatErr))
if (Test-Path $seatErr) { Get-Content $seatErr | Select-Object -Last 20 }
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD732 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP732 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
