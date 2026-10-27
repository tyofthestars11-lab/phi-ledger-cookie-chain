<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\OMNI\Scripts\*" "D:\OMNI-UE\Scripts" -Force
Write-Output "SYNCED OMNI scripts"

# STEP 2: the shelf, named whole (job 089's root: Epic\EpicGamesLauncher)
$vc = "C:\ProgramData\Epic\EpicGamesLauncher\VaultCache"
Write-Output "=== VAULTCACHE PACKS ==="
Get-ChildItem $vc -Directory | ForEach-Object { $_.Name }

# STEP 3: LavaMate -> OMNI (data\Content maps to /Game, the 089 pattern)
$lava = Get-ChildItem $vc -Directory | Where-Object { $_.Name -like 'LavaMate*' } | Select-Object -First 1
if ($lava) {
    robocopy "$($lava.FullName)\data\Content" 'D:\OMNI-UE\Content' /E /NFL /NDL /NJH | Out-Null
    Write-Output "LAVAMATE -> OMNI Content (from $($lava.Name))"
} else { Write-Output "LavaMate pack folder not found on the shelf" }
$sz = (Get-ChildItem 'D:\OMNI-UE\Content' -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
Write-Output ("OMNI Content now {0:N2} GB" -f ($sz/1GB))

# STEP 4: OMNI art v2 on its stocked shelf + build + smoke
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\apply_materials.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\art-pass3.log" 2>&1 | Out-Null
Write-Output "OMNI ART exit: $LASTEXITCODE"
Select-String -Path "D:\OMNI-UE\Saved\art-pass3.log" -Pattern "\[ART\]" | Select-Object -First 18 | ForEach-Object { $_.Line }
& "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat" OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex -NoHotReload 2>&1 | Select-Object -Last 2
$proc = Start-Process "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe" -ArgumentList '"D:\OMNI-UE\OMNI.uproject" -game -windowed -ResX=1280 -ResY=720 -abslog=D:\OMNI-UE\Saved\smoke-game4.log' -PassThru
Start-Sleep -Seconds 25
try { taskkill /PID $proc.Id /T /F 2>&1 | Out-Null } catch {}
Write-Output "SMOKE: dwell complete"
Select-String -Path "D:\OMNI-UE\Saved\smoke-game4.log" -Pattern "PHI BODY|LoadMap|has no skeleton" | Select-Object -First 8 | ForEach-Object { $_.Line }
Write-Output "=== JOB 108 DONE ==="
```
