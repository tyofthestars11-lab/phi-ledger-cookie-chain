<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe"
function Smoke($proj, $map, $tag) {
  Write-Output "=== $tag smoke ($map) ==="
  $log = "$($proj | Split-Path)\Saved\Logs\phi-smoke-$tag.log"
  $p = Start-Process $UE -ArgumentList "`"$proj`"", $map, "-game", "-windowed", "-ResX=1280", "-ResY=720", "-abslog=$log", "-unattended", "-nosplash" -PassThru
  Start-Sleep -Seconds 50
  if (!$p.HasExited) { Stop-Process -Id $p.Id -Force; Write-Output "smoke closed after dwell" }
  Start-Sleep -Seconds 3
  if (Test-Path $log) {
    Select-String -Path $log -Pattern "PHI BODY|PHI FACTION BODY|PHI CENSUS|PHI VOICE" | Select-Object -First 40 | ForEach-Object { $_.Line }
  } else { Write-Output "no smoke log at $log" }
}
Smoke "D:\OMNI-UE\OMNI.uproject" "/Game/Maps/OMNIWorld" "omni"
Smoke "D:\VEIL\VEIL.uproject" "/Game/Maps/VEILDistrict" "veil"
Write-Output "=== JOB 137 DONE ==="
```
