<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 671 - MITOCHONDRIAL ENGINE SEATING PATH (Ground: Tyree word build the cell not a cube viewer. Job 670 showed the 668 engine header and source present with refs only inside the engine files themselves. This job finds the seating path: every project source file outside the engine files that names PHI_MitochondrialEngine, plus the VEIL build file dependency lines that seat the Systems module. Read only. No writes to game source, no cook, no package, no editor launch.) ==='
$h671 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_MitochondrialEngine.h'
$c671 = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_MitochondrialEngine.cpp'
$root671 = 'D:\VEIL-OMNI\Source\VEIL'
$hp671 = Test-Path $h671
$cp671 = Test-Path $c671
$rp671 = Test-Path $root671
Write-Output ('MITO671 HEADER PRESENT ' + $hp671)
Write-Output ('MITO671 SOURCE PRESENT ' + $cp671)
Write-Output ('MITO671 ROOT PRESENT ' + $rp671)
if ($rp671) { $refs671 = Get-ChildItem -Path $root671 -Recurse -Include *.cpp,*.h -ErrorAction SilentlyContinue | Select-String -Pattern 'PHI_MitochondrialEngine' | Where-Object { ($_.Path -ne $h671) -and ($_.Path -ne $c671) }; if ($refs671) { $refs671 | ForEach-Object { Write-Output ('MITO671 EXTERNAL REF ' + $_.Path) } } else { Write-Output 'MITO671 NO EXTERNAL REF.' } }
if ($rp671) { $build671 = Get-ChildItem -Path $root671 -Recurse -Filter *.Build.cs -ErrorAction SilentlyContinue; if ($build671) { $build671 | ForEach-Object { Write-Output ('MITO671 BUILD FILE ' + $_.FullName) }; $build671 | Select-String -Pattern 'DependencyModuleNames' | ForEach-Object { Write-Output ('MITO671 BUILD LINE ' + $_.Line.Trim()) } } else { Write-Output 'MITO671 NO BUILD FILE.' } }
Write-Output 'MITO671 NOWRITE.'
Write-Output 'MITO671 NOCOOK.'
Write-Output 'JOB 671 DONE.'
```
