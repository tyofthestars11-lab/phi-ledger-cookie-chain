<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== census2 OMNI, solo - largest actors + whatever hangs over the spawn ==="
Copy-Item "veil\world_census2.py" "D:\OMNI-UE\Scripts\world_census2.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\world_census2.py" -abslog="D:\OMNI-UE\Saved\census2.log" 2>&1 | Out-Null
Select-String -Path "D:\OMNI-UE\Saved\census2.log" -Pattern "\[CENSUS2\]|Traceback" | ForEach-Object { $_.Line }
Write-Output "=== JOB 159 DONE ==="
```
