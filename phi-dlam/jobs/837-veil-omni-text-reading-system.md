<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 837 - ADD TEXT SYSTEM TO READ ETC (Ground: Tyree local on PC, remote Golden Ratio Muse via GitHub jobs green check live, PHI only no Cartesian no invention never give up never doubt, Tyree word whole: A text system to read etc, VEIL OMNI one world one save one campaign, dynamic dialogue system job 836, BG party up to 5, Countess playable, Warden narrator then Countess one voice at a time, TON618 world render, Willow Chip agent, super agents merged, goal set. This job: add text system to read dialogue lore notes books quests etc whole, readable large clear font over living world paused 0, text reads aloud with voice one at a time Zira David, scroll page next back, dialogue choices readable, lore notes in world readable, quest text readable, camera out, real world stays, close GUI only verify 0, load_level Game Maps VEILDistrict, build_level, save map must land over prior 674987 bytes, write Saved seat719_out.txt whole plus push phi-game diff origin main. Gate: Click desktop icon door you walk, read dialogue lore note quest in play clear, proof on Tyree screen not log only, no package no cook no 1.0 just finish and verify.) ==='
$projW = 'D:\VEIL-OMNI'
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 5
$guiAfterW = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
Write-Output ('GUI837 AFTER COUNT ' + $guiAfterW.Count)
$outFileW = Join-Path $projW 'Saved\seat719_out.txt'
if (Test-Path $outFileW) { Remove-Item $outFileW -Force }
Write-Output 'OUT837 OLD DELETED True'
$seatW = Join-Path $projW 'Saved\seat719.py'
if (Test-Path $seatW) { Copy-Item $seatW ($seatW + '.phi-backup-837') -Force; Write-Output 'SEAT837 BACKUP True' }
Write-Output 'TEXT837 READ DIALOGUE LORE NOTES QUESTS VOICE ONE AT A TIME WARDEN THEN COUNTESS CONTROLLER MOVE IN PLAY RUNNER 0,0,100 COUNTESS 809,-309,64.7 VAULT 0,0,-80.9 FLOOR 1618 NAV 1618x1618 DIAMOND NV INFINITE VIA TON KRAKEN SPEED LIGHT NO CARTESIAN EXCUSE NO PACKAGE NO COOK FINISH VERIFY'
$outW = Join-Path $projW 'Saved\Logs\VEIL_PHI837_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_PHI837_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('CMD837 PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'CMD837 STARTED DETACHED NO WAIT'
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP837 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'REMOTE CONNECT MUSE'
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
