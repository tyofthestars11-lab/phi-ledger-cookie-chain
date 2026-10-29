<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 573 - WORLD PENDING KILL CALL REMOVAL FIX (Ground: Job 572 replaced the World pending kill call and the build still failed with error C2039, IsPendingKill is also not a member of UWorld, so this job removes that World call entirely, the IsValidLowLevel and GetGameState guards already cover the World, then rebuilds with proof. Every variable carries the p573 prefix.) ==='
$p573c1 = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_CrashFix_AddressZero.cpp'
$p573h1 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_CrashFix_AddressZero.h'
$p573h2 = 'D:\VEIL-OMNI\Source\VEIL\Public\Game\PHI_GameState_Fixed.h'
$p573c2 = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\PHI_GameState_Fixed.cpp'
$p573backup = 'D:\VEIL-OMNI\Saved\backup573'
$p573log572 = 'D:\VEIL-OMNI\Saved\build572.log'
$p573log573 = 'D:\VEIL-OMNI\Saved\build573.log'
$p573uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p573buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
New-Item -ItemType Directory -Path $p573backup -Force | Out-Null
Copy-Item -Path $p573c1 -Destination (Join-Path $p573backup 'PHI_CrashFix_AddressZero.cpp') -Force
Copy-Item -Path $p573h1 -Destination (Join-Path $p573backup 'PHI_CrashFix_AddressZero.h') -Force
Copy-Item -Path $p573h2 -Destination (Join-Path $p573backup 'PHI_GameState_Fixed.h') -Force
Copy-Item -Path $p573c2 -Destination (Join-Path $p573backup 'PHI_GameState_Fixed.cpp') -Force
Write-Output 'BACKUP573 DONE'
if (Test-Path $p573log572) {
  $p573errs = @(Select-String -Path $p573log572 -Pattern 'erro[r]' | Select-Object -First 40)
  foreach ($p573e in $p573errs) { Write-Output ('LOGERROR ' + $p573e.Line.Trim()) }
  Write-Output 'LOG572 READ DONE'
} else {
  Write-Output 'LOG572 MISSING'
}
$p573t1 = [IO.File]::ReadAllText($p573c1)
$p573old = '    if (World->IsPendingKill()) { return false; }'
if ($p573t1.Contains($p573old)) { $p573t1 = $p573t1.Replace($p573old, ''); Write-Output 'PATCH573 WORLD OK' } else { Write-Output 'PATCH573 WORLD MISS' }
[IO.File]::WriteAllText($p573c1, $p573t1)
$p573t2 = [IO.File]::ReadAllText($p573h1)
$p573t3 = [IO.File]::ReadAllText($p573h2)
$p573t4 = [IO.File]::ReadAllText($p573c2)
$p573open = ([regex]::Matches($p573t1, '\{')).Count + ([regex]::Matches($p573t2, '\{')).Count + ([regex]::Matches($p573t3, '\{')).Count + ([regex]::Matches($p573t4, '\{')).Count
$p573close = ([regex]::Matches($p573t1, '\}')).Count + ([regex]::Matches($p573t2, '\}')).Count + ([regex]::Matches($p573t3, '\}')).Count + ([regex]::Matches($p573t4, '\}')).Count
$p573popen = ([regex]::Matches($p573t1, '\(')).Count + ([regex]::Matches($p573t2, '\(')).Count + ([regex]::Matches($p573t3, '\(')).Count + ([regex]::Matches($p573t4, '\(')).Count
$p573pclose = ([regex]::Matches($p573t1, '\)')).Count + ([regex]::Matches($p573t2, '\)')).Count + ([regex]::Matches($p573t3, '\)')).Count + ([regex]::Matches($p573t4, '\)')).Count
Write-Output ('BRACE OPEN ' + $p573open + ' CLOSE ' + $p573close)
Write-Output ('PAREN OPEN ' + $p573popen + ' CLOSE ' + $p573pclose)
$p573d1 = @(Compare-Object -ReferenceObject (Get-Content (Join-Path $p573backup 'PHI_CrashFix_AddressZero.cpp')) -DifferenceObject (Get-Content $p573c1))
foreach ($p573d in $p573d1) { Write-Output ('DIFF ' + $p573d.InputObject) }
if (($p573open -eq $p573close) -and ($p573popen -eq $p573pclose)) {
  & $p573buildbat VEILEditor Win64 Development -Project="$p573uproj" -WaitMutex -NoHotReload *> "$p573log573"
  $p573res = @(Select-String -Path $p573log573 -Pattern 'Result:' | Select-Object -Last 1)
  if ($p573res.Count -gt 0) { Write-Output ('BUILD ' + $p573res[0].Line.Trim()) } else { Write-Output 'BUILD RESULT LINE MISSING' }
  $p573errs2 = @(Select-String -Path $p573log573 -Pattern 'erro[r]' | Select-Object -First 40)
  foreach ($p573e in $p573errs2) { Write-Output ('LOGERROR ' + $p573e.Line.Trim()) }
} else {
  Copy-Item -Path (Join-Path $p573backup 'PHI_CrashFix_AddressZero.cpp') -Destination $p573c1 -Force
  Write-Output 'GATE FAIL RESTORED'
}
Write-Output 'PHI P573 VERDICT: WORLD PENDING KILL CALL REMOVAL FIX ABOVE'
Write-Output 'JOB 573 DONE'
```
