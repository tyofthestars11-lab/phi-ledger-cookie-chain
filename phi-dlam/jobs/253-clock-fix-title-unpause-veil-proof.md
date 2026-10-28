# Job 253 — CLOCK FIX: the title stops pausing the world (both GameModes) + VEIL build + TICKPROOF proof

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 250 NAMED THE GATE. Engine source (LevelTick.cpp): TimeSeconds advances only inside if ( !bIsPaused ), the TimerManager ticks only under !bIsPaused, and actor ticks ride the same gate. Own-code sweep: the ONLY SetPause(true) in either module is the TITLE - VEILGameMode.cpp:173 / OMNIGameMode.cpp:197, SetPause(true) with the comment "the title is a real title: the world waits behind it". The title pauses the world and the measured runs never lift it: worldTime 0.00 forever, pawnTickEntries 0, timerRemaining frozen at 3.00 - in PIE and in the standalone package alike - while the GAMEMODE ALIVE print read its own view of pause, not the world gate flag. THE FIX, smallest change answering the evidence: the title becomes an overlay on a LIVING world - SetPause(true) at the title line becomes SetPause(false). The pause menu keeps its own pause flow untouched. Backup first, exact-line match required (abort the edit if the count is not exactly 1 per file), then build VEIL and prove the clock in -game: TICKPROOF must show worldTime ADVANCING and pawnTickEntries > 0. A marker file records the verdict for job 254. ==='
foreach ($gm in @('D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp','D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp')) {
  Write-Output "===== region 150-235: $gm ====="
  if (Test-Path $gm) { $c = Get-Content $gm; for ($i=149; $i -lt [Math]::Min(235,$c.Count); $i++) { '{0}: {1}' -f ($i+1), $c[$i] } } else { Write-Output 'FILE MISSING' }
}
$bk = 'D:\_PhiHolding\src-backup-253'; New-Item -ItemType Directory -Force $bk | Out-Null
foreach ($gm in @('D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp','D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp')) {
  Copy-Item $gm $bk -Force
  $raw = Get-Content $gm -Raw
  $count = ([regex]::Matches($raw, 'SetPause\(true\);\s*// the title is a real title')).Count
  Write-Output "title-pause matches in $gm : $count"
  if ($count -eq 1) {
    $new = $raw -replace 'SetPause\(true\);(\s*)// the title is a real title: the world waits behind it', 'SetPause(false);$1// PHI CLOCK FIX (job 253): the title overlays a LIVING world - LevelTick.cpp gates TimeSeconds, the TimerManager and actor ticks behind !bIsPaused (job 250), so pausing for the title froze the world clock, the pawn tick and the timers in PIE and standalone alike'
    Set-Content $gm $new -NoNewline
    Write-Output "EDITED: $gm"
  } else { Write-Output "EDIT ABORTED for $gm - match count was not exactly 1; region above is the evidence" }
}
Write-Output '===== verify: no title SetPause(true) remains ====='
foreach ($root in @('D:\VEIL\Source','D:\OMNI-UE\Source')) { Get-ChildItem $root -Recurse -Include *.cpp,*.h | Select-String -Pattern 'SetPause\(true\)' | ForEach-Object { "$($_.Path):$($_.LineNumber): $($_.Line.Trim())" } }
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat' VEILEditor Win64 Development -Project='D:\VEIL\VEIL.uproject' -WaitMutex -NoHotReload 2>&1 | Select-String -Pattern 'error|Total time' | Select-Object -First 12 | ForEach-Object { $_.Line }
$log = 'D:\_PhiHolding\tickproof_veil_clockfix.log'
$p = Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe' -ArgumentList @('D:\VEIL\VEIL.uproject','-game','-windowed','-resx=800','-resy=450','-unattended','-nosplash',"-abslog=$log") -PassThru
Start-Sleep -Seconds 40
$proof = Select-String -Path $log -Pattern 'TICKPROOF' -ErrorAction SilentlyContinue | Select-Object -Last 4 | ForEach-Object { $_.Line }
$proof | ForEach-Object { Write-Output $_ }
$adv = ($proof | Where-Object { $_ -match 'worldTime=([0-9.]+)' -and [double]$Matches[1] -gt 0.5 }).Count
$tick = ($proof | Where-Object { $_ -match 'pawnTickEntries=([0-9]+)' -and [int]$Matches[1] -gt 0 }).Count
Write-Output "CLOCKFIX VEIL: samplesWithTimeAdvanced=$adv samplesWithPawnTicks=$tick"
"VEIL clockfix proof: timeAdvanced=$adv pawnTicks=$tick at $(Get-Date -Format o)" | Set-Content 'D:\_PhiHolding\clockfix_veil_proof.txt'
Stop-Process -Id $p.Id -Force -ErrorAction SilentlyContinue
Write-Output 'CLOCK FIX VEIL PROOF DONE'
```
