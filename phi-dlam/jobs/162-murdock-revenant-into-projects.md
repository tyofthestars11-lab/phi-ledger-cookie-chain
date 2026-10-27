<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== character reinforcements from the library he already owns: ParagonMurdock + ParagonRevenant into both projects ==="
$vc = "C:\ProgramData\Epic\EpicGamesLauncher\VaultCache"
foreach ($pack in @("ParagonMurdock","ParagonRevenant")) {
  $src = Get-ChildItem $vc -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -like "$pack*" } | Select-Object -First 1
  if (!$src) { Write-Output "$pack : NOT in VaultCache under that name"; continue }
  $data = Join-Path $src.FullName "data\Content"
  if (!(Test-Path $data)) { $data = Join-Path $src.FullName "Content" }
  foreach ($proj in @("D:\VEIL","D:\OMNI-UE")) {
    robocopy $data "$proj\Content" /E /NFL /NDL /NJH /NJS /NP | Out-Null
    Write-Output "$pack -> $proj : robocopy exit $LASTEXITCODE (0-7 = success)"
  }
}
Write-Output "--- project Content sizes now ---"
foreach ($proj in @("D:\VEIL","D:\OMNI-UE")) {
  $sz = (Get-ChildItem "$proj\Content" -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
  Write-Output "$proj Content: $([math]::Round($sz/1GB,2)) GB"
}
Write-Output "=== JOB 162 DONE ==="
```
