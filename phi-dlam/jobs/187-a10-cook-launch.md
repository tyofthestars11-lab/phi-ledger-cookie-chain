<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== A10: VEIL cook launched in the open on the clean-build tree - its fresh UAT log IS the full error census ==="
$UAT = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat"
$args = @("BuildCookRun", "-project=D:\VEIL\VEIL.uproject", "-noP4", "-platform=Win64", "-clientconfig=Development", "-cook", "-build", "-stage", "-pak", "-archive", "-archivedirectory=D:\Builds\VEIL-A10", "-unattended", "-utf8output")
$p = Start-Process $UAT -ArgumentList $args -PassThru -WindowStyle Hidden
Write-Output "A10 UAT pid: $($p.Id)"
Start-Sleep -Seconds 20
if (Get-Process -Id $p.Id -ErrorAction SilentlyContinue) { Write-Output "A10: running in the open (state read follows in a later job)" } else { Write-Output "A10: exited within 20s - its log carries the reason" }
Write-Output "=== JOB 187 DONE ==="
```
