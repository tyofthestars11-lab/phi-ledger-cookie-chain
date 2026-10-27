<!-- PHI-DIRECT -->
# JOB 073 - VEIL PACKAGE: DIAGNOSE + BACKGROUND RESTART (DIRECT)

REVISED per Tyree: no taking over the PC screen. Nothing gets closed,
nothing launches a window. This job syncs VEIL (fog-safe builder,
1st/3rd camera toggle, PHI LICENSE), reads the first packaging run's
own error lines, and starts BuildCookRun again in the background.
Verdict (files only, no launch): job 074.

```powershell
$repo = 'C:\Users\Admin\phi-vault'
git -C $repo pull -q
robocopy (Join-Path $repo 'veil\VEIL\Source') 'D:\VEIL\Source' /MIR /NFL /NDL /NJH | Out-Null
robocopy (Join-Path $repo 'veil\VEIL\Config') 'D:\VEIL\Config' /MIR /NFL /NDL /NJH | Out-Null
Copy-Item (Join-Path $repo 'veil\VEIL\PHI-LICENSE.md') 'D:\VEIL\PHI-LICENSE.md' -Force
"SYNCED: VEIL Source + Config + PHI-LICENSE (camera toggle, license)"
"=== FIRST PACKAGE RUN: UAT OUTCOME LINES ==="
Get-Content 'D:\VEIL\uat-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|ERROR|Error:' | Select-Object -Last 12 | ForEach-Object { $_.Line }
Get-Content 'D:\VEIL\uat-out.log' -Tail 6 -ErrorAction SilentlyContinue
Get-Content 'D:\VEIL\uat-err.log' -Tail 6 -ErrorAction SilentlyContinue
"=== D:\VEIL-Package TREE (top) ==="
Get-ChildItem 'D:\VEIL-Package' -ErrorAction SilentlyContinue | ForEach-Object { $_.Name }
Remove-Item 'D:\VEIL\uat2-out.log','D:\VEIL\uat2-err.log' -ErrorAction SilentlyContinue
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$args = 'BuildCookRun -project="D:\VEIL\VEIL.uproject" -noP4 -platform=Win64 -clientconfig=Development -cook -build -stage -pak -archive -archivedirectory="D:\VEIL-Package" -unattended'
$p = Start-Process -FilePath $uat -ArgumentList $args -RedirectStandardOutput 'D:\VEIL\uat2-out.log' -RedirectStandardError 'D:\VEIL\uat2-err.log' -PassThru -WindowStyle Hidden
"PACKAGE RESTARTED detached (background, no window), PID $($p.Id) -> D:\VEIL-Package"
Start-Sleep -Seconds 45
Get-Content 'D:\VEIL\uat2-out.log' -Tail 6 -ErrorAction SilentlyContinue
"=== JOB 073 DONE (package continues detached; verdict in job 074) ==="
```
