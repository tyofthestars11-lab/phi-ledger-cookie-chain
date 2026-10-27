<!-- PHI-DIRECT -->
# JOB 028 - VORTEX STAGING + DEPLOYMENT METHOD READ (DIRECT, read only)

Context: after the repoint (025) and exclusions (026), Vortex STILL shows
the deployment issue (Tyree, 20:14 MDT). Prime suspect now: HARDLINK
deployment cannot cross volumes. If Vortex's mod staging folder sits on C:
(%APPDATA%\Vortex is 51.1 GB per job 016) while the game sits on D:,
hardlink died the day the game moved - no address fix revives it. This job
reads, nothing else: where staging actually lives (both drives, sized),
and what Vortex's state says for installPath / deploymentMethod.

## STEP 1 - WHERE THE STAGING LIVES
```powershell
$rv = "$env:APPDATA\Vortex"
if (Test-Path $rv) { Get-ChildItem $rv -Directory -ErrorAction SilentlyContinue | ForEach-Object { $s = (Get-ChildItem $_.FullName -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; "ROAMING: $($_.Name) = $([math]::Round($s/1GB,2)) GB" } | Sort-Object }
$sf = "$env:APPDATA\Vortex\starfield"
if (Test-Path $sf) { Get-ChildItem $sf -Directory -ErrorAction SilentlyContinue | ForEach-Object { $s = (Get-ChildItem $_.FullName -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; "STARFIELD-DIR: $($_.Name) = $([math]::Round($s/1GB,2)) GB" } }
if (Test-Path 'D:\Vortex Mods') { Get-ChildItem 'D:\Vortex Mods' -Directory -ErrorAction SilentlyContinue | ForEach-Object { $s = (Get-ChildItem $_.FullName -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; "D-STAGING: $($_.Name) = $([math]::Round($s/1GB,2)) GB" } }
```

## STEP 2 - WHAT VORTEX'S STATE SAYS (installPath / deploymentMethod windows)
```powershell
$root = "$env:APPDATA\Vortex"
$files = Get-ChildItem $root -Recurse -File -ErrorAction SilentlyContinue | Where-Object { ($_.Extension -in '.json','.txt','.vortex','') -and $_.Length -lt 20MB }
foreach ($f in $files) {
  try { $t = [IO.File]::ReadAllText($f.FullName) } catch { continue }
  foreach ($k in 'deploymentMethod','installPath') {
    $ms = [regex]::Matches($t, ".{0,60}$k.{0,140}")
    foreach ($m in ($ms | Select-Object -First 4)) { "STATE [$($f.Name)] $k :: $($m.Value -replace '\s+',' ')" }
  }
}
```
