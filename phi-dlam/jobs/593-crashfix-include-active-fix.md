<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 593 - CRASHFIX INCLUDE ACTIVE FIX (Ground: Job 592 read build590 log C2653 UPHI_CrashFix_AddressZero is not a class or namespace name and C3861 GuardedAdvanceProgression identifier not found at OMNIQuestSystem lines 102 104 139 142 153 158, job 590 include check failed because it searched the whole text which already contains the call sites, so this job checks only for an include line, adds the CrashFix header include if no include line exists, backup first, full list rebuild only, diff only intended lines, brace paren balance, build only if patched, restore on gate fail, no package, no map placement, no terminal work, Cyberpunk parked, NWIRO AI help is the editor check after this fix. Every variable carries the p593 prefix.) ==='
$p593file = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\OMNIQuestSystem.cpp'
$p593bak = 'D:\VEIL-OMNI\Saved\backup593'
if (-not (Test-Path $p593bak)) { New-Item -ItemType Directory -Path $p593bak -Force | Out-Null }
Copy-Item $p593file "$p593bak\OMNIQuestSystem.cpp" -Force
Write-Output 'BACKUP593 DONE'
$p593orig = @(Get-Content $p593file)
$p593inclines = @($p593orig | Select-String -Pattern 'CrashFix')
Write-Output ('INCLUDE593 LINES ' + $p593inclines.Count)
$p593new = @()
$p593patched = 0
$p593incdone = 0
foreach ($p593line in $p593orig) {
  $p593new += $p593line
  if (($p593incdone -eq 0) -and ($p593inclines.Count -eq 0) -and ($p593line -match '#include')) {
    $p593new += '#include "Systems/PHI_CrashFix_AddressZero.h"'
    $p593patched = 1
    $p593incdone = 1
  }
}
Write-Output ('PATCH593 COUNT ' + $p593patched)
if ($p593patched -eq 1) {
  $p593new | Set-Content $p593file -Encoding UTF8
  Write-Output 'PATCH593 CRASHFIX INCLUDE OK'
} else {
  Write-Output 'PATCH593 INCLUDE ALREADY PRESENT OR NO INCLUDE LINE'
}
$p593after = @(Get-Content $p593file)
$p593diff = @(Compare-Object $p593orig $p593after)
Write-Output ('DIFF593 LINES ' + $p593diff.Count)
$p593text = Get-Content $p593file -Raw
$p593open = @([regex]::Matches($p593text, '\{')).Count
$p593close = @([regex]::Matches($p593text, '\}')).Count
$p593po = @([regex]::Matches($p593text, '\(')).Count
$p593pc = @([regex]::Matches($p593text, '\)')).Count
Write-Output ('BRACE593 ' + $p593open + '/' + $p593close)
Write-Output ('PAREN593 ' + $p593po + '/' + $p593pc)
if (($p593patched -eq 1) -and ($p593open -eq $p593close) -and ($p593po -eq $p593pc)) {
  $p593buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
  $p593uproj = 'D:\VEIL-OMNI\VEIL.uproject'
  & $p593buildbat VEILEditor Win64 Development -Project="$p593uproj" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build593.log'
  Write-Output ('BUILD593 EXIT ' + $LASTEXITCODE)
} else {
  Write-Output 'BUILD593 SKIPPED NOT PATCHED'
}
Write-Output 'PHI P593 VERDICT: CRASHFIX INCLUDE ACTIVE FIX ABOVE'
Write-Output 'JOB 593 DONE'
```
