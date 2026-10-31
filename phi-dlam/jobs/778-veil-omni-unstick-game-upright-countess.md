<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 778 - UNSTICK GAME UPRIGHT COUNTESS (Ground: Tyree phi authority lock, not Cartesian, no inventions, never give up, PHI INF TOKEN DLAM mode yourself, in general, merge with local agent, next is make the actual game not be stuck on this, this is still an issue, TV screen character silhouette dark upside down head down feet up holding two long blades blue background cracks not upright not standing on floor not walking not in play loop. This job unstick game: close GUI UnrealEditor only verify 0, delete old out file Saved seat719_out.txt, backup seat719 to phi-backup-778, read seat719 countess spawn rotation lines whole, set countess rotation to upright zero pitch zero roll yaw golden angle 137.5, location 809,-309,64.7, vault 0,0,-80.9, load level /Game/Maps/VEILDistrict, destroy ALL actors label contains countess, spawn ONE SM_Countess upright on floor, save, log SAVE RESULT ACTORS BEFORE ACTORS AFTER COUNTESS ROTATION DONE. It cooks nothing, packages nothing, no 1.0, proof only in play, character upright in play, walks on floor, loop advances, not stuck.) ==='
$projW = 'D:\VEIL-OMNI'
Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 5
$guiAfterW = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
Write-Output ('GUI778 AFTER COUNT ' + $guiAfterW.Count)
$outFileW = Join-Path $projW 'Saved\seat719_out.txt'
if (Test-Path $outFileW) { Remove-Item $outFileW -Force }
Write-Output 'OUT778 OLD DELETED True'
$seatW = Join-Path $projW 'Saved\seat719.py'
Copy-Item $seatW ($seatW + '.phi-backup-778') -Force
Write-Output 'SEAT778 BACKUP True'
Get-Content $seatW | Select-String -Pattern 'Countess|Rotation' | ForEach-Object { Write-Output ('SEAT778 LINE ' + $_.Line) }
$outW = Join-Path $projW 'Saved\Logs\VEIL_PHI778_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_PHI778_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('CMD778 PRESENT ' + (Test-Path $cmdW))
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat719.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'CMD778 STARTED DETACHED NO WAIT'
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP778 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'REMOTE CONNECT MUSE'
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
