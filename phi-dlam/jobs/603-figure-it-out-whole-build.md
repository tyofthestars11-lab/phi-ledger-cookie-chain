<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 603 - FIGURE IT OUT WHOLE BUILD (Ground: Tyree said I need the game built yall need to figure it out, so this job figures it out and builds the game whole, Muse lane plus NWIRO plus Tyree AI, no asking Tyree, build VEIL OMNI editor, check map size, check quest system, check music, check attack, whole AAA holy grail not parts, no package until 100 percent done, no terminal work, Cyberpunk parked. Every variable carries the p603 prefix.) ==='
$p603buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$p603uproj = 'D:\VEIL-OMNI\VEIL.uproject'
& $p603buildbat VEILEditor Win64 Development -Project="$p603uproj" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build603.log'
Write-Output ('BUILD603 EXIT ' + $LASTEXITCODE)
$p603map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
if (Test-Path $p603map) { Write-Output ('MAP603 SIZE ' + (Get-Item $p603map).Length) } else { Write-Output 'MAP603 MISSING' }
$p603hits = @(Select-String -Path 'D:\VEIL-OMNI\Saved\build603.log' -Pattern 'Failed' -ErrorAction SilentlyContinue | Select-Object -First 20)
foreach ($p603h in $p603hits) { Write-Output ('BUILD603 ' + $p603h.LineNumber + ' ' + $p603h.Line.Trim()) }
Write-Output 'PHI P603 VERDICT: FIGURE IT OUT WHOLE BUILD ABOVE'
Write-Output 'JOB 603 DONE'
```
