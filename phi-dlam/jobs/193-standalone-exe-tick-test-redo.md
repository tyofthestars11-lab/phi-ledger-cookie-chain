<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== job 189's harness flaw: the exe existed but no proof lines were captured and the log was never checked. This redo instruments the harness itself. ==="
$exe = "D:\OMNI-UE\Binaries\Win64\OMNI.exe"
Write-Output "exe written: $((Get-Item $exe).LastWriteTime), size $([math]::Round((Get-Item $exe).Length/1MB,1)) MB"
$log = "D:\OMNI-UE\Saved\smoke-standalone2.log"
if (Test-Path $log) { Remove-Item $log -Force }
$p = Start-Process $exe -ArgumentList '/Game/Maps/OMNIWorld','-windowed','-resx=640','-resy=360',"-abslog=$log" -PassThru
Start-Sleep -Seconds 10
if ($p.HasExited) { Write-Output "exe EXITED within 10s, exit code: $($p.ExitCode)" } else { Write-Output "exe alive at 10s" }
Start-Sleep -Seconds 20
if (!$p.HasExited) { Stop-Process -Id $p.Id -Force -ErrorAction SilentlyContinue; Write-Output "standalone smoke closed after 30s" }
if (Test-Path $log) {
  Write-Output "log exists: $((Get-Item $log).Length) bytes"
  Select-String -Path $log -Pattern "TICKPROOF|TIMER CHECK|GAMEMODE ALIVE|BODY CHECK|LogTemp|Fatal|Error" | Select-Object -First 16 | ForEach-Object { $_.Line }
  $tk = Select-String -Path $log -Pattern "TICKPROOF" | Select-Object -Last 1
  if ($tk) {
    if ($tk.Line -match "worldTime=0\.00") { Write-Output "DECISION: the clock stands in the standalone engine too - the break is in the project/code, not the editor hosting" }
    if ($tk.Line -notmatch "worldTime=0\.00") { Write-Output "DECISION: world time ADVANCES in the standalone engine - the editor-binary hosting was the terrain; the packaged build is the true test" }
  } else { Write-Output "no TICKPROOF in the standalone log - the tail decides:"; Get-Content $log -Tail 12 | ForEach-Object { $_ } }
} else { Write-Output "NO LOG PRODUCED - the exe never reached logging; that absence is the result" }
Write-Output "=== JOB 193 DONE ==="
```
