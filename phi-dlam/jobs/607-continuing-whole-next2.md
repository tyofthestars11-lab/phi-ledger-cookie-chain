<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 607 - CONTINUING WHOLE NEXT2 (Ground: Tyree asked Continuing, so this job is the next continuing whole step after 606, lane continues, build green, editor open, quest music attack progression, whole AAA holy grail not parts, no package until 100 percent done, no terminal work, Cyberpunk parked. Every variable carries the p607 prefix.) ==='
$p607batdir = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles'
Set-Location $p607batdir
Write-Output 'IN607 BATCHFILES'
.\Build.bat VEILEditor Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build607.log'
Write-Output ('BUILD607 EXIT ' + $LASTEXITCODE)
$p607map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
if (Test-Path $p607map) { Write-Output ('MAP607 SIZE ' + (Get-Item $p607map).Length) } else { Write-Output 'MAP607 MISSING' }
$p607bolt = @(Select-String -Path 'D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp' -Pattern 'PHI BOLT' -ErrorAction SilentlyContinue)
Write-Output ('BOLT607 COUNT ' + $p607bolt.Count)
Write-Output 'PHI P607 VERDICT: CONTINUING WHOLE NEXT2 ABOVE'
Write-Output 'JOB 607 DONE'
```
