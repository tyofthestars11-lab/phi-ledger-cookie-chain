<!-- PHI-DIRECT -->
# JOB 054 - VEIL: SYNC BUILD6 FIXES + REBUILD (DIRECT)

Build6 (job 052 read) cleared every old wall and failed on two real API
errors, both now fixed in the repo:
- Private/Game/VEILMainMenu.cpp: missing #include "Blueprint/WidgetTree.h"
  (UWidgetTree undefined; the ConstructWidget template errors cascaded).
- Private/AI/VEILFactionAI.cpp: EPathFollowingStatus::Moving is not a member
  in UE 5.8; replaced with a velocity check.
- Private/VEIL.cpp: IMPLEMENT_PRIMARY_GAME_MODULE now committed.
This job waits for an idle tree (job 053's closer may be mid-build), syncs
the three fixed files from the repo, and rebuilds incrementally.

```powershell
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
$waited = 0
while ($waited -lt 210) {
  $procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
  if (@($procs).Count -eq 0) { break }
  Start-Sleep -Seconds 30; $waited += 30
}
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
"WAITED: $waited s; BUILD PROCESSES: $(@($procs).Count); DLL EXISTS: $(Test-Path $dll)"
if (@($procs).Count -gt 0) { "HOLD: tree still busy - sync and build skipped this drain."; return }
$repo = 'C:\Users\Admin\phi-vault'
git -C $repo pull -q
$srcRoot = Join-Path $repo 'veil\VEIL\Source\VEIL'
foreach ($rel in @('Private\Game\VEILMainMenu.cpp', 'Private\AI\VEILFactionAI.cpp', 'Private\VEIL.cpp')) {
  Copy-Item (Join-Path $srcRoot $rel) (Join-Path 'D:\VEIL\Source\VEIL' $rel) -Force
  "SYNCED: $rel"
}
if (Test-Path $dll) { "DLL ALREADY STANDS - no build needed."; return }
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Remove-Item 'D:\VEIL\build8-out.log','D:\VEIL\build8-err.log' -ErrorAction SilentlyContinue
$p = Start-Process -FilePath $build -ArgumentList 'VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\VEIL\build8-out.log' -RedirectStandardError 'D:\VEIL\build8-err.log' -PassThru -WindowStyle Hidden
"BUILD8 STARTED detached, PID $($p.Id) - fixed sources, incremental."
```
