<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Source\*" "D:\VEIL\Source" -Recurse -Force
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Write-Output "SYNCED VEIL source + scripts"

# STEP 2: art pass on VEILDistrict + VEILWorld
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\apply_materials.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\art-pass.log" 2>&1 | Out-Null
Write-Output "ART PASS exit: $LASTEXITCODE"
Select-String -Path "D:\VEIL\Saved\art-pass.log" -Pattern "\[ART\]" | Select-Object -First 20 | ForEach-Object { $_.Line }

# STEP 3: rebuild VEIL (anim BeginPlay wiring)
& "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat" VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -NoHotReload 2>&1 | Select-Object -Last 3

# STEP 4: dwell smoke - anim verdict lines from the game's own log
$proc = Start-Process "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe" -ArgumentList '"D:\VEIL\VEIL.uproject" -game -windowed -ResX=1280 -ResY=720 -abslog=D:\VEIL\Saved\smoke-game3.log' -PassThru
Start-Sleep -Seconds 25
try { taskkill /PID $proc.Id /T /F 2>&1 | Out-Null } catch {}
Write-Output "SMOKE: dwell complete"
Write-Output "=== PHI BODY / ANIM GREP (first 10) ==="
Select-String -Path "D:\VEIL\Saved\smoke-game3.log" -Pattern "PHI BODY" | Select-Object -First 10 | ForEach-Object { $_.Line }
Write-Output "=== ANIM WARNINGS (first 6) ==="
Select-String -Path "D:\VEIL\Saved\smoke-game3.log" -Pattern "LogAnimation|LogSkeletalMesh|AnimInstance" | Select-Object -First 6 | ForEach-Object { $_.Line }
Write-Output "=== JOB 097 DONE ==="
```
