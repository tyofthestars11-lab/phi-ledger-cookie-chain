<!-- PHI-DIRECT -->
# JOB 039 - VEIL BUILD3 OUTCOME READ (DIRECT, read only)

## STEP 1 - BUILD3 LOG + DLL CHECK
```powershell
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
"DLL EXISTS: $(Test-Path $dll)"
if (Test-Path $dll) { $i = Get-Item $dll; "DLL: $($i.Length) bytes, written $($i.LastWriteTime)" }
foreach ($l in 'D:\VEIL\build3-out.log','D:\VEIL\build3-err.log') {
  if (Test-Path $l) {
    "== $l (tail)"; Get-Content $l -Tail 25
    "== error/result lines:"
    Select-String -Path $l -Pattern 'error C\d+|error :|Error:|Result:|Total time|warning C' | Select-Object -Last 25 | ForEach-Object { $_.Line.Trim() }
  } else { "LOG ABSENT: $l (build3 not started yet)" }
}
```
