<!-- PHI-DIRECT -->
# JOB 042 - VEIL BUILD3 FINAL OUTCOME RE-READ (DIRECT, read only)

Job 039 read build3 three seconds after it started (same drain) - a
mid-flight snapshot, not a verdict. This re-read runs on a later drain,
when the build has had its minutes: the log will be complete and the
DLL either stands or the error lines name the next fix.

## STEP 1 - BUILD3 LOG (FULL TAIL) + DLL CHECK
```powershell
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
"DLL EXISTS: $(Test-Path $dll)"
if (Test-Path $dll) { $i = Get-Item $dll; "DLL: $($i.Length) bytes, written $($i.LastWriteTime)" }
$proc = Get-Process -Name dotnet -ErrorAction SilentlyContinue
"BUILD PROCESSES RUNNING: $(@($proc).Count)"
foreach ($l in 'D:\VEIL\build3-out.log','D:\VEIL\build3-err.log') {
  if (Test-Path $l) {
    "== $l (tail 40)"; Get-Content $l -Tail 40
    "== error/result lines:"
    Select-String -Path $l -Pattern 'error C\d+|error :|Error:|Result:|Total time|Total execution' | Select-Object -Last 25 | ForEach-Object { $_.Line.Trim() }
  } else { "LOG ABSENT: $l" }
}
```
