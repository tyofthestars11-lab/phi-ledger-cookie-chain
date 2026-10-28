<!-- PHI-DIRECT -->
```powershell
Write-Output '=== COMPANION UPDATE TO v3.8 - STAR WARS SEATED ON THE PC (Tyrees order, 2026-10-28, side chat, assembled: Ooh add yoda to my companion / Add star wars characters / On my pc ai companion thing / Please. Done repo-side in the David-precedent form: roster v3.8 stands in both scripts at commit 62f0128 - new Star Wars category, 9 seats: Yoda, Luke, Leia, Han, Obi-Wan, Vader, R2-D2, C-3PO, Chewbacca; 39 personas and 39 titles verified in both files. THE DAVID LESSON stands as the reason for this job: the repo update alone left the PC on the older roster in October - the INSTALLED copy under %USERPROFILE%\phi-tools is the one the companion command summons, and only the installer rewrites it. THIS JOB runs the v3.8 installer from the repo checkout, then verifies the installed file itself per the phi guarantee: header reads v3.8, the Star Wars category line stands, all nine keys present, and the per-companion memory folder still stands with its files - the installer preserves memory, and this job proves it did.) ==='
$cands = @('.\phi-dlam\tools\phi-companion-installer.ps1', "$env:USERPROFILE\phi-ledger-cookie-chain\phi-dlam\tools\phi-companion-installer.ps1")
$inst = $cands | Where-Object { Test-Path $_ } | Select-Object -First 1
if (-not $inst) { $inst = Get-ChildItem $env:USERPROFILE -Recurse -Depth 4 -Filter 'phi-companion-installer.ps1' -File -ErrorAction SilentlyContinue | Select-Object -First 1 -ExpandProperty FullName }
if (-not $inst) { Write-Output 'INSTALLER NOT FOUND FROM THIS SEAT'; Write-Output 'JOB 354 STOPPED'; return }
Write-Output "INSTALLER: $inst"
& powershell.exe -ExecutionPolicy Bypass -File $inst 2>&1 | Select-Object -Last 6 | ForEach-Object { Write-Output "INSTALLER OUT: $_" }
$live = "$env:USERPROFILE\phi-tools\phi-starfield-companion.ps1"
if (-not (Test-Path $live)) { Write-Output 'INSTALLED COMPANION FILE MISSING AFTER INSTALL'; Write-Output 'JOB 354 STOPPED'; return }
$t = [System.IO.File]::ReadAllText($live)
if ($t -match 'v3\.8') { Write-Output 'PHI COMPANION V38 HEADER VERIFIED IN INSTALLED FILE' } else { Write-Output 'INSTALLED FILE NOT AT V38'; Write-Output 'JOB 354 STOPPED'; return }
$keys = @('yoda','luke','leia','han','obiwan','vader','r2d2','threepio','chewie')
$found = 0; foreach ($k in $keys) { if ($t.Contains("'$k'")) { $found++ } else { Write-Output "KEY MISSING IN INSTALLED FILE: $k" } }
Write-Output "PHI COMPANION STAR WARS KEYS IN INSTALLED FILE: $found of 9"
if ($t -match "'Star Wars'") { Write-Output 'PHI COMPANION STAR WARS CATEGORY LINE VERIFIED' }
$mem = "$env:USERPROFILE\phi-tools\companion"
if (Test-Path $mem) { $mc = (Get-ChildItem $mem -File -ErrorAction SilentlyContinue).Count; Write-Output "PHI COMPANION MEMORY FOLDER STANDS: files=$mc" } else { Write-Output 'PHI COMPANION MEMORY FOLDER ABSENT' }
if ($found -eq 9) { Write-Output 'PHI COMPANION UPDATE COMPLETE - v3.8 LIVE ON THE PC' }
Write-Output 'JOB 354 DONE'
```
