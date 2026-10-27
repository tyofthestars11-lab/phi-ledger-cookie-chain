<!-- PHI-DIRECT -->
# JOB 064 - VEIL PHI FIX CHAIN (DIRECT)

The fix, resumed from the checkpoint - never restarted: build10's failure
is fuel. This job syncs the hardened VEIL source (fog writes cut to the
engine-proven surface), rebuilds, and either launches the game and reads
the WORLD BUILT line, or captures the COMPLETE error block into this
result so the next fix is written from full evidence, not tails.

```powershell
Get-Process UnrealEditor -ErrorAction SilentlyContinue | ForEach-Object { $null = $_.CloseMainWindow() }
Start-Sleep -Seconds 5
Get-Process UnrealEditor -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
$repo = 'C:\Users\Admin\phi-vault'
git -C $repo pull -q
robocopy (Join-Path $repo 'veil\VEIL\Source') 'D:\VEIL\Source' /MIR /NFL /NDL /NJH | Out-Null
robocopy (Join-Path $repo 'veil\VEIL\Config') 'D:\VEIL\Config' /MIR /NFL /NDL /NJH | Out-Null
"SYNCED: VEIL Source + Config (phi-fix hardened)"
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Remove-Item 'D:\VEIL\build11-out.log','D:\VEIL\build11-err.log' -ErrorAction SilentlyContinue
$p = Start-Process -FilePath $build -ArgumentList 'VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\VEIL\build11-out.log' -RedirectStandardError 'D:\VEIL\build11-err.log' -PassThru -WindowStyle Hidden
"BUILD11 STARTED detached, PID $($p.Id)"
Start-Sleep -Seconds 200
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
$dllTime = (Get-Item $dll -ErrorAction SilentlyContinue).LastWriteTime
"AFTER 200 s: build processes=$(@($procs).Count) dll=$dllTime"
Get-Content 'D:\VEIL\build11-out.log' -Tail 3 -ErrorAction SilentlyContinue
$errLines = Get-Content 'D:\VEIL\build11-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'error|Error' | Select-Object -First 30 | ForEach-Object { $_.Line }
if ($errLines) { "--- BUILD11 ERROR BLOCK (full) ---"; $errLines }
if (@($procs).Count -eq 0 -and $dllTime -gt (Get-Date).AddMinutes(-8)) {
  $editor = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
  $g = Start-Process -FilePath $editor -ArgumentList '"D:\VEIL\VEIL.uproject" -game -windowed -ResX=1280 -ResY=720' -PassThru
  Start-Sleep -Seconds 45
  $g.Refresh()
  "VEIL GAME (phi-fix build): running=$(-not $g.HasExited) window='$($g.MainWindowTitle)' - LEFT OPEN for Tyree"
  Get-Content 'D:\VEIL\Saved\Logs\VEIL.log' -Tail 400 -ErrorAction SilentlyContinue | Select-String -Pattern 'VEIL WORLD BUILT|VEIL world booted|Error|Fatal' | Select-Object -Last 10 | ForEach-Object { $_.Line }
} else { "VEIL GAME: not launched - build11 failed or still running; the error block above is the fix's evidence." }
"=== JOB 064 DONE ==="
```
