<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PROOF READ 498 - THE LOG VERDICT ON THE CONTROLS (Ground: the new build is in his hands and the controls still do not answer, and job 488 seated the pad proof inside the character tick for exactly this moment: every two seconds the game writes the raw gamepad stick and button values beside the mapping context seats, so the log itself names the broken link. This job reads the newest game log whole at the proof addresses - the pad proof lines, the faction body lines from job 492, the Warden body line, the monument line, the floor lines, and any texture budget lines - and it also lists the ready character assets standing inside the MetaHumanCharacter plugin content, since job 497 seated the plugin with 613 engine assets and zero project characters. Read only: nothing is written, nothing is patched; the fix seats from these prints in the same motion. Every variable carries the pr498 prefix.) ==='
$pr498proj = 'D:\VEIL-OMNI'
$pr498logs = Get-ChildItem (Join-Path $pr498proj 'Saved\Logs') -Filter '*.log' -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending
if ($pr498logs) {
  $pr498log = $pr498logs[0].FullName
  Write-Output ('LOG ' + $pr498log + ' bytes=' + $pr498logs[0].Length + ' written=' + $pr498logs[0].LastWriteTime)
  $pr498pad = @(Select-String -Path $pr498log -Pattern 'PAD PROOF')
  Write-Output ('PADPROOF COUNT=' + $pr498pad.Count)
  $pr498pad | Select-Object -Last 12 | ForEach-Object { Write-Output ('PAD ' + $_.Line.Trim()) }
  Select-String -Path $pr498log -Pattern 'PHI FACTION BODY' | Select-Object -Last 6 | ForEach-Object { Write-Output ('BODY ' + $_.Line.Trim()) }
  Select-String -Path $pr498log -Pattern 'PHI WARDEN BODY' | Select-Object -Last 3 | ForEach-Object { Write-Output ('WARDEN ' + $_.Line.Trim()) }
  Select-String -Path $pr498log -Pattern 'MONUMENT' | Select-Object -Last 3 | ForEach-Object { Write-Output ('MON ' + $_.Line.Trim()) }
  Select-String -Path $pr498log -Pattern 'over budget|Texture pool' | Select-Object -First 4 | ForEach-Object { Write-Output ('TEX ' + $_.Line.Trim()) }
  Select-String -Path $pr498log -Pattern 'PHI INPUT SEAT|PHI FLOOR DIAG' | Select-Object -Last 6 | ForEach-Object { Write-Output ('SEAT ' + $_.Line.Trim()) }
} else { Write-Output 'LOG NONE' }
$pr498mh = 'C:\Program Files\Epic Games\UE_5.8\Engine\Plugins\MetaHuman\MetaHumanCharacter\Content'
if (Test-Path $pr498mh) {
  $pr498assets = @(Get-ChildItem $pr498mh -Recurse -Filter '*.uasset' -ErrorAction SilentlyContinue)
  Write-Output ('MHCHAR ASSETS=' + $pr498assets.Count)
  $pr498assets | Select-Object -First 25 | ForEach-Object { Write-Output ('MHA ' + $_.FullName.Replace($pr498mh, '')) }
} else { Write-Output 'MHCHAR CONTENT MISSING' }
Write-Output 'PHI PR498 VERDICT: LOGREAD DONE'
Write-Output 'JOB 498 DONE'
```
