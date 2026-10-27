<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Config\*" "D:\VEIL\Config" -Force
Copy-Item "veil\VEIL\Source\*" "D:\VEIL\Source" -Recurse -Force
Write-Output "SYNCED VEIL config + source"

# STEP 2: package attempt 5 - the ABP's skeleton decides this one
& "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat" BuildCookRun -project="D:\VEIL\VEIL.uproject" -noP4 -platform=Win64 -clientconfig=Development -cook -build -stage -pak -archive -archivedirectory="D:\VEIL-Package" 2>&1 | Tee-Object -FilePath "D:\VEIL\Saved\uat-package5.log" | Select-Object -Last 5

# STEP 3: outcome; if the exe exists, the desktop door points at it
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
    Select-String -Path "D:\VEIL\Saved\uat-package5.log" -Pattern "Error:|Cook failed" | Select-Object -First 6 | ForEach-Object { $_.Line }
}
Write-Output "=== JOB 104 DONE ==="
```
