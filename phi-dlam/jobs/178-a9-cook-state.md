<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== A9 state: the cook job 172 launched in the open (pid 55588) - where does it stand? ==="
$p = Get-Process -Id 55588 -ErrorAction SilentlyContinue
if ($p) { Write-Output "A9 UAT pid 55588: STILL RUNNING" } else { Write-Output "A9 UAT pid 55588: not running (cook finished or closed)" }
if (Test-Path "D:\Builds\VEIL-A9") {
  Write-Output "D:\Builds\VEIL-A9 EXISTS:"
  Get-ChildItem "D:\Builds\VEIL-A9" -Recurse -Filter "*.exe" -ErrorAction SilentlyContinue | ForEach-Object { "  exe: $($_.FullName)" }
  $sz = (Get-ChildItem "D:\Builds\VEIL-A9" -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
  Write-Output "  archive size: $([math]::Round($sz/1GB,2)) GB"
} else { Write-Output "D:\Builds\VEIL-A9 not created" }
Write-Output "--- launch log tail ---"
if (Test-Path "D:\VEIL\Saved\uat-a9-launch.log") { Get-Content "D:\VEIL\Saved\uat-a9-launch.log" -Tail 12 }
if (Test-Path "D:\VEIL\Saved\uat-a9-launch.err.log") { Write-Output "--- err tail ---"; Get-Content "D:\VEIL\Saved\uat-a9-launch.err.log" -Tail 6 }
$uatLog = "$env:APPDATA\Unreal Engine\AutomationTool\Logs\C+Program+Files+Epic+Games+UE_5.8\Log.txt"
if (Test-Path $uatLog) {
  Write-Output "--- UAT trace: first errors of the latest run ---"
  Select-String -Path $uatLog -Pattern "LogObj: Error|LogBlueprint: Error|Cook failed|BUILD SUCCESSFUL|AutomationTool exiting" | Select-Object -First 10 | ForEach-Object { $_.Line }
}
Write-Output "=== JOB 178 DONE ==="
```
