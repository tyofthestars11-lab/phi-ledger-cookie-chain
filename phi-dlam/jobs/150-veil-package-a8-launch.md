<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== VEIL package attempt A8 - launch in the open (one game through the chain first) ==="
$existing = Get-Process -Name "AutomationTool","RunUAT" -ErrorAction SilentlyContinue
if ($existing) { Write-Output "a UAT process is already running (pid $($existing.Id)) - A8 not launched; the running cook owns the mutex"; Write-Output "=== JOB 150 DONE ==="; return }
$uatLog = "D:\VEIL\Saved\uat-a8-launch.log"
$RunUAT = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat"
$args = "BuildCookRun -project=`"D:\VEIL\VEIL.uproject`" -noP4 -platform=Win64 -clientconfig=Development -cook -allmaps -build -stage -pak -archive -archivedirectory=`"D:\Builds\VEIL-A8`""
$p = Start-Process -FilePath $RunUAT -ArgumentList $args -RedirectStandardOutput $uatLog -RedirectStandardError "D:\VEIL\Saved\uat-a8-launch.err.log" -PassThru
Write-Output "VEIL A8 UAT launched in the open: pid $($p.Id)"
Write-Output "launch log: $uatLog ; UAT log home: %APPDATA%\Unreal Engine\AutomationTool\Logs"
Write-Output "=== JOB 150 DONE ==="
```
