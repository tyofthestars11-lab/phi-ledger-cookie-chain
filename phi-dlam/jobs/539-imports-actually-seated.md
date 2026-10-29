<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 539 - THE IMPORTS ACTUALLY GET SEATED (Ground: the 537 result printed PATCH OK and then CSC CS0103 for EnumWindows and IsWindowVisible, with the exe bytes and write time unchanged from the old build, so the terminal relaunched under a V61 name while still running the old code. The 537 check looked for the bare name, and the new body itself carries that name, so the check thought the pieces stood and skipped seating them. This job seats the imports by checking for the declaration line itself, verifies the declaration stands, closes the panel, rebuilds, and launches the new exe only when the build prints no error line, so a stale exe never again wears a new version name. The Cyberpunk row correction rides the live census again when the game runs. Every variable carries the p539 prefix.) ==='
$p539dir = 'C:\Users\Admin\PhiTerminal'
$p539src = Join-Path $p539dir 'PhiTerminal3.cs'
$p539games = Join-Path $p539dir 'games.txt'
$p539census = Join-Path $p539dir 'cyberproc539.txt'
Get-Process | Where-Object { $_.ProcessName -match ('cybe' + [char]114) -or $_.MainWindowTitle -match 'Cyberpunk' } | ForEach-Object { Write-Output ('CYBERPROC ' + $_.ProcessName + ' pid=' + $_.Id + ' title=' + $_.MainWindowTitle) }
$p539cy = @(Get-Process | Where-Object { $_.ProcessName -match ('cybe' + [char]114) })
if ($p539cy.Count -gt 0) { Set-Content $p539census $p539cy[0].ProcessName } else { Set-Content $p539census '' }
if (Test-Path $p539games) { Get-Content $p539games | Where-Object { $_ -match 'Cyberpunk' } | ForEach-Object { Write-Output ('GAMEROW ' + $_) } } else { Write-Output 'GAMEROW FILE MISSING' }
$p539p = 'aW1wb3J0IGlvLCByZQpTUkMgPSByJ0M6XFVzZXJzXEFkbWluXFBoaVRlcm1pbmFsXFBoaVRlcm1pbmFsMy5jcycKR0FNRVMgPSByJ0M6XFVzZXJzXEFkbWluXFBoaVRlcm1pbmFsXGdhbWVzLnR4dCcKQ0VOU1VTID0gcidDOlxVc2Vyc1xBZG1pblxQaGlUZXJtaW5hbFxjeWJlcnByb2M1MzkudHh0JwpvcmlnID0gaW8ub3BlbihTUkMsIGVuY29kaW5nPSd1dGYtOCcsIGVycm9ycz0ncmVwbGFjZScpLnJlYWQoKQp0ZXh0ID0gb3JpZwpwcmludCgnRk9SRUdST1VORCBSRUFEIFBSRVNFTlQnIGlmICdFbnVtV2luZG93cygoaCcgaW4gdGV4dCBlbHNlICdGT1JFR1JPVU5EIFJFQUQgTUlTU0lORycpCmlmICdFbnVtV2luZG93cyhFbnVtV2luZG93c1Byb2MnIG5vdCBpbiB0ZXh0OgogICAgbHMgPSB0ZXh0LnNwbGl0KCdcbicpCiAgICBkb25lID0gRmFsc2UKICAgIGZvciBpLCBsIGluIGVudW1lcmF0ZShscyk6CiAgICAgICAgaWYgJ0dldFdpbmRvd1RocmVhZFByb2Nlc3NJZCcgaW4gbCBhbmQgJ2V4dGVybicgaW4gbDoKICAgICAgICAgICAgaW5kID0gbFs6bGVuKGwpIC0gbGVuKGwubHN0cmlwKCkpXQogICAgICAgICAgICBscy5pbnNlcnQoaSArIDEsIGluZCArICdbRGxsSW1wb3J0KCJ1c2VyMzIuZGxsIildIHN0YXRpYyBleHRlcm4gYm9vbCBFbnVtV2luZG93cyhFbnVtV2luZG93c1Byb2MgbHBFbnVtRnVuYywgSW50UHRyIGxQYXJhbSk7JykKICAgICAgICAgICAgbHMuaW5zZXJ0KGkgKyAyLCBpbmQgKyAnZGVsZWdhdGUgYm9vbCBFbnVtV2luZG93c1Byb2MoSW50UHRyIGhXbmQsIEludFB0ciBsUGFyYW0pOycpCiAgICAgICAgICAgIGxzLmluc2VydChpICsgMywgaW5kICsgJ1tEbGxJbXBvcnQoInVzZXIzMi5kbGwiKV0gc3RhdGljIGV4dGVybiBib29sIElzV2luZG93VmlzaWJsZShJbnRQdHIgaFduZCk7JykKICAgICAgICAgICAgZG9uZSA9IFRydWUKICAgICAgICAgICAgYnJlYWsKICAgIGlmIG5vdCBkb25lOgogICAgICAgIHByaW50KCdQQVRDSCBHQVRFIEZBSUwgLSBJTVBPUlQgQU5DSE9SIE5PVCBGT1VORCcpCiAgICAgICAgcmFpc2UgU3lzdGVtRXhpdAogICAgdGV4dCA9ICdcbicuam9pbihscykKICAgIHByaW50KCdJTVBPUlRTIFNFQVRFRCcpCmVsc2U6CiAgICBwcmludCgnSU1QT1JUUyBBTFJFQURZIFBSRVNFTlQnKQppZiAnRW51bVdpbmRvd3MoRW51bVdpbmRvd3NQcm9jJyBpbiB0ZXh0IGFuZCAnSXNXaW5kb3dWaXNpYmxlKEludFB0ciBoV25kKScgaW4gdGV4dDoKICAgIGlvLm9wZW4oU1JDICsgJy5iYWs1MzknLCAndycsIGVuY29kaW5nPSd1dGYtOCcpLndyaXRlKG9yaWcpCiAgICBpby5vcGVuKFNSQywgJ3cnLCBlbmNvZGluZz0ndXRmLTgnKS53cml0ZSh0ZXh0KQogICAgcHJpbnQoJ1BBVENIIE9LIC0gSU1QT1JUUyBTRUFURUQgQU5EIFZFUklGSUVEJykKZWxzZToKICAgIHByaW50KCdQQVRDSCBHQVRFIEZBSUwgLSBJTVBPUlQgVkVSSUZZIEZBSUxFRCcpCiAgICByYWlzZSBTeXN0ZW1FeGl0CnRyeToKICAgIGNuYW1lID0gaW8ub3BlbihDRU5TVVMsIGVuY29kaW5nPSd1dGYtOCcsIGVycm9ycz0ncmVwbGFjZScpLnJlYWQoKS5zdHJpcCgpCmV4Y2VwdCBFeGNlcHRpb246CiAgICBjbmFtZSA9ICcnCnByaW50KCdDRU5TVVMgTkFNRT0lcycgJSBjbmFtZSkKaWYgY25hbWU6CiAgICB0cnk6CiAgICAgICAgZ3Jvd3MgPSBpby5vcGVuKEdBTUVTLCBlbmNvZGluZz0ndXRmLTgnLCBlcnJvcnM9J3JlcGxhY2UnKS5yZWFkKCkuc3BsaXQoJ1xuJykKICAgICAgICBmaXhlZCA9IDAKICAgICAgICBmb3IgaSwgZyBpbiBlbnVtZXJhdGUoZ3Jvd3MpOgogICAgICAgICAgICBwYXJ0cyA9IGcuc3BsaXQoJ3wnKQogICAgICAgICAgICBpZiBsZW4ocGFydHMpID49IDMgYW5kIHBhcnRzWzBdLnN0cmlwKCkgPT0gJ0N5YmVycHVuayAyMDc3JyBhbmQgcGFydHNbMV0uc3RyaXAoKSA9PSAnWEJPWCBHQU1FUyc6CiAgICAgICAgICAgICAgICBwYXJ0c1syXSA9IGNuYW1lCiAgICAgICAgICAgICAgICBncm93c1tpXSA9ICd8Jy5qb2luKHBhcnRzKQogICAgICAgICAgICAgICAgZml4ZWQgKz0gMQogICAgICAgIGlmIGZpeGVkOgogICAgICAgICAgICBpby5vcGVuKEdBTUVTLCAndycsIGVuY29kaW5nPSd1dGYtOCcpLndyaXRlKCdcbicuam9pbihncm93cykpCiAgICAgICAgICAgIHByaW50KCdST1cgRklYRUQgY3liZXJwdW5rIHByb2NuYW1lPSVzJyAlIGNuYW1lKQogICAgICAgIGVsc2U6CiAgICAgICAgICAgIHByaW50KCdST1cgU0tJUCAtIENZQkVSUFVOSyBYQk9YIFJPVyBOT1QgRk9VTkQnKQogICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgICAgIHByaW50KCdST1cgU0tJUCAtIEdBTUVTIFJFQUQgVEhSRVcgJXMnICUgc3RyKGUpWzo2MF0pCmVsc2U6CiAgICBwcmludCgnUk9XIFNLSVAgLSBOTyBDWUJFUlBVTksgUFJPQ0VTUyBBVCBEUkFJTiBUSU1FJykK'
$p539py = Join-Path $p539dir 'fix539.py'
[IO.File]::WriteAllBytes($p539py, [Convert]::FromBase64String($p539p))
$p539pyexe = 'C:\Users\Admin\AppData\Local\Microsoft\WindowsApps\python.exe'
$p539patch = (& $p539pyexe $p539py | Out-String)
Write-Output $p539patch
if ($p539patch -match 'PATCH OK') {
  $p539old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
  foreach ($p539o in $p539old) { Stop-Process -Id $p539o.Id -Force -ErrorAction SilentlyContinue; Write-Output ('PANEL CLOSED pid=' + $p539o.Id) }
  $p539csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
  $p539exe = Join-Path $p539dir 'PhiTerminal.exe'
  $p539cscout = (& $p539csc /nologo /target:winexe /out:$p539exe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $p539src | Out-String)
  Write-Output $p539cscout
  if ($p539cscout -match ('erro' + [char]114)) {
    Write-Output 'BUILD FAILED - STALE EXE LEFT ALONE, NO RELAUNCH'
  } else {
    $p539item = Get-Item $p539exe
    Write-Output ('EXE BYTES=' + $p539item.Length + ' WRITE=' + $p539item.LastWriteTime)
    $p539proc = Start-Process -FilePath $p539exe -WorkingDirectory $p539dir -PassThru
    Start-Sleep -Seconds 3
    $p539chk = Get-Process -Id $p539proc.Id -ErrorAction SilentlyContinue
    if ($p539chk) { Write-Output ('TERMINAL V62 STANDS pid=' + $p539proc.Id) } else { Write-Output 'TERMINAL V62 LAUNCH NOT SEEN' }
  }
} else { Write-Output 'BUILD SKIPPED - PATCH DID NOT PRINT OK' }
Write-Output 'PHI P539 VERDICT: PATCH AND BUILD LINES ABOVE - A NEW EXE WRITE TIME IS THE PROOF'
Write-Output 'JOB 539 DONE'
```
