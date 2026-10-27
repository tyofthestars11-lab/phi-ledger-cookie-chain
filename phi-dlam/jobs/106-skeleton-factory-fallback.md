<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Copy-Item "veil\OMNI\Scripts\*" "D:\OMNI-UE\Scripts" -Force
Write-Output "SYNCED scripts"

# STEP 2: factory skeleton repair (guarded - skips if 105's copy landed)
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\fix_skeleton_from_mesh.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\skelfix.log" 2>&1 | Out-Null
Select-String -Path "D:\VEIL\Saved\skelfix.log" -Pattern "\[SKELFIX\]" | ForEach-Object { $_.Line }
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\fix_skeleton_from_mesh.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\skelfix.log" 2>&1 | Out-Null
Select-String -Path "D:\OMNI-UE\Saved\skelfix.log" -Pattern "\[SKELFIX\]" | ForEach-Object { $_.Line }

# STEP 3: rebuild VEIL + smoke - the anim verdict
& "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat" VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -NoHotReload 2>&1 | Select-Object -Last 2
$proc = Start-Process "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe" -ArgumentList '"D:\VEIL\VEIL.uproject" -game -windowed -ResX=1280 -ResY=720 -abslog=D:\VEIL\Saved\smoke-game5.log' -PassThru
Start-Sleep -Seconds 25
try { taskkill /PID $proc.Id /T /F 2>&1 | Out-Null } catch {}
Write-Output "SMOKE: dwell complete"
Select-String -Path "D:\VEIL\Saved\smoke-game5.log" -Pattern "PHI BODY|has no skeleton" | Select-Object -First 8 | ForEach-Object { $_.Line }
Write-Output "=== JOB 106 DONE ==="
```
