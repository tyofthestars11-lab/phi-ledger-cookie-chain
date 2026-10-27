<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Write-Output "SYNCED VEIL scripts"

# STEP 2: before - every mannequin mesh names its skeleton reference
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\probe_skeleton.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\skeleton-probe2.log" 2>&1 | Out-Null
Write-Output "=== BEFORE ==="
Select-String -Path "D:\VEIL\Saved\skeleton-probe2.log" -Pattern "\[SKEL\]" | ForEach-Object { $_.Line }

# STEP 3: find the real skeleton on disk; mirror-copy it (and any sibling
# Skeleton assets in its folder) into both projects at the same
# Content-relative path the template uses
$found = $null
foreach ($r in @("C:\Program Files\Epic Games\UE_5.8\Templates", "C:\Program Files\Epic Games\UE_5.8\FeaturePacks", "C:\ProgramData\Epic\UnrealEngineLauncher\VaultCache")) {
    if (Test-Path $r) { $found = Get-ChildItem $r -Recurse -File -Filter "SK_Mannequin_Skeleton.uasset" -ErrorAction SilentlyContinue | Select-Object -First 1; if ($found) { break } }
}
if ($found) {
    Write-Output "SKELETON FOUND: $($found.FullName)"
    $parts = $found.FullName -split "\\"
    $ci = [Array]::LastIndexOf($parts, "Content")
    $rel = ($parts[($ci+1)..($parts.Length-1)] -join "\")
    Write-Output "Content-relative path: $rel"
    $siblings = Get-ChildItem $found.Directory.FullName -File -Filter "*.uasset" | Where-Object { $_.Name -match "keleton" }
    foreach ($proj in @("D:\VEIL", "D:\OMNI-UE")) {
        foreach ($sib in $siblings) {
            $sibRel = $rel -replace [regex]::Escape($found.Name), $sib.Name
            $dest = Join-Path $proj ("Content\" + $sibRel)
            New-Item -ItemType Directory -Force (Split-Path $dest) | Out-Null
            Copy-Item $sib.FullName $dest -Force
            Write-Output "copied $($sib.Name) -> $dest"
        }
    }
} else {
    Write-Output "SKELETON FILE NOT FOUND on disk - the repair takes the other road (report stands)"
}

# STEP 4: after - probe again, rebuild, smoke for the anim verdict
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\probe_skeleton.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\skeleton-probe3.log" 2>&1 | Out-Null
Write-Output "=== AFTER ==="
Select-String -Path "D:\VEIL\Saved\skeleton-probe3.log" -Pattern "\[SKEL\]" | ForEach-Object { $_.Line }
& "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat" VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -NoHotReload 2>&1 | Select-Object -Last 2
$proc = Start-Process "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe" -ArgumentList '"D:\VEIL\VEIL.uproject" -game -windowed -ResX=1280 -ResY=720 -abslog=D:\VEIL\Saved\smoke-game4.log' -PassThru
Start-Sleep -Seconds 25
try { taskkill /PID $proc.Id /T /F 2>&1 | Out-Null } catch {}
Write-Output "SMOKE: dwell complete"
Select-String -Path "D:\VEIL\Saved\smoke-game4.log" -Pattern "PHI BODY|has no skeleton" | Select-Object -First 8 | ForEach-Object { $_.Line }
Write-Output "=== JOB 105 DONE ==="
```
