<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== OMNI deep pass: spawn census + material census + nav rebuild, then materials re-pass ==="
Copy-Item "veil\omni_deep_pass.py" "D:\OMNI-UE\Scripts\omni_deep_pass.py" -Force
$Cmd = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $Cmd "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\omni_deep_pass.py" -unattended -nosplash 2>&1 | Select-String "DEEP" | ForEach-Object { $_.Line }
Write-Output "--- materials re-pass (stocked pools, post job-111 copies) ---"
& $Cmd "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\apply_materials.py" -unattended -nosplash 2>&1 | Select-String "MAT|material|hit|miss" | Select-Object -First 30 | ForEach-Object { $_.Line }
Write-Output "=== JOB 140 DONE ==="
```
