<!-- PHI-DIRECT -->
# JOB 040 - VORTEX STARFIELD GAME RECORD DUMP (DIRECT, read only)

Tyree's report: Vortex will not let him un-manage Starfield or purge its
mods - it cites a setup problem. The block lives in Vortex's stored
Starfield game record. This job dumps every trace of that record: it
searches state.v2, the starfield folders, and the Roaming root state
files for starfield / ProjectGold / BethesdaSoftworks and prints the
surrounding text whole (wide windows), plus lists the state.v2 files
with sizes. Read only - the repair or the state-side purge authors
itself from this record, never from a guess.

## STEP 1 - DUMP THE GAME RECORD
```powershell
$roots = @("$env:APPDATA\Vortex\state.v2", "$env:APPDATA\Vortex\starfield", "$env:APPDATA\Vortex")
"STATE.V2 FILES:"
Get-ChildItem "$env:APPDATA\Vortex\state.v2" -File -ErrorAction SilentlyContinue | ForEach-Object { "$($_.Name) - $($_.Length) bytes" }
$seen = @{}
foreach ($r in $roots) {
  if (-not (Test-Path $r)) { continue }
  $files = if ($r -eq "$env:APPDATA\Vortex") { Get-ChildItem $r -File -ErrorAction SilentlyContinue } else { Get-ChildItem $r -Recurse -File -ErrorAction SilentlyContinue }
  foreach ($f in $files) {
    if ($f.Length -gt 20MB -or $seen.ContainsKey($f.FullName) -or $f.Name -like '*.log') { continue }
    $seen[$f.FullName] = $true
    try { $t = [IO.File]::ReadAllText($f.FullName) } catch { continue }
    foreach ($k in 'ProjectGold','starfield') {
      $i = $t.IndexOf($k)
      if ($i -ge 0) {
        "== $($f.FullName) @ $k"
        $start = [Math]::Max(0, $i - 200); $len = [Math]::Min(1400, $t.Length - $start)
        ($t.Substring($start, $len) -replace '\s+', ' ')
      }
    }
  }
}
```
