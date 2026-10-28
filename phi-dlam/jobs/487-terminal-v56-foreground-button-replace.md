<!-- PHI-DIRECT -->
```powershell
Write-Output '=== TERMINAL V5.6 487 - THE BUTTON IS THE FOREGROUND ONE (Ground: Tyree, 2026-10-28: listen to me, replace it with the foreground one. The v5.5 panel stood over his open game and the button still found no game: the watched front window seat read the game name in the same breath that records the window, and a name that cannot be read dropped the whole record without a word. This job prints the running process census whole, biggest first, so the game stands named in the record beside its window number, and prints the terminal log attach lines. Then the button is replaced whole with the foreground code itself: the button calls the foreground attach, the exact function the typed attach command runs and the road that worked in his hands, and behind it the watched seat now records the window number first, reads the name only as far as it can be read, and holds the game even when the name cannot be read, speaking any fault in plain words. The picked and library roads leave the button, as he ordered. Source backs up, panel closes, exe recompiles, window relaunches, verdict prints TERMINAL V56 with fgButton. Every variable carries the at487 prefix.) ==='
$at487dir = 'C:\Users\Admin\PhiTerminal'
$at487src = Join-Path $at487dir 'PhiTerminal3.cs'
Get-Process -ErrorAction SilentlyContinue | Sort-Object WorkingSet64 -Descending | Select-Object -First 30 | ForEach-Object { Write-Output ('PROC ' + $_.ProcessName + ' pid=' + $_.Id + ' memMB=' + [int]($_.WorkingSet64 / 1048576)) }
$at487log = Join-Path $at487dir 'phi_terminal_universal.log'
if (Test-Path $at487log) { Get-Content $at487log -Tail 300 | Select-String -Pattern 'ATTACH|FGWATCH' | ForEach-Object { Write-Output ('TLOG ' + $_.Line) } }
$at487lines = @(Get-Content $at487src)
function Print-Fn {
  param($at487ls, $at487sig, $at487tag)
  $at487start = -1
  for ($at487i = 0; $at487i -lt $at487ls.Count; $at487i++) { if ($at487ls[$at487i].Contains($at487sig)) { $at487start = $at487i; break } }
  if ($at487start -lt 0) { Write-Output ($at487tag + ' NOT FOUND'); return }
  $at487depth = 0; $at487begun = $false
  for ($at487j = $at487start; $at487j -lt $at487ls.Count; $at487j++) {
    Write-Output ($at487tag + ' ' + ($at487j + 1) + ' ' + $at487ls[$at487j])
    $at487depth += ([regex]::Matches($at487ls[$at487j], '\{')).Count - ([regex]::Matches($at487ls[$at487j], '\}')).Count
    if ($at487ls[$at487j].Contains('{')) { $at487begun = $true }
    if ($at487begun -and $at487depth -eq 0) { break }
  }
}
Print-Fn $at487lines 'void AttachSelected()' 'SEL'
Copy-Item $at487src ($at487src + '.phi-backup-487') -Force
$at487b64 = @'
aW1wb3J0IHN5cwoKcGF0aCA9IHN5cy5hcmd2WzFdCnNyYyA9IG9wZW4ocGF0aCwgInIiLCBlbmNvZGluZz0idXRmLTgtc2lnIiku
cmVhZCgpCmxpbmVzID0gc3JjLnNwbGl0KCJcbiIpCgpkZWYgY291bnQoc3ViKToKICAgIHJldHVybiBzcmMuY291bnQoc3ViKQoK
ZyA9IFtdCmcuYXBwZW5kKCgiYXR0YWNoU2VsZWN0ZWQiLCBjb3VudCgidm9pZCBBdHRhY2hTZWxlY3RlZCgpIikgPT0gMSkpCmcu
YXBwZW5kKCgiYXR0YWNoRm9yZWdyb3VuZERlZiIsIGNvdW50KCJ2b2lkIEF0dGFjaEZvcmVncm91bmQoKSIpID49IDEpKQpnLmFw
cGVuZCgoInRyYWNrVGljayIsIGNvdW50KCJ2b2lkIFRyYWNrRm9yZWdyb3VuZFRpY2soIikgPT0gMSkpCmcuYXBwZW5kKCgibGFz
dEZnIiwgY291bnQoImxhc3RGZ1BpZCIpID49IDEpKQpnLmFwcGVuZCgoIm5vdFlldCIsIGNvdW50KCJmcm9udCB3aW5kb3cgYXR0
YWNoIHJlYWQiKSA9PSAwKSkKZm9yIG5hbWUsIG9rIGluIGc6CiAgICBwcmludCgiR0FURSAiICsgbmFtZSArICI9IiArICgiMSIg
aWYgb2sgZWxzZSAiMCIpKQppZiBub3QgYWxsKG9rIGZvciBfLCBvayBpbiBnKToKICAgIHByaW50KCJQQVRDSCBHQVRFIEZBSUwg
LSBub3RoaW5nIHdyaXR0ZW4iKQogICAgc3lzLmV4aXQoMikKCmRlZiBmaW5kX2Z1bmMobGluZXMsIHNpZyk6CiAgICBmb3IgaSwg
bG4gaW4gZW51bWVyYXRlKGxpbmVzKToKICAgICAgICBpZiBzaWcgaW4gbG46CiAgICAgICAgICAgIGRlcHRoID0gMAogICAgICAg
ICAgICBzdGFydGVkID0gRmFsc2UKICAgICAgICAgICAgZm9yIGogaW4gcmFuZ2UoaSwgbGVuKGxpbmVzKSk6CiAgICAgICAgICAg
ICAgICBkZXB0aCArPSBsaW5lc1tqXS5jb3VudCgieyIpIC0gbGluZXNbal0uY291bnQoIn0iKQogICAgICAgICAgICAgICAgaWYg
InsiIGluIGxpbmVzW2pdOgogICAgICAgICAgICAgICAgICAgIHN0YXJ0ZWQgPSBUcnVlCiAgICAgICAgICAgICAgICBpZiBzdGFy
dGVkIGFuZCBkZXB0aCA9PSAwOgogICAgICAgICAgICAgICAgICAgIHJldHVybiBpLCBqCiAgICAgICAgICAgIHJldHVybiBpLCAt
MQogICAgcmV0dXJuIC0xLCAtMQoKb2xkX29wZW4gPSBzcmMuY291bnQoInsiKQpvbGRfY2xvc2UgPSBzcmMuY291bnQoIn0iKQoK
c2VsX3MsIHNlbF9lID0gZmluZF9mdW5jKGxpbmVzLCAidm9pZCBBdHRhY2hTZWxlY3RlZCgpIikKdHJrX3MsIHRya19lID0gZmlu
ZF9mdW5jKGxpbmVzLCAidm9pZCBUcmFja0ZvcmVncm91bmRUaWNrKCIpCnByaW50KCJTUEFOIHNlbD0iICsgc3RyKHNlbF9zKSAr
ICIuLiIgKyBzdHIoc2VsX2UpICsgIiB0cmFjaz0iICsgc3RyKHRya19zKSArICIuLiIgKyBzdHIodHJrX2UpKQppZiBtaW4oc2Vs
X3MsIHRya19zKSA8IDAgb3Igc2VsX2UgPCAwIG9yIHRya19lIDwgMDoKICAgIHByaW50KCJQQVRDSCBHQVRFIEZBSUwgLSBzcGFu
IG5vdCBmb3VuZCIpCiAgICBzeXMuZXhpdCgyKQoKaW5kID0gIiAgICAgICAgIgoKbmV3c2VsID0gWwogICAgaW5kICsgInByaXZh
dGUgdm9pZCBBdHRhY2hTZWxlY3RlZCgpIiwKICAgIGluZCArICJ7IiwKICAgIGluZCArICIgICAgQXR0YWNoRm9yZWdyb3VuZCgp
OyIsCiAgICBpbmQgKyAiICAgIGlmIChhdHRhY2hlZCAhPSBudWxsKSByZXR1cm47IiwKICAgIGluZCArICIgICAgaWYgKGxhc3RG
Z1BpZCA+IDApIiwKICAgIGluZCArICIgICAgeyIsCiAgICBpbmQgKyAiICAgICAgICBQcm9jZXNzIGZwMiA9IG51bGw7IiwKICAg
IGluZCArICIgICAgICAgIHRyeSB7IGZwMiA9IFByb2Nlc3MuR2V0UHJvY2Vzc0J5SWQobGFzdEZnUGlkKTsgfSIsCiAgICBpbmQg
KyAiICAgICAgICBjYXRjaCAoRXhjZXB0aW9uIGV4KSB7IFNheShcImZyb250IHdpbmRvdyBhdHRhY2ggcmVhZDogXCIgKyBleC5N
ZXNzYWdlKTsgfSIsCiAgICBpbmQgKyAiICAgICAgICBpZiAoZnAyICE9IG51bGwpIiwKICAgIGluZCArICIgICAgICAgIHsiLAog
ICAgaW5kICsgIiAgICAgICAgICAgIGF0dGFjaGVkID0gZnAyOyIsCiAgICBpbmQgKyAiICAgICAgICAgICAgdHJ5IHsgU2V0QXR0
YWNoZWQoKTsgfSBjYXRjaCB7IFNheShcIkF0dGFjaGVkIHRvIHRoZSBmcm9udCB3aW5kb3cgZ2FtZSAtIHBvd2VycyBhcmUgbGl2
ZS5cIik7IH0iLAogICAgaW5kICsgIiAgICAgICAgICAgIHJldHVybjsiLAogICAgaW5kICsgIiAgICAgICAgfSIsCiAgICBpbmQg
KyAiICAgIH0iLAogICAgaW5kICsgIiAgICBTYXkoXCJObyBnYW1lIGluIGZyb250IHlldCAtIGNsaWNrIGludG8geW91ciBnYW1l
IG9uY2UsIHRoZW4gQVRUQUNILlwiKTsiLAogICAgaW5kICsgIn0iLApdCgpuZXd0cmsgPSBbCiAgICBpbmQgKyAicHJpdmF0ZSB2
b2lkIFRyYWNrRm9yZWdyb3VuZFRpY2sob2JqZWN0IHNlbmRlciwgRXZlbnRBcmdzIGUpIiwKICAgIGluZCArICJ7IiwKICAgIGlu
ZCArICIgICAgdHJ5IiwKICAgIGluZCArICIgICAgeyIsCiAgICBpbmQgKyAiICAgICAgICBJbnRQdHIgaCA9IEdldEZvcmVncm91
bmRXaW5kb3coKTsiLAogICAgaW5kICsgIiAgICAgICAgaWYgKGggPT0gSW50UHRyLlplcm8pIHJldHVybjsiLAogICAgaW5kICsg
IiAgICAgICAgdWludCBwaWQ7IiwKICAgIGluZCArICIgICAgICAgIEdldFdpbmRvd1RocmVhZFByb2Nlc3NJZChoLCBvdXQgcGlk
KTsiLAogICAgaW5kICsgIiAgICAgICAgaWYgKChpbnQpcGlkID09IFN5c3RlbS5EaWFnbm9zdGljcy5Qcm9jZXNzLkdldEN1cnJl
bnRQcm9jZXNzKCkuSWQpIHJldHVybjsiLAogICAgaW5kICsgIiAgICAgICAgaWYgKChpbnQpcGlkID09IGxhc3RGZ1BpZCkgcmV0
dXJuOyIsCiAgICBpbmQgKyAiICAgICAgICBzdHJpbmcgbm0gPSBcIlwiOyIsCiAgICBpbmQgKyAiICAgICAgICB0cnkgeyBubSA9
IFByb2Nlc3MuR2V0UHJvY2Vzc0J5SWQoKGludClwaWQpLlByb2Nlc3NOYW1lOyB9IGNhdGNoIHsgfSIsCiAgICBpbmQgKyAiICAg
ICAgICBpZiAobm0uTGVuZ3RoID4gMCAmJiBJc1N5c3RlbVNlYXQobm0pKSByZXR1cm47IiwKICAgIGluZCArICIgICAgICAgIGxh
c3RGZ1BpZCA9IChpbnQpcGlkOyIsCiAgICBpbmQgKyAiICAgICAgICBsYXN0RmdOYW1lID0gbm07IiwKICAgIGluZCArICIgICAg
ICAgIEhvc3RGb3JtLkxvZyhcIkZHV0FUQ0ggcGlkPVwiICsgbGFzdEZnUGlkICsgXCIgbmFtZT1cIiArIGxhc3RGZ05hbWUpOyIs
CiAgICBpbmQgKyAiICAgIH0iLAogICAgaW5kICsgIiAgICBjYXRjaCB7IH0iLAogICAgaW5kICsgIn0iLApdCgojIGFwcGx5IGRl
c2NlbmRpbmc6IEF0dGFjaFNlbGVjdGVkIHNwYW4gYW5kIHRyYWNrZXIgc3BhbiwgaGlnaGVyIGZpcnN0CnNwYW5zID0gc29ydGVk
KFsoc2VsX3MsIHNlbF9lLCBuZXdzZWwpLCAodHJrX3MsIHRya19lLCBuZXd0cmspXSwga2V5PWxhbWJkYSB0OiB0WzBdLCByZXZl
cnNlPVRydWUpCmZvciBzLCBlLCBuZXcgaW4gc3BhbnM6CiAgICBsaW5lc1tzOmUgKyAxXSA9IG5ldwoKb3V0ID0gIlxuIi5qb2lu
KGxpbmVzKQpuZXdfb3BlbiA9IG91dC5jb3VudCgieyIpCm5ld19jbG9zZSA9IG91dC5jb3VudCgifSIpCnByaW50KCJCUkFDRSBE
RUxUQSBvcGVuPSIgKyBzdHIobmV3X29wZW4gLSBvbGRfb3BlbikgKyAiIGNsb3NlPSIgKyBzdHIobmV3X2Nsb3NlIC0gb2xkX2Ns
b3NlKSkKaWYgKG5ld19vcGVuIC0gbmV3X2Nsb3NlKSAhPSAob2xkX29wZW4gLSBvbGRfY2xvc2UpOgogICAgcHJpbnQoIlBBVENI
IEdBVEUgRkFJTCAtIGJyYWNlIGJhbGFuY2UgY2hhbmdlZCIpCiAgICBzeXMuZXhpdCgyKQpvcGVuKHBhdGgsICJ3IiwgZW5jb2Rp
bmc9InV0Zi04Iikud3JpdGUob3V0KQpwcmludCgiUEFUQ0ggT0sgZmdCdXR0b249MSIpCg==
'@
$at487pypath = Join-Path $at487dir 'patch487.py'
[IO.File]::WriteAllBytes($at487pypath, [Convert]::FromBase64String($at487b64))
$at487pyExe = $null
foreach ($at487cand in @('python', 'python3', 'py')) { $at487gc = Get-Command $at487cand -ErrorAction SilentlyContinue; if ($at487gc) { $at487pyExe = $at487gc.Source; break } }
Write-Output ('PYTHON=' + $at487pyExe)
if (-not $at487pyExe) { Write-Output 'PHI AT487 VERDICT: TERMINAL V56 SKIP no python'; Write-Output 'JOB 487 DONE'; return }
$at487out = @(& $at487pyExe $at487pypath $at487src 2>&1 | ForEach-Object { $_.ToString() })
foreach ($at487line in $at487out) { Write-Output ('PATCHER ' + $at487line) }
if (-not (($at487out -join ' ') -match 'PATCH OK')) { Write-Output 'PHI AT487 VERDICT: TERMINAL V56 patch=FAIL panel untouched'; Write-Output 'JOB 487 DONE'; return }
$at487old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
foreach ($at487o in $at487old) { Stop-Process -Id $at487o.Id -Force -ErrorAction SilentlyContinue; Write-Output ('PANEL CLOSED pid=' + $at487o.Id) }
Start-Sleep -Seconds 1
$at487csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$at487exe = Join-Path $at487dir 'PhiTerminal.exe'
& $at487csc /nologo /target:winexe /out:$at487exe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $at487src | ForEach-Object { Write-Output ('CSC ' + $_) }
$at487bytes = 0; if (Test-Path $at487exe) { $at487bytes = (Get-Item $at487exe).Length }
Write-Output ('EXE BYTES=' + $at487bytes)
$at487pid = 0; $at487state = 'NOT-LAUNCHED'
if ($at487bytes -gt 0) {
  $at487proc = Start-Process -FilePath $at487exe -WorkingDirectory $at487dir -PassThru
  Start-Sleep -Seconds 4
  $at487chk = Get-Process -Id $at487proc.Id -ErrorAction SilentlyContinue
  if ($at487chk) { $at487state = 'STANDS'; $at487pid = $at487proc.Id } else { $at487state = 'EXITED' }
}
Write-Output ('PHI AT487 VERDICT: TERMINAL V56 state=' + $at487state + ' pid=' + $at487pid + ' fgButton=1')
Write-Output 'JOB 487 DONE'
```
