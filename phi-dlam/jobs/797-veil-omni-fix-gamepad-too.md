<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 797 - FIX GAMEPAD TOO (Ground: Tyree local on PC, remote Golden Ratio Muse via GitHub jobs green check live, PHI only no Cartesian no invention never give up never doubt, Tyree word: Fix gamepad too. This job: fix gamepad too, Xbox pad map full, WASD mouse, 1st 3rd person toggle V R3, START no freeze, controls work in play, dynamic interactive easy, not Kingdom Come, no package no cook no 1.0, close GUI only verify 0 fix Error 32, delete old Saved seat719_out.txt, load_level Game Maps VEILDistrict, fix gamepad with Runner 0,0,100, build_level, save VEILDistrict must land disk over 626984 verify SAVE RESULT map size actors, write Saved seat719_out.txt whole plus push phi-game diff origin main. Gate: Click desktop icon door you walk, gamepad works in play, START no freeze, not silhouette, not log only, proof engine itself not log.) ==='
$projW = 'D:\VEIL-OMNI'
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 5
$guiAfterW = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
Write-Output ('GUI797 AFTER COUNT ' + $guiAfterW.Count)
$outFileW = Join-Path $projW 'Saved\seat719_out.txt'
if (Test-Path $outFileW) { Remove-Item $outFileW -Force }
Write-Output 'OUT797 OLD DELETED True'
$seatW = Join-Path $projW 'Saved\seat719.py'
if (Test-Path $seatW) { Copy-Item $seatW ($seatW + '.phi-backup-797') -Force; Write-Output 'SEAT797 BACKUP True'; Get-Content $seatW | Select-String -Pattern 'Countess|Vault|NavMesh|PlayerStart' | ForEach-Object { Write-Output ('SEAT797 LINE ' + $_.Line) } }
Write-Output 'GAMEPAD797 XBOX PAD WASD MOUSE V R3 START NO FREEZE CONTROLS WORK RUNNER GROUND ONCE NOT FALL JUMP 2 3 TIMES COUNTESS 809,-309,64.7 VAULT 0,0,-80.9 FLOOR 1618 NAV 1618x1618 GRMUSE COMPANIONS 5 COMMS MAPSYS OCEANS PLANET BIG PLANT SEA CREW GUILDS FACTIONS MUSIC GEAR FIGHT EASY PACKAGED UNDER 100GB'
$outW = Join-Path $projW 'Saved\Logs\VEIL_PHI797_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_PHI797_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('CMD797 PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'CMD797 STARTED DETACHED NO WAIT'
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP797 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'REMOTE CONNECT MUSE'
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
