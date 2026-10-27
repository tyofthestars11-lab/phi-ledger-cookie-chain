<!-- PHI-DIRECT -->
# JOB 034 - VEIL BUILD OUTCOME READ (DIRECT, read only)

Reads the detached build that job 033 started: build log tail + error
lines, and whether the compiled module DLL now exists. If the DLL is
there, VEIL opens; if not, the error lines here are the fix list.

## STEP 1 - BUILD LOG + DLL CHECK
```powershell
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
"DLL EXISTS: $(Test-Path $dll)"
if (Test-Path $dll) { "DLL: " + (Get-Item $dll | Select-Object -ExpandProperty LastWriteTime) }
foreach ($l in 'D:\VEIL\build-out.log','D:\VEIL\build-err.log') {
  if (Test-Path $l) {
    "== $l (tail)"
    Get-Content $l -Tail 30
    "== error lines:"
    Select-String -Path $l -Pattern 'error C\d+|error :|Error:|BUILD FAILED|Total time' | Select-Object -Last 20 | ForEach-Object { $_.Line.Trim() }
  } else { "LOG ABSENT: $l (build not started yet)" }
}
```
