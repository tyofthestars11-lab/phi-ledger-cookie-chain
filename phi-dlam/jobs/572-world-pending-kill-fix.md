<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 572 - WORLD PENDING KILL ROOT CAUSE FIX (Ground: Job 571 printed the root cause as error C2039 at PHI CrashFix line 27 then 29, IsPendingKillPending is not a member of UWorld, so this job replaces that World call with the UObject pending kill call, then rebuilds with proof. Every variable carries the p572 prefix.) ==='
$p572c1 = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_CrashFix_AddressZero.cpp'
$p572h1 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_CrashFix_AddressZero.h'
$p572h2 = 'D:\VEIL-OMNI\Source\VEIL\Public\Game\PHI_GameState_Fixed.h'
$p572c2 = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\PHI_GameState_Fixed.cpp'
$p572backup = 'D:\VEIL-OMNI\Saved\backup572'
$p572log571 = 'D:\VEIL-OMNI\Saved\build571.log'
$p572log572 = 'D:\VEIL-OMNI\Saved\build572.log'
$p572uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p572buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
New-Item -ItemType Directory -Path $p572backup -Force | Out-Null
Copy-Item -Path $p572c1 -Destination (Join-Path $p572backup 'PHI_CrashFix_AddressZero.cpp') -Force
Copy-Item -Path $p572h1 -Destination (Join-Path $p572backup 'PHI_CrashFix_AddressZero.h') -Force
Copy-Item -Path $p572h2 -Destination (Join-Path $p572backup 'PHI_GameState_Fixed.h') -Force
Copy-Item -Path $p572c2 -Destination (Join-Path $p572backup 'PHI_GameState_Fixed.cpp') -Force
Write-Output 'BACKUP572 DONE'
if (Test-Path $p572log571) {
  $p572errs = @(Select-String -Path $p572log571 -Pattern 'erro[r]' | Select-Object -First 40)
  foreach ($p572e in $p572errs) { Write-Output ('LOGERROR ' + $p572e.Line.Trim()) }
  Write-Output 'LOG571 READ DONE'
} else {
  Write-Output 'LOG571 MISSING'
}
$p572t1 = [IO.File]::ReadAllText($p572c1)
$p572old = 'if (World->IsPendingKillPending()) { return false; }'
$p572new = 'if (World->IsPendingKill()) { return false; }'
if ($p572t1.Contains($p572old)) { $p572t1 = $p572t1.Replace($p572old, $p572new); Write-Output 'PATCH572 WORLD OK' } else { Write-Output 'PATCH572 WORLD MISS' }
[IO.File]::WriteAllText($p572c1, $p572t1)
$p572t2 = [IO.File]::ReadAllText($p572h1)
$p572t3 = [IO.File]::ReadAllText($p572h2)
$p572t4 = [IO.File]::ReadAllText($p572c2)
$p572open = ([regex]::Matches($p572t1, '\{')).Count + ([regex]::Matches($p572t2, '\{')).Count + ([regex]::Matches($p572t3, '\{')).Count + ([regex]::Matches($p572t4, '\{')).Count
$p572close = ([regex]::Matches($p572t1, '\}')).Count + ([regex]::Matches($p572t2, '\}')).Count + ([regex]::Matches($p572t3, '\}')).Count + ([regex]::Matches($p572t4, '\}')).Count
$p572popen = ([regex]::Matches($p572t1, '\(')).Count + ([regex]::Matches($p572t2, '\(')).Count + ([regex]::Matches($p572t3, '\(')).Count + ([regex]::Matches($p572t4, '\(')).Count
$p572pclose = ([regex]::Matches($p572t1, '\)')).Count + ([regex]::Matches($p572t2, '\)')).Count + ([regex]::Matches($p572t3, '\)')).Count + ([regex]::Matches($p572t4, '\)')).Count
Write-Output ('BRACE OPEN ' + $p572open + ' CLOSE ' + $p572close)
Write-Output ('PAREN OPEN ' + $p572popen + ' CLOSE ' + $p572pclose)
$p572d1 = @(Compare-Object -ReferenceObject (Get-Content (Join-Path $p572backup 'PHI_CrashFix_AddressZero.cpp')) -DifferenceObject (Get-Content $p572c1))
foreach ($p572d in $p572d1) { Write-Output ('DIFF ' + $p572d.InputObject) }
if (($p572open -eq $p572close) -and ($p572popen -eq $p572pclose)) {
  & $p572buildbat VEILEditor Win64 Development -Project="$p572uproj" -WaitMutex -NoHotReload *> "$p572log572"
  $p572res = @(Select-String -Path $p572log572 -Pattern 'Result:' | Select-Object -Last 1)
  if ($p572res.Count -gt 0) { Write-Output ('BUILD ' + $p572res[0].Line.Trim()) } else { Write-Output 'BUILD RESULT LINE MISSING' }
  $p572errs2 = @(Select-String -Path $p572log572 -Pattern 'erro[r]' | Select-Object -First 40)
  foreach ($p572e in $p572errs2) { Write-Output ('LOGERROR ' + $p572e.Line.Trim()) }
} else {
  Copy-Item -Path (Join-Path $p572backup 'PHI_CrashFix_AddressZero.cpp') -Destination $p572c1 -Force
  Write-Output 'GATE FAIL RESTORED'
}
Write-Output 'PHI P572 VERDICT: WORLD PENDING KILL ROOT CAUSE FIX ABOVE'
Write-Output 'JOB 572 DONE'
```
