<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== swap2 VEIL, solo - the cube replacement pass ==="
Copy-Item "veil\swap_armed2.py" "D:\VEIL\Scripts\swap_armed2.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\swap_armed2.py" -abslog="D:\VEIL\Saved\swap2.log" 2>&1 | Out-Null
Select-String -Path "D:\VEIL\Saved\swap2.log" -Pattern "\[SWAP2\]|Traceback" | ForEach-Object { $_.Line }
Write-Output "=== JOB 156 DONE ==="
```
