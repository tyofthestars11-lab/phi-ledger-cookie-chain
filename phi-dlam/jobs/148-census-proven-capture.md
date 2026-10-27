<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== census + deep pass + swap2, PROVEN capture (-abslog file + token grep, the job 130/134 pattern) ==="
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
Copy-Item "veil\world_census.py" "D:\VEIL\Scripts\world_census.py" -Force
Copy-Item "veil\world_census.py" "D:\OMNI-UE\Scripts\world_census.py" -Force
Copy-Item "veil\omni_deep_pass.py" "D:\OMNI-UE\Scripts\omni_deep_pass.py" -Force
Copy-Item "veil\swap_armed2.py" "D:\VEIL\Scripts\swap_armed2.py" -Force
Copy-Item "veil\swap_armed2.py" "D:\OMNI-UE\Scripts\swap_armed2.py" -Force
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\world_census.py" -abslog="D:\VEIL\Saved\census.log" 2>&1 | Out-Null
Write-Output "--- VEIL census ---"
Select-String -Path "D:\VEIL\Saved\census.log" -Pattern "\[CENSUS\]|Error|Traceback" | ForEach-Object { $_.Line }
& $UEC "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\world_census.py" -abslog="D:\OMNI-UE\Saved\census.log" 2>&1 | Out-Null
Write-Output "--- OMNI census ---"
Select-String -Path "D:\OMNI-UE\Saved\census.log" -Pattern "\[CENSUS\]|Error|Traceback" | ForEach-Object { $_.Line }
& $UEC "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\omni_deep_pass.py" -abslog="D:\OMNI-UE\Saved\deep.log" 2>&1 | Out-Null
Write-Output "--- OMNI deep pass ---"
Select-String -Path "D:\OMNI-UE\Saved\deep.log" -Pattern "\[DEEP\]|Error|Traceback" | ForEach-Object { $_.Line }
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\swap_armed2.py" -abslog="D:\VEIL\Saved\swap2.log" 2>&1 | Out-Null
Write-Output "--- VEIL swap2 ---"
Select-String -Path "D:\VEIL\Saved\swap2.log" -Pattern "\[SWAP2\]|Error|Traceback" | ForEach-Object { $_.Line }
& $UEC "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\swap_armed2.py" -abslog="D:\OMNI-UE\Saved\swap2.log" 2>&1 | Out-Null
Write-Output "--- OMNI swap2 ---"
Select-String -Path "D:\OMNI-UE\Saved\swap2.log" -Pattern "\[SWAP2\]|Error|Traceback" | ForEach-Object { $_.Line }
Write-Output "=== JOB 148 DONE ==="
```
