<!-- PHI-DIRECT -->
# JOB 057 - VEIL WORLD BUILD (DIRECT)

Tyree's verdict (2026-10-27): VEIL opens to an empty Untitled map - the
module compiled but the game was never in it. The repo now carries the
world tranche: AVEILWorldBuilder (district + dusk rig + plaza + beacon),
GlobalDefaultGameMode wiring, visible runner + machine bodies. This job:
close the editor (DLL lock), sync Source + Config to D:\VEIL, start the
rebuild detached, and report the build's state.

```powershell
Get-Process UnrealEditor -ErrorAction SilentlyContinue | ForEach-Object { $null = $_.CloseMainWindow() }
Start-Sleep -Seconds 5
Get-Process UnrealEditor -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
$repo = 'C:\Users\Admin\phi-vault'
git -C $repo pull -q
robocopy (Join-Path $repo 'veil\VEIL\Source') 'D:\VEIL\Source' /MIR /NFL /NDL /NJH | Out-Null
robocopy (Join-Path $repo 'veil\VEIL\Config') 'D:\VEIL\Config' /MIR /NFL /NDL /NJH | Out-Null
"SYNCED: VEIL Source + Config (world tranche)"
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Remove-Item 'D:\VEIL\build10-out.log','D:\VEIL\build10-err.log' -ErrorAction SilentlyContinue
$p = Start-Process -FilePath $build -ArgumentList 'VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\VEIL\build10-out.log' -RedirectStandardError 'D:\VEIL\build10-err.log' -PassThru -WindowStyle Hidden
"BUILD10 STARTED detached, PID $($p.Id)"
Start-Sleep -Seconds 150
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
"AFTER 150 s: build processes=$(@($procs).Count) dll=$((Get-Item $dll -ErrorAction SilentlyContinue).LastWriteTime)"
Get-Content 'D:\VEIL\build10-out.log' -Tail 4 -ErrorAction SilentlyContinue
"=== JOB 057 DONE (verdict sweep is job 059) ==="
```
