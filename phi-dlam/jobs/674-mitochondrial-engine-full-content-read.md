<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 674 - MITOCHONDRIAL ENGINE FULL CONTENT READ (Ground: Job 673 clarified Public Systems and Private Systems present True with the 668 engine header and source present True. This job reads the full engine header and source content line by line, prints line counts and every content line, and prints the ledger value lines found in the source. Read only. No writes to game source, no cook, no package, no editor launch.) ==='
$h674 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_MitochondrialEngine.h'
$c674 = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_MitochondrialEngine.cpp'
$hp674 = Test-Path $h674
$cp674 = Test-Path $c674
Write-Output ('MITO674 HEADER PRESENT ' + $hp674)
Write-Output ('MITO674 SOURCE PRESENT ' + $cp674)
if ($hp674) { $hl674 = Get-Content $h674; Write-Output ('MITO674 HEADER LINES ' + $hl674.Count); $hl674 | ForEach-Object { Write-Output ('MITO674 HEADER CONTENT ' + $_.Trim()) } }
if ($cp674) { $cl674 = Get-Content $c674; Write-Output ('MITO674 SOURCE LINES ' + $cl674.Count); $cl674 | ForEach-Object { Write-Output ('MITO674 SOURCE CONTENT ' + $_.Trim()) } }
if ($cp674) { Get-Content $c674 | Select-String -Pattern 'NDnaLedger|GoldenPitch|EquilibriumRung|EchoGap|CoherenceDissolve' | ForEach-Object { Write-Output ('MITO674 LEDGER ' + $_.Line.Trim()) } }
Write-Output 'MITO674 NOWRITE.'
Write-Output 'MITO674 NOCOOK.'
Write-Output 'JOB 674 DONE.'
```
