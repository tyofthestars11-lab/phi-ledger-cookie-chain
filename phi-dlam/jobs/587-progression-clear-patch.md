<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 587 - PROGRESSION CLEAR PATCH (Ground: Job 586 read GuardedAdvanceProgression signature UObject WorldContext int32 Stage float Percent, job 585 read PATH OF LIGHT CLEAR at OMNIQuestSystem line 148 as the last stage, so this job patches that clear line to call GuardedAdvanceProgression with stage 5 percent 100, backup first, full list rebuild only, diff only intended lines, brace paren balance, build only if patched, restore on gate fail, no package, no map placement, no terminal work, Cyberpunk parked. Every variable carries the p587 prefix.) ==='
$p587file = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\OMNIQuestSystem.cpp'
$p587bak = 'D:\VEIL-OMNI\Saved\backup587'
if (-not (Test-Path $p587bak)) { New-Item -ItemType Directory -Path $p587bak -Force | Out-Null }
Copy-Item $p587file "$p587bak\OMNIQuestSystem.cpp" -Force
Write-Output 'BACKUP587 DONE'
$p587orig = @(Get-Content $p587file)
$p587new = @()
$p587patched = 0
foreach ($p587line in $p587orig) {
  $p587new += $p587line
  if ($p587line -match 'PATH OF LIGHT CLEAR') {
    $p587new += '  UPHI_CrashFix_AddressZero::GuardedAdvanceProgression(this, 5, 100.0f);'
    $p587patched = 1
  }
}
if ($p587patched -eq 1) {
  $p587new | Set-Content $p587file -Encoding UTF8
  Write-Output 'PATCH587 PROGRESSION CLEAR OK'
} else {
  Write-Output 'PATCH587 NO CLEAR LINE GATE FAIL'
}
$p587after = @(Get-Content $p587file)
$p587diff = @(Compare-Object $p587orig $p587after)
Write-Output ('DIFF587 LINES ' + $p587diff.Count)
$p587text = Get-Content $p587file -Raw
$p587open = @([regex]::Matches($p587text, '\{')).Count
$p587close = @([regex]::Matches($p587text, '\}')).Count
$p587po = @([regex]::Matches($p587text, '\(')).Count
$p587pc = @([regex]::Matches($p587text, '\)')).Count
Write-Output ('BRACE587 ' + $p587open + '/' + $p587close)
Write-Output ('PAREN587 ' + $p587po + '/' + $p587pc)
if (($p587patched -eq 1) -and ($p587open -eq $p587close) -and ($p587po -eq $p587pc)) {
  $p587buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
  $p587uproj = 'D:\VEIL-OMNI\VEIL.uproject'
  & $p587buildbat VEILEditor Win64 Development -Project="$p587uproj" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build587.log'
  Write-Output ('BUILD587 EXIT ' + $LASTEXITCODE)
} else {
  Copy-Item "$p587bak\OMNIQuestSystem.cpp" $p587file -Force
  Write-Output 'BUILD587 SKIPPED RESTORED'
}
Write-Output 'PHI P587 VERDICT: PROGRESSION CLEAR PATCH ABOVE'
Write-Output 'JOB 587 DONE'
```
