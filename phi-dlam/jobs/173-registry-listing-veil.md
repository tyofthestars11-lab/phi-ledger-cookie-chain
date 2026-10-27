<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== registry listing VEIL, solo - the swap's retune gets written from these names ==="
Copy-Item "veil\registry_listing.py" "D:\VEIL\Scripts\registry_listing.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\registry_listing.py" -abslog="D:\VEIL\Saved\registry.log" 2>&1 | Out-Null
Select-String -Path "D:\VEIL\Saved\registry.log" -Pattern "\[REGISTRY\]|Traceback" | ForEach-Object { $_.Line }
Write-Output "=== JOB 173 DONE ==="
```
