<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WORLD GROUND 489 - THE BUILDERS READ WHOLE (Ground: the Copilot board folded into the bible as the standing production order, 2026-10-28, and Tyree: do what you need to. Phase 1 rides jobs 487 and 488 already in line. This job gathers the whole ground the next tranches author from, in one read: the world builder source and header whole, so the monument and region seats author against the true SpawnBlock shape; the GameMode spawn region, so the agent and giver seats read as placed; every BindStoneBody caller in the source tree; the Warden files and lines wherever they stand; and the exact on-disk object paths for the Murdock, Revenant and Minion bodies and animation blueprints, built mechanically from the file paths so no path is ever typed from a pattern. Read-only: nothing patches, nothing builds, the prints are the product. Every variable carries the wb489 prefix.) ==='
$wb489proj = 'D:\VEIL-OMNI'
$wb489wb = Join-Path $wb489proj 'Source\VEIL\Private\World\VEILWorldBuilder.cpp'
$wb489wbl = @(Get-Content $wb489wb)
Write-Output ('WB LINES=' + $wb489wbl.Count)
for ($wb489i = 0; $wb489i -lt $wb489wbl.Count; $wb489i++) { Write-Output ('WB ' + ($wb489i + 1) + ' ' + $wb489wbl[$wb489i]) }
$wb489wbh = Join-Path $wb489proj 'Source\VEIL\Public\World\VEILWorldBuilder.h'
if (Test-Path $wb489wbh) { $wb489hl = @(Get-Content $wb489wbh); Write-Output ('WBH LINES=' + $wb489hl.Count); for ($wb489i = 0; $wb489i -lt $wb489hl.Count; $wb489i++) { Write-Output ('WBH ' + ($wb489i + 1) + ' ' + $wb489hl[$wb489i]) } } else { Write-Output 'WBH NOT FOUND' }
$wb489gm = Join-Path $wb489proj 'Source\VEIL\Private\Game\VEILGameMode.cpp'
$wb489gml = @(Get-Content $wb489gm)
for ($wb489i = 84; $wb489i -lt 130 -and $wb489i -lt $wb489gml.Count; $wb489i++) { Write-Output ('GM ' + ($wb489i + 1) + ' ' + $wb489gml[$wb489i]) }
Get-ChildItem (Join-Path $wb489proj 'Source\VEIL') -Recurse -Include *.cpp, *.h | Select-String -Pattern 'BindStoneBody' | ForEach-Object { Write-Output ('BIND ' + $_.Filename + ' ' + $_.LineNumber + ' ' + $_.Line.Trim()) }
Get-ChildItem (Join-Path $wb489proj 'Source\VEIL') -Recurse -Include *.cpp, *.h | Where-Object { $_.Name -match 'Warden' } | ForEach-Object { Write-Output ('WARFILE ' + $_.FullName) }
Get-ChildItem (Join-Path $wb489proj 'Source\VEIL') -Recurse -Include *.cpp, *.h | Select-String -Pattern 'Warden' | Select-Object -First 40 | ForEach-Object { Write-Output ('WAR ' + $_.Filename + ' ' + $_.LineNumber + ' ' + $_.Line.Trim()) }
$wb489content = Join-Path $wb489proj 'Content'
$wb489count = 0
foreach ($wb489pack in @('ParagonMurdock', 'ParagonRevenant', 'ParagonMinions')) {
  $wb489root = Join-Path $wb489content $wb489pack
  if (-not (Test-Path $wb489root)) { Write-Output ('ASSET PACK MISSING ' + $wb489pack); continue }
  Get-ChildItem $wb489root -Recurse -Filter *.uasset | Where-Object { $_.FullName -match 'Meshes' -or $_.Name -match 'AnimBlueprint' } | Select-Object -First 60 | ForEach-Object {
    $wb489rel = $_.FullName.Substring($wb489content.Length).Replace('\', '/')
    $wb489obj = '/Game' + $wb489rel.Substring(0, $wb489rel.Length - 7) + '.' + $_.BaseName
    Write-Output ('ASSET ' + $wb489obj + ' bytes=' + $_.Length)
    $wb489count++
  }
}
Write-Output ('PHI WB489 VERDICT: WORLD GROUND wb=1 assets=' + $wb489count)
Write-Output 'JOB 489 DONE'
```
