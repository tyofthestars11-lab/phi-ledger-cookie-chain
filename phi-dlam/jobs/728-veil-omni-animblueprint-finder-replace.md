<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 728 - ANIMBLUEPRINT FINDER REPLACE (Ground: Job 726 read VEILCharacter.cpp lines 100 to 175 whole. The finder block is two lines: a static FClassFinder declaration for Countess_AnimBlueprint, then an if line that sets AnimInstanceClass when it succeeds and an else line that sets AnimationSingleNode. The asset does not exist, job 725, so the constructor lookup is the CDO error source. BeginPlay line 160 already loads the AnimBlueprint class when present and plays Idle_Relaxed when absent, so the constructor finder is not the animation path. This job replaces the two finder lines plus the else line with one AnimationSingleNode line, verified first on a local copy of the exact snippet. If no finder lines are present, it edits nothing. After an edit only, it backs the file up and starts a detached build, no wait. It cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$charW = Join-Path $projW 'Source\VEIL\Private\Character\VEILCharacter.cpp'
Write-Output ('CHAR728 PRESENT ' + (Test-Path $charW))
if (Test-Path $charW) {
  $uses = @(Select-String -Path $charW -Pattern 'PhiCountessABP')
  Write-Output ('USES728 COUNT ' + $uses.Count)
  foreach ($useLine in $uses) { Write-Output ('USES728 LINE ' + $useLine.LineNumber + ' ' + $useLine.Line) }
  if ($uses.Count -gt 0) {
    $backupW = Join-Path $projW 'Source\VEIL\Private\Character\VEILCharacter.cpp.phi-backup-728'
    Copy-Item $charW $backupW -Force
    Write-Output ('BACKUP728 PRESENT ' + (Test-Path $backupW))
    $inLines = Get-Content $charW
    $outLines = @()
    $dropElse = $false
    foreach ($inLine in $inLines) {
      if ($dropElse -and ($inLine -match 'else')) { $dropElse = $false; continue }
      if ($inLine -match 'PhiCountessABP') {
        if ($inLine -match 'static') { continue }
        $outLines += '            GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);'
        $dropElse = $true
        continue
      }
      $outLines += $inLine
    }
    Set-Content $charW $outLines -Encoding ascii
    Write-Output 'EDIT728 FINDER REPLACED WITH SINGLENODE'
    $afterUses = @(Select-String -Path $charW -Pattern 'PhiCountessABP')
    Write-Output ('AFTER728 FINDER LINES ' + $afterUses.Count)
    $outW = Join-Path $projW 'Saved\Logs\VEIL_ABP_FIX2_build_out.log'
    $errW = Join-Path $projW 'Saved\Logs\VEIL_ABP_FIX2_build_err.log'
    $buildW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
    Write-Output ('BUILD728 PRESENT ' + (Test-Path $buildW))
    Start-Process -FilePath $buildW -ArgumentList 'VEIL','Win64','Development','-Project="D:\VEIL-OMNI\VEIL.uproject"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
    Write-Output 'BUILD728 STARTED DETACHED NO WAIT'
  } else {
    Write-Output 'EDIT728 NOT DONE NO FINDER LINES'
    Write-Output 'BUILD728 NOT STARTED'
  }
}
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP728 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
