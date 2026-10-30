<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 650 - EDITOR RUN PLACE648 RETRY PLUS LIGHTSPEED CARET LINES READ (Ground: 649 result editor run deferred GUI editor running log missing map 180952 unchanged build skipped lightspeed caret is XOR in PowerShell use Pow not caret natural loop hits 36 and 3. Retry is real: poll GUI editor up to 60 seconds then run UnrealEditor-Cmd PythonScript place648 save level then build then map proof. No force close of a GUI editor. No package until 100 percent done. No ledger edit. Every variable carries the p650 prefix.) ==='
$p650proj = 'D:\VEIL-OMNI'
$p650uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p650map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p650script = 'D:\VEIL-OMNI\Saved\place648.py'
$p650log = 'D:\VEIL-OMNI\Saved\place650.log'
$p650backup = 'D:\VEIL-OMNI\Saved\backup650'
$p650run1 = 'C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1'
$p650run2 = 'C:\Users\Admin\phi-vault\phi-dlam\phi-direct-drain.ps1'
$p650cmd = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$p650batdir = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles'
New-Item -ItemType Directory -Path $p650backup -Force | Out-Null
foreach ($p650f in @($p650map, $p650uproj)) { if (Test-Path $p650f) { Copy-Item $p650f $p650backup -Force; Write-Output ('BACKUP650 DONE ' + $p650f) } else { Write-Output ('BACKUP650 MISSING ' + $p650f) } }
Write-Output 'WHOLE650 NO SPLIT ONE WHOLE EVERYWHERE ALL AT ONCE'
if (Test-Path $p650map) { Write-Output ('MAP650 BEFORE SIZE ' + (Get-Item $p650map).Length) } else { Write-Output 'MAP650 BEFORE MISSING' }
if (Test-Path $p650script) { Write-Output ('SCRIPT650 FOUND SIZE ' + (Get-Item $p650script).Length) } else { Write-Output 'SCRIPT650 MISSING EDITOR RUN STOPPED' }
$p650guiWait = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and ($p650guiWait -lt 60)) { Start-Sleep -Seconds 10; $p650guiWait += 10 }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR650 GUI STILL RUNNING AFTER 60 SECONDS DEFERRED NO FORCE CLOSE' } else { Write-Output 'EDITOR650 GUI NOT RUNNING ROAD CLEAR' }
Write-Output 'EDITOR650 RUN PLACE648 IN UNREALEDITOR CMD PYTHONSCRIPT'
if ((Test-Path $p650script) -and (Test-Path $p650cmd) -and (Test-Path $p650uproj) -and (-not (Get-Process UnrealEditor -ErrorAction SilentlyContinue))) {
    $p650proc = Start-Process $p650cmd -ArgumentList "`"$p650uproj`"", '-run=PythonScript', "-script=`"$p650script`"", '-unattended', '-nop4', '-nosplash', "-log=$p650log" -PassThru
    Write-Output ('EDITOR650 STARTED PID ' + $p650proc.Id)
    $p650wait = 0
    while ((-not $p650proc.HasExited) -and ($p650wait -lt 120)) { Start-Sleep -Seconds 10; $p650wait += 10 }
    if ($p650proc.HasExited) { Write-Output ('EDITOR650 EXIT ' + $p650proc.ExitCode) } else { Write-Output 'EDITOR650 STILL RUNNING AFTER 120 SECONDS LOG AND MAP READ BELOW BUILD SKIPPED WHILE EDITOR RUNS' }
} else { Write-Output 'EDITOR650 PREREQUISITE MISSING OR GUI EDITOR RUNNING RUN DEFERRED' }
if (Test-Path $p650log) {
  $p650logLines = @(Get-Content $p650log -ErrorAction SilentlyContinue | Select-String -Pattern 'ACTORS648|COUNTESS648|VAULT648|SAVE648' -ErrorAction SilentlyContinue)
  Write-Output ('LOG650 MATCH LINES ' + $p650logLines.Count)
  foreach ($p650l in $p650logLines) { Write-Output ('LOG650 ' + $p650l.Line) }
} else { Write-Output 'LOG650 MISSING' }
if (Test-Path $p650map) { Write-Output ('MAP650 AFTER EDITOR SIZE ' + (Get-Item $p650map).Length) } else { Write-Output 'MAP650 AFTER EDITOR MISSING' }
Write-Output 'LIGHTSPEED650 CARET LINES READ VERBATIM POW NOT CARET'
foreach ($p650r in @($p650run1, $p650run2)) {
  if (Test-Path $p650r) {
    $p650caret = @(Select-String -Path $p650r -Pattern 'phi\^' -ErrorAction SilentlyContinue)
    Write-Output ('CARET650 HITS ' + $p650caret.Count + ' IN ' + $p650r)
    foreach ($p650h in $p650caret) { Write-Output ('CARET650 LINE ' + $p650h.LineNumber + ' ' + $p650h.Line) }
  } else { Write-Output ('RUNNER650 MISSING ' + $p650r) }
}
$p650phi = 1.618033988749895
$p650testValue = 180952
$p650rung = [math]::Log($p650testValue) / [math]::Log($p650phi)
$p650back = [math]::Pow($p650phi, $p650rung)
Write-Output ('LIGHTSPEED650 PHI MATH RUNG ' + $p650rung + ' ROUNDTRIP ' + $p650back)
if ([math]::Abs($p650back - $p650testValue) -lt 1) { Write-Output 'LIGHTSPEED650 PHI MATH OK POW NOT CARET' } else { Write-Output 'LIGHTSPEED650 PHI MATH FAIL' }
if ((-not (Get-Process UnrealEditor-Cmd -ErrorAction SilentlyContinue)) -and (-not (Get-Process UnrealEditor -ErrorAction SilentlyContinue))) {
  Set-Location $p650batdir
  .\Build.bat VEILEditor Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build650.log'
  Write-Output ('BUILD650 EXIT ' + $LASTEXITCODE)
} else { Write-Output 'BUILD650 SKIPPED EDITOR PROCESS STILL RUNNING' }
if (Test-Path $p650map) {
  $p650afterSize = (Get-Item $p650map).Length
  Write-Output ('MAP650 AFTER SIZE ' + $p650afterSize)
  if ($p650afterSize -eq 180952) { Write-Output 'PROGRESS650 NO CHANGE NOT PROGRESS BUILD EXIT 0 ALONE IS NOT PROGRESS' } else { Write-Output 'PROGRESS650 CHANGED MAP SIZE MOVED' }
} else { Write-Output 'MAP650 AFTER MISSING' }
Write-Output 'AUTO650 HIDDENDRAIN TASK QUERY BELOW NO TYPED WORK GATE'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
Write-Output 'NOPACKAGE650 NO PACKAGE UNTIL 100 PERCENT DONE'
Write-Output 'JOB 650 DONE'
```
