<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 651 - SAVE CLOSE GUI RUN PLACE648 (Ground: Tyree order file 651 save and close GUI editor then run Cmd editor plus 650 result GUI still open run deferred again map after 180952 no change not progress build skipped log missing. This job closes the GUI editor by Tyree word, graceful close first then forced close only after a 90 second graceful wait, backup taken first, then runs UnrealEditor-Cmd place648, then builds only if no editor process runs. No split phi squared equals phi plus 1 does not split one whole everywhere all at once. No package until 100 percent done. No ledger edit. Every variable carries the p651 prefix.) ==='
$p651proj = 'D:\VEIL-OMNI'
$p651uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p651map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p651script = 'D:\VEIL-OMNI\Saved\place648.py'
$p651log = 'D:\VEIL-OMNI\Saved\place651.log'
$p651backup = 'D:\VEIL-OMNI\Saved\backup651'
$p651run1 = 'C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1'
$p651run2 = 'C:\Users\Admin\phi-vault\phi-dlam\phi-direct-drain.ps1'
$p651cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$p651batdir = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles'
New-Item -ItemType Directory -Path $p651backup -Force | Out-Null
foreach ($p651f in @($p651map, $p651uproj)) { if (Test-Path $p651f) { Copy-Item $p651f $p651backup -Force; Write-Output ('BACKUP651 DONE ' + $p651f) } else { Write-Output ('BACKUP651 MISSING ' + $p651f) } }
Write-Output 'WHOLE651 NO SPLIT ONE WHOLE EVERYWHERE ALL AT ONCE'
if (Test-Path $p651map) { Write-Output ('MAP651 BEFORE SIZE ' + (Get-Item $p651map).Length) } else { Write-Output 'MAP651 BEFORE MISSING' }
if (Test-Path $p651script) { Write-Output ('SCRIPT651 FOUND SIZE ' + (Get-Item $p651script).Length) } else { Write-Output 'SCRIPT651 MISSING EDITOR RUN STOPPED' }
foreach ($p651r in @($p651run1, $p651run2)) {
  if (Test-Path $p651r) {
    $p651hits = @(Select-String -Path $p651r -Pattern 'lightspeed' -ErrorAction SilentlyContinue)
    Write-Output ('LIGHTSPEED651 HITS ' + $p651hits.Count + ' IN ' + $p651r)
    $p651caret = @(Select-String -Path $p651r -Pattern 'phi\^' -ErrorAction SilentlyContinue)
    Write-Output ('CARET651 HITS ' + $p651caret.Count + ' IN ' + $p651r)
  } else { Write-Output ('RUNNER651 MISSING ' + $p651r) }
}
$p651phi = 1.618033988749895
$p651rung = [math]::Log(180952) / [math]::Log($p651phi)
$p651back = [math]::Pow($p651phi, $p651rung)
Write-Output ('LIGHTSPEED651 PHI MATH RUNG ' + $p651rung + ' ROUNDTRIP ' + $p651back)
$p651gui = Get-Process UnrealEditor -ErrorAction SilentlyContinue
if ($p651gui) {
  Write-Output 'EDITOR651 GUI OPEN GRACEFUL CLOSE STARTS'
  foreach ($p651p in $p651gui) { $p651p.CloseMainWindow() | Out-Null }
  $p651wait = 0
  while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and ($p651wait -lt 90)) { Start-Sleep -Seconds 10; $p651wait += 10 }
  if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) {
    Write-Output 'EDITOR651 GRACEFUL CLOSE WAITED 90 SECONDS STILL OPEN FORCED CLOSE BY TYREE WORD BACKUP ALREADY TAKEN'
    Stop-Process -Name UnrealEditor -Force -ErrorAction SilentlyContinue
    Start-Sleep -Seconds 10
  }
  if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR651 GUI STILL OPEN AFTER FORCED CLOSE CMD RUN SKIPPED' } else { Write-Output 'EDITOR651 GUI CLOSED CMD EDITOR RUN STARTS' }
} else { Write-Output 'EDITOR651 GUI ALREADY CLOSED CMD EDITOR RUN STARTS' }
if ((-not (Get-Process UnrealEditor -ErrorAction SilentlyContinue)) -and (Test-Path $p651script) -and (Test-Path $p651cmd) -and (Test-Path $p651uproj)) {
  $p651proc = Start-Process $p651cmd -ArgumentList "`"$p651uproj`"", '-run=PythonScript', "-script=`"$p651script`"", '-unattended', '-nop4', '-nosplash', "-log=$p651log" -PassThru
  Write-Output ('EDITOR651 STARTED PID ' + $p651proc.Id)
  $p651wait2 = 0
  while ((-not $p651proc.HasExited) -and ($p651wait2 -lt 180)) { Start-Sleep -Seconds 10; $p651wait2 += 10 }
  if ($p651proc.HasExited) { Write-Output ('EDITOR651 EXIT ' + $p651proc.ExitCode) } else { Write-Output 'EDITOR651 STILL RUNNING AFTER 180 SECONDS BUILD SKIPPED WHILE EDITOR RUNS' }
} else { Write-Output 'EDITOR651 CMD RUN SKIPPED GUI OPEN OR PREREQUISITE MISSING' }
if (Test-Path $p651log) {
  $p651logLines = @(Get-Content $p651log -ErrorAction SilentlyContinue | Select-String -Pattern 'ACTORS648|COUNTESS648|VAULT648|SAVE648' -ErrorAction SilentlyContinue)
  Write-Output ('LOG651 MATCH LINES ' + $p651logLines.Count)
  foreach ($p651l in $p651logLines) { Write-Output ('LOG651 ' + $p651l.Line) }
} else { Write-Output 'LOG651 MISSING' }
if ((-not (Get-Process UnrealEditor-Cmd -ErrorAction SilentlyContinue)) -and (-not (Get-Process UnrealEditor -ErrorAction SilentlyContinue))) {
  Set-Location $p651batdir
  .\Build.bat VEILEditor Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build651.log'
  Write-Output ('BUILD651 EXIT ' + $LASTEXITCODE)
} else { Write-Output 'BUILD651 SKIPPED EDITOR PROCESS STILL RUNNING' }
if (Test-Path $p651map) {
  $p651afterSize = (Get-Item $p651map).Length
  Write-Output ('MAP651 AFTER SIZE ' + $p651afterSize)
  if ($p651afterSize -eq 180952) { Write-Output 'PROGRESS651 NO CHANGE NOT PROGRESS BUILD EXIT 0 ALONE IS NOT PROGRESS' } else { Write-Output 'PROGRESS651 CHANGED MAP SIZE MOVED' }
} else { Write-Output 'MAP651 AFTER MISSING' }
Write-Output 'AUTO651 HIDDENDRAIN TASK QUERY BELOW'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
Write-Output 'NOPACKAGE651 NO PACKAGE UNTIL 100 PERCENT DONE'
Write-Output 'JOB 651 DONE'
```
