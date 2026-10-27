<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== A8 cook: why did pid 58244 end with no archive? the launch log answers ==="
if (Test-Path "D:\VEIL\Saved\uat-a8-launch.log") { Get-Content "D:\VEIL\Saved\uat-a8-launch.log" -Tail 30 }
if (Test-Path "D:\VEIL\Saved\uat-a8-launch.err.log") { Write-Output "--- err log ---"; Get-Content "D:\VEIL\Saved\uat-a8-launch.err.log" -Tail 15 }
$uatDir = "$env:APPDATA\Unreal Engine\AutomationTool\Logs"
if (Test-Path $uatDir) { Get-ChildItem $uatDir | Sort-Object LastWriteTime -Descending | Select-Object -First 4 | ForEach-Object { "$($_.Name)  $($_.LastWriteTime)" } }
Write-Output "=== smoke4 logs: what was the game doing when the dwell ended? (tails, unfiltered) ==="
foreach ($f in @("D:\OMNI-UE\Saved\Logs\phi-smoke4-omni.log","D:\VEIL\Saved\Logs\phi-smoke4-veil.log")) {
  Write-Output "--- $f tail ---"
  if (Test-Path $f) { Get-Content $f -Tail 12; Write-Output "--- PHI line count in file:"; (Select-String -Path $f -Pattern "PHI" | Measure-Object).Count }
  else { Write-Output "absent" }
}
Write-Output "=== JOB 160 DONE ==="
```
