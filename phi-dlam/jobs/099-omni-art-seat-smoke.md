<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\OMNI\Config\*" "D:\OMNI-UE\Config" -Force
Copy-Item "veil\OMNI\Source\*" "D:\OMNI-UE\Source" -Recurse -Force
Copy-Item "veil\OMNI\Scripts\*" "D:\OMNI-UE\Scripts" -Force
Write-Output "SYNCED OMNI config + source + scripts"

# STEP 2: art pass on OMNIWorld
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\apply_materials.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\art-pass.log" 2>&1 | Out-Null
Write-Output "ART PASS exit: $LASTEXITCODE"
Select-String -Path "D:\OMNI-UE\Saved\art-pass.log" -Pattern "\[ART\]" | Select-Object -First 14 | ForEach-Object { $_.Line }

# STEP 3: rebuild OMNI
& "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat" OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex -NoHotReload 2>&1 | Select-Object -Last 3

# STEP 4: dwell smoke - OMNI must now boot OMNIWorld, not the template
$proc = Start-Process "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe" -ArgumentList '"D:\OMNI-UE\OMNI.uproject" -game -windowed -ResX=1280 -ResY=720 -abslog=D:\OMNI-UE\Saved\smoke-game3.log' -PassThru
Start-Sleep -Seconds 25
try { taskkill /PID $proc.Id /T /F 2>&1 | Out-Null } catch {}
Write-Output "SMOKE: dwell complete"
Select-String -Path "D:\OMNI-UE\Saved\smoke-game3.log" -Pattern "PHI BODY|LoadMap" | Select-Object -First 8 | ForEach-Object { $_.Line }
Write-Output "=== JOB 099 DONE ==="
```
