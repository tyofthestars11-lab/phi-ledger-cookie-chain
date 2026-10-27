<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== FabLibrary retry: job 166's copy returned robocopy exit 16 - first read its actual layout, then copy what is there ==="
$vc = "C:\ProgramData\Epic\EpicGamesLauncher\VaultCache"
$src = Get-ChildItem $vc -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -like "FabLibrary*" } | Select-Object -First 1
if (!$src) { Write-Output "no FabLibrary folder in VaultCache" }
else {
  Write-Output "folder: $($src.FullName)"
  Get-ChildItem $src.FullName | ForEach-Object { "  $($_.Name)" }
  $data = Join-Path $src.FullName "data\Content"
  if (!(Test-Path $data)) { $data = Join-Path $src.FullName "data" }
  if (!(Test-Path $data)) { $data = $src.FullName }
  Write-Output "copy source: $data"
  foreach ($proj in @("D:\VEIL","D:\OMNI-UE")) {
    robocopy $data "$proj\Content\FabLibrary" /E /NFL /NDL /NJH /NJS /NP | Out-Null
    Write-Output "FabLibrary -> $proj\Content\FabLibrary : robocopy exit $LASTEXITCODE (0-7 = success)"
  }
}
Write-Output "=== JOB 177 DONE ==="
```
