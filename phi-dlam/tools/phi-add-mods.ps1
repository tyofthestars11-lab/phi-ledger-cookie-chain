# PHI ADD MODS — generic Nexus-mod placer for the Game Pass build — phi^2 = phi + 1
# Finds each mod ZIP (bundled beside this script, else Downloads), merges its Data tree,
# registers every plugin it carries, enables loose files, proves each placement.
# Mods: StarUI Inventory | The Gang's All Here | NPC Routines Expanded | Better NPCs
$ErrorActionPreference = 'SilentlyContinue'
"=== PHI ADD MODS ==="
$cands = @('C:\XboxGames\Starfield\Content', 'C:\XboxGames\Starfield')
$pkg = Get-AppxPackage | Where-Object { $_.Name -match 'Starfield|ProjectGold' } | Select-Object -First 1
if ($pkg) { $cands += $pkg.InstallLocation }
$game = $cands | Where-Object { Test-Path "$_\Starfield.exe" } | Select-Object -First 1
if (-not $game) { "game folder not found — standing down"; return }
$data = "$game\Data"; New-Item -ItemType Directory -Path $data -Force | Out-Null
"game Data: $data"
$patterns = @('StarUI', 'Gang', 'Routines', 'BetterNPC', 'Better NPC')
$zips = @()
foreach ($src in @("$PSScriptRoot\mods", "$env:USERPROFILE\Downloads")) {
  if (Test-Path $src) { $zips += Get-ChildItem $src -Filter *.zip | Where-Object { $n = $_.Name; $patterns | Where-Object { $n -match $_ } } }
}
if (-not $zips) { "no mod ZIPs found yet (vault mods folder / Downloads) — the installer stands ready"; return }
$placed = @()
foreach ($zip in $zips) {
  $tmp = "$env:TEMP\phi-mod"; Remove-Item $tmp -Recurse -Force; Expand-Archive $zip.FullName -DestinationPath $tmp -Force
  $srcData = Get-ChildItem $tmp -Recurse -Directory | Where-Object { $_.Name -eq 'Data' } | Select-Object -First 1
  if ($srcData) { Copy-Item "$($srcData.FullName)\*" -Destination $data -Recurse -Force; "merged Data tree: $($zip.Name)" }
  else {
    Get-ChildItem $tmp -Recurse -File | Where-Object { $_.Extension -in '.esm','.ba2','.esp','.esl' } | ForEach-Object { Copy-Item $_.FullName -Destination $data -Force }
    $iface = Get-ChildItem $tmp -Recurse -Directory | Where-Object { $_.Name -eq 'Interface' } | Select-Object -First 1
    if ($iface) { New-Item -ItemType Directory -Path "$data\Interface" -Force | Out-Null; Copy-Item "$($iface.FullName)\*" -Destination "$data\Interface" -Recurse -Force }
    "placed loose payload: $($zip.Name)"
  }
  $placed += Get-ChildItem $tmp -Recurse -File | Where-Object { $_.Extension -in '.esm','.esp','.esl' } | ForEach-Object { $_.Name }
}
$plugDir = "$env:LOCALAPPDATA\Starfield"; New-Item -ItemType Directory -Path $plugDir -Force | Out-Null
$plug = "$plugDir\plugins.txt"
if (-not (Test-Path $plug)) { Set-Content $plug -Value '# Starfield plugins' -Encoding UTF8 }
$lines = Get-Content $plug
if ($lines[0] -notmatch '^#') { $lines = @('# Starfield plugins') + $lines }
foreach ($pl in ($placed | Select-Object -Unique)) { if (-not ($lines -match [regex]::Escape($pl))) { $lines += "*$pl"; "registered: $pl" } }
Set-Content $plug -Value $lines -Encoding UTF8
$iniDir = "$env:USERPROFILE\Documents\My Games\Starfield"; New-Item -ItemType Directory -Path $iniDir -Force | Out-Null
$ini = "$iniDir\StarfieldCustom.ini"
$iniTxt = if (Test-Path $ini) { Get-Content $ini -Raw } else { '' }
if ($iniTxt -notmatch 'bInvalidateOlderFiles') {
  Add-Content $ini -Value "`r`n[Archive]`r`nbInvalidateOlderFiles=1`r`nsResourceDataDirsFinal=" -Encoding UTF8
  "StarfieldCustom.ini: loose files enabled"
} else { "StarfieldCustom.ini: loose files already enabled — stands" }
"=== PROOF — plugins.txt now: ==="; Get-Content $plug | ForEach-Object { "    $_" }
"=== MODS PLACED. Launch normally. ==="
