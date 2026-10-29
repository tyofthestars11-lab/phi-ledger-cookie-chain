<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 617 - FINISH GAME CONTENT (Ground: Tyree said Help finish the video game, so this job is the finish content step after 616, vault world music quest attack progression, whole AAA holy grail not parts, finish means content in play not just build green, no package until 100 percent done, no terminal work, Cyberpunk parked. Every variable carries the p617 prefix.) ==='
$p617audio = 'D:\VEIL-OMNI\Content\PHI\Audio'
if (Test-Path $p617audio) { $p617stems = @(Get-ChildItem $p617audio -File); Write-Output ('STEMS617 COUNT ' + $p617stems.Count) } else { Write-Output 'AUDIO617 MISSING' }
$p617map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
if (Test-Path $p617map) { Write-Output ('MAP617 SIZE ' + (Get-Item $p617map).Length) } else { Write-Output 'MAP617 MISSING' }
$p617batdir = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles'
Set-Location $p617batdir
.\Build.bat VEILEditor Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build617.log'
Write-Output ('BUILD617 EXIT ' + $LASTEXITCODE)
Write-Output 'PHI P617 VERDICT: FINISH GAME CONTENT ABOVE'
Write-Output 'JOB 617 DONE'
```
