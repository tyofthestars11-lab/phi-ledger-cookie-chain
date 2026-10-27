<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Copy-Item "veil\OMNI\Scripts\*" "D:\OMNI-UE\Scripts" -Force
Write-Output "SYNCED scripts"

$VC = "C:\ProgramData\Epic\EpicGamesLauncher\VaultCache"
robocopy "$VC\ParagonCountess\data\Content" "D:\OMNI-UE\Content" /E /NFL /NDL /NJH | Out-Null
Write-Output "Countess -> OMNI (exit $LASTEXITCODE)"
robocopy "$VC\ParagonCountess\data\Content" "D:\VEIL\Content" /E /NFL /NDL /NJH | Out-Null
Write-Output "Countess -> VEIL (exit $LASTEXITCODE)"
robocopy "$VC\ParagonGreystone\data\Content" "D:\OMNI-UE\Content" /E /NFL /NDL /NJH | Out-Null
Write-Output "Greystone -> OMNI (exit $LASTEXITCODE)"

$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\probe_anims.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\probe-anims.log" 2>&1 | Out-Null
Write-Output "=== VEIL ANIMS + SICKA MESHES ==="
Select-String -Path "D:\VEIL\Saved\probe-anims.log" -Pattern "\[ANIM\]|\[MESH\]" | Select-Object -First 60 | ForEach-Object { $_.Line }

& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\probe_all_meshes.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\probe-all.log" 2>&1 | Out-Null
Write-Output "=== OMNI LIVING BODIES ==="
Select-String -Path "D:\OMNI-UE\Saved\probe-all.log" -Pattern "\[PROBE\].*-> /Game|\[PROBE\] meshes|\[PROBE\] COMPLETE" | Select-Object -First 24 | ForEach-Object { $_.Line }

& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\probe_anims.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\probe-anims.log" 2>&1 | Out-Null
Write-Output "=== OMNI ANIMS ==="
Select-String -Path "D:\OMNI-UE\Saved\probe-anims.log" -Pattern "\[ANIM\]" | Select-Object -First 40 | ForEach-Object { $_.Line }

& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\spawn_probe.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\spawn-probe.log" 2>&1 | Out-Null
Write-Output "=== OMNI SPAWN vs GROUND ==="
Select-String -Path "D:\OMNI-UE\Saved\spawn-probe.log" -Pattern "\[SPAWN\]|\[GROUND\]" | ForEach-Object { $_.Line }

# nav bake LAST - nothing saves a level after this
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\bake_nav.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\nav-bake2.log" 2>&1 | Out-Null
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\bake_nav.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\nav-bake2.log" 2>&1 | Out-Null
Write-Output "=== NAV REBAKE (final step) ==="
Select-String -Path "D:\VEIL\Saved\nav-bake2.log","D:\OMNI-UE\Saved\nav-bake2.log" -Pattern "\[NAV\]" | ForEach-Object { $_.Line }
Write-Output "=== JOB 111 DONE ==="
```
