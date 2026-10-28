<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CONTROLS FIX 480 - THE BUILT MAP GETS ITS SEAT (Ground assembled whole: Tyree at the 473 build, mouse and key does, not xbox controller, stop regression, the Golden Ratio progresses only. Job 477 read the run whole: the pawn stands on the floor, the world clock runs, nothing is paused, and every bind stands in the source. The ancestor of this character stands in the repo under veil and reads plain: its code-built fallback holds the full pad map, left stick move, right stick look, A jump, B dodge, X interact, RT fire, LT aim, L3 sprint, and at its tail it hands the built context to DefaultMappingContext, and BeginPlay seats that context on the subsystem. In the merged file one link of that chain stands broken, and no read has yet printed the merged BeginPlay or the merged fallback tail, so this job prints both whole first, plus every AddMappingContext line and every DefaultMappingContext assignment in the file, the header context members, and the GameMode menu region lines 195 to 215. Then the repair, carried as a count gated base64 patcher: the built context is seated directly, by its own name BuiltMappingContext, at two points that cover both call orders, the tail of BuildFallbackInput itself and the tail of BeginPlay, each guarded so a context already seated is never doubled, each printing a PHI INPUT SEAT line into the game log when it fires. The patcher gates on the context member standing in the header and the cpp; if the seat already stands it writes nothing and the prints carry the ground for the next pass. On a clean patch one build runs the standing way and its Result line rides the verdict. Backups first, every variable carries the cf480 prefix.) ==='
$cf480cpp = 'D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp'
$cf480h = 'D:\VEIL-OMNI\Source\VEIL\Public\Character\VEILCharacter.h'
$cf480gm = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp'
$cf480cl = @(Get-Content $cf480cpp)
$cf480mc = @(Select-String -Path $cf480cpp -SimpleMatch 'AddMappingContext')
foreach ($cf480m in $cf480mc) { Write-Output ('MAPCTX ' + $cf480m.LineNumber + ' ' + $cf480m.Line.Trim()) }
Write-Output ('MAPCTX COUNT=' + $cf480mc.Count)
$cf480da = @(Select-String -Path $cf480cpp -Pattern 'DefaultMappingContext\s*=')
foreach ($cf480d in $cf480da) { Write-Output ('DMCASSIGN ' + $cf480d.LineNumber + ' ' + $cf480d.Line.Trim()) }
$cf480hl = @(Select-String -Path $cf480h -SimpleMatch 'MappingContext')
foreach ($cf480hh in $cf480hl) { Write-Output ('HD ' + $cf480hh.LineNumber + ' ' + $cf480hh.Line.Trim()) }
function Print-FuncBody {
  param($cf480lines, $cf480sig, $cf480tag)
  $cf480start = -1
  for ($cf480i = 0; $cf480i -lt $cf480lines.Count; $cf480i++) { if ($cf480lines[$cf480i].Contains($cf480sig)) { $cf480start = $cf480i; break } }
  if ($cf480start -lt 0) { Write-Output ($cf480tag + ' NOT FOUND'); return @() }
  $cf480body = @(); $cf480depth = 0; $cf480begun = $false
  for ($cf480j = $cf480start; $cf480j -lt $cf480lines.Count; $cf480j++) {
    $cf480ln = $cf480lines[$cf480j]
    $cf480body += $cf480ln
    Write-Output ($cf480tag + ' ' + ($cf480j + 1) + ' ' + $cf480ln)
    $cf480depth += ([regex]::Matches($cf480ln, '\{')).Count - ([regex]::Matches($cf480ln, '\}')).Count
    if ($cf480ln.Contains('{')) { $cf480begun = $true }
    if ($cf480begun -and $cf480depth -eq 0) { break }
    if ($cf480body.Count -gt 180) { Write-Output ($cf480tag + ' TRUNCATED'); break }
  }
  return $cf480body
}
$cf480bg = Print-FuncBody $cf480cl 'void AVEILCharacter::BeginPlay' 'BG'
$cf480fb = Print-FuncBody $cf480cl 'void AVEILCharacter::BuildFallbackInput' 'FB'
$cf480pad = 0; foreach ($cf480fl in $cf480fb) { $cf480pad += ([regex]::Matches($cf480fl, 'Gamepad_')).Count }
Write-Output ('FB PADKEYS=' + $cf480pad)
$cf480gml = @(Get-Content $cf480gm)
for ($cf480g = 194; $cf480g -lt 215 -and $cf480g -lt $cf480gml.Count; $cf480g++) { Write-Output ('GM ' + ($cf480g + 1) + ' ' + $cf480gml[$cf480g]) }
Copy-Item $cf480cpp ($cf480cpp + '.phi-backup-480') -Force
Copy-Item $cf480h ($cf480h + '.phi-backup-480') -Force
$cf480b64 = @'
aW1wb3J0IHN5cwoKY3BwX3BhdGggPSBzeXMuYXJndlsxXQpoX3BhdGggPSBzeXMuYXJndlsyXQpjcHAgPSBvcGVuKGNwcF9wYXRo
LCAiciIsIGVuY29kaW5nPSJ1dGYtOC1zaWciKS5yZWFkKCkKaGRyID0gb3BlbihoX3BhdGgsICJyIiwgZW5jb2Rpbmc9InV0Zi04
LXNpZyIpLnJlYWQoKQoKaF9jb3VudCA9IGhkci5jb3VudCgiQnVpbHRNYXBwaW5nQ29udGV4dCIpCmNwcF9jb3VudCA9IGNwcC5j
b3VudCgiQnVpbHRNYXBwaW5nQ29udGV4dCIpCnNlYXRlZCA9IGNwcC5jb3VudCgiQWRkTWFwcGluZ0NvbnRleHQoQnVpbHRNYXBw
aW5nQ29udGV4dCIpICsgY3BwLmNvdW50KCJBZGRNYXBwaW5nQ29udGV4dCggQnVpbHRNYXBwaW5nQ29udGV4dCIpCnByaW50KCJH
QVRFUyBoZWFkZXJCdWlsdD0iICsgc3RyKGhfY291bnQpICsgIiBjcHBCdWlsdD0iICsgc3RyKGNwcF9jb3VudCkgKyAiIGFscmVh
ZHlTZWF0ZWQ9IiArIHN0cihzZWF0ZWQpKQoKaWYgaF9jb3VudCA8IDEgb3IgY3BwX2NvdW50IDwgMToKICAgIHByaW50KCJQQVRD
SCBHQVRFIEZBSUwgY29udGV4dCBtZW1iZXIgbWlzc2luZyIpCiAgICBzeXMuZXhpdCgyKQppZiBzZWF0ZWQgPiAwOgogICAgcHJp
bnQoIlBBVENIIFNLSVAgc2VhdCBhbHJlYWR5IHByZXNlbnQiKQogICAgc3lzLmV4aXQoMCkKCmxpbmVzID0gY3BwLnNwbGl0KCJc
biIpCgpkZWYgZmluZF9mdW5jKGxpbmVzLCBzaWcpOgogICAgZm9yIGksIGxuIGluIGVudW1lcmF0ZShsaW5lcyk6CiAgICAgICAg
aWYgc2lnIGluIGxuOgogICAgICAgICAgICBkZXB0aCA9IDAKICAgICAgICAgICAgc3RhcnRlZCA9IEZhbHNlCiAgICAgICAgICAg
IGZvciBqIGluIHJhbmdlKGksIGxlbihsaW5lcykpOgogICAgICAgICAgICAgICAgZGVwdGggKz0gbGluZXNbal0uY291bnQoInsi
KSAtIGxpbmVzW2pdLmNvdW50KCJ9IikKICAgICAgICAgICAgICAgIGlmICJ7IiBpbiBsaW5lc1tqXToKICAgICAgICAgICAgICAg
ICAgICBzdGFydGVkID0gVHJ1ZQogICAgICAgICAgICAgICAgaWYgc3RhcnRlZCBhbmQgZGVwdGggPT0gMDoKICAgICAgICAgICAg
ICAgICAgICByZXR1cm4gaSwgagogICAgICAgICAgICByZXR1cm4gaSwgLTEKICAgIHJldHVybiAtMSwgLTEKCmZiX3N0YXJ0LCBm
Yl9lbmQgPSBmaW5kX2Z1bmMobGluZXMsICJ2b2lkIEFWRUlMQ2hhcmFjdGVyOjpCdWlsZEZhbGxiYWNrSW5wdXQoKSIpCmJnX3N0
YXJ0LCBiZ19lbmQgPSBmaW5kX2Z1bmMobGluZXMsICJ2b2lkIEFWRUlMQ2hhcmFjdGVyOjpCZWdpblBsYXkoKSIpCnByaW50KCJT
UEFOUyBmYWxsYmFjaz0iICsgc3RyKGZiX3N0YXJ0KSArICIuLiIgKyBzdHIoZmJfZW5kKSArICIgYmVnaW5wbGF5PSIgKyBzdHIo
Ymdfc3RhcnQpICsgIi4uIiArIHN0cihiZ19lbmQpKQppZiBmYl9lbmQgPCAwIG9yIGJnX2VuZCA8IDA6CiAgICBwcmludCgiUEFU
Q0ggR0FURSBGQUlMIGZ1bmN0aW9uIHNwYW4gbm90IGZvdW5kIikKICAgIHN5cy5leGl0KDMpCgpzZWF0X2ZiID0gWwogICAgIiAg
ICAvLyBQSEkgNDgwOiB0aGUgYnVpbHQgY29udGV4dCBpcyBzZWF0ZWQgb24gdGhlIGxvY2FsIHBsYXllciBzdWJzeXN0ZW0gaGVy
ZSwgYXQgaXRzIGJ1aWxkLCIsCiAgICAiICAgIC8vIHNvIHRoZSBwYWQgYW5kIHRoZSBrZXlzIHJvdXRlIGZyb20gdGhlIGhvdXIg
dGhlIGZhbGxiYWNrIHN0YW5kcy4iLAogICAgIiAgICBpZiAoQVBsYXllckNvbnRyb2xsZXIqIFBoaTQ4MFBDID0gQ2FzdDxBUGxh
eWVyQ29udHJvbGxlcj4oR2V0Q29udHJvbGxlcigpKSkiLAogICAgIiAgICB7IiwKICAgICIgICAgICAgIGlmIChVTG9jYWxQbGF5
ZXIqIFBoaTQ4MExQID0gUGhpNDgwUEMtPkdldExvY2FsUGxheWVyKCkpIiwKICAgICIgICAgICAgIHsiLAogICAgIiAgICAgICAg
ICAgIGlmIChVRW5oYW5jZWRJbnB1dExvY2FsUGxheWVyU3Vic3lzdGVtKiBQaGk0ODBTdWIgPSBVTG9jYWxQbGF5ZXI6OkdldFN1
YnN5c3RlbTxVRW5oYW5jZWRJbnB1dExvY2FsUGxheWVyU3Vic3lzdGVtPihQaGk0ODBMUCkpIiwKICAgICIgICAgICAgICAgICB7
IiwKICAgICIgICAgICAgICAgICAgICAgaWYgKEJ1aWx0TWFwcGluZ0NvbnRleHQgJiYgIVBoaTQ4MFN1Yi0+SGFzTWFwcGluZ0Nv
bnRleHQoQnVpbHRNYXBwaW5nQ29udGV4dCkpIHsgUGhpNDgwU3ViLT5BZGRNYXBwaW5nQ29udGV4dChCdWlsdE1hcHBpbmdDb250
ZXh0LCAwKTsgfSIsCiAgICAiICAgICAgICAgICAgICAgIFVFX0xPRyhMb2dUZW1wLCBEaXNwbGF5LCBURVhUKFwiUEhJIElOUFVU
IFNFQVQ6IGZhbGxiYWNrIGJ1aWxkXCIpKTsiLAogICAgIiAgICAgICAgICAgIH0iLAogICAgIiAgICAgICAgfSIsCiAgICAiICAg
IH0iLApdCgpzZWF0X2JnID0gWwogICAgIiAgICAvLyBQSEkgNDgwOiB0aGUgYnVpbHQgY29udGV4dCBpcyBzZWF0ZWQgYXQgQmVn
aW5QbGF5IGFzIHRoZSBzZWNvbmQgcm9hZC4iLAogICAgIiAgICBpZiAoQVBsYXllckNvbnRyb2xsZXIqIFBoaTQ4MFBDID0gQ2Fz
dDxBUGxheWVyQ29udHJvbGxlcj4oR2V0Q29udHJvbGxlcigpKSkiLAogICAgIiAgICB7IiwKICAgICIgICAgICAgIGlmIChVTG9j
YWxQbGF5ZXIqIFBoaTQ4MExQID0gUGhpNDgwUEMtPkdldExvY2FsUGxheWVyKCkpIiwKICAgICIgICAgICAgIHsiLAogICAgIiAg
ICAgICAgICAgIGlmIChVRW5oYW5jZWRJbnB1dExvY2FsUGxheWVyU3Vic3lzdGVtKiBQaGk0ODBTdWIgPSBVTG9jYWxQbGF5ZXI6
OkdldFN1YnN5c3RlbTxVRW5oYW5jZWRJbnB1dExvY2FsUGxheWVyU3Vic3lzdGVtPihQaGk0ODBMUCkpIiwKICAgICIgICAgICAg
ICAgICB7IiwKICAgICIgICAgICAgICAgICAgICAgaWYgKEJ1aWx0TWFwcGluZ0NvbnRleHQgJiYgIVBoaTQ4MFN1Yi0+SGFzTWFw
cGluZ0NvbnRleHQoQnVpbHRNYXBwaW5nQ29udGV4dCkpIHsgUGhpNDgwU3ViLT5BZGRNYXBwaW5nQ29udGV4dChCdWlsdE1hcHBp
bmdDb250ZXh0LCAwKTsgfSIsCiAgICAiICAgICAgICAgICAgICAgIFVFX0xPRyhMb2dUZW1wLCBEaXNwbGF5LCBURVhUKFwiUEhJ
IElOUFVUIFNFQVQ6IGJlZ2lucGxheVwiKSk7IiwKICAgICIgICAgICAgICAgICB9IiwKICAgICIgICAgICAgIH0iLAogICAgIiAg
ICB9IiwKXQoKIyBpbnNlcnQgaW4gZGVzY2VuZGluZyBwb3NpdGlvbiBvcmRlciBzbyBlYXJsaWVyIGluZGljZXMgc3RheSB2YWxp
ZCBlaXRoZXIgd2F5Cmluc2VydGlvbnMgPSBzb3J0ZWQoWyhmYl9lbmQsIHNlYXRfZmIpLCAoYmdfZW5kLCBzZWF0X2JnKV0sIGtl
eT1sYW1iZGEgdDogdFswXSwgcmV2ZXJzZT1UcnVlKQpmb3IgcG9zLCBibG9jayBpbiBpbnNlcnRpb25zOgogICAgbGluZXNbcG9z
OnBvc10gPSBibG9jawoKaW5jbHVkZV9hZGRlZCA9IDAKam9pbmVkID0gIlxuIi5qb2luKGxpbmVzKQppZiAiRW5oYW5jZWRJbnB1
dFN1YnN5c3RlbXMuaCIgbm90IGluIGpvaW5lZDoKICAgIGxhc3RfaW5jID0gLTEKICAgIGZvciBpIGluIHJhbmdlKG1pbig2MCwg
bGVuKGxpbmVzKSkpOgogICAgICAgIGlmIGxpbmVzW2ldLmxzdHJpcCgpLnN0YXJ0c3dpdGgoIiNpbmNsdWRlIik6CiAgICAgICAg
ICAgIGxhc3RfaW5jID0gaQogICAgaWYgbGFzdF9pbmMgPj0gMDoKICAgICAgICBsaW5lcy5pbnNlcnQobGFzdF9pbmMgKyAxLCAi
I2luY2x1ZGUgXCJFbmhhbmNlZElucHV0U3Vic3lzdGVtcy5oXCIiKQogICAgICAgIGluY2x1ZGVfYWRkZWQgPSAxCgpvdXQgPSAi
XG4iLmpvaW4obGluZXMpCm9wZW5zID0gb3V0LmNvdW50KCJ7IikgLSBjcHAuY291bnQoInsiKQpjbG9zZXMgPSBvdXQuY291bnQo
In0iKSAtIGNwcC5jb3VudCgifSIpCnByaW50KCJCUkFDRSBERUxUQSBvcGVuPSIgKyBzdHIob3BlbnMpICsgIiBjbG9zZT0iICsg
c3RyKGNsb3NlcykgKyAiIGluY2x1ZGU9IiArIHN0cihpbmNsdWRlX2FkZGVkKSkKaWYgb3BlbnMgIT0gY2xvc2VzOgogICAgcHJp
bnQoIlBBVENIIEdBVEUgRkFJTCBicmFjZXMiKQogICAgc3lzLmV4aXQoNCkKCndpdGggb3BlbihjcHBfcGF0aCwgInciLCBlbmNv
ZGluZz0idXRmLTgiKSBhcyBmOgogICAgZi53cml0ZShvdXQpCnByaW50KCJQQVRDSCBPSyBzZWF0PTIiKQo=
'@
$cf480dir = 'D:\VEIL-OMNI\Saved'
$cf480pypath = Join-Path $cf480dir 'patch480.py'
[IO.File]::WriteAllBytes($cf480pypath, [Convert]::FromBase64String($cf480b64))
$cf480pyExe = $null
foreach ($cf480cand in @('python', 'python3', 'py')) { $cf480gc = Get-Command $cf480cand -ErrorAction SilentlyContinue; if ($cf480gc) { $cf480pyExe = $cf480gc.Source; break } }
Write-Output ('PYTHON=' + $cf480pyExe)
if (-not $cf480pyExe) { Write-Output 'PHI CF480 VERDICT: CONTROLS FIX SKIP no python'; Write-Output 'JOB 480 DONE'; return }
$cf480out = @(& $cf480pyExe $cf480pypath $cf480cpp $cf480h 2>&1 | ForEach-Object { $_.ToString() })
foreach ($cf480line in $cf480out) { Write-Output ('PATCHER ' + $cf480line) }
$cf480joined = $cf480out -join ' '
if ($cf480joined -match 'PATCH SKIP') { Write-Output ('PHI CF480 VERDICT: CONTROLS FIX patch=SKIP seat already present padkeys=' + $cf480pad); Write-Output 'JOB 480 DONE'; return }
if (-not ($cf480joined -match 'PATCH OK')) { Write-Output ('PHI CF480 VERDICT: CONTROLS FIX patch=FAIL padkeys=' + $cf480pad); Write-Output 'JOB 480 DONE'; return }
$cf480buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$cf480uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$cf480logf = 'D:\VEIL-OMNI\Saved\build480.log'
& $cf480buildbat VEILEditor Win64 Development -Project=\"$cf480uproj\" -WaitMutex -NoHotReload *> \"$cf480logf\"
$cf480result = @(Select-String -Path $cf480logf -Pattern 'Result:' -ErrorAction SilentlyContinue | Select-Object -Last 1)
$cf480resLine = 'none'; foreach ($cf480rr in $cf480result) { $cf480resLine = $cf480rr.Line.Trim() }
Write-Output ('BUILD ' + $cf480resLine)
$cf480errs = @(Select-String -Path $cf480logf -Pattern 'erro[r] C' -ErrorAction SilentlyContinue | Select-Object -First 10)
foreach ($cf480ee in $cf480errs) { Write-Output ('ERR ' + $cf480ee.Line.Trim()) }
Write-Output ('PHI CF480 VERDICT: CONTROLS FIX patch=OK padkeys=' + $cf480pad + ' build=' + $cf480resLine)
Write-Output 'JOB 480 DONE'
```
