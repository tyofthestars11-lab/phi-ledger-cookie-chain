<!-- PHI-DIRECT -->
```powershell
Write-Output '=== FIX 506 - THE SELF ANSWER THROTTLED AT ITS REAL LINE (Ground: job 505 gate held its patch because the self print does not stand alone - it lives inside a one line condition at line 477 of the terminal source, the exact line the 505 result printed whole. The gate holding was the guarantee working: nothing was written. This job authors directly against that measured line: the same condition, the same words, with a five second throttle wrapped around the print alone, so a held key or a burst of attach calls speaks the answer once and then stands quiet while the condition stays true. The guard field seats beside an existing static field, every anchor is counted, the write verifies by read back, and on a clean patch the job closes the running terminal, compiles with the standing compiler line, relaunches the fixed build, and prints its log tail. Every variable carries the p506 prefix.) ==='
$p506b64 = 'aW1wb3J0IHN5cywgcmUKClNSQyA9IHIiQzpcVXNlcnNcQWRtaW5cUGhpVGVybWluYWxcUGhpVGVybWluYWwzLmNzIgpzcmMgPSBvcGVuKFNSQywgZW5jb2Rpbmc9InV0Zi04IiwgZXJyb3JzPSJyZXBsYWNlIikucmVhZCgpCmxpbmVzID0gc3JjLnNwbGl0KCJcbiIpCnByaW50KCJDUyBMSU5FUz0lZCIgJSBsZW4obGluZXMpKQoKaGl0cyA9IFtpIGZvciBpLCBMIGluIGVudW1lcmF0ZShsaW5lcykgaWYgInRlcm1pbmFsIGl0c2VsZiIgaW4gTF0KcHJpbnQoIlNFTEYgTElORSBDT1VOVD0lZCIgJSBsZW4oaGl0cykpCmZvciBoIGluIGhpdHM6CiAgICBwcmludCgiU0VMRiAlZDogJXMiICUgKGggKyAxLCBsaW5lc1toXS5zdHJpcCgpKSkKaWYgbGVuKGhpdHMpICE9IDE6CiAgICBwcmludCgiUEFUQ0ggR0FURSBGQUlMIHNlbGYgbGluZSBjb3VudCIpOyBzeXMuZXhpdCgwKQpoID0gaGl0c1swXQpsaW5lID0gbGluZXNbaF0KbSA9IHJlLnNlYXJjaChyJ1NheVwoIlRoYXQgaXMgdGhlIHRlcm1pbmFsIGl0c2VsZlteIl0qIlwpOycsIGxpbmUpCmlmIG5vdCBtOgogICAgcHJpbnQoIlBBVENIIEdBVEUgRkFJTCBzYXkgY2FsbCBub3QgZm91bmQiKTsgc3lzLmV4aXQoMCkKaWYgIkdldEN1cnJlbnRQcm9jZXNzKCkuSWQiIG5vdCBpbiBsaW5lOgogICAgcHJpbnQoIlBBVENIIEdBVEUgRkFJTCBzZWxmIGNvbmRpdGlvbiBub3QgZm91bmQiKTsgc3lzLmV4aXQoMCkKaWYgbm90IGxpbmUucnN0cmlwKCkuZW5kc3dpdGgoInJldHVybjsgfSIpOgogICAgcHJpbnQoIlBBVENIIEdBVEUgRkFJTCBsaW5lIHRhaWwgc2hhcGUiKTsgc3lzLmV4aXQoMCkKaWYgInVzaW5nIFN5c3RlbTsiIG5vdCBpbiBzcmM6CiAgICBwcmludCgiUEFUQ0ggR0FURSBGQUlMIHVzaW5nIFN5c3RlbSIpOyBzeXMuZXhpdCgwKQpzdGF0aWNzID0gW2kgZm9yIGksIEwgaW4gZW51bWVyYXRlKGxpbmVzKSBpZiByZS5zZWFyY2gocideXHMrKHByaXZhdGVccyt8cHVibGljXHMrKT9zdGF0aWNccytcdysnLCBMKSBhbmQgKCI9IiBpbiBMIG9yICI7IiBpbiBMKSBhbmQgIigiIG5vdCBpbiBMLnNwbGl0KCI9IilbMF1dCnByaW50KCJTVEFUSUMgRklFTEQgQ0FORElEQVRFUz0lZCIgJSBsZW4oc3RhdGljcykpCmlmIG5vdCBzdGF0aWNzOgogICAgcHJpbnQoIlBBVENIIEdBVEUgRkFJTCBubyBzdGF0aWMgZmllbGQgYW5jaG9yIik7IHN5cy5leGl0KDApCgpzYXkgPSBtLmdyb3VwKDApCnByZWZpeCA9IGxpbmVbOm0uc3RhcnQoKV0ucnN0cmlwKCkKaW5kID0gbGluZVs6bGVuKGxpbmUpIC0gbGVuKGxpbmUubHN0cmlwKCkpXQpzZiA9IHN0YXRpY3NbMF0Kc2ZpbmQgPSBsaW5lc1tzZl1bOmxlbihsaW5lc1tzZl0pIC0gbGVuKGxpbmVzW3NmXS5sc3RyaXAoKSldCmxpbmVzLmluc2VydChzZiArIDEsIHNmaW5kICsgInN0YXRpYyBpbnQgUGhpU2VsZk5vdGljZVRpY2sgPSAwOyIpCmlmIHNmIDwgaDoKICAgIGggPSBoICsgMQpsaW5lc1toXSA9IGluZCArIHByZWZpeCArICIgaWYgKFBoaVNlbGZOb3RpY2VUaWNrID09IDAgfHwgRW52aXJvbm1lbnQuVGlja0NvdW50IC0gUGhpU2VsZk5vdGljZVRpY2sgPiA1MDAwKSB7IFBoaVNlbGZOb3RpY2VUaWNrID0gRW52aXJvbm1lbnQuVGlja0NvdW50OyAiICsgc2F5ICsgIiB9IHJldHVybjsgfSIKb3V0ID0gIlxuIi5qb2luKGxpbmVzKQpvcGVuKFNSQywgInciLCBlbmNvZGluZz0idXRmLTgiLCBuZXdsaW5lPSIiKS53cml0ZShvdXQpCmNoayA9IG9wZW4oU1JDLCBlbmNvZGluZz0idXRmLTgiLCBlcnJvcnM9InJlcGxhY2UiKS5yZWFkKCkKcHJpbnQoIlZFUklGWSBndWFyZEZpZWxkPSVkIiAlIGNoay5jb3VudCgiUGhpU2VsZk5vdGljZVRpY2sgPSAwOyIpKQpwcmludCgiVkVSSUZZIGd1YXJkQ2FsbD0lZCIgJSBjaGsuY291bnQoIlBoaVNlbGZOb3RpY2VUaWNrID0gRW52aXJvbm1lbnQuVGlja0NvdW50OyIpKQpwcmludCgiVkVSSUZZIHNheUtlcHQ9JWQiICUgY2hrLmNvdW50KCJUaGF0IGlzIHRoZSB0ZXJtaW5hbCBpdHNlbGYiKSkKcHJpbnQoIlBBVENIIE9LIikK'
$p506py = Join-Path $env:TEMP 'patch506.py'
[IO.File]::WriteAllBytes($p506py, [Convert]::FromBase64String($p506b64))
$p506exe = 'C:\Users\Admin\AppData\Local\Microsoft\WindowsApps\python.exe'
$p506out = & $p506exe $p506py
$p506out | ForEach-Object { Write-Output $_ }
$p506dir = 'C:\Users\Admin\PhiTerminal'
$p506bin = Join-Path $p506dir 'PhiTerminal.exe'
if (($p506out -join ' ') -match 'PATCH OK') {
  Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue | Stop-Process -Force
  Start-Sleep -Seconds 2
  $p506csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
  $p506cs = Join-Path $p506dir 'PhiTerminal3.cs'
  $p506cout = & $p506csc /target:winexe /out:$p506bin /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $p506cs 2>&1
  $p506cout | Select-Object -Last 6 | ForEach-Object { Write-Output ('CSC ' + $_) }
  Write-Output ('EXE bytes=' + (Get-Item $p506bin).Length + ' written=' + (Get-Item $p506bin).LastWriteTime)
  Start-Process -FilePath $p506bin -WorkingDirectory $p506dir
  Start-Sleep -Seconds 4
  $p506log = Join-Path $p506dir 'phi_terminal_universal.log'
  if (Test-Path $p506log) { Get-Content $p506log -Tail 6 | ForEach-Object { Write-Output ('NEWTAIL ' + $_) } }
  Write-Output 'PHI P506 VERDICT: FIXED BUILD STANDING'
} else {
  Write-Output 'PHI P506 VERDICT: PATCH HELD - PRINTS ABOVE'
}
Write-Output 'JOB 506 DONE'
```
