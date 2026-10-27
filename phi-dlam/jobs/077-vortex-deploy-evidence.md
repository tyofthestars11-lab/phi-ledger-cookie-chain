<!-- PHI-DIRECT -->
# JOB 077 - VORTEX ROOT CAUSE: THE C: GHOST PATH (DIRECT)

Tyree's screenshots settled the shape (2026-10-27 09:40 MDT): Vortex
2.9.1's own dialogs name the output directory as
"C:\XboxGames\Starfield\Content\Data" - C:. His real Starfield is the
D: install (129.37 GB, D:\XboxGames\Starfield). Every deployment
method (Hardlink, Move, Symlink, Null) fails on the same wrong door:
"Can't write to output directory." Reinstalling Vortex changed
nothing because the state in AppData survived the uninstall. Fallout
and New Vegas work because their managed paths are right.

This job proves the two paths side by side, scans the real D: Data
folder for residue of the wrong-version unofficial patch he
downloaded, reads Vortex's stored game path from its state, and backs
the state up before ANY fix touches it. Read-only except the backup.

```powershell
"=== C: GHOST PATH ==="
foreach ($g in 'C:\XboxGames\Starfield\Content\Data', 'C:\XboxGames\Starfield', 'C:\XboxGames') {
  if (Test-Path $g) { "EXISTS: $g"; Get-ChildItem $g -ErrorAction SilentlyContinue | Select-Object -First 8 | ForEach-Object { "  $($_.Name)" } }
  else { "ABSENT: $g" }
}
"=== D: REAL INSTALL ==="
$d = 'D:\XboxGames\Starfield\Content\Data'
if (Test-Path $d) {
  "EXISTS: $d"
  $probe = Join-Path $d 'phi-write-probe.tmp'
  try { New-Item $probe -ItemType File -Force -ErrorAction Stop | Out-Null; Remove-Item $probe -Force; "D DATA WRITABLE: yes" }
  catch { "D DATA WRITABLE: NO - $($_.Exception.Message.Substring(0, [Math]::Min(120, $_.Exception.Message.Length)))" }
  "--- PLUGIN / ARCHIVE FILES IN D DATA (patch residue scan) ---"
  Get-ChildItem $d -Include '*.esm','*.esp','*.esl' -File -ErrorAction SilentlyContinue | ForEach-Object { $_.Name }
  Get-ChildItem $d -Filter '*.ini' -File -ErrorAction SilentlyContinue | ForEach-Object { $_.Name }
  $cust = Join-Path $d 'StarfieldCustom.ini'
  if (Test-Path $cust) { "--- StarfieldCustom.ini ---"; Get-Content $cust }
} else { "ABSENT: $d" }
$docs = "$env:USERPROFILE\Documents\My Games\Starfield\Data"
if (Test-Path $docs) { "DOCS DATA EXISTS: $docs"; Get-ChildItem $docs -ErrorAction SilentlyContinue | Select-Object -First 10 | ForEach-Object { "  $($_.Name)" } }
"=== VORTEX STATE: STORED XBOXGAMES PATHS ==="
$vx = "$env:APPDATA\Vortex"
Get-ChildItem $vx -Recurse -Include '*.ldb' -ErrorAction SilentlyContinue | Select-Object -First 10 | ForEach-Object {
  Select-String -Path $_.FullName -Pattern 'XboxGames' -AllMatches -ErrorAction SilentlyContinue | Select-Object -First 2 | ForEach-Object {
    $line = $_.Line; $i = $line.IndexOf('XboxGames'); if ($i -gt 0) { $line.Substring([Math]::Max(0,$i-40), [Math]::Min(140, $line.Length-[Math]::Max(0,$i-40))) }
  }
}
"=== STATE BACKUP (before any fix) ==="
$bk = 'C:\Users\Admin\phi-vault-backups\vortex-state-2026-10-27-pre-path-fix'
New-Item -ItemType Directory -Path $bk -Force | Out-Null
robocopy $vx $bk /E /NFL /NDL /NJH | Out-Null
"BACKED UP: $bk"
"=== JOB 077 DONE ==="
```
