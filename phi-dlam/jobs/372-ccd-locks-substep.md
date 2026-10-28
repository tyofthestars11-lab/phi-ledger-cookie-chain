<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CCD + ROTATION LOCKS + SUBSTEP 0.01 - JOB 372 (Third study relay, folded whole: the discrete-versus-continuous production fixes, with the mapping onto our pawn made explicit in the relay itself. Our pawn is C++ and a Character WITH a Movement Component - VEILCharacter is an ACharacter C++ class and job 338 prints read the CharacterMovement directly - so she carries both halves at once: the capsule answers to the movement component (discrete floor sweeps; the floor-complexity fix rides job 369, AlwaysCheckFloor rides job 371), while the mesh, IF it is simulating, answers to the physics solver, where CCD, rotation locks and substepping are the governing fixes. For a character pawn the production form is simulate OFF, which job 371 sets; CCD, locks and substepping stand as the settings that protect every simulating body in the game, and this job sets them in their true forms. One, CCD on the mesh body: FBodyInstance bUseCCD = true at class level in the constructor (the flags are read when the physics state is created), with SetCCDEnabled enforced again at BeginPlay. Two, the tumble axes locked: bLockXRotation and bLockYRotation = true on the same BodyInstance - pitch and roll locked, yaw free - so no body wearing this mesh can tumble while it simulates. Three, substepping normalized to the paste own value: job 369 sets MaxSubstepTime=0.016667 only where the section stands absent; the study specifies 0.01 (10 ms micro-steps), and this job normalizes DefaultEngine.ini to bSubstepping=True, MaxSubstepTime=0.01, MaxSubsteps=6 - line-counted edits, backup first (.phi-backup-372), every key verified by read-back, and if the section stands absent here too the whole section is appended with the paste values. Four, the source patch verifies itself by read-back before compile, per the PHI GUARANTEE; anchor misses stop the job before any write. Five, compile the editor target and run VEILDistrict: the PHI CCDLOCK 372 proof line prints ccd, lockX and lockY as read at spawn, beside the 371 and 365 lines where they stand. Merged base at D VEIL-OMNI only; the parents are archive.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 372 DEFERRED'; return }
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
Write-Output '--- SECTION 1: SUBSTEPPING NORMALIZE TO 0.01 ---'
$eng = "$base\Config\DefaultEngine.ini"
if (Test-Path $eng) {
  Select-String -Path $eng -Pattern 'PhysicsSettings|Substep' | ForEach-Object { ("ENG BEFORE {0}: {1}" -f $_.LineNumber, $_.Line.Trim()) } | Write-Output
  Copy-Item $eng "$eng.phi-backup-372" -Force
  $txt = [System.IO.File]::ReadAllText($eng)
  if (-not $txt.Contains('[/Script/Engine.PhysicsSettings]')) {
    Add-Content $eng ''
    Add-Content $eng '[/Script/Engine.PhysicsSettings]'
    Add-Content $eng 'bSubstepping=True'
    Add-Content $eng 'MaxSubstepTime=0.01'
    Add-Content $eng 'MaxSubsteps=6'
    Write-Output 'PHYSICS SECTION APPENDED with paste values'
  } else {
    foreach ($kv in @(@('bSubstepping','True'), @('MaxSubstepTime','0.01'), @('MaxSubsteps','6'))) {
      $key = $kv[0]; $val = $kv[1]
      $cnt = ([regex]::Matches($txt, "(?m)^$key=")).Count
      if ($cnt -ge 1) { $txt = [regex]::Replace($txt, "(?m)^$key=.*$", ($key + '=' + $val), 1); Write-Output ("KEY SET: " + $key + "=" + $val + " (stood x" + $cnt + ")") }
      else {
        $secLine = '[/Script/Engine.PhysicsSettings]'
        $si = $txt.IndexOf($secLine) + $secLine.Length
        $txt = $txt.Substring(0, $si) + "`r`n" + $key + '=' + $val + $txt.Substring($si)
        Write-Output ("KEY INSERTED: " + $key + "=" + $val)
      }
    }
    [System.IO.File]::WriteAllText($eng, $txt)
  }
  $engAfter = [System.IO.File]::ReadAllText($eng)
  foreach ($want in @('bSubstepping=True','MaxSubstepTime=0.01','MaxSubsteps=6')) {
    Write-Output ("VERIFY " + $want + ": " + $engAfter.Contains($want))
  }
} else { Write-Output 'DefaultEngine.ini NOT FOUND - substep section skipped' }
Write-Output '--- SECTION 2: CCD + LOCKS SOURCE PATCH ---'
$cppItem = Get-ChildItem "$base\Source" -Recurse -Filter 'VEILCharacter.cpp' -File | Select-Object -First 1
if (-not $cppItem) { Write-Output 'VEILCHARACTER CPP NOT FOUND'; Write-Output 'JOB 372 STOPPED'; return }
$cpp = $cppItem.FullName
Write-Output ("CPP: " + $cpp)
Select-String -Path $cpp -Pattern 'UseCCD|LockXRotation|LockYRotation|BodyInstance' | ForEach-Object { ("SRC BEFORE {0}: {1}" -f $_.LineNumber, $_.Line.Trim()) } | Write-Output
$src = [System.IO.File]::ReadAllText($cpp)
if ($src.Contains('PHI CCDLOCK 372')) {
  Write-Output 'CCDLOCK ALREADY IN FILE - no second patch; compile and run still verify it'
} else {
  Copy-Item $cpp "$cpp.phi-backup-372" -Force
  Write-Output 'CPP BACKED UP (.phi-backup-372)'
  $ctorBlock = @'
    // PHI CCDLOCK 372 - body instance defaults: CCD on, tumble axes locked, yaw free
    GetMesh()->BodyInstance.bUseCCD = true;
    GetMesh()->BodyInstance.bLockXRotation = true;
    GetMesh()->BodyInstance.bLockYRotation = true;
'@
  $playBlock = @'
    // PHI CCDLOCK 372 - spawn enforcement + proof line
    if (FBodyInstance* BI372 = GetMesh()->GetBodyInstance()) { BI372->SetCCDEnabled(true); }
    UE_LOG(LogTemp, Warning, TEXT("PHI CCDLOCK 372 ccd=%d lockX=%d lockY=%d"), GetMesh()->BodyInstance.bUseCCD ? 1 : 0, GetMesh()->BodyInstance.bLockXRotation ? 1 : 0, GetMesh()->BodyInstance.bLockYRotation ? 1 : 0);
'@
  $bpIdx = $src.IndexOf('AVEILCharacter::BeginPlay')
  $spIdx = -1
  if ($bpIdx -ge 0) { $spIdx = $src.IndexOf('Super::BeginPlay();', $bpIdx) }
  $ctIdx = $src.IndexOf('AVEILCharacter::AVEILCharacte' + [char]114)
  $capIdx = -1
  if ($ctIdx -ge 0) { $capIdx = $src.IndexOf('InitCapsuleSize', $ctIdx) }
  if ($spIdx -lt 0 -or $capIdx -lt 0) { Write-Output ("ANCHOR MISS ctor=" + $capIdx + " beginplay=" + $spIdx + " - nothing written."); Write-Output 'JOB 372 STOPPED BEFORE WRITE'; return }
  $bpIns = $spIdx + 'Super::BeginPlay();'.Length
  $src = $src.Substring(0, $bpIns) + "`r`n" + $playBlock + $src.Substring($bpIns)
  $capSemi = $src.IndexOf(';', $capIdx)
  $src = $src.Substring(0, $capSemi + 1) + "`r`n" + $ctorBlock + $src.Substring($capSemi + 1)
  [System.IO.File]::WriteAllText($cpp, $src)
  $check = [System.IO.File]::ReadAllText($cpp)
  $hits = ([regex]::Matches($check, 'PHI CCDLOCK 372')).Count
  if ($check.Contains('bUseCCD = true') -and $check.Contains('bLockXRotation = true') -and $check.Contains('bLockYRotation = true') -and $hits -ge 2) { Write-Output 'PATCHED + VERIFIED in file (ccdlock blocks x2)' } else { Write-Output 'PATCH VERIFY FAILED - no build runs.'; Write-Output 'JOB 372 STOPPED'; return }
}
Write-Output '--- SECTION 3: COMPILE + RUN ---'
$target372 = -join ([char[]](86,69,73,76,69,100,105,116,111,114))
$buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$blog = "$base\Saved\ccdlock372.log"
$p = Start-Process $buildbat -ArgumentList @($target372,'Win64','Development',"-Project=$uproj",'-WaitMutex','-NoHotReload') -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $blog -RedirectStandardError "$blog.errlog"
Write-Output ("BUILD exit: " + $p.ExitCode)
Select-String -Path $blog -Pattern 'error C[0-9]+|error :|Result:|Total time' -ErrorAction SilentlyContinue | Select-Object -Last 12 | ForEach-Object { $_.Line.Trim() } | Write-Output
if ($p.ExitCode -ne 0) { Write-Output 'BUILD FAILED - no game run.'; Write-Output 'JOB 372 STOPPED AFTER BUILD'; return }
$gp = Start-Process $edexe -ArgumentList @($uproj, '/Game/Maps/VEILDistrict', '-game','-log','-nullrhi','-nosound','-unattended','-nopause','-nosplash') -PassThru -WindowStyle Hidden
Start-Sleep -Seconds 35
if (-not $gp.HasExited) { Stop-Process -Id $gp.Id -Force -ErrorAction SilentlyContinue; Write-Output 'RUN STOPPED AFTER 35s CAPTURE' } else { Write-Output ("RUN EXITED EARLY code=" + $gp.ExitCode) }
Start-Sleep -Seconds 3
$logf = Get-ChildItem "$base\Saved\Logs\*.log" -File | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($logf) {
  $hits2 = Select-String -Path $logf.FullName -Pattern 'PHI CCDLOCK 372|PHI TUMBLEKILL 371|PHI SPAWN TRUTH' -ErrorAction SilentlyContinue
  if ($hits2) { $hits2 | Select-Object -Last 14 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LINES IN LOG - compile verdict stands, spawn proof rides the next run' }
} else { Write-Output 'NO LOG FILE FOUND' }
Write-Output 'JOB 372 DONE'
```
