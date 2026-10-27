# Job 204 — Recover job 200's script output from the full console file already on disk

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$console = 'D:\VEIL\Saved\abp-deep-console.txt'
Write-Output '=== Job 200s commandlet exited 1 and its result printed only the console TAIL - the ABPDEEP lines (or the Python traceback that explains their absence) live in the full console file already on this disk. This job is a pure read of that file: every ABPDEEP line, every LogPython line, every Traceback block. No new runs. ==='
if (Test-Path $console) {
  Write-Output "console file: $((Get-Item $console).Length) bytes, $((Get-Content $console | Measure-Object -Line).Lines) lines"
  Write-Output '--- ABPDEEP / LogPython / Traceback lines ---'
  Select-String -Path $console -Pattern 'ABPDEEP|LogPython|Traceback' | ForEach-Object { $_.Line }
  Write-Output '--- last 15 lines of the file ---'
  Get-Content $console -Tail 15
} else {
  Write-Output 'console file ABSENT - job 200s capture never landed either; the read reruns with the next tranche'
}
```
