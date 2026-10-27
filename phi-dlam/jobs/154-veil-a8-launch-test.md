<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== VEIL A8 launch test (or state read if the cook is still running) ==="
$exe = Get-ChildItem "D:\Builds\VEIL-A8" -Recurse -Filter *.exe -ErrorAction SilentlyContinue | Where-Object { $_.Name -notmatch "CrashReport|UnrealCEF|EpicWebHelper" } | Select-Object -First 1
if ($exe) {
  Write-Output "packaged exe found: $($exe.FullName) ($([math]::Round($exe.Length/1MB,1)) MB)"
  $log = "D:\VEIL\Saved\Logs\phi-a8-launch.log"
  $p = Start-Process $exe.FullName -ArgumentList "-windowed", "-ResX=1280", "-ResY=720", "-abslog=$log", "-unattended", "-nosplash" -PassThru
  Start-Sleep -Seconds 40
  if (!$p.HasExited) { Stop-Process -Id $p.Id -Force; Write-Output "packaged game closed after dwell (launch held for the full window)" } else { Write-Output "packaged game exited on its own, code $($p.ExitCode)" }
  Start-Sleep -Seconds 3
  if (Test-Path $log) {
    Select-String -Path $log -Pattern "PHI MOVE TEST|PHI BODY CHECK|PHI VOICE|PHI CENSUS|Error" | Select-Object -First 60 | ForEach-Object { $_.Line }
  } else { Write-Output "no launch log at $log" }
} else {
  Write-Output "no packaged exe yet - A8 state instead:"
  $proc = Get-Process -Id 58244 -ErrorAction SilentlyContinue
  if ($proc) { Write-Output "A8 UAT still running: pid 58244, CPU $($proc.CPU)s" } else { Write-Output "A8 UAT process 58244: not running" }
  $uatLogs = Get-ChildItem "$env:APPDATA\Unreal Engine\AutomationTool\Logs" -Filter *.txt -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending
  if ($uatLogs) { Select-String -Path $uatLogs[0].FullName -Pattern "BUILD SUCCESSFUL|BUILD FAILED|ExitCode|Error:" | Select-Object -Last 15 | ForEach-Object { $_.Line }; Get-Content $uatLogs[0].FullName -Tail 4 }
}
Write-Output "=== JOB 154 DONE ==="
```
