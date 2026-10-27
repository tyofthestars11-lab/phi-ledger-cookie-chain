<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Scripts\*" "D:\VEIL\Scripts" -Force
Copy-Item "veil\OMNI\Scripts\*" "D:\OMNI-UE\Scripts" -Force
Write-Output "SYNCED scripts"

# STEP 2: what did VEIL art v2 actually apply? (its log, past the pool list)
Write-Output "=== ART V2 FORENSICS ==="
Select-String -Path "D:\VEIL\Saved\art-pass2.log" -Pattern "family|materialized|Traceback|Error" | Select-Object -First 14 | ForEach-Object { $_.Line }

# STEP 3: THE BIND - real skeleton onto both meshes + ABP, both games
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\bind_skeleton.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\bind.log" 2>&1 | Out-Null
Write-Output "=== VEIL BIND ==="
Select-String -Path "D:\VEIL\Saved\bind.log" -Pattern "\[BIND\]" | ForEach-Object { $_.Line }
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\bind_skeleton.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\bind.log" 2>&1 | Out-Null
Write-Output "=== OMNI BIND ==="
Select-String -Path "D:\OMNI-UE\Saved\bind.log" -Pattern "\[BIND\]" | ForEach-Object { $_.Line }

# STEP 4: rebuild VEIL + smoke - ANIM LIVE is the verdict
& "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat" VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -NoHotReload 2>&1 | Select-Object -Last 2
$proc = Start-Process "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe" -ArgumentList '"D:\VEIL\VEIL.uproject" -game -windowed -ResX=1280 -ResY=720 -abslog=D:\VEIL\Saved\smoke-game6.log' -PassThru
Start-Sleep -Seconds 25
try { taskkill /PID $proc.Id /T /F 2>&1 | Out-Null } catch {}
Write-Output "SMOKE: dwell complete"
Select-String -Path "D:\VEIL\Saved\smoke-game6.log" -Pattern "PHI BODY|has no skeleton" | Select-Object -First 8 | ForEach-Object { $_.Line }

# STEP 5: package attempt 6 - the ABP compiles now, or names its next error
& "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat" BuildCookRun -project="D:\VEIL\VEIL.uproject" -noP4 -platform=Win64 -clientconfig=Development -cook -build -stage -pak -archive -archivedirectory="D:\VEIL-Package" 2>&1 | Tee-Object -FilePath "D:\VEIL\Saved\uat-package6.log" | Select-Object -Last 4
if (Test-Path "D:\VEIL-Package\Windows\VEIL.exe") {
    Write-Output "PACKAGE EXE EXISTS: D:\VEIL-Package\Windows\VEIL.exe"
    $ws = New-Object -ComObject WScript.Shell
    $lnk = $ws.CreateShortcut("$env:USERPROFILE\Desktop\VEIL - The Last Signal.lnk")
    $lnk.TargetPath = "D:\VEIL-Package\Windows\VEIL.exe"
    $lnk.WorkingDirectory = "D:\VEIL-Package\Windows"
    $lnk.Save()
    Write-Output "DESKTOP DOOR UPGRADED to the packaged exe"
} else {
    Write-Output "NO EXE YET"
    Select-String -Path "D:\VEIL\Saved\uat-package6.log" -Pattern "Error:|Cook failed" | Select-Object -First 6 | ForEach-Object { $_.Line }
}
Write-Output "=== JOB 107 DONE ==="
```
