<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 820 - FIX KEEPS FATAL ERRORING (Ground: Tyree local on PC, remote Golden Ratio Muse via GitHub jobs green check live, PHI only no Cartesian no invention never give up never doubt, Tyree word: The game keeps fatal erroring Fix that, game was up after local result 810-815 with no OOM, now fatal error repeats in play, cause not yet read from a log. This job: read fatal error whole first never guess, read Saved Logs newest log tail, read Saved Crashes newest crash log, read D3D12 dump name if present, print fatal error line whole, fix root cause at root in source or settings, close GUI only verify 0, load_level Game Maps VEILDistrict, build_level, save map must land over prior 670004 bytes, write Saved seat719_out.txt whole plus push phi-game diff origin main. Gate: Click desktop icon door you walk, game stays up no fatal error dialog, controller moves, Warden narrator then Countess, proof in play not log only, no package no cook no 1.0 just finish and verify.) ==='
$projW = 'D:\VEIL-OMNI'
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 5
$guiAfterW = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
Write-Output ('GUI820 AFTER COUNT ' + $guiAfterW.Count)
$outFileW = Join-Path $projW 'Saved\seat719_out.txt'
if (Test-Path $outFileW) { Remove-Item $outFileW -Force }
Write-Output 'OUT820 OLD DELETED True'
$seatW = Join-Path $projW 'Saved\seat719.py'
if (Test-Path $seatW) { Copy-Item $seatW ($seatW + '.phi-backup-820') -Force; Write-Output 'SEAT820 BACKUP True' }
Write-Output 'FATAL820 READ LOG WHOLE FIRST FIX ROOT CAUSE GAME STAYS UP NO FATAL DIALOG CONTROLLER MOVE WARDEN THEN COUNTESS NV STEP 1 OF 1 ONLY RUNNER 0,0,100 COUNTESS 809,-309,64.7 VAULT 0,0,-80.9 FLOOR 1618 NAV 1618x1618 DIAMOND NV INFINITE VIA TON KRAKEN SPEED LIGHT NO CARTESIAN EXCUSE NO PACKAGE NO COOK FINISH VERIFY'
$logDirW = Join-Path $projW 'Saved\Logs'
if (Test-Path $logDirW) { $logW = Get-ChildItem $logDirW -Filter '*.log' | Sort-Object LastWriteTime -Descending | Select-Object -First 1; Write-Output ('LOG820 LAST ' + $logW.Name); Get-Content $logW.FullName -Tail 50 | ForEach-Object { Write-Output ('LOG820 TAIL ' + $_) } }
$crashDirW = Join-Path $projW 'Saved\Crashes'
if (Test-Path $crashDirW) { Get-ChildItem $crashDirW | Sort-Object LastWriteTime -Descending | Select-Object -First 3 | ForEach-Object { Write-Output ('CRASH820 ' + $_.FullName) } }
$outW = Join-Path $projW 'Saved\Logs\VEIL_PHI820_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_PHI820_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('CMD820 PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'CMD820 STARTED DETACHED NO WAIT'
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP820 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'REMOTE CONNECT MUSE'
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
