<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
New-Item -ItemType Directory -Force "D:\VEIL\Data" | Out-Null
New-Item -ItemType Directory -Force "D:\OMNI-UE\Data" | Out-Null
Copy-Item "veil\VEIL\Source\*" "D:\VEIL\Source" -Recurse -Force
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Copy-Item "veil\VEIL\Data\*" "D:\VEIL\Data" -Force
Copy-Item "veil\OMNI\Source\*" "D:\OMNI-UE\Source" -Recurse -Force
Copy-Item "veil\OMNI\Scripts\*" "D:\OMNI-UE\Scripts" -Force
Copy-Item "veil\OMNI\Data\*" "D:\OMNI-UE\Data" -Force
Write-Output "SYNCED both projects (source + scripts + item data)"

$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
$BB = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat"

# STEP 2: build VEIL (item row struct compiles in), import its table
& $BB VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -NoHotReload 2>&1 | Select-Object -Last 2
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\import_items.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\items-import.log" 2>&1 | Out-Null
Write-Output "VEIL import exit: $LASTEXITCODE"
Select-String -Path "D:\VEIL\Saved\items-import.log" -Pattern "\[ITEMS\]" | ForEach-Object { $_.Line }

# STEP 3: build OMNI, import its table
& $BB OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex -NoHotReload 2>&1 | Select-Object -Last 2
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\import_items.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\items-import.log" 2>&1 | Out-Null
Write-Output "OMNI import exit: $LASTEXITCODE"
Select-String -Path "D:\OMNI-UE\Saved\items-import.log" -Pattern "\[ITEMS\]" | ForEach-Object { $_.Line }
Write-Output "=== JOB 100 DONE ==="
```
