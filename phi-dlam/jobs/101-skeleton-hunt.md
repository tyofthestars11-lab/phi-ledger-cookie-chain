<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Write-Output "SYNCED VEIL scripts"

# STEP 2: probe what skeleton the mesh and the ABP think they have
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\probe_skeleton.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\skeleton-probe.log" 2>&1 | Out-Null
Select-String -Path "D:\VEIL\Saved\skeleton-probe.log" -Pattern "\[SKEL\]" | ForEach-Object { $_.Line }

# STEP 3: hunt the skeleton asset across the whole install + VaultCache
Write-Output "=== SKELETON FILE HUNT ==="
$roots = @("C:\Program Files\Epic Games\UE_5.8\Templates", "C:\Program Files\Epic Games\UE_5.8\FeaturePacks", "C:\ProgramData\Epic\UnrealEngineLauncher\VaultCache", "C:\Users\Admin\AppData\Local\UnrealEngine")
foreach ($r in $roots) {
    if (Test-Path $r) {
        Get-ChildItem $r -Recurse -File -Include "*keleton*.uasset","SK_Mannequin*.uasset","SKM_Manny*.uasset" -ErrorAction SilentlyContinue |
            Select-Object -First 14 | ForEach-Object { $_.FullName }
    }
}
Write-Output "=== JOB 101 DONE (copy + fix ride job 102 once the home is named) ==="
```
