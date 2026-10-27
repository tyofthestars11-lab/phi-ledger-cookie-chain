<!-- PHI-DIRECT -->
# JOB 066 - BUILD VERDICT READ (DIRECT, SHORT)

Job 065's single block outran the runner's 240 s bound - its builds were
started detached and its verdict lines never got written. This job is
the read only: DLL times, log tails, error lines, live game windows.
Nothing builds, nothing launches, nothing closes.

```powershell
"=== VEIL build12 ==="
(Get-Item 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll' -ErrorAction SilentlyContinue).LastWriteTime
Get-Content 'D:\VEIL\build12-out.log' -Tail 4 -ErrorAction SilentlyContinue
Get-Content 'D:\VEIL\build12-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'error C|fatal error|Total execution time' | Select-Object -First 8 | ForEach-Object { $_.Line }
"=== OMNI build4 ==="
(Get-Item 'D:\OMNI-UE\Binaries\Win64\UnrealEditor-OMNI.dll' -ErrorAction SilentlyContinue).LastWriteTime
Get-Content 'D:\OMNI-UE\build4-out.log' -Tail 4 -ErrorAction SilentlyContinue
Get-Content 'D:\OMNI-UE\build4-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'error C|fatal error|Total execution time' | Select-Object -First 8 | ForEach-Object { $_.Line }
"=== GAME WINDOWS / LOGS ==="
Get-Process UnrealEditor -ErrorAction SilentlyContinue | ForEach-Object { "UnrealEditor pid=$($_.Id) window='$($_.MainWindowTitle)'" }
Get-Content 'D:\VEIL\Saved\Logs\VEIL.log' -Tail 400 -ErrorAction SilentlyContinue | Select-String -Pattern 'VEIL WORLD BUILT|VEIL world booted' | Select-Object -Last 3 | ForEach-Object { $_.Line }
Get-Content 'D:\OMNI-UE\Saved\Logs\OMNI.log' -Tail 400 -ErrorAction SilentlyContinue | Select-String -Pattern 'OMNI WORLD BUILT|OMNI QUEST|OMNI world booted' | Select-Object -Last 5 | ForEach-Object { $_.Line }
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
"BUILD PROCESSES STILL RUNNING: $(@($procs).Count)"
"=== JOB 066 DONE ==="
```
