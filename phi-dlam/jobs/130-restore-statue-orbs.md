<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\restore_orbs.py" "D:\VEIL\Scripts\restore_orbs.py" -Force
Copy-Item "veil\OMNI\Scripts\restore_orbs.py" "D:\OMNI-UE\Scripts\restore_orbs.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\restore_orbs.py" -abslog="D:\VEIL\Saved\orb.log" 2>&1 | Out-Null
Select-String -Path "D:\VEIL\Saved\orb.log" -Pattern "\[ORB\]" | ForEach-Object { $_.Line }
& $UEC "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\restore_orbs.py" -abslog="D:\OMNI-UE\Saved\orb.log" 2>&1 | Out-Null
Select-String -Path "D:\OMNI-UE\Saved\orb.log" -Pattern "\[ORB\]" | ForEach-Object { $_.Line }
Write-Output "=== JOB 130 DONE ==="
```
