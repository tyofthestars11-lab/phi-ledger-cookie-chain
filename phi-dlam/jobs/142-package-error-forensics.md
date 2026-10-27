<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== OMNI-A7 compile error lines (the failure above the tail) ==="
$log = "D:\OMNI-UE\Saved\package-omni-a7.log"
if (Test-Path $log) {
  Select-String -Path $log -Pattern "error|Error" | Select-Object -First 30 | ForEach-Object { $_.Line }
  Write-Output "--- lines around first error ---"
  $first = (Select-String -Path $log -Pattern "error C\d|error:" | Select-Object -First 1).LineNumber
  if ($first) { Get-Content $log | Select-Object -Skip ([Math]::Max(0,$first-6)) -First 25 }
} else { Write-Output "omni a7 log missing" }
Write-Output "=== AutomationTool logs (where open UAT cooks actually write) ==="
$at = "$env:APPDATA\Unreal Engine\AutomationTool\Logs"
Get-ChildItem $at -Recurse -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 12 FullName, Length, LastWriteTime | Format-Table -AutoSize | Out-String | Write-Output
Write-Output "=== JOB 142 DONE ==="
```
