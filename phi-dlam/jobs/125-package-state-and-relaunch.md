<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit 2>&1 | Select-Object -Last 1; Write-Output "MERGE SEALED" }
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Write-Output "=== UAT / cook processes still running? ==="
Get-Process -Name "AutomationTool", "dotnet", "UnrealEditor-Cmd" -ErrorAction SilentlyContinue | ForEach-Object { "$($_.ProcessName) pid=$($_.Id) cpu=$([int]$_.CPU)s" }
Write-Output "=== VEIL-A7 archive contents ==="
if (Test-Path "D:\Builds\VEIL-A7") {
    Get-ChildItem "D:\Builds\VEIL-A7" -Recurse -Filter "*.exe" -ErrorAction SilentlyContinue | ForEach-Object { $_.FullName }
    Get-ChildItem "D:\Builds\VEIL-A7" -Recurse -ErrorAction SilentlyContinue | Measure-Object -Property Length -Sum | ForEach-Object { "total MB: $([int]($_.Sum/1MB))" }
} else { Write-Output "D:\Builds\VEIL-A7 does not exist" }
Write-Output "=== latest UAT log tail ==="
$uatlog = Get-ChildItem "C:\Users\Admin\AppData\Local\UnrealEngine\Programs\AutomationTool\Saved\Logs\*.txt" -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($uatlog) { Write-Output $uatlog.FullName; Get-Content $uatlog.FullName -Tail 6 }
$cooking = Get-Process -Name "AutomationTool" -ErrorAction SilentlyContinue
$exe = Get-ChildItem "D:\Builds\VEIL-A7" -Recurse -Filter "*.exe" -ErrorAction SilentlyContinue
if (-not $cooking -and -not $exe) {
    Write-Output "=== relaunching VEIL package in the open (the 240s lane cannot hold a full cook) ==="
    $UAT = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat"
    Start-Process $UAT -ArgumentList 'BuildCookRun -project="D:\VEIL\VEIL.uproject" -noP4 -platform=Win64 -clientconfig=Development -cook -allmaps -build -stage -pak -archive -archivedirectory="D:\Builds\VEIL-A7"' | Out-Null
    Write-Output "VEIL UAT launched - a later job reads the archive"
} elseif ($exe) { Write-Output "VEIL PACKAGE STANDS - exe present" }
else { Write-Output "VEIL cook still running - leave it" }
Write-Output "=== JOB 125 DONE ==="
```
