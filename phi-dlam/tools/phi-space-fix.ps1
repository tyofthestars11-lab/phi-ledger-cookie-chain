# PHI SPACE FIX — Tyree's C: drive, games ranked by size. Report only, deletes NOTHING.
$ErrorActionPreference = 'SilentlyContinue'
function SizeGB($p) { [math]::Round(((Get-ChildItem $p -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum / 1GB), 1) }
$d = Get-PSDrive C
"=== C:  FREE {0} GB  /  USED {1} GB  /  TOTAL {2} GB ===" -f [math]::Round($d.Free/1GB,1), [math]::Round($d.Used/1GB,1), [math]::Round(($d.Free+$d.Used)/1GB,1)
"=== After Starfield (155 GB) moves in: {0} GB free ===" -f [math]::Round($d.Free/1GB - 155, 1)
"--- GAMES (biggest first) ---"
$roots = @(
  'C:\Program Files (x86)\Ubisoft\Ubisoft Game Launcher\games',
  'C:\Program Files\Ubisoft\Ubisoft Game Launcher\games',
  'C:\Program Files\Epic Games',
  'C:\Program Files (x86)\Steam\steamapps\common',
  'C:\XboxGames', 'C:\Games',
  'C:\Program Files\Riot Games',
  'C:\Program Files (x86)\Battle.net',
  'C:\Program Files\EA Games',
  'C:\Program Files (x86)\Origin Games',
  'C:\Program Files\GOG Galaxy\Games'
)
$found = @()
foreach ($r in $roots) {
  if (Test-Path $r) {
    Get-ChildItem $r -Directory | ForEach-Object { $found += [pscustomobject]@{ Game = $_.Name; GB = SizeGB $_.FullName; Path = $_.FullName } }
  }
}
$found | Sort-Object GB -Descending | Format-Table Game, GB -AutoSize
"--- BIGGEST SINGLE FOLDERS (Program Files) ---"
$pf = @()
foreach ($base in @('C:\Program Files', 'C:\Program Files (x86)')) {
  Get-ChildItem $base -Directory | ForEach-Object { $pf += [pscustomobject]@{ Folder = $_.FullName; GB = SizeGB $_.FullName } }
}
$pf | Sort-Object GB -Descending | Select-Object -First 10 | Format-Table Folder, GB -AutoSize
"=== DONE. Nothing was deleted. ==="
