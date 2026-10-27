<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Copy-Item "veil\OMNI\Scripts\*" "D:\OMNI-UE\Scripts" -Force
Write-Output "SYNCED scripts"

$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"

# STEP 2: OMNI art v2 (its shelf is stocked now) + mood pass on OMNIWorld
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\apply_materials.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\art-pass2.log" 2>&1 | Out-Null
Write-Output "OMNI ART V2 exit: $LASTEXITCODE"
Select-String -Path "D:\OMNI-UE\Saved\art-pass2.log" -Pattern "\[ART\]" | Select-Object -First 16 | ForEach-Object { $_.Line }
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\add_mood.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\mood.log" 2>&1 | Out-Null
Select-String -Path "D:\OMNI-UE\Saved\mood.log" -Pattern "\[MOOD\]" | ForEach-Object { $_.Line }

# STEP 3: VEIL mood pass
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\add_mood.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\mood.log" 2>&1 | Out-Null
Select-String -Path "D:\VEIL\Saved\mood.log" -Pattern "\[MOOD\]" | ForEach-Object { $_.Line }

# STEP 4: items import, corrected JSON shape, both games
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\import_items.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\items-import2.log" 2>&1 | Out-Null
Select-String -Path "D:\VEIL\Saved\items-import2.log" -Pattern "\[ITEMS\]" | ForEach-Object { $_.Line }
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\import_items.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\items-import2.log" 2>&1 | Out-Null
Select-String -Path "D:\OMNI-UE\Saved\items-import2.log" -Pattern "\[ITEMS\]" | ForEach-Object { $_.Line }
Write-Output "=== JOB 103 DONE ==="
```
