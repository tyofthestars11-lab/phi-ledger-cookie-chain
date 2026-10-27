<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit 2>&1 | Select-Object -Last 1; Write-Output "MERGE SEALED" }
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\probe_faction_anims.py" "D:\VEIL\Scripts\probe_faction_anims.py" -Force
Copy-Item "veil\OMNI\Scripts\probe_faction_anims.py" "D:\OMNI-UE\Scripts\probe_faction_anims.py" -Force
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\probe_faction_anims.py" -abslog="D:\VEIL\Saved\fprobe.log" 2>&1 | Out-Null
Write-Output "=== VEIL FACTION ANIMS ==="
Select-String -Path "D:\VEIL\Saved\fprobe.log" -Pattern "\[FPROBE\]|\[FANIM\]" | Select-Object -First 80 | ForEach-Object { $_.Line }
& $UEC "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\probe_faction_anims.py" -abslog="D:\OMNI-UE\Saved\fprobe.log" 2>&1 | Out-Null
Write-Output "=== OMNI FACTION ANIMS ==="
Select-String -Path "D:\OMNI-UE\Saved\fprobe.log" -Pattern "\[FPROBE\]|\[FANIM\]" | Select-Object -First 80 | ForEach-Object { $_.Line }
Write-Output "=== JOB 126 DONE ==="
```
