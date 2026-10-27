<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== OMNI deep pass, solo (one commandlet per job) ==="
Copy-Item "veil\omni_deep_pass.py" "D:\OMNI-UE\Scripts\omni_deep_pass.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\omni_deep_pass.py" -abslog="D:\OMNI-UE\Saved\deep.log" 2>&1 | Out-Null
Select-String -Path "D:\OMNI-UE\Saved\deep.log" -Pattern "\[DEEP\]|Traceback" | ForEach-Object { $_.Line }
Write-Output "=== JOB 155 DONE ==="
```
