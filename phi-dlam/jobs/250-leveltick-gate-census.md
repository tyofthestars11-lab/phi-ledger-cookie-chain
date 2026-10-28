# Job 250 — LevelTick gate census: the exact condition around TimeSeconds += DeltaSeconds, plus an own-code sweep

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 246 settled the discriminator: the packaged VEIL_DONE, running standalone with no editor, reproduces the frozen signature exactly - worldTime 0.00 in all 7 samples over 30 seconds, pawnTickEntries 0, timerRemaining 3.00 frozen, while worldDelta reads real and the PC ticks. The freeze is in the game data/code, not the editor. Job 244s source census caught the anatomy but at +-1 line of context: RealTimeSeconds += DeltaSeconds runs, then DeltaSeconds = GameDeltaSeconds overwrites the delta, then a braced block holds TimeSeconds += DeltaSeconds - and the condition guarding that block was NOT captured. This job reads LevelTick.cpp with WIDE context around GameDeltaSeconds, the time-advance block, the timer tick, and IsPaused, reads WorldSettings.h for PauseDelay, and sweeps OUR OWN module code (VEIL + OMNI Source trees) for anything that touches pause, dilation, slomo, or delta - our code is a suspect surface too. Read-only. ==='
$lt = 'C:\Program Files\Epic Games\UE_5.8\Engine\Source\Runtime\Engine\Private\LevelTick.cpp'
Write-Output '--- GameDeltaSeconds in LevelTick.cpp (context 20,20) ---'
Select-String -Path $lt -Pattern 'GameDeltaSeconds' -Context 20,20 | ForEach-Object { $_.Context.PreContext; $_.Line; $_.Context.PostContext; '...' }
Write-Output '--- UnpausedTimeSeconds block (context 6,30) ---'
Select-String -Path $lt -Pattern 'UnpausedTimeSeconds \+=' -Context 6,30 | ForEach-Object { $_.Context.PreContext; $_.Line; $_.Context.PostContext; '...' }
Write-Output '--- TimerManager tick in LevelTick.cpp ---'
Select-String -Path $lt -Pattern 'TimerManager|TickTimers' -Context 3,3 | ForEach-Object { $_.Context.PreContext; $_.Line; $_.Context.PostContext; '...' }
$wd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Source\Runtime\Engine\Private\World.cpp'
Write-Output '--- UWorld::IsPaused in World.cpp (context 4,14) ---'
Select-String -Path $wd -Pattern 'bool UWorld::IsPaused' -Context 4,14 | ForEach-Object { $_.Context.PreContext; $_.Line; $_.Context.PostContext; '...' }
$wsh = 'C:\Program Files\Epic Games\UE_5.8\Engine\Source\Runtime\Engine\Classes\GameFramework\WorldSettings.h'
Write-Output '--- PauseDelay in WorldSettings.h (context 3,3) ---'
Select-String -Path $wsh -Pattern 'PauseDelay' -Context 3,3 | ForEach-Object { $_.Context.PreContext; $_.Line; $_.Context.PostContext; '...' }
Write-Output '--- OWN-CODE SWEEP: pause / dilation / delta writes in both modules ---'
foreach ($root in @('D:\VEIL\Source','D:\OMNI-UE\Source')) {
  Write-Output ">>> $root"
  Get-ChildItem $root -Recurse -Include *.cpp,*.h -ErrorAction SilentlyContinue | Select-String -Pattern 'SetPause|SetGlobalTimeDilation|CustomTimeDilation|Slomo|SetTimeDilation|bEnableWorldTick|PauseGame|SetGamePaused|DeltaSeconds\s*=\s*0|TimeDilation\s*=' | ForEach-Object { "$($_.Path):$($_.LineNumber): $($_.Line.Trim())" }
}
Write-Output '--- standalone VEIL.log: pause/fixed/demo lines whole ---'
$vlog = 'D:\Builds\VEIL\VEIL_DONE\Windows\VEIL\Saved\Logs\VEIL.log'
if (Test-Path $vlog) { Select-String -Path $vlog -Pattern 'Paus|Fixed|Demo|Slomo|Dilation' | Select-Object -First 25 | ForEach-Object { $_.Line } } else { Write-Output "log missing: $vlog" }
```
