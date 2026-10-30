<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 756 - FIND VAULT MESH ASSETS (Ground: Job 753 read seat752 out file whole: VAULT ALREADY PRESENT, VAULT MESH SEARCH COUNT 0, NONE FOUND, LATTICE LEFT AS IS, map 629620, single Countess on disk. Vault real mesh path is not in any seat log, no guessed path stands. This job reads only: Content directory search for Vault in file names, list full paths and sizes, also list mesh asset files with Vault in the path, no edits, no save. It cooks nothing, packages nothing, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$contentW = Join-Path $projW 'Content'
Write-Output ('CONTENT756 PRESENT ' + (Test-Path $contentW))
if (Test-Path $contentW) {
  $vaultFiles = @(Get-ChildItem -Path $contentW -Recurse -Filter '*Vault*' -ErrorAction SilentlyContinue)
  Write-Output ('VAULT756 FILES ' + $vaultFiles.Count)
  foreach ($f in $vaultFiles) { Write-Output ('VAULT756 FILE ' + $f.FullName + ' SIZE ' + $f.Length) }
  $meshFiles = @(Get-ChildItem -Path $contentW -Recurse -Include '*.uasset' -ErrorAction SilentlyContinue | Where-Object { $_.FullName -match 'Vault' })
  Write-Output ('VAULT756 UASSET ' + $meshFiles.Count)
  foreach ($f in $meshFiles) { Write-Output ('VAULT756 UASSET ' + $f.FullName) }
}
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP756 SIZE ' + (Get-Item $mapW).Length) }
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
