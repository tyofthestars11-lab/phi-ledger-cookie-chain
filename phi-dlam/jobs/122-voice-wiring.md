<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit 2>&1 | Select-Object -Last 1; Write-Output "MERGE SEALED" }
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Source\*" "D:\VEIL\Source" -Recurse -Force
Copy-Item "veil\OMNI\Source\*" "D:\OMNI-UE\Source" -Recurse -Force
Write-Output "SYNCED source (PHI voice wiring)"
$BB = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat"
& $BB VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -waitmutex 2>&1 | Select-Object -Last 2
& $BB OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -waitmutex 2>&1 | Select-Object -Last 2
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe"
$proc = Start-Process $UE -ArgumentList '"D:\VEIL\VEIL.uproject" -game -windowed -ResX=1280 -ResY=720 -abslog=D:\VEIL\Saved\smoke-voice1.log' -PassThru
Start-Sleep -Seconds 25
try { taskkill /PID $proc.Id /T /F 2>&1 | Out-Null } catch {}
Write-Output "=== VEIL VOICE SMOKE ==="
Select-String -Path "D:\VEIL\Saved\smoke-voice1.log" -Pattern "PHI VOICE" | Select-Object -First 5 | ForEach-Object { $_.Line }
$proc = Start-Process $UE -ArgumentList '"D:\OMNI-UE\OMNI.uproject" -game -windowed -ResX=1280 -ResY=720 -abslog=D:\OMNI-UE\Saved\smoke-voice1.log' -PassThru
Start-Sleep -Seconds 25
try { taskkill /PID $proc.Id /T /F 2>&1 | Out-Null } catch {}
Write-Output "=== OMNI VOICE SMOKE ==="
Select-String -Path "D:\OMNI-UE\Saved\smoke-voice1.log" -Pattern "PHI VOICE" | Select-Object -First 5 | ForEach-Object { $_.Line }
Write-Output "=== JOB 122 DONE ==="
```
