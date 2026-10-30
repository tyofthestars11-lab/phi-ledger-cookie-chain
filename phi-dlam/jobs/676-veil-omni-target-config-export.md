<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 676 - VEIL OMNI TARGET AND CONFIG EXPORT (Ground: Job 675 exported the uproject, Build.cs, Source tree, and Content list, but its result carries zero Target lines and zero Config lines, so this job completes that manifest for Cowork. This job exports the Target files and the Config ini files as read only text: each Target file full content and each Config ini full content, with file counts. The live project sits only on his PC, not on the Muse VM. No writes to game source, no cook, no package, no editor launch.) ==='
$proj676 = 'D:\VEIL-OMNI'
Write-Output ('MITO676 PROJECT PRESENT ' + (Test-Path $proj676))
$tgt676 = Get-ChildItem -Path $proj676 -Filter *.Target.cs -ErrorAction SilentlyContinue
Write-Output ('MITO676 TARGET COUNT ' + $tgt676.Count)
$tgt676 | ForEach-Object { Write-Output ('MITO676 TARGET FILE ' + $_.FullName + ' BYTES ' + $_.Length); Get-Content $_.FullName | ForEach-Object { Write-Output ('MITO676 TARGET CONTENT ' + $_.Trim()) } }
$cfg676 = 'D:\VEIL-OMNI\Config'
Write-Output ('MITO676 CONFIG PRESENT ' + (Test-Path $cfg676))
if (Test-Path $cfg676) { $ini676 = Get-ChildItem -Path $cfg676 -Filter *.ini -ErrorAction SilentlyContinue; Write-Output ('MITO676 CONFIG COUNT ' + $ini676.Count); $ini676 | ForEach-Object { Write-Output ('MITO676 CONFIG FILE ' + $_.FullName + ' BYTES ' + $_.Length); Get-Content $_.FullName | ForEach-Object { Write-Output ('MITO676 CONFIG CONTENT ' + $_.Trim()) } } } else { Write-Output 'MITO676 NO CONFIG ROOT.' }
Write-Output 'MITO676 NOWRITE.'
Write-Output 'MITO676 NOCOOK.'
Write-Output 'JOB 676 DONE.'
```
