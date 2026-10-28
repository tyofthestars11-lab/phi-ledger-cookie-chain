<!-- PHI-DIRECT -->
```powershell
Write-Output '=== FRAMEWORK LOCK 484 - THE GAME READS AS ONE GAME (Ground: Tyree, 2026-10-28: the game is the whole framework locked at once, not single faults in linear time. This pass reads the framework whole and seats what stands unseated in the same motion. The character constructor region prints with its capsule and mesh lines, the movement and collision lines print wherever they stand, and the newest game log floor lines print as the standing proof: she stands, onGround equals 1, moveMode walking. The faction agent mesh region prints whole, and a gated patcher seats the census-verified Greystone body, the real 12.5 MB hero mesh at its printed path, on every skeletal mesh load the agent class carries, replacing whatever path stands there, then one clean build runs. The Countess material chain and the package stand behind the standing gate Tyree set: nothing packages until the game is 100 percent, and this pass does not touch that gate. Every variable carries the rs484 prefix.) ==='
$rs484fa = 'D:\VEIL-OMNI\Source\VEIL\Private\AI\VEILFactionAI.cpp'
$rs484ch = 'D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp'
$rs484fal = @(Get-Content $rs484fa)
for ($rs484i = 229; $rs484i -lt 270 -and $rs484i -lt $rs484fal.Count; $rs484i++) { Write-Output ('FA ' + ($rs484i + 1) + ' ' + $rs484fal[$rs484i]) }
$rs484chl = @(Get-Content $rs484ch)
for ($rs484j = 94; $rs484j -lt 166 -and $rs484j -lt $rs484chl.Count; $rs484j++) { Write-Output ('CTOR ' + ($rs484j + 1) + ' ' + $rs484chl[$rs484j]) }
$rs484frame = @(Select-String -Path $rs484ch -Pattern 'InitCapsuleSize|SetCollisionProfileName|SetMovementMode|MaxWalkSpeed|SetSimulatePhysics')
foreach ($rs484fr in $rs484frame) { Write-Output ('FRAME ' + $rs484fr.LineNumber + ' ' + $rs484fr.Line.Trim()) }
$rs484glog = 'D:\VEIL-OMNI\Saved\Logs\VEIL.log'
if (Test-Path $rs484glog) {
  $rs484fd = @(Select-String -Path $rs484glog -SimpleMatch 'PHI FLOOR DIAG' | Select-Object -Last 1)
  foreach ($rs484d in $rs484fd) { Write-Output ('PROOF ' + $rs484d.Line.Trim()) }
  $rs484tp = @(Select-String -Path $rs484glog -SimpleMatch 'PHI PC TICKPROOF' | Select-Object -Last 1)
  foreach ($rs484t in $rs484tp) { Write-Output ('PROOF ' + $rs484t.Line.Trim()) }
}
Copy-Item $rs484fa ($rs484fa + '.phi-backup-484') -Force
$rs484b64 = @'
aW1wb3J0IHJlCmltcG9ydCBzeXMKCnBhdGggPSBzeXMuYXJndlsxXQp0YXJnZXQgPSAiL0dhbWUvUGFyYWdvbkdyZXlzdG9uZS9D
aGFyYWN0ZXJzL0hlcm9lcy9HcmV5c3RvbmUvTWVzaGVzL0dyZXlzdG9uZS5HcmV5c3RvbmUiCnNyYyA9IG9wZW4ocGF0aCwgInIi
LCBlbmNvZGluZz0idXRmLTgtc2lnIikucmVhZCgpCmxpbmVzID0gc3JjLnNwbGl0KCJcbiIpCgpsb2FkcyA9IFtdCmZvciBpLCBs
biBpbiBlbnVtZXJhdGUobGluZXMpOgogICAgaWYgIkxvYWRPYmplY3Q8VVNrZWxldGFsTWVzaD4iIGluIGxuOgogICAgICAgIGZv
ciBqIGluIHJhbmdlKGksIG1pbihpICsgNCwgbGVuKGxpbmVzKSkpOgogICAgICAgICAgICBtID0gcmUuc2VhcmNoKHInVEVYVFwo
IigvR2FtZS9bXiJdKykiXCknLCBsaW5lc1tqXSkKICAgICAgICAgICAgaWYgbToKICAgICAgICAgICAgICAgIGxvYWRzLmFwcGVu
ZCgoaiwgbS5ncm91cCgxKSkpCiAgICAgICAgICAgICAgICBicmVhawoKcHJpbnQoIkxPQURTIGZvdW5kPSIgKyBzdHIobGVuKGxv
YWRzKSkpCmZvciBqLCBvbGQgaW4gbG9hZHM6CiAgICBwcmludCgiTE9BRCBsaW5lPSIgKyBzdHIoaiArIDEpICsgIiBvbGQ9IiAr
IG9sZCkKCmlmIGxlbihsb2FkcykgPT0gMDoKICAgIHByaW50KCJQQVRDSCBHQVRFIEZBSUwgbm8gc2tlbGV0YWwgbWVzaCBsb2Fk
IHBhdGggZm91bmQiKQogICAgc3lzLmV4aXQoMikKCmlmIGFsbChvbGQgPT0gdGFyZ2V0IGZvciBfLCBvbGQgaW4gbG9hZHMpOgog
ICAgcHJpbnQoIlBBVENIIFNLSVAgYWxyZWFkeSBzZWF0ZWQiKQogICAgc3lzLmV4aXQoMCkKCmZvciBqLCBvbGQgaW4gbG9hZHM6
CiAgICBpZiBvbGQgIT0gdGFyZ2V0OgogICAgICAgIGxpbmVzW2pdID0gbGluZXNbal0ucmVwbGFjZSgnVEVYVCgiJyArIG9sZCAr
ICciKScsICdURVhUKCInICsgdGFyZ2V0ICsgJyIpJykKCm91dCA9ICJcbiIuam9pbihsaW5lcykKdmVyaWZ5ID0gb3V0LmNvdW50
KHRhcmdldCkKcHJpbnQoIlZFUklGWSB0YXJnZXRQYXRocz0iICsgc3RyKHZlcmlmeSkpCmlmIHZlcmlmeSA8IDE6CiAgICBwcmlu
dCgiUEFUQ0ggR0FURSBGQUlMIHZlcmlmeSIpCiAgICBzeXMuZXhpdCgzKQoKd2l0aCBvcGVuKHBhdGgsICJ3IiwgZW5jb2Rpbmc9
InV0Zi04IikgYXMgZjoKICAgIGYud3JpdGUob3V0KQpwcmludCgiUEFUQ0ggT0sgbG9hZHM9IiArIHN0cihsZW4obG9hZHMpKSkK
'@
$rs484pypath = 'D:\VEIL-OMNI\Saved\patch484.py'
[IO.File]::WriteAllBytes($rs484pypath, [Convert]::FromBase64String($rs484b64))
$rs484pyExe = $null
foreach ($rs484cand in @('python', 'python3', 'py')) { $rs484gc = Get-Command $rs484cand -ErrorAction SilentlyContinue; if ($rs484gc) { $rs484pyExe = $rs484gc.Source; break } }
Write-Output ('PYTHON=' + $rs484pyExe)
if (-not $rs484pyExe) { Write-Output 'PHI RS484 VERDICT: FRAMEWORK LOCK SKIP no python'; Write-Output 'JOB 484 DONE'; return }
$rs484out = @(& $rs484pyExe $rs484pypath $rs484fa 2>&1 | ForEach-Object { $_.ToString() })
foreach ($rs484line in $rs484out) { Write-Output ('PATCHER ' + $rs484line) }
$rs484joined = $rs484out -join ' '
if ($rs484joined -match 'PATCH SKIP') { Write-Output 'PHI RS484 VERDICT: FRAMEWORK LOCK patch=SKIP already seated'; Write-Output 'JOB 484 DONE'; return }
if (-not ($rs484joined -match 'PATCH OK')) { Write-Output 'PHI RS484 VERDICT: FRAMEWORK LOCK patch=FAIL'; Write-Output 'JOB 484 DONE'; return }
$rs484buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$rs484uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$rs484logf = 'D:\VEIL-OMNI\Saved\build484.log'
& $rs484buildbat VEILEditor Win64 Development -Project="$rs484uproj" -WaitMutex -NoHotReload *> "$rs484logf"
$rs484result = @(Select-String -Path $rs484logf -Pattern 'Result:' -ErrorAction SilentlyContinue | Select-Object -Last 1)
$rs484resLine = 'none'; foreach ($rs484rr in $rs484result) { $rs484resLine = $rs484rr.Line.Trim() }
Write-Output ('BUILD ' + $rs484resLine)
$rs484errs = @(Select-String -Path $rs484logf -Pattern 'erro[r] C' -ErrorAction SilentlyContinue | Select-Object -First 10)
foreach ($rs484ee in $rs484errs) { Write-Output ('ERR ' + $rs484ee.Line.Trim()) }
Write-Output ('PHI RS484 VERDICT: FRAMEWORK LOCK patch=OK build=' + $rs484resLine)
Write-Output 'JOB 484 DONE'
```
