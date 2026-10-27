<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== VEIL materials pass, run for real this time (job 188 proved no [ART] log exists for VEIL; the script stands in the repo) ==="
Copy-Item "veil\VEIL\Scripts\apply_materials.py" "D:\VEIL\Scripts\apply_materials.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\apply_materials.py" -abslog="D:\VEIL\Saved\materials.log" 2>&1 | Out-Null
Select-String -Path "D:\VEIL\Saved\materials.log" -Pattern "\[ART\]|Traceback|Exception" | ForEach-Object { $_.Line }
Write-Output "=== JOB 192 DONE ==="
```
