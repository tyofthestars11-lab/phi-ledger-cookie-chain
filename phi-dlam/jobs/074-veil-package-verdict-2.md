<!-- PHI-DIRECT -->
# JOB 074 - VEIL PACKAGE VERDICT 2, FILES ONLY (DIRECT, SHORT)

REVISED per Tyree: no launching, no screen. Reads the restarted
packaging run home from its logs and the files on disk. States stay
separate: packaged is not launched; launched is not playable. The
playable confirmation is Tyree's open of the exe (or his screenshot).

```powershell
"=== UAT2 LOG ==="
Get-Content 'D:\VEIL\uat2-out.log' -ErrorAction SilentlyContinue | Select-String -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|ERROR:' | Select-Object -Last 6 | ForEach-Object { $_.Line }
Get-Content 'D:\VEIL\uat2-out.log' -Tail 4 -ErrorAction SilentlyContinue
$uat = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'AutomationTool|UnrealBuildTool' }
"UAT PROCESSES STILL RUNNING: $(@($uat).Count)"
$exe = Get-ChildItem 'D:\VEIL-Package' -Recurse -Filter 'VEIL.exe' -ErrorAction SilentlyContinue | Select-Object -First 1
if ($exe) {
  "PACKAGED EXE: $($exe.FullName) ($([math]::Round($exe.Length/1MB,2)) MB, $($exe.LastWriteTime))"
  $siblings = Get-ChildItem $exe.DirectoryName | Select-Object -First 12 | ForEach-Object { $_.Name }
  "BESIDE THE EXE: $($siblings -join ', ')"
  "STATE: packaged. NOT launched by this job (screen is Tyree's). Playable = unconfirmed until opened."
} else {
  "PACKAGED EXE: not found yet - packaging still running or failed; UAT lines above carry the state."
}
"=== JOB 074 DONE ==="
```
