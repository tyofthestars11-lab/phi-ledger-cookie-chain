<!-- PHI-DIRECT -->
# JOB 038 - VEIL V7 TARGET + REBUILD (DIRECT)

The engine named its requirement on Tyree's screen: BuildSettingsVersion
must be V7 for UE 5.8 (the target files shipped at V5). Both Target.cs
files are updated to V7 in the repo. This job refreshes the two files
into D:\VEIL, clears stale Intermediate, and starts the editor build
detached to build3 logs. Job 039 reads the outcome.

## STEP 1 - REFRESH TARGETS + DETACHED BUILD3
```powershell
$src = 'C:\Users\Admin\phi-vault\veil\VEIL\Source'; $dst = 'D:\VEIL'
Copy-Item "$src\VEIL.Target.cs" "$dst\Source\VEIL.Target.cs" -Force
Copy-Item "$src\VEILEditor.Target.cs" "$dst\Source\VEILEditor.Target.cs" -Force
"TARGET VERSION: " + (Select-String -Path "$dst\Source\VEILEditor.Target.cs" -Pattern 'BuildSettingsVersion\.\w+').Matches.Value
Remove-Item "$dst\Intermediate" -Recurse -Force -ErrorAction SilentlyContinue
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Remove-Item "$dst\build3-out.log","$dst\build3-err.log" -ErrorAction SilentlyContinue
$p = Start-Process -FilePath $build -ArgumentList 'VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput "$dst\build3-out.log" -RedirectStandardError "$dst\build3-err.log" -PassThru -WindowStyle Hidden
"BUILD3 STARTED detached, PID $($p.Id)"
```
