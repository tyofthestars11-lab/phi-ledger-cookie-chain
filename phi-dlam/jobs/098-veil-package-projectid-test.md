<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Config\*" "D:\VEIL\Config" -Force
Write-Output "SYNCED VEIL config (ProjectID line removed - the cook's only Error line across three failed cooks)"
$DP = "D:\VEIL\DefaultGame.ini check:"
if (Select-String -Path "D:\VEIL\Config\DefaultGame.ini" -Pattern "ProjectID" -Quiet) { Write-Output "ProjectID STILL PRESENT" } else { Write-Output "ProjectID absent on disk - confirmed" }

# STEP 2: the cook itself, Development, output watched live
& "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat" BuildCookRun -project="D:\VEIL\VEIL.uproject" -noP4 -platform=Win64 -clientconfig=Development -cook -build -stage -pak -archive -archivedirectory="D:\VEIL-Package" 2>&1 | Tee-Object -FilePath "D:\VEIL\Saved\uat-package4.log" | Select-Object -Last 6

# STEP 3: outcome + the AutomationTool exception trace
if (Test-Path "D:\VEIL-Package\Windows\VEIL.exe") { Write-Output "PACKAGE EXE EXISTS: D:\VEIL-Package\Windows\VEIL.exe" } else { Write-Output "NO EXE YET" }
Write-Output "=== ERROR LINES (first 8) ==="
Select-String -Path "D:\VEIL\Saved\uat-package4.log" -Pattern "Error:|Cook failed|BUILD FAILED|BUILD SUCCESSFUL" | Select-Object -First 8 | ForEach-Object { $_.Line }
Write-Output "=== JOB 098 DONE ==="
```
