<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 737 - READ SEAT736 LOG (Ground: Job 736 read the editor build Result Succeeded, DLL now 966144 written 10/30/2026 14:50:11 new, seat719 script present, seat Cmd started detached with new log names VEIL_SEAT736, map 626984. This job reads only: the seat736 log SEAT719 search and tail, golden pitch search, CDO error search, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$seatOut = Join-Path $projW 'Saved\Logs\VEIL_SEAT736_cmd_out.log'
Write-Output ('SEAT737 OUT PRESENT ' + (Test-Path $seatOut))
if (Test-Path $seatOut) {
  $seatLines = @(Select-String -Path $seatOut -Pattern 'SEAT719')
  Write-Output ('SEAT737 LINES ' + $seatLines.Count)
  foreach ($seatLine in $seatLines) { Write-Output ('SEAT737 LINE ' + $seatLine.Line) }
  $pitchLines = @(Select-String -Path $seatOut -Pattern 'GOLDEN PITCH')
  Write-Output ('PITCH737 LINES ' + $pitchLines.Count)
  foreach ($pitchLine in $pitchLines) { Write-Output ('PITCH737 LINE ' + $pitchLine.Line) }
  $cdoLines = @(Select-String -Path $seatOut -Pattern 'Countess_AnimBlueprint')
  Write-Output ('CDO737 LINES ' + $cdoLines.Count)
  Write-Output 'SEAT737 OUT TAIL 40'
  Get-Content $seatOut | Select-Object -Last 40
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD737 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP737 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
