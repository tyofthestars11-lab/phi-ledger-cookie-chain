<!-- PHI-DIRECT -->
# JOB 036 - VEIL FIX REFRESH + CLEAN REBUILD (DIRECT)

Job 033's log named the faults exactly: (1) UHT rejected two manager
class names - a WorldSubsystem needs the U prefix (UVEILFactionManager,
UVEILDiscoveryManager), they shipped with A; (2) the project was missing
its target rules files (VEIL.Target.cs / VEILEditor.Target.cs), so the
editor target had no rules at all; (3) an invalid ProjectID GUID. All
fixed in the source and committed under veil/. This job refreshes
D:\VEIL from the repo, clears the stale Intermediate/Binaries so the
build is clean, and starts the editor build detached, logging to
D:\VEIL\build2-out.log (+ .err). Job 037 reads the outcome.

## STEP 1 - REFRESH + CLEAN + DETACHED BUILD
```powershell
$src = 'C:\Users\Admin\phi-vault\veil\VEIL'; $dst = 'D:\VEIL'
robocopy $src $dst /E /NFL /NDL /NJH /NJS | Out-Null
"TARGET FILES: game=$(Test-Path "$dst\Source\VEIL.Target.cs") editor=$(Test-Path "$dst\Source\VEILEditor.Target.cs")"
"PREFIX CHECK: " + (Select-String -Path "$dst\Source\VEIL\Public\AI\VEILFactionAI.h" -Pattern 'UVEILFactionManager' -Quiet)
Remove-Item "$dst\Intermediate" -Recurse -Force -ErrorAction SilentlyContinue
Remove-Item "$dst\Binaries" -Recurse -Force -ErrorAction SilentlyContinue
"CLEANED Intermediate + Binaries"
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Remove-Item "$dst\build2-out.log","$dst\build2-err.log" -ErrorAction SilentlyContinue
$p = Start-Process -FilePath $build -ArgumentList 'VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput "$dst\build2-out.log" -RedirectStandardError "$dst\build2-err.log" -PassThru -WindowStyle Hidden
"BUILD2 STARTED detached, PID $($p.Id)"
```
