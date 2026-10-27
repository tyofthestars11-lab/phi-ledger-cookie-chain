<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit 2>&1 | Select-Object -Last 1; Write-Output "MERGE SEALED" }
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Copy-Item "veil\OMNI\Scripts\fix_spawn.py" "D:\OMNI-UE\Scripts\fix_spawn.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\fix_spawn.py" -abslog="D:\OMNI-UE\Saved\spawn-fix.log" 2>&1 | Out-Null
Write-Output "=== SPAWN FIX ==="
Select-String -Path "D:\OMNI-UE\Saved\spawn-fix.log" -Pattern "\[SPAWN\]|\[CENSUS\]" | Select-Object -First 20 | ForEach-Object { $_.Line }
Write-Output "=== JOB 124 DONE ==="
```
