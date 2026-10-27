<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Source\*" "D:\VEIL\Source" -Recurse -Force
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Copy-Item "veil\VEIL\Data\*" "D:\VEIL\Data" -Force
Write-Output "SYNCED VEIL source + scripts + data (god mode, menus, dialogue)"

$BB = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat"
& $BB VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -waitmutex 2>&1 | Select-Object -Last 3

$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\import_dialogue.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\dialogue-import.log" 2>&1 | Out-Null
Write-Output "=== VEIL DIALOGUE ==="
Select-String -Path "D:\VEIL\Saved\dialogue-import.log" -Pattern "\[DIALOGUE\]" | ForEach-Object { $_.Line }

$proc = Start-Process "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe" -ArgumentList '"D:\VEIL\VEIL.uproject" -game -windowed -ResX=1280 -ResY=720 -abslog=D:\VEIL\Saved\smoke-game6.log' -PassThru
Start-Sleep -Seconds 25
try { taskkill /PID $proc.Id /T /F 2>&1 | Out-Null } catch {}
Write-Output "=== VEIL SMOKE (menus + godmode build) ==="
Select-String -Path "D:\VEIL\Saved\smoke-game6.log" -Pattern "PHI BODY|Main menu|GODMODE" | Select-Object -First 8 | ForEach-Object { $_.Line }
Write-Output "=== JOB 112 DONE ==="
```
