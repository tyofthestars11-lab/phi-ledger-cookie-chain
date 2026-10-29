<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 611 - CONTINUE ON (Ground: Tyree said I need you to continue, so this job is the next continuing whole step after 610, Muse continues, lane continues, build green, editor open, quest music attack progression, whole AAA holy grail not parts, no package until 100 percent done, no terminal work, Cyberpunk parked. Every variable carries the p611 prefix.) ==='
$p611batdir = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles'
Set-Location $p611batdir
Write-Output 'IN611 BATCHFILES'
.\Build.bat VEILEditor Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build611.log'
Write-Output ('BUILD611 EXIT ' + $LASTEXITCODE)
$p611map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
if (Test-Path $p611map) { Write-Output ('MAP611 SIZE ' + (Get-Item $p611map).Length) } else { Write-Output 'MAP611 MISSING' }
$p611warden = @(Select-String -Path 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\OMNIQuestSystem.cpp' -Pattern 'WardenAwake' -ErrorAction SilentlyContinue)
Write-Output ('WARDEN611 COUNT ' + $p611warden.Count)
Write-Output 'PHI P611 VERDICT: CONTINUE ON ABOVE'
Write-Output 'JOB 611 DONE'
```
