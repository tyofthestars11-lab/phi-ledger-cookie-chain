<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== the exact header lines the VEIL compiler saw in job 175 (its copy, not the repo's) ==="
Get-Content "D:\VEIL\Source\VEIL\Public\Game\VEILGameMode.h" | Select-Object -Index (30..40 + 74..82) | ForEach-Object { $_ }
Write-Output "=== sync source, build both ==="
Copy-Item "veil\VEIL\Source\*" "D:\VEIL\Source" -Recurse -Force -ErrorAction SilentlyContinue
Copy-Item "veil\OMNI\Source\*" "D:\OMNI-UE\Source" -Recurse -Force -ErrorAction SilentlyContinue
$Build = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat"
& $Build VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex 2>&1 | Select-String "Result:|error" | Select-Object -First 12 | ForEach-Object { $_.Line }
& $Build OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex 2>&1 | Select-String "Result:|error" | Select-Object -First 6 | ForEach-Object { $_.Line }
Write-Output "=== OMNI smoke: the controller interrogates the pawn's tick state ==="
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe"
$log = "D:\OMNI-UE\Saved\Logs\phi-smoke7-omni.log"
$p = Start-Process $UE -ArgumentList "`"D:\OMNI-UE\OMNI.uproject`"", "/Game/Maps/OMNIWorld", "-game", "-windowed", "-ResX=1280", "-ResY=720", "-abslog=$log", "-unattended", "-nosplash" -PassThru
Start-Sleep -Seconds 30
if (!$p.HasExited) { Stop-Process -Id $p.Id -Force; Write-Output "smoke closed after 30s" }
Start-Sleep -Seconds 3
if (Test-Path $log) { Select-String -Path $log -Pattern "TICKPROOF|MOVE TEST|GAMEMODE ALIVE|BODY CHECK" | ForEach-Object { $_.Line } }
Write-Output "=== JOB 180 DONE ==="
```
