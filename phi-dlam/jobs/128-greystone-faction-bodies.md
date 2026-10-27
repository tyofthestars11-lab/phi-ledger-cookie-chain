<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit 2>&1 | Select-Object -Last 1; Write-Output "MERGE SEALED" }
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Copy-Item "veil\VEIL\Source\*" "D:\VEIL\Source" -Recurse -Force
Copy-Item "veil\OMNI\Source\*" "D:\OMNI-UE\Source" -Recurse -Force
Write-Output "SYNCED source (Greystone faction bodies + direct steer)"
$BB = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat"
& $BB VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -waitmutex 2>&1 | Select-Object -Last 2
& $BB OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -waitmutex 2>&1 | Select-Object -Last 2
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe"
$proc = Start-Process $UE -ArgumentList '"D:\OMNI-UE\OMNI.uproject" -game -windowed -ResX=1280 -ResY=720 -abslog=D:\OMNI-UE\Saved\smoke-faction1.log' -PassThru
Start-Sleep -Seconds 30
try { taskkill /PID $proc.Id /T /F 2>&1 | Out-Null } catch {}
Write-Output "=== OMNI FACTION BODY SMOKE ==="
Select-String -Path "D:\OMNI-UE\Saved\smoke-faction1.log" -Pattern "PHI FACTION BODY" | Select-Object -First 6 | ForEach-Object { $_.Line }
Write-Output "=== VEIL package archive check (job 125's open cook) ==="
if (Test-Path "D:\Builds\VEIL-A7") {
    Get-ChildItem "D:\Builds\VEIL-A7" -Recurse -Filter "*.exe" -ErrorAction SilentlyContinue | ForEach-Object { $_.FullName }
    Get-ChildItem "D:\Builds\VEIL-A7" -Recurse -ErrorAction SilentlyContinue | Measure-Object -Property Length -Sum | ForEach-Object { "archive MB so far: $([int]($_.Sum/1MB))" }
} else { Write-Output "D:\Builds\VEIL-A7 not created yet - cook still in early stages" }
Get-Process -Name "AutomationTool" -ErrorAction SilentlyContinue | ForEach-Object { "UAT still cooking: pid=$($_.Id) cpu=$([int]$_.CPU)s" }
Write-Output "=== JOB 128 DONE ==="
```
