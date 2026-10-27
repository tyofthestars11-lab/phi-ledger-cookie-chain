<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== A9 probe: quarantine the broken vendor blueprint (reversible - moved, never deleted), then cook ==="
Write-Output "A8's trace (job 163) carries exactly two blueprint errors, both inside ONE asset our C++ game never spawns:"
Write-Output "ParagonCountess CountessPlayerCharacter.uasset - its ResetOrientationAndPosition node references a function that no longer exists."
foreach ($g in @(@("VEIL","D:\VEIL"), @("OMNI","D:\OMNI-UE"))) {
  $bp = "$($g[1])\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset"
  $hold = "D:\_PhiHolding\$($g[0])"
  New-Item -ItemType Directory -Force -Path $hold | Out-Null
  if (Test-Path $bp) { Move-Item $bp "$hold\CountessPlayerCharacter.uasset" -Force; Write-Output "$($g[0]): BP quarantined to $hold" }
  else { Write-Output "$($g[0]): BP not present (already quarantined or absent)" }
  Get-ChildItem "$($g[1])\Content\ParagonCountess\Characters\Heroes\Countess" -Filter "*.uasset" | ForEach-Object { "  still in place: $($_.Name)" }
}
Write-Output "=== launch the A9 cook for VEIL in the open (Development, all maps, archive D:\Builds\VEIL-A9) ==="
$UAT = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat"
$args = "BuildCookRun -project=`"D:\VEIL\VEIL.uproject`" -noP4 -platform=Win64 -clientconfig=Development -cook -allmaps -build -stage -pak -archive -archivedirectory=`"D:\Builds\VEIL-A9`" -unattended"
$p = Start-Process $UAT -ArgumentList $args -RedirectStandardOutput "D:\VEIL\Saved\uat-a9-launch.log" -RedirectStandardError "D:\VEIL\Saved\uat-a9-launch.err.log" -PassThru
Write-Output "A9 UAT launched in the open, pid $($p.Id)"
Write-Output "=== JOB 172 DONE ==="
```
