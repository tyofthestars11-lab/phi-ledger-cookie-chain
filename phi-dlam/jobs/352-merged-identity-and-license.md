<!-- PHI-DIRECT -->
```powershell
Write-Output '=== MERGED IDENTITY + LICENSE CARRIAGE - GOLDEN EYE, ALL FREE ALL PHI (Tyrees assembled order, 2026-10-28: Finish / Golden Eye what you need and add it / All free all phi. The terms ride on the finished game: VEIL OMNI is free to play under the PHI LICENSE the parents already carry in code, no paywall anywhere on it, framework licensing through Tyree only, universal scope. The merged base still presents the parent name in its config - job 340 read ProjectName=VEIL: THE LAST SIGNAL in D:\VEIL\Config\DefaultGame.ini. THIS JOB gives the base its merged name - ProjectName becomes VEIL OMNI: THE LAST SIGNAL - PATH OF LIGHT (hyphen form; the config is an ASCII surface) - with the backup taken first and the new line verified by read-back in the same job, and it prints the license lines as they stand in the base sources so the carriage is proven from the record, not asserted. The GameDefaultMap does not change in this job: VEILDistrict remains the home region while the District seats.) ==='
$ini = 'D:\VEIL\Config\DefaultGame.ini'
if (-not (Test-Path $ini)) { Write-Output 'DEFAULTGAME.INI MISSING'; Write-Output 'JOB 352 STOPPED'; return }
Copy-Item $ini "$ini.phi-backup-352" -Force
$src = [System.IO.File]::ReadAllText($ini)
if ($src.Contains('ProjectName=VEIL OMNI')) { Write-Output 'MERGED NAME ALREADY STANDS' } else {
  $count = ([regex]::Matches($src, 'ProjectName=')).Count
  "PROJECTNAME LINES: $count" | Write-Output
  if ($count -ne 1) { Write-Output 'PROJECTNAME NOT UNIQUE - no write made.'; Write-Output 'JOB 352 STOPPED'; return }
  $src = $src -replace 'ProjectName=[^\r\n]*', 'ProjectName=VEIL OMNI: THE LAST SIGNAL - PATH OF LIGHT'
  [System.IO.File]::WriteAllText($ini, $src)
  $check = [System.IO.File]::ReadAllText($ini)
  if ($check.Contains('ProjectName=VEIL OMNI: THE LAST SIGNAL - PATH OF LIGHT')) { Write-Output 'MERGED NAME WRITTEN + VERIFIED in DefaultGame.ini' } else { Write-Output 'NAME WRITE FAILED VERIFY'; Write-Output 'JOB 352 STOPPED'; return }
}
Write-Output '===== LICENSE LINES AS THEY STAND IN THE BASE ====='
Get-ChildItem 'D:\VEIL\Source' -Recurse -Include '*.cpp','*.h' -File -ErrorAction SilentlyContinue | Select-String -Pattern 'PHI LICENSE|free to play|licensed only through|Tyree Shariff Jones' -ErrorAction SilentlyContinue | Select-Object -First 20 | ForEach-Object { Write-Output ("PHI LICENSE LINE " + $_.Filename + ":" + $_.LineNumber + " " + $_.Line.Trim()) }
Write-Output 'JOB 352 DONE'
```
