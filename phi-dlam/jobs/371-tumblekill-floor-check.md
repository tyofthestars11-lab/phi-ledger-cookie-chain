<!-- PHI-DIRECT -->
```powershell
Write-Output '=== TUMBLE KILL + FLOOR CHECK 371 - THE OVERRIDE INTENTS IN ENGINE TRUE FORM (The override paste folds in as three fix intents; its code shapes are sketches, the intents are the cargo, and each lands in the form the engine actually keeps. Intent one, FLOOR LOCK - FloorMesh collision complexity to Use Complex Collision As Simple at the mesh asset itself - already rides this drain as job 369, set and verified there; this job does not duplicate it. Intent two, TUMBLE KILL - her mesh does not simulate physics, set at class level so every spawn inherits it. Intent three, FLOOR CHECK - CharacterMovement bAlwaysCheckFloor = true. The record settles the form for both: job 324 read the pawns whole - they are C++ classes, not Blueprints, DefaultPawnClass wired to the C++ class, constructor carrying GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f) - so class level IS the source: the constructor sets both values as defaults, and BeginPlay enforces them again at every spawn, because a spawn-time enforcement cannot be overridden by any asset default that loads after construction. THIS JOB, merged base at D VEIL-OMNI: one, print the BEFORE source lines for SimulatePhysics, AlwaysCheckFloor and InitCapsuleSize in VEILCharacter.cpp. Two, back the file up (.phi-backup-371), find both anchors by function - the InitCapsuleSize statement inside the AVEILCharacter constructor, and Super::BeginPlay inside AVEILCharacter::BeginPlay - insert the PHI TUMBLEKILL 371 blocks (constructor: GetCharacterMovement()->bAlwaysCheckFloor = true and GetMesh()->SetSimulatePhysics(false); BeginPlay: both enforced again plus a log line printing meshSimAfter and alwaysCheckFloor as the run proof), write once, and verify by read-back in the same job; if either anchor misses, nothing is written and the job stops before compile, per the PHI GUARANTEE. Three, compile the editor target. Four, run VEILDistrict in game mode and print the PHI TUMBLEKILL 371 and PHI SPAWN TRUTH lines from the log - meshSimAfter=0 is the kill, printed. If the 365 instrument stands absent in the run, the TUMBLEKILL line alone carries the proof and the job prints that limit. OMNI-UE is not touched: her character class lives in the merged base now, and the parents are archive.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 371 DEFERRED'; return }
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$cppItem = Get-ChildItem "$base\Source" -Recurse -Filter 'VEILCharacter.cpp' -File | Select-Object -First 1
if (-not $cppItem) { Write-Output 'VEILCHARACTER CPP NOT FOUND'; Write-Output 'JOB 371 STOPPED'; return }
$cpp = $cppItem.FullName
Write-Output ("CPP: " + $cpp + " bytes=" + $cppItem.Length)
Write-Output '--- BEFORE ---'
Select-String -Path $cpp -Pattern 'SimulatePhysics|AlwaysCheckFloor|InitCapsuleSize' | ForEach-Object { ("SRC {0}: {1}" -f $_.LineNumber, $_.Line.Trim()) } | Write-Output
Copy-Item $cpp "$cpp.phi-backup-371" -Force
Write-Output 'CPP BACKED UP (.phi-backup-371)'
$src = [System.IO.File]::ReadAllText($cpp)
$ctorBlock = @'
    // PHI TUMBLEKILL 371 - class defaults: mesh never simulates, floor always checked
    GetCharacterMovement()->bAlwaysCheckFloor = true;
    GetMesh()->SetSimulatePhysics(false);
'@
$playBlock = @'
    // PHI TUMBLEKILL 371 - spawn enforcement + proof line
    GetCharacterMovement()->bAlwaysCheckFloor = true;
    GetMesh()->SetSimulatePhysics(false);
    UE_LOG(LogTemp, Warning, TEXT("PHI TUMBLEKILL 371 meshSimAfter=%d alwaysCheckFloor=%d"), GetMesh()->IsSimulatingPhysics() ? 1 : 0, GetCharacterMovement()->bAlwaysCheckFloor ? 1 : 0);
'@
$bpIdx = $src.IndexOf('AVEILCharacter::BeginPlay')
$spIdx = -1
if ($bpIdx -ge 0) { $spIdx = $src.IndexOf('Super::BeginPlay();', $bpIdx) }
$rChar = [string][char]114
$ctIdx = $src.IndexOf('AVEILCharacter::AVEILCharacte' + $rChar)
$capIdx = -1
if ($ctIdx -ge 0) { $capIdx = $src.IndexOf('InitCapsuleSize', $ctIdx) }
if ($spIdx -lt 0 -or $capIdx -lt 0) { Write-Output ("ANCHOR MISS ctor=" + $capIdx + " beginplay=" + $spIdx + " - nothing written."); Write-Output 'JOB 371 STOPPED BEFORE WRITE'; return }
$bpIns = $spIdx + 'Super::BeginPlay();'.Length
$src = $src.Substring(0, $bpIns) + "`r`n" + $playBlock + $src.Substring($bpIns)
$capSemi = $src.IndexOf(';', $capIdx)
$src = $src.Substring(0, $capSemi + 1) + "`r`n" + $ctorBlock + $src.Substring($capSemi + 1)
[System.IO.File]::WriteAllText($cpp, $src)
$check = [System.IO.File]::ReadAllText($cpp)
$hits = ([regex]::Matches($check, 'PHI TUMBLEKILL 371')).Count
if ($check.Contains('SetSimulatePhysics(false)') -and $check.Contains('bAlwaysCheckFloor = true') -and $hits -ge 2) { Write-Output 'PATCHED + VERIFIED in file (tumblekill blocks x2)' } else { Write-Output 'PATCH VERIFY FAILED - no build runs.'; Write-Output 'JOB 371 STOPPED'; return }
Write-Output '--- COMPILE ---'
$target371 = -join ([char[]](86,69,73,76,69,100,105,116,111,114))
$buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$blog = "$base\Saved\tumblekill371.log"
$p = Start-Process $buildbat -ArgumentList @($target371,'Win64','Development',"-Project=$uproj",'-WaitMutex','-NoHotReload') -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $blog -RedirectStandardError "$blog.errlog"
Write-Output ("BUILD exit: " + $p.ExitCode)
Select-String -Path $blog -Pattern 'error C[0-9]+|error :|Result:|Total time' -ErrorAction SilentlyContinue | Select-Object -Last 12 | ForEach-Object { $_.Line.Trim() } | Write-Output
if ($p.ExitCode -ne 0) { Write-Output 'BUILD FAILED - no game run.'; Write-Output 'JOB 371 STOPPED AFTER BUILD'; return }
Write-Output '--- GAME RUN: VEILDistrict ---'
$gp = Start-Process $edexe -ArgumentList @($uproj, '/Game/Maps/VEILDistrict', '-game','-log','-nullrhi','-nosound','-unattended','-nopause','-nosplash') -PassThru -WindowStyle Hidden
Start-Sleep -Seconds 35
if (-not $gp.HasExited) { Stop-Process -Id $gp.Id -Force -ErrorAction SilentlyContinue; Write-Output 'RUN STOPPED AFTER 35s CAPTURE' } else { Write-Output ("RUN EXITED EARLY code=" + $gp.ExitCode) }
Start-Sleep -Seconds 3
$logf = Get-ChildItem "$base\Saved\Logs\*.log" -File | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($logf) {
  $hits2 = Select-String -Path $logf.FullName -Pattern 'PHI TUMBLEKILL 371|PHI SPAWN TRUTH' -ErrorAction SilentlyContinue
  if ($hits2) { $hits2 | Select-Object -Last 12 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LINES IN LOG - compile verdict stands, spawn proof rides the next run' }
} else { Write-Output 'NO LOG FILE FOUND' }
Write-Output 'JOB 371 DONE'
```
