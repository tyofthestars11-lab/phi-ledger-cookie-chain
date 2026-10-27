<!-- PHI-DIRECT -->
# JOB 067 - VEIL REAL-GAME BUILD 13 + SHOW (DIRECT)

The real-game tranche: the builder now purges the template map's own
sun/sky/fog/floor before building (one rig, one city), towers carry a
city palette + lit floor bands, fog deepened for dusk. Sync, rebuild,
launch, read WORLD BUILT back.

```powershell
Get-Process UnrealEditor -ErrorAction SilentlyContinue | ForEach-Object { $null = $_.CloseMainWindow() }
Start-Sleep -Seconds 5
Get-Process UnrealEditor -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
$repo = 'C:\Users\Admin\phi-vault'
git -C $repo pull -q
robocopy (Join-Path $repo 'veil\VEIL\Source') 'D:\VEIL\Source' /MIR /NFL /NDL /NJH | Out-Null
robocopy (Join-Path $repo 'veil\VEIL\Config') 'D:\VEIL\Config' /MIR /NFL /NDL /NJH | Out-Null
"SYNCED: VEIL Source + Config (real-game tranche)"
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Remove-Item 'D:\VEIL\build13-out.log','D:\VEIL\build13-err.log' -ErrorAction SilentlyContinue
$p = Start-Process -FilePath $build -ArgumentList 'VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\VEIL\build13-out.log' -RedirectStandardError 'D:\VEIL\build13-err.log' -PassThru -WindowStyle Hidden
"BUILD13 STARTED detached, PID $($p.Id)"
Start-Sleep -Seconds 190
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
$dll = (Get-Item 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll' -ErrorAction SilentlyContinue).LastWriteTime
"AFTER 190 s: build processes=$(@($procs).Count) dll=$dll"
Get-Content 'D:\VEIL\build13-out.log' -Tail 3 -ErrorAction SilentlyContinue
$e = Get-Content 'D:\VEIL\build13-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'error C|fatal error' | Select-Object -First 15 | ForEach-Object { $_.Line }
if ($e) { "--- BUILD13 ERRORS ---"; $e }
if (@($procs).Count -eq 0 -and $dll -gt (Get-Date).AddMinutes(-8)) {
  $editor = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
  $g = Start-Process -FilePath $editor -ArgumentList '"D:\VEIL\VEIL.uproject" -game -windowed -ResX=1280 -ResY=720' -PassThru
  Start-Sleep -Seconds 40
  $g.Refresh()
  "VEIL GAME (build13, real-game tranche): running=$(-not $g.HasExited) window='$($g.MainWindowTitle)' - LEFT OPEN for Tyree"
  Get-Content 'D:\VEIL\Saved\Logs\VEIL.log' -Tail 400 -ErrorAction SilentlyContinue | Select-String -Pattern 'VEIL WORLD BUILT|VEIL world booted|Error|Fatal|competing' | Select-Object -Last 8 | ForEach-Object { $_.Line }
} else { "VEIL GAME: not launched - build13 failed or still running." }
"=== JOB 067 DONE ==="
```
