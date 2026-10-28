<!-- PHI-DIRECT -->
```powershell
Write-Output '=== VEIL FINISH COOK - PLATFORM TOKEN CORRECTED (Job 314 named the cause from the cook logs own lines: The platform name Windows is not a valid platform name. Valid names are Win64, Mac, IOS, Android, Linux... - the repackage jobs 303/304/307/308 carried -platform=Windows, one wrong token from this seat, and UAT exited in 0 seconds without cooking anything; every exe those jobs reported was the older pre-grounding build, and job 314s settle proof confirmed the pawns falling in them: VEIL Z -12431 to -17206, OMNI Z -12785 to -17593. This job is the same cook with the single corrected token -platform=Win64, the form the successful cooks in this lane used. It cooks the GROUNDED map saved by the fix, archives over the old build, then runs the settle proof: the package census should show the grounded counts and the MOVE TEST should begin near ground height, not negative thousands. Editor-closed guard on.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - finish cook deferred, nothing touched.'; Write-Output 'VEIL FINISH COOK DEFERRED'; return }
$uproj = Get-ChildItem 'D:\VEIL' -Filter '*.uproject' -File -ErrorAction SilentlyContinue | Select-Object -First 1 -ExpandProperty FullName
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
if (-not (Test-Path $uat)) { $uat = Get-ChildItem 'C:\Program Files\Epic Games' -Recurse -Filter 'RunUAT.bat' -ErrorAction SilentlyContinue | Select-Object -First 1 -ExpandProperty FullName }
if ($uproj -and $uat) {
  $cooklog = 'D:\VEIL\Saved\finishcook315.log'
  $p = Start-Process $uat -ArgumentList @('BuildCookRun', "-project=$uproj", '-noP4', '-platform=Win64', '-clientconfig=Development', '-build', '-cook', '-stage', '-pak', '-archive', "-archivedirectory=D:\Builds\VEIL\VEIL_DONE") -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $cooklog -RedirectStandardError "$cooklog.err"
  "UAT exit: $($p.ExitCode)" | Write-Output
  Select-String -Path $cooklog -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|Error:' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output
  $exe = 'D:\Builds\VEIL\VEIL_DONE\Windows\VEIL.exe'
  if (Test-Path $exe) { $fi = Get-Item $exe; "exe: $($fi.FullName) | modified $($fi.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss')) | $([math]::Round($fi.Length/1MB,1)) MB" | Write-Output } else { "exe MISSING: $exe" | Write-Output }
  if (Test-Path $exe) {
    $proc = Start-Process $exe -ArgumentList @('-PhiStandaloneProof') -PassThru -WindowStyle Hidden
    Start-Sleep -Seconds 40
    $logs = Get-ChildItem 'D:\VEIL\Saved\Logs', 'D:\Builds\VEIL\VEIL_DONE\Windows\VEIL\Saved\Logs' -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    if ($logs) { "proof log: $($logs.FullName)" | Write-Output; Select-String -Path $logs.FullName -Pattern 'PHI CENSUS|PHI MOVE TEST|PHI GM TICKPROOF' | Select-Object -Last 10 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
    Get-Process VEIL -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
  }
} else { Write-Output 'TERRAIN MISSING: uproject or RunUAT not found - nothing ran' }
Write-Output 'VEIL FINISH COOK DONE'
```
