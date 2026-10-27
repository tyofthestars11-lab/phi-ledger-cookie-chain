<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== job 169's own lines, read clean (its first read was crowded out by startup error lines) ==="
if (Test-Path "D:\OMNI-UE\Saved\materials.log") {
  Select-String -Path "D:\OMNI-UE\Saved\materials.log" -Pattern "\[MAT\]|Traceback" | ForEach-Object { $_.Line }
} else { Write-Output "materials.log absent" }
Write-Output "=== JOB 176 DONE ==="
```
