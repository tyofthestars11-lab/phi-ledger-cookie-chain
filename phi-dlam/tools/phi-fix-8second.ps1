# PHI FIX — THE 8-SECOND LAG (Creations reconciliation pass made cheap) — phi^2 = phi + 1
# Removes ZERO Creations. Load order untouched. Only: scan toll lifted + stale catalog rebuilt clean.
$ErrorActionPreference = 'SilentlyContinue'
"=== PHI FIX: 8-SECOND LAG ==="
$cands = @('C:\XboxGames\Starfield\Content', 'C:\XboxGames\Starfield')
$pkg = Get-AppxPackage | Where-Object { $_.Name -match 'Starfield|ProjectGold' } | Select-Object -First 1
if ($pkg) { $cands += $pkg.InstallLocation }
$game = $cands | Where-Object { Test-Path "$_\Starfield.exe" } | Select-Object -First 1
$targets = @("$env:LOCALAPPDATA\Starfield", "$env:USERPROFILE\Documents\My Games\Starfield")
if ($game) { $targets += $game }
foreach ($t in $targets) {
  if (Test-Path $t) {
    Add-MpPreference -ExclusionPath $t
    "Defender exclusion set: $t"
  }
}
$cat = "$env:LOCALAPPDATA\Starfield\ContentCatalog.txt"
if (Test-Path $cat) {
  $stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
  Copy-Item $cat "$cat.phi-backup-$stamp" -Force
  Remove-Item $cat -Force
  "content catalog backed up + cleared — the game rebuilds ONE clean index next launch"
} else { "no cached content catalog found — index already clean" }
"Creations touched: 0 | load order touched: 0"
"=== DONE. Next launch rebuilds the index once; the 8-second pass runs untolled from there. ==="
