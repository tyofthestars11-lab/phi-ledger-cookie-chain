<!-- PHI-DIRECT -->
```powershell
Write-Output '=== BUILD READ 491 - THE RULES ERROR IN ITS OWN WORDS (Ground: job 488 seated PHI PAD PROOF in the character Tick, gates clean, texture pool verified at 2500, and its build came back Result: Failed (RulesError) before a single file compiled, with only the Result line captured. A RulesError is the build reading its own rules, not the game code, and the reason stands written in build488.log beside the verdict. This job prints that reason whole, the rules lines and the log tail, then runs the standing build once more with the reason in the record. The Result line and the first fault lines ride the verdict. Every variable carries the bd491 prefix.) ==='
$bd491proj = 'D:\VEIL-OMNI'
$bd491old = Join-Path $bd491proj 'Saved\build488.log'
if (Test-Path $bd491old) {
  Select-String -Path $bd491old -Pattern 'RulesErro[r]' -Context 4, 12 | ForEach-Object { Write-Output ('RULES ' + $_.Line) }
  Get-Content $bd491old -Tail 15 | ForEach-Object { Write-Output ('LOGTAIL ' + $_) }
} else { Write-Output 'OLD LOG MISSING' }
$bd491ed = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
if ($bd491ed.Count -gt 0) { Write-Output 'EDITOR=OPEN'; Write-Output 'PHI BD491 VERDICT: BUILD build=HELD-EDITOR-OPEN'; Write-Output 'JOB 491 DONE'; return }
Write-Output 'EDITOR=CLOSED'
$bd491buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$bd491uproj = Join-Path $bd491proj 'VEIL.uproject'
$bd491log = Join-Path $bd491proj 'Saved\build491.log'
& $bd491buildbat VEILEditor Win64 Development -Project="$bd491uproj" -WaitMutex -NoHotReload *> "$bd491log"
$bd491res = ''
if (Test-Path $bd491log) { $bd491res = (Select-String -Path $bd491log -Pattern 'Result:' | Select-Object -Last 1).Line }
Write-Output ('BUILD ' + $bd491res)
if (Test-Path $bd491log) { Select-String -Path $bd491log -Pattern 'rro[r]' | Select-Object -First 8 | ForEach-Object { Write-Output ('ERR ' + $_.Line) } }
Write-Output ('PHI BD491 VERDICT: BUILD build=' + $bd491res)
Write-Output 'JOB 491 DONE'
```
