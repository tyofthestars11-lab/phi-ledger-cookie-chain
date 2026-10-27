<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== swap2 OMNI, solo - the cube replacement pass ==="
Copy-Item "veil\swap_armed2.py" "D:\OMNI-UE\Scripts\swap_armed2.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\swap_armed2.py" -abslog="D:\OMNI-UE\Saved\swap2.log" 2>&1 | Out-Null
Select-String -Path "D:\OMNI-UE\Saved\swap2.log" -Pattern "\[SWAP2\]|Traceback" | ForEach-Object { $_.Line }
Write-Output "=== JOB 157 DONE ==="
```
