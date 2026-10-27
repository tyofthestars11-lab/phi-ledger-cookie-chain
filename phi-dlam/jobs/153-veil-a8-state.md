<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== VEIL A8 package state ==="
$proc = Get-Process -Id 58244 -ErrorAction SilentlyContinue
if ($proc) { Write-Output "A8 UAT still running: pid 58244, CPU $($proc.CPU)s" } else { Write-Output "A8 UAT process 58244: not running (cook finished or closed)" }
$uatLogs = Get-ChildItem "$env:APPDATA\Unreal Engine\AutomationTool\Logs" -Filter *.txt -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending
if ($uatLogs) {
  Write-Output "--- newest UAT log tail ($($uatLogs[0].Name)) ---"
  Select-String -Path $uatLogs[0].FullName -Pattern "BUILD SUCCESSFUL|BUILD FAILED|ExitCode|LogCook: Display: Cooked|Error:" | Select-Object -Last 25 | ForEach-Object { $_.Line }
  Get-Content $uatLogs[0].FullName -Tail 6
}
if (Test-Path "D:\Builds\VEIL-A8") {
  Write-Output "--- D:\Builds\VEIL-A8 ---"
  Get-ChildItem "D:\Builds\VEIL-A8" -Recurse -Filter *.exe -ErrorAction SilentlyContinue | ForEach-Object { "$($_.FullName)  $([math]::Round($_.Length/1MB,1)) MB" }
  $sz = (Get-ChildItem "D:\Builds\VEIL-A8" -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
  Write-Output "archive size so far: $([math]::Round($sz/1GB,2)) GB"
} else { Write-Output "D:\Builds\VEIL-A8 not created yet" }
Write-Output "=== JOB 153 DONE ==="
```
