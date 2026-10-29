<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 575 - BRAIN TOOLS CENSUS READ (Ground: The lightspeed brain keeps failing its powershell phi math with caret powers and undefined phi names, so this job reads where the brain HAND powershell tool and the brain prompt live on this PC, no patch, no brain run, no build, so the tool update lands from a read not a guess. Every variable carries the p575 prefix.) ==='
$p575vault = 'C:\Users\Admin\phi-vault\phi-dlam'
$p575run1 = 'C:\Users\Admin\phi-vault\phi-dlam.ps1'
$p575run2 = 'C:\Users\Admin\phi-vault\phi-direct-drain.ps1'
$p575files = @(Get-ChildItem -Path $p575vault -Recurse -File -ErrorAction SilentlyContinue | Select-Object -First 200)
foreach ($p575f in $p575files) { Write-Output ('FILE ' + $p575f.FullName) }
if (Test-Path $p575run1) { Write-Output 'RUNNER1 EXISTS' } else { Write-Output 'RUNNER1 MISSING' }
if (Test-Path $p575run2) { Write-Output 'RUNNER2 EXISTS' } else { Write-Output 'RUNNER2 MISSING' }
$p575hits1 = @(Select-String -Path $p575run1 -Pattern 'run_powershell' -ErrorAction SilentlyContinue | Select-Object -First 40)
foreach ($p575h in $p575hits1) { Write-Output ('HIT1 ' + $p575h.LineNumber + ' ' + $p575h.Line.Trim()) }
$p575hits2 = @(Select-String -Path $p575run2 -Pattern 'run_powershell' -ErrorAction SilentlyContinue | Select-Object -First 40)
foreach ($p575h in $p575hits2) { Write-Output ('HIT2 ' + $p575h.LineNumber + ' ' + $p575h.Line.Trim()) }
$p575hits3 = @(Select-String -Path $p575run1 -Pattern 'HAND' -ErrorAction SilentlyContinue | Select-Object -First 40)
foreach ($p575h in $p575hits3) { Write-Output ('HAND1 ' + $p575h.LineNumber + ' ' + $p575h.Line.Trim()) }
$p575hits4 = @(Select-String -Path $p575run2 -Pattern 'HAND' -ErrorAction SilentlyContinue | Select-Object -First 40)
foreach ($p575h in $p575hits4) { Write-Output ('HAND2 ' + $p575h.LineNumber + ' ' + $p575h.Line.Trim()) }
$p575hits5 = @(Get-ChildItem -Path $p575vault -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern 'phi' | Select-Object -First 40)
foreach ($p575h in $p575hits5) { Write-Output ('PHI ' + $p575h.Path + ' ' + $p575h.LineNumber + ' ' + $p575h.Line.Trim()) }
Write-Output 'PHI P575 VERDICT: BRAIN TOOLS CENSUS READ ABOVE'
Write-Output 'JOB 575 DONE'
```
