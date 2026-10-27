<!-- PHI-DIRECT -->
# JOB 027 - WRITE PERMISSION ON THE REAL DATA FOLDER (DIRECT, conditional)

After job 025 repointed Vortex to D:, Vortex's health check still flagged
Hardlink Deployment against the output directory. Vortex's own wizard named
the cure in Tyree's photos: "the current user account needs to be given
write permission" to the Data folder - it was just naming the dead C: path
then. This job tests write access on the REAL folder
(D:\XboxGames\Starfield\Content\Data) with a probe file; ONLY IF the probe
fails does it grant his account + Administrators Full Control, elevated
(his UAC Yes is the allow), then re-tests. If the probe passes, nothing
changes and the report says so.

## STEP 1 - WRITE PROBE + ACL READ
```powershell
$data = 'D:\XboxGames\Starfield\Content\Data'
$probe = Join-Path $data 'phi-probe.tmp'
try { Set-Content -Path $probe -Value 'probe' -ErrorAction Stop; Remove-Item $probe -Force; "WRITE PROBE: PASS - $data is writable" } catch { "WRITE PROBE: FAIL - $($_.Exception.Message)" }
$acl = Get-Acl 'D:\XboxGames\Starfield\Content' -ErrorAction SilentlyContinue
if ($acl) { "CONTENT OWNER: $($acl.Owner)"; $acl.Access | Where-Object { $_.IdentityReference -match 'Admin|Users|SYSTEM' } | Select-Object -First 6 | ForEach-Object { "ACL: $($_.IdentityReference) - $($_.FileSystemRights) - $($_.AccessControlType)" } }
```

## STEP 2 - GRANT (only if the probe failed; elevated)
```powershell
$data = 'D:\XboxGames\Starfield\Content\Data'
$probe = Join-Path $data 'phi-probe.tmp'
$writable = $false
try { Set-Content -Path $probe -Value 'probe' -ErrorAction Stop; Remove-Item $probe -Force; $writable = $true } catch {}
if ($writable) { "GRANT SKIPPED - already writable" } else {
  $fix = "$env:TEMP\phi-acl-fix.ps1"; $log = "$env:TEMP\phi-acl-fix.log"
  Remove-Item $log -ErrorAction SilentlyContinue
  $body = @'
$out = @()
foreach ($t in 'D:\XboxGames\Starfield\Content','D:\XboxGames\Starfield\Content\Data') {
  $r = icacls $t /grant "*S-1-5-32-544:(OI)(CI)F" "*S-1-5-21-85939356-3593402667-215545242-1001:(OI)(CI)F" /T /C 2>&1 | Select-Object -Last 1
  $out += "ICACLS $t -> $r"
}
$out | Set-Content -Path "$env:TEMP\phi-acl-fix.log"
'@
  Set-Content -Path $fix -Value $body
  try { Start-Process powershell.exe -Verb RunAs -ArgumentList "-NoProfile -ExecutionPolicy Bypass -File `"$fix`"" -Wait -ErrorAction Stop; "ELEVATED GRANT FINISHED" } catch { "ELEVATION FAILED: $($_.Exception.Message)" }
  if (Test-Path $log) { Get-Content $log | ForEach-Object { "GRANT: $_" } } else { "NO GRANT LOG - Allow declined or blocked" }
  try { Set-Content -Path $probe -Value 'probe' -ErrorAction Stop; Remove-Item $probe -Force; "WRITE PROBE AFTER: PASS" } catch { "WRITE PROBE AFTER: FAIL - $($_.Exception.Message)" }
}
```
