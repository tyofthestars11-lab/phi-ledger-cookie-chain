<!-- PHI-DIRECT -->
# JOB 065 - BOTH GAMES: ATMOSPHERE FIX, REBUILD, SHOW (DIRECT)

Forensics (job 062) named the killer verbatim, in both games:
fatal error C1083: 'Atmosphere/SkyAtmosphere.h' - that header path does
not exist in UE 5.8. The builders now carry the atmosphere as a
USkyAtmosphereComponent (Components/SkyAtmosphereComponent.h). This job
syncs both projects, rebuilds both, and launches each game that stands,
reading its own WORLD BUILT line back from its log.

```powershell
Get-Process UnrealEditor -ErrorAction SilentlyContinue | ForEach-Object { $null = $_.CloseMainWindow() }
Start-Sleep -Seconds 5
Get-Process UnrealEditor -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
$repo = 'C:\Users\Admin\phi-vault'
git -C $repo pull -q
robocopy (Join-Path $repo 'veil\VEIL\Source') 'D:\VEIL\Source' /MIR /NFL /NDL /NJH | Out-Null
robocopy (Join-Path $repo 'veil\VEIL\Config') 'D:\VEIL\Config' /MIR /NFL /NDL /NJH | Out-Null
robocopy (Join-Path $repo 'veil\OMNI\Source') 'D:\OMNI-UE\Source' /MIR /NFL /NDL /NJH | Out-Null
robocopy (Join-Path $repo 'veil\OMNI\Config') 'D:\OMNI-UE\Config' /MIR /NFL /NDL /NJH | Out-Null
robocopy (Join-Path $repo 'veil\OMNI\OMNI.uproject') 'D:\OMNI-UE' /NFL /NDL /NJH | Out-Null
"SYNCED: VEIL + OMNI Source/Config (atmosphere fix)"
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$editor = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
Remove-Item 'D:\VEIL\build12-out.log','D:\VEIL\build12-err.log' -ErrorAction SilentlyContinue
$p1 = Start-Process -FilePath $build -ArgumentList 'VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\VEIL\build12-out.log' -RedirectStandardError 'D:\VEIL\build12-err.log' -PassThru -WindowStyle Hidden
"BUILD12 (VEIL) STARTED detached, PID $($p1.Id)"
Start-Sleep -Seconds 200
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
$vdll = (Get-Item 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll' -ErrorAction SilentlyContinue).LastWriteTime
"VEIL AFTER 200 s: build processes=$(@($procs).Count) dll=$vdll"
Get-Content 'D:\VEIL\build12-out.log' -Tail 3 -ErrorAction SilentlyContinue
$e1 = Get-Content 'D:\VEIL\build12-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'error C|fatal error' | Select-Object -First 15 | ForEach-Object { $_.Line }
if ($e1) { "--- BUILD12 ERRORS ---"; $e1 }
if (@($procs).Count -eq 0 -and $vdll -gt (Get-Date).AddMinutes(-8)) {
  $g = Start-Process -FilePath $editor -ArgumentList '"D:\VEIL\VEIL.uproject" -game -windowed -ResX=1280 -ResY=720' -PassThru
  Start-Sleep -Seconds 45
  $g.Refresh()
  "VEIL GAME (build12): running=$(-not $g.HasExited) window='$($g.MainWindowTitle)' - LEFT OPEN for Tyree"
  Get-Content 'D:\VEIL\Saved\Logs\VEIL.log' -Tail 400 -ErrorAction SilentlyContinue | Select-String -Pattern 'VEIL WORLD BUILT|VEIL world booted|Error|Fatal' | Select-Object -Last 8 | ForEach-Object { $_.Line }
  Stop-Process -Id $g.Id -Force -ErrorAction SilentlyContinue
  "VEIL game closed after verdict read (OMNI build needs the machine)"
} else { "VEIL GAME: not launched - build12 failed or still running." }
Remove-Item 'D:\OMNI-UE\build4-out.log','D:\OMNI-UE\build4-err.log' -ErrorAction SilentlyContinue
$p2 = Start-Process -FilePath $build -ArgumentList 'OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\OMNI-UE\build4-out.log' -RedirectStandardError 'D:\OMNI-UE\build4-err.log' -PassThru -WindowStyle Hidden
"BUILD4 (OMNI) STARTED detached, PID $($p2.Id)"
Start-Sleep -Seconds 200
$procs2 = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
$odll = (Get-Item 'D:\OMNI-UE\Binaries\Win64\UnrealEditor-OMNI.dll' -ErrorAction SilentlyContinue).LastWriteTime
"OMNI AFTER 200 s: build processes=$(@($procs2).Count) dll=$odll"
Get-Content 'D:\OMNI-UE\build4-out.log' -Tail 3 -ErrorAction SilentlyContinue
$e2 = Get-Content 'D:\OMNI-UE\build4-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'error C|fatal error' | Select-Object -First 15 | ForEach-Object { $_.Line }
if ($e2) { "--- BUILD4 ERRORS ---"; $e2 }
if (@($procs2).Count -eq 0 -and $odll -gt (Get-Date).AddMinutes(-8)) {
  $g2 = Start-Process -FilePath $editor -ArgumentList '"D:\OMNI-UE\OMNI.uproject" -game -windowed -ResX=1280 -ResY=720' -PassThru
  Start-Sleep -Seconds 45
  $g2.Refresh()
  "OMNI GAME (build4): running=$(-not $g2.HasExited) window='$($g2.MainWindowTitle)' - LEFT OPEN for Tyree"
  Get-Content 'D:\OMNI-UE\Saved\Logs\OMNI.log' -Tail 400 -ErrorAction SilentlyContinue | Select-String -Pattern 'OMNI WORLD BUILT|OMNI QUEST|OMNI world booted|Error|Fatal' | Select-Object -Last 10 | ForEach-Object { $_.Line }
} else { "OMNI GAME: not launched - build4 failed or still running." }
"=== JOB 065 DONE ==="
```
