<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== A10 state: the cook job 187 launched in the open (pid 59228) ==="
$p = Get-Process -Id 59228 -ErrorAction SilentlyContinue
if ($p) { Write-Output "A10 UAT pid 59228: STILL RUNNING" } else { Write-Output "A10 UAT pid 59228: not running (cook finished or closed)" }
if (Test-Path "D:\Builds\VEIL-A10") {
  Write-Output "D:\Builds\VEIL-A10 EXISTS:"
  Get-ChildItem "D:\Builds\VEIL-A10" -Recurse -Filter "*.exe" -ErrorAction SilentlyContinue | ForEach-Object { "  exe: $($_.FullName)" }
  $sz = (Get-ChildItem "D:\Builds\VEIL-A10" -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
  Write-Output "  archive size: $([math]::Round($sz/1GB,2)) GB"
} else { Write-Output "D:\Builds\VEIL-A10 not created" }
Write-Output "=== A10's fresh UAT log: the full error census ==="
$uat = "C:\Users\Admin\AppData\Roaming\Unreal Engine\AutomationTool\Logs\C+Program+Files+Epic+Games+UE_5.8\Log.txt"
if (Test-Path $uat) {
  $errs = Select-String -Path $uat -Pattern "Error:" | ForEach-Object { $_.Line }
  Write-Output "total Error lines: $($errs.Count)"
  $errs | Select-Object -First 30 | ForEach-Object { $_ }
  Write-Output "--- distinct assets named in errors ---"
  $errs | Select-String -Pattern "D:\\\\VEIL\\\\Content\\\\[^ :]+" | ForEach-Object { $_.Matches[0].Value } | Sort-Object -Unique
  Select-String -Path $uat -Pattern "BUILD SUCCESSFUL|BUILD FAILED|ExitCode=" | Select-Object -Last 4 | ForEach-Object { $_.Line }
} else { Write-Output "UAT Log.txt absent" }
Write-Output "=== JOB 190 DONE ==="
```
