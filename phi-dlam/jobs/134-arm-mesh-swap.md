<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\swap_armed.py" "D:\VEIL\Scripts\swap_armed.py" -Force
Copy-Item "veil\OMNI\Scripts\swap_armed.py" "D:\OMNI-UE\Scripts\swap_armed.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\swap_armed.py" -abslog="D:\VEIL\Saved\swaparm.log" 2>&1 | Out-Null
Select-String -Path "D:\VEIL\Saved\swaparm.log" -Pattern "\[SWAPARM\]" | ForEach-Object { $_.Line }
Write-Output "=== JOB 134 DONE ==="
```
