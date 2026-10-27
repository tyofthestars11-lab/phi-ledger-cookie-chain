<!-- PHI-DIRECT -->
# JOB 053 - VEIL ZERO-TOKEN CLOSER (DIRECT)

Tyree's word: the finish runs on this lane — zero brain calls, zero tokens —
so Rabbit can stand down. This job only acts on an IDLE tree: if a build is
running, it holds and reports (no collision). If the DLL already stands, it
reports victory. Only if no build is running AND the DLL is missing does it
swing the last lever: purge Binaries + Intermediate (kills poisoned UHT
cache), then start build7 from the clean synced source.

## STEP 1 - READ THE TREE
```powershell
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
"DLL EXISTS: $(Test-Path $dll)"
"BUILD PROCESSES RUNNING: $(@($procs).Count)"
if (Test-Path $dll) { "VERDICT: DLL STANDS - VEIL IS LIVE. size=$((Get-Item $dll).Length) written=$((Get-Item $dll).LastWriteTime)" }
elseif (@($procs).Count -gt 0) { "VERDICT: HOLD - a build is running on the tree; closer stands down, no purge." }
else { "VERDICT: TREE IDLE, NO DLL - closer swings in step 2." }
```

## STEP 2 - CONDITIONAL PURGE + BUILD7 (only when idle and DLL missing)
```powershell
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
if ((Test-Path $dll) -or @($procs).Count -gt 0) { "STEP 2 SKIPPED (see step 1 verdict)." }
else {
  Remove-Item 'D:\VEIL\Binaries' -Recurse -Force -ErrorAction SilentlyContinue
  Remove-Item 'D:\VEIL\Intermediate' -Recurse -Force -ErrorAction SilentlyContinue
  "PURGED: D:\VEIL\Binaries + D:\VEIL\Intermediate"
  $build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
  Remove-Item 'D:\VEIL\build7-out.log','D:\VEIL\build7-err.log' -ErrorAction SilentlyContinue
  $p = Start-Process -FilePath $build -ArgumentList 'VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\VEIL\build7-out.log' -RedirectStandardError 'D:\VEIL\build7-err.log' -PassThru -WindowStyle Hidden
  "BUILD7 STARTED detached, PID $($p.Id) - clean tree, clean cache, clean source."
}
```
