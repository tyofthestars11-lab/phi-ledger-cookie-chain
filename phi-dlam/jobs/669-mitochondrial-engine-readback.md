<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 669 - MITOCHONDRIAL ENGINE READBACK (Ground: Tyree word build the cell not a cube viewer. This job reads back the 668 mitochondrial engine header and source, prints presence and line counts and the ledger value lines found in the source, and prints proof lines. No writes to game source, no cook, no package, no editor launch.) ==='
$h669 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_MitochondrialEngine.h'
$c669 = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_MitochondrialEngine.cpp'
$hp669 = Test-Path $h669
$cp669 = Test-Path $c669
Write-Output ('MITO669 HEADER PRESENT ' + $hp669)
Write-Output ('MITO669 SOURCE PRESENT ' + $cp669)
if ($hp669) { $hl669 = (Get-Content $h669).Count; Write-Output ('MITO669 HEADER LINES ' + $hl669) }
if ($cp669) { $cl669 = (Get-Content $c669).Count; Write-Output ('MITO669 SOURCE LINES ' + $cl669) }
if ($cp669) { Get-Content $c669 | Select-String -Pattern 'NDnaLedger|GoldenPitch|EquilibriumRung|EchoGap|CoherenceDissolve' | ForEach-Object { Write-Output ('MITO669 READ ' + $_.Line) } }
Write-Output 'MITO669 NOWRITE.'
Write-Output 'MITO669 NOCOOK.'
Write-Output 'JOB 669 DONE.'
```
