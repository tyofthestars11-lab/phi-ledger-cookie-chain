<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== do the two copies of VEILGameMode.h match byte for byte? (vault repo copy vs D: copy) ==="
$vault = "veil\VEIL\Source\VEIL\Public\Game\VEILGameMode.h"
$pc = "D:\VEIL\Source\VEIL\Public\Game\VEILGameMode.h"
Write-Output "vault hash: $((Get-FileHash $vault).Hash)"
Write-Output "pc hash:    $((Get-FileHash $pc).Hash)"
Write-Output "--- line diff (vault vs pc), first 20 differences ---"
Compare-Object (Get-Content $vault) (Get-Content $pc) | Select-Object -First 20 | ForEach-Object { "$($_.SideIndicator) $($_.InputObject)" }
Write-Output "=== the never-printed spans of the PC copy: lines 1-30 and 84-113 ==="
Get-Content $pc | Select-Object -Index (0..29) | ForEach-Object { $_ }
Write-Output "--- 84-113 ---"
Get-Content $pc | Select-Object -Index (83..112) | ForEach-Object { $_ }
Write-Output "=== UHT state: generated file vs header timestamps ==="
Get-Item "D:\VEIL\Intermediate\Build\Win64\UnrealEditor\Inc\VEIL\UHT\VEILGameMode.gen.cpp", $pc -ErrorAction SilentlyContinue | ForEach-Object { "$($_.LastWriteTime) $($_.FullName)" }
Write-Output "=== sync source (the repaired TICKPROOF cpps ride this), build both ==="
Copy-Item "veil\VEIL\Source\*" "D:\VEIL\Source" -Recurse -Force -ErrorAction SilentlyContinue
Copy-Item "veil\OMNI\Source\*" "D:\OMNI-UE\Source" -Recurse -Force -ErrorAction SilentlyContinue
Write-Output "pc hash after sync: $((Get-FileHash $pc).Hash)"
$Build = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat"
& $Build VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex 2>&1 | Select-String "Result:|error" | Select-Object -First 10
& $Build OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex 2>&1 | Select-String "Result:|error" | Select-Object -First 10
Write-Output "=== OMNI smoke 30s: interrogation v2, for real this time ==="
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe"
$p = Start-Process $UE -ArgumentList '"D:\OMNI-UE\OMNI.uproject"','/Game/Maps/OMNIWorld','-game','-windowed','-resx=640','-resy=360','-abslog="D:\OMNI-UE\Saved\smoke185.log"' -PassThru
Start-Sleep -Seconds 30
if (!$p.HasExited) { Stop-Process -Id $p.Id -Force -ErrorAction SilentlyContinue; Write-Output "smoke closed after 30s" }
Select-String -Path "D:\OMNI-UE\Saved\smoke185.log" -Pattern "TICKPROOF|TIMER CHECK|GAMEMODE ALIVE|BODY CHECK|Traceback" | Select-Object -First 14 | ForEach-Object { $_.Line }
$tk = Select-String -Path "D:\OMNI-UE\Saved\smoke185.log" -Pattern "TICKPROOF" | Select-Object -Last 1
if ($tk) {
  if ($tk.Line -match "worldTime=0\.00" -and $tk.Line -match "timerActive=1") { Write-Output "DECISION: clock at 0.00 with the 3s timer still pending and delta real - the break sits on the world's time path" }
  if ($tk.Line -match "pawnTickEntries=0") { Write-Output "DECISION: pawn Tick never entered - entry count 0" }
  if ($tk.Line -match "pawnTickEntries=[1-9]") { Write-Output "DECISION: pawn Tick entered - the count is live" }
  if ($tk.Line -match "sameWorld=0") { Write-Output "DECISION: controller and pawn sit in different worlds" }
}
Write-Output "=== the A9 log folder: what AutomationTool logs survive? ==="
Get-ChildItem "C:\Users\Admin\AppData\Roaming\Unreal Engine\AutomationTool\Logs\C+Program+Files+Epic+Games+UE_5.8" -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 8 | ForEach-Object { "$($_.LastWriteTime) $($_.Length) $($_.Name)" }
Write-Output "=== JOB 185 DONE ==="
```
