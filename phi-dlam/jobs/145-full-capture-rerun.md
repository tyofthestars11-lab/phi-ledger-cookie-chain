<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== 145 full-capture re-run: no grep filters - the error lines are the payload ==="
Write-Output "--- on-disk script heads (proof of what the PC actually holds) ---"
Get-Content "D:\VEIL\Scripts\world_census.py" -First 4
Get-Content "D:\OMNI-UE\Scripts\omni_deep_pass.py" -First 4
$Cmd = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
Write-Output "--- world census VEIL (full tail) ---"
& $Cmd "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\world_census.py" -unattended -nosplash 2>&1 | Select-Object -Last 50
Write-Output "exit: $LASTEXITCODE"
Write-Output "--- deep pass OMNI (full tail) ---"
& $Cmd "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\omni_deep_pass.py" -unattended -nosplash 2>&1 | Select-Object -Last 50
Write-Output "exit: $LASTEXITCODE"
Write-Output "--- swap armed2 VEIL (full tail) ---"
& $Cmd "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\swap_armed2.py" -unattended -nosplash 2>&1 | Select-Object -Last 30
Write-Output "exit: $LASTEXITCODE"
Write-Output "=== JOB 145 DONE ==="
```
