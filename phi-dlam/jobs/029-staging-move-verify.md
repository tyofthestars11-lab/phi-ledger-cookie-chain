<!-- PHI-DIRECT -->
# JOB 029 - STAGING MOVE VERIFICATION (DIRECT, read only)

Runs after Tyree moves Starfield's mod staging folder to D: in Vortex
(Settings -> Mods -> Mod Staging Folder). Verifies: staging now lives on
D: (sized), the C: staging folder is drained, Vortex's snapshot carries
the new path, and the D: Data folder count (deployment landing check).

## STEP 1 - STAGING GEOGRAPHY AFTER THE MOVE
```powershell
foreach ($p in "$env:APPDATA\Vortex\starfield\mods", 'D:\Vortex Mods\starfield\mods', 'D:\Vortex Mods\starfield') {
  if (Test-Path $p) { $f = Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue; "STAGING: $p - $($f.Count) files, $([math]::Round(($f | Measure-Object Length -Sum).Sum/1GB,2)) GB" } else { "STAGING ABSENT: $p" }
}
$d = 'D:\XboxGames\Starfield\Content\Data'
"DATA FILES NOW: $((Get-ChildItem $d -File -ErrorAction SilentlyContinue).Count)"
$snap = "$env:APPDATA\Vortex\starfield\snapshots\snapshot.json"
if (Test-Path $snap) { $t = [IO.File]::ReadAllText($snap); "SNAPSHOT MENTIONS D STAGING: $($t -match [regex]::Escape('D:\Vortex Mods')) - MENTIONS C GAME: $($t -match [regex]::Escape('C:\XboxGames')) - MENTIONS D GAME: $($t -match [regex]::Escape('D:\XboxGames'))" }
```
