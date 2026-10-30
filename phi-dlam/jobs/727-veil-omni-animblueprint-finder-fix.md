<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 727 - ANIMBLUEPRINT FINDER FIX CONDITIONAL (Ground: Job 725 read AnimBlueprint asset MISSING, Rig asset PRESENT 68570, VEILCharacter.cpp AnimBlueprint lines at 106 124 160, line 124 is a constructor FClassFinder for Countess_AnimBlueprint, line 160 is a LoadClass fallback to PlayAnimation PoseSeq, Animations folder 208 sequence files and no AnimBlueprint asset. This job reads every use of the finder variable in VEILCharacter.cpp. If the finder declaration is the only use, it backs the file up and removes that one line, so the CDO constructor no longer reaches for an asset that does not exist, and the line 160 fallback stands. If the variable is used anywhere else, it edits nothing and prints every use plainly. After an edit only, it starts a detached build, no wait. It cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$charW = Join-Path $projW 'Source\VEIL\Private\Character\VEILCharacter.cpp'
Write-Output ('CHAR727 PRESENT ' + (Test-Path $charW))
if (Test-Path $charW) {
  $uses = @(Select-String -Path $charW -Pattern 'PhiCountessABP')
  Write-Output ('USES727 COUNT ' + $uses.Count)
  foreach ($useLine in $uses) { Write-Output ('USES727 LINE ' + $useLine.LineNumber + ' ' + $useLine.Line) }
  if ($uses.Count -eq 1) {
    $backupW = Join-Path $projW 'Source\VEIL\Private\Character\VEILCharacter.cpp.phi-backup-727'
    Copy-Item $charW $backupW -Force
    Write-Output ('BACKUP727 PRESENT ' + (Test-Path $backupW))
    $newLines = Get-Content $charW | Where-Object { $_ -notmatch 'PhiCountessABP' }
    Set-Content $charW $newLines -Encoding ascii
    Write-Output 'EDIT727 FINDER LINE REMOVED'
    $afterLines = @(Select-String -Path $charW -Pattern 'AnimBlueprint')
    Write-Output ('AFTER727 ANIMBLUEPRINT LINES ' + $afterLines.Count)
    foreach ($afterLine in $afterLines) { Write-Output ('AFTER727 LINE ' + $afterLine.LineNumber + ' ' + $afterLine.Line) }
    $outW = Join-Path $projW 'Saved\Logs\VEIL_ABP_FIX_build_out.log'
    $errW = Join-Path $projW 'Saved\Logs\VEIL_ABP_FIX_build_err.log'
    $buildW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
    Write-Output ('BUILD727 PRESENT ' + (Test-Path $buildW))
    Start-Process -FilePath $buildW -ArgumentList 'VEIL','Win64','Development','-Project="D:\VEIL-OMNI\VEIL.uproject"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
    Write-Output 'BUILD727 STARTED DETACHED NO WAIT'
  } else {
    Write-Output 'EDIT727 NOT DONE USES ABOVE NOT ONE'
    Write-Output 'BUILD727 NOT STARTED'
  }
}
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP727 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
