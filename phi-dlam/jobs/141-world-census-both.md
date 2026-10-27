<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== world census: every tall actor, base + mesh, all maps, both projects ==="
Copy-Item "veil\world_census.py" "D:\VEIL\Scripts\world_census.py" -Force
Copy-Item "veil\world_census.py" "D:\OMNI-UE\Scripts\world_census.py" -Force
$Cmd = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
Write-Output "--- VEIL maps ---"
& $Cmd "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\world_census.py" -unattended -nosplash 2>&1 | Select-String "CENSUS" | ForEach-Object { $_.Line }
Write-Output "--- OMNI maps ---"
& $Cmd "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\world_census.py" -unattended -nosplash 2>&1 | Select-String "CENSUS" | ForEach-Object { $_.Line }
Write-Output "=== JOB 141 DONE ==="
```
