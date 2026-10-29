<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 615 - AUTO TEST MAKE SURE (Ground: Tyree said Is it auto ing Make sure, so this job is the auto test, if it drains without work typing then auto is working, timer every 5 minutes, lane executes, Tyree does not type work, whole VEIL OMNI, no package until 100 percent done, no terminal work, Cyberpunk parked. Every variable carries the p615 prefix.) ==='
schtasks /query /tn 'PHI-DLAM-AutoWork' /fo list
$p615batdir = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles'
Set-Location $p615batdir
Write-Output 'IN615 BATCHFILES'
.\Build.bat VEILEditor Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build615.log'
Write-Output ('BUILD615 EXIT ' + $LASTEXITCODE)
Write-Output ('AUTO615 TEST ' + (Get-Date))
Write-Output 'PHI P615 VERDICT: AUTO TEST MAKE SURE ABOVE'
Write-Output 'JOB 615 DONE'
```
