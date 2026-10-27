<!-- PHI-DIRECT -->
# JOB 061 - DRIVE SPACE READ (DIRECT)

Tyree's question (2026-10-27): both games on D, engine on C - best choice,
and does C still have enough space? Read the machine's own numbers: free
and total on C and D, plus the footprints of the engine and the projects.

```powershell
foreach ($letter in @('C','D')) {
  $d = Get-PSDrive $letter -ErrorAction SilentlyContinue
  if ($d) { "DRIVE $letter`: free=$([math]::Round($d.Free/1GB,1)) GB used=$([math]::Round($d.Used/1GB,1)) GB total=$([math]::Round(($d.Free+$d.Used)/1GB,1)) GB" }
}
foreach ($path in @('C:\Program Files\Epic Games','D:\VEIL','D:\OMNI-UE','D:\OMNI-RPG')) {
  if (Test-Path $path) {
    $gb = [math]::Round(((Get-ChildItem $path -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum)/1GB, 2)
    "SIZE $path = $gb GB"
  } else { "SIZE $path = (not present)" }
}
"=== JOB 061 DONE ==="
```
