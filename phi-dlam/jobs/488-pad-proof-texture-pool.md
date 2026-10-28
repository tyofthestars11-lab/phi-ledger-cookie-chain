<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PAD PROOF 488 - THE PAD SPEAKS IN THE LOG (Ground: Tyree, 2026-10-28: fix the game pad for VEIL, it worked fine before just jumping and running, and his editor photo the same minutes: she stands, the world clock runs, paused equals 0, and the red line reads video memory exhausted 18.258 MB over budget while the bodies stand black against the sky. The pad worked in his hands in the 442 era, keyboard and mouse work now, the source pad map stands whole at 18 keys, both input seats stand written, and the 482 build is green, so the fault lives at runtime where no source read can see it. This job prints the GameMode input region and the main menu file whole, raises the texture streaming pool to 2500 in DefaultEngine.ini so the bodies can take their real materials, seats PHI PAD PROOF in the character Tick: every two seconds the log reads the raw stick and button state straight from the controller and which mapping contexts stand seated, a read that names its own fault line next play. The build runs when the editor stands closed; when the editor stands open the patch stands written and the build rides the next drain. Every variable carries the gp488 prefix.) ==='
$gp488proj = 'D:\VEIL-OMNI'
$gp488gm = Join-Path $gp488proj 'Source\VEIL\Private\Game\VEILGameMode.cpp'
$gp488gmlines = @(Get-Content $gp488gm)
for ($gp488i = 179; $gp488i -lt 230 -and $gp488i -lt $gp488gmlines.Count; $gp488i++) { Write-Output ('GM ' + ($gp488i + 1) + ' ' + $gp488gmlines[$gp488i]) }
$gp488menu = Join-Path $gp488proj 'Source\VEIL\Private\Game\VEILMainMenu.cpp'
if (Test-Path $gp488menu) { $gp488mlines = @(Get-Content $gp488menu); Write-Output ('MENU LINES=' + $gp488mlines.Count); for ($gp488i = 0; $gp488i -lt $gp488mlines.Count; $gp488i++) { Write-Output ('MENU ' + ($gp488i + 1) + ' ' + $gp488mlines[$gp488i]) } } else { Write-Output 'MENU NOT FOUND' }
$gp488ini = Join-Path $gp488proj 'Config\DefaultEngine.ini'
Select-String -Path $gp488ini -Pattern 'Streaming|PoolSize|ConsoleVariables' | ForEach-Object { Write-Output ('INI BEFORE ' + $_.Line) }
Copy-Item $gp488ini ($gp488ini + '.phi-backup-488') -Force
$gp488txt = Get-Content $gp488ini -Raw
if ($gp488txt -match 'r\.Streaming\.PoolSize\s*=\s*\d+') { $gp488txt = $gp488txt -replace 'r\.Streaming\.PoolSize\s*=\s*\d+', 'r.Streaming.PoolSize=2500' }
elseif ($gp488txt -match '\[ConsoleVariables\]') { $gp488txt = $gp488txt -replace '\[ConsoleVariables\]', "[ConsoleVariables]`r`nr.Streaming.PoolSize=2500" }
else { $gp488txt = $gp488txt + "`r`n[ConsoleVariables]`r`nr.Streaming.PoolSize=2500`r`n" }
Set-Content $gp488ini $gp488txt -Encoding ASCII
Select-String -Path $gp488ini -Pattern 'r.Streaming.PoolSize' | ForEach-Object { Write-Output ('INI VERIFY ' + $_.Line) }
$gp488src = Join-Path $gp488proj 'Source\VEIL\Private\Character\VEILCharacter.cpp'
Copy-Item $gp488src ($gp488src + '.phi-backup-488') -Force
$gp488b64 = @'
aW1wb3J0IHN5cywgcmUKCnBhdGggPSBzeXMuYXJndlsxXQpzcmMgPSBvcGVuKHBhdGgsICJyIiwgZW5jb2Rpbmc9InV0Zi04LXNp
ZyIpLnJlYWQoKQpsaW5lcyA9IHNyYy5zcGxpdCgiXG4iKQoKZyA9IFtdCmcuYXBwZW5kKCgidGlja1NpZyIsIHNyYy5jb3VudCgi
dm9pZCBBVkVJTENoYXJhY3Rlcjo6VGljaygiKSA9PSAxKSkKZy5hcHBlbmQoKCJub3RZZXQiLCBzcmMuY291bnQoIlBISSBQQUQg
UFJPT0YiKSA9PSAwKSkKZy5hcHBlbmQoKCJjdHhNZW1iZXJzIiwgc3JjLmNvdW50KCJCdWlsdE1hcHBpbmdDb250ZXh0IikgPj0g
MSBhbmQgc3JjLmNvdW50KCJEZWZhdWx0TWFwcGluZ0NvbnRleHQiKSA+PSAxKSkKZm9yIG5hbWUsIG9rIGluIGc6CiAgICBwcmlu
dCgiR0FURSAiICsgbmFtZSArICI9IiArICgiMSIgaWYgb2sgZWxzZSAiMCIpKQppZiBub3QgYWxsKG9rIGZvciBfLCBvayBpbiBn
KToKICAgIHByaW50KCJQQVRDSCBHQVRFIEZBSUwgLSBub3RoaW5nIHdyaXR0ZW4iKQogICAgc3lzLmV4aXQoMikKCiMgbG9jYXRl
IFRpY2sgc2lnbmF0dXJlLCBleHRyYWN0IHRoZSBmbG9hdCBwYXJhbSBuYW1lLCBmaW5kIHNwYW4Kc2lnX2kgPSAtMQpwYXJhbSA9
IE5vbmUKZm9yIGksIGxuIGluIGVudW1lcmF0ZShsaW5lcyk6CiAgICBpZiAidm9pZCBBVkVJTENoYXJhY3Rlcjo6VGljaygiIGlu
IGxuOgogICAgICAgIHNpZ19pID0gaQogICAgICAgIG0gPSByZS5zZWFyY2gociJUaWNrXChccypmbG9hdFxzKyhcdyspIiwgbG4p
CiAgICAgICAgaWYgbToKICAgICAgICAgICAgcGFyYW0gPSBtLmdyb3VwKDEpCiAgICAgICAgYnJlYWsKaWYgc2lnX2kgPCAwIG9y
IG5vdCBwYXJhbToKICAgIHByaW50KCJQQVRDSCBHQVRFIEZBSUwgLSB0aWNrIHBhcmFtIG5vdCByZWFkIikKICAgIHN5cy5leGl0
KDIpCnByaW50KCJUSUNLIHBhcmFtPSIgKyBwYXJhbSkKCmRlcHRoID0gMApzdGFydGVkID0gRmFsc2UKb3Blbl9pID0gLTEKZW5k
X2kgPSAtMQpmb3IgaiBpbiByYW5nZShzaWdfaSwgbGVuKGxpbmVzKSk6CiAgICBpZiAieyIgaW4gbGluZXNbal0gYW5kIG9wZW5f
aSA8IDA6CiAgICAgICAgb3Blbl9pID0gagogICAgZGVwdGggKz0gbGluZXNbal0uY291bnQoInsiKSAtIGxpbmVzW2pdLmNvdW50
KCJ9IikKICAgIGlmICJ7IiBpbiBsaW5lc1tqXToKICAgICAgICBzdGFydGVkID0gVHJ1ZQogICAgaWYgc3RhcnRlZCBhbmQgZGVw
dGggPT0gMDoKICAgICAgICBlbmRfaSA9IGoKICAgICAgICBicmVhawpwcmludCgiU1BBTiB0aWNrPSIgKyBzdHIoc2lnX2kpICsg
Ii4uIiArIHN0cihlbmRfaSkgKyAiIG9wZW49IiArIHN0cihvcGVuX2kpKQppZiBvcGVuX2kgPCAwIG9yIGVuZF9pIDwgMDoKICAg
IHByaW50KCJQQVRDSCBHQVRFIEZBSUwgLSB0aWNrIHNwYW4gbm90IGZvdW5kIikKICAgIHN5cy5leGl0KDIpCgpvbGRfb3BlbiA9
IHNyYy5jb3VudCgieyIpCm9sZF9jbG9zZSA9IHNyYy5jb3VudCgifSIpCnQgPSAiXHQiCmJsb2NrID0gWwogICAgdCArICJ7IiwK
ICAgIHQgKyB0ICsgInN0YXRpYyBmbG9hdCBQYWRQcm9vZkFjYyA9IDAuZjsiLAogICAgdCArIHQgKyAic3RhdGljIGludCBQYWRQ
cm9vZkNvdW50ID0gMDsiLAogICAgdCArIHQgKyAiUGFkUHJvb2ZBY2MgKz0gIiArIHBhcmFtICsgIjsiLAogICAgdCArIHQgKyAi
aWYgKFBhZFByb29mQWNjID4gMi5mICYmIFBhZFByb29mQ291bnQgPCA2MCkiLAogICAgdCArIHQgKyAieyIsCiAgICB0ICsgdCAr
IHQgKyAiUGFkUHJvb2ZBY2MgPSAwLmY7IFBhZFByb29mQ291bnQrKzsiLAogICAgdCArIHQgKyB0ICsgImlmIChBUGxheWVyQ29u
dHJvbGxlciogUFBDID0gQ2FzdDxBUGxheWVyQ29udHJvbGxlcj4oR2V0Q29udHJvbGxlcigpKSkiLAogICAgdCArIHQgKyB0ICsg
InsiLAogICAgdCArIHQgKyB0ICsgdCArICJmbG9hdCBMWCA9IFBQQy0+R2V0SW5wdXRBbmFsb2dLZXlTdGF0ZShFS2V5czo6R2Ft
ZXBhZF9MZWZ0WCk7IiwKICAgIHQgKyB0ICsgdCArIHQgKyAiZmxvYXQgTFkgPSBQUEMtPkdldElucHV0QW5hbG9nS2V5U3RhdGUo
RUtleXM6OkdhbWVwYWRfTGVmdFkpOyIsCiAgICB0ICsgdCArIHQgKyB0ICsgImZsb2F0IFJYID0gUFBDLT5HZXRJbnB1dEFuYWxv
Z0tleVN0YXRlKEVLZXlzOjpHYW1lcGFkX1JpZ2h0WCk7IiwKICAgIHQgKyB0ICsgdCArIHQgKyAiaW50IEZBID0gUFBDLT5Jc0lu
cHV0S2V5RG93bihFS2V5czo6R2FtZXBhZF9GYWNlQnV0dG9uX0JvdHRvbSkgPyAxIDogMDsiLAogICAgdCArIHQgKyB0ICsgdCAr
ICJpbnQgSGFzQnVpbHQgPSAtMTsgaW50IEhhc0RlZiA9IC0xOyIsCiAgICB0ICsgdCArIHQgKyB0ICsgImlmIChVTG9jYWxQbGF5
ZXIqIExQID0gUFBDLT5HZXRMb2NhbFBsYXllcigpKSB7IGlmIChVRW5oYW5jZWRJbnB1dExvY2FsUGxheWVyU3Vic3lzdGVtKiBF
UyA9IExQLT5HZXRTdWJzeXN0ZW08VUVuaGFuY2VkSW5wdXRMb2NhbFBsYXllclN1YnN5c3RlbT4oKSkgeyBIYXNCdWlsdCA9IChC
dWlsdE1hcHBpbmdDb250ZXh0ICYmIEVTLT5IYXNNYXBwaW5nQ29udGV4dChCdWlsdE1hcHBpbmdDb250ZXh0KSkgPyAxIDogMDsg
SGFzRGVmID0gKERlZmF1bHRNYXBwaW5nQ29udGV4dCAmJiBFUy0+SGFzTWFwcGluZ0NvbnRleHQoRGVmYXVsdE1hcHBpbmdDb250
ZXh0KSkgPyAxIDogMDsgfSB9IiwKICAgIHQgKyB0ICsgdCArIHQgKyAiVUVfTE9HKExvZ1RlbXAsIERpc3BsYXksIFRFWFQoXCJQ
SEkgUEFEIFBST09GOiBuPSVkIGx4PSUuMmYgbHk9JS4yZiByeD0lLjJmIGZhY2VBPSVkIGhhc0J1aWx0PSVkIGhhc0RlZj0lZFwi
KSwgUGFkUHJvb2ZDb3VudCwgTFgsIExZLCBSWCwgRkEsIEhhc0J1aWx0LCBIYXNEZWYpOyIsCiAgICB0ICsgdCArIHQgKyAifSIs
CiAgICB0ICsgdCArICJ9IiwKICAgIHQgKyAifSIsCl0KCmxpbmVzW29wZW5faSArIDE6b3Blbl9pICsgMV0gPSBibG9jawpvdXQg
PSAiXG4iLmpvaW4obGluZXMpCm5ld19vcGVuID0gb3V0LmNvdW50KCJ7IikKbmV3X2Nsb3NlID0gb3V0LmNvdW50KCJ9IikKcHJp
bnQoIkJSQUNFIERFTFRBIG9wZW49IiArIHN0cihuZXdfb3BlbiAtIG9sZF9vcGVuKSArICIgY2xvc2U9IiArIHN0cihuZXdfY2xv
c2UgLSBvbGRfY2xvc2UpKQppZiAobmV3X29wZW4gLSBuZXdfY2xvc2UpICE9IChvbGRfb3BlbiAtIG9sZF9jbG9zZSk6CiAgICBw
cmludCgiUEFUQ0ggR0FURSBGQUlMIC0gYnJhY2UgYmFsYW5jZSBjaGFuZ2VkIikKICAgIHN5cy5leGl0KDIpCm9wZW4ocGF0aCwg
InciLCBlbmNvZGluZz0idXRmLTgiKS53cml0ZShvdXQpCnByaW50KCJQQVRDSCBPSyBwYWRwcm9vZj0xIikK
'@
$gp488pypath = Join-Path $gp488proj 'patch488.py'
[IO.File]::WriteAllBytes($gp488pypath, [Convert]::FromBase64String($gp488b64))
$gp488pyExe = $null
foreach ($gp488cand in @('python', 'python3', 'py')) { $gp488gc = Get-Command $gp488cand -ErrorAction SilentlyContinue; if ($gp488gc) { $gp488pyExe = $gp488gc.Source; break } }
Write-Output ('PYTHON=' + $gp488pyExe)
if (-not $gp488pyExe) { Write-Output 'PHI GP488 VERDICT: PADPROOF SKIP no python'; Write-Output 'JOB 488 DONE'; return }
$gp488out = @(& $gp488pyExe $gp488pypath $gp488src 2>&1 | ForEach-Object { $_.ToString() })
foreach ($gp488line in $gp488out) { Write-Output ('PATCHER ' + $gp488line) }
if (-not (($gp488out -join ' ') -match 'PATCH OK')) { Write-Output 'PHI GP488 VERDICT: PADPROOF patch=FAIL'; Write-Output 'JOB 488 DONE'; return }
$gp488ed = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
if ($gp488ed.Count -gt 0) { Write-Output 'EDITOR=OPEN build=HELD-WRITTEN'; Write-Output 'PHI GP488 VERDICT: PADPROOF patch=OK ini=2500 build=HELD-WRITTEN'; Write-Output 'JOB 488 DONE'; return }
Write-Output 'EDITOR=CLOSED'
$gp488buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$gp488uproj = Join-Path $gp488proj 'VEIL.uproject'
$gp488log = Join-Path $gp488proj 'Saved\build488.log'
& $gp488buildbat VEILEditor Win64 Development -Project="$gp488uproj" -WaitMutex -NoHotReload *> "$gp488log"
$gp488res = ''
if (Test-Path $gp488log) { $gp488res = (Select-String -Path $gp488log -Pattern 'Result:' | Select-Object -Last 1).Line }
Write-Output ('BUILD ' + $gp488res)
if (Test-Path $gp488log) { Select-String -Path $gp488log -Pattern 'erro[r]' | Select-Object -First 6 | ForEach-Object { Write-Output ('ERR ' + $_.Line) } }
Write-Output ('PHI GP488 VERDICT: PADPROOF patch=OK ini=2500 build=' + $gp488res)
Write-Output 'JOB 488 DONE'
```
