<!-- PHI-DIRECT -->
# JOB 074 - VEIL PACKAGE VERDICT 2 + EXE TEST (DIRECT, SHORT)

Reads the restarted packaging run (uat2 logs) home: outcome lines, the
packaged .exe on disk, and a live launch test of the standalone game.

```powershell
"=== UAT2 LOG ==="
Get-Content 'D:\VEIL\uat2-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|ERROR:' | Select-Object -Last 6 | ForEach-Object { $_.Line }
Get-Content 'D:\VEIL\uat2-out.log' -Tail 4 -ErrorAction SilentlyContinue
$uat = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'AutomationTool|UnrealBuildTool' }
"UAT PROCESSES STILL RUNNING: $(@($uat).Count)"
$exe = Get-ChildItem 'D:\VEIL-Package' -Recurse -Filter 'VEIL.exe' -ErrorAction SilentlyContinue | Select-Object -First 1
if ($exe) {
  "PACKAGED EXE: $($exe.FullName) ($([math]::Round($exe.Length/1MB,2)) MB, $($exe.LastWriteTime))"
  $g = Start-Process -FilePath $exe.FullName -PassThru
  Start-Sleep -Seconds 40
  $g.Refresh()
  "PACKAGED VEIL RUNNING: $(-not $g.HasExited) window='$($g.MainWindowTitle)' - LEFT OPEN for Tyree"
} else {
  "PACKAGED EXE: not found yet - packaging still running or failed; UAT lines above carry the state."
}
"=== JOB 074 DONE ==="
```
