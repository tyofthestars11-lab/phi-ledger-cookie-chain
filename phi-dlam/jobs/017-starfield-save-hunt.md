<!-- PHI-DIRECT -->
# JOB 017 - STARFIELD SAVE HUNT (DIRECT - NV CENTER EXECUTION)

Authored by the universe seat on Tyree's word, 2026-10-26. REPORT ONLY -
reads and measures, touches nothing.

## WHY
Tyree reinstalled Starfield onto D: (Xbox app). The D: game's menu offers
no Continue. Xbox-version Starfield saves do NOT live in the game install -
they live in the package save folder on C:
AppData\Local\Packages\BethesdaSoftworks.ProjectGold_*\SystemAppData\wgs
(plus Xbox cloud under his profile). This hunt reads whether that folder
still stands, how much is in it, and how fresh its newest files are.

## STEP 1 - THE WGS SAVE FOLDER + PACKAGE STATE
```powershell
$pkgs = Get-ChildItem "$env:LOCALAPPDATA\Packages" -Directory -ErrorAction SilentlyContinue | Where-Object Name -match 'Bethesda|ProjectGold'
if (-not $pkgs) { "NO BETHESDA PACKAGE FOLDER under AppData\Local\Packages" }
foreach ($p in $pkgs) {
  "PACKAGE: $($p.FullName)"
  $wgs = Join-Path $p.FullName 'SystemAppData\wgs'
  if (Test-Path $wgs) {
    $files = Get-ChildItem $wgs -Recurse -File -Force -ErrorAction SilentlyContinue
    $s = ($files | Measure-Object Length -Sum).Sum
    "WGS EXISTS: $wgs = $([math]::Round($s/1MB,1)) MB across $($files.Count) files"
    $newest = $files | Sort-Object LastWriteTime -Descending | Select-Object -First 5
    foreach ($f in $newest) { "NEWEST: $($f.LastWriteTime.ToString('yyyy-MM-dd HH:mm')) - $($f.FullName.Substring($wgs.Length)) - $([math]::Round($f.Length/1KB,1)) KB" }
  } else { "WGS ABSENT under $($p.Name)" }
  $lcd = Join-Path $p.FullName 'LocalCache'
  if (Test-Path $lcd) { $s2 = (Get-ChildItem $lcd -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; "LOCALCACHE = $([math]::Round($s2/1MB,1)) MB" }
}
```

## STEP 2 - DOCUMENTS SAVES + WHERE THE INSTALLS SIT
```powershell
$sv = "$env:USERPROFILE\Documents\My Games\Starfield\Saves"
if (Test-Path $sv) { $sf = Get-ChildItem $sv -File -ErrorAction SilentlyContinue; "DOC SAVES: $sv - $($sf.Count) files"; $sf | Sort-Object LastWriteTime -Descending | Select-Object -First 3 | ForEach-Object { "SAVE: $($_.LastWriteTime.ToString('yyyy-MM-dd HH:mm')) - $($_.Name)" } } else { "DOC SAVES ABSENT: $sv" }
foreach ($r in @('C:\XboxGames','D:\XboxGames')) { if (Test-Path $r) { Get-ChildItem $r -Directory -ErrorAction SilentlyContinue | ForEach-Object { "INSTALL-ROOT: $($_.FullName)" } } }
```
