<!-- PHI-DIRECT -->
# JOB 072 - OMNI FOG FIX: BUILD 6 + SHOW (DIRECT)

Build5's killer, verbatim from job 068: error C2039 -
'FogInscatteringColor' is not a member of
UExponentialHeightFogComponent in UE 5.8 (OMNIWorldBuilder.cpp line
123). Those fog member writes are now cut; density only, same as VEIL.
Sync, rebuild, launch, read the quest lines back.

```powershell
Get-Process UnrealEditor -ErrorAction SilentlyContinue | ForEach-Object { $null = $_.CloseMainWindow() }
Start-Sleep -Seconds 5
Get-Process UnrealEditor -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
$repo = 'C:\Users\Admin\phi-vault'
git -C $repo pull -q
robocopy (Join-Path $repo 'veil\OMNI\Source') 'D:\OMNI-UE\Source' /MIR /NFL /NDL /NJH | Out-Null
robocopy (Join-Path $repo 'veil\OMNI\Config') 'D:\OMNI-UE\Config' /MIR /NFL /NDL /NJH | Out-Null
robocopy (Join-Path $repo 'veil\OMNI\OMNI.uproject') 'D:\OMNI-UE' /NFL /NDL /NJH | Out-Null
"SYNCED: OMNI Source + Config + uproject (fog fix)"
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Remove-Item 'D:\OMNI-UE\build6-out.log','D:\OMNI-UE\build6-err.log' -ErrorAction SilentlyContinue
$p = Start-Process -FilePath $build -ArgumentList 'OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\OMNI-UE\build6-out.log' -RedirectStandardError 'D:\OMNI-UE\build6-err.log' -PassThru -WindowStyle Hidden
"BUILD6 STARTED detached, PID $($p.Id)"
Start-Sleep -Seconds 150
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
$dll = (Get-Item 'D:\OMNI-UE\Binaries\Win64\UnrealEditor-OMNI.dll' -ErrorAction SilentlyContinue).LastWriteTime
"AFTER 150 s: build processes=$(@($procs).Count) dll=$dll"
Get-Content 'D:\OMNI-UE\build6-out.log' -Tail 3 -ErrorAction SilentlyContinue
$e = Get-Content 'D:\OMNI-UE\build6-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'error C|fatal error' | Select-Object -First 15 | ForEach-Object { $_.Line }
if ($e) { "--- BUILD6 ERRORS ---"; $e }
if (@($procs).Count -eq 0 -and $dll -gt (Get-Date).AddMinutes(-6)) {
  $editor = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
  $g = Start-Process -FilePath $editor -ArgumentList '"D:\OMNI-UE\OMNI.uproject" -game -windowed -ResX=1280 -ResY=720' -PassThru
  Start-Sleep -Seconds 40
  $g.Refresh()
  "OMNI GAME (build6, fog fix): running=$(-not $g.HasExited) window='$($g.MainWindowTitle)' - LEFT OPEN for Tyree"
  Get-Content 'D:\OMNI-UE\Saved\Logs\OMNI.log' -Tail 400 -ErrorAction SilentlyContinue | Select-String -Pattern 'OMNI WORLD BUILT|OMNI QUEST|OMNI world booted|Error|Fatal|competing' | Select-Object -Last 10 | ForEach-Object { $_.Line }
} else { "OMNI GAME: not launched - build6 failed or still running." }
"=== JOB 072 DONE ==="
```
