<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== sync source (TICKPROOF v3), build BOTH fully, smoke: what kind of world is the smoke running? ==="
Copy-Item "veil\OMNI\Source\*" "D:\OMNI-UE\Source" -Recurse -Force -ErrorAction SilentlyContinue
Copy-Item "veil\VEIL\Source\*" "D:\VEIL\Source" -Recurse -Force -ErrorAction SilentlyContinue
$Build = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat"
& $Build VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex 2>&1 | Select-String "Result:|error" | Select-Object -First 8
& $Build OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex 2>&1 | Select-String "Result:|error" | Select-Object -First 8
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe"
$p = Start-Process $UE -ArgumentList '"D:\OMNI-UE\OMNI.uproject"','/Game/Maps/OMNIWorld','-game','-windowed','-resx=640','-resy=360','-abslog="D:\OMNI-UE\Saved\smoke186.log"' -PassThru
Start-Sleep -Seconds 30
if (!$p.HasExited) { Stop-Process -Id $p.Id -Force -ErrorAction SilentlyContinue; Write-Output "smoke closed after 30s" }
Select-String -Path "D:\OMNI-UE\Saved\smoke186.log" -Pattern "TICKPROOF|TIMER CHECK|GAMEMODE ALIVE|BODY CHECK|Traceback" | Select-Object -First 12 | ForEach-Object { $_.Line }
$tk = Select-String -Path "D:\OMNI-UE\Saved\smoke186.log" -Pattern "TICKPROOF" | Select-Object -Last 1
if ($tk) {
  if ($tk.Line -match "gameWorld=0") { Write-Output "DECISION: the smoke world is NOT a game world (gameWorld=0) - the editor-binary -game launch is the terrain, not the game's code" }
  if ($tk.Line -match "gameWorld=1" -and $tk.Line -match "worldBegun=1" -and $tk.Line -match "worldTime=0\.00") { Write-Output "DECISION: a begun game world whose clock still stands - the level tick dispatch itself is the joint" }
  if ($tk.Line -match "timerRemaining=3\.00") { Write-Output "DECISION: timer remaining frozen at 3.00 - the timer manager's tick never runs" }
}
Write-Output "=== JOB 186 DONE ==="
```
