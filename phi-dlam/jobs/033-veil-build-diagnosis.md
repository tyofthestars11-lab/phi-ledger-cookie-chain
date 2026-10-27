<!-- PHI-DIRECT -->
# JOB 033 - VEIL BUILD DIAGNOSIS + DETACHED MANUAL BUILD (DIRECT)

Tyree opened D:\VEIL\VEIL.uproject, clicked Yes on "rebuild modules", and
got: "VEIL could not be compiled. Try rebuilding from source manually."
This job (1) checks whether Visual Studio / MSVC exists on the PC at all,
(2) reads the actual error lines from the build logs - the log is the
verdict, not a guess, and (3) starts the manual build DETACHED via the
engine's Build.bat with output to D:\VEIL\build-out.log so no job
timeout can kill it mid-compile. Job 034 reads the outcome.

## STEP 1 - TOOLCHAIN + ERROR LINES
```powershell
"VS2022 DIRS:"
foreach ($p in 'C:\Program Files\Microsoft Visual Studio\2022\Community','C:\Program Files\Microsoft Visual Studio\2022\Professional','C:\Program Files\Microsoft Visual Studio\2022\Enterprise','C:\Program Files\Microsoft Visual Studio\2022\BuildTools') { if (Test-Path $p) { "FOUND: $p" } }
$vswhere = 'C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe'
if (Test-Path $vswhere) { "VSWHERE: " + (& $vswhere -latest -products * -property displayName) ; "VC TOOLS: " + (& $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property displayName) }
$ubt = "$env:LOCALAPPDATA\UnrealBuildTool\Log.txt"
if (Test-Path $ubt) { "UBT LOG ERRORS:"; Select-String -Path $ubt -Pattern 'error|Error' | Select-Object -Last 25 | ForEach-Object { $_.Line.Trim() } }
$elog = Get-ChildItem 'D:\VEIL\Saved\Logs\*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($elog) { "EDITOR LOG: $($elog.Name)"; Select-String -Path $elog.FullName -Pattern 'error C|error:|LogCompile|failed' | Select-Object -Last 15 | ForEach-Object { $_.Line.Trim() } }
```

## STEP 2 - START THE MANUAL BUILD, DETACHED
```powershell
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
if (Test-Path $build) {
  Remove-Item 'D:\VEIL\build-out.log','D:\VEIL\build-err.log' -ErrorAction SilentlyContinue
  $p = Start-Process -FilePath $build -ArgumentList 'VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\VEIL\build-out.log' -RedirectStandardError 'D:\VEIL\build-err.log' -PassThru -WindowStyle Hidden
  "BUILD STARTED detached, PID $($p.Id) - outcome lands in D:\VEIL\build-out.log"
} else { "BUILD.BAT NOT FOUND at $build" }
```
