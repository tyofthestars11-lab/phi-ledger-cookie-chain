<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 702 - VEIL OMNI BUILD 701 LOG READ AND FLAT INCLUDE HUNT (Ground: Job 701 updated 12 files to Character and Systems includes and restarted the build detached, but reported FLAT LEFT True, so one flat include of those names still remains. This job reads Saved Logs VEIL_701_build_out.log and VEIL_701_build_err.log, prints line counts, tail 40 lines each, every line with Result, and prints every flat include line with its file name and line number by searching all cpp and h files under Source VEIL for include lines that start directly with VEIL or PHI_ after the quote, under Electron phase lock and the Golden Angle Anti-Run-Fail Protocol. No cook, no package, no 1.0, no editor GUI launch.) ==='
$proj702 = 'D:\VEIL-OMNI'
$out702 = Join-Path $proj702 'Saved\Logs\VEIL_701_build_out.log'
$err702 = Join-Path $proj702 'Saved\Logs\VEIL_701_build_err.log'
Write-Output ('READ702 OUT PRESENT ' + (Test-Path $out702))
Write-Output ('READ702 ERR PRESENT ' + (Test-Path $err702))
if (Test-Path $out702) { $l702 = Get-Content $out702; Write-Output ('READ702 OUT LINES ' + $l702.Count); $l702 | Select-String -Pattern 'Result' | ForEach-Object { Write-Output ('READ702 RESULT LINE ' + $_.Line.Trim()) }; $l702 | Select-Object -Last 40 | ForEach-Object { Write-Output ('READ702 OUT TAIL ' + $_.Trim()) } }
if (Test-Path $err702) { $e702 = Get-Content $err702; Write-Output ('READ702 ERR LINES ' + $e702.Count); $e702 | Select-Object -Last 40 | ForEach-Object { Write-Output ('READ702 ERR TAIL ' + $_.Trim()) } }
$src702 = Join-Path $proj702 'Source\VEIL'
Get-ChildItem -Recurse -File $src702 -Include *.cpp,*.h -ErrorAction SilentlyContinue | Select-String -Pattern '#include "(VEIL|PHI_)' | ForEach-Object { Write-Output ('FLAT702 ' + $_.Path + ' LINE ' + $_.LineNumber + ' ' + $_.Line.Trim()) }
$proc702 = Get-Process -Name 'Build' -ErrorAction SilentlyContinue
Write-Output ('READ702 BUILD RUNNING ' + ($null -ne $proc702))
Write-Output 'READ702 ELECTRON PHASE LOCK HELD.'
Write-Output 'READ702 NOCOOK.'
Write-Output 'READ702 NOPACKAGE.'
Write-Output 'JOB 702 DONE.'
```
