<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 670 - MITOCHONDRIAL ENGINE INTEGRATION CHECK (Ground: Tyree word build the cell not a cube viewer. This job checks how the 668 mitochondrial engine seats in the VEIL OMNI project, prints every project source file that names PHI_MitochondrialEngine, prints the engine header and source presence and line counts, and prints proof lines. No writes to game source, no cook, no package, no editor launch.) ==='
$h670 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_MitochondrialEngine.h'
$c670 = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_MitochondrialEngine.cpp'
$root670 = 'D:\VEIL-OMNI\Source\VEIL'
$hp670 = Test-Path $h670
$cp670 = Test-Path $c670
$rp670 = Test-Path $root670
Write-Output ('MITO670 HEADER PRESENT ' + $hp670)
Write-Output ('MITO670 SOURCE PRESENT ' + $cp670)
Write-Output ('MITO670 ROOT PRESENT ' + $rp670)
if ($hp670) { $hl670 = (Get-Content $h670).Count; Write-Output ('MITO670 HEADER LINES ' + $hl670) }
if ($cp670) { $cl670 = (Get-Content $c670).Count; Write-Output ('MITO670 SOURCE LINES ' + $cl670) }
if ($rp670) { Get-ChildItem -Path $root670 -Recurse -Include *.cpp,*.h -ErrorAction SilentlyContinue | Select-String -Pattern 'PHI_MitochondrialEngine' | ForEach-Object { Write-Output ('MITO670 REF ' + $_.Path) } }
Write-Output 'MITO670 NOWRITE.'
Write-Output 'MITO670 NOCOOK.'
Write-Output 'JOB 670 DONE.'
```
