<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== the A8 cook's own exception trace (AutomationTool Log.txt) ==="
$uatLog = "$env:APPDATA\Unreal Engine\AutomationTool\Logs\C+Program+Files+Epic+Games+UE_5.8\Log.txt"
if (Test-Path $uatLog) {
  Select-String -Path $uatLog -Pattern "Exception|Cook failed|Error:|Failed to" | Select-Object -First 25 | ForEach-Object { $_.Line }
} else { Write-Output "UAT Log.txt not at the expected path" }
Write-Output "=== classes census VEIL (every actor class - the shape's class hunt) ==="
Copy-Item "veil\classes_census.py" "D:\VEIL\Scripts\classes_census.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\classes_census.py" -abslog="D:\VEIL\Saved\classes.log" 2>&1 | Out-Null
Select-String -Path "D:\VEIL\Saved\classes.log" -Pattern "\[CLASSES\]|Traceback" | ForEach-Object { $_.Line }
Write-Output "=== JOB 163 DONE ==="
```
