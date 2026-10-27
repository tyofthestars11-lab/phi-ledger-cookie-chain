<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit 2>&1 | Select-Object -Last 1; Write-Output "MERGE SEALED" }
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\reseat_towers.py" "D:\VEIL\Scripts\reseat_towers.py" -Force
Copy-Item "veil\OMNI\Scripts\reseat_towers.py" "D:\OMNI-UE\Scripts\reseat_towers.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\reseat_towers.py" -abslog="D:\VEIL\Saved\reseat.log" 2>&1 | Out-Null
Write-Output "=== VEIL RESEAT ==="
Select-String -Path "D:\VEIL\Saved\reseat.log" -Pattern "\[RESEAT\]" | Select-Object -First 25 | ForEach-Object { $_.Line }
& $UEC "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\reseat_towers.py" -abslog="D:\OMNI-UE\Saved\reseat.log" 2>&1 | Out-Null
Write-Output "=== OMNI RESEAT ==="
Select-String -Path "D:\OMNI-UE\Saved\reseat.log" -Pattern "\[RESEAT\]" | Select-Object -First 25 | ForEach-Object { $_.Line }
Write-Output "=== JOB 127 DONE ==="
```
