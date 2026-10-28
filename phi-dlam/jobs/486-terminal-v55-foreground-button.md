<!-- PHI-DIRECT -->
```powershell
Write-Output '=== TERMINAL V5.5 486 - THE ATTACH BUTTON RUNS THE FOREGROUND CODE (Ground from Tyree at the panel, 2026-10-28, assembled whole: attach foreground worked and loaded the game, attach selected does not work, use that code for attached, the button is attach foreground slash selected with foreground code, and it does not hold the attached when clicked, just hovers blue over the game words. His photo of the merged button clicks reads the fault plain: the picked game was not running, the library scan found nothing running, and the foreground road seated last only ever saw the terminal itself, because a button click makes the terminal the front window. This job seats the foreground code as the button engine itself. The panel now watches the front window four times a second with the foreground code own eyes and remembers the last real game window standing in front, skipping system seats and the terminal itself. The ATTACH button runs that remembered foreground seat FIRST, then the picked game, then the library scan. The game pick now holds its blue when clicked, and the attached game is held in the panel title where it cannot be missed. The foreground function itself is not touched. Source backs up, panel closes, exe recompiles, window relaunches, verdict prints TERMINAL V55 with fgFirst. Every variable carries the fg486 prefix.) ==='
$fg486dir = 'C:\Users\Admin\PhiTerminal'
$fg486src = Join-Path $fg486dir 'PhiTerminal3.cs'
$fg486lines = @(Get-Content $fg486src)
function Print-Fn {
  param($fg486ls, $fg486sig, $fg486tag)
  $fg486start = -1
  for ($fg486i = 0; $fg486i -lt $fg486ls.Count; $fg486i++) { if ($fg486ls[$fg486i].Contains($fg486sig)) { $fg486start = $fg486i; break } }
  if ($fg486start -lt 0) { Write-Output ($fg486tag + ' NOT FOUND'); return }
  $fg486depth = 0; $fg486begun = $false
  for ($fg486j = $fg486start; $fg486j -lt $fg486ls.Count; $fg486j++) {
    Write-Output ($fg486tag + ' ' + ($fg486j + 1) + ' ' + $fg486ls[$fg486j])
    $fg486depth += ([regex]::Matches($fg486ls[$fg486j], '\{')).Count - ([regex]::Matches($fg486ls[$fg486j], '\}')).Count
    if ($fg486ls[$fg486j].Contains('{')) { $fg486begun = $true }
    if ($fg486begun -and $fg486depth -eq 0) { break }
  }
}
Print-Fn $fg486lines 'void AttachSelected()' 'SEL'
Print-Fn $fg486lines 'void SetAttached()' 'SA'
Copy-Item $fg486src ($fg486src + '.phi-backup-486') -Force
$fg486b64 = @'
aW1wb3J0IHN5cwoKcGF0aCA9IHN5cy5hcmd2WzFdCnNyYyA9IG9wZW4ocGF0aCwgInIiLCBlbmNvZGluZz0idXRmLTgtc2lnIiku
cmVhZCgpCmxpbmVzID0gc3JjLnNwbGl0KCJcbiIpCgpkZWYgY291bnQoc3ViKToKICAgIHJldHVybiBzcmMuY291bnQoc3ViKQoK
ZyA9IFtdCmcuYXBwZW5kKCgiYXR0YWNoU2VsZWN0ZWQiLCBjb3VudCgidm9pZCBBdHRhY2hTZWxlY3RlZCgpIikgPT0gMSkpCmcu
YXBwZW5kKCgidHJ5QXR0YWNoUm93IiwgY291bnQoIlRyeUF0dGFjaFJvdyIpID49IDEpKQpnLmFwcGVuZCgoInNjYW5TYXkiLCBj
b3VudCgibG9va2luZyBmb3IgdGhlIGdhbWUgdGhhdCBpcyIpID49IDEpKQpnLmFwcGVuZCgoImF0dGFjaGVkRmllbGQiLCBjb3Vu
dCgicHJpdmF0ZSBQcm9jZXNzIGF0dGFjaGVkOyIpID09IDEpKQpnLmFwcGVuZCgoImN0b3IiLCBjb3VudCgicHVibGljIFRlcm1G
b3JtKCkiKSA9PSAxKSkKZy5hcHBlbmQoKCJzZXRBdHRhY2hlZCIsIGNvdW50KCJ2b2lkIFNldEF0dGFjaGVkKCkiKSA9PSAxKSkK
Zy5hcHBlbmQoKCJsaXN0VmlldyIsIGNvdW50KCJuZXcgTGlzdFZpZXcoKSIpID09IDEpKQpnLmFwcGVuZCgoImZnRGVjbCIsIGNv
dW50KCJHZXRGb3JlZ3JvdW5kV2luZG93IikgPj0gMSkpCmcuYXBwZW5kKCgic3lzdGVtU2VhdCIsIGNvdW50KCJib29sIElzU3lz
dGVtU2VhdCgiKSA9PSAxKSkKZy5hcHBlbmQoKCJub3RZZXQiLCBjb3VudCgibGFzdEZnUGlkIikgPT0gMCkpCmZvciBuYW1lLCBv
ayBpbiBnOgogICAgcHJpbnQoIkdBVEUgIiArIG5hbWUgKyAiPSIgKyAoIjEiIGlmIG9rIGVsc2UgIjAiKSkKaWYgbm90IGFsbChv
ayBmb3IgXywgb2sgaW4gZyk6CiAgICBwcmludCgiUEFUQ0ggR0FURSBGQUlMIC0gbm90aGluZyB3cml0dGVuIikKICAgIHN5cy5l
eGl0KDIpCgpkZWYgZmluZF9mdW5jKGxpbmVzLCBzaWcpOgogICAgZm9yIGksIGxuIGluIGVudW1lcmF0ZShsaW5lcyk6CiAgICAg
ICAgaWYgc2lnIGluIGxuOgogICAgICAgICAgICBkZXB0aCA9IDAKICAgICAgICAgICAgc3RhcnRlZCA9IEZhbHNlCiAgICAgICAg
ICAgIGZvciBqIGluIHJhbmdlKGksIGxlbihsaW5lcykpOgogICAgICAgICAgICAgICAgZGVwdGggKz0gbGluZXNbal0uY291bnQo
InsiKSAtIGxpbmVzW2pdLmNvdW50KCJ9IikKICAgICAgICAgICAgICAgIGlmICJ7IiBpbiBsaW5lc1tqXToKICAgICAgICAgICAg
ICAgICAgICBzdGFydGVkID0gVHJ1ZQogICAgICAgICAgICAgICAgaWYgc3RhcnRlZCBhbmQgZGVwdGggPT0gMDoKICAgICAgICAg
ICAgICAgICAgICByZXR1cm4gaSwgagogICAgICAgICAgICByZXR1cm4gaSwgLTEKICAgIHJldHVybiAtMSwgLTEKCmRlZiBmaW5k
X2xpbmUobGluZXMsIHN1Yik6CiAgICBmb3IgaSwgbG4gaW4gZW51bWVyYXRlKGxpbmVzKToKICAgICAgICBpZiBzdWIgaW4gbG46
CiAgICAgICAgICAgIHJldHVybiBpCiAgICByZXR1cm4gLTEKCm9sZF9vcGVuID0gc3JjLmNvdW50KCJ7IikKb2xkX2Nsb3NlID0g
c3JjLmNvdW50KCJ9IikKCiMgLS0tIHNwYW5zIG9uIG9yaWdpbmFsIGxpbmVzIC0tLQpzZWxfcywgc2VsX2UgPSBmaW5kX2Z1bmMo
bGluZXMsICJ2b2lkIEF0dGFjaFNlbGVjdGVkKCkiKQpzYV9zLCBzYV9lID0gZmluZF9mdW5jKGxpbmVzLCAidm9pZCBTZXRBdHRh
Y2hlZCgpIikKY3RfcywgY3RfZSA9IGZpbmRfZnVuYyhsaW5lcywgInB1YmxpYyBUZXJtRm9ybSgpIikKZmxkX2kgPSBmaW5kX2xp
bmUobGluZXMsICJwcml2YXRlIFByb2Nlc3MgYXR0YWNoZWQ7IikKbGliX2kgPSBmaW5kX2xpbmUobGluZXMsICJuZXcgTGlzdFZp
ZXcoKSIpCnByaW50KCJTUEFOIHNlbD0iICsgc3RyKHNlbF9zKSArICIuLiIgKyBzdHIoc2VsX2UpICsgIiBzZXRBdHRhY2hlZD0i
ICsgc3RyKHNhX3MpICsgIi4uIiArIHN0cihzYV9lKSArICIgY3Rvcj0iICsgc3RyKGN0X3MpICsgIi4uIiArIHN0cihjdF9lKSAr
ICIgZmllbGQ9IiArIHN0cihmbGRfaSkgKyAiIGxpYj0iICsgc3RyKGxpYl9pKSkKaWYgbWluKHNlbF9zLCBzYV9zLCBjdF9zLCBm
bGRfaSwgbGliX2kpIDwgMCBvciBzZWxfZSA8IDAgb3Igc2FfZSA8IDAgb3IgY3RfZSA8IDA6CiAgICBwcmludCgiUEFUQ0ggR0FU
RSBGQUlMIC0gc3BhbiBub3QgZm91bmQiKQogICAgc3lzLmV4aXQoMikKCmluZGVudCA9ICIgICAgICAgICIKCnRpY2sgPSBbCiAg
ICBpbmRlbnQgKyAicHJpdmF0ZSB2b2lkIFRyYWNrRm9yZWdyb3VuZFRpY2sob2JqZWN0IHNlbmRlciwgRXZlbnRBcmdzIGUpIiwK
ICAgIGluZGVudCArICJ7IiwKICAgIGluZGVudCArICIgICAgdHJ5IiwKICAgIGluZGVudCArICIgICAgeyIsCiAgICBpbmRlbnQg
KyAiICAgICAgICBJbnRQdHIgaCA9IEdldEZvcmVncm91bmRXaW5kb3coKTsiLAogICAgaW5kZW50ICsgIiAgICAgICAgaWYgKGgg
PT0gSW50UHRyLlplcm8pIHJldHVybjsiLAogICAgaW5kZW50ICsgIiAgICAgICAgdWludCBwaWQ7IiwKICAgIGluZGVudCArICIg
ICAgICAgIEdldFdpbmRvd1RocmVhZFByb2Nlc3NJZChoLCBvdXQgcGlkKTsiLAogICAgaW5kZW50ICsgIiAgICAgICAgaWYgKChp
bnQpcGlkID09IFN5c3RlbS5EaWFnbm9zdGljcy5Qcm9jZXNzLkdldEN1cnJlbnRQcm9jZXNzKCkuSWQpIHJldHVybjsiLAogICAg
aW5kZW50ICsgIiAgICAgICAgaWYgKChpbnQpcGlkID09IGxhc3RGZ1BpZCkgcmV0dXJuOyIsCiAgICBpbmRlbnQgKyAiICAgICAg
ICBQcm9jZXNzIHAgPSBQcm9jZXNzLkdldFByb2Nlc3NCeUlkKChpbnQpcGlkKTsiLAogICAgaW5kZW50ICsgIiAgICAgICAgaWYg
KElzU3lzdGVtU2VhdChwLlByb2Nlc3NOYW1lKSkgcmV0dXJuOyIsCiAgICBpbmRlbnQgKyAiICAgICAgICBsYXN0RmdQaWQgPSAo
aW50KXBpZDsiLAogICAgaW5kZW50ICsgIiAgICAgICAgbGFzdEZnTmFtZSA9IHAuUHJvY2Vzc05hbWU7IiwKICAgIGluZGVudCAr
ICIgICAgfSIsCiAgICBpbmRlbnQgKyAiICAgIGNhdGNoIHsgfSIsCiAgICBpbmRlbnQgKyAifSIsCl0KCm5ld3NlbCA9IFsKICAg
IGluZGVudCArICJwcml2YXRlIHZvaWQgQXR0YWNoU2VsZWN0ZWQoKSIsCiAgICBpbmRlbnQgKyAieyIsCiAgICBpbmRlbnQgKyAi
ICAgIGlmIChsYXN0RmdQaWQgPiAwKSIsCiAgICBpbmRlbnQgKyAiICAgIHsiLAogICAgaW5kZW50ICsgIiAgICAgICAgdHJ5IiwK
ICAgIGluZGVudCArICIgICAgICAgIHsiLAogICAgaW5kZW50ICsgIiAgICAgICAgICAgIFByb2Nlc3MgZnAgPSBQcm9jZXNzLkdl
dFByb2Nlc3NCeUlkKGxhc3RGZ1BpZCk7IiwKICAgIGluZGVudCArICIgICAgICAgICAgICBpZiAoIUlzU3lzdGVtU2VhdChmcC5Q
cm9jZXNzTmFtZSkpIiwKICAgIGluZGVudCArICIgICAgICAgICAgICB7IiwKICAgIGluZGVudCArICIgICAgICAgICAgICAgICAg
U2F5KFwiQXR0YWNoaW5nIHRvIHRoZSBnYW1lIGluIGZyb250OiBcIiArIGZwLlByb2Nlc3NOYW1lKTsiLAogICAgaW5kZW50ICsg
IiAgICAgICAgICAgICAgICBhdHRhY2hlZCA9IGZwOyBTZXRBdHRhY2hlZCgpOyByZXR1cm47IiwKICAgIGluZGVudCArICIgICAg
ICAgICAgICB9IiwKICAgIGluZGVudCArICIgICAgICAgIH0iLAogICAgaW5kZW50ICsgIiAgICAgICAgY2F0Y2ggeyB9IiwKICAg
IGluZGVudCArICIgICAgfSIsCiAgICBpbmRlbnQgKyAiICAgIEdhbWVSb3cgcGlja2VkID0gbnVsbDsiLAogICAgaW5kZW50ICsg
IiAgICBpZiAobGliLlNlbGVjdGVkSXRlbXMuQ291bnQgPiAwKSBwaWNrZWQgPSAoR2FtZVJvdylsaWIuU2VsZWN0ZWRJdGVtc1sw
XS5UYWc7IiwKICAgIGluZGVudCArICIgICAgaWYgKHBpY2tlZCAhPSBudWxsICYmIFRyeUF0dGFjaFJvdyhwaWNrZWQpKSByZXR1
cm47IiwKICAgIGluZGVudCArICIgICAgaWYgKHBpY2tlZCAhPSBudWxsKSBTYXkocGlja2VkLk5hbWUgKyBcIiBpcyBub3QgcnVu
bmluZyAtIGxvb2tpbmcgZm9yIHRoZSBnYW1lIHRoYXQgaXNcIik7IiwKICAgIGluZGVudCArICIgICAgZm9yZWFjaCAoR2FtZVJv
dyByb3cgaW4gY2F0YWxvZykiLAogICAgaW5kZW50ICsgIiAgICB7IiwKICAgIGluZGVudCArICIgICAgICAgIGlmIChwaWNrZWQg
IT0gbnVsbCAmJiByb3cgPT0gcGlja2VkKSBjb250aW51ZTsiLAogICAgaW5kZW50ICsgIiAgICAgICAgaWYgKFRyeUF0dGFjaFJv
dyhyb3cpKSByZXR1cm47IiwKICAgIGluZGVudCArICIgICAgfSIsCiAgICBpbmRlbnQgKyAiICAgIFNheShcIk5vIGdhbWUgaXMg
b3BlbiB5ZXQgLSBvcGVuIHlvdXIgZ2FtZSwgY2xpY2sgaW50byBpdCBvbmNlLCB0aGVuIHByZXNzIH4gYW5kIEFUVEFDSC5cIik7
IiwKICAgIGluZGVudCArICJ9IiwKXQoKZmllbGRzID0gWwogICAgaW5kZW50ICsgInByaXZhdGUgaW50IGxhc3RGZ1BpZCA9IDA7
IiwKICAgIGluZGVudCArICJwcml2YXRlIHN0cmluZyBsYXN0RmdOYW1lID0gXCJcIjsiLAogICAgaW5kZW50ICsgInByaXZhdGUg
U3lzdGVtLldpbmRvd3MuRm9ybXMuVGltZXIgZmdUaW1lcjsiLApdCgpjdG9yc2VhdCA9IFsKICAgIGluZGVudCArICIgICAgZmdU
aW1lciA9IG5ldyBTeXN0ZW0uV2luZG93cy5Gb3Jtcy5UaW1lcigpOyIsCiAgICBpbmRlbnQgKyAiICAgIGZnVGltZXIuSW50ZXJ2
YWwgPSAyNTA7IiwKICAgIGluZGVudCArICIgICAgZmdUaW1lci5UaWNrICs9IFRyYWNrRm9yZWdyb3VuZFRpY2s7IiwKICAgIGlu
ZGVudCArICIgICAgZmdUaW1lci5TdGFydCgpOyIsCl0KCmhvbGRsaW5lID0gWwogICAgaW5kZW50ICsgIiAgICBpZiAoYXR0YWNo
ZWQgIT0gbnVsbCkgeyB0cnkgeyB0aGlzLlRleHQgPSBcIlBISSBURVJNSU5BTCAtIEFUVEFDSEVEOiBcIiArIGF0dGFjaGVkLlBy
b2Nlc3NOYW1lOyB9IGNhdGNoIHsgfSB9IiwKXQoKIyBhcHBseSBkZXNjZW5kaW5nIGJ5IGFuY2hvciBsaW5lCiMgMSkgQXR0YWNo
U2VsZWN0ZWQgcmVwbGFjZSwgdGhlbiB0aWNrIGluc2VydCBiZWZvcmUgaXQKbGluZXNbc2VsX3M6c2VsX2UgKyAxXSA9IG5ld3Nl
bApsaW5lc1tzZWxfczpzZWxfc10gPSB0aWNrCiMgMikgU2V0QXR0YWNoZWQgaG9sZCBsaW5lIGJlZm9yZSBpdHMgY2xvc2luZyBi
cmFjZQpsaW5lc1tzYV9lOnNhX2VdID0gaG9sZGxpbmUKIyAzKSBjb25zdHJ1Y3RvciBzZWF0IGJlZm9yZSBpdHMgY2xvc2luZyBi
cmFjZQpsaW5lc1tjdF9lOmN0X2VdID0gY3RvcnNlYXQKIyA0KSBIaWRlU2VsZWN0aW9uIHJpZ2h0IGFmdGVyIHRoZSBMaXN0Vmll
dyBjcmVhdGlvbiBsaW5lCmxpbmVzW2xpYl9pICsgMTpsaWJfaSArIDFdID0gWyIgICAgICAgICAgICBsaWIuSGlkZVNlbGVjdGlv
biA9IGZhbHNlOyJdCiMgNSkgZmllbGRzIGFmdGVyIHRoZSBhdHRhY2hlZCBmaWVsZCBsaW5lCmxpbmVzW2ZsZF9pICsgMTpmbGRf
aSArIDFdID0gZmllbGRzCgpvdXQgPSAiXG4iLmpvaW4obGluZXMpCm5ld19vcGVuID0gb3V0LmNvdW50KCJ7IikKbmV3X2Nsb3Nl
ID0gb3V0LmNvdW50KCJ9IikKcHJpbnQoIkJSQUNFIERFTFRBIG9wZW49IiArIHN0cihuZXdfb3BlbiAtIG9sZF9vcGVuKSArICIg
Y2xvc2U9IiArIHN0cihuZXdfY2xvc2UgLSBvbGRfY2xvc2UpKQppZiAobmV3X29wZW4gLSBuZXdfY2xvc2UpICE9IChvbGRfb3Bl
biAtIG9sZF9jbG9zZSk6CiAgICBwcmludCgiUEFUQ0ggR0FURSBGQUlMIC0gYnJhY2UgYmFsYW5jZSBjaGFuZ2VkIikKICAgIHN5
cy5leGl0KDIpCm9wZW4ocGF0aCwgInciLCBlbmNvZGluZz0idXRmLTgiKS53cml0ZShvdXQpCnByaW50KCJQQVRDSCBPSyBmZ0Zp
cnN0PTEiKQo=
'@
$fg486pypath = Join-Path $fg486dir 'patch486.py'
[IO.File]::WriteAllBytes($fg486pypath, [Convert]::FromBase64String($fg486b64))
$fg486pyExe = $null
foreach ($fg486cand in @('python', 'python3', 'py')) { $fg486gc = Get-Command $fg486cand -ErrorAction SilentlyContinue; if ($fg486gc) { $fg486pyExe = $fg486gc.Source; break } }
Write-Output ('PYTHON=' + $fg486pyExe)
if (-not $fg486pyExe) { Write-Output 'PHI FG486 VERDICT: TERMINAL V55 SKIP no python'; Write-Output 'JOB 486 DONE'; return }
$fg486out = @(& $fg486pyExe $fg486pypath $fg486src 2>&1 | ForEach-Object { $_.ToString() })
foreach ($fg486line in $fg486out) { Write-Output ('PATCHER ' + $fg486line) }
if (-not (($fg486out -join ' ') -match 'PATCH OK')) { Write-Output 'PHI FG486 VERDICT: TERMINAL V55 patch=FAIL panel untouched'; Write-Output 'JOB 486 DONE'; return }
$fg486old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
foreach ($fg486o in $fg486old) { Stop-Process -Id $fg486o.Id -Force -ErrorAction SilentlyContinue; Write-Output ('PANEL CLOSED pid=' + $fg486o.Id) }
Start-Sleep -Seconds 1
$fg486csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$fg486exe = Join-Path $fg486dir 'PhiTerminal.exe'
& $fg486csc /nologo /target:winexe /out:$fg486exe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $fg486src | ForEach-Object { Write-Output ('CSC ' + $_) }
$fg486bytes = 0; if (Test-Path $fg486exe) { $fg486bytes = (Get-Item $fg486exe).Length }
Write-Output ('EXE BYTES=' + $fg486bytes)
$fg486pid = 0; $fg486state = 'NOT-LAUNCHED'
if ($fg486bytes -gt 0) {
  $fg486proc = Start-Process -FilePath $fg486exe -WorkingDirectory $fg486dir -PassThru
  Start-Sleep -Seconds 4
  $fg486chk = Get-Process -Id $fg486proc.Id -ErrorAction SilentlyContinue
  if ($fg486chk) { $fg486state = 'STANDS'; $fg486pid = $fg486proc.Id } else { $fg486state = 'EXITED' }
}
Write-Output ('PHI FG486 VERDICT: TERMINAL V55 state=' + $fg486state + ' pid=' + $fg486pid + ' fgFirst=1')
Write-Output 'JOB 486 DONE'
```
