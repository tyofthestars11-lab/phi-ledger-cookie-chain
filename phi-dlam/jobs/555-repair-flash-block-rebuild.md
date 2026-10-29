<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 555 - REPAIR THE FLASH BLOCK AND REBUILD (Ground: job 554 patched the bolt but the build failed, and the patcher that inserted the spawn log shifted every line after it so the flash block lost its opening brace. This job prints the 554 build error lines, repairs the three flash lines at their true positions with no insert step, verifies the repair in the same job, and rebuilds with the result printed. No game relaunch rides this job. Every variable carries the p555 prefix.) ==='
$p555log554 = 'D:\VEIL-OMNI\Saved\build554.log'
if (Test-Path $p555log554) {
  $p555errs = @(Select-String -Path $p555log554 -Pattern 'erro[r]' | Select-Object -Last 30)
  foreach ($p555e in $p555errs) { Write-Output ('BUILD554 ERROR ' + $p555e.Line.Trim()) }
  if ($p555errs.Count -eq 0) { Write-Output 'BUILD554 ERROR LINES NONE FOUND' }
} else { Write-Output 'BUILD554 LOG MISSING' }
$p555b64 = 'aW1wb3J0IHN5cwpzcmMgPSBzeXMuYXJndlsxXQp2ZXJkaWN0ID0gc3lzLmFyZ3ZbMl0KcmF3ID0gb3BlbihzcmMsICdyYicpLnJlYWQoKQpubCA9IGInXHJcbicgaWYgcmF3LmNvdW50KGInXHJcbicpID4gcmF3LmNvdW50KGInXG4nKSAtIHJhdy5jb3VudChiJ1xyXG4nKSBlbHNlIGInXG4nCnRleHQgPSByYXcuZGVjb2RlKCd1dGYtOCcsIGVycm9ycz0ncmVwbGFjZScpCmxpbmVzID0gdGV4dC5zcGxpdGxpbmVzKCkKc3Bhd24gPSAnaWYgKEFTdGF0aWNNZXNoQWN0b3IqIEZsYXNoID0gR2V0V29ybGQoKS0+U3Bhd25BY3RvcjxBU3RhdGljTWVzaEFjdG9yPihBU3RhdGljTWVzaEFjdG9yOjpTdGF0aWNDbGFzcygpLCBCb2x0RW5kLCBGUm90YXRvcjo6WmVyb1JvdGF0b3IpKScKc2NhbGVfbmV3ID0gJ0ZsYXNoLT5TZXRBY3RvclNjYWxlM0QoRlZlY3RvcigxLjJmLCAxLjJmLCAxLjJmKSk7JwpsaWZlX25ldyA9ICdGbGFzaC0+U2V0TGlmZVNwYW4oMC41Zik7JwpsaWZlX29sZCA9ICdGbGFzaC0+U2V0TGlmZVNwYW4oMC4yZik7JwppZHhzID0gW2kgZm9yIGksIGxuIGluIGVudW1lcmF0ZShsaW5lcykgaWYgbG4uc3RyaXAoKSA9PSBzcGF3bl0KaWYgbGVuKGlkeHMpICE9IDE6CiAgICBvcGVuKHZlcmRpY3QsICd3Jykud3JpdGUoJ1JFUEFJUiBHQVRFIEZBSUwnKQogICAgcHJpbnQoJ1JFUEFJUiBHQVRFIEZBSUwgLSBmbGFzaCBzcGF3biBhbmNob3IgY291bnQgJyArIHN0cihsZW4oaWR4cykpKQogICAgc3lzLmV4aXQoMCkKcyA9IGlkeHNbMF0KcmVnaW9uID0gbGluZXNbbWF4KDAsIHMgLSAxKTpzICsgOV0KcHJpbnQoJ0ZMQVNIIFJFR0lPTiBOT1c6JykKZm9yIGosIGxuIGluIGVudW1lcmF0ZShyZWdpb24pOgogICAgcHJpbnQoJ1JFR0lPTiAnICsgc3RyKG1heCgwLCBzIC0gMSkgKyBqICsgMSkgKyAnICcgKyBsbi5zdHJpcCgpKQppZiBub3QgKGxpbmVzW3MgKyAxXS5zdHJpcCgpID09IHNjYWxlX25ldyBhbmQgbGluZXNbcyArIDJdLnN0cmlwKCkgPT0gbGlmZV9uZXcgYW5kIGxpbmVzW3MgKyAzXS5zdHJpcCgpID09IGxpZmVfb2xkKToKICAgIG9wZW4odmVyZGljdCwgJ3cnKS53cml0ZSgnUkVQQUlSIEdBVEUgRkFJTCcpCiAgICBwcmludCgnREFNQUdFIFBBVFRFUk4gTUlTTUFUQ0ggLSByZWdpb24gcHJpbnRlZCBhYm92ZSwgbm90aGluZyB3cml0dGVuJykKICAgIHN5cy5leGl0KDApCm91dCA9IGxpc3QobGluZXMpCm91dFtzICsgMV0gPSBsaW5lc1tzICsgMV1bOmxlbihsaW5lc1tzICsgMV0pIC0gbGVuKGxpbmVzW3MgKyAxXS5sc3RyaXAoKSldICsgJ3snCm91dFtzICsgMl0gPSBsaW5lc1tzICsgMl1bOmxlbihsaW5lc1tzICsgMl0pIC0gbGVuKGxpbmVzW3MgKyAyXS5sc3RyaXAoKSldICsgc2NhbGVfbmV3Cm91dFtzICsgM10gPSBsaW5lc1tzICsgM11bOmxlbihsaW5lc1tzICsgM10pIC0gbGVuKGxpbmVzW3MgKyAzXS5sc3RyaXAoKSldICsgbGlmZV9uZXcKb3BlbihzcmMsICd3YicpLndyaXRlKG5sLmpvaW4oW2wuZW5jb2RlKCd1dGYtOCcpIGZvciBsIGluIG91dF0pICsgbmwpCmNoZWNrID0gb3BlbihzcmMsICdyJywgZW5jb2Rpbmc9J3V0Zi04JywgZXJyb3JzPSdyZXBsYWNlJykucmVhZCgpLnNwbGl0bGluZXMoKQpvayA9IChjaGVja1tzICsgMV0uc3RyaXAoKSA9PSAneycgYW5kIGNoZWNrW3MgKyAyXS5zdHJpcCgpID09IHNjYWxlX25ldyBhbmQgY2hlY2tbcyArIDNdLnN0cmlwKCkgPT0gbGlmZV9uZXcKICAgICAgYW5kIHN1bSgxIGZvciBsbiBpbiBjaGVjayBpZiBsbi5zdHJpcCgpID09IGxpZmVfbmV3IGFuZCAnRmxhc2gnIGluIGxuKSA9PSAxCiAgICAgIGFuZCAnQm9sdC0+U2V0QWN0b3JTY2FsZTNEKEZWZWN0b3IoQm9sdExlbiAvIDEwMC5mLCAwLjM1ZiwgMC4zNWYpKTsnIGluIGNoZWNrCiAgICAgIGFuZCAnUEhJIEJPTFQgU1BBV05FRCcgaW4gJ1xuJy5qb2luKGNoZWNrKSkKaWYgbm90IG9rOgogICAgb3Blbih2ZXJkaWN0LCAndycpLndyaXRlKCdSRVBBSVIgVkVSSUZZIEZBSUwnKQogICAgcHJpbnQoJ1JFUEFJUiBWRVJJRlkgRkFJTCcpCiAgICBzeXMuZXhpdCgwKQpvcGVuKHZlcmRpY3QsICd3Jykud3JpdGUoJ1JFUEFJUiBPSycpCnByaW50KCdSRVBBSVIgT0sgLSBGTEFTSCBCUkFDRSBSRVNUT1JFRCwgU0NBTEUgQU5EIExJRkUgQVQgVFJVRSBMSU5FUycpCmZvciBsbiBpbiBjaGVja1tzOnMgKyA0XToKICAgIHByaW50KCdSRVBBSVJFRCAnICsgbG4uc3RyaXAoKSkK'
$p555patcher = 'D:\VEIL-OMNI\Saved\patch555.py'
[IO.File]::WriteAllBytes($p555patcher, [Convert]::FromBase64String($p555b64))
$p555src = 'D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp'
$p555verdict = 'D:\VEIL-OMNI\Saved\patch555.verdict.txt'
$p555py = 'C:\Users\Admin\AppData\Local\Microsoft\WindowsApps\python.exe'
& $p555py $p555patcher $p555src $p555verdict
$p555v = ''
if (Test-Path $p555verdict) { $p555v = Get-Content $p555verdict }
Write-Output ('VERDICT ' + $p555v)
if ($p555v -eq 'REPAIR OK') {
  $p555buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
  $p555uproj = 'D:\VEIL-OMNI\VEIL.uproject'
  $p555log = 'D:\VEIL-OMNI\Saved\build555.log'
  & $p555buildbat VEILEditor Win64 Development -Project="$p555uproj" -WaitMutex -NoHotReload *> "$p555log"
  $p555res = @(Select-String -Path $p555log -Pattern 'Result:' | Select-Object -Last 1)
  if ($p555res.Count -gt 0) { Write-Output ('BUILD ' + $p555res[0].Line.Trim()) } else { Write-Output 'BUILD RESULT LINE MISSING' }
} else { Write-Output 'REPAIR HELD - SOURCE UNTOUCHED' }
Write-Output 'PHI P555 VERDICT: FLASH REPAIR ABOVE'
Write-Output 'JOB 555 DONE'
```
