<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 511 - THE COMPANIONS READ AGAIN (Ground: his photo shows the companion script falling at its first lines - the long dash in its banner reads under his older PowerShell as an end quote, the string breaks open, and every line after it falls in a cascade. The file itself is whole; the reading is the fault, the same encoding class that parse killed jobs before. This job finds every script in the companion tools folder, counts the special characters in each, backs each one up, and re-saves it in the signed form his PowerShell reads correctly, repairing any already garbled characters on the way. Then it proves the repair with the real parser itself: every script is parsed whole and its error count printed. A companion that parses with zero errors stands. Every variable carries the p511 prefix.) ==='
$p511b64 = 'aW1wb3J0IG9zLCBnbG9iCgpGT0xERVIgPSByIkM6XFVzZXJzXEFkbWluXHBoaS10b29scyIKZmlsZXMgPSBzb3J0ZWQoZ2xvYi5nbG9iKG9zLnBhdGguam9pbihGT0xERVIsICIqLnBzMSIpKSkKcHJpbnQoIlBTMSBDT1VOVD0lZCIgJSBsZW4oZmlsZXMpKQpmb3IgcGF0aCBpbiBmaWxlczoKICAgIG5hbWUgPSBvcy5wYXRoLmJhc2VuYW1lKHBhdGgpCiAgICByYXcgPSBvcGVuKHBhdGgsICJyYiIpLnJlYWQoKQogICAgYm9tID0gcmF3WzozXSA9PSBiIlx4ZWZceGJiXHhiZiIKICAgIG5vbmFzY2lpID0gc3VtKDEgZm9yIGIgaW4gcmF3IGlmIGIgPiAxMjcpCiAgICBwcmludCgiRklMRSAlcyBieXRlcz0lZCBib209JWQgbm9uYXNjaWk9JWQiICUgKG5hbWUsIGxlbihyYXcpLCAxIGlmIGJvbSBlbHNlIDAsIG5vbmFzY2lpKSkKICAgIGlmIGJvbSBhbmQgbm9uYXNjaWkgPT0gMDoKICAgICAgICBwcmludCgiQUNUICVzIG5vbmUtbmVlZGVkIiAlIG5hbWUpCiAgICAgICAgY29udGludWUKICAgIHRyeToKICAgICAgICB0ZXh0ID0gcmF3LmRlY29kZSgidXRmLTgtc2lnIikKICAgIGV4Y2VwdCBVbmljb2RlRGVjb2RlRXJyb3I6CiAgICAgICAgdGV4dCA9IHJhdy5kZWNvZGUoImNwMTI1MiIpCiAgICAgICAgcHJpbnQoIkFDVCAlcyBkZWNvZGVkLWFzLWNwMTI1MiIgJSBuYW1lKQogICAgaWYgIlx1MDBlMlx1MjBhYyIgaW4gdGV4dCBvciAiXHUwMGMzIiBpbiB0ZXh0OgogICAgICAgIHRyeToKICAgICAgICAgICAgdGV4dCA9IHRleHQuZW5jb2RlKCJjcDEyNTIiKS5kZWNvZGUoInV0Zi04IikKICAgICAgICAgICAgcHJpbnQoIkFDVCAlcyBtb2ppYmFrZS1yZXBhaXJlZCIgJSBuYW1lKQogICAgICAgIGV4Y2VwdCAoVW5pY29kZUVuY29kZUVycm9yLCBVbmljb2RlRGVjb2RlRXJyb3IpOgogICAgICAgICAgICBwcmludCgiQUNUICVzIG1vamliYWtlLXJlcGFpci1za2lwcGVkIiAlIG5hbWUpCiAgICBiYWsgPSBwYXRoICsgIi5iYWs1MTEiCiAgICBpZiBub3Qgb3MucGF0aC5leGlzdHMoYmFrKToKICAgICAgICBvcGVuKGJhaywgIndiIikud3JpdGUocmF3KQogICAgb3BlbihwYXRoLCAid2IiKS53cml0ZShiIlx4ZWZceGJiXHhiZiIgKyB0ZXh0LmVuY29kZSgidXRmLTgiKSkKICAgIGNoayA9IG9wZW4ocGF0aCwgInJiIikucmVhZCgpCiAgICBwcmludCgiQUNUICVzIHJld3JpdHRlbiBieXRlcz0lZCBib21Ob3c9JWQiICUgKG5hbWUsIGxlbihjaGspLCAxIGlmIGNoa1s6M10gPT0gYiJceGVmXHhiYlx4YmYiIGVsc2UgMCkpCnByaW50KCJSRVBBSVIgUEFTUyBET05FIikK'
$p511py = Join-Path $env:TEMP 'patch511.py'
[IO.File]::WriteAllBytes($p511py, [Convert]::FromBase64String($p511b64))
$p511exe = 'C:\Users\Admin\AppData\Local\Microsoft\WindowsApps\python.exe'
& $p511exe $p511py | ForEach-Object { Write-Output $_ }
$p511bad = 0
$p511files = Get-ChildItem 'C:\Users\Admin\phi-tools' -Filter '*.ps1' -ErrorAction SilentlyContinue
foreach ($p511f in $p511files) {
  $p511tokens = $null
  $p511errors = $null
  [System.Management.Automation.Language.Parser]::ParseFile($p511f.FullName, [ref]$p511tokens, [ref]$p511errors) | Out-Null
  $p511n = 0
  if ($p511errors) { $p511n = $p511errors.Count }
  Write-Output ('PARSE ' + $p511f.Name + ' errors=' + $p511n)
  if ($p511n -gt 0) { $p511bad = 1; Write-Output ('FIRSTERR ' + $p511errors[0].Message) }
}
Write-Output ('PARSE BAD=' + $p511bad)
if ($p511bad -eq 0) { Write-Output 'PHI P511 VERDICT: COMPANIONS PARSE CLEAN' } else { Write-Output 'PHI P511 VERDICT: FAULTS REMAIN - PRINTED ABOVE' }
Write-Output 'JOB 511 DONE'
```
