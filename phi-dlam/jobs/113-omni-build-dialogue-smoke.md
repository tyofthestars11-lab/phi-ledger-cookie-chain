<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\OMNI\Source\*" "D:\OMNI-UE\Source" -Recurse -Force
Copy-Item "veil\OMNI\Scripts\*" "D:\OMNI-UE\Scripts" -Force
Copy-Item "veil\OMNI\Data\*" "D:\OMNI-UE\Data" -Force
Write-Output "SYNCED OMNI source + scripts + data"

$BB = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat"
& $BB OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -waitmutex 2>&1 | Select-Object -Last 3

$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\import_dialogue.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\dialogue-import.log" 2>&1 | Out-Null
Write-Output "=== OMNI DIALOGUE ==="
Select-String -Path "D:\OMNI-UE\Saved\dialogue-import.log" -Pattern "\[DIALOGUE\]" | ForEach-Object { $_.Line }

$proc = Start-Process "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe" -ArgumentList '"D:\OMNI-UE\OMNI.uproject" -game -windowed -ResX=1280 -ResY=720 -abslog=D:\OMNI-UE\Saved\smoke-game6.log' -PassThru
Start-Sleep -Seconds 25
try { taskkill /PID $proc.Id /T /F 2>&1 | Out-Null } catch {}
Write-Output "=== OMNI SMOKE ==="
Select-String -Path "D:\OMNI-UE\Saved\smoke-game6.log" -Pattern "PHI BODY|Main menu|GODMODE" | Select-Object -First 8 | ForEach-Object { $_.Line }
Write-Output "=== JOB 113 DONE ==="
```
