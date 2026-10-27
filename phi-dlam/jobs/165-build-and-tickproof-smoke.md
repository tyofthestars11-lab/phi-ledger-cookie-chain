<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== build v3 instruments (GAMEMODE ALIVE + tick-driven MOVE TEST + TICKPROOF) ==="
Copy-Item "veil\VEIL\Source\*" "D:\VEIL\Source" -Recurse -Force -ErrorAction SilentlyContinue
Copy-Item "veil\OMNI\Source\*" "D:\OMNI-UE\Source" -Recurse -Force -ErrorAction SilentlyContinue
$Build = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat"
& $Build VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex 2>&1 | Select-String "Result:|error" | ForEach-Object { $_.Line }
& $Build OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex 2>&1 | Select-String "Result:|error" | ForEach-Object { $_.Line }
Write-Output "=== OMNI smoke with mid-run log snapshots (is the log alive while the game runs?) ==="
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe"
$log = "D:\OMNI-UE\Saved\Logs\phi-smoke5-omni.log"
$p = Start-Process $UE -ArgumentList "`"D:\OMNI-UE\OMNI.uproject`"", "/Game/Maps/OMNIWorld", "-game", "-windowed", "-ResX=1280", "-ResY=720", "-abslog=$log", "-unattended", "-nosplash" -PassThru
foreach ($mark in @(15, 30, 45)) {
  Start-Sleep -Seconds 15
  $lines = if (Test-Path $log) { (Get-Content $log | Measure-Object -Line).Lines } else { 0 }
  $phi = if (Test-Path $log) { (Select-String -Path $log -Pattern "PHI" | Measure-Object).Count } else { 0 }
  Write-Output "t=${mark}s: processAlive=$($p.HasExited -eq $false) logLines=$lines phiLines=$phi"
}
if (!$p.HasExited) { Stop-Process -Id $p.Id -Force; Write-Output "smoke closed after 45s" }
Start-Sleep -Seconds 3
if (Test-Path $log) { Select-String -Path $log -Pattern "PHI GAMEMODE ALIVE|PHI TICKPROOF|PHI MOVE TEST|PHI BODY|PHI VOICE|PHI CENSUS|PHI FACTION" | ForEach-Object { $_.Line } }
Write-Output "=== JOB 165 DONE ==="
```
