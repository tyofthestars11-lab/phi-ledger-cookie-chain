<!-- PHI-DIRECT -->
# JOB 055 - VEIL FINAL VERDICT SWEEP (DIRECT)

Last link in the zero-token finish chain (053 purge+build7, 054 fixes+build8).
Idempotent: if the DLL stands, report victory and do nothing. If a build is
running, hold. If the tree is idle and the DLL is still missing, sync the
three fixed files once more and run the final build. Then read the verdict
of whichever build log is newest.

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
if (Test-Path $dll) { "VERDICT: DLL STANDS - VEIL IS LIVE. size=$((Get-Item $dll).Length) written=$((Get-Item $dll).LastWriteTime)"; return }
if (@($procs).Count -gt 0) { "VERDICT: HOLD - build still running; verdict rides the next sweep."; return }
$repo = 'C:\Users\Admin\phi-vault'
git -C $repo pull -q
$srcRoot = Join-Path $repo 'veil\VEIL\Source\VEIL'
foreach ($rel in @('Private\Game\VEILMainMenu.cpp', 'Private\AI\VEILFactionAI.cpp', 'Private\VEIL.cpp')) {
  Copy-Item (Join-Path $srcRoot $rel) (Join-Path 'D:\VEIL\Source\VEIL' $rel) -Force
  "SYNCED: $rel"
}
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Remove-Item 'D:\VEIL\build9-out.log','D:\VEIL\build9-err.log' -ErrorAction SilentlyContinue
$p = Start-Process -FilePath $build -ArgumentList 'VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\VEIL\build9-out.log' -RedirectStandardError 'D:\VEIL\build9-err.log' -PassThru -WindowStyle Hidden
"BUILD9 STARTED detached, PID $($p.Id) - final build on fixed sources."
```
