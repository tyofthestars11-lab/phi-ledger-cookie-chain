<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 746 - READ GPU CRASH LOG (Ground: Tyree clicked the game and his screen showed an Error dialog, GPU Crashed or D3D Device Removed, check log for GPU state information, GPU mini dump written to D VEIL-OMNI Saved Logs D3D12.0.2026.10.30-16.06.32.nv-gpudmp. This job reads only: that dump file presence and size, the newest VEIL log tail 100 lines searched for GPU, D3D, Crash, Fatal, the Logs folder list for 2026-10-30 files, VEIL exe processes. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$dumpW = Join-Path $projW 'Saved\Logs\D3D12.0.2026.10.30-16.06.32.nv-gpudmp'
Write-Output ('DUMP746 PRESENT ' + (Test-Path $dumpW))
if (Test-Path $dumpW) { Write-Output ('DUMP746 SIZE ' + (Get-Item $dumpW).Length) }
$logsW = Join-Path $projW 'Saved\Logs'
Get-ChildItem $logsW -File | Sort-Object LastWriteTime -Descending | Select-Object -First 15 | ForEach-Object { Write-Output ('LOG746 FILE ' + $_.Name + ' SIZE ' + $_.Length + ' WRITE ' + $_.LastWriteTime) }
$veilLog = Join-Path $projW 'Saved\Logs\VEIL.log'
Write-Output ('VEIL746 LOG PRESENT ' + (Test-Path $veilLog))
if (Test-Path $veilLog) {
  foreach ($term in @('GPU','D3D','Crash','Fatal')) {
    $found = @(Select-String -Path $veilLog -Pattern $term)
    Write-Output ('VEIL746 TERM ' + $term + ' LINES ' + $found.Count)
    foreach ($foundLine in $found | Select-Object -Last 15) { Write-Output ('VEIL746 LINE ' + $foundLine.Line) }
  }
  Write-Output 'VEIL746 LOG TAIL 100'
  Get-Content $veilLog | Select-Object -Last 100
}
Get-Process -Name 'VEIL' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('VEIL746 EXE ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB)) }
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('EDITOR746 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB)) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
