# Job 239 — ProjectID format fix (both games) + VEIL_DONE repackage alone

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 233 measured: both VEIL cooks now carry exactly ONE distinct Error - LoadConfig import failed for ProjectID in: 451B8EAC-A89D-495A-A347-31670EA913C3 - and the cook fails ExitCode 25 with the ABP at 0 mentions. Job 201 proved the ini HOLDS that dashed string; 233 proves the engine cannot IMPORT it in that form. Presence is not importability. The form the engine itself exports for an FGuid config value is the struct form (A=,B=,C=,D=) with signed int32 components. This job: (1) dumps the ProjectID lines raw bytes so any stray character stands named in the record; (2) backs up both DefaultGame.ini files; (3) rewrites ONLY the value, components computed here from the existing digits - the GUID identity does not change, nothing is hand-typed; (4) verifies the new line; (5) relaunches the VEIL_DONE package ALONE (231/232 launched together and OMNIs UAT died on the single-instance mutex before its log was set). Job 098 removed the line entirely in the old-guid era and the cook then failed on ABP_Unarmed - that asset is gone and the ABP stands quarantined, so that test does not settle this form. ==='
$enc = New-Object System.Text.UTF8Encoding($false)
New-Item -ItemType Directory -Force -Path 'D:\_PhiHolding\config-backup-239' | Out-Null
foreach ($g in @(@('VEIL','D:\VEIL\Config\DefaultGame.ini','451B8EAC-A89D-495A-A347-31670EA913C3'), @('OMNI','D:\OMNI-UE\Config\DefaultGame.ini','DC5E4CF1-FD4D-485E-98F1-2B96AF43DB4C'))) {
  $name = $g[0]; $ini = $g[1]; $guid = $g[2]
  if (-not (Test-Path $ini)) { Write-Output "$name ini MISSING: $ini"; continue }
  Copy-Item $ini "D:\_PhiHolding\config-backup-239\$name-DefaultGame.ini" -Force
  $raw = [IO.File]::ReadAllBytes($ini)
  $text = [IO.File]::ReadAllText($ini)
  $line = ($text -split "`r?`n" | Where-Object { $_ -match 'ProjectID=' } | Select-Object -First 1)
  Write-Output "$name current line: [$line]"
  $lb = [Text.Encoding]::UTF8.GetBytes($line)
  Write-Output "$name line bytes: $(($lb | ForEach-Object { $_.ToString('X2') }) -join ' ')"
  $digits = $guid -replace '-', ''
  if ($digits.Length -ne 32) { Write-Output "$name ABORT: guid digits $($digits.Length) - file untouched."; continue }
  $A = [Convert]::ToInt32($digits.Substring(0,8), 16)
  $B = [Convert]::ToInt32($digits.Substring(8,8), 16)
  $C = [Convert]::ToInt32($digits.Substring(16,8), 16)
  $D = [Convert]::ToInt32($digits.Substring(24,8), 16)
  $newVal = "ProjectID=(A=$A,B=$B,C=$C,D=$D)"
  $newText = $text -replace 'ProjectID=[^\r\n]*', $newVal
  if ($newText -ne $text) {
    [IO.File]::WriteAllText($ini, $newText, $enc)
    $check = ([IO.File]::ReadAllText($ini) -split "`r?`n" | Where-Object { $_ -match 'ProjectID=' } | Select-Object -First 1)
    Write-Output "$name rewritten: [$check]"
  } else { Write-Output "$name NO CHANGE MADE - pattern did not match; file untouched." }
}
$uat = Get-Process -Name 'AutomationTool','RunUAT' -ErrorAction SilentlyContinue
if ($uat) { Write-Output "UAT already running ($($uat.Id -join ', ')) - VEIL package NOT launched; next job launches it." }
else {
  $uatBat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
  $log = 'D:\VEIL\Saved\Logs\PackageVEILDone2.log'
  $p = Start-Process -FilePath $uatBat -ArgumentList 'BuildCookRun','-Project=D:\VEIL\VEIL.uproject','-Platform=Win64','-Cook','-Stage','-Pak','-Package','-Archive','-ArchiveDirectory=D:\Builds\VEIL\VEIL_DONE','-ClientConfig=Development','-Unattended','-NoP4' -PassThru -WindowStyle Hidden -RedirectStandardOutput $log -RedirectStandardError 'D:\VEIL\Saved\Logs\PackageVEILDone2.err.log'
  Write-Output "PACKAGE VEIL_DONE (attempt 2, ProjectID struct form) LAUNCHED: pid $($p.Id), archive D:\Builds\VEIL\VEIL_DONE, log $log"
}
```
