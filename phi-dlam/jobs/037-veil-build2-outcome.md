<!-- PHI-DIRECT -->
# JOB 037 - VEIL BUILD2 OUTCOME READ (DIRECT, read only)

## STEP 1 - BUILD2 LOG + DLL CHECK
```powershell
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
"DLL EXISTS: $(Test-Path $dll)"
if (Test-Path $dll) { $i = Get-Item $dll; "DLL: $($i.Length) bytes, written $($i.LastWriteTime)" }
foreach ($l in 'D:\VEIL\build2-out.log','D:\VEIL\build2-err.log') {
  if (Test-Path $l) {
    "== $l (tail)"; Get-Content $l -Tail 25
    "== error/result lines:"
    Select-String -Path $l -Pattern 'error C\d+|error :|Error:|Result:|Total time|BUILD' | Select-Object -Last 20 | ForEach-Object { $_.Line.Trim() }
  } else { "LOG ABSENT: $l (build2 not started yet)" }
}
```
