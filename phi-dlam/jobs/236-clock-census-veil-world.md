# Job 236 — Clock census VEILWorld: same commandlet, second VEIL map

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 234 built the ClockCensusCommandlet into VEILEditor for VEILDistrict. This job runs the same commandlet on VEILWorld so both VEIL maps stand read in the engines own property names. If 234s build did not land, the commandlet is unknown to the editor and this job reports that instead of guessing. ==='
if (Test-Path 'D:\VEIL\Source\VEIL\Public\ClockCensusCommandlet.h') {
  $cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
  $run = & $cmd 'D:\VEIL\VEIL.uproject' '-run=ClockCensusCommandlet' '-MAP=/Game/Maps/VEILWorld' '-FILE=D:\VEIL\Content\Maps\VEILWorld.umap' '-OUT=World' '-abslog=D:\VEIL\Saved\Logs\clock_census_world_cmd.log' -unattended 2>&1
  $run | Select-String -Pattern 'Error|Traceback|Exception' | Select-Object -First 10 | ForEach-Object { $_.Line }
  Write-Output '--- clock_census_World.txt ---'
  Get-Content 'D:\VEIL\Saved\Logs\clock_census_World.txt' -ErrorAction SilentlyContinue
  Write-Output '--- nav_api_census_World.txt ---'
  Get-Content 'D:\VEIL\Saved\Logs\nav_api_census_World.txt' -ErrorAction SilentlyContinue
} else { Write-Output 'ClockCensusCommandlet.h NOT present in D:\VEIL\Source\VEIL\Public - job 234 did not land; census not attempted.' }
```
