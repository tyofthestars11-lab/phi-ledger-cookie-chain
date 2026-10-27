<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Write-Output "=== VEIL smoke-game7: the body lines ==="
Select-String -Path "D:\VEIL\Saved\smoke-game7.log" -Pattern "PHI BODY" | ForEach-Object { $_.Line }
Write-Output "=== VEIL skeleton warnings (want zero) ==="
(Select-String -Path "D:\VEIL\Saved\smoke-game7.log" -Pattern "has no skeleton").Count
Write-Output "=== OMNI smoke-game7: the body lines ==="
Select-String -Path "D:\OMNI-UE\Saved\smoke-game7.log" -Pattern "PHI BODY" | ForEach-Object { $_.Line }
Write-Output "=== OMNI skeleton warnings (want zero) ==="
(Select-String -Path "D:\OMNI-UE\Saved\smoke-game7.log" -Pattern "has no skeleton").Count
Write-Output "=== JOB 123 DONE ==="
```
