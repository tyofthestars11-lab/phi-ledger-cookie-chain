<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 590 - FIBONACCI PROGRESSION FIX (Ground: Jobs 587 and 588 patched progression but both builds returned EXIT 6, and the stage percents were linear 20 80 100, so this job fixes both, adds the CrashFix header include if it is missing, and sets stage percents by Fibonacci, fragment stage 1 Fib 1 of 5 equals 20, Warden stage 4 Fib 3 of 5 equals 60, Clear stage 5 Fib 5 of 5 equals 100, backup first, full list rebuild only, diff only intended lines, brace paren balance, build only if patched, restore on gate fail, no package, no map placement, no terminal work, Cyberpunk parked. Every variable carries the p590 prefix.) ==='
$p590file = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\OMNIQuestSystem.cpp'
$p590bak = 'D:\VEIL-OMNI\Saved\backup590'
if (-not (Test-Path $p590bak)) { New-Item -ItemType Directory -Path $p590bak -Force | Out-Null }
Copy-Item $p590file "$p590bak\OMNIQuestSystem.cpp" -Force
Write-Output 'BACKUP590 DONE'
$p590orig = @(Get-Content $p590file)
$p590text = Get-Content $p590file -Raw
$p590new = @()
$p590patched = 0
$p590incdone = 0
foreach ($p590line in $p590orig) {
  $p590out = $p590line
  if (($p590line -match '4, 80.0f') -and ($p590line -match 'GuardedAdvanceProgression')) {
    $p590out = $p590line -replace '4, 80.0f', '4, 60.0f'
    $p590patched = $p590patched + 1
  }
  $p590new += $p590out
  if (($p590incdone -eq 0) -and ($p590text -notmatch 'PHI_CrashFix_AddressZero') -and ($p590line -match '#include')) {
    $p590new += '#include "Systems/PHI_CrashFix_AddressZero.h"'
    $p590patched = $p590patched + 1
    $p590incdone = 1
  }
}
Write-Output ('PATCH590 COUNT ' + $p590patched)
if ($p590patched -ge 1) {
  $p590new | Set-Content $p590file -Encoding UTF8
  Write-Output 'PATCH590 FIBONACCI PROGRESSION OK'
} else {
  Write-Output 'PATCH590 NO TARGET GATE FAIL'
}
$p590after = @(Get-Content $p590file)
$p590diff = @(Compare-Object $p590orig $p590after)
Write-Output ('DIFF590 LINES ' + $p590diff.Count)
$p590text2 = Get-Content $p590file -Raw
$p590open = @([regex]::Matches($p590text2, '\{')).Count
$p590close = @([regex]::Matches($p590text2, '\}')).Count
$p590po = @([regex]::Matches($p590text2, '\(')).Count
$p590pc = @([regex]::Matches($p590text2, '\)')).Count
Write-Output ('BRACE590 ' + $p590open + '/' + $p590close)
Write-Output ('PAREN590 ' + $p590po + '/' + $p590pc)
if (($p590patched -ge 1) -and ($p590open -eq $p590close) -and ($p590po -eq $p590pc)) {
  $p590buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
  $p590uproj = 'D:\VEIL-OMNI\VEIL.uproject'
  & $p590buildbat VEILEditor Win64 Development -Project="$p590uproj" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build590.log'
  Write-Output ('BUILD590 EXIT ' + $LASTEXITCODE)
} else {
  Copy-Item "$p590bak\OMNIQuestSystem.cpp" $p590file -Force
  Write-Output 'BUILD590 SKIPPED RESTORED'
}
Write-Output 'PHI P590 VERDICT: FIBONACCI PROGRESSION FIX ABOVE'
Write-Output 'JOB 590 DONE'
```
