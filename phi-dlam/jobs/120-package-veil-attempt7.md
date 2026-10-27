<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit 2>&1 | Select-Object -Last 1; Write-Output "MERGE SEALED" }
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
$UAT = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat"
& $UAT BuildCookRun -project="D:\VEIL\VEIL.uproject" -noP4 -platform=Win64 -clientconfig=Development -cook -allmaps -build -stage -pak -archive -archivedirectory="D:\Builds\VEIL-A7" 2>&1 | Select-Object -Last 6
Write-Output "=== EXE CHECK ==="
Get-ChildItem "D:\Builds\VEIL-A7" -Recurse -Filter "*.exe" -ErrorAction SilentlyContinue | Select-Object -First 4 | ForEach-Object { $_.FullName }
Write-Output "=== JOB DONE ==="
```
