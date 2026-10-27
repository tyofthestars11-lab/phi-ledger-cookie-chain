<!-- PHI-DIRECT -->
# JOB 060 - OMNI RPG QUEST PORT: BUILD + SHOW (DIRECT)

The quest tranche landed in the repo after job 058 was queued: the quest
system (six-stage chain, phi XP ladder), WARDEN PRIME, talking statues,
fragments, the cache - all spawned by the GameMode. This job syncs the
OMNI Source, rebuilds, then launches OMNI with -game and reads the log
for the quest system's own lines. If build1 (job 058) is still running,
this job waits for the drain first.

```powershell
$waited = 0
while ($waited -lt 180) {
  $procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
  if (@($procs).Count -eq 0) { break }
  Start-Sleep -Seconds 25; $waited += 25
}
"BUILD DRAIN WAITED: $waited s"
$repo = 'C:\Users\Admin\phi-vault'
git -C $repo pull -q
robocopy (Join-Path $repo 'veil\OMNI\Source') 'D:\OMNI-UE\Source' /MIR /NFL /NDL /NJH | Out-Null
robocopy (Join-Path $repo 'veil\OMNI\Config') 'D:\OMNI-UE\Config' /MIR /NFL /NDL /NJH | Out-Null
"SYNCED: OMNI Source + Config (quest tranche)"
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$p = Start-Process -FilePath $build -ArgumentList 'OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\OMNI-UE\build2-out.log' -RedirectStandardError 'D:\OMNI-UE\build2-err.log' -PassThru -WindowStyle Hidden
"BUILD2 STARTED detached, PID $($p.Id)"
Start-Sleep -Seconds 170
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
$dll = 'D:\OMNI-UE\Binaries\Win64\UnrealEditor-OMNI.dll'
"AFTER 170 s: build processes=$(@($procs).Count) dll=$((Get-Item $dll -ErrorAction SilentlyContinue).LastWriteTime)"
Get-Content 'D:\OMNI-UE\build2-out.log' -Tail 4 -ErrorAction SilentlyContinue
Get-Content 'D:\OMNI-UE\build2-err.log' -Tail 4 -ErrorAction SilentlyContinue
if (@($procs).Count -eq 0 -and (Test-Path $dll)) {
  $editor = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
  $g = Start-Process -FilePath $editor -ArgumentList '"D:\OMNI-UE\OMNI.uproject" -game -windowed -ResX=1280 -ResY=720' -PassThru
  Start-Sleep -Seconds 45
  $g.Refresh()
  "OMNI GAME (quest build): running=$(-not $g.HasExited) window='$($g.MainWindowTitle)'"
  Get-Content 'D:\OMNI-UE\Saved\Logs\OMNI.log' -Tail 400 -ErrorAction SilentlyContinue | Select-String -Pattern 'OMNI WORLD BUILT|OMNI QUEST|Error|Fatal' | Select-Object -Last 12 | ForEach-Object { $_.Line }
  if (-not $g.HasExited) { $null = $g.CloseMainWindow(); Start-Sleep -Seconds 3; if (-not $g.HasExited) { Stop-Process -Id $g.Id -Force -ErrorAction SilentlyContinue } }
  "OMNI game closed after verdict."
} else { "OMNI GAME: not launched - build still running or DLL missing; verdict rides the next sweep." }
"=== JOB 060 DONE ==="
```
