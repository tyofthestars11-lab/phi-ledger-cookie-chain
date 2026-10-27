<!-- PHI-DIRECT -->
# JOB 069 - VEIL PACKAGE START (DIRECT)

A real game is a packaged game: a standalone .exe, no editor. This job
starts Unreal's BuildCookRun for VEIL into D:\VEIL-Package, detached -
cooking takes minutes, so the verdict rides job 070. Short block.

```powershell
$dll = (Get-Item 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll' -ErrorAction SilentlyContinue).LastWriteTime
"VEIL DLL: $dll"
Remove-Item 'D:\VEIL\uat-out.log','D:\VEIL\uat-err.log' -ErrorAction SilentlyContinue
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$args = 'BuildCookRun -project="D:\VEIL\VEIL.uproject" -noP4 -platform=Win64 -clientconfig=Development -cook -build -stage -pak -archive -archivedirectory="D:\VEIL-Package" -unattended'
$p = Start-Process -FilePath $uat -ArgumentList $args -RedirectStandardOutput 'D:\VEIL\uat-out.log' -RedirectStandardError 'D:\VEIL\uat-err.log' -PassThru -WindowStyle Hidden
"PACKAGE STARTED detached, PID $($p.Id) -> D:\VEIL-Package"
Start-Sleep -Seconds 60
Get-Content 'D:\VEIL\uat-out.log' -Tail 6 -ErrorAction SilentlyContinue
"=== JOB 069 DONE (package continues detached; verdict in job 070) ==="
```
