<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== swap armed2: exterior buildings, worlds only, BOTH projects ==="
Copy-Item "veil\swap_armed2.py" "D:\VEIL\Scripts\swap_armed2.py" -Force
Copy-Item "veil\swap_armed2.py" "D:\OMNI-UE\Scripts\swap_armed2.py" -Force
$Cmd = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
Write-Output "--- VEIL pass ---"
& $Cmd "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\swap_armed2.py" -unattended -nosplash 2>&1 | Select-String "SWAP2" | ForEach-Object { $_.Line }
Write-Output "--- OMNI pass ---"
& $Cmd "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\swap_armed2.py" -unattended -nosplash 2>&1 | Select-String "SWAP2" | ForEach-Object { $_.Line }
Write-Output "=== JOB 139 DONE ==="
```
