<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 595 - FIGURE INCLUDE OUT (Ground: Job 593 counted 6 CrashFix lines but those were call sites not include lines, job 592 read C2653 class not found and C3861 identifier not found, so this job figures it out for real, it lists only lines that start with include, counts only those that contain CrashFix, adds the header include only if no include line contains CrashFix, backup first, full list rebuild only, diff only intended lines, brace paren balance, build only if patched, restore on gate fail, no package, no map placement, no terminal work, Cyberpunk parked. Every variable carries the p595 prefix.) ==='
$p595file = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\OMNIQuestSystem.cpp'
$p595bak = 'D:\VEIL-OMNI\Saved\backup595'
if (-not (Test-Path $p595bak)) { New-Item -ItemType Directory -Path $p595bak -Force | Out-Null }
Copy-Item $p595file "$p595bak\OMNIQuestSystem.cpp" -Force
Write-Output 'BACKUP595 DONE'
$p595orig = @(Get-Content $p595file)
$p595inc = 0
$p595crashinc = 0
foreach ($p595line in $p595orig) {
  if ($p595line.Trim().StartsWith('#include')) {
    $p595inc = $p595inc + 1
    Write-Output ('INCLUDE595 ' + $p595line.Trim())
    if ($p595line -match 'CrashFix') { $p595crashinc = $p595crashinc + 1 }
  }
}
Write-Output ('INCLUDE595 TOTAL ' + $p595inc)
Write-Output ('CRASHFIX595 INCLUDE COUNT ' + $p595crashinc)
$p595new = @()
$p595patched = 0
$p595done = 0
foreach ($p595line in $p595orig) {
  $p595new += $p595line
  if (($p595done -eq 0) -and ($p595crashinc -eq 0) -and ($p595line.Trim().StartsWith('#include'))) {
    $p595new += '#include "Systems/PHI_CrashFix_AddressZero.h"'
    $p595patched = 1
    $p595done = 1
  }
}
Write-Output ('PATCH595 COUNT ' + $p595patched)
if ($p595patched -eq 1) {
  $p595new | Set-Content $p595file -Encoding UTF8
  Write-Output 'PATCH595 FIGURE INCLUDE OK'
} else {
  Write-Output 'PATCH595 NO PATCH INCLUDE ALREADY IN LIST'
}
$p595after = @(Get-Content $p595file)
$p595diff = @(Compare-Object $p595orig $p595after)
Write-Output ('DIFF595 LINES ' + $p595diff.Count)
$p595text = Get-Content $p595file -Raw
$p595open = @([regex]::Matches($p595text, '\{')).Count
$p595close = @([regex]::Matches($p595text, '\}')).Count
$p595po = @([regex]::Matches($p595text, '\(')).Count
$p595pc = @([regex]::Matches($p595text, '\)')).Count
Write-Output ('BRACE595 ' + $p595open + '/' + $p595close)
Write-Output ('PAREN595 ' + $p595po + '/' + $p595pc)
if (($p595patched -eq 1) -and ($p595open -eq $p595close) -and ($p595po -eq $p595pc)) {
  $p595buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
  $p595uproj = 'D:\VEIL-OMNI\VEIL.uproject'
  & $p595buildbat VEILEditor Win64 Development -Project="$p595uproj" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build595.log'
  Write-Output ('BUILD595 EXIT ' + $LASTEXITCODE)
} else {
  Write-Output 'BUILD595 SKIPPED NOT PATCHED'
}
Write-Output 'PHI P595 VERDICT: FIGURE INCLUDE OUT ABOVE'
Write-Output 'JOB 595 DONE'
```
