<!-- PHI-DIRECT -->
```powershell
Write-Output '=== FLIGHT SEAT V2 460 - THE GATE CORRECTED, THE RUNNER FLIES (Ground: job 456 authored the flight seat and its own gate closed on it: BIND LINES counted 3, not 1, because the GameMode binds TogglePauseMenu on three lines, P, Escape and Gamepad Special Right at lines 221 to 223 of VEILGameMode cpp, job 453 read them whole, and every one of those lines carries both BindKey and TogglePauseMenu. The gate demanded exactly one and skipped a seat that was never in doubt. The correction is mechanical: the flight bind inserts after the LAST of the pause bind lines, and the gate is count at least one. Everything else rides as 456 authored it: backups before edits, the ToggleFlight function appended at the end of the GameMode cpp toggling MOVE Flying with cheat flying against MOVE Walking and printing PHI FLIGHT ON or OFF, the declaration inserted after the TogglePauseMenu declaration line in the header, count one measured there by 456 itself, the edited regions verified by count, and the build in the same job with its Result line riding the verdict. If either gate misses, SKIP prints and nothing builds. Every variable carries the fl460 prefix.) ==='
$fl460gm = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp'
$fl460gh = 'D:\VEIL-OMNI\Source\VEIL\Public\Game\VEILGameMode.h'
$fl460lines = @(Get-Content $fl460gm)
$fl460bindIdx = @()
for ($fl460i = 0; $fl460i -lt $fl460lines.Count; $fl460i++) { if ($fl460lines[$fl460i] -match 'BindKey' -and $fl460lines[$fl460i] -match 'TogglePauseMenu') { $fl460bindIdx += $fl460i } }
$fl460already = @($fl460lines | Where-Object { $_ -match 'ToggleFlight' }).Count
Write-Output ('BIND LINES=' + $fl460bindIdx.Count + ' ALREADY=' + $fl460already)
$fl460hLines = @(Get-Content $fl460gh)
$fl460declIdx = @()
for ($fl460k = 0; $fl460k -lt $fl460hLines.Count; $fl460k++) { if ($fl460hLines[$fl460k] -match 'TogglePauseMenu') { $fl460declIdx += $fl460k } }
Write-Output ('DECL LINES=' + $fl460declIdx.Count)
$fl460go = ($fl460bindIdx.Count -ge 1) -and ($fl460declIdx.Count -ge 1) -and ($fl460already -eq 0)
if (-not $fl460go) { Write-Output 'PHI FL460 VERDICT: FLIGHT SEAT SKIP gates closed'; Write-Output 'JOB 460 DONE'; return }
Copy-Item $fl460gm ($fl460gm + '.phi-backup-460') -Force
Copy-Item $fl460gh ($fl460gh + '.phi-backup-460') -Force
$fl460lastBind = $fl460bindIdx[$fl460bindIdx.Count - 1]
$fl460bindLine = "`t`tInputComponent->BindKey(EKeys::F, IE_Pressed, this, &AVEILGameMode::ToggleFlight);"
$fl460newLines = @()
for ($fl460j = 0; $fl460j -lt $fl460lines.Count; $fl460j++) { $fl460newLines += $fl460lines[$fl460j]; if ($fl460j -eq $fl460lastBind) { $fl460newLines += $fl460bindLine } }
$fl460func = @('', 'void AVEILGameMode::ToggleFlight()', '{', "`tACharacter* Runner = Cast<ACharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());", "`tif (!Runner) { return; }", "`tUCharacterMovementComponent* Move = Runner->GetCharacterMovement();", "`tif (!Move) { return; }", "`tif (Move->MovementMode == MOVE_Flying)", "`t{", "`t`tMove->SetMovementMode(MOVE_Walking);", "`t`tUE_LOG(LogTemp, Display, TEXT(""PHI FLIGHT OFF""));", "`t}", "`telse", "`t{", "`t`tMove->SetMovementMode(MOVE_Flying);", "`t`tMove->bCheatFlying = true;", "`t`tUE_LOG(LogTemp, Display, TEXT(""PHI FLIGHT ON""));", "`t}", '}')
$fl460newLines += $fl460func
Set-Content -Path $fl460gm -Value $fl460newLines
$fl460hNew = @()
for ($fl460m = 0; $fl460m -lt $fl460hLines.Count; $fl460m++) { $fl460hNew += $fl460hLines[$fl460m]; if ($fl460m -eq $fl460declIdx[0]) { $fl460hNew += "`tvoid ToggleFlight();" } }
Set-Content -Path $fl460gh -Value $fl460hNew
$fl460verify = @(Select-String -Path $fl460gm -Pattern 'ToggleFlight' -ErrorAction SilentlyContinue)
Write-Output ('TOGGLEFLIGHT LINES IN CPP=' + $fl460verify.Count)
$fl460buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$fl460uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$fl460log = 'D:\VEIL-OMNI\Saved\build460.log'
& $fl460buildbat VEILEditor Win64 Development -Project="$fl460uproj" -WaitMutex -NoHotReload *> "$fl460log"
$fl460result = @(Select-String -Path $fl460log -Pattern 'Result:' -ErrorAction SilentlyContinue | Select-Object -Last 1)
foreach ($fl460r in $fl460result) { Write-Output ('BUILD ' + $fl460r.Line.Trim()) }
Write-Output ('PHI FL460 VERDICT: FLIGHT SEAT toggle_lines=' + $fl460verify.Count)
Write-Output 'JOB 460 DONE'
```
