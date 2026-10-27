<!-- PHI-DIRECT -->
# JOB 048 - VEIL PHI FIX: NAME THE ERROR, RESUME THE BUILD (DIRECT)

Tyree's word (2026-10-26 ~23:31 MDT): "just fix and continue."
R1 is stuck on a syntax error from the Unreal side. This job reads the
build's own logs — the first error line is the address — and resumes the
build from its checkpoint if nothing is running (UBT is incremental:
compiled actions are cached, the build continues, it never restarts).

## STEP 1 - FORENSICS: DLL, PROCESSES, FIRST ERRORS VERBATIM
```powershell
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
"DLL EXISTS: $(Test-Path $dll)"
if (Test-Path $dll) { "DLL WRITTEN: $((Get-Item $dll).LastWriteTime) SIZE: $((Get-Item $dll).Length)" }
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
"BUILD PROCESSES RUNNING: $(@($procs).Count)"
$logs = @('D:\VEIL\build4-out.log', 'D:\VEIL\build4-err.log', 'C:\Users\Admin\AppData\Local\UnrealBuildTool\Log.txt', 'D:\VEIL\Saved\Logs\VEIL.log')
foreach ($lg in $logs) {
  if (Test-Path $lg) {
    "== $lg (modified $((Get-Item $lg).LastWriteTime))"
    Get-Content $lg -Tail 25
    "== ERROR LINES in $lg :"
    Select-String -Path $lg -Pattern 'error|Error|ERROR|failed|Failed' | Select-Object -First 30 | ForEach-Object { $_.Line }
  } else { "== $lg MISSING" }
}
```

## STEP 2 - RESUME FROM CHECKPOINT IF THE BUILD IS DOWN AND THE DLL IS MISSING
```powershell
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet' }
if ((Test-Path $dll)) { "PHI FIX: DLL STANDS - nothing to resume." }
elseif (@($procs).Count -gt 0) { "PHI FIX: a build is already running ($(@($procs).Count) processes) - UBT -WaitMutex holds the line; no second launch." }
else {
  $build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
  Remove-Item 'D:\VEIL\build5-out.log','D:\VEIL\build5-err.log' -ErrorAction SilentlyContinue
  $p = Start-Process -FilePath $build -ArgumentList 'VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\VEIL\build5-out.log' -RedirectStandardError 'D:\VEIL\build5-err.log' -PassThru -WindowStyle Hidden
  "BUILD5 RESUMED detached, PID $($p.Id) - incremental from the build4 checkpoint."
}
```
