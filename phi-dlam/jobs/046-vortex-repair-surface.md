<!-- PHI-DIRECT -->
# JOB 046 - VORTEX REPAIR SURFACE MAP (DIRECT, read only + one preserved copy)

Tyree's word: fix Vortex. Its state is a LevelDB store (job 040) whose
Starfield record carries the setup problem - GUI can't repair it, text
can't read it. Before any fix touches the live store, this job maps the
repair surface:
1. Vortex's own state backups (temp\state_backups_full and kin) - names,
   dates, sizes. A pre-break backup is the vendor-sanctioned restore.
2. Database readers available on this PC: python / node on PATH, and
   what Vortex's own install carries under resources (its bundled
   level engine is the natural reader for its own store).
3. A PRESERVED COPY of the live store at
   C:\Users\Admin\phi-vault-backups\state-v2-live-2026-10-26 (copied,
   never moved) - the fix gets rehearsed on the copy first.

## STEP 1 - MAP BACKUPS + READERS + PRESERVE THE STORE
```powershell
"STATE BACKUPS:"
foreach ($d in "$env:APPDATA\Vortex\temp\state_backups_full", "$env:APPDATA\Vortex\temp") {
  if (Test-Path $d) { Get-ChildItem $d -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 12 | ForEach-Object { "$($_.Name) - $($_.LastWriteTime) - $([math]::Round($_.Length/1KB,1)) KB" } }
}
"READERS:"
foreach ($c in 'python.exe','py.exe','node.exe') { $w = where.exe $c 2>$null; if ($w) { "$c -> $w" } else { "$c -> absent" } }
"VORTEX RESOURCES:"
Get-ChildItem 'C:\Program Files\Vortex\resources' -ErrorAction SilentlyContinue | ForEach-Object { $_.Name }
"PRESERVE COPY:"
$dst = 'C:\Users\Admin\phi-vault-backups\state-v2-live-2026-10-26'
robocopy "$env:APPDATA\Vortex\state.v2" $dst /E /NFL /NDL /NJH /NJS | Out-Null
"COPY FILES: $((Get-ChildItem $dst -Recurse -File -ErrorAction SilentlyContinue).Count)"
```
