# Job 244 — Source census redo (inline, no scope trap) + attempt-2 package verdict for both games

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Two corrections in one job. (1) Job 238s census printed only its header: its Probe function appended to $script:lines, which bound to a shadow scope - every probe line was written into a variable the final print never read. The redo inlines all five probes in the main body, no functions, no scope tricks. (2) Job 240 raced job 239: it read VEILs attempt-2 log at 2 seconds old (2,692 bytes, cook in flight) and its UAT check looked for process names AutomationTool/RunUAT - the real UAT runs as dotnet, so it launched OMNI while VEIL was still cooking. This job reads both attempt-2 logs whole and delivers the verdict; if OMNIs attempt 2 died on the mutex AND VEILs run is finished, OMNI relaunches alone as attempt 3. ==='
$engine = 'C:\Program Files\Epic Games\UE_5.8'
$out = 'D:\VEIL\Saved\Logs\ue58_source_census.txt'
$lines = @('=== UE 5.8 SOURCE CENSUS (redo, inline) ===')
$p = "$engine\Engine\Source\Runtime\Engine\Classes\GameFramework\WorldSettings.h"
$lines += "--- WorldSettings.h exists=$(Test-Path $p) ---"
if (Test-Path $p) { $m = Select-String -Path $p -Pattern 'bEnableWorldTick|bEnableWorldPaused|Pauser' -Context 1,1; if ($m) { foreach ($x in $m) { $lines += ($x.Context.PreContext + $x.Line + $x.Context.PostContext) } } else { $lines += 'NO MATCHES' } }
$p = "$engine\Engine\Source\Runtime\Engine\Private\LevelTick.cpp"
$lines += "--- LevelTick.cpp exists=$(Test-Path $p) ---"
if (Test-Path $p) { $m = Select-String -Path $p -Pattern 'bEnableWorldTick|TimeSeconds' -Context 1,1; if ($m) { foreach ($x in $m) { $lines += ($x.Context.PreContext + $x.Line + $x.Context.PostContext) } } else { $lines += 'NO MATCHES' } }
$p = "$engine\Engine\Source\Runtime\NavigationSystem\Private\NavigationSystem.cpp"
$lines += "--- NavigationSystem.cpp exists=$(Test-Path $p) ---"
if (Test-Path $p) { $m = Select-String -Path $p -Pattern 'ReleaseBuildLock|IsBuildLocked|NOT building because navigation build is locked' -Context 1,1; if ($m) { foreach ($x in $m) { $lines += ($x.Context.PreContext + $x.Line + $x.Context.PostContext) } } else { $lines += 'NO MATCHES' } }
$p = "$engine\Engine\Source\Runtime\NavigationSystem\Public\NavigationSystem.h"
$lines += "--- NavigationSystem.h exists=$(Test-Path $p) ---"
if (Test-Path $p) { $m = Select-String -Path $p -Pattern 'ReleaseBuildLock|IsBuildLocked|CancelBuild' -Context 1,1; if ($m) { foreach ($x in $m) { $lines += ($x.Context.PreContext + $x.Line + $x.Context.PostContext) } } else { $lines += 'NO MATCHES' } }
$p = "$engine\Engine\Source\Runtime\NavigationSystem\Public\NavigationSystemTypes.h"
$lines += "--- NavigationSystemTypes.h exists=$(Test-Path $p) ---"
if (Test-Path $p) { $m = Select-String -Path $p -Pattern 'BuildLock|LockFlags' -Context 1,1; if ($m) { foreach ($x in $m) { $lines += ($x.Context.PreContext + $x.Line + $x.Context.PostContext) } } else { $lines += 'NO MATCHES' } }
$lines | Set-Content $out -Encoding UTF8
$lines | ForEach-Object { Write-Output $_ }
Write-Output '=== ATTEMPT-2 PACKAGE VERDICT ==='
$veilDone = $false
foreach ($t in @(@('VEIL attempt2','D:\VEIL\Saved\Logs\PackageVEILDone2.log','D:\Builds\VEIL\VEIL_DONE'), @('OMNI attempt2','D:\OMNI-UE\Saved\Logs\PackageOMNIDone2.log','D:\Builds\OMNI\OMNI_DONE'))) {
  $name = $t[0]; $log = $t[1]; $arch = $t[2]
  Write-Output "--- $name ---"
  if (Test-Path $log) {
    $fi = Get-Item $log
    Write-Output "log: $($fi.Length) bytes, last write $($fi.LastWriteTime)"
    $ll = Get-Content $log
    $errs = @($ll | Select-String -Pattern 'Error:')
    Write-Output "Error: lines = $($errs.Count)"
    $errs | Select-Object -First 10 | ForEach-Object { $_.Line }
    $fin = $ll | Select-String -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting'
    $fin | Select-Object -Last 3 | ForEach-Object { $_.Line }
    if ($name -eq 'VEIL attempt2' -and $fin) { $veilDone = $true }
    $ll | Select-Object -Last 3
  } else { Write-Output "log MISSING: $log" }
  if (Test-Path $arch) {
    Get-ChildItem $arch -Recurse -Filter *.exe -ErrorAction SilentlyContinue | ForEach-Object { "exe: $($_.FullName) $([math]::Round($_.Length/1MB,1)) MB $($_.LastWriteTime)" }
  } else { Write-Output "archive MISSING: $arch" }
}
$omniLog = 'D:\OMNI-UE\Saved\Logs\PackageOMNIDone2.log'
$omniDead = $false
if (Test-Path $omniLog) { $oi = Get-Item $omniLog; if ($oi.Length -lt 3000) { $omniDead = $true } }
if ($omniDead -and $veilDone) {
  $uatBat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
  $olog = 'D:\OMNI-UE\Saved\Logs\PackageOMNIDone3.log'
  $p3 = Start-Process -FilePath $uatBat -ArgumentList 'BuildCookRun','-Project=D:\OMNI-UE\OMNI.uproject','-Platform=Win64','-Cook','-Stage','-Pak','-Package','-Archive','-ArchiveDirectory=D:\Builds\OMNI\OMNI_DONE','-ClientConfig=Development','-Unattended','-NoP4' -PassThru -WindowStyle Hidden -RedirectStandardOutput $olog -RedirectStandardError 'D:\OMNI-UE\Saved\Logs\PackageOMNIDone3.err.log'
  Write-Output "PACKAGE OMNI_DONE (attempt 3, alone after VEIL finished) LAUNCHED: pid $($p3.Id), log $olog"
} elseif ($omniDead) { Write-Output 'OMNI attempt 2 died pre-log but VEIL attempt 2 shows no completion lines yet - OMNI relaunch waits for the next drain, no parallel UAT.' }
else { Write-Output 'OMNI attempt 2 log reads as a real run - no relaunch.' }
```
