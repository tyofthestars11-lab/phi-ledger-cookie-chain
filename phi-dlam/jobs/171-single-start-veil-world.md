<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== single start VEIL side: VEILWorld's duplicate start resolved the same way ==="
Copy-Item "veil\single_start.py" "D:\VEIL\Scripts\single_start.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\single_start.py" -abslog="D:\VEIL\Saved\start.log" 2>&1 | Out-Null
Select-String -Path "D:\VEIL\Saved\start.log" -Pattern "\[START\]|Traceback" | ForEach-Object { $_.Line }
Write-Output "=== JOB 171 DONE ==="
```
