<!-- PHI-DIRECT -->
```powershell
Write-Output '=== DIAG CLOCK FIX + REBUILD + PROOF - OMNI (Job 333 read whole: its patch LANDED and VERIFIED in the OMNI GameMode file - PATCHED + VERIFIED in file - but the OMNI build+proof step hit the runner 240s step ceiling and printed nothing: the cook state it left behind is read first in this job. The diagnostic itself carries the same nested-clock fault named in job 334: job 331 full text shows the PHI PC TICKPROOF line sits INSIDE the if (PcProofClock >= 5.f) guard in the PlayerController Tick, and the diagnostic inserted before it adds one frame of DeltaSeconds per 5-second execution toward a 6.f threshold - about 31 minutes of runtime to fire, unreachable in proof time. THIS JOB: read the 333 cook state (exe stamp + diagcook333.log tail), then threshold 6.f to 0.f so the diagnostic fires on the tickproof cadence itself, latch 2000.f to 500.f so it prints at every tickproof fire, both edits read back from the file before any build runs - a missed or unverified edit stops this job BEFORE the cook. Then rebuild + recook + proof. OMNI gets this whole step to itself so the 240s ceiling cannot squeeze it again - VEIL runs in job 334, filed in the same motion.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 335 DEFERRED'; return }
Write-Output '##### OMNI 333 COOK STATE (step cut at the 240s ceiling) #####'
$exe333 = 'D:\Builds\OMNI\OMNI_DONE\Windows\OMNI.exe'
if (Test-Path $exe333) { $fi333 = Get-Item $exe333; "OMNI exe modified $($fi333.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss'))" | Write-Output } else { Write-Output 'OMNI EXE MISSING' }
$cl333 = 'D:\OMNI-UE\Saved\diagcook333.log'
if (Test-Path $cl333) { Select-String -Path $cl333 -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting' | Select-Object -Last 3 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO diagcook333.log FOUND' }
$file = 'D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp'
if (-not (Test-Path $file)) { Write-Output 'GM FILE NOT FOUND'; return }
$src = [System.IO.File]::ReadAllText($file)
if (-not $src.Contains('PHI FLOOR DIAG')) { Write-Output 'DIAG BLOCK ABSENT in OMNI GameMode - no cook runs on an unpatched file.'; Write-Output 'JOB 335 STOPPED BEFORE COOK'; return }
$changed = $false
if ($src.Contains('PhiDiagClock >= 6.f')) { $src = $src.Replace('PhiDiagClock >= 6.f', 'PhiDiagClock >= 0.f'); $changed = $true; Write-Output 'THRESHOLD EDIT APPLIED: 6.f -> 0.f' } elseif ($src.Contains('PhiDiagClock >= 0.f')) { Write-Output 'THRESHOLD ALREADY AT 0.f' } else { Write-Output 'THRESHOLD ANCHOR MISS - no cook runs.'; Write-Output 'JOB 335 STOPPED BEFORE COOK'; return }
if ($src.Contains('PhiDiagClock = 2000.f;')) { $src = $src.Replace('PhiDiagClock = 2000.f;', 'PhiDiagClock = 500.f;'); $changed = $true; Write-Output 'LATCH EDIT APPLIED: 2000.f -> 500.f' } elseif ($src.Contains('PhiDiagClock = 500.f;')) { Write-Output 'LATCH ALREADY AT 500.f' } else { Write-Output 'LATCH ANCHOR MISS - no cook runs.'; Write-Output 'JOB 335 STOPPED BEFORE COOK'; return }
if ($changed) { Copy-Item $file "$file.phi-backup-335" -Force; [System.IO.File]::WriteAllText($file, $src) }
$check = [System.IO.File]::ReadAllText($file)
if ($check.Contains('PhiDiagClock >= 0.f') -and $check.Contains('PhiDiagClock = 500.f;') -and -not $check.Contains('PhiDiagClock >= 6.f')) { Write-Output 'DIAG CLOCK FIXED + VERIFIED in file' } else { Write-Output 'FIX WRITE FAILED VERIFY - no cook runs.'; Write-Output 'JOB 335 STOPPED BEFORE COOK'; return }
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$proj = 'D:\OMNI-UE'; $arch = 'D:\Builds\OMNI\OMNI_DONE'; $exename = 'OMNI.exe'; $name = 'OMNI'
$uproj = Get-ChildItem $proj -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
$cooklog = "$proj\Saved\diagcook335.log"
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
Write-Output 'JOB 335 DONE'
```
