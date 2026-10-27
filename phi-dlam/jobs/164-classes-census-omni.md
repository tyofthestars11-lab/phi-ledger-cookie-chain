<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== classes census OMNI, solo ==="
Copy-Item "veil\classes_census.py" "D:\OMNI-UE\Scripts\classes_census.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\classes_census.py" -abslog="D:\OMNI-UE\Saved\classes.log" 2>&1 | Out-Null
Select-String -Path "D:\OMNI-UE\Saved\classes.log" -Pattern "\[CLASSES\]|Traceback" | ForEach-Object { $_.Line }
Write-Output "=== JOB 164 DONE ==="
```
