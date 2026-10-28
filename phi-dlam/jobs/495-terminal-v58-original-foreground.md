<!-- PHI-DIRECT -->
```powershell
Write-Output '=== TERMINAL V5.8 495 - THE ORIGINAL FOREGROUND CODE, READ WHOLE AND SEATED AS ITSELF (Ground: Tyree, assembled whole from his burst: there were two attach options originally, attach selected and attach foreground; the foreground one actually attached, the terminal acknowledged the game; for attach selected it does not, it is like clicking on an empty space; replace attach selected with attach foreground; you are stuck on selected; the code in use is empty. The archaeology is read, not theorized: the original pair stands in the v4 source carried inside job 469, where AttachForeground reads the live foreground window at the click, takes its process, attaches, and SetAttached speaks the game name and pid - the acknowledgment he remembers. Jobs 486 and 487 never replaced that function body; they built roads around it, a 250ms remembered-window watcher and a remembered pid fallback, and job 490 pointed the button at the function without ever printing its body. This job prints both current bodies whole into the result, then seats the original v4 AttachForeground body verbatim as the function itself - byte for byte the code that attached in his hands. The button from 490 already calls it and already wears his name, ATTACHED FOREGROUND SELECTED. Source backs up, panel closes, exe recompiles, window relaunches, verdict prints TERMINAL V58 with fgRestored. Every variable carries the at495 prefix.) ==='
$at495dir = 'C:\Users\Admin\PhiTerminal'
$at495src = Join-Path $at495dir 'PhiTerminal3.cs'
$at495lines = @(Get-Content $at495src)
function Print-Fn {
  param($at495ls, $at495sig, $at495tag)
  $at495start = -1
  for ($at495i = 0; $at495i -lt $at495ls.Count; $at495i++) { if ($at495ls[$at495i].Contains($at495sig)) { $at495start = $at495i; break } }
  if ($at495start -lt 0) { Write-Output ($at495tag + ' NOT FOUND'); return }
  $at495depth = 0; $at495begun = $false
  for ($at495j = $at495start; $at495j -lt $at495ls.Count; $at495j++) {
    Write-Output ($at495tag + ' ' + ($at495j + 1) + ' ' + $at495ls[$at495j])
    $at495depth += ([regex]::Matches($at495ls[$at495j], '\{')).Count - ([regex]::Matches($at495ls[$at495j], '\}')).Count
    if ($at495ls[$at495j].Contains('{')) { $at495begun = $true }
    if ($at495begun -and $at495depth -eq 0) { break }
  }
}
Print-Fn $at495lines 'void AttachSelected()' 'SEL'
Print-Fn $at495lines 'void AttachForeground()' 'FGD'
Copy-Item $at495src ($at495src + '.phi-backup-495') -Force
$at495b64 = @'
aW1wb3J0IHN5cwoKcGF0aCA9IHN5cy5hcmd2WzFdCnNyYyA9IG9wZW4ocGF0aCwgInIiLCBlbmNvZGluZz0idXRmLTgtc2lnIiku
cmVhZCgpCmxpbmVzID0gc3JjLnNwbGl0KCJcbiIpCgpkZWYgZmluZF9mdW5jKGxpbmVzLCBzaWcpOgogICAgZm9yIGksIGxuIGlu
IGVudW1lcmF0ZShsaW5lcyk6CiAgICAgICAgaWYgc2lnIGluIGxuOgogICAgICAgICAgICBkZXB0aCA9IDAKICAgICAgICAgICAg
c3RhcnRlZCA9IEZhbHNlCiAgICAgICAgICAgIGZvciBqIGluIHJhbmdlKGksIGxlbihsaW5lcykpOgogICAgICAgICAgICAgICAg
ZGVwdGggKz0gbGluZXNbal0uY291bnQoInsiKSAtIGxpbmVzW2pdLmNvdW50KCJ9IikKICAgICAgICAgICAgICAgIGlmICJ7IiBp
biBsaW5lc1tqXToKICAgICAgICAgICAgICAgICAgICBzdGFydGVkID0gVHJ1ZQogICAgICAgICAgICAgICAgaWYgc3RhcnRlZCBh
bmQgZGVwdGggPT0gMDoKICAgICAgICAgICAgICAgICAgICByZXR1cm4gaSwgagogICAgICAgICAgICByZXR1cm4gaSwgLTEKICAg
IHJldHVybiAtMSwgLTEKCmcgPSBbXQpnLmFwcGVuZCgoImF0dGFjaEZvcmVncm91bmREZWYiLCBzcmMuY291bnQoInZvaWQgQXR0
YWNoRm9yZWdyb3VuZCgpIikgPT0gMSkpCmcuYXBwZW5kKCgiYXR0YWNoU2VsZWN0ZWQiLCBzcmMuY291bnQoInZvaWQgQXR0YWNo
U2VsZWN0ZWQoKSIpID09IDEpKQpnLmFwcGVuZCgoImZnV2luZG93RGVjbCIsIHNyYy5jb3VudCgiR2V0Rm9yZWdyb3VuZFdpbmRv
dyIpID49IDEpKQpnLmFwcGVuZCgoInNldEF0dGFjaGVkIiwgc3JjLmNvdW50KCJ2b2lkIFNldEF0dGFjaGVkKCkiKSA9PSAxKSkK
Zm9yIG5hbWUsIG9rIGluIGc6CiAgICBwcmludCgiR0FURSAiICsgbmFtZSArICI9IiArICgiMSIgaWYgb2sgZWxzZSAiMCIpKQpp
ZiBub3QgYWxsKG9rIGZvciBfLCBvayBpbiBnKToKICAgIHByaW50KCJQQVRDSCBHQVRFIEZBSUwgLSBub3RoaW5nIHdyaXR0ZW4i
KQogICAgc3lzLmV4aXQoMikKCmZnX3MsIGZnX2UgPSBmaW5kX2Z1bmMobGluZXMsICJ2b2lkIEF0dGFjaEZvcmVncm91bmQoKSIp
CnNlbF9zLCBzZWxfZSA9IGZpbmRfZnVuYyhsaW5lcywgInZvaWQgQXR0YWNoU2VsZWN0ZWQoKSIpCnByaW50KCJTUEFOIGZnPSIg
KyBzdHIoZmdfcykgKyAiLi4iICsgc3RyKGZnX2UpICsgIiBzZWw9IiArIHN0cihzZWxfcykgKyAiLi4iICsgc3RyKHNlbF9lKSkK
aWYgbWluKGZnX3MsIHNlbF9zKSA8IDAgb3IgZmdfZSA8IDAgb3Igc2VsX2UgPCAwOgogICAgcHJpbnQoIlBBVENIIEdBVEUgRkFJ
TCAtIHNwYW4gbm90IGZvdW5kIikKICAgIHN5cy5leGl0KDIpCgpwcmludCgiQ1VSUkVOVCBBdHRhY2hGb3JlZ3JvdW5kIGJvZHk6
IikKZm9yIGxuIGluIGxpbmVzW2ZnX3M6ZmdfZSArIDFdOgogICAgcHJpbnQoIkNVUkZHICIgKyBsbikKcHJpbnQoIkNVUlJFTlQg
QXR0YWNoU2VsZWN0ZWQgYm9keToiKQpmb3IgbG4gaW4gbGluZXNbc2VsX3M6c2VsX2UgKyAxXToKICAgIHByaW50KCJDVVJTRUwg
IiArIGxuKQoKaWYgc3JjLmNvdW50KCJhdHRhY2ggcmVhZCBhbiBleGNlcHRpb24iKSA+PSAxOgogICAgcHJpbnQoIlBBVENIIE5P
T1AgYWxyZWFkeU9yaWdpbmFsPTEiKQogICAgc3lzLmV4aXQoMCkKCmluZCA9ICIgICAgICAgICIKb3JpZ2luYWwgPSBbCiAgICBp
bmQgKyAicHJpdmF0ZSB2b2lkIEF0dGFjaEZvcmVncm91bmQoKSIsCiAgICBpbmQgKyAieyIsCiAgICBpbmQgKyAiICAgIEludFB0
ciBoID0gR2V0Rm9yZWdyb3VuZFdpbmRvdygpOyIsCiAgICBpbmQgKyAiICAgIHVpbnQgcGlkOyIsCiAgICBpbmQgKyAiICAgIEdl
dFdpbmRvd1RocmVhZFByb2Nlc3NJZChoLCBvdXQgcGlkKTsiLAogICAgaW5kICsgIiAgICB0cnkgeyBhdHRhY2hlZCA9IFByb2Nl
c3MuR2V0UHJvY2Vzc0J5SWQoKGludClwaWQpOyBTZXRBdHRhY2hlZCgpOyB9IiwKICAgIGluZCArICIgICAgY2F0Y2ggKEV4Y2Vw
dGlvbiBleCkgeyBTYXkoXCJhdHRhY2ggcmVhZCBhbiBleGNlcHRpb246IFwiICsgZXguTWVzc2FnZSk7IH0iLAogICAgaW5kICsg
In0iLApdCm9sZF9vcGVuID0gc3JjLmNvdW50KCJ7IikKb2xkX2Nsb3NlID0gc3JjLmNvdW50KCJ9IikKbGluZXNbZmdfczpmZ19l
ICsgMV0gPSBvcmlnaW5hbApvdXQgPSAiXG4iLmpvaW4obGluZXMpCm5ld19vcGVuID0gb3V0LmNvdW50KCJ7IikKbmV3X2Nsb3Nl
ID0gb3V0LmNvdW50KCJ9IikKcHJpbnQoIkJSQUNFIERFTFRBIG9wZW49IiArIHN0cihuZXdfb3BlbiAtIG9sZF9vcGVuKSArICIg
Y2xvc2U9IiArIHN0cihuZXdfY2xvc2UgLSBvbGRfY2xvc2UpKQppZiAobmV3X29wZW4gLSBuZXdfY2xvc2UpICE9IChvbGRfb3Bl
biAtIG9sZF9jbG9zZSk6CiAgICBwcmludCgiUEFUQ0ggR0FURSBGQUlMIC0gYnJhY2UgYmFsYW5jZSBjaGFuZ2VkIikKICAgIHN5
cy5leGl0KDIpCm9wZW4ocGF0aCwgInciLCBlbmNvZGluZz0idXRmLTgiKS53cml0ZShvdXQpCnByaW50KCJQQVRDSCBPSyBmZ1Jl
c3RvcmVkPTEiKQo=
'@
$at495pypath = Join-Path $at495dir 'patch495.py'
[IO.File]::WriteAllBytes($at495pypath, [Convert]::FromBase64String($at495b64))
$at495pyExe = $null
foreach ($at495cand in @('python', 'python3', 'py')) { $at495gc = Get-Command $at495cand -ErrorAction SilentlyContinue; if ($at495gc) { $at495pyExe = $at495gc.Source; break } }
Write-Output ('PYTHON=' + $at495pyExe)
if (-not $at495pyExe) { Write-Output 'PHI AT495 VERDICT: TERMINAL V58 SKIP no python'; Write-Output 'JOB 495 DONE'; return }
$at495out = @(& $at495pyExe $at495pypath $at495src 2>&1 | ForEach-Object { $_.ToString() })
foreach ($at495line in $at495out) { Write-Output ('PATCHER ' + $at495line) }
if (-not ((($at495out -join ' ') -match 'PATCH OK') -or (($at495out -join ' ') -match 'alreadyOriginal'))) { Write-Output 'PHI AT495 VERDICT: TERMINAL V58 patch=FAIL panel untouched'; Write-Output 'JOB 495 DONE'; return }
$at495old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
foreach ($at495o in $at495old) { Stop-Process -Id $at495o.Id -Force -ErrorAction SilentlyContinue; Write-Output ('PANEL CLOSED pid=' + $at495o.Id) }
Start-Sleep -Seconds 1
$at495csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$at495exe = Join-Path $at495dir 'PhiTerminal.exe'
& $at495csc /nologo /target:winexe /out:$at495exe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $at495src | ForEach-Object { Write-Output ('CSC ' + $_) }
$at495bytes = 0; if (Test-Path $at495exe) { $at495bytes = (Get-Item $at495exe).Length }
Write-Output ('EXE BYTES=' + $at495bytes)
$at495pid = 0; $at495state = 'NOT-LAUNCHED'
if ($at495bytes -gt 0) {
  $at495proc = Start-Process -FilePath $at495exe -WorkingDirectory $at495dir -PassThru
  Start-Sleep -Seconds 4
  $at495chk = Get-Process -Id $at495proc.Id -ErrorAction SilentlyContinue
  if ($at495chk) { $at495state = 'STANDS'; $at495pid = $at495proc.Id } else { $at495state = 'EXITED' }
}
Write-Output ('PHI AT495 VERDICT: TERMINAL V58 state=' + $at495state + ' pid=' + $at495pid + ' fgRestored=1')
Write-Output 'JOB 495 DONE'
```
