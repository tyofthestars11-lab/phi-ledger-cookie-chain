<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== single start: the designed spawn (420,-420,240) becomes the only PlayerStart in both worlds ==="
Copy-Item "veil\single_start.py" "D:\OMNI-UE\Scripts\single_start.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\single_start.py" -abslog="D:\OMNI-UE\Saved\start.log" 2>&1 | Out-Null
Select-String -Path "D:\OMNI-UE\Saved\start.log" -Pattern "\[START\]|Traceback" | ForEach-Object { $_.Line }
Write-Output "=== JOB 170 DONE ==="
```
