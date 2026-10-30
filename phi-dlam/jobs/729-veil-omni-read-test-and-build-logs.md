<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 729 - READ TEST AND BUILD LOGS (Ground: Job 726 started a minimal Python test Cmd with no map argument, job 727 held its edit with uses 2 at lines 124 and 125, job 728 replaces the finder lines with one AnimationSingleNode line and starts a detached build after an edit only. This job reads only: the seat726 test log for the TEST print, the seat726 error log, and the 728 build log tail, plus Cmd processes and map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$testOut = Join-Path $projW 'Saved\Logs\VEIL_SEAT726_cmd_out.log'
$testErr = Join-Path $projW 'Saved\Logs\VEIL_SEAT726_cmd_err.log'
$buildOut = Join-Path $projW 'Saved\Logs\VEIL_ABP_FIX2_build_out.log'
$buildErr = Join-Path $projW 'Saved\Logs\VEIL_ABP_FIX2_build_err.log'
Write-Output ('TEST729 OUT PRESENT ' + (Test-Path $testOut))
if (Test-Path $testOut) {
  $testLines = @(Select-String -Path $testOut -Pattern 'SEAT726 TEST')
  Write-Output ('TEST729 LINES ' + $testLines.Count)
  foreach ($testLine in $testLines) { Write-Output ('TEST729 LINE ' + $testLine.Line) }
  Write-Output 'TEST729 OUT TAIL 40'
  Get-Content $testOut | Select-Object -Last 40
}
Write-Output ('TEST729 ERR PRESENT ' + (Test-Path $testErr))
if (Test-Path $testErr) { Get-Content $testErr | Select-Object -Last 20 }
Write-Output ('BUILD729 OUT PRESENT ' + (Test-Path $buildOut))
if (Test-Path $buildOut) {
  Write-Output ('BUILD729 OUT SIZE ' + (Get-Item $buildOut).Length)
  Write-Output 'BUILD729 OUT TAIL 30'
  Get-Content $buildOut | Select-Object -Last 30
}
Write-Output ('BUILD729 ERR PRESENT ' + (Test-Path $buildErr))
if (Test-Path $buildErr) { Get-Content $buildErr | Select-Object -Last 20 }
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD729 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP729 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
