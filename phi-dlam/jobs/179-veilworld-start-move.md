<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== VEILWorld's start moves to the designed coordinates (OMNI parity, job 124) ==="
Copy-Item "veil\move_veilworld_start.py" "D:\VEIL\Scripts\move_veilworld_start.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\move_veilworld_start.py" -abslog="D:\VEIL\Saved\start2.log" 2>&1 | Out-Null
Get-Content "D:\VEIL\Saved\start2.log" -Tail 30 | Select-String -Pattern "START2|Traceback|Error|line" | ForEach-Object { $_.Line }
Write-Output "=== JOB 179 DONE ==="
```
