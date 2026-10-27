<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== the free-store packs still only in the cache come INTO both projects + OMNI parity ==="
$vc = "C:\ProgramData\Epic\EpicGamesLauncher\VaultCache"
function CopyPack($pattern, $targets) {
  $src = Get-ChildItem $vc -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -like "$pattern*" } | Select-Object -First 1
  if (!$src) { Write-Output "$pattern : NOT in VaultCache"; return }
  $data = Join-Path $src.FullName "data\Content"
  if (!(Test-Path $data)) { $data = Join-Path $src.FullName "Content" }
  foreach ($proj in $targets) {
    robocopy $data "$proj\Content" /E /NFL /NDL /NJH /NJS /NP | Out-Null
    Write-Output "$($src.Name) -> $proj : robocopy exit $LASTEXITCODE (0-7 = success)"
  }
}
CopyPack "FREEMounc" @("D:\VEIL","D:\OMNI-UE")
CopyPack "LavaMate" @("D:\VEIL","D:\OMNI-UE")
CopyPack "ModularS" @("D:\VEIL","D:\OMNI-UE")
CopyPack "FabLibrary" @("D:\VEIL","D:\OMNI-UE")
CopyPack "ParagonMinions" @("D:\OMNI-UE")
CopyPack "SickaEnv" @("D:\OMNI-UE")
Write-Output "--- Content sizes now ---"
foreach ($proj in @("D:\VEIL","D:\OMNI-UE")) {
  $sz = (Get-ChildItem "$proj\Content" -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
  Write-Output "$proj Content: $([math]::Round($sz/1GB,2)) GB"
}
Write-Output "=== JOB 166 DONE ==="
```
