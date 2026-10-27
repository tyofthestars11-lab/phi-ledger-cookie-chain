<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Copy-Item "veil\OMNI\Scripts\*" "D:\OMNI-UE\Scripts" -Force
Write-Output "SYNCED paragon anim probe (pull now carries --no-edit: no merge editor, ever)"

$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\probe_paragon_anims.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\probe-panims.log" 2>&1 | Out-Null
Write-Output "=== VEIL PARAGON ANIMS (mesh/skeleton/sequence triangle) ==="
Select-String -Path "D:\VEIL\Saved\probe-panims.log" -Pattern "\[PANIM\]" | Select-Object -First 55 | ForEach-Object { $_.Line }

Write-Output "=== TP_ThirdPerson CONTENT (the true layout) ==="
Get-ChildItem "C:\Program Files\Epic Games\UE_5.8\Templates\TP_ThirdPerson\Content" -Recurse -File -ErrorAction SilentlyContinue |
    Select-Object -First 40 | ForEach-Object { $_.FullName }
Write-Output "=== JOB 116 DONE ==="
```
