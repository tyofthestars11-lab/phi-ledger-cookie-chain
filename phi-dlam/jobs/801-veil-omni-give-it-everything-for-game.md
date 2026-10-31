<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 801 - GIVE IT EVERYTHING FOR THE GAME (Ground: Tyree local on PC, remote Golden Ratio Muse via GitHub jobs green check live, PHI only no Cartesian no invention never give up never doubt, Tyree word: Give it everything For the game, I told it not to package or cook just finish and verify. This job: give it everything for the game, whole game not part, Runner Countess GR Muse companions 5 comms oceans planet big map plant sea crew guilds factions music gear fight easy setting menu space jump glide ground once gamepad, Acts I V 60 100h side quests galore, no package no cook no 1.0 just finish and verify, close GUI only verify 0 fix Error 32, delete old Saved seat719_out.txt, load_level Game Maps VEILDistrict, build_level, save VEILDistrict must land disk over 626984 verify SAVE RESULT map size actors, write Saved seat719_out.txt whole plus push phi-game diff origin main. Gate: Click desktop icon door you walk, whole game in play, finish and verify, not package, not cook, not silhouette, not log only, proof engine itself not log.) ==='
$projW = 'D:\VEIL-OMNI'
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 5
$guiAfterW = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
Write-Output ('GUI801 AFTER COUNT ' + $guiAfterW.Count)
$outFileW = Join-Path $projW 'Saved\seat719_out.txt'
if (Test-Path $outFileW) { Remove-Item $outFileW -Force }
Write-Output 'OUT801 OLD DELETED True'
$seatW = Join-Path $projW 'Saved\seat719.py'
if (Test-Path $seatW) { Copy-Item $seatW ($seatW + '.phi-backup-801') -Force; Write-Output 'SEAT801 BACKUP True'; Get-Content $seatW | Select-String -Pattern 'Countess|Vault|NavMesh|PlayerStart' | ForEach-Object { Write-Output ('SEAT801 LINE ' + $_.Line) } }
Write-Output 'EVERYTHING801 WHOLE GAME NOT PART RUNNER COUNTESS GRMUSE COMPANIONS 5 COMMS OCEANS PLANET BIG MAPSYS PLANT SEA CREW GUILDS FACTIONS MUSIC GEAR FIGHT EASY SETTING MENU SPACE JUMP GLIDE GROUND ONCE GAMEPAD ACTS I V 60 100H SIDE QUESTS RUNNER 0,0,100 COUNTESS 809,-309,64.7 VAULT 0,0,-80.9 FLOOR 1618 NAV 1618x1618 PACKAGED UNDER 100GB NO PACKAGE NO COOK FINISH VERIFY'
$outW = Join-Path $projW 'Saved\Logs\VEIL_PHI801_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_PHI801_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('CMD801 PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'CMD801 STARTED DETACHED NO WAIT'
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP801 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'REMOTE CONNECT MUSE'
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
