<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 673 - MITOCHONDRIAL ENGINE SYSTEMS SEAT CLARIFY (Ground: Job 672 printed SYSTEMS FOLDER PRESENT False for Source VEIL Systems, while the 668 engine files sit under Public Systems and Private Systems. This job clarifies the true seat: Public Systems and Private Systems presence, the engine files inside each, the full VEIL.Build.cs dependency arrays, and the uproject Modules array entries. Read only. No writes to game source, no cook, no package, no editor launch.) ==='
$root673 = 'D:\VEIL-OMNI\Source\VEIL'
$pub673 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems'
$priv673 = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems'
$h673 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_MitochondrialEngine.h'
$c673 = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_MitochondrialEngine.cpp'
$build673 = 'D:\VEIL-OMNI\Source\VEIL\VEIL.Build.cs'
Write-Output ('MITO673 PUBLIC SYSTEMS PRESENT ' + (Test-Path $pub673))
Write-Output ('MITO673 PRIVATE SYSTEMS PRESENT ' + (Test-Path $priv673))
Write-Output ('MITO673 HEADER PRESENT ' + (Test-Path $h673))
Write-Output ('MITO673 SOURCE PRESENT ' + (Test-Path $c673))
if (Test-Path $pub673) { Get-ChildItem -Path $pub673 -Filter *.h -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('MITO673 PUBLIC FILE ' + $_.Name) } }
if (Test-Path $priv673) { Get-ChildItem -Path $priv673 -Filter *.cpp -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('MITO673 PRIVATE FILE ' + $_.Name) } }
if (Test-Path $build673) { $bl673 = Get-Content $build673; Write-Output ('MITO673 BUILD LINES ' + $bl673.Count); $bl673 | ForEach-Object { Write-Output ('MITO673 BUILD CONTENT ' + $_.Trim()) } }
$up673 = Get-ChildItem -Path 'D:\VEIL-OMNI' -Filter *.uproject -ErrorAction SilentlyContinue | Select-Object -First 1
if ($up673) { Write-Output ('MITO673 UPROJECT ' + $up673.FullName); Get-Content $up673.FullName | ForEach-Object { Write-Output ('MITO673 UPROJECT CONTENT ' + $_.Trim()) } } else { Write-Output 'MITO673 NO UPROJECT.' }
Write-Output 'MITO673 NOWRITE.'
Write-Output 'MITO673 NOCOOK.'
Write-Output 'JOB 673 DONE.'
```
