<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 571 - BUILD FAILURE ROOT CAUSE FIX (Ground: Job 570 staged CrashFix and GameState and the build came back Failed OtherCompilationError with no error lines in its result, so this job reads build570 log first and prints the root cause lines, then patches the named gaps, then rebuilds with proof. Every variable carries the p571 prefix.) ==='
$p571h1 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\PHI_CrashFix_AddressZero.h'
$p571c1 = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_CrashFix_AddressZero.cpp'
$p571h2 = 'D:\VEIL-OMNI\Source\VEIL\Public\Game\PHI_GameState_Fixed.h'
$p571c2 = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\PHI_GameState_Fixed.cpp'
$p571backup = 'D:\VEIL-OMNI\Saved\backup571'
$p571log570 = 'D:\VEIL-OMNI\Saved\build570.log'
$p571log571 = 'D:\VEIL-OMNI\Saved\build571.log'
$p571uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p571buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$p571nl = [char]10
New-Item -ItemType Directory -Path $p571backup -Force | Out-Null
Copy-Item -Path $p571h1 -Destination (Join-Path $p571backup 'PHI_CrashFix_AddressZero.h') -Force
Copy-Item -Path $p571c1 -Destination (Join-Path $p571backup 'PHI_CrashFix_AddressZero.cpp') -Force
Copy-Item -Path $p571h2 -Destination (Join-Path $p571backup 'PHI_GameState_Fixed.h') -Force
Copy-Item -Path $p571c2 -Destination (Join-Path $p571backup 'PHI_GameState_Fixed.cpp') -Force
Write-Output 'BACKUP571 DONE'
if (Test-Path $p571log570) {
  $p571errs = @(Select-String -Path $p571log570 -Pattern 'erro[r]' | Select-Object -First 40)
  foreach ($p571e in $p571errs) { Write-Output ('LOGERROR ' + $p571e.Line.Trim()) }
  $p571codes = @(Select-String -Path $p571log570 -Pattern 'C[0-9]{4}' | Select-Object -First 40)
  foreach ($p571c in $p571codes) { Write-Output ('LOGCODE ' + $p571c.Line.Trim()) }
  $p571phi = @(Select-String -Path $p571log570 -Pattern 'PHI_' | Select-Object -First 40)
  foreach ($p571p in $p571phi) { Write-Output ('LOGPHI ' + $p571p.Line.Trim()) }
  Write-Output 'LOG570 READ DONE'
} else {
  Write-Output 'LOG570 MISSING'
}
$p571t1 = [IO.File]::ReadAllText($p571h1)
$p571t2 = [IO.File]::ReadAllText($p571c1)
$p571t3 = [IO.File]::ReadAllText($p571h2)
$p571t4 = [IO.File]::ReadAllText($p571c2)
$p571rep1 = '#include "CoreMinimal.h"' + $p571nl + 'class APawn;' + $p571nl + 'class UWorld;'
if ($p571t1.Contains('#include "CoreMinimal.h"')) { $p571t1 = $p571t1.Replace('#include "CoreMinimal.h"', $p571rep1); Write-Output 'PATCH571 HEADER1 OK' } else { Write-Output 'PATCH571 HEADER1 MISS' }
$p571rep2 = '#include "Game/PHI_GameState_Fixed.h"' + $p571nl + '#include "Engine/Engine.h"'
if ($p571t4.Contains('#include "Game/PHI_GameState_Fixed.h"')) { $p571t4 = $p571t4.Replace('#include "Game/PHI_GameState_Fixed.h"', $p571rep2); Write-Output 'PATCH571 GAMESTATE OK' } else { Write-Output 'PATCH571 GAMESTATE MISS' }
$p571rep3 = '#include "GameFramework/CharacterMovementComponent.h"' + $p571nl + '#include "GameFramework/Pawn.h"' + $p571nl + '#include "Engine/World.h"'
if ($p571t2.Contains('#include "GameFramework/CharacterMovementComponent.h"')) { $p571t2 = $p571t2.Replace('#include "GameFramework/CharacterMovementComponent.h"', $p571rep3); Write-Output 'PATCH571 CRASHFIX OK' } else { Write-Output 'PATCH571 CRASHFIX MISS' }
[IO.File]::WriteAllText($p571h1, $p571t1)
[IO.File]::WriteAllText($p571c1, $p571t2)
[IO.File]::WriteAllText($p571h2, $p571t3)
[IO.File]::WriteAllText($p571c2, $p571t4)
$p571open = ([regex]::Matches($p571t1, '\{')).Count + ([regex]::Matches($p571t2, '\{')).Count + ([regex]::Matches($p571t3, '\{')).Count + ([regex]::Matches($p571t4, '\{')).Count
$p571close = ([regex]::Matches($p571t1, '\}')).Count + ([regex]::Matches($p571t2, '\}')).Count + ([regex]::Matches($p571t3, '\}')).Count + ([regex]::Matches($p571t4, '\}')).Count
$p571popen = ([regex]::Matches($p571t1, '\(')).Count + ([regex]::Matches($p571t2, '\(')).Count + ([regex]::Matches($p571t3, '\(')).Count + ([regex]::Matches($p571t4, '\(')).Count
$p571pclose = ([regex]::Matches($p571t1, '\)')).Count + ([regex]::Matches($p571t2, '\)')).Count + ([regex]::Matches($p571t3, '\)')).Count + ([regex]::Matches($p571t4, '\)')).Count
Write-Output ('BRACE OPEN ' + $p571open + ' CLOSE ' + $p571close)
Write-Output ('PAREN OPEN ' + $p571popen + ' CLOSE ' + $p571pclose)
$p571d1 = @(Compare-Object -ReferenceObject (Get-Content (Join-Path $p571backup 'PHI_CrashFix_AddressZero.h')) -DifferenceObject (Get-Content $p571h1))
foreach ($p571d in $p571d1) { Write-Output ('DIFF ' + $p571d.InputObject) }
$p571d2 = @(Compare-Object -ReferenceObject (Get-Content (Join-Path $p571backup 'PHI_CrashFix_AddressZero.cpp')) -DifferenceObject (Get-Content $p571c1))
foreach ($p571d in $p571d2) { Write-Output ('DIFF ' + $p571d.InputObject) }
$p571d3 = @(Compare-Object -ReferenceObject (Get-Content (Join-Path $p571backup 'PHI_GameState_Fixed.cpp')) -DifferenceObject (Get-Content $p571c2))
foreach ($p571d in $p571d3) { Write-Output ('DIFF ' + $p571d.InputObject) }
if (($p571open -eq $p571close) -and ($p571popen -eq $p571pclose)) {
  & $p571buildbat VEILEditor Win64 Development -Project="$p571uproj" -WaitMutex -NoHotReload *> "$p571log571"
  $p571res = @(Select-String -Path $p571log571 -Pattern 'Result:' | Select-Object -Last 1)
  if ($p571res.Count -gt 0) { Write-Output ('BUILD ' + $p571res[0].Line.Trim()) } else { Write-Output 'BUILD RESULT LINE MISSING' }
  $p571errs2 = @(Select-String -Path $p571log571 -Pattern 'erro[r]' | Select-Object -First 40)
  foreach ($p571e in $p571errs2) { Write-Output ('LOGERROR ' + $p571e.Line.Trim()) }
} else {
  Copy-Item -Path (Join-Path $p571backup 'PHI_CrashFix_AddressZero.h') -Destination $p571h1 -Force
  Copy-Item -Path (Join-Path $p571backup 'PHI_CrashFix_AddressZero.cpp') -Destination $p571c1 -Force
  Copy-Item -Path (Join-Path $p571backup 'PHI_GameState_Fixed.h') -Destination $p571h2 -Force
  Copy-Item -Path (Join-Path $p571backup 'PHI_GameState_Fixed.cpp') -Destination $p571c2 -Force
  Write-Output 'GATE FAIL RESTORED'
}
Write-Output 'PHI P571 VERDICT: BUILD FAILURE ROOT CAUSE FIX ABOVE'
Write-Output 'JOB 571 DONE'
```
