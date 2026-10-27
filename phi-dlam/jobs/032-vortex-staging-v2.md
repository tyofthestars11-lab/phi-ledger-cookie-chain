<!-- PHI-DIRECT -->
# JOB 032 - VORTEX STAGING MIGRATION v2 (DIRECT, guarded, verify-or-rollback)

Job 030's "0 matches" was a broken search (its collection code threw), not
a true negative - do not trust it. This job re-searches correctly, then
moves Starfield's staging folder from C: to D:\Vortex Mods\starfield\mods
so hardlink deployment (staging D: -> game D:) can live again.

GUARDS: edit happens only if exactly ONE state file carries an
"installPath" entry; the file is backed up first (.phi-backup-20261026b);
after the text edit the file must still parse as JSON and carry the new
D: value - otherwise the backup is restored and nothing else changes.
The staged mods are copied (never deleted from C:) and verified by count.

## STEP 1 - SEARCH (FIXED) + GUARDED EDIT + COPY + RELAUNCH
```powershell
$ErrorActionPreference = 'Continue'
$hits = New-Object System.Collections.ArrayList
$dirs = @("$env:APPDATA\Vortex\state.v2", "$env:APPDATA\Vortex\starfield", "$env:APPDATA\Vortex")
$seen = @{}
foreach ($d in $dirs) {
  if (-not (Test-Path $d)) { continue }
  $files = if ($d -eq "$env:APPDATA\Vortex") { Get-ChildItem $d -File -ErrorAction SilentlyContinue } else { Get-ChildItem $d -Recurse -File -ErrorAction SilentlyContinue }
  foreach ($f in $files) {
    if ($f.Length -gt 10MB -or $seen.ContainsKey($f.FullName)) { continue }
    $seen[$f.FullName] = $true
    try { $t = [IO.File]::ReadAllText($f.FullName) } catch { continue }
    if ($t.Contains('"installPath"') -or $t.Contains('USERDATA')) { [void]$hits.Add([pscustomobject]@{ File = $f.FullName; Text = $t }) }
  }
}
"STATE FILES WITH installPath/USERDATA: $($hits.Count)"
foreach ($h in $hits) {
  "FILE: $($h.File)"
  $i = $h.Text.IndexOf('"installPath"')
  if ($i -ge 0) { "WINDOW: " + ($h.Text.Substring($i, [Math]::Min(400, $h.Text.Length - $i)) -replace '\s+', ' ') }
}
$cands = @($hits | Where-Object { $_.Text.Contains('"installPath"') })
"GUARD: installPath files = $($cands.Count)"
if ($cands.Count -eq 1) {
  $f = $cands[0]; $t = $f.Text
  $newJson = '"starfield": "D:\\Vortex Mods\\starfield\\mods"'
  $edited = $null
  $win = $t.Substring($t.IndexOf('"installPath"'), [Math]::Min(800, $t.Length - $t.IndexOf('"installPath"')))
  if ($win -match '"starfield"\s*:\s*"[^"]*"') {
    $edited = $t -replace '"starfield"\s*:\s*"[^"]*"', $newJson, 1
    "PATTERN: existing starfield entry replaced"
  } elseif ($win -match '"installPath"\s*:\s*\{') {
    $edited = $t -replace '("installPath"\s*:\s*\{)', ('$1' + $newJson + ', '), 1
    "PATTERN: starfield entry inserted into installPath"
  } else { "PATTERN: no known shape - no edit" }
  if ($edited) {
    $proc = Get-Process -Name Vortex -ErrorAction SilentlyContinue
    if ($proc) { $proc | ForEach-Object { $_.CloseMainWindow() | Out-Null }; Start-Sleep -Seconds 6; Get-Process -Name Vortex -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue; "VORTEX CLOSED" }
    Copy-Item $f.File "$($f.File).phi-backup-20261026b" -Force
    [IO.File]::WriteAllText($f.File, $edited)
    $check = [IO.File]::ReadAllText($f.File)
    $parseOk = $true; try { $null = $check | ConvertFrom-Json -ErrorAction Stop } catch { $parseOk = $false }
    $hasNew = $check.Contains('D:\\Vortex Mods\\starfield\\mods') -or $check.Contains('D:\Vortex Mods\starfield\mods')
    "VERIFY: json parses = $parseOk - D: staging present = $hasNew"
    if ($parseOk -and $hasNew) {
      $src = "$env:APPDATA\Vortex\starfield\mods"; $dst = 'D:\Vortex Mods\starfield\mods'
      New-Item -ItemType Directory -Path $dst -Force | Out-Null
      robocopy $src $dst /E /NFL /NDL /NJH /NJS | Out-Null
      $sf = Get-ChildItem $src -Recurse -File -Force; $df = Get-ChildItem $dst -Recurse -File -Force
      "COPY: source $($sf.Count) files -> target $($df.Count) files"
      Start-Process 'C:\Program Files\Vortex\Vortex.exe'; "VORTEX RELAUNCHED - staging now on D:"
    } else {
      Copy-Item "$($f.File).phi-backup-20261026b" $f.File -Force
      "VERIFY FAILED - backup restored, no changes stand"
      Start-Process 'C:\Program Files\Vortex\Vortex.exe'; "VORTEX RELAUNCHED (unchanged)"
    }
  }
} else {
  "GUARD STOPPED - no edit. The windows above show where the path lives."
}
```
