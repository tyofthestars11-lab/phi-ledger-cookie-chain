<!-- PHI-DIRECT -->
# JOB 044 - VEIL BUILD4 OUTCOME READ (DIRECT, read only)

## STEP 1 - BUILD4 LOG + DLL CHECK
```powershell
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
"DLL EXISTS: $(Test-Path $dll)"
if (Test-Path $dll) { $i = Get-Item $dll; "DLL: $($i.Length) bytes, written $($i.LastWriteTime)" }
"BUILD PROCESSES RUNNING: $(@(Get-Process -Name dotnet -ErrorAction SilentlyContinue).Count)"
foreach ($l in 'D:\VEIL\build4-out.log','D:\VEIL\build4-err.log') {
  if (Test-Path $l) {
    "== $l (tail 40)"; Get-Content $l -Tail 40
    "== error/result lines:"
    Select-String -Path $l -Pattern 'error C\d+|error :|Error:|Result:|Total time|Total execution' | Select-Object -Last 25 | ForEach-Object { $_.Line.Trim() }
  } else { "LOG ABSENT: $l" }
}
```
