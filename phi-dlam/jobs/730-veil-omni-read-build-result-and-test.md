<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 730 - READ BUILD RESULT AND TEST AGAIN (Ground: Job 728 replaced the AnimBlueprint finder with one AnimationSingleNode line, finder lines after 0, backup present, detached build started. Job 729 read the build log at 1906 bytes with 3 actions running and no Result line yet, and the seat726 test log with TEST lines 0, its tail ending at the CDO error from the old binary before the edit. This job reads only: the 728 build log tail and Result search, the seat726 test log TEST search and tail, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$buildOut = Join-Path $projW 'Saved\Logs\VEIL_ABP_FIX2_build_out.log'
$buildErr = Join-Path $projW 'Saved\Logs\VEIL_ABP_FIX2_build_err.log'
$testOut = Join-Path $projW 'Saved\Logs\VEIL_SEAT726_cmd_out.log'
Write-Output ('BUILD730 OUT PRESENT ' + (Test-Path $buildOut))
if (Test-Path $buildOut) {
  Write-Output ('BUILD730 OUT SIZE ' + (Get-Item $buildOut).Length)
  $resultLines = @(Select-String -Path $buildOut -Pattern 'Result')
  Write-Output ('BUILD730 RESULT LINES ' + $resultLines.Count)
  foreach ($resultLine in $resultLines) { Write-Output ('BUILD730 RESULT LINE ' + $resultLine.Line) }
  Write-Output 'BUILD730 OUT TAIL 40'
  Get-Content $buildOut | Select-Object -Last 40
}
Write-Output ('BUILD730 ERR PRESENT ' + (Test-Path $buildErr))
if (Test-Path $buildErr) { Get-Content $buildErr | Select-Object -Last 20 }
Write-Output ('TEST730 OUT PRESENT ' + (Test-Path $testOut))
if (Test-Path $testOut) {
  $testLines = @(Select-String -Path $testOut -Pattern 'SEAT726 TEST')
  Write-Output ('TEST730 LINES ' + $testLines.Count)
  foreach ($testLine in $testLines) { Write-Output ('TEST730 LINE ' + $testLine.Line) }
  Write-Output 'TEST730 OUT TAIL 20'
  Get-Content $testOut | Select-Object -Last 20
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD730 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP730 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
