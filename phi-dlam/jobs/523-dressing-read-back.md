<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 523 - THE DRESSING READ BACK AND THE VAULT CENSUS (Ground: job 522 ran three of the delivered Meta scripts in the editor and scattered the project own environment meshes into the saved district, each writing its own page. This job reads both pages whole, greps the project log for the bracket lines the Meta scripts print, reads the district save time, and lists what stands in his Epic vault cache - the packs he owns already downloaded, which are the next pool the dressing can draw from without any store visit. Every variable carries the p523 prefix.) ==='
foreach ($p523page in @('D:\VEIL-OMNI\folded522.txt', 'D:\VEIL-OMNI\dress522.txt')) {
  if (Test-Path $p523page) {
    Write-Output ('PAGE ' + $p523page + ' at ' + (Get-Item $p523page).LastWriteTime)
    Get-Content $p523page | ForEach-Object { Write-Output ('PG ' + $_) }
  } else {
    Write-Output ('PAGE MISSING ' + $p523page)
  }
}
$p523map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
if (Test-Path $p523map) { Write-Output ('DISTRICT SAVED AT ' + (Get-Item $p523map).LastWriteTime + ' bytes=' + (Get-Item $p523map).Length) }
$p523logs = 'D:\VEIL-OMNI\Saved\Logs'
$p523new = Get-ChildItem $p523logs -Filter '*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($p523new) {
  $p523hits = Select-String -Path $p523new.FullName -Pattern '\[WORLD\]|\[ASSETS\]|\[STORE\]|\[LIGHT\]|\[MATERIAL\]|\[COLLISION\]|\[SPAWN\]' -ErrorAction SilentlyContinue | Select-Object -Last 40
  foreach ($p523h in $p523hits) { Write-Output ('META ' + $p523h.Line) }
  Write-Output ('META LINES=' + ($p523hits | Measure-Object).Count)
}
$p523vault = 'C:\ProgramData\Epic\EpicGamesLauncher\VaultCache'
if (Test-Path $p523vault) {
  $p523packs = Get-ChildItem $p523vault -Directory -ErrorAction SilentlyContinue
  Write-Output ('VAULT PACKS=' + ($p523packs | Measure-Object).Count)
  foreach ($p523pk in $p523packs) { Write-Output ('VAULT ' + $p523pk.Name) }
} else {
  Write-Output 'VAULT CACHE NOT FOUND'
}
Write-Output 'PHI P523 VERDICT: READ BACK PRINTED ABOVE'
Write-Output 'JOB 523 DONE'
```
