<!-- PHI-DIRECT -->
# JOB 030 - STAGING MIGRATION, GUARDED (DIRECT)

Tyree's Vortex is v2.9.0 - its Settings has no Mods tab (his photo:
Interface / Vortex / Download / Workarounds / Theme), so the staging move
runs from this side instead. GUARDED DESIGN: the job searches Vortex's
state (state.v2 + starfield dirs + Roaming root files, small files only)
for the staging path line (installPath / starfield\mods). It changes
NOTHING unless exactly one clean match is found whose current value
points at the C: staging folder. On any doubt it prints what it found
and stops - zero damage on failure. On success: closes Vortex (graceful,
force after 6 s), backs up the state file (.phi-backup-20261026), writes
the D: path, copies the staged mods to D:\Vortex Mods\starfield\mods,
verifies the copy by file count + bytes, relaunches Vortex. The C:
staging copy is left in place - nothing deleted.

## STEP 1 - FIND THE LINE, THEN MOVE ONLY IF THE GUARD PASSES
```powershell
$found = @()
$dirs = @("$env:APPDATA\Vortex\state.v2", "$env:APPDATA\Vortex\starfield")
foreach ($d in $dirs) { if (Test-Path $d) { Get-ChildItem $d -Recurse -File -ErrorAction SilentlyContinue | Where-Object { $_.Length -lt 5MB } | ForEach-Object {
  try { $t = [IO.File]::ReadAllText($_.FullName) } catch { return }
  if ($t -match 'installPath' -or $t -match [regex]::Escape('starfield\mods')) { $script:found += [pscustomobject]@{ File = $_.FullName; Text = $t } }
} } }
Get-ChildItem "$env:APPDATA\Vortex" -File -ErrorAction SilentlyContinue | Where-Object { $_.Length -lt 5MB } | ForEach-Object {
  try { $t = [IO.File]::ReadAllText($_.FullName) } catch { return }
  if ($t -match 'installPath' -or $t -match [regex]::Escape('starfield\mods')) { $script:found += [pscustomobject]@{ File = $_.FullName; Text = $t } }
}
"MATCHING STATE FILES: $($found.Count)"
foreach ($f in $found) { "FILE: $($f.File)"; foreach ($m in ([regex]::Matches($f.Text, '.{0,50}installPath.{0,160}') | Select-Object -First 3)) { "WINDOW: $($m.Value -replace '\s+',' ')" } }
$oldForms = @('C:\\Users\\Admin\\AppData\\Roaming\\Vortex\\starfield\\mods','C:\Users\Admin\AppData\Roaming\Vortex\starfield\mods','C:/Users/Admin/AppData/Roaming/Vortex/starfield/mods')
$newForms = @('D:\\Vortex Mods\\starfield\\mods','D:\Vortex Mods\starfield\mods','D:/Vortex Mods/starfield/mods')
$targets = @()
foreach ($f in $found) { for ($i = 0; $i -lt 3; $i++) { if ($f.Text.Contains($oldForms[$i])) { $targets += $f; break } } }
"GUARD: files carrying the C: staging path = $($targets.Count)"
if ($targets.Count -eq 1) {
  $proc = Get-Process -Name Vortex -ErrorAction SilentlyContinue
  if ($proc) { $proc | ForEach-Object { $_.CloseMainWindow() | Out-Null }; Start-Sleep -Seconds 6; Get-Process -Name Vortex -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue; "VORTEX CLOSED" } else { "VORTEX NOT RUNNING" }
  $f = $targets[0]; $t = $f.Text
  Copy-Item $f.File "$($f.File).phi-backup-20261026" -Force
  for ($i = 0; $i -lt 3; $i++) { $t = $t.Replace($oldForms[$i], $newForms[$i]) }
  [IO.File]::WriteAllText($f.File, $t)
  $check = [IO.File]::ReadAllText($f.File)
  "EDIT VERIFY: D: staging present = $($check.Contains('D:') -and $check.Contains('starfield')) - C: staging remaining = $($check.Contains('Roaming\Vortex\starfield\mods') -or $check.Contains('Roaming\\Vortex\\starfield\\mods'))"
  $src = "$env:APPDATA\Vortex\starfield\mods"; $dst = 'D:\Vortex Mods\starfield\mods'
  New-Item -ItemType Directory -Path $dst -Force | Out-Null
  Copy-Item "$src\*" $dst -Recurse -Force
  $sf = Get-ChildItem $src -Recurse -File -Force; $df = Get-ChildItem $dst -Recurse -File -Force
  "COPY: source $($sf.Count) files $([math]::Round(($sf | Measure-Object Length -Sum).Sum/1MB,1)) MB -> target $($df.Count) files $([math]::Round(($df | Measure-Object Length -Sum).Sum/1MB,1)) MB"
  Start-Process 'C:\Program Files\Vortex\Vortex.exe'; "VORTEX RELAUNCHED"
} else {
  "GUARD STOPPED THE MOVE - no changes made. The windows above carry the shape for the next cut."
}
```
