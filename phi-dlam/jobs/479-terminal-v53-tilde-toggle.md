<!-- PHI-DIRECT -->
```powershell
Write-Output '=== TERMINAL V5.3 479 - THE TOGGLE KEY MOVES TO TILDE (Ground from Tyree, 2026-10-28: Tab does not work, and the seat he chose in the side chat at 13:33 MDT stands in memory: Tab is the scanner key inside Cyberpunk, so the terminal toggle fought the game for one key. The toggle moves to the tilde key above Tab, the classic terminal key, OEM 3 in Windows and Keys.Oemtilde in the source, a key Cyberpunk leaves alone. Tab goes back to the game untouched and the Escape hide stays. The new key gets two roads so one road closing can never close the toggle again: the standing low level hook answers it, and a poll timer reads the key state directly 25 times a second, both roads passing through one guarded toggle that can never throw and never double fires inside 350 milliseconds. The hook seat itself hardens with a second module handle road, and the toggle and hide log lines name the tilde seat. The job reads the terminal log and the source toggle lines first and prints them, backs the source up, then runs a count gated patcher carried in base64; any gate miss writes nothing and the standing panel keeps running untouched. On a clean patch the panel closes, the exe recompiles, the window relaunches, and the fresh log lines print as the verdict ground: TERMINAL V53 with its state. Every variable carries the tk479 prefix.) ==='
$tk479dir = 'C:\Users\Admin\PhiTerminal'
$tk479src = Join-Path $tk479dir 'PhiTerminal3.cs'
$tk479log = Join-Path $tk479dir 'phi_terminal_universal.log'
if (Test-Path $tk479log) {
  $tk479logAll = @(Get-Content $tk479log)
  $tk479hookLines = @($tk479logAll | Select-String -SimpleMatch 'HOOK SEATED')
  $tk479lastHook = 'none'; if ($tk479hookLines.Count -gt 0) { $tk479lastHook = $tk479hookLines[$tk479hookLines.Count - 1].Line }
  $tk479tabShows = @($tk479logAll | Select-String -SimpleMatch 'TAB SHOW').Count
  $tk479tabHides = @($tk479logAll | Select-String -SimpleMatch 'TAB HIDE').Count
  Write-Output ('LOGREAD lastHook=' + $tk479lastHook)
  Write-Output ('LOGREAD tabShows=' + $tk479tabShows + ' tabHides=' + $tk479tabHides)
} else { Write-Output 'LOGREAD log missing' }
$tk479srcRaw = Get-Content $tk479src -Raw
$tk479tabSeats = ([regex]::Matches($tk479srcRaw, 'Keys\.Tab')).Count
$tk479tildeSeats = ([regex]::Matches($tk479srcRaw, 'Keys\.Oemtilde')).Count
Write-Output ('SRCREAD tabSeats=' + $tk479tabSeats + ' tildeSeats=' + $tk479tildeSeats)
Copy-Item $tk479src ($tk479src + '.phi-backup-479') -Force
$tk479b64 = @'
aW1wb3J0IHN5cwoKcGF0aCA9IHN5cy5hcmd2WzFdCnNyYyA9IG9wZW4ocGF0aCwgInIiLCBlbmNvZGluZz0idXRmLTgtc2lnIiku
cmVhZCgpCgplZGl0cyA9IFtdCgplZGl0cy5hcHBlbmQoKAogICAgIiAgICAgICAgcHJpdmF0ZSBIb29rUHJvYyBwcm9jOyIsCiAg
ICAiICAgICAgICBwcml2YXRlIEhvb2tQcm9jIHByb2M7XG4iCiAgICAiICAgICAgICBwcml2YXRlIGJvb2wga2V5V2FzRG93biA9
IGZhbHNlO1xuIgogICAgIiAgICAgICAgcHJpdmF0ZSBsb25nIGxhc3RLZXlNcyA9IDA7XG4iCiAgICAiICAgICAgICBwcml2YXRl
IFN5c3RlbS5XaW5kb3dzLkZvcm1zLlRpbWVyIGtleVBvbGw7IgopKQoKZWRpdHMuYXBwZW5kKCgKICAgICcgICAgICAgIFtEbGxJ
bXBvcnQoImtlcm5lbDMyLmRsbCIpXSBzdGF0aWMgZXh0ZXJuIEludFB0ciBHZXRNb2R1bGVIYW5kbGUoc3RyaW5nIG5hbWUpOycs
CiAgICAnICAgICAgICBbRGxsSW1wb3J0KCJrZXJuZWwzMi5kbGwiKV0gc3RhdGljIGV4dGVybiBJbnRQdHIgR2V0TW9kdWxlSGFu
ZGxlKHN0cmluZyBuYW1lKTtcbicKICAgICcgICAgICAgIFtEbGxJbXBvcnQoInVzZXIzMi5kbGwiKV0gc3RhdGljIGV4dGVybiBz
aG9ydCBHZXRBc3luY0tleVN0YXRlKGludCB2ayk7JwopKQoKZWRpdHMuYXBwZW5kKCgKICAgICIgICAgICAgICAgICBob29rSWQg
PSBTZXRXaW5kb3dzSG9va0V4KFdIX0tFWUJPQVJEX0xMLCBwcm9jLCBHZXRNb2R1bGVIYW5kbGUoUHJvY2Vzcy5HZXRDdXJyZW50
UHJvY2VzcygpLk1haW5Nb2R1bGUuTW9kdWxlTmFtZSksIDApOyIsCiAgICAiICAgICAgICAgICAgSW50UHRyIG1vZEggPSBHZXRN
b2R1bGVIYW5kbGUoUHJvY2Vzcy5HZXRDdXJyZW50UHJvY2VzcygpLk1haW5Nb2R1bGUuTW9kdWxlTmFtZSk7XG4iCiAgICAiICAg
ICAgICAgICAgaWYgKG1vZEggPT0gSW50UHRyLlplcm8pIHsgbW9kSCA9IE1hcnNoYWwuR2V0SElOU1RBTkNFKHR5cGVvZihIb3N0
Rm9ybSkuQXNzZW1ibHkuTWFuaWZlc3RNb2R1bGUpOyB9XG4iCiAgICAiICAgICAgICAgICAgaG9va0lkID0gU2V0V2luZG93c0hv
b2tFeChXSF9LRVlCT0FSRF9MTCwgcHJvYywgbW9kSCwgMCk7IgopKQoKZWRpdHMuYXBwZW5kKCgKICAgICIgICAgICAgIHByaXZh
dGUgSW50UHRyIEhvb2tDYWxsYmFjayhpbnQgY29kZSwgSW50UHRyIHdwLCBJbnRQdHIgbHApIiwKICAgICIgICAgICAgIHB1Ymxp
YyB2b2lkIFRvZ2dsZUtleShzdHJpbmcgcm9hZClcbiIKICAgICIgICAgICAgIHtcbiIKICAgICIgICAgICAgICAgICBsb25nIG5v
d01zID0gRGF0ZVRpbWUuVXRjTm93LlRpY2tzIC8gMTAwMDA7XG4iCiAgICAiICAgICAgICAgICAgaWYgKG5vd01zIC0gbGFzdEtl
eU1zIDwgMzUwKSB7IHJldHVybjsgfVxuIgogICAgIiAgICAgICAgICAgIGxhc3RLZXlNcyA9IG5vd01zO1xuIgogICAgIiAgICAg
ICAgICAgIExvZyhcIlRJTERFIFZJQSBcIiArIHJvYWQpO1xuIgogICAgIiAgICAgICAgICAgIHRyeSB7IHRlcm0uQmVnaW5JbnZv
a2UobmV3IEFjdGlvbih0ZXJtLlRvZ2dsZVNhZmUpKTsgfSBjYXRjaCB7IH1cbiIKICAgICIgICAgICAgIH1cbiIKICAgICIgICAg
ICAgIHByaXZhdGUgSW50UHRyIEhvb2tDYWxsYmFjayhpbnQgY29kZSwgSW50UHRyIHdwLCBJbnRQdHIgbHApIgopKQoKZWRpdHMu
YXBwZW5kKCgKICAgICIgICAgICAgICAgICAgICAgaWYgKHZrID09IChpbnQpS2V5cy5UYWIpIHsgdGVybS5CZWdpbkludm9rZShu
ZXcgQWN0aW9uKHRlcm0uVG9nZ2xlU2FmZSkpOyB9IiwKICAgICIgICAgICAgICAgICAgICAgaWYgKHZrID09IChpbnQpS2V5cy5P
ZW10aWxkZSkgeyBUb2dnbGVLZXkoXCJIT09LXCIpOyB9IgopKQoKZWRpdHMuYXBwZW5kKCgKICAgICIgICAgICAgICAgICAgICAg
ZWxzZSBpZiAodmsgPT0gKGludClLZXlzLkVzY2FwZSkgeyB0ZXJtLkJlZ2luSW52b2tlKG5ldyBBY3Rpb24odGVybS5IaWRlU2Fm
ZSkpOyB9IiwKICAgICIgICAgICAgICAgICAgICAgZWxzZSBpZiAodmsgPT0gKGludClLZXlzLkVzY2FwZSkgeyB0cnkgeyB0ZXJt
LkJlZ2luSW52b2tlKG5ldyBBY3Rpb24odGVybS5IaWRlU2FmZSkpOyB9IGNhdGNoIHsgfSB9IgopKQoKZWRpdHMuYXBwZW5kKCgK
ICAgICcgICAgICAgICAgICBMb2coIkhPT0sgU0VBVEVEIHYzIGhvb2s9IiArIGhvb2tJZC5Ub1N0cmluZygpKTsnLAogICAgJyAg
ICAgICAgICAgIExvZygiSE9PSyBTRUFURUQgdjMgaG9vaz0iICsgaG9va0lkLlRvU3RyaW5nKCkpO1xuJwogICAgIiAgICAgICAg
ICAgIGtleVBvbGwgPSBuZXcgU3lzdGVtLldpbmRvd3MuRm9ybXMuVGltZXIoKTtcbiIKICAgICIgICAgICAgICAgICBrZXlQb2xs
LkludGVydmFsID0gNDA7XG4iCiAgICAiICAgICAgICAgICAga2V5UG9sbC5UaWNrICs9IChzMiwgZTIpID0+IHsgYm9vbCBkb3du
Tm93ID0gKEdldEFzeW5jS2V5U3RhdGUoKGludClLZXlzLk9lbXRpbGRlKSAmIDB4ODAwMCkgIT0gMDsgaWYgKGRvd25Ob3cgJiYg
IWtleVdhc0Rvd24pIHsgVG9nZ2xlS2V5KFwiUE9MTFwiKTsgfSBrZXlXYXNEb3duID0gZG93bk5vdzsgfTtcbiIKICAgICIgICAg
ICAgICAgICBrZXlQb2xsLlN0YXJ0KCk7XG4iCiAgICAnICAgICAgICAgICAgTG9nKCJUSUxERSBQT0xMIFNFQVRFRCB2NTMiKTsn
CikpCgplZGl0cy5hcHBlbmQoKAogICAgJ0hvc3RGb3JtLkxvZygiVEFCIEhJREUiKScsCiAgICAnSG9zdEZvcm0uTG9nKCJUSUxE
RSBISURFIiknCikpCgplZGl0cy5hcHBlbmQoKAogICAgJ0hvc3RGb3JtLkxvZygiVEFCIFNIT1ciKScsCiAgICAnSG9zdEZvcm0u
TG9nKCJUSUxERSBTSE9XIiknCikpCgplZGl0cy5hcHBlbmQoKAogICAgJ01ha2VCdG4oIkhJREUgKFRhYikiJywKICAgICdNYWtl
QnRuKCJISURFICh+KSInCikpCgplZGl0cy5hcHBlbmQoKAogICAgJ0hPT0sgU0VBVEVEIHYzIGhvb2s9JywKICAgICdIT09LIFNF
QVRFRCB2NTMgdG9nZ2xlPVRJTERFIGhvb2s9JwopKQoKY291bnRzID0gW10Kb2sgPSBUcnVlCmZvciBpLCAob2xkLCBuZXcpIGlu
IGVudW1lcmF0ZShlZGl0cyk6CiAgICBjID0gc3JjLmNvdW50KG9sZCkKICAgIGNvdW50cy5hcHBlbmQoImUiICsgc3RyKGkgKyAx
KSArICI9IiArIHN0cihjKSkKICAgIGlmIGMgIT0gMToKICAgICAgICBvayA9IEZhbHNlCgpwcmludCgiR0FURVMgIiArICIgIi5q
b2luKGNvdW50cykpCmlmIG5vdCBvazoKICAgIHByaW50KCJQQVRDSCBHQVRFIEZBSUwiKQogICAgc3lzLmV4aXQoMikKCm91dCA9
IHNyYwpmb3Igb2xkLCBuZXcgaW4gZWRpdHM6CiAgICBvdXQgPSBvdXQucmVwbGFjZShvbGQsIG5ldywgMSkKCm9wZW5zID0gb3V0
LmNvdW50KCJ7IikgLSBzcmMuY291bnQoInsiKQpjbG9zZXMgPSBvdXQuY291bnQoIn0iKSAtIHNyYy5jb3VudCgifSIpCnByaW50
KCJCUkFDRSBERUxUQSBvcGVuPSIgKyBzdHIob3BlbnMpICsgIiBjbG9zZT0iICsgc3RyKGNsb3NlcykpCmlmIG9wZW5zICE9IGNs
b3NlczoKICAgIHByaW50KCJQQVRDSCBHQVRFIEZBSUwgYnJhY2VzIikKICAgIHN5cy5leGl0KDMpCgp3aXRoIG9wZW4ocGF0aCwg
InciLCBlbmNvZGluZz0idXRmLTgiKSBhcyBmOgogICAgZi53cml0ZShvdXQpCnByaW50KCJQQVRDSCBPSyB0aWxkZT0xIHR3b3Jv
YWRzPTEiKQo=
'@
$tk479pypath = Join-Path $tk479dir 'patch479.py'
[IO.File]::WriteAllBytes($tk479pypath, [Convert]::FromBase64String($tk479b64))
$tk479pyExe = $null
foreach ($tk479cand in @('python', 'python3', 'py')) { $tk479gc = Get-Command $tk479cand -ErrorAction SilentlyContinue; if ($tk479gc) { $tk479pyExe = $tk479gc.Source; break } }
Write-Output ('PYTHON=' + $tk479pyExe)
if (-not $tk479pyExe) { Write-Output 'PHI TK479 VERDICT: TERMINAL V53 SKIP no python'; Write-Output 'JOB 479 DONE'; return }
$tk479out = @(& $tk479pyExe $tk479pypath $tk479src 2>&1 | ForEach-Object { $_.ToString() })
foreach ($tk479line in $tk479out) { Write-Output ('PATCHER ' + $tk479line) }
$tk479patchOk = (($tk479out -join ' ') -match 'PATCH OK')
if (-not $tk479patchOk) { Write-Output 'PHI TK479 VERDICT: TERMINAL V53 patch=FAIL state=UNCHANGED'; Write-Output 'JOB 479 DONE'; return }
$tk479srcRaw2 = Get-Content $tk479src -Raw
$tk479tabAfter = ([regex]::Matches($tk479srcRaw2, 'Keys\.Tab')).Count
$tk479tildeAfter = ([regex]::Matches($tk479srcRaw2, 'Keys\.Oemtilde')).Count
Write-Output ('VERIFY tabAfter=' + $tk479tabAfter + ' tildeAfter=' + $tk479tildeAfter)
$tk479old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
foreach ($tk479o in $tk479old) { Stop-Process -Id $tk479o.Id -Force -ErrorAction SilentlyContinue; Write-Output ('PANEL CLOSED pid=' + $tk479o.Id) }
Start-Sleep -Seconds 1
$tk479csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$tk479exe = Join-Path $tk479dir 'PhiTerminal.exe'
& $tk479csc /nologo /target:winexe /out:$tk479exe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $tk479src | ForEach-Object { Write-Output ('CSC ' + $_) }
$tk479exeBytes = 0; if (Test-Path $tk479exe) { $tk479exeBytes = (Get-Item $tk479exe).Length }
Write-Output ('EXE BYTES=' + $tk479exeBytes)
$tk479pid = 0; $tk479state = 'NOT-LAUNCHED'
if ($tk479exeBytes -gt 0) {
  $tk479proc = Start-Process -FilePath $tk479exe -WorkingDirectory $tk479dir -PassThru
  Start-Sleep -Seconds 4
  $tk479check2 = Get-Process -Id $tk479proc.Id -ErrorAction SilentlyContinue
  if ($tk479check2) { $tk479state = 'STANDS'; $tk479pid = $tk479proc.Id } else { $tk479state = 'EXITED' }
}
if (Test-Path $tk479log) {
  $tk479fresh = @(Get-Content $tk479log)
  $tk479fh = @($tk479fresh | Select-String -SimpleMatch 'HOOK SEATED')
  if ($tk479fh.Count -gt 0) { Write-Output ('LOGFRESH ' + $tk479fh[$tk479fh.Count - 1].Line) }
  $tk479fp = @($tk479fresh | Select-String -SimpleMatch 'TILDE POLL SEATED')
  if ($tk479fp.Count -gt 0) { Write-Output ('LOGFRESH ' + $tk479fp[$tk479fp.Count - 1].Line) }
}
Write-Output ('PHI TK479 VERDICT: TERMINAL V53 state=' + $tk479state + ' pid=' + $tk479pid + ' patch=OK tildeAfter=' + $tk479tildeAfter)
Write-Output 'JOB 479 DONE'
```
