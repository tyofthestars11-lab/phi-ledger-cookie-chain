<!-- PHI-DIRECT -->
```powershell
Write-Output '=== TERMINAL V5.7 490 - THE BUTTON IS ATTACH FOREGROUND, RENAMED AS HE NAMED IT (Ground: Tyree, 2026-10-28: you are not listening, the attach foreground button worked, replace attach selected with that and rename it attached foreground selected, what is so hard about that. His v5.6 photo reads the last fault plain: Cyberpunk stands open behind the panel, the watched window number belongs to a process already gone, and the button found no game. The roads built around the foreground code are the fault; the foreground code itself worked in his hands as its own button. This job removes every road: the button body becomes the foreground attach alone, the exact function that worked, and the button takes the name he gave it, ATTACHED FOREGROUND SELECTED. Nothing else in the panel is touched. Source backs up, panel closes, exe recompiles, window relaunches, verdict prints TERMINAL V57 with fgPure. Every variable carries the at490 prefix.) ==='
$at490dir = 'C:\Users\Admin\PhiTerminal'
$at490src = Join-Path $at490dir 'PhiTerminal3.cs'
$at490lines = @(Get-Content $at490src)
function Print-Fn {
  param($at490ls, $at490sig, $at490tag)
  $at490start = -1
  for ($at490i = 0; $at490i -lt $at490ls.Count; $at490i++) { if ($at490ls[$at490i].Contains($at490sig)) { $at490start = $at490i; break } }
  if ($at490start -lt 0) { Write-Output ($at490tag + ' NOT FOUND'); return }
  $at490depth = 0; $at490begun = $false
  for ($at490j = $at490start; $at490j -lt $at490ls.Count; $at490j++) {
    Write-Output ($at490tag + ' ' + ($at490j + 1) + ' ' + $at490ls[$at490j])
    $at490depth += ([regex]::Matches($at490ls[$at490j], '\{')).Count - ([regex]::Matches($at490ls[$at490j], '\}')).Count
    if ($at490ls[$at490j].Contains('{')) { $at490begun = $true }
    if ($at490begun -and $at490depth -eq 0) { break }
  }
}
Print-Fn $at490lines 'void AttachSelected()' 'SEL'
Select-String -Path $at490src -Pattern 'ATTACH SELECTED' | ForEach-Object { Write-Output ('TEXTLINE ' + $_.LineNumber + ' ' + $_.Line.Trim()) }
Copy-Item $at490src ($at490src + '.phi-backup-490') -Force
$at490b64 = @'
aW1wb3J0IHN5cwoKcGF0aCA9IHN5cy5hcmd2WzFdCnNyYyA9IG9wZW4ocGF0aCwgInIiLCBlbmNvZGluZz0idXRmLTgtc2lnIiku
cmVhZCgpCmxpbmVzID0gc3JjLnNwbGl0KCJcbiIpCgpnID0gW10KZy5hcHBlbmQoKCJhdHRhY2hTZWxlY3RlZCIsIHNyYy5jb3Vu
dCgidm9pZCBBdHRhY2hTZWxlY3RlZCgpIikgPT0gMSkpCmcuYXBwZW5kKCgiYXR0YWNoRm9yZWdyb3VuZERlZiIsIHNyYy5jb3Vu
dCgidm9pZCBBdHRhY2hGb3JlZ3JvdW5kKCkiKSA+PSAxKSkKZy5hcHBlbmQoKCJidXR0b25UZXh0Iiwgc3JjLmNvdW50KCciQVRU
QUNIIFNFTEVDVEVEIicpID09IDEpKQpnLmFwcGVuZCgoIm5vdFlldCIsIHNyYy5jb3VudCgnIkFUVEFDSEVEIEZPUkVHUk9VTkQg
U0VMRUNURUQiJykgPT0gMCkpCmZvciBuYW1lLCBvayBpbiBnOgogICAgcHJpbnQoIkdBVEUgIiArIG5hbWUgKyAiPSIgKyAoIjEi
IGlmIG9rIGVsc2UgIjAiKSkKaWYgbm90IGFsbChvayBmb3IgXywgb2sgaW4gZyk6CiAgICBwcmludCgiUEFUQ0ggR0FURSBGQUlM
IC0gbm90aGluZyB3cml0dGVuIikKICAgIHN5cy5leGl0KDIpCgpkZWYgZmluZF9mdW5jKGxpbmVzLCBzaWcpOgogICAgZm9yIGks
IGxuIGluIGVudW1lcmF0ZShsaW5lcyk6CiAgICAgICAgaWYgc2lnIGluIGxuOgogICAgICAgICAgICBkZXB0aCA9IDAKICAgICAg
ICAgICAgc3RhcnRlZCA9IEZhbHNlCiAgICAgICAgICAgIGZvciBqIGluIHJhbmdlKGksIGxlbihsaW5lcykpOgogICAgICAgICAg
ICAgICAgZGVwdGggKz0gbGluZXNbal0uY291bnQoInsiKSAtIGxpbmVzW2pdLmNvdW50KCJ9IikKICAgICAgICAgICAgICAgIGlm
ICJ7IiBpbiBsaW5lc1tqXToKICAgICAgICAgICAgICAgICAgICBzdGFydGVkID0gVHJ1ZQogICAgICAgICAgICAgICAgaWYgc3Rh
cnRlZCBhbmQgZGVwdGggPT0gMDoKICAgICAgICAgICAgICAgICAgICByZXR1cm4gaSwgagogICAgICAgICAgICByZXR1cm4gaSwg
LTEKICAgIHJldHVybiAtMSwgLTEKCm9sZF9vcGVuID0gc3JjLmNvdW50KCJ7IikKb2xkX2Nsb3NlID0gc3JjLmNvdW50KCJ9IikK
c2VsX3MsIHNlbF9lID0gZmluZF9mdW5jKGxpbmVzLCAidm9pZCBBdHRhY2hTZWxlY3RlZCgpIikKcHJpbnQoIlNQQU4gc2VsPSIg
KyBzdHIoc2VsX3MpICsgIi4uIiArIHN0cihzZWxfZSkpCmlmIHNlbF9zIDwgMCBvciBzZWxfZSA8IDA6CiAgICBwcmludCgiUEFU
Q0ggR0FURSBGQUlMIC0gc3BhbiBub3QgZm91bmQiKQogICAgc3lzLmV4aXQoMikKCmluZCA9ICIgICAgICAgICIKbmV3c2VsID0g
WwogICAgaW5kICsgInByaXZhdGUgdm9pZCBBdHRhY2hTZWxlY3RlZCgpIiwKICAgIGluZCArICJ7IiwKICAgIGluZCArICIgICAg
QXR0YWNoRm9yZWdyb3VuZCgpOyIsCiAgICBpbmQgKyAifSIsCl0KbGluZXNbc2VsX3M6c2VsX2UgKyAxXSA9IG5ld3NlbApvdXQg
PSAiXG4iLmpvaW4obGluZXMpCm91dCA9IG91dC5yZXBsYWNlKCciQVRUQUNIIFNFTEVDVEVEIicsICciQVRUQUNIRUQgRk9SRUdS
T1VORCBTRUxFQ1RFRCInKQpuZXdfb3BlbiA9IG91dC5jb3VudCgieyIpCm5ld19jbG9zZSA9IG91dC5jb3VudCgifSIpCnByaW50
KCJCUkFDRSBERUxUQSBvcGVuPSIgKyBzdHIobmV3X29wZW4gLSBvbGRfb3BlbikgKyAiIGNsb3NlPSIgKyBzdHIobmV3X2Nsb3Nl
IC0gb2xkX2Nsb3NlKSkKaWYgKG5ld19vcGVuIC0gbmV3X2Nsb3NlKSAhPSAob2xkX29wZW4gLSBvbGRfY2xvc2UpOgogICAgcHJp
bnQoIlBBVENIIEdBVEUgRkFJTCAtIGJyYWNlIGJhbGFuY2UgY2hhbmdlZCIpCiAgICBzeXMuZXhpdCgyKQpvcGVuKHBhdGgsICJ3
IiwgZW5jb2Rpbmc9InV0Zi04Iikud3JpdGUob3V0KQpwcmludCgiUEFUQ0ggT0sgZmdQdXJlPTEiKQo=
'@
$at490pypath = Join-Path $at490dir 'patch490.py'
[IO.File]::WriteAllBytes($at490pypath, [Convert]::FromBase64String($at490b64))
$at490pyExe = $null
foreach ($at490cand in @('python', 'python3', 'py')) { $at490gc = Get-Command $at490cand -ErrorAction SilentlyContinue; if ($at490gc) { $at490pyExe = $at490gc.Source; break } }
Write-Output ('PYTHON=' + $at490pyExe)
if (-not $at490pyExe) { Write-Output 'PHI AT490 VERDICT: TERMINAL V57 SKIP no python'; Write-Output 'JOB 490 DONE'; return }
$at490out = @(& $at490pyExe $at490pypath $at490src 2>&1 | ForEach-Object { $_.ToString() })
foreach ($at490line in $at490out) { Write-Output ('PATCHER ' + $at490line) }
if (-not (($at490out -join ' ') -match 'PATCH OK')) { Write-Output 'PHI AT490 VERDICT: TERMINAL V57 patch=FAIL panel untouched'; Write-Output 'JOB 490 DONE'; return }
$at490old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
foreach ($at490o in $at490old) { Stop-Process -Id $at490o.Id -Force -ErrorAction SilentlyContinue; Write-Output ('PANEL CLOSED pid=' + $at490o.Id) }
Start-Sleep -Seconds 1
$at490csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$at490exe = Join-Path $at490dir 'PhiTerminal.exe'
& $at490csc /nologo /target:winexe /out:$at490exe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $at490src | ForEach-Object { Write-Output ('CSC ' + $_) }
$at490bytes = 0; if (Test-Path $at490exe) { $at490bytes = (Get-Item $at490exe).Length }
Write-Output ('EXE BYTES=' + $at490bytes)
$at490pid = 0; $at490state = 'NOT-LAUNCHED'
if ($at490bytes -gt 0) {
  $at490proc = Start-Process -FilePath $at490exe -WorkingDirectory $at490dir -PassThru
  Start-Sleep -Seconds 4
  $at490chk = Get-Process -Id $at490proc.Id -ErrorAction SilentlyContinue
  if ($at490chk) { $at490state = 'STANDS'; $at490pid = $at490proc.Id } else { $at490state = 'EXITED' }
}
Write-Output ('PHI AT490 VERDICT: TERMINAL V57 state=' + $at490state + ' pid=' + $at490pid + ' fgPure=1')
Write-Output 'JOB 490 DONE'
```
