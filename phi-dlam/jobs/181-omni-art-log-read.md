<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== job 169's materials verdict under its real tag: apply_materials logs as [ART] ==="
if (Test-Path "D:\OMNI-UE\Saved\materials.log") {
  Select-String -Path "D:\OMNI-UE\Saved\materials.log" -Pattern "\[ART\]" | ForEach-Object { $_.Line }
} else { Write-Output "materials.log absent" }
Write-Output "=== JOB 181 DONE ==="
```
