<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== the same world, the same instruments, a TRUE standalone engine: build the OMNI GAME target and run its own exe ==="
$Build = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat"
& $Build OMNI Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex 2>&1 | Select-String "Result:|error" | Select-Object -First 8
$exe = "D:\OMNI-UE\Binaries\Win64\OMNI.exe"
if (Test-Path $exe) {
  Write-Output "standalone exe: $exe ($([math]::Round((Get-Item $exe).Length/1MB,1)) MB)"
  $p = Start-Process $exe -ArgumentList '/Game/Maps/OMNIWorld','-windowed','-resx=640','-resy=360','-abslog="D:\OMNI-UE\Saved\smoke-standalone.log"' -PassThru
  Start-Sleep -Seconds 30
  if (!$p.HasExited) { Stop-Process -Id $p.Id -Force -ErrorAction SilentlyContinue; Write-Output "standalone smoke closed after 30s" }
  Select-String -Path "D:\OMNI-UE\Saved\smoke-standalone.log" -Pattern "TICKPROOF|TIMER CHECK|GAMEMODE ALIVE|BODY CHECK|Traceback" | Select-Object -First 12 | ForEach-Object { $_.Line }
  $tk = Select-String -Path "D:\OMNI-UE\Saved\smoke-standalone.log" -Pattern "TICKPROOF" | Select-Object -Last 1
  if ($tk) {
    if ($tk.Line -match "worldTime=0\.00") { Write-Output "DECISION: the clock stands in the standalone engine too - the break is in the project/code, not the editor hosting" }
    if ($tk.Line -notmatch "worldTime=0\.00") { Write-Output "DECISION: world time ADVANCES in the standalone engine - the editor-binary hosting was the terrain; the packaged build is the true test" }
  }
} else { Write-Output "OMNI.exe not produced - the build lines above carry the reason" }
Write-Output "=== JOB 189 DONE ==="
```
