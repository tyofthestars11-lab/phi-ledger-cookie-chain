<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== job 148 timed out at the step bound (five editor startups in one job) - recover whatever its -abslog files already hold ==="
foreach ($f in @("D:\VEIL\Saved\census.log","D:\OMNI-UE\Saved\census.log","D:\OMNI-UE\Saved\deep.log","D:\VEIL\Saved\swap2.log","D:\OMNI-UE\Saved\swap2.log")) {
  Write-Output "--- $f ---"
  if (Test-Path $f) {
    Select-String -Path $f -Pattern "\[CENSUS\]|\[DEEP\]|\[SWAP2\]|Traceback" | Select-Object -First 80 | ForEach-Object { $_.Line }
  } else { Write-Output "absent - that pass never wrote its log" }
}
Write-Output "=== JOB 151 DONE ==="
```
