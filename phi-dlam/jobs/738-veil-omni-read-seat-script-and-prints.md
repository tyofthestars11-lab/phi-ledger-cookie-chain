<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 738 - READ SEAT SCRIPT AND PRINTS (Ground: Job 737 read the seat736 log with SEAT lines 6 metadata and deprecation warnings only, PITCH lines 0, CDO lines 0, tail ends with commandlet Success 0 errors and 13 warnings, map 626984 unchanged. No SEAT proof prints stood in that read. This job reads only: the seat719 script lines 60 to 130, the seat736 log searched for Vault, Countess, SEAT, and SAVED prints, the seat736 log tail 20, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$pyW = Join-Path $projW 'Saved\seat719.py'
Write-Output ('SCRIPT738 PRESENT ' + (Test-Path $pyW))
if (Test-Path $pyW) {
  Write-Output 'SCRIPT738 LINES 60 TO 130'
  Get-Content $pyW | Select-Object -Skip 59 -First 71
}
$seatOut = Join-Path $projW 'Saved\Logs\VEIL_SEAT736_cmd_out.log'
Write-Output ('SEAT738 OUT PRESENT ' + (Test-Path $seatOut))
if (Test-Path $seatOut) {
  foreach ($term in @('Vault','Countess','SEAT','SAVED')) {
    $found = @(Select-String -Path $seatOut -Pattern $term)
    Write-Output ('SEAT738 TERM ' + $term + ' LINES ' + $found.Count)
    foreach ($foundLine in $found) { Write-Output ('SEAT738 LINE ' + $foundLine.Line) }
  }
  Write-Output 'SEAT738 OUT TAIL 20'
  Get-Content $seatOut | Select-Object -Last 20
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD738 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP738 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
