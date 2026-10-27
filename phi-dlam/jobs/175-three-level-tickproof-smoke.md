<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== build the three-level tick proofs (GameMode + PlayerController join the Character) ==="
Copy-Item "veil\VEIL\Source\*" "D:\VEIL\Source" -Recurse -Force -ErrorAction SilentlyContinue
Copy-Item "veil\OMNI\Source\*" "D:\OMNI-UE\Source" -Recurse -Force -ErrorAction SilentlyContinue
$Build = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat"
& $Build VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex 2>&1 | Select-String "Result:|error C" | ForEach-Object { $_.Line }
& $Build OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex 2>&1 | Select-String "Result:|error C" | ForEach-Object { $_.Line }
Write-Output "=== OMNI smoke: snapshots + the log's own frame counter at the tail ==="
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe"
$log = "D:\OMNI-UE\Saved\Logs\phi-smoke6-omni.log"
$p = Start-Process $UE -ArgumentList "`"D:\OMNI-UE\OMNI.uproject`"", "/Game/Maps/OMNIWorld", "-game", "-windowed", "-ResX=1280", "-ResY=720", "-abslog=$log", "-unattended", "-nosplash" -PassThru
foreach ($mark in @(15, 30, 45, 60)) {
  Start-Sleep -Seconds 15
  $lines = if (Test-Path $log) { (Get-Content $log | Measure-Object -Line).Lines } else { 0 }
  Write-Output "t=${mark}s: alive=$($p.HasExited -eq $false) logLines=$lines"
}
if (!$p.HasExited) { Stop-Process -Id $p.Id -Force; Write-Output "smoke closed after 60s" }
Start-Sleep -Seconds 3
if (Test-Path $log) {
  Select-String -Path $log -Pattern "TICKPROOF|MOVE TEST|GAMEMODE ALIVE" | ForEach-Object { $_.Line }
  Write-Output "--- final 3 log lines (frame counter state) ---"
  Get-Content $log -Tail 3
}
Write-Output "=== JOB 175 DONE ==="
```
