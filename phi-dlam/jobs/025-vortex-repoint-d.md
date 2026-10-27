<!-- PHI-DIRECT -->
# JOB 025 - REPOINT VORTEX AT D: (DIRECT)

Tyree's photo, 2026-10-26 19:56 MDT: Vortex error - tried to access
"C:\XboxGames\Starfield\Content\Data" - ENOENT, it doesn't exist.
Tyree: "Make this please." This is the stale-aim trap named at 18:46:
Vortex still points at the dead C: shell (0.1 GB) while the game lives at
D:\XboxGames\Starfield. This job closes Vortex, rewrites its saved
Starfield address from C: to D: in its own state files (every edited file
backed up first as .phi-backup-20261026), verifies the old address is
gone, and relaunches Vortex aimed at the real install.

## STEP 1 - THE TRUTH OF BOTH ADDRESSES
```powershell
$d = 'D:\XboxGames\Starfield\Content\Data'
$c = 'C:\XboxGames\Starfield\Content\Data'
"D DATA EXISTS: $(Test-Path $d) - files: $((Get-ChildItem $d -File -ErrorAction SilentlyContinue).Count)"
"C DATA EXISTS: $(Test-Path $c)"
"VORTEX RUNNING: $([bool](Get-Process Vortex -ErrorAction SilentlyContinue))"
```

## STEP 2 - CLOSE VORTEX (graceful first)
```powershell
$p = Get-Process Vortex -ErrorAction SilentlyContinue
if ($p) { $p | ForEach-Object { $_.CloseMainWindow() | Out-Null }; "CLOSE SENT"; Start-Sleep -Seconds 6 }
$p2 = Get-Process Vortex -ErrorAction SilentlyContinue
if ($p2) { $p2 | Stop-Process -Force; "VORTEX FORCE-CLOSED (it was stuck on the error dialog)" } else { "VORTEX CLOSED" }
```

## STEP 3 - REPOINT THE ADDRESS (backups first, then verify)
```powershell
$root = "$env:APPDATA\Vortex"
$pairs = @(@('C:\\XboxGames\\Starfield','D:\\XboxGames\\Starfield'), @('C:\XboxGames\Starfield','D:\XboxGames\Starfield'), @('C:/XboxGames/Starfield','D:/XboxGames/Starfield'))
$files = Get-ChildItem $root -Recurse -File -ErrorAction SilentlyContinue | Where-Object { ($_.Extension -in '.json','.txt','.vortex','') -and $_.Length -lt 20MB }
foreach ($f in $files) {
  try { $t = [IO.File]::ReadAllText($f.FullName) } catch { continue }
  $n = 0; foreach ($pr in $pairs) { $n += ([regex]::Matches($t, [regex]::Escape($pr[0]))).Count }
  if ($n -gt 0) {
    Copy-Item $f.FullName "$($f.FullName).phi-backup-20261026" -Force
    foreach ($pr in $pairs) { $t = $t.Replace($pr[0], $pr[1]) }
    [IO.File]::WriteAllText($f.FullName, $t)
    "REPOINTED: $($f.FullName) - $n address(es) C: -> D: (backup kept)"
  }
}
$left = 0; foreach ($f in $files) { try { $t = [IO.File]::ReadAllText($f.FullName); foreach ($pr in $pairs) { $left += ([regex]::Matches($t, [regex]::Escape($pr[0]))).Count } } catch {} }
"C: ADDRESSES REMAINING IN VORTEX STATE: $left"
```

## STEP 4 - RELAUNCH VORTEX ON THE NEW AIM
```powershell
$exe = 'C:\Program Files\Vortex\Vortex.exe'
if (Test-Path $exe) { Start-Process $exe; "VORTEX RELAUNCHED" } else { "VORTEX EXE NOT AT $exe - relaunch skipped" }
```
