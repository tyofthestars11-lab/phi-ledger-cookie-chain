<!-- PHI-DIRECT -->
```powershell
Write-Output '=== KEY TRUTH 483 - WHAT THE BOARD SENDS FOR TILDE (Ground: terminal v5.3 stands, pid 47648 at its seat, hook and poll both live on the tilde key, and Tyree at his board reports the tilde press clicks the other key. Two reads settle it. First, the terminal log itself: every tilde press that reached the panel since v5.3 stood is counted and its last lines printed, so an arrived press and a never-arrived press read differently at a glance. Second, a small listener is compiled and left standing for twelve minutes beside the terminal: it hears every key on the board and writes each key code and its name into keycatch.log in the terminal folder, throttled per key, then closes itself. Whatever code his board truly sends for that keycap stands in that log in its own words, and the toggle moves to the code it truly sends. Every variable carries the kt483 prefix.) ==='
$kt483dir = 'C:\Users\Admin\PhiTerminal'
$kt483log = Join-Path $kt483dir 'phi_terminal_universal.log'
$kt483via = 0; $kt483show = 0; $kt483hide = 0
if (Test-Path $kt483log) {
  $kt483all = @(Get-Content $kt483log)
  $kt483via = @($kt483all | Select-String -SimpleMatch 'TILDE VIA').Count
  $kt483show = @($kt483all | Select-String -SimpleMatch 'TILDE SHOW').Count
  $kt483hide = @($kt483all | Select-String -SimpleMatch 'TILDE HIDE').Count
  $kt483tl = @($kt483all | Select-String -SimpleMatch 'TILDE' | Select-Object -Last 5)
  foreach ($kt483t in $kt483tl) { Write-Output ('TLOG ' + $kt483t.Line) }
}
Write-Output ('TILDECOUNT via=' + $kt483via + ' show=' + $kt483show + ' hide=' + $kt483hide)
$kt483panel = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
if ($kt483panel.Count -gt 0) { Write-Output ('PANEL pid=' + $kt483panel[0].Id) } else { Write-Output 'PANEL NONE' }
$kt483b64 = @'
dXNpbmcgU3lzdGVtOwp1c2luZyBTeXN0ZW0uQ29sbGVjdGlvbnMuR2VuZXJpYzsKdXNpbmcgU3lzdGVtLkRpYWdub3N0aWNzOwp1
c2luZyBTeXN0ZW0uSU87CnVzaW5nIFN5c3RlbS5SdW50aW1lLkludGVyb3BTZXJ2aWNlczsKdXNpbmcgU3lzdGVtLldpbmRvd3Mu
Rm9ybXM7CgpuYW1lc3BhY2UgS2V5Q2F0Y2gKewogICAgc3RhdGljIGNsYXNzIFByb2dyYW0KICAgIHsKICAgICAgICBbU1RBVGhy
ZWFkXQogICAgICAgIHN0YXRpYyB2b2lkIE1haW4oKQogICAgICAgIHsKICAgICAgICAgICAgQXBwbGljYXRpb24uRW5hYmxlVmlz
dWFsU3R5bGVzKCk7CiAgICAgICAgICAgIEFwcGxpY2F0aW9uLlNldENvbXBhdGlibGVUZXh0UmVuZGVyaW5nRGVmYXVsdChmYWxz
ZSk7CiAgICAgICAgICAgIEFwcGxpY2F0aW9uLlJ1bihuZXcgQ2F0Y2hGb3JtKCkpOwogICAgICAgIH0KICAgIH0KCiAgICBwdWJs
aWMgY2xhc3MgQ2F0Y2hGb3JtIDogRm9ybQogICAgewogICAgICAgIHByaXZhdGUgSW50UHRyIGhvb2tJZCA9IEludFB0ci5aZXJv
OwogICAgICAgIHByaXZhdGUgY29uc3QgaW50IFdIX0tFWUJPQVJEX0xMID0gMTM7CiAgICAgICAgcHJpdmF0ZSBjb25zdCBpbnQg
V01fS0VZRE9XTiA9IDB4MDEwMDsKICAgICAgICBwcml2YXRlIGNvbnN0IGludCBXTV9TWVNLRVlET1dOID0gMHgwMTA0OwogICAg
ICAgIHByaXZhdGUgZGVsZWdhdGUgSW50UHRyIEhvb2tQcm9jKGludCBjb2RlLCBJbnRQdHIgd3AsIEludFB0ciBscCk7CiAgICAg
ICAgcHJpdmF0ZSBIb29rUHJvYyBwcm9jOwogICAgICAgIHByaXZhdGUgRGljdGlvbmFyeTxpbnQsIGxvbmc+IGxhc3RMb2cgPSBu
ZXcgRGljdGlvbmFyeTxpbnQsIGxvbmc+KCk7CiAgICAgICAgcHJpdmF0ZSBEYXRlVGltZSBlbmRBdDsKICAgICAgICBbRGxsSW1w
b3J0KCJ1c2VyMzIuZGxsIildIHN0YXRpYyBleHRlcm4gSW50UHRyIFNldFdpbmRvd3NIb29rRXgoaW50IGlkLCBIb29rUHJvYyBj
YiwgSW50UHRyIG1vZCwgdWludCB0aWQpOwogICAgICAgIFtEbGxJbXBvcnQoInVzZXIzMi5kbGwiKV0gc3RhdGljIGV4dGVybiBi
b29sIFVuaG9va1dpbmRvd3NIb29rRXgoSW50UHRyIGhrKTsKICAgICAgICBbRGxsSW1wb3J0KCJ1c2VyMzIuZGxsIildIHN0YXRp
YyBleHRlcm4gSW50UHRyIENhbGxOZXh0SG9va0V4KEludFB0ciBoaywgaW50IGNvZGUsIEludFB0ciB3cCwgSW50UHRyIGxwKTsK
ICAgICAgICBbRGxsSW1wb3J0KCJrZXJuZWwzMi5kbGwiKV0gc3RhdGljIGV4dGVybiBJbnRQdHIgR2V0TW9kdWxlSGFuZGxlKHN0
cmluZyBuYW1lKTsKCiAgICAgICAgcHVibGljIENhdGNoRm9ybSgpCiAgICAgICAgewogICAgICAgICAgICB0aGlzLlNob3dJblRh
c2tiYXIgPSBmYWxzZTsKICAgICAgICAgICAgdGhpcy5XaW5kb3dTdGF0ZSA9IEZvcm1XaW5kb3dTdGF0ZS5NaW5pbWl6ZWQ7CiAg
ICAgICAgICAgIHRoaXMuRm9ybUJvcmRlclN0eWxlID0gRm9ybUJvcmRlclN0eWxlLkZpeGVkVG9vbFdpbmRvdzsKICAgICAgICAg
ICAgdGhpcy5PcGFjaXR5ID0gMDsKICAgICAgICAgICAgdGhpcy5TaXplID0gbmV3IFN5c3RlbS5EcmF3aW5nLlNpemUoMSwgMSk7
CiAgICAgICAgICAgIGVuZEF0ID0gRGF0ZVRpbWUuTm93LkFkZE1pbnV0ZXMoMTIpOwogICAgICAgICAgICBMb2coIktFWUNBVENI
IFNUQVJUIik7CiAgICAgICAgICAgIHByb2MgPSBIb29rQ2FsbGJhY2s7CiAgICAgICAgICAgIGhvb2tJZCA9IFNldFdpbmRvd3NI
b29rRXgoV0hfS0VZQk9BUkRfTEwsIHByb2MsIEdldE1vZHVsZUhhbmRsZShQcm9jZXNzLkdldEN1cnJlbnRQcm9jZXNzKCkuTWFp
bk1vZHVsZS5Nb2R1bGVOYW1lKSwgMCk7CiAgICAgICAgICAgIExvZygiS0VZQ0FUQ0ggSE9PSz0iICsgaG9va0lkLlRvU3RyaW5n
KCkpOwogICAgICAgICAgICB2YXIgdCA9IG5ldyBUaW1lcigpOwogICAgICAgICAgICB0LkludGVydmFsID0gNTAwMDsKICAgICAg
ICAgICAgdC5UaWNrICs9IChzLCBlKSA9PiB7IGlmIChEYXRlVGltZS5Ob3cgPiBlbmRBdCkgeyBMb2coIktFWUNBVENIIEVORCIp
OyB0aGlzLkNsb3NlKCk7IH0gfTsKICAgICAgICAgICAgdC5TdGFydCgpOwogICAgICAgIH0KICAgICAgICBwcml2YXRlIEludFB0
ciBIb29rQ2FsbGJhY2soaW50IGNvZGUsIEludFB0ciB3cCwgSW50UHRyIGxwKQogICAgICAgIHsKICAgICAgICAgICAgdHJ5CiAg
ICAgICAgICAgIHsKICAgICAgICAgICAgICAgIGlmIChjb2RlID49IDAgJiYgKHdwID09IChJbnRQdHIpV01fS0VZRE9XTiB8fCB3
cCA9PSAoSW50UHRyKVdNX1NZU0tFWURPV04pKQogICAgICAgICAgICAgICAgewogICAgICAgICAgICAgICAgICAgIGludCB2ayA9
IE1hcnNoYWwuUmVhZEludDMyKGxwKTsKICAgICAgICAgICAgICAgICAgICBsb25nIG5vdyA9IERhdGVUaW1lLlV0Y05vdy5UaWNr
cyAvIDEwMDAwOwogICAgICAgICAgICAgICAgICAgIGxvbmcgcHJldjsKICAgICAgICAgICAgICAgICAgICBpZiAoIWxhc3RMb2cu
VHJ5R2V0VmFsdWUodmssIG91dCBwcmV2KSB8fCBub3cgLSBwcmV2ID4gMTAwMCkKICAgICAgICAgICAgICAgICAgICB7CiAgICAg
ICAgICAgICAgICAgICAgICAgIGxhc3RMb2dbdmtdID0gbm93OwogICAgICAgICAgICAgICAgICAgICAgICBMb2coIktFWSB2az0i
ICsgdmsgKyAiIG5hbWU9IiArICgoS2V5cyl2aykuVG9TdHJpbmcoKSk7CiAgICAgICAgICAgICAgICAgICAgfQogICAgICAgICAg
ICAgICAgfQogICAgICAgICAgICB9CiAgICAgICAgICAgIGNhdGNoIHsgfQogICAgICAgICAgICByZXR1cm4gQ2FsbE5leHRIb29r
RXgoaG9va0lkLCBjb2RlLCB3cCwgbHApOwogICAgICAgIH0KICAgICAgICBwcm90ZWN0ZWQgb3ZlcnJpZGUgdm9pZCBPbkZvcm1D
bG9zZWQoRm9ybUNsb3NlZEV2ZW50QXJncyBlKQogICAgICAgIHsKICAgICAgICAgICAgVW5ob29rV2luZG93c0hvb2tFeChob29r
SWQpOwogICAgICAgICAgICBiYXNlLk9uRm9ybUNsb3NlZChlKTsKICAgICAgICB9CiAgICAgICAgcHVibGljIHN0YXRpYyB2b2lk
IExvZyhzdHJpbmcgcykKICAgICAgICB7CiAgICAgICAgICAgIHRyeQogICAgICAgICAgICB7CiAgICAgICAgICAgICAgICBzdHJp
bmcgcCA9IFBhdGguQ29tYmluZShBcHBsaWNhdGlvbi5TdGFydHVwUGF0aCwgImtleWNhdGNoLmxvZyIpOwogICAgICAgICAgICAg
ICAgRmlsZS5BcHBlbmRBbGxUZXh0KHAsIERhdGVUaW1lLk5vdy5Ub1N0cmluZygieXl5eS1NTS1kZCBISDptbTpzcyIpICsgIiAi
ICsgcyArIEVudmlyb25tZW50Lk5ld0xpbmUpOwogICAgICAgICAgICB9CiAgICAgICAgICAgIGNhdGNoIHsgfQogICAgICAgIH0K
ICAgIH0KfQo=
'@
$kt483csrc = Join-Path $kt483dir 'KeyCatch.cs'
[IO.File]::WriteAllBytes($kt483csrc, [Convert]::FromBase64String($kt483b64))
$kt483old = @(Get-Process -Name 'KeyCatch' -ErrorAction SilentlyContinue)
foreach ($kt483o in $kt483old) { Stop-Process -Id $kt483o.Id -Force -ErrorAction SilentlyContinue }
$kt483csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$kt483cexe = Join-Path $kt483dir 'KeyCatch.exe'
& $kt483csc /nologo /target:winexe /out:$kt483cexe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $kt483csrc | ForEach-Object { Write-Output ('CSC ' + $_) }
$kt483bytes = 0; if (Test-Path $kt483cexe) { $kt483bytes = (Get-Item $kt483cexe).Length }
Write-Output ('CATCHER BYTES=' + $kt483bytes)
$kt483cpid = 0; $kt483cstate = 'NOT-LAUNCHED'
if ($kt483bytes -gt 0) {
  $kt483proc = Start-Process -FilePath $kt483cexe -WorkingDirectory $kt483dir -PassThru
  Start-Sleep -Seconds 2
  $kt483chk = Get-Process -Id $kt483proc.Id -ErrorAction SilentlyContinue
  if ($kt483chk) { $kt483cstate = 'STANDS'; $kt483cpid = $kt483proc.Id } else { $kt483cstate = 'EXITED' }
}
Write-Output ('PHI KT483 VERDICT: KEY TRUTH via=' + $kt483via + ' show=' + $kt483show + ' catcher=' + $kt483cstate + ' cpid=' + $kt483cpid)
Write-Output 'JOB 483 DONE'
```
