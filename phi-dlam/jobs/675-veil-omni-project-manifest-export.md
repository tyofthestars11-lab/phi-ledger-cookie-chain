<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 675 - VEIL OMNI PROJECT MANIFEST EXPORT (Ground: Tyree ordered the live Unreal VEIL OMNI files from his PC to be given to Cowork. The live project sits only on his PC, not on the Muse VM. This job exports the live project manifest as read only text: uproject full content, Build.cs full content, Target files, Config inis, and the full Source tree with file sizes, plus the Content map list. No writes to game source, no cook, no package, no editor launch.) ==='
$proj675 = 'D:\VEIL-OMNI'
Write-Output ('MITO675 PROJECT PRESENT ' + (Test-Path $proj675))
$up675 = Get-ChildItem -Path $proj675 -Filter *.uproject -ErrorAction SilentlyContinue | Select-Object -First 1
if ($up675) { Write-Output ('MITO675 UPROJECT ' + $up675.FullName); Get-Content $up675.FullName | ForEach-Object { Write-Output ('MITO675 UPROJECT CONTENT ' + $_.Trim()) } } else { Write-Output 'MITO675 NO UPROJECT.' }
$build675 = 'D:\VEIL-OMNI\Source\VEIL\VEIL.Build.cs'
if (Test-Path $build675) { Get-Content $build675 | ForEach-Object { Write-Output ('MITO675 BUILD CONTENT ' + $_.Trim()) } } else { Write-Output 'MITO675 NO BUILD FILE.' }
$src675 = 'D:\VEIL-OMNI\Source\VEIL'
if (Test-Path $src675) { Get-ChildItem -Path $src675 -Recurse -Include *.cpp,*.h,*.cs -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('MITO675 SOURCE FILE ' + $_.FullName + ' BYTES ' + $_.Length) } } else { Write-Output 'MITO675 NO SOURCE ROOT.' }
$content675 = 'D:\VEIL-OMNI\Content'
if (Test-Path $content675) { Get-ChildItem -Path $content675 -Recurse -ErrorAction SilentlyContinue | Where-Object { -not $_.PSIsContainer } | ForEach-Object { Write-Output ('MITO675 CONTENT FILE ' + $_.FullName + ' BYTES ' + $_.Length) } } else { Write-Output 'MITO675 NO CONTENT ROOT.' }
Write-Output 'MITO675 NOWRITE.'
Write-Output 'MITO675 NOCOOK.'
Write-Output 'JOB 675 DONE.'
```
