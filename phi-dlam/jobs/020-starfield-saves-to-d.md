<!-- PHI-DIRECT -->
# JOB 020 - CODE THE SAVES HOME TO D: (DIRECT - EXECUTES A COPY)

Tyree's word, 2026-10-26: "The game will not load a save file because a save
file does not exist on D." Correct in practice: the D: install reads its own
save home (the package data tied to D:, under D:\WpSystem), and that home is
empty. The cloud-restored save set sits in the OLD C: package home
(AppData\Local\Packages\BethesdaSoftworks.ProjectGold_*\SystemAppData\wgs -
150.3 MB, job 017). This job copies that set, whole and as one consistent
set (index + containers together), into the D: save home.

SAFETY: Block 1 only READS both sides and prints exact paths. Block 2 copies
ONLY IF the source holds files AND the D: target wgs folder is found; if the
target is not found it copies NOTHING and prints the D: package layout so
the next step is exact. Nothing is deleted anywhere. The C: set stays as the
backup.

## STEP 1 - READ BOTH HOMES
```powershell
$src = Get-ChildItem "$env:LOCALAPPDATA\Packages" -Directory -ErrorAction SilentlyContinue | Where-Object Name -match 'ProjectGold' | Select-Object -First 1
if ($src) {
  $sw = Join-Path $src.FullName 'SystemAppData\wgs'
  $sf = Get-ChildItem $sw -Recurse -File -Force -ErrorAction SilentlyContinue
  "SOURCE: $sw - $($sf.Count) files, $([math]::Round(($sf | Measure-Object Length -Sum).Sum/1MB,1)) MB"
} else { "SOURCE PACKAGE NOT FOUND on C:" }
"SEARCHING D: WpSystem for the ProjectGold package home..."
$tgts = Get-ChildItem 'D:\WpSystem' -Recurse -Directory -Force -ErrorAction SilentlyContinue | Where-Object Name -match 'ProjectGold'
if ($tgts) { foreach ($t in $tgts) { "D PACKAGE: $($t.FullName)" } } else { "NO ProjectGold package folder found under D:\WpSystem" }
$tw = $tgts | ForEach-Object { Join-Path $_.FullName 'SystemAppData\wgs' } | Where-Object { Test-Path $_ } | Select-Object -First 1
if ($tw) { $tf = Get-ChildItem $tw -Recurse -File -Force -ErrorAction SilentlyContinue; "TARGET WGS: $tw - $($tf.Count) files, $([math]::Round(($tf | Measure-Object Length -Sum).Sum/1MB,1)) MB" } else { "TARGET WGS FOLDER NOT FOUND on D:" }
```

## STEP 2 - THE COPY (only if both sides are exact)
```powershell
$src = Get-ChildItem "$env:LOCALAPPDATA\Packages" -Directory -ErrorAction SilentlyContinue | Where-Object Name -match 'ProjectGold' | Select-Object -First 1
$sw = if ($src) { Join-Path $src.FullName 'SystemAppData\wgs' } else { $null }
$sf = if ($sw -and (Test-Path $sw)) { Get-ChildItem $sw -Recurse -File -Force -ErrorAction SilentlyContinue } else { @() }
$tgts = Get-ChildItem 'D:\WpSystem' -Recurse -Directory -Force -ErrorAction SilentlyContinue | Where-Object Name -match 'ProjectGold'
$tw = $tgts | ForEach-Object { Join-Path $_.FullName 'SystemAppData\wgs' } | Where-Object { Test-Path $_ } | Select-Object -First 1
if ($sf.Count -gt 0 -and $tw) {
  Copy-Item "$sw\*" -Destination $tw -Recurse -Force -ErrorAction Continue
  $af = Get-ChildItem $tw -Recurse -File -Force -ErrorAction SilentlyContinue
  "COPIED: target now holds $($af.Count) files, $([math]::Round(($af | Measure-Object Length -Sum).Sum/1MB,1)) MB at $tw"
} else {
  "COPY NOT RUN: source files = $($sf.Count); target wgs = $tw"
}
```
