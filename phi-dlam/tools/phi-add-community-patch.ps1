# PHI ADD — STARFIELD COMMUNITY PATCH — place, register, prove — phi^2 = phi + 1
$ErrorActionPreference = 'SilentlyContinue'
"=== PHI ADD: STARFIELD COMMUNITY PATCH ==="
$bundled = "$PSScriptRoot\sfcp\Starfield.Community.Patch.0.1.7.zip"
if (Test-Path $bundled) { $zip = Get-Item $bundled; "bundled patch: SFCP 0.1.7 (sha 91ec1ce33a001144)" }
else {
  $zip = Get-ChildItem "$env:USERPROFILE\Downloads" -Filter *.zip | Where-Object { $_.Name -match 'Community|SFCP|Patch' } | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  if (-not $zip) { "no bundled patch beside this script and none in Downloads — standing down"; return }
  "found in Downloads: {0} ({1} MB)" -f $zip.Name, [math]::Round($zip.Length/1MB,1)
}
$cands = @('C:\XboxGames\Starfield\Content', 'C:\XboxGames\Starfield')
$pkg = Get-AppxPackage | Where-Object { $_.Name -match 'Starfield|ProjectGold' } | Select-Object -First 1
if ($pkg) { $cands += $pkg.InstallLocation }
$game = $cands | Where-Object { Test-Path "$_\Starfield.exe" } | Select-Object -First 1
if (-not $game) { "game folder with Starfield.exe not found in the known seats — photo this line to Muse"; return }
"game: $game"
$data = "$game\Data"; New-Item -ItemType Directory -Path $data -Force | Out-Null
$tmp = "$env:TEMP\sfcp"; Remove-Item $tmp -Recurse -Force; Expand-Archive $zip.FullName -DestinationPath $tmp -Force
$files = Get-ChildItem $tmp -Recurse -File | Where-Object { $_.Extension -in '.esm','.ba2','.esp','.esl' }
if (-not $files) { "no plugin files inside the ZIP — photo this line to Muse"; return }
foreach ($f in $files) { Copy-Item $f.FullName -Destination $data -Force; "placed: {0} -> Data" -f $f.Name }
$esm = $files | Where-Object { $_.Name -eq 'StarfieldCommunityPatch.esm' } | Select-Object -First 1
if (-not $esm) { "StarfieldCommunityPatch.esm not among the placed files — photo this line to Muse"; return }
$plugDir = "$env:LOCALAPPDATA\Starfield"; New-Item -ItemType Directory -Path $plugDir -Force | Out-Null
$plug = "$plugDir\plugins.txt"
if (-not (Test-Path $plug)) { Set-Content $plug -Value '# Starfield plugins' -Encoding UTF8 }
$lines = Get-Content $plug
if ($lines[0] -notmatch '^#') { $lines = @('# Starfield plugins') + $lines }
if (-not ($lines -match 'StarfieldCommunityPatch')) { $lines += '*StarfieldCommunityPatch.esm'; "registered in plugins.txt" } else { "already registered — stands" }
Set-Content $plug -Value $lines -Encoding UTF8
"=== PROOF ==="
"esm in Data: {0}" -f (Test-Path "$data\StarfieldCommunityPatch.esm")
"plugins.txt now:"; Get-Content $plug | ForEach-Object { "    $_" }
"=== PATCH ADDED. Launch Starfield normally — the fixes ride the load order. ==="
