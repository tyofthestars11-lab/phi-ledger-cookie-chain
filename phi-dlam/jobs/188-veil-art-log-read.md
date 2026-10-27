<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== VEIL's materials verdict under its real tag: apply_materials logs as [ART] (OMNI's read in job 181: 231/0 PASS COMPLETE) ==="
if (Test-Path "D:\VEIL\Saved\materials.log") {
  Select-String -Path "D:\VEIL\Saved\materials.log" -Pattern "\[ART\]" | ForEach-Object { $_.Line }
} else { Write-Output "VEIL materials.log absent - its pass state is unproven" }
Write-Output "=== JOB 188 DONE ==="
```
