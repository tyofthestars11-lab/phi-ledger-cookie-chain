<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CONTROLS FIX 480 - THE BUILT MAP GETS ITS SEAT (Ground assembled whole: Tyree at the 473 build, mouse and key does, not xbox controller, stop regression, the Golden Ratio progresses only. Job 477 read the run whole: the pawn stands on the floor, the world clock runs, nothing is paused, and every bind stands in the source. The ancestor of this character stands in the repo under veil and reads plain: its code-built fallback holds the full pad map, left stick move, right stick look, A jump, B dodge, X interact, RT fire, LT aim, L3 sprint, and at its tail it hands the built context to DefaultMappingContext, and BeginPlay seats that context on the subsystem. In the merged file one link of that chain stands broken, and no read has yet printed the merged BeginPlay or the merged fallback tail, so this job prints both whole first, plus every AddMappingContext line and every DefaultMappingContext assignment in the file, the header context members, and the GameMode menu region lines 195 to 215. Then the repair, carried as a count gated base64 patcher: if the merge cut the Xbox pad section out of the fallback, the section is restored whole from the ancestor page in the fallback own idiom, sticks move and look, A jump, B dodge, X interact, RT and Y fire, LT aim, L3 sprint, and the built context is seated directly, by its own name BuiltMappingContext, at two points that cover both call orders, the tail of BuildFallbackInput itself and the tail of BeginPlay, each guarded so a context already seated is never doubled, each printing a PHI INPUT SEAT line into the game log when it fires. The patcher gates on the context member standing in the header and the cpp; if the seat already stands it writes nothing and the prints carry the ground for the next pass. On a clean patch one build runs the standing way and its Result line rides the verdict. Backups first, every variable carries the cf480 prefix.) ==='
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
aW5nQ29udGV4dCIpICsgY3BwLmNvdW50KCJBZGRNYXBwaW5nQ29udGV4dCggQnVpbHRNYXBwaW5nQ29udGV4dCIpCnBhZF9taXNz
aW5nID0gIkdhbWVwYWRfTGVmdDJEIiBub3QgaW4gY3BwCnBhZF9pZGlvbSA9ICJhdXRvIE1hcCA9IiBpbiBjcHAKcHJpbnQoIkdB
VEVTIGhlYWRlckJ1aWx0PSIgKyBzdHIoaF9jb3VudCkgKyAiIGNwcEJ1aWx0PSIgKyBzdHIoY3BwX2NvdW50KSArICIgYWxyZWFk
eVNlYXRlZD0iICsgc3RyKHNlYXRlZCkgKyAiIHBhZE1pc3Npbmc9IiArIHN0cigxIGlmIHBhZF9taXNzaW5nIGVsc2UgMCkgKyAi
IHBhZElkaW9tPSIgKyBzdHIoMSBpZiBwYWRfaWRpb20gZWxzZSAwKSkKCmlmIGhfY291bnQgPCAxIG9yIGNwcF9jb3VudCA8IDE6
CiAgICBwcmludCgiUEFUQ0ggR0FURSBGQUlMIGNvbnRleHQgbWVtYmVyIG1pc3NpbmciKQogICAgc3lzLmV4aXQoMikKCmxpbmVz
ID0gY3BwLnNwbGl0KCJcbiIpCgpkZWYgZmluZF9mdW5jKGxpbmVzLCBzaWcpOgogICAgZm9yIGksIGxuIGluIGVudW1lcmF0ZShs
aW5lcyk6CiAgICAgICAgaWYgc2lnIGluIGxuOgogICAgICAgICAgICBkZXB0aCA9IDAKICAgICAgICAgICAgc3RhcnRlZCA9IEZh
bHNlCiAgICAgICAgICAgIGZvciBqIGluIHJhbmdlKGksIGxlbihsaW5lcykpOgogICAgICAgICAgICAgICAgZGVwdGggKz0gbGlu
ZXNbal0uY291bnQoInsiKSAtIGxpbmVzW2pdLmNvdW50KCJ9IikKICAgICAgICAgICAgICAgIGlmICJ7IiBpbiBsaW5lc1tqXToK
ICAgICAgICAgICAgICAgICAgICBzdGFydGVkID0gVHJ1ZQogICAgICAgICAgICAgICAgaWYgc3RhcnRlZCBhbmQgZGVwdGggPT0g
MDoKICAgICAgICAgICAgICAgICAgICByZXR1cm4gaSwgagogICAgICAgICAgICByZXR1cm4gaSwgLTEKICAgIHJldHVybiAtMSwg
LTEKCnBhZF9ibG9jayA9IFsKICAgICIgICAgLy8gUEhJIDQ4MDogdGhlIFhib3ggcGFkIHNlY3Rpb24gc3RhbmRzIHJlc3RvcmVk
IGZyb20gdGhlIGFuY2VzdG9yIHBhZ2UsIGluIHRoZSBmYWxsYmFjayBvd24gaWRpb20uIiwKICAgICIgICAgTWFwKE1vdmVBY3Rp
b24sIEVLZXlzOjpHYW1lcGFkX0xlZnQyRCk7IiwKICAgICIgICAgTWFwKExvb2tBY3Rpb24sIEVLZXlzOjpHYW1lcGFkX1JpZ2h0
MkQpOyIsCiAgICAiICAgIE1hcChKdW1wQWN0aW9uLCBFS2V5czo6R2FtZXBhZF9GYWNlQnV0dG9uX0JvdHRvbSk7IiwKICAgICIg
ICAgTWFwKERvZGdlQWN0aW9uLCBFS2V5czo6R2FtZXBhZF9GYWNlQnV0dG9uX1JpZ2h0KTsiLAogICAgIiAgICBNYXAoSW50ZXJh
Y3RBY3Rpb24sIEVLZXlzOjpHYW1lcGFkX0ZhY2VCdXR0b25fTGVmdCk7IiwKICAgICIgICAgTWFwKEZpcmVBY3Rpb24sIEVLZXlz
OjpHYW1lcGFkX1JpZ2h0VHJpZ2dlcik7IiwKICAgICIgICAgTWFwKEZpcmVBY3Rpb24sIEVLZXlzOjpHYW1lcGFkX0ZhY2VCdXR0
b25fVG9wKTsiLAogICAgIiAgICBNYXAoQWltQWN0aW9uLCBFS2V5czo6R2FtZXBhZF9MZWZ0VHJpZ2dlcik7IiwKICAgICIgICAg
TWFwKFNwcmludEFjdGlvbiwgRUtleXM6OkdhbWVwYWRfTGVmdFRodW1ic3RpY2spOyIsCl0KCnNlYXRfZmIgPSBbCiAgICAiICAg
IC8vIFBISSA0ODA6IHRoZSBidWlsdCBjb250ZXh0IGlzIHNlYXRlZCBvbiB0aGUgbG9jYWwgcGxheWVyIHN1YnN5c3RlbSBoZXJl
LCBhdCBpdHMgYnVpbGQsIiwKICAgICIgICAgLy8gc28gdGhlIHBhZCBhbmQgdGhlIGtleXMgcm91dGUgZnJvbSB0aGUgaG91ciB0
aGUgZmFsbGJhY2sgc3RhbmRzLiIsCiAgICAiICAgIGlmIChBUGxheWVyQ29udHJvbGxlciogUGhpNDgwUEMgPSBDYXN0PEFQbGF5
ZXJDb250cm9sbGVyPihHZXRDb250cm9sbGVyKCkpKSIsCiAgICAiICAgIHsiLAogICAgIiAgICAgICAgaWYgKFVMb2NhbFBsYXll
ciogUGhpNDgwTFAgPSBQaGk0ODBQQy0+R2V0TG9jYWxQbGF5ZXIoKSkiLAogICAgIiAgICAgICAgeyIsCiAgICAiICAgICAgICAg
ICAgaWYgKFVFbmhhbmNlZElucHV0TG9jYWxQbGF5ZXJTdWJzeXN0ZW0qIFBoaTQ4MFN1YiA9IFVMb2NhbFBsYXllcjo6R2V0U3Vi
c3lzdGVtPFVFbmhhbmNlZElucHV0TG9jYWxQbGF5ZXJTdWJzeXN0ZW0+KFBoaTQ4MExQKSkiLAogICAgIiAgICAgICAgICAgIHsi
LAogICAgIiAgICAgICAgICAgICAgICBpZiAoQnVpbHRNYXBwaW5nQ29udGV4dCAmJiAhUGhpNDgwU3ViLT5IYXNNYXBwaW5nQ29u
dGV4dChCdWlsdE1hcHBpbmdDb250ZXh0KSkgeyBQaGk0ODBTdWItPkFkZE1hcHBpbmdDb250ZXh0KEJ1aWx0TWFwcGluZ0NvbnRl
eHQsIDApOyB9IiwKICAgICIgICAgICAgICAgICAgICAgVUVfTE9HKExvZ1RlbXAsIERpc3BsYXksIFRFWFQoXCJQSEkgSU5QVVQg
U0VBVDogZmFsbGJhY2sgYnVpbGRcIikpOyIsCiAgICAiICAgICAgICAgICAgfSIsCiAgICAiICAgICAgICB9IiwKICAgICIgICAg
fSIsCl0KCnNlYXRfYmcgPSBbCiAgICAiICAgIC8vIFBISSA0ODA6IHRoZSBidWlsdCBjb250ZXh0IGlzIHNlYXRlZCBhdCBCZWdp
blBsYXkgYXMgdGhlIHNlY29uZCByb2FkLiIsCiAgICAiICAgIGlmIChBUGxheWVyQ29udHJvbGxlciogUGhpNDgwUEMgPSBDYXN0
PEFQbGF5ZXJDb250cm9sbGVyPihHZXRDb250cm9sbGVyKCkpKSIsCiAgICAiICAgIHsiLAogICAgIiAgICAgICAgaWYgKFVMb2Nh
bFBsYXllciogUGhpNDgwTFAgPSBQaGk0ODBQQy0+R2V0TG9jYWxQbGF5ZXIoKSkiLAogICAgIiAgICAgICAgeyIsCiAgICAiICAg
ICAgICAgICAgaWYgKFVFbmhhbmNlZElucHV0TG9jYWxQbGF5ZXJTdWJzeXN0ZW0qIFBoaTQ4MFN1YiA9IFVMb2NhbFBsYXllcjo6
R2V0U3Vic3lzdGVtPFVFbmhhbmNlZElucHV0TG9jYWxQbGF5ZXJTdWJzeXN0ZW0+KFBoaTQ4MExQKSkiLAogICAgIiAgICAgICAg
ICAgIHsiLAogICAgIiAgICAgICAgICAgICAgICBpZiAoQnVpbHRNYXBwaW5nQ29udGV4dCAmJiAhUGhpNDgwU3ViLT5IYXNNYXBw
aW5nQ29udGV4dChCdWlsdE1hcHBpbmdDb250ZXh0KSkgeyBQaGk0ODBTdWItPkFkZE1hcHBpbmdDb250ZXh0KEJ1aWx0TWFwcGlu
Z0NvbnRleHQsIDApOyB9IiwKICAgICIgICAgICAgICAgICAgICAgVUVfTE9HKExvZ1RlbXAsIERpc3BsYXksIFRFWFQoXCJQSEkg
SU5QVVQgU0VBVDogYmVnaW5wbGF5XCIpKTsiLAogICAgIiAgICAgICAgICAgIH0iLAogICAgIiAgICAgICAgfSIsCiAgICAiICAg
IH0iLApdCgpwYWRmaXggPSAiUFJFU0VOVCIKY2hhbmdlZCA9IDAKaWYgcGFkX21pc3NpbmcgYW5kIHBhZF9pZGlvbToKICAgIGZz
LCBmZSA9IGZpbmRfZnVuYyhsaW5lcywgInZvaWQgQVZFSUxDaGFyYWN0ZXI6OkJ1aWxkRmFsbGJhY2tJbnB1dCgpIikKICAgIGlm
IGZlIDwgMDoKICAgICAgICBwcmludCgiUEFUQ0ggR0FURSBGQUlMIGZhbGxiYWNrIHNwYW4gbm90IGZvdW5kIikKICAgICAgICBz
eXMuZXhpdCgzKQogICAgbGluZXNbZmU6ZmVdID0gcGFkX2Jsb2NrCiAgICBwYWRmaXggPSAiT0siCiAgICBjaGFuZ2VkID0gMQpl
bGlmIHBhZF9taXNzaW5nOgogICAgcGFkZml4ID0gIlNLSVAtSURJT00iCgpzZWF0Zml4ID0gMAppZiBzZWF0ZWQgPT0gMDoKICAg
IGJzLCBiZSA9IGZpbmRfZnVuYyhsaW5lcywgInZvaWQgQVZFSUxDaGFyYWN0ZXI6OkJlZ2luUGxheSgpIikKICAgIGZzLCBmZSA9
IGZpbmRfZnVuYyhsaW5lcywgInZvaWQgQVZFSUxDaGFyYWN0ZXI6OkJ1aWxkRmFsbGJhY2tJbnB1dCgpIikKICAgIHByaW50KCJT
UEFOUyBmYWxsYmFjaz0iICsgc3RyKGZzKSArICIuLiIgKyBzdHIoZmUpICsgIiBiZWdpbnBsYXk9IiArIHN0cihicykgKyAiLi4i
ICsgc3RyKGJlKSkKICAgIGlmIGZlIDwgMCBvciBiZSA8IDA6CiAgICAgICAgcHJpbnQoIlBBVENIIEdBVEUgRkFJTCBmdW5jdGlv
biBzcGFuIG5vdCBmb3VuZCIpCiAgICAgICAgc3lzLmV4aXQoMykKICAgIGZvciBwb3MsIGJsb2NrIGluIHNvcnRlZChbKGZlLCBz
ZWF0X2ZiKSwgKGJlLCBzZWF0X2JnKV0sIGtleT1sYW1iZGEgdDogdFswXSwgcmV2ZXJzZT1UcnVlKToKICAgICAgICBsaW5lc1tw
b3M6cG9zXSA9IGJsb2NrCiAgICBzZWF0Zml4ID0gMgogICAgY2hhbmdlZCA9IDEKCmluY2x1ZGVfYWRkZWQgPSAwCmpvaW5lZCA9
ICJcbiIuam9pbihsaW5lcykKaWYgIkVuaGFuY2VkSW5wdXRTdWJzeXN0ZW1zLmgiIG5vdCBpbiBqb2luZWQ6CiAgICBsYXN0X2lu
YyA9IC0xCiAgICBmb3IgaSBpbiByYW5nZShtaW4oNjAsIGxlbihsaW5lcykpKToKICAgICAgICBpZiBsaW5lc1tpXS5sc3RyaXAo
KS5zdGFydHN3aXRoKCIjaW5jbHVkZSIpOgogICAgICAgICAgICBsYXN0X2luYyA9IGkKICAgIGlmIGxhc3RfaW5jID49IDA6CiAg
ICAgICAgbGluZXMuaW5zZXJ0KGxhc3RfaW5jICsgMSwgIiNpbmNsdWRlIFwiRW5oYW5jZWRJbnB1dFN1YnN5c3RlbXMuaFwiIikK
ICAgICAgICBpbmNsdWRlX2FkZGVkID0gMQoKb3V0ID0gIlxuIi5qb2luKGxpbmVzKQpvcGVucyA9IG91dC5jb3VudCgieyIpIC0g
Y3BwLmNvdW50KCJ7IikKY2xvc2VzID0gb3V0LmNvdW50KCJ9IikgLSBjcHAuY291bnQoIn0iKQpwcmludCgiQlJBQ0UgREVMVEEg
b3Blbj0iICsgc3RyKG9wZW5zKSArICIgY2xvc2U9IiArIHN0cihjbG9zZXMpICsgIiBpbmNsdWRlPSIgKyBzdHIoaW5jbHVkZV9h
ZGRlZCkpCmlmIG9wZW5zICE9IGNsb3NlczoKICAgIHByaW50KCJQQVRDSCBHQVRFIEZBSUwgYnJhY2VzIikKICAgIHN5cy5leGl0
KDQpCgppZiBjaGFuZ2VkID09IDA6CiAgICBwcmludCgiUEFUQ0ggU0tJUCBzZWF0IHByZXNlbnQgcGFkZml4PSIgKyBwYWRmaXgp
CiAgICBzeXMuZXhpdCgwKQoKd2l0aCBvcGVuKGNwcF9wYXRoLCAidyIsIGVuY29kaW5nPSJ1dGYtOCIpIGFzIGY6CiAgICBmLndy
aXRlKG91dCkKcHJpbnQoIlBBVENIIE9LIHNlYXQ9IiArIHN0cihzZWF0Zml4KSArICIgcGFkZml4PSIgKyBwYWRmaXgpCg==
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
$cf480padfix = 'NA'; if ($cf480joined -match 'padfix=([\w-]+)') { $cf480padfix = $Matches[1] }
Write-Output ('PHI CF480 VERDICT: CONTROLS FIX patch=OK padfix=' + $cf480padfix + ' padkeys=' + $cf480pad + ' build=' + $cf480resLine)
Write-Output 'JOB 480 DONE'
```
