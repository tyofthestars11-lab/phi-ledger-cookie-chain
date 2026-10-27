<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== Builds root ==="
if (Test-Path "D:\Builds") { Get-ChildItem "D:\Builds" | Select-Object Name, LastWriteTime | Format-Table -AutoSize | Out-String | Write-Output } else { Write-Output "D:\Builds absent" }
foreach ($a in @("VEIL-A7","OMNI-A7")) {
  $p = "D:\Builds\$a"
  if (Test-Path $p) {
    $sz = (Get-ChildItem $p -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
    Write-Output "$a present: $([math]::Round($sz/1MB,1)) MB, newest: $((Get-ChildItem $p -Recurse -File | Sort-Object LastWriteTime -Descending | Select-Object -First 1).LastWriteTime)"
  } else { Write-Output "$a archive not present" }
}
Write-Output "=== UAT / editor processes ==="
Get-Process | Where-Object { $_.ProcessName -match "Unreal|UAT|AutomationTool" } | Select-Object Id, ProcessName, StartTime | Format-Table -AutoSize | Out-String | Write-Output
Write-Output "=== VEIL package logs (tails) ==="
foreach ($lg in @("D:\VEIL\Saved\package-veil-a7.log","D:\VEIL\Saved\Logs\package-veil-a7.log")) {
  if (Test-Path $lg) { Write-Output "--- $lg"; Get-Content $lg -Tail 30 }
}
Get-ChildItem "D:\VEIL\Saved" -Filter "*pack*" -ErrorAction SilentlyContinue | Select-Object Name, Length, LastWriteTime | Format-Table -AutoSize | Out-String | Write-Output
Write-Output "=== OMNI package logs (tails) ==="
foreach ($lg in @("D:\OMNI-UE\Saved\package-omni-a7.log","D:\OMNI-UE\Saved\Logs\package-omni-a7.log")) {
  if (Test-Path $lg) { Write-Output "--- $lg"; Get-Content $lg -Tail 30 }
}
Get-ChildItem "D:\OMNI-UE\Saved" -Filter "*pack*" -ErrorAction SilentlyContinue | Select-Object Name, Length, LastWriteTime | Format-Table -AutoSize | Out-String | Write-Output
Write-Output "=== JOB 136 DONE ==="
```
