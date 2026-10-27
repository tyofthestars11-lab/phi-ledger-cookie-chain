<!-- PHI-DIRECT -->
# JOB 031 - INSTALL VEIL ON THE PC (DIRECT)

Copies the VEIL Unreal project (committed under veil/VEIL in this repo)
from the vault clone to D:\VEIL, verifies the project file, counts files,
finds the UE 5.8 engine folder, and reports D: free space. Refresh-safe:
robocopy mirrors the source, so re-runs just update the copy.

## STEP 1 - COPY + VERIFY + ENGINE HUNT
```powershell
$src = 'C:\Users\Admin\phi-vault\veil\VEIL'; $dst = 'D:\VEIL'
if (-not (Test-Path $src)) { "SOURCE MISSING: $src - vault clone has not pulled yet" } else {
  robocopy $src $dst /E /NFL /NDL /NJH /NJS | Out-Null
  $files = Get-ChildItem $dst -Recurse -File -ErrorAction SilentlyContinue
  "VEIL INSTALLED: $dst - $($files.Count) files, $([math]::Round(($files | Measure-Object Length -Sum).Sum/1KB,0)) KB"
  "UPROJECT: $(Test-Path "$dst\VEIL.uproject")"
  foreach ($e in 'C:\Program Files\Epic Games\UE_5.8','D:\Epic Games\UE_5.8','D:\UE_5.8') { if (Test-Path $e) { "ENGINE FOUND: $e" } }
  $d = Get-PSDrive D; "D FREE: $([math]::Round($d.Free/1GB,1)) GB"
}
```
