<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 588 - PROGRESSION FRAGMENT WARDEN PATCH (Ground: Job 586 read GuardedAdvanceProgression signature stage percent, job 585 read Fragment gathered at OMNIQuestSystem line 102 and WARDEN PRIME HAS WOKEN at line 136, job 587 patched Clear at stage 5 percent 100, so this job patches fragment at stage 1 percent 20 and Warden at stage 4 percent 80, backup first, full list rebuild only, diff only intended lines, brace paren balance, build only if patched, restore on gate fail, no package, no map placement, no terminal work, Cyberpunk parked. Every variable carries the p588 prefix.) ==='
$p588file = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\OMNIQuestSystem.cpp'
$p588bak = 'D:\VEIL-OMNI\Saved\backup588'
if (-not (Test-Path $p588bak)) { New-Item -ItemType Directory -Path $p588bak -Force | Out-Null }
Copy-Item $p588file "$p588bak\OMNIQuestSystem.cpp" -Force
Write-Output 'BACKUP588 DONE'
$p588orig = @(Get-Content $p588file)
$p588new = @()
$p588patched = 0
foreach ($p588line in $p588orig) {
  $p588new += $p588line
  if ($p588line -match 'Fragment') {
    if ($p588line -match 'gathered') {
      $p588new += '  UPHI_CrashFix_AddressZero::GuardedAdvanceProgression(this, 1, 20.0f);'
      $p588patched = $p588patched + 1
    }
  }
  if ($p588line -match 'WARDEN PRIME HAS WOKEN') {
    $p588new += '  UPHI_CrashFix_AddressZero::GuardedAdvanceProgression(this, 4, 80.0f);'
    $p588patched = $p588patched + 1
  }
}
Write-Output ('PATCH588 COUNT ' + $p588patched)
if ($p588patched -ge 1) {
  $p588new | Set-Content $p588file -Encoding UTF8
  Write-Output 'PATCH588 PROGRESSION FRAGMENT WARDEN OK'
} else {
  Write-Output 'PATCH588 NO TARGET LINE GATE FAIL'
}
$p588after = @(Get-Content $p588file)
$p588diff = @(Compare-Object $p588orig $p588after)
Write-Output ('DIFF588 LINES ' + $p588diff.Count)
$p588text = Get-Content $p588file -Raw
$p588open = @([regex]::Matches($p588text, '\{')).Count
$p588close = @([regex]::Matches($p588text, '\}')).Count
$p588po = @([regex]::Matches($p588text, '\(')).Count
$p588pc = @([regex]::Matches($p588text, '\)')).Count
Write-Output ('BRACE588 ' + $p588open + '/' + $p588close)
Write-Output ('PAREN588 ' + $p588po + '/' + $p588pc)
if (($p588patched -ge 1) -and ($p588open -eq $p588close) -and ($p588po -eq $p588pc)) {
  $p588buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
  $p588uproj = 'D:\VEIL-OMNI\VEIL.uproject'
  & $p588buildbat VEILEditor Win64 Development -Project="$p588uproj" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build588.log'
  Write-Output ('BUILD588 EXIT ' + $LASTEXITCODE)
} else {
  Copy-Item "$p588bak\OMNIQuestSystem.cpp" $p588file -Force
  Write-Output 'BUILD588 SKIPPED RESTORED'
}
Write-Output 'PHI P588 VERDICT: PROGRESSION FRAGMENT WARDEN PATCH ABOVE'
Write-Output 'JOB 588 DONE'
```
