<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== OMNI materials pass - 231 of 231 slots wear lava (job 155); the stocked pools answer ==="
Copy-Item "veil\OMNI\Scripts\apply_materials.py" "D:\OMNI-UE\Scripts\apply_materials.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\apply_materials.py" -abslog="D:\OMNI-UE\Saved\materials.log" 2>&1 | Out-Null
Select-String -Path "D:\OMNI-UE\Saved\materials.log" -Pattern "\[MAT\]|\[MATERIAL|Traceback|Error" | Select-Object -First 40 | ForEach-Object { $_.Line }
Write-Output "=== JOB 169 DONE ==="
```
