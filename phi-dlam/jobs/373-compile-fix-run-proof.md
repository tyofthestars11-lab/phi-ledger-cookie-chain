<!-- PHI-DIRECT -->
```powershell
Write-Output '=== COMPILE FIX + RUN PROOF 373 - THE SINGLE INCLUDE ROOT, REPAIRED AND PROVEN (Results 365, 371 and 372 stand read whole as the record: all three editor builds stopped on VEILCharacter.cpp error C2027, undefined type UPhysicsAsset, because the job 365 instrument block in BeginPlay calls GetPhysicsAsset while no PhysicsAsset include line stands in the file; job 372 added error C2039, SetCCDEnabled is not a member of FBodyInstance, from its own BeginPlay enforcement line. The 365 instrument, the 371 tumblekill blocks and the 372 ccdlock blocks all stand written and read-back verified in the source - only compilation is blocked. THIS JOB, merged base at D VEIL-OMNI only: one, back VEILCharacter.cpp up as .phi-backup-373. Two, insert the include line for PhysicsEngine/PhysicsAsset.h immediately after the existing CapsuleComponent include line, a counted anchor that must occur exactly once; if the PhysicsAsset include already stands, print that and skip the insert. Three, find the single line carrying SetCCDEnabled and replace that whole statement with three direct BodyInstance flag writes - bUseCCD, bLockXRotation and bLockYRotation, all true - preserving the line leading indentation; zero or multiple matches print and stop before any write. Four, read back and print the verification set: PhysicsAsset include count, SetCCDEnabled count at zero, the three flag writes present, and the standing marker counts for PHI SPAWN TRUTH, PHI TUMBLEKILL 371 and PHI CCDLOCK 372. Five, compile the editor target on the Build.bat road; on failure the error lines print whole and the job stops. Six, run VEILDistrict and OMNIWorld each in game mode with a 60 second capture and print whole from the logs every PHI SPAWN TRUTH, PHI TICK TRUTH, PHI TUMBLEKILL 371 and PHI CCDLOCK 372 line - the spawn proof the whole drain has been riding toward.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 373 DEFERRED'; return }
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$cppItem = Get-ChildItem "$base\Source" -Recurse -Filter 'VEILCharacter.cpp' -File | Select-Object -First 1
if (-not $cppItem) { Write-Output 'VEILCHARACTER CPP NOT FOUND'; Write-Output 'JOB 373 STOPPED'; return }
$cpp = $cppItem.FullName
Write-Output ("CPP: " + $cpp + " bytes=" + $cppItem.Length)
Copy-Item $cpp "$cpp.phi-backup-373" -Force
Write-Output 'CPP BACKED UP (.phi-backup-373)'
$src = [System.IO.File]::ReadAllText($cpp)
$anchor = '#include "Components/CapsuleComponent.h"'
$incLine = '#include "PhysicsEngine/PhysicsAsset.h"'
$anchorCount = ([regex]::Matches($src, [regex]::Escape($anchor))).Count
$incCountBefore = ([regex]::Matches($src, [regex]::Escape($incLine))).Count
$lines = $src -split "`r`n|`n"
$ccdLines = @()
for ($i = 0; $i -lt $lines.Count; $i++) { if ($lines[$i].Contains('SetCCDEnabled')) { $ccdLines += $i } }
Write-Output ("ANCHOR COUNT CapsuleComponent include: " + $anchorCount)
Write-Output ("PHYSICSASSET INCLUDE COUNT BEFORE: " + $incCountBefore)
Write-Output ("SETCCD LINES COUNT: " + $ccdLines.Count)
if ($ccdLines.Count -ne 1) { Write-Output 'SETCCD LINE NOT UNIQUE - nothing written.'; Write-Output 'JOB 373 STOPPED BEFORE WRITE'; return }
if ($incCountBefore -eq 0 -and $anchorCount -ne 1) { Write-Output 'INCLUDE ANCHOR NOT UNIQUE AND INCLUDE ABSENT - nothing written.'; Write-Output 'JOB 373 STOPPED BEFORE WRITE'; return }
$outLines = @()
foreach ($ln in $lines) {
  if ($ln.Contains('SetCCDEnabled')) {
    $indent = [regex]::Match($ln, '^\s*').Value
    $outLines += ($indent + 'GetMesh()->BodyInstance.bUseCCD = true;')
    $outLines += ($indent + 'GetMesh()->BodyInstance.bLockXRotation = true;')
    $outLines += ($indent + 'GetMesh()->BodyInstance.bLockYRotation = true;')
  } else {
    $outLines += $ln
    if ($incCountBefore -eq 0 -and $ln.Trim() -eq $anchor) { $outLines += $incLine }
  }
}
if ($incCountBefore -gt 0) { Write-Output 'PHYSICSASSET INCLUDE ALREADY STANDS - insert skipped' }
$newSrc = $outLines -join "`r`n"
[System.IO.File]::WriteAllText($cpp, $newSrc)
Write-Output '--- READ-BACK VERIFY ---'
$check = [System.IO.File]::ReadAllText($cpp)
$vInc = ([regex]::Matches($check, [regex]::Escape($incLine))).Count
$vCcd = ([regex]::Matches($check, 'SetCCDEnabled')).Count
Write-Output ("VERIFY PhysicsAsset include count: " + $vInc)
Write-Output ("VERIFY SetCCDEnabled count: " + $vCcd)
Write-Output ("VERIFY bUseCCD write present: " + $check.Contains('BodyInstance.bUseCCD = true'))
Write-Output ("VERIFY bLockXRotation write present: " + $check.Contains('BodyInstance.bLockXRotation = true'))
Write-Output ("VERIFY bLockYRotation write present: " + $check.Contains('BodyInstance.bLockYRotation = true'))
Write-Output ("MARKER PHI SPAWN TRUTH count: " + ([regex]::Matches($check, 'PHI SPAWN TRUTH')).Count)
Write-Output ("MARKER PHI TUMBLEKILL 371 count: " + ([regex]::Matches($check, 'PHI TUMBLEKILL 371')).Count)
Write-Output ("MARKER PHI CCDLOCK 372 count: " + ([regex]::Matches($check, 'PHI CCDLOCK 372')).Count)
if ($vInc -lt 1 -or $vCcd -ne 0) { Write-Output 'PATCH VERIFY FAILED - no build runs.'; Write-Output 'JOB 373 STOPPED'; return }
Write-Output 'PATCHED + VERIFIED in file (include + CCD flag writes)'
Write-Output '--- COMPILE ---'
$target373 = -join ([char[]](86,69,73,76,69,100,105,116,111,114))
$buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$blog = "$base\Saved\compilefix373.log"
$p = Start-Process $buildbat -ArgumentList @($target373,'Win64','Development',"-Project=$uproj",'-WaitMutex','-NoHotReload') -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $blog -RedirectStandardError "$blog.errlog"
Write-Output ("BUILD exit: " + $p.ExitCode)
Select-String -Path $blog -Pattern 'error C[0-9]+|error :|Error|Traceback|Exception|Result:|Total time' -ErrorAction SilentlyContinue | Select-Object -Last 15 | ForEach-Object { $_.Line.Trim() } | Write-Output
if ($p.ExitCode -ne 0) { Write-Output 'BUILD FAILED - no game runs.'; Write-Output 'JOB 373 STOPPED AFTER BUILD'; return }
foreach ($map in @('/Game/Maps/VEILDistrict', '/Game/Maps/OMNIWorld')) {
  Write-Output ("--- GAME RUN: " + $map + " ---")
  $gp = Start-Process $edexe -ArgumentList @($uproj, $map, '-game','-log','-nullrhi','-nosound','-unattended','-nopause','-nosplash') -PassThru -WindowStyle Hidden
  Start-Sleep -Seconds 60
  if (-not $gp.HasExited) { Stop-Process -Id $gp.Id -Force -ErrorAction SilentlyContinue; Write-Output 'RUN STOPPED AFTER 60s CAPTURE' } else { Write-Output ("RUN EXITED EARLY code=" + $gp.ExitCode) }
  Start-Sleep -Seconds 3
  $logf = Get-ChildItem "$base\Saved\Logs\*.log" -File | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  if ($logf) {
    $hits2 = Select-String -Path $logf.FullName -Pattern 'PHI SPAWN TRUTH|PHI TICK TRUTH|PHI TUMBLEKILL 371|PHI CCDLOCK 372' -ErrorAction SilentlyContinue
    if ($hits2) { $hits2 | ForEach-Object { $_.Line } | Write-Output } else { Write-Output 'NO PROOF LINES IN LOG for this run' }
  } else { Write-Output 'NO LOG FILE FOUND' }
}
Write-Output 'JOB 373 DONE'
```
