<!-- PHI-DIRECT -->
# JOB 062 - BUILD ERROR FORENSICS (DIRECT)

Jobs 057/058/060 came back Failed (OtherCompilationError) but the result
tails cut the actual error lines. Pull them from the logs on disk:
build10 (VEIL world tranche - ran 31.76 s, a real compile error) and the
OMNI build1/build2 logs (failed in under a second - a startup cause).
Read-only: report the error lines verbatim, change nothing.

```powershell
"--- VEIL build10-out: error lines ---"
Get-Content 'D:\VEIL\build10-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'error|Error' | Select-Object -First 25 | ForEach-Object { $_.Line }
"--- VEIL build10-err: all ---"
Get-Content 'D:\VEIL\build10-err.log' -ErrorAction SilentlyContinue | Select-Object -First 25
"--- OMNI build1-out: all (short) ---"
Get-Content 'D:\OMNI-UE\build1-out.log' -ErrorAction SilentlyContinue | Select-Object -First 40
"--- OMNI build1-err: all ---"
Get-Content 'D:\OMNI-UE\build1-err.log' -ErrorAction SilentlyContinue | Select-Object -First 25
"--- OMNI build2-out: error lines ---"
Get-Content 'D:\OMNI-UE\build2-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'error|Error' | Select-Object -First 15 | ForEach-Object { $_.Line }
"--- OMNI staged tree check ---"
Get-ChildItem 'D:\OMNI-UE' | ForEach-Object { $_.Name }
Get-Content 'D:\OMNI-UE\OMNI.uproject' -ErrorAction SilentlyContinue
"=== JOB 062 DONE ==="
```
