<!-- PHI-DIRECT -->
```powershell
Write-Output '=== TERMINAL V5.4 485 - ONE ATTACH DOOR, MERGED WHOLE (Ground from Tyree at the panel, 2026-10-28, assembled whole: attach foreground needs to be merged in attach selected, and attach selected does not work. Read at the source, the old button only ever tried the one picked row and stopped: no pick, or the picked game not running under its shelf name, and the click died quiet. This job prints the two attach functions whole first, then a gated patcher replaces the selected function with the merged door: the picked game first, then every game in the library in shelf order until one answers as running, then the foreground road merged in as the last road with every guard it already carries, and every road speaks in plain words so the button never sits silent again. The foreground function itself is not touched. Source backs up, panel closes, exe recompiles, window relaunches, verdict prints TERMINAL V54 with the merged count. Every variable carries the ma485 prefix.) ==='
$ma485dir = 'C:\Users\Admin\PhiTerminal'
$ma485src = Join-Path $ma485dir 'PhiTerminal3.cs'
$ma485lines = @(Get-Content $ma485src)
function Print-Fn {
  param($ma485ls, $ma485sig, $ma485tag)
  $ma485start = -1
  for ($ma485i = 0; $ma485i -lt $ma485ls.Count; $ma485i++) { if ($ma485ls[$ma485i].Contains($ma485sig)) { $ma485start = $ma485i; break } }
  if ($ma485start -lt 0) { Write-Output ($ma485tag + ' NOT FOUND'); return }
  $ma485depth = 0; $ma485begun = $false
  for ($ma485j = $ma485start; $ma485j -lt $ma485ls.Count; $ma485j++) {
    Write-Output ($ma485tag + ' ' + ($ma485j + 1) + ' ' + $ma485ls[$ma485j])
    $ma485depth += ([regex]::Matches($ma485ls[$ma485j], '\{')).Count - ([regex]::Matches($ma485ls[$ma485j], '\}')).Count
    if ($ma485ls[$ma485j].Contains('{')) { $ma485begun = $true }
    if ($ma485begun -and $ma485depth -eq 0) { break }
  }
}
Print-Fn $ma485lines 'void AttachSelected()' 'SEL'
Print-Fn $ma485lines 'void AttachForeground()' 'FG'
Copy-Item $ma485src ($ma485src + '.phi-backup-485') -Force
$ma485b64 = @'
aW1wb3J0IHN5cwoKcGF0aCA9IHN5cy5hcmd2WzFdCnNyYyA9IG9wZW4ocGF0aCwgInIiLCBlbmNvZGluZz0idXRmLTgtc2lnIiku
cmVhZCgpCgpmZ19kZWYgPSBzcmMuY291bnQoInZvaWQgQXR0YWNoRm9yZWdyb3VuZCgpIikKc2VsX2NvdW50ID0gc3JjLmNvdW50
KCJ2b2lkIEF0dGFjaFNlbGVjdGVkKCkiKQpwcmludCgiR0FURVMgYXR0YWNoU2VsZWN0ZWQ9IiArIHN0cihzZWxfY291bnQpICsg
IiBhdHRhY2hGb3JlZ3JvdW5kRGVmPSIgKyBzdHIoZmdfZGVmKSkKaWYgc2VsX2NvdW50ICE9IDEgb3IgZmdfZGVmIDwgMToKICAg
IHByaW50KCJQQVRDSCBHQVRFIEZBSUwgYXR0YWNoIGZ1bmN0aW9ucyBub3QgYXMgZXhwZWN0ZWQiKQogICAgc3lzLmV4aXQoMikK
CmxpbmVzID0gc3JjLnNwbGl0KCJcbiIpCgpkZWYgZmluZF9mdW5jKGxpbmVzLCBzaWcpOgogICAgZm9yIGksIGxuIGluIGVudW1l
cmF0ZShsaW5lcyk6CiAgICAgICAgaWYgc2lnIGluIGxuOgogICAgICAgICAgICBkZXB0aCA9IDAKICAgICAgICAgICAgc3RhcnRl
ZCA9IEZhbHNlCiAgICAgICAgICAgIGZvciBqIGluIHJhbmdlKGksIGxlbihsaW5lcykpOgogICAgICAgICAgICAgICAgZGVwdGgg
Kz0gbGluZXNbal0uY291bnQoInsiKSAtIGxpbmVzW2pdLmNvdW50KCJ9IikKICAgICAgICAgICAgICAgIGlmICJ7IiBpbiBsaW5l
c1tqXToKICAgICAgICAgICAgICAgICAgICBzdGFydGVkID0gVHJ1ZQogICAgICAgICAgICAgICAgaWYgc3RhcnRlZCBhbmQgZGVw
dGggPT0gMDoKICAgICAgICAgICAgICAgICAgICByZXR1cm4gaSwgagogICAgICAgICAgICByZXR1cm4gaSwgLTEKICAgIHJldHVy
biAtMSwgLTEKCnMsIGUgPSBmaW5kX2Z1bmMobGluZXMsICJ2b2lkIEF0dGFjaFNlbGVjdGVkKCkiKQpwcmludCgiU1BBTiBhdHRh
Y2hTZWxlY3RlZD0iICsgc3RyKHMpICsgIi4uIiArIHN0cihlKSkKaWYgZSA8IDA6CiAgICBwcmludCgiUEFUQ0ggR0FURSBGQUlM
IHNwYW4gbm90IGZvdW5kIikKICAgIHN5cy5leGl0KDMpCgpuZXdfZm4gPSBbCiAgICAiICAgICAgICBwcml2YXRlIHZvaWQgQXR0
YWNoU2VsZWN0ZWQoKSIsCiAgICAiICAgICAgICB7IiwKICAgICIgICAgICAgICAgICAvLyBQSEkgdjUuNDogb25lIGF0dGFjaCBk
b29yIC0gdGhlIHBpY2tlZCBnYW1lIGZpcnN0LCB0aGVuIGFueSBydW5uaW5nIGdhbWUgaW4gdGhlIGxpYnJhcnksIiwKICAgICIg
ICAgICAgICAgICAvLyB0aGVuIHRoZSBmb3JlZ3JvdW5kIHJvYWQgbWVyZ2VkIGluIGFzIHRoZSBsYXN0IHJvYWQuIFRoZSBidXR0
b24gbmV2ZXIgc2l0cyBzaWxlbnQuIiwKICAgICIgICAgICAgICAgICBpZiAobGliLlNlbGVjdGVkSXRlbXMuQ291bnQgPiAwKSIs
CiAgICAiICAgICAgICAgICAgeyIsCiAgICAiICAgICAgICAgICAgICAgIEdhbWVSb3cgcGlja2VkID0gKEdhbWVSb3cpbGliLlNl
bGVjdGVkSXRlbXNbMF0uVGFnOyIsCiAgICAiICAgICAgICAgICAgICAgIGlmIChUcnlBdHRhY2hSb3cocGlja2VkKSkgeyByZXR1
cm47IH0iLAogICAgIiAgICAgICAgICAgICAgICBTYXkocGlja2VkLk5hbWUgKyBcIiBpcyBub3QgcnVubmluZyAtIGxvb2tpbmcg
Zm9yIHRoZSBnYW1lIHRoYXQgaXNcIik7IiwKICAgICIgICAgICAgICAgICB9IiwKICAgICIgICAgICAgICAgICBmb3JlYWNoIChH
YW1lUm93IHJvdyBpbiBjYXRhbG9nKSIsCiAgICAiICAgICAgICAgICAgeyIsCiAgICAiICAgICAgICAgICAgICAgIGlmIChUcnlB
dHRhY2hSb3cocm93KSkgeyByZXR1cm47IH0iLAogICAgIiAgICAgICAgICAgIH0iLAogICAgIiAgICAgICAgICAgIEF0dGFjaEZv
cmVncm91bmQoKTsiLAogICAgIiAgICAgICAgfSIsCiAgICAiICAgICAgICBwcml2YXRlIGJvb2wgVHJ5QXR0YWNoUm93KEdhbWVS
b3cgcikiLAogICAgIiAgICAgICAgeyIsCiAgICAiICAgICAgICAgICAgaWYgKHIuUnVubmluZ1BpZCA+IDApIiwKICAgICIgICAg
ICAgICAgICB7IiwKICAgICIgICAgICAgICAgICAgICAgdHJ5IHsgYXR0YWNoZWQgPSBQcm9jZXNzLkdldFByb2Nlc3NCeUlkKHIu
UnVubmluZ1BpZCk7IFNldEF0dGFjaGVkKCk7IHJldHVybiB0cnVlOyB9IiwKICAgICIgICAgICAgICAgICAgICAgY2F0Y2ggeyB9
IiwKICAgICIgICAgICAgICAgICB9IiwKICAgICIgICAgICAgICAgICBpZiAoci5Qcm9jTmFtZS5MZW5ndGggPiAwKSIsCiAgICAi
ICAgICAgICAgICAgeyIsCiAgICAiICAgICAgICAgICAgICAgIFByb2Nlc3NbXSBoaXRzID0gUHJvY2Vzcy5HZXRQcm9jZXNzZXNC
eU5hbWUoci5Qcm9jTmFtZSk7IiwKICAgICIgICAgICAgICAgICAgICAgaWYgKGhpdHMuTGVuZ3RoID4gMCkgeyBhdHRhY2hlZCA9
IGhpdHNbMF07IFNldEF0dGFjaGVkKCk7IHJldHVybiB0cnVlOyB9IiwKICAgICIgICAgICAgICAgICB9IiwKICAgICIgICAgICAg
ICAgICByZXR1cm4gZmFsc2U7IiwKICAgICIgICAgICAgIH0iLApdCgpsaW5lc1tzOmUgKyAxXSA9IG5ld19mbgpvdXQgPSAiXG4i
LmpvaW4obGluZXMpCm9wZW5zID0gb3V0LmNvdW50KCJ7IikgLSBzcmMuY291bnQoInsiKQpjbG9zZXMgPSBvdXQuY291bnQoIn0i
KSAtIHNyYy5jb3VudCgifSIpCnByaW50KCJCUkFDRSBERUxUQSBvcGVuPSIgKyBzdHIob3BlbnMpICsgIiBjbG9zZT0iICsgc3Ry
KGNsb3NlcykpCmlmIG9wZW5zICE9IGNsb3NlczoKICAgIHByaW50KCJQQVRDSCBHQVRFIEZBSUwgYnJhY2VzIikKICAgIHN5cy5l
eGl0KDQpCgp3aXRoIG9wZW4ocGF0aCwgInciLCBlbmNvZGluZz0idXRmLTgiKSBhcyBmOgogICAgZi53cml0ZShvdXQpCnByaW50
KCJQQVRDSCBPSyBtZXJnZWQ9MSIpCg==
'@
$ma485pypath = Join-Path $ma485dir 'patch485.py'
[IO.File]::WriteAllBytes($ma485pypath, [Convert]::FromBase64String($ma485b64))
$ma485pyExe = $null
foreach ($ma485cand in @('python', 'python3', 'py')) { $ma485gc = Get-Command $ma485cand -ErrorAction SilentlyContinue; if ($ma485gc) { $ma485pyExe = $ma485gc.Source; break } }
Write-Output ('PYTHON=' + $ma485pyExe)
if (-not $ma485pyExe) { Write-Output 'PHI MA485 VERDICT: TERMINAL V54 SKIP no python'; Write-Output 'JOB 485 DONE'; return }
$ma485out = @(& $ma485pyExe $ma485pypath $ma485src 2>&1 | ForEach-Object { $_.ToString() })
foreach ($ma485line in $ma485out) { Write-Output ('PATCHER ' + $ma485line) }
if (-not (($ma485out -join ' ') -match 'PATCH OK')) { Write-Output 'PHI MA485 VERDICT: TERMINAL V54 patch=FAIL panel untouched'; Write-Output 'JOB 485 DONE'; return }
$ma485old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
foreach ($ma485o in $ma485old) { Stop-Process -Id $ma485o.Id -Force -ErrorAction SilentlyContinue; Write-Output ('PANEL CLOSED pid=' + $ma485o.Id) }
Start-Sleep -Seconds 1
$ma485csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$ma485exe = Join-Path $ma485dir 'PhiTerminal.exe'
& $ma485csc /nologo /target:winexe /out:$ma485exe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $ma485src | ForEach-Object { Write-Output ('CSC ' + $_) }
$ma485bytes = 0; if (Test-Path $ma485exe) { $ma485bytes = (Get-Item $ma485exe).Length }
Write-Output ('EXE BYTES=' + $ma485bytes)
$ma485pid = 0; $ma485state = 'NOT-LAUNCHED'
if ($ma485bytes -gt 0) {
  $ma485proc = Start-Process -FilePath $ma485exe -WorkingDirectory $ma485dir -PassThru
  Start-Sleep -Seconds 4
  $ma485chk = Get-Process -Id $ma485proc.Id -ErrorAction SilentlyContinue
  if ($ma485chk) { $ma485state = 'STANDS'; $ma485pid = $ma485proc.Id } else { $ma485state = 'EXITED' }
}
Write-Output ('PHI MA485 VERDICT: TERMINAL V54 state=' + $ma485state + ' pid=' + $ma485pid + ' merged=1')
Write-Output 'JOB 485 DONE'
```
