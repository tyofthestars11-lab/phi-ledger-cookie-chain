<!-- PHI-DIRECT -->
# JOB 026 - DEFENDER EXCLUSIONS, ELEVATED (DIRECT)

Job 024's step 3 failed on every line: "You don't have enough permissions"
- the seat runs unelevated, and Defender exclusions need admin. The scan
toll is still on every save/catalog write, which is the loudest remaining
suspect for the autosave/quick-save pause. This job writes a small fix
script, launches it ELEVATED (a Windows UAC prompt appears on Tyree's
screen - his tap on Yes is the allow), and reads back the result log the
elevated run leaves behind. If no log appears, the elevation was declined
and the report says so plainly.

## STEP 1 - ELEVATE + APPLY + READ BACK
```powershell
$fix = "$env:TEMP\phi-defender-fix.ps1"
$log = "$env:TEMP\phi-defender-fix.log"
Remove-Item $log -ErrorAction SilentlyContinue
$body = @'
$out = @()
$paths = @('D:\XboxGames\Starfield', "$env:LOCALAPPDATA\Starfield")
$pkgC = Get-ChildItem "$env:LOCALAPPDATA\Packages" -Directory -ErrorAction SilentlyContinue | Where-Object Name -match 'ProjectGold' | Select-Object -First 1
if ($pkgC) { $paths += (Join-Path $pkgC.FullName 'SystemAppData\wgs') }
$pkgD = Get-ChildItem 'D:\WpSystem' -Recurse -Directory -Force -ErrorAction SilentlyContinue | Where-Object Name -match 'ProjectGold' | Select-Object -First 1
if ($pkgD) { $paths += (Join-Path $pkgD.FullName 'SystemAppData\wgs') }
foreach ($w in $paths) { try { Add-MpPreference -ExclusionPath $w -ErrorAction Stop; $out += "OK PATH: $w" } catch { $out += "FAIL PATH: $w - $($_.Exception.Message)" } }
try { Add-MpPreference -ExclusionProcess 'Starfield.exe' -ErrorAction Stop; $out += 'OK PROCESS: Starfield.exe' } catch { $out += "FAIL PROCESS: $($_.Exception.Message)" }
$out | Set-Content -Path "$env:TEMP\phi-defender-fix.log"
'@
Set-Content -Path $fix -Value $body
try { Start-Process powershell.exe -Verb RunAs -ArgumentList "-NoProfile -ExecutionPolicy Bypass -File `"$fix`"" -Wait -ErrorAction Stop; "ELEVATED RUN FINISHED" } catch { "ELEVATION FAILED: $($_.Exception.Message)" }
if (Test-Path $log) { Get-Content $log | ForEach-Object { "RESULT: $_" } } else { "NO LOG - the Allow prompt was declined or blocked" }
```
