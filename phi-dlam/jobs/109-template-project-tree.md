<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Copy-Item "veil\OMNI\Scripts\*" "D:\OMNI-UE\Scripts" -Force
Write-Output "SYNCED scripts"

# STEP 2: why did the bind script stop after its first line? (its own log)
Write-Output "=== BIND LOG: the exception, verbatim ==="
Select-String -Path "D:\VEIL\Saved\bind.log" -Pattern "Traceback|Exception|Error" -Context 0,6 | Select-Object -First 4 | ForEach-Object { $_.Line; $_.Context.PostContext }

# STEP 3: the template PROJECT's own tree - Epic's shippable, self-consistent set
Write-Output "=== TP_ThirdPerson MANNEQUIN FILES ==="
$tp = "C:\Program Files\Epic Games\UE_5.8\Templates\TP_ThirdPerson"
Get-ChildItem $tp -Recurse -File -Include "SKM_*.uasset","ABP_*.uasset","*Skeleton*.uasset","SK_Mannequin*.uasset" -ErrorAction SilentlyContinue |
    Select-Object -First 22 | ForEach-Object { $_.FullName }

# STEP 4: copy the Characters subtree WHOLE into both projects (paths preserved)
$chars = Get-ChildItem "$tp\Content" -Directory -Filter "Characters" -ErrorAction SilentlyContinue | Select-Object -First 1
if ($chars) {
    robocopy $chars.FullName "D:\VEIL\Content\Characters" /E /NFL /NDL /NJH | Out-Null
    Write-Output "TP Characters -> VEIL (robocopy exit $LASTEXITCODE)"
    robocopy $chars.FullName "D:\OMNI-UE\Content\Characters" /E /NFL /NDL /NJH | Out-Null
    Write-Output "TP Characters -> OMNI (robocopy exit $LASTEXITCODE)"
} else { Write-Output "No Characters folder under TP_ThirdPerson\Content - hunt output above carries the true layout" }

# STEP 5: probe ALL meshes - a mesh whose skeleton resolves names itself
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\probe_all_meshes.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\probe-all.log" 2>&1 | Out-Null
Write-Output "=== PROBE ALL (VEIL) ==="
Select-String -Path "D:\VEIL\Saved\probe-all.log" -Pattern "\[PROBE\]" | ForEach-Object { $_.Line }
Write-Output "=== JOB 109 DONE ==="
```
