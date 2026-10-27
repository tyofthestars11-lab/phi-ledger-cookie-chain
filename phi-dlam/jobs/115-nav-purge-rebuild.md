<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Copy-Item "veil\OMNI\Scripts\*" "D:\OMNI-UE\Scripts" -Force
Copy-Item "veil\VEIL\Config\*" "D:\VEIL\Config" -Force
Copy-Item "veil\OMNI\Config\*" "D:\OMNI-UE\Config" -Force
Write-Output "SYNCED purge script + config (RecastNavMesh defaults)"
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\purge_nav.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\nav-purge.log" 2>&1 | Out-Null
Write-Output "=== VEIL PURGE ==="
Select-String -Path "D:\VEIL\Saved\nav-purge.log" -Pattern "\[PURGE\]" | ForEach-Object { $_.Line }
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\purge_nav.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\nav-purge.log" 2>&1 | Out-Null
Write-Output "=== OMNI PURGE ==="
Select-String -Path "D:\OMNI-UE\Saved\nav-purge.log" -Pattern "\[PURGE\]" | ForEach-Object { $_.Line }
Write-Output "=== JOB 115 DONE ==="
```
