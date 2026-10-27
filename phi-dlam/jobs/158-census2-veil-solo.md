<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== census2 VEIL, solo - largest actors + whatever hangs over the spawn ==="
Copy-Item "veil\world_census2.py" "D:\VEIL\Scripts\world_census2.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\world_census2.py" -abslog="D:\VEIL\Saved\census2.log" 2>&1 | Out-Null
Select-String -Path "D:\VEIL\Saved\census2.log" -Pattern "\[CENSUS2\]|Traceback" | ForEach-Object { $_.Line }
Write-Output "=== JOB 158 DONE ==="
```
