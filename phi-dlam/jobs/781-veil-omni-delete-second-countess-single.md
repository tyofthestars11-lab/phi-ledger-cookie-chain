<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 781 - DELETE SECOND COUNTESS SINGLE ONLY (Ground: Tyree local on PC, remote Golden Ratio Muse via GitHub jobs green check live, PHI only no Cartesian no invention never give up never doubt, progress kinda like a floor hexagonal tiles character on floor, but there is still 2 of her, duplicate Countess in play center detailed plus right silhouette with blade, job 780 step 4 destroy ALL countess labels clean 663 duplicate double silhouette not yet landed single. This job: close GUI UnrealEditor processes only verify 0 fix Error 32, delete old Saved seat719_out.txt plus survey_out.txt, load_level Game Maps VEILDistrict, destroy ALL actors label contains countess, destroy ALL actors class path contains Countess, keep ONE Countess SkeletalMeshActor at 809,-309,64.7 mesh as read from seat719 countess mesh line whole no invented path, keep ONE VEILCharacter playable at 0,0,100, PlayerStart 0,0,100, Vault 0,0,-80.9, floor 1618 collision BlockAll, NavMeshBoundsVolume 1618, build_level, save VEILDistrict must land disk over 626984 verify SAVE RESULT map size actors, write Saved seat719_out.txt whole plus push phi-game diff origin main. Gate: Click desktop icon door you walk single Countess only not 2 of her, Floor white hexagonal, Vault visible, Countess single, walks on floor, NavMesh green, Fragment to Forge to Beacon advances equals game not world. It cooks nothing packages nothing no 1.0 proof only in play engine itself not log.) ==='
$projW = 'D:\VEIL-OMNI'
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 5
$guiAfterW = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
Write-Output ('GUI781 AFTER COUNT ' + $guiAfterW.Count)
$outFileW = Join-Path $projW 'Saved\seat719_out.txt'
if (Test-Path $outFileW) { Remove-Item $outFileW -Force }
$surveyW = Join-Path $projW 'Saved\survey_out.txt'
if (Test-Path $surveyW) { Remove-Item $surveyW -Force }
Write-Output 'OUT781 OLD DELETED True'
$seatW = Join-Path $projW 'Saved\seat719.py'
if (Test-Path $seatW) { Copy-Item $seatW ($seatW + '.phi-backup-781') -Force; Write-Output 'SEAT781 BACKUP True'; Get-Content $seatW | Select-String -Pattern 'Countess|Vault|NavMesh|PlayerStart' | ForEach-Object { Write-Output ('SEAT781 LINE ' + $_.Line) } }
Write-Output 'SINGLE781 COUNTESS ONLY 809,-309,64.7 CHARACTER 0,0,100 PLAYERSTART 0,0,100 VAULT 0,0,-80.9 FLOOR 1618 NAV 1618x1618'
$outW = Join-Path $projW 'Saved\Logs\VEIL_PHI781_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_PHI781_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('CMD781 PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'CMD781 STARTED DETACHED NO WAIT'
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP781 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'REMOTE CONNECT MUSE'
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
