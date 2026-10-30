<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 731 - SEAT ON NEW BINARY CONDITIONAL (Ground: Job 728 replaced the AnimBlueprint finder with one AnimationSingleNode line, finder lines after 0, detached build started. Job 729 read that build at 1906 bytes with 3 actions running and no Result line yet. Job 730 reads the build Result again. This job acts in one motion: it reads the 728 build log, and only if a Succeeded Result line is present does it start a fresh detached Cmd run of the seat719 seating script on VEILDistrict, with new log names so the old seat logs stand untouched. If the build is not succeeded yet, it starts nothing and prints the build tail plainly. It edits nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$buildOut = Join-Path $projW 'Saved\Logs\VEIL_ABP_FIX2_build_out.log'
Write-Output ('BUILD731 OUT PRESENT ' + (Test-Path $buildOut))
$buildOk = $false
if (Test-Path $buildOut) {
  $okLines = @(Select-String -Path $buildOut -Pattern 'Succeeded')
  Write-Output ('BUILD731 SUCCEEDED LINES ' + $okLines.Count)
  foreach ($okLine in $okLines) { Write-Output ('BUILD731 LINE ' + $okLine.Line) }
  if ($okLines.Count -gt 0) { $buildOk = $true }
  Write-Output 'BUILD731 OUT TAIL 20'
  Get-Content $buildOut | Select-Object -Last 20
}
if ($buildOk) {
  $pyW = Join-Path $projW 'Saved\seat719.py'
  Write-Output ('SEAT731 SCRIPT PRESENT ' + (Test-Path $pyW))
  if (Test-Path $pyW) {
    $outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT731_cmd_out.log'
    $errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT731_cmd_err.log'
    $cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
    Write-Output ('SEAT731 CMD PRESENT ' + (Test-Path $cmdW))
    Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
    Write-Output 'SEAT731 CMD STARTED DETACHED NO WAIT'
  } else {
    Write-Output 'SEAT731 NOT STARTED SCRIPT MISSING'
  }
} else {
  Write-Output 'SEAT731 NOT STARTED BUILD NOT SUCCEEDED YET'
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD731 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP731 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
