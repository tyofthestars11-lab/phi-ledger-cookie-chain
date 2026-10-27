<!-- PHI-DIRECT -->
# JOB 052 - VEIL BUILD6 OUTCOME READ (DIRECT)

Build6 started detached 2026-10-27 02:40 MDT (PID 33212) from the synced
clean source. Read its verdict: DLL, processes, log tails, first errors.

```powershell
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
"DLL EXISTS: $(Test-Path $dll)"
if (Test-Path $dll) { "DLL WRITTEN: $((Get-Item $dll).LastWriteTime) SIZE: $((Get-Item $dll).Length)" }
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
"BUILD PROCESSES RUNNING: $(@($procs).Count)"
foreach ($lg in @('D:\VEIL\build6-out.log', 'D:\VEIL\build6-err.log')) {
  if (Test-Path $lg) {
    "== $lg (modified $((Get-Item $lg).LastWriteTime))"
    Get-Content $lg -Tail 20
    "== FIRST ERROR LINES in $lg :"
    Select-String -Path $lg -Pattern 'error C|error :|Error:|Result: Failed' | Select-Object -First 20 | ForEach-Object { $_.Line }
  } else { "== $lg MISSING" }
}
```
