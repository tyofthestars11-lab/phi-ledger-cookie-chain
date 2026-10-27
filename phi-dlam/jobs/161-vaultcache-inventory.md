<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== VaultCache: every pack the free store has already put on this disk ==="
$vc = "C:\ProgramData\Epic\EpicGamesLauncher\VaultCache"
Get-ChildItem $vc -Directory -ErrorAction SilentlyContinue | ForEach-Object {
  $sz = (Get-ChildItem $_.FullName -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
  "$($_.Name)  $([math]::Round($sz/1MB,0)) MB"
}
Write-Output "=== top-level Content folders already inside each project ==="
Write-Output "--- VEIL ---"
Get-ChildItem "D:\VEIL\Content" -Directory -ErrorAction SilentlyContinue | ForEach-Object { $_.Name }
Write-Output "--- OMNI ---"
Get-ChildItem "D:\OMNI-UE\Content" -Directory -ErrorAction SilentlyContinue | ForEach-Object { $_.Name }
Write-Output "=== JOB 161 DONE ==="
```
