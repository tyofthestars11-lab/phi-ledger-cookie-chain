<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Copy-Item "veil\OMNI\Scripts\*" "D:\OMNI-UE\Scripts" -Force
Copy-Item "veil\OMNI\Source\*" "D:\OMNI-UE\Source" -Recurse -Force
Copy-Item "veil\OMNI\Config\*" "D:\OMNI-UE\Config" -Force
Write-Output "SYNCED scripts + OMNI source/config"

# STEP 2: OMNI gets its environment + machine content from the VaultCache shelf
$vc = $null
foreach ($r in @("C:\ProgramData\Epic\UnrealEngineLauncher\VaultCache", "C:\ProgramData\Epic\UnrealEngineLauncher", "D:\VaultCache")) {
    if (Test-Path $r) { $hit = Get-ChildItem $r -Recurse -Directory -Filter "SickaEnv" -ErrorAction SilentlyContinue | Select-Object -First 1; if ($hit) { $vc = $hit.FullName -replace "\\Content\\SickaEnv$","" -replace "\\SickaEnv$",""; break } }
}
Write-Output "SickaEnv found under: $vc"
if ($vc) {
    $sickaSrc = Get-ChildItem $vc -Recurse -Directory -Filter "SickaEnv" -ErrorAction SilentlyContinue | Select-Object -First 1
    robocopy $sickaSrc.FullName "D:\OMNI-UE\Content\SickaEnv" /E /NFL /NDL /NJH /NJS | Out-Null
    Write-Output "SickaEnv copied to OMNI (robocopy exit $LASTEXITCODE)"
    $minSrc = Get-ChildItem $vc -Recurse -Directory -Filter "ParagonMinions" -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($minSrc) { robocopy $minSrc.FullName "D:\OMNI-UE\Content\ParagonMinions" /E /NFL /NDL /NJH /NJS | Out-Null; Write-Output "ParagonMinions copied to OMNI (robocopy exit $LASTEXITCODE)" }
}

# STEP 3: art pass v2 on VEIL (environment pools only) + the old pass's failure lines
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
Write-Output "=== OLD ART LOG: failure hunt ==="
Select-String -Path "D:\VEIL\Saved\art-pass.log" -Pattern "Traceback|Error|Exception|materialized" | Select-Object -First 8 | ForEach-Object { $_.Line }
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\apply_materials.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\art-pass2.log" 2>&1 | Out-Null
Write-Output "ART V2 exit: $LASTEXITCODE"
Select-String -Path "D:\VEIL\Saved\art-pass2.log" -Pattern "\[ART\]" | Select-Object -First 26 | ForEach-Object { $_.Line }
Write-Output "=== JOB 102 DONE ==="
```
