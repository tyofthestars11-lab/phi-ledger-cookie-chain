<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 672 - MITOCHONDRIAL ENGINE MODULE SEAT READ (Ground: Job 671 found no external ref to PHI_MitochondrialEngine and printed the VEIL build file dependency lines. This job reads the full seat: the whole VEIL.Build.cs dependency arrays, the uproject Modules section, and the Source VEIL subfolder list, so the next step knows exactly where the Systems module seats. Read only. No writes to game source, no cook, no package, no editor launch.) ==='
$build672 = 'D:\\VEIL-OMNI\\Source\\VEIL\\VEIL.Build.cs'
$root672 = 'D:\\VEIL-OMNI\\Source\\VEIL'
$proj672 = 'D:\\VEIL-OMNI'
$bp672 = Test-Path $build672
$rp672 = Test-Path $root672
Write-Output ('MITO672 BUILD PRESENT ' + $bp672)
Write-Output ('MITO672 ROOT PRESENT ' + $rp672)
if ($bp672) { $lines672 = Get-Content $build672; Write-Output ('MITO672 BUILD LINES ' + $lines672.Count); $lines672 | Select-String -Pattern 'DependencyModuleNames' | ForEach-Object { Write-Output ('MITO672 BUILD LINE ' + $_.Line.Trim()) } }
if ($rp672) { $dirs672 = Get-ChildItem -Path $root672 -Directory -ErrorAction SilentlyContinue; $dirs672 | ForEach-Object { Write-Output ('MITO672 SUBFOLDER ' + $_.Name) }; $sys672 = Test-Path (Join-Path $root672 'Systems'); Write-Output ('MITO672 SYSTEMS FOLDER PRESENT ' + $sys672) }
$up672 = Get-ChildItem -Path $proj672 -Filter *.uproject -ErrorAction SilentlyContinue | Select-Object -First 1
if ($up672) { Write-Output ('MITO672 UPROJECT ' + $up672.FullName); Get-Content $up672.FullName | Select-String -Pattern 'Modules' | ForEach-Object { Write-Output ('MITO672 UPROJECT LINE ' + $_.Line.Trim()) } } else { Write-Output 'MITO672 NO UPROJECT.' }
Write-Output 'MITO672 NOWRITE.'
Write-Output 'MITO672 NOCOOK.'
Write-Output 'JOB 672 DONE.'
```
