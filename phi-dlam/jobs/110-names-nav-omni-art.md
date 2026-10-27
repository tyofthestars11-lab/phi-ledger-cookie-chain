<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Config\*" "D:\VEIL\Config" -Force
Copy-Item "veil\OMNI\Config\*" "D:\OMNI-UE\Config" -Force
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Copy-Item "veil\OMNI\Scripts\*" "D:\OMNI-UE\Scripts" -Force
Write-Output "SYNCED config (names for both + own ProjectIDs) + scripts"
Select-String -Path "D:\VEIL\Config\DefaultGame.ini" -Pattern "ProjectName" | ForEach-Object { "VEIL " + $_.Line }
Select-String -Path "D:\OMNI-UE\Config\DefaultGame.ini" -Pattern "ProjectName" | ForEach-Object { "OMNI " + $_.Line }

# STEP 2: nav bake, all three worlds
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\bake_nav.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\nav-bake.log" 2>&1 | Out-Null
Write-Output "=== VEIL NAV ==="
Select-String -Path "D:\VEIL\Saved\nav-bake.log" -Pattern "\[NAV\]" | ForEach-Object { $_.Line }
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\bake_nav.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\nav-bake.log" 2>&1 | Out-Null
Write-Output "=== OMNI NAV ==="
Select-String -Path "D:\OMNI-UE\Saved\nav-bake.log" -Pattern "\[NAV\]" | ForEach-Object { $_.Line }

# STEP 3: OMNI art rerun - the stocked-pool fallback now guarantees coverage
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\apply_materials.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\art-pass4.log" 2>&1 | Out-Null
Write-Output "=== OMNI ART (fallback armed) ==="
Select-String -Path "D:\OMNI-UE\Saved\art-pass4.log" -Pattern "\[ART\]" | Select-Object -First 12 | ForEach-Object { $_.Line }

# STEP 4: OMNI smoke - world, body, and the warning state
$proc = Start-Process "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe" -ArgumentList '"D:\OMNI-UE\OMNI.uproject" -game -windowed -ResX=1280 -ResY=720 -abslog=D:\OMNI-UE\Saved\smoke-game5.log' -PassThru
Start-Sleep -Seconds 25
try { taskkill /PID $proc.Id /T /F 2>&1 | Out-Null } catch {}
Write-Output "SMOKE: dwell complete"
Select-String -Path "D:\OMNI-UE\Saved\smoke-game5.log" -Pattern "PHI BODY|LoadMap" | Select-Object -First 6 | ForEach-Object { $_.Line }
Write-Output "=== JOB 110 DONE ==="
```
