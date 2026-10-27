<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe"
Write-Output "=== VEIL District runtime census ==="
& $UE "D:\VEIL\VEIL.uproject" /Game/Maps/VEILDistrict -game -unattended -nosplash -abslog="D:\VEIL\Saved\census-district.log" -ExecCmds="quit" 2>&1 | Out-Null
Start-Sleep -Seconds 2
Select-String -Path "D:\VEIL\Saved\census-district.log" -Pattern "PHI CENSUS" -ErrorAction SilentlyContinue | ForEach-Object { $_.Line }
Write-Output "=== OMNI World runtime census ==="
& $UE "D:\OMNI-UE\OMNI.uproject" /Game/Maps/OMNIWorld -game -unattended -nosplash -abslog="D:\OMNI-UE\Saved\census-omni.log" -ExecCmds="quit" 2>&1 | Out-Null
Select-String -Path "D:\OMNI-UE\Saved\census-omni.log" -Pattern "PHI CENSUS" -ErrorAction SilentlyContinue | ForEach-Object { $_.Line }
Write-Output "=== JOB 133 DONE ==="
```
