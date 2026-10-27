<!-- PHI-DIRECT -->
# JOB 043 - VEIL MODULE FILES + BUILD4 (DIRECT)

Build3's log named the last fault exactly: every .cpp died on
#include "VEIL.h" (fatal C1083) - the module header and the module
implementation were never in the project. Both now exist
(Public/VEIL.h with the log category, Private/VEIL.cpp with
IMPLEMENT_MODULE). This job refreshes them, cleans Intermediate,
and starts build4 detached to build4 logs. Job 044 reads the outcome.

## STEP 1 - REFRESH + CLEAN + BUILD4
```powershell
$src = 'C:\Users\Admin\phi-vault\veil\VEIL\Source\VEIL'; $dst = 'D:\VEIL\Source\VEIL'
Copy-Item "$src\Public\VEIL.h" "$dst\Public\VEIL.h" -Force
Copy-Item "$src\Private\VEIL.cpp" "$dst\Private\VEIL.cpp" -Force
"MODULE FILES: header=$(Test-Path "$dst\Public\VEIL.h") impl=$(Test-Path "$dst\Private\VEIL.cpp")"
Remove-Item 'D:\VEIL\Intermediate' -Recurse -Force -ErrorAction SilentlyContinue
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Remove-Item 'D:\VEIL\build4-out.log','D:\VEIL\build4-err.log' -ErrorAction SilentlyContinue
$p = Start-Process -FilePath $build -ArgumentList 'VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\VEIL\build4-out.log' -RedirectStandardError 'D:\VEIL\build4-err.log' -PassThru -WindowStyle Hidden
"BUILD4 STARTED detached, PID $($p.Id)"
```
