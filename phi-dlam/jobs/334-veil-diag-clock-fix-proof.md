<!-- PHI-DIRECT -->
```powershell
Write-Output '=== DIAG CLOCK FIX + REBUILD + PROOF - VEIL (Job 333 read whole: its patch LANDED and VERIFIED in both GameMode files - the PHI GUARANTEE held, no silent miss - and VEIL rebuilt BUILD SUCCESSFUL, exe 2026-10-28 00:26:02, proof ran, pawn fell Z -12317.058 to -17139.528 moved 405.0, and ZERO PHI FLOOR DIAG lines printed. The fault is read from the source, job 331 full text: 333 inserted the diagnostic immediately before the PHI PC TICKPROOF log line, and that line sits INSIDE the if (PcProofClock >= 5.f) guard in AVEILPlayerController::Tick. The diagnostic carries its own clock - PhiDiagClock += DeltaSeconds, fire at >= 6.f - but inside that guard it executes once per 5 seconds and adds one frame of DeltaSeconds (about 0.016) per execution: about 375 executions, about 31 minutes of runtime, to reach 6.f. A 40-second proof gives it about 0.13. The threshold is unreachable in proof time - the diagnostic never fired. THIS JOB: threshold 6.f to 0.f so the diagnostic fires on the tickproof cadence itself; latch 2000.f to 500.f so it prints at every tickproof fire instead of once; both edits read back from the file before any build runs - a missed or unverified edit stops this job BEFORE the cook, no silent unpatched cook, ever. Then rebuild + recook + proof, DIAG/TRACE/ACTOR lines in the grep. One game per job so the runner 240s step ceiling cannot squeeze the second game again - VEIL here, OMNI in job 335, filed in the same motion.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 334 DEFERRED'; return }
$file = 'D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp'
if (-not (Test-Path $file)) { Write-Output 'GM FILE NOT FOUND'; return }
$src = [System.IO.File]::ReadAllText($file)
if (-not $src.Contains('PHI FLOOR DIAG')) { Write-Output 'DIAG BLOCK ABSENT in VEIL GameMode - no cook runs on an unpatched file.'; Write-Output 'JOB 334 STOPPED BEFORE COOK'; return }
$changed = $false
if ($src.Contains('PhiDiagClock >= 6.f')) { $src = $src.Replace('PhiDiagClock >= 6.f', 'PhiDiagClock >= 0.f'); $changed = $true; Write-Output 'THRESHOLD EDIT APPLIED: 6.f -> 0.f' } elseif ($src.Contains('PhiDiagClock >= 0.f')) { Write-Output 'THRESHOLD ALREADY AT 0.f' } else { Write-Output 'THRESHOLD ANCHOR MISS - no cook runs.'; Write-Output 'JOB 334 STOPPED BEFORE COOK'; return }
if ($src.Contains('PhiDiagClock = 2000.f;')) { $src = $src.Replace('PhiDiagClock = 2000.f;', 'PhiDiagClock = 500.f;'); $changed = $true; Write-Output 'LATCH EDIT APPLIED: 2000.f -> 500.f' } elseif ($src.Contains('PhiDiagClock = 500.f;')) { Write-Output 'LATCH ALREADY AT 500.f' } else { Write-Output 'LATCH ANCHOR MISS - no cook runs.'; Write-Output 'JOB 334 STOPPED BEFORE COOK'; return }
if ($changed) { Copy-Item $file "$file.phi-backup-334" -Force; [System.IO.File]::WriteAllText($file, $src) }
$check = [System.IO.File]::ReadAllText($file)
if ($check.Contains('PhiDiagClock >= 0.f') -and $check.Contains('PhiDiagClock = 500.f;') -and -not $check.Contains('PhiDiagClock >= 6.f')) { Write-Output 'DIAG CLOCK FIXED + VERIFIED in file' } else { Write-Output 'FIX WRITE FAILED VERIFY - no cook runs.'; Write-Output 'JOB 334 STOPPED BEFORE COOK'; return }
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$proj = 'D:\VEIL'; $arch = 'D:\Builds\VEIL\VEIL_DONE'; $exename = 'VEIL.exe'; $name = 'VEIL'
$uproj = Get-ChildItem $proj -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
$cooklog = "$proj\Saved\diagcook334.log"
$p = Start-Process $uat -ArgumentList @('BuildCookRun', "-project=$uproj", '-noP4', '-platform=Win64', '-clientconfig=Development', '-build', '-cook', '-stage', '-pak', '-archive', "-archivedirectory=$arch") -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $cooklog -RedirectStandardError "$cooklog.err"
"UAT exit: $($p.ExitCode)" | Write-Output
Select-String -Path $cooklog -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|error C[0-9]+|Error:' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output
$exe = "$arch\Windows\$exename"
if (Test-Path $exe) { $fi = Get-Item $exe; "exe modified $($fi.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss'))" | Write-Output
  $proc = Start-Process $exe -ArgumentList @('-PhiStandaloneProof') -PassThru -WindowStyle Hidden
  Start-Sleep -Seconds 30
  $logs = Get-ChildItem "$proj\Saved\Logs", "$arch\Windows\$name\Saved\Logs" -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  if ($logs) { Select-String -Path $logs.FullName -Pattern 'PHI FLOOR DIAG|PHI FLOOR TRACE|PHI FLOOR ACTOR|PHI PC TICKPROOF|PHI MOVE TEST|PHI CENSUS' | Select-Object -Last 30 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
  Get-Process $name -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
} else { Write-Output 'EXE MISSING AFTER DIAG COOK' }
Write-Output 'JOB 334 DONE'
```
