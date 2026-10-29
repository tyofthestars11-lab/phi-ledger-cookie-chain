<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 596 - NWIRO MUSE WHOLE BUILD (Ground: Tyree ordered have the AI help and have it build the game with you, NWIRO AI Pro 1.1.7 is seated at 13 plugins in VEIL OMNI, so this job is the joint build, Muse lane builds and NWIRO plugin is loaded in the project during the build, no package until 100 percent done, no map placement, no terminal work, Cyberpunk parked, so the game builds whole with both seats not one alone. Every variable carries the p596 prefix.) ==='
$p596buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$p596uproj = 'D:\VEIL-OMNI\VEIL.uproject'
if (Test-Path $p596uproj) { Write-Output 'PROJ596 EXISTS' } else { Write-Output 'PROJ596 MISSING' }
& $p596buildbat VEILEditor Win64 Development -Project="$p596uproj" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build596.log'
Write-Output ('BUILD596 EXIT ' + $LASTEXITCODE)
$p596hits = @(Select-String -Path 'D:\VEIL-OMNI\Saved\build596.log' -Pattern 'Failed' -ErrorAction SilentlyContinue | Select-Object -First 20)
foreach ($p596h in $p596hits) { Write-Output ('BUILD596 ' + $p596h.LineNumber + ' ' + $p596h.Line.Trim()) }
Write-Output 'PHI P596 VERDICT: NWIRO MUSE WHOLE BUILD ABOVE'
Write-Output 'JOB 596 DONE'
```
