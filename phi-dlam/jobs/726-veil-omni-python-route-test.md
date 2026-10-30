<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 726 - PYTHON ROUTE TEST AND CHARACTER LINES (Ground: Job 725 read AnimBlueprint asset MISSING, Rig asset PRESENT 68570, VEILCharacter.cpp AnimBlueprint lines 3 at lines 106 124 160, Animations folder 208 sequence files and no AnimBlueprint, map 626984, seat logs frozen at 19:46:17 UTC with no SEAT lines. This job does two things in one motion: it reads the exact character code around the AnimBlueprint reference so the fix job needs no new read, and it starts a fresh detached Cmd run with a minimal Python script and no map argument, to prove whether the PythonScript route itself prints at all, separate from the VEILDistrict load. It edits nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$charW = Join-Path $projW 'Source\VEIL\Private\Character\VEILCharacter.cpp'
Write-Output ('CHAR726 PRESENT ' + (Test-Path $charW))
if (Test-Path $charW) {
  $charLines = Get-Content $charW
  Write-Output 'CHAR726 LINES 100 TO 175'
  $charLines[99..174]
  $poseLines = @(Select-String -Path $charW -Pattern 'PoseSeq')
  Write-Output ('POSE726 LINES ' + $poseLines.Count)
  foreach ($poseLine in $poseLines) { Write-Output ('POSE726 LINE ' + $poseLine.LineNumber + ' ' + $poseLine.Line) }
}
$pyW = Join-Path $projW 'Saved\seat726.py'
$pyText = @"
import unreal
unreal.log("SEAT726 TEST HELLO")
print("SEAT726 TEST HELLO")
unreal.log("SEAT726 DONE")
print("SEAT726 DONE")
"@
Set-Content $pyW $pyText -Encoding ascii
Write-Output ('TEST726 SCRIPT PRESENT ' + (Test-Path $pyW))
$outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT726_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT726_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('TEST726 CMD PRESENT ' + (Test-Path $cmdW))
Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('OLD726 CMD ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB) + ' CPU ' + $_.CPU) }
Get-Process -Name 'UnrealEdito*' -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -ne 'UnrealEditor-Cmd' } | ForEach-Object { Write-Output ('GUI726 ID ' + $_.Id + ' NAME ' + $_.ProcessName + ' WS MB ' + [int]($_.WorkingSet / 1MB)) }
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat726.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'TEST726 CMD STARTED DETACHED NO WAIT'
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP726 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
