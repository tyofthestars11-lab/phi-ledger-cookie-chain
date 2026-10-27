<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== VEILGameMode.h lines 41-73 from THIS machine's copy (the GameMode class body - the parser chokes at the NEXT class head, so the fault sits in here) ==="
Get-Content "D:\VEIL\Source\VEIL\Public\Game\VEILGameMode.h" | Select-Object -Index (40..72) | ForEach-Object { $_ }
Write-Output "=== sync source, build both (v2 TICKPROOF + timer + tick-entry counter ride this sync) ==="
Copy-Item "veil\VEIL\Source\*" "D:\VEIL\Source" -Recurse -Force -ErrorAction SilentlyContinue
Copy-Item "veil\OMNI\Source\*" "D:\OMNI-UE\Source" -Recurse -Force -ErrorAction SilentlyContinue
$Build = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat"
& $Build VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex 2>&1 | Select-String "Result:|error" | Select-Object -First 10
& $Build OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex 2>&1 | Select-String "Result:|error" | Select-Object -First 10
Write-Output "=== OMNI smoke 30s: the v2 interrogation ==="
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe"
$p = Start-Process $UE -ArgumentList '"D:\OMNI-UE\OMNI.uproject"','/Game/Maps/OMNIWorld','-game','-windowed','-resx=640','-resy=360','-abslog="D:\OMNI-UE\Saved\smoke180v2.log"' -PassThru
Start-Sleep -Seconds 30
if (!$p.HasExited) { Stop-Process -Id $p.Id -Force -ErrorAction SilentlyContinue; Write-Output "smoke closed after 30s" }
Select-String -Path "D:\OMNI-UE\Saved\smoke180v2.log" -Pattern "TICKPROOF|TIMER CHECK|GAMEMODE ALIVE|BODY CHECK|Traceback" | Select-Object -First 14 | ForEach-Object { $_.Line }
$tk = Select-String -Path "D:\OMNI-UE\Saved\smoke180v2.log" -Pattern "TICKPROOF" | Select-Object -Last 1
if ($tk) {
  if ($tk.Line -match "worldTime=0\.00" -and $tk.Line -match "timerActive=1") { Write-Output "DECISION: clock at 0.00 with the 3s timer still pending and delta real - the break sits on the world's time path" }
  if ($tk.Line -match "pawnTickEntries=0") { Write-Output "DECISION: pawn Tick never entered - entry count 0" }
  if ($tk.Line -match "pawnTickEntries=[1-9]") { Write-Output "DECISION: pawn Tick entered - the count is live" }
  if ($tk.Line -match "sameWorld=0") { Write-Output "DECISION: controller and pawn sit in different worlds" }
}
Write-Output "=== JOB 182 DONE ==="
```
