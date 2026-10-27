<!-- PHI-DIRECT -->
# JOB 073 - VEIL PACKAGE: DIAGNOSE + RESTART (DIRECT, SHORT)

Job 070 found no packaged exe and no UAT process running - the first
packaging run ended without landing. This job reads the UAT log's own
error lines first, closes any editor/game process that could hold
files open, then starts BuildCookRun again, detached. Verdict: job 074.

```powershell
"=== FIRST PACKAGE RUN: UAT OUTCOME LINES ==="
Get-Content 'D:\VEIL\uat-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|ERROR|Error:' | Select-Object -Last 12 | ForEach-Object { $_.Line }
Get-Content 'D:\VEIL\uat-out.log' -Tail 6 -ErrorAction SilentlyContinue
Get-Content 'D:\VEIL\uat-err.log' -Tail 6 -ErrorAction SilentlyContinue
"=== D:\VEIL-Package TREE (top) ==="
Get-ChildItem 'D:\VEIL-Package' -ErrorAction SilentlyContinue | ForEach-Object { $_.Name }
Get-Process UnrealEditor -ErrorAction SilentlyContinue | ForEach-Object { $null = $_.CloseMainWindow() }
Start-Sleep -Seconds 5
Get-Process UnrealEditor -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
Remove-Item 'D:\VEIL\uat2-out.log','D:\VEIL\uat2-err.log' -ErrorAction SilentlyContinue
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$args = 'BuildCookRun -project="D:\VEIL\VEIL.uproject" -noP4 -platform=Win64 -clientconfig=Development -cook -build -stage -pak -archive -archivedirectory="D:\VEIL-Package" -unattended'
$p = Start-Process -FilePath $uat -ArgumentList $args -RedirectStandardOutput 'D:\VEIL\uat2-out.log' -RedirectStandardError 'D:\VEIL\uat2-err.log' -PassThru -WindowStyle Hidden
"PACKAGE RESTARTED detached, PID $($p.Id) -> D:\VEIL-Package"
Start-Sleep -Seconds 45
Get-Content 'D:\VEIL\uat2-out.log' -Tail 6 -ErrorAction SilentlyContinue
"=== JOB 073 DONE (package continues detached; verdict in job 074) ==="
```
