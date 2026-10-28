<!-- PHI-DIRECT -->
```powershell
Write-Output '=== BUILD 482 - THE COMPILE THAT NEVER RAN (Ground: job 480 landed its patch whole, seat equals 2, pad section standing at 18 lines, and then its build line died before the compiler ever started: the line carried stray backslashes before its quotes, copied from a screen rendering of the standing build line, and the redirect path broke on them. The patch has stood written and uncompiled since. This job verifies the two PHI INPUT SEAT lines stand in the character source, prints whether the editor stands open, then runs the standing compile with clean quotes and nothing else in the way. The Result line and the first compiler error lines ride the verdict. Every variable carries the bd482 prefix.) ==='
$bd482cpp = 'D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp'
$bd482seats = @(Select-String -Path $bd482cpp -SimpleMatch 'PHI INPUT SEAT')
Write-Output ('SEATS=' + $bd482seats.Count)
foreach ($bd482s in $bd482seats) { Write-Output ('SEATLINE ' + $bd482s.LineNumber + ' ' + $bd482s.Line.Trim()) }
$bd482ed = @(Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match '^UnrealEdito[r]$' })
if ($bd482ed.Count -gt 0) { Write-Output ('EDITOR=OPEN pid=' + $bd482ed[0].Id) } else { Write-Output 'EDITOR=CLOSED' }
if ($bd482seats.Count -ne 2) { Write-Output 'PHI BD482 VERDICT: BUILD SKIP seats missing'; Write-Output 'JOB 482 DONE'; return }
$bd482buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$bd482uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$bd482logf = 'D:\VEIL-OMNI\Saved\build482.log'
& $bd482buildbat VEILEditor Win64 Development -Project="$bd482uproj" -WaitMutex -NoHotReload *> "$bd482logf"
$bd482result = @(Select-String -Path $bd482logf -Pattern 'Result:' -ErrorAction SilentlyContinue | Select-Object -Last 1)
$bd482resLine = 'none'; foreach ($bd482rr in $bd482result) { $bd482resLine = $bd482rr.Line.Trim() }
Write-Output ('BUILD ' + $bd482resLine)
$bd482errs = @(Select-String -Path $bd482logf -Pattern 'erro[r] C' -ErrorAction SilentlyContinue | Select-Object -First 10)
foreach ($bd482ee in $bd482errs) { Write-Output ('ERR ' + $bd482ee.Line.Trim()) }
Write-Output ('PHI BD482 VERDICT: BUILD seats=2 build=' + $bd482resLine)
Write-Output 'JOB 482 DONE'
```
