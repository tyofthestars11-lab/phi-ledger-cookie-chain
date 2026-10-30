<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 736 - READ EDITOR BUILD THEN SEAT (Ground: Job 735 closes UnrealEditor-Cmd processes then starts a detached VEILEditor Win64 Development build, DLL before build still 798208 written 10/29/2026 19:38:37 old, seat log still SEAT lines 1 metadata only, map 626984. This job acts in one motion: it reads the editor build log Result search and tail, reads the DLL size and write time again, and only if a Succeeded Result line is present does it start a fresh detached Cmd run of the seat719 seating script on VEILDistrict, with new log names VEIL_SEAT736 so the old seat logs stand untouched. If the build is not succeeded yet, it starts nothing and prints the build tail plainly. It edits nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$buildOut = Join-Path $projW 'Saved\Logs\VEIL_EDITOR_build_out.log'
Write-Output ('BUILD736 OUT PRESENT ' + (Test-Path $buildOut))
$buildOk = $false
if (Test-Path $buildOut) {
  Write-Output ('BUILD736 OUT SIZE ' + (Get-Item $buildOut).Length)
  $resultLines = @(Select-String -Path $buildOut -Pattern 'Result')
  Write-Output ('BUILD736 RESULT LINES ' + $resultLines.Count)
  foreach ($resultLine in $resultLines) { Write-Output ('BUILD736 RESULT LINE ' + $resultLine.Line) }
  $okLines = @(Select-String -Path $buildOut -Pattern 'Succeeded')
  Write-Output ('BUILD736 SUCCEEDED LINES ' + $okLines.Count)
  if ($okLines.Count -gt 0) { $buildOk = $true }
  Write-Output 'BUILD736 OUT TAIL 40'
  Get-Content $buildOut | Select-Object -Last 40
}
$dllW = Join-Path $projW 'Binaries\Win64\UnrealEditor-VEIL.dll'
Write-Output ('DLL736 PRESENT ' + (Test-Path $dllW))
if (Test-Path $dllW) { Write-Output ('DLL736 SIZE ' + (Get-Item $dllW).Length + ' WRITE ' + (Get-Item $dllW).LastWriteTime) }
if ($buildOk) {
  $pyW = Join-Path $projW 'Saved\seat719.py'
  Write-Output ('SEAT736 SCRIPT PRESENT ' + (Test-Path $pyW))
  if (Test-Path $pyW) {
    $outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT736_cmd_out.log'
    $errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT736_cmd_err.log'
    $cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
    Write-Output ('SEAT736 CMD PRESENT ' + (Test-Path $cmdW))
    Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
    Write-Output 'SEAT736 CMD STARTED DETACHED NO WAIT'
  } else {
    Write-Output 'SEAT736 NOT STARTED SCRIPT MISSING'
  }
} else {
  Write-Output 'SEAT736 NOT STARTED BUILD NOT SUCCEEDED YET'
}
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('CMD736 ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP736 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
