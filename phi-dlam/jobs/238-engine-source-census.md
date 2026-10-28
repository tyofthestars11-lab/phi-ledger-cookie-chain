# Job 238 — Engine source census: Meta's UE 5.8 decode lines, read from Tyree's own install (corrected paths)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Meta pasted a UE 5.8 reverse-engineer decode naming engine internals for all four open problems, plus a dump job whose paths were relative (engine\Engine\Source\...), half its Add-Content calls missing the $ on the output variable, and its engine variable never used - as written it produces an empty file and a false refute. This job is that census corrected: absolute paths from the install root, file-existence checks first, full match lines with context, captured whole. It settles which of Metas named internals actually exist in THIS 5.8 install: WorldSettings.h (bEnableWorldTick / bEnableWorldPaused / Pauser), LevelTick.cpp (the TimeSeconds advance), NavigationSystem (ReleaseBuildLock / IsBuildLocked / the locked log string). ==='
$engine = 'C:\Program Files\Epic Games\UE_5.8'
$out = 'D:\VEIL\Saved\Logs\ue58_source_census.txt'
$lines = @()
$lines += '=== UE 5.8 SOURCE CENSUS ==='
function Probe($label, $rel, $pattern) {
  $p = Join-Path $engine $rel
  $script:lines += "--- $label : $rel exists=$(Test-Path $p) ---"
  if (Test-Path $p) {
    $m = Select-String -Path $p -Pattern $pattern -Context 1,1
    if ($m) { foreach ($x in $m) { $script:lines += ($x.Context.PreContext + $x.Line + $x.Context.PostContext) } }
    else { $script:lines += 'NO MATCHES' }
  }
}
Probe 'WorldSettings.h tick flags' 'Engine\Source\Runtime\Engine\Classes\GameFramework\WorldSettings.h' 'bEnableWorldTick|bEnableWorldPaused|Pauser'
Probe 'LevelTick.cpp clock advance' 'Engine\Source\Runtime\Engine\Private\LevelTick.cpp' 'bEnableWorldTick|TimeSeconds'
Probe 'NavigationSystem.cpp lock' 'Engine\Source\Runtime\NavigationSystem\Private\NavigationSystem.cpp' 'ReleaseBuildLock|IsBuildLocked|NOT building because navigation build is locked'
Probe 'NavigationSystem.h lock API' 'Engine\Source\Runtime\NavigationSystem\Public\NavigationSystem.h' 'ReleaseBuildLock|IsBuildLocked|CancelBuild'
Probe 'NavigationSystemTypes lock flags' 'Engine\Source\Runtime\NavigationSystem\Public\NavigationSystemTypes.h' 'BuildLock|0x20|LockFlags'
$lines | Set-Content $out -Encoding UTF8
$lines | ForEach-Object { Write-Output $_ }
```
