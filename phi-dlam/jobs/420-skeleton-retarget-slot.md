<!-- PHI-DIRECT -->
```powershell
Write-Output '=== SKELETON RETARGET SLOT 420 - THE SKELETON SIDE OF THE REFERENCE TO THE LEGACY RIG ASSET (Ground from job 419, read whole: Paragon_Proto_Retarget.uasset, a UE 4.19 era asset whose class Rig does not exist in this engine build, stands REFERENCED with exactly one referencer, /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/S_Countess_Skeleton, the Countess own skeleton asset at 44707 bytes in the same Meshes folder, with source refs zero and config refs zero, so the skeleton itself carries the reference to the unloadable legacy rig. This job reads the skeleton side of that reference and no other road, so the fix for the missing Rig class is authored against the exact slot that carries it. One, print the skeleton file size and SHA-256. Two, the byte census prints every ASCII string of length four or more carrying Rig, Retarget, Proto, or /Script/ with its byte offset, uncapped, and the slot name the skeleton uses for this reference stands among them. Three, the registry dependency read prints the dependency type the registry records between S_Countess_Skeleton and Paragon_Proto_Retarget, probed with hard-only and soft-only option sets beside the full set, because a hard reference loads with the skeleton while a soft one loads on demand. Four, load S_Countess_Skeleton in a pythonscript commandlet, print the loaded class name, and print every line of the load log carrying Retarget, Rig, Failed, Unable, or Missing, the skeleton load being where the warning fires. Five, the verdict in one line: SKELETON REFERENCE with the slot string named and the dependency type stated, or REFERENCE FORM UNREADABLE with the counts. Read-only throughout: no edits, no moves, and every variable carries the skl420 prefix under the standing ban on automatic variable names.) ==='

$skl420Waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $skl420Waited -lt 10) { Start-Sleep -Seconds 10; $skl420Waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'PHI SKL420 NAMED HOLD: EDITOR STILL STANDING AFTER THE 100 SECOND IN-JOB WAIT - no commandlet launched into the contention'; Write-Output 'JOB 420 STOPPED'; return }
Write-Output 'PHI SKL420 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road'
$skl420Base = 'D:\VEIL-OMNI'
$skl420Uproj = "$skl420Base\VEIL.uproject"
$skl420CmdExe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$skl420MeshFolder = "$skl420Base\Content\ParagonCountess\Characters\Heroes\Countess\Meshes"
$skl420Target = Join-Path $skl420MeshFolder 'S_Countess_Skeleton.uasset'
if (-not (Test-Path $skl420Target)) {
  $skl420Hit = Get-ChildItem (Join-Path $skl420Base 'Content') -Recurse -Filter 'S_Countess_Skeleton.uasset' -File -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($skl420Hit) { $skl420Target = $skl420Hit.FullName } else { $skl420Target = '' }
}
Write-Output '--- SECTION 1: RESOLVE, SIZE, SHA-256 ---'
if ($skl420Target -eq '') {
  Write-Output 'SKELETON FILE NOT FOUND UNDER THE MERGED BASE CONTENT TREE'
  Write-Output 'PHI SKL420 VERDICT: REFERENCE FORM UNREADABLE family strings=0 script strings=0 dep=UNRESOLVED'
  Write-Output 'JOB 420 DONE'
  return
}
Write-Output ("PHI SKL420 TARGET FILE: " + $skl420Target)
$skl420Item = Get-Item $skl420Target
Write-Output ("PHI SKL420 SIZE BYTES=" + $skl420Item.Length)
$skl420Hash = (Get-FileHash $skl420Target -Algorithm SHA256).Hash.ToLower()
Write-Output ("PHI SKL420 SHA256: " + $skl420Hash)
Write-Output '--- SECTION 2: BYTE CENSUS - RIG RETARGET PROTO AND SCRIPT STRINGS WITH OFFSETS UNCAPPED ---'
$skl420Bytes = [System.IO.File]::ReadAllBytes($skl420Target)
$skl420Runs = @()
$skl420Start = -1
for ($skl420Idx = 0; $skl420Idx -lt $skl420Bytes.Length; $skl420Idx++) {
  $skl420Byte = $skl420Bytes[$skl420Idx]
  if ($skl420Byte -ge 32 -and $skl420Byte -le 126) {
    if ($skl420Start -lt 0) { $skl420Start = $skl420Idx }
  } else {
    if ($skl420Start -ge 0 -and ($skl420Idx - $skl420Start) -ge 4) {
      $skl420Text = [System.Text.Encoding]::ASCII.GetString($skl420Bytes, $skl420Start, $skl420Idx - $skl420Start)
      $skl420Runs += [PSCustomObject]@{ Offset = $skl420Start; Text = $skl420Text }
    }
    $skl420Start = -1
  }
}
if ($skl420Start -ge 0 -and ($skl420Bytes.Length - $skl420Start) -ge 4) {
  $skl420Text = [System.Text.Encoding]::ASCII.GetString($skl420Bytes, $skl420Start, $skl420Bytes.Length - $skl420Start)
  $skl420Runs += [PSCustomObject]@{ Offset = $skl420Start; Text = $skl420Text }
}
Write-Output ("PHI SKL420 ASCII RUNS LEN4PLUS COUNT=" + $skl420Runs.Count)
$skl420Tokens = @('Rig', 'Retarget', 'Proto', '/Script/')
$skl420Family = @()
$skl420ScriptCount = 0
foreach ($skl420Run in $skl420Runs) {
  $skl420IsFamily = 0
  foreach ($skl420Token in $skl420Tokens) { if ($skl420Run.Text.Contains($skl420Token)) { $skl420IsFamily = 1; break } }
  if ($skl420Run.Text.Contains('/Script/')) { $skl420ScriptCount++ }
  if ($skl420IsFamily -eq 1) { $skl420Family += $skl420Run }
}
Write-Output ("PHI SKL420 FAMILY STRINGS COUNT=" + $skl420Family.Count)
Write-Output ("PHI SKL420 SCRIPT STRINGS COUNT=" + $skl420ScriptCount)
foreach ($skl420Run in $skl420Family) { Write-Output ("FAMILY STRING offset=" + $skl420Run.Offset + " : " + $skl420Run.Text) }
Write-Output 'SLOT RULE: the slot candidate is the first family string in file order that carries Rig with no path separator and no Paragon text; if none stands, the first family string carrying the full Paragon_Proto_Retarget name stands as the slot text'
$skl420Slot = ''
$skl420SlotOffset = -1
foreach ($skl420Run in $skl420Family) {
  if (-not $skl420Run.Text.Contains('Rig')) { continue }
  if ($skl420Run.Text.Contains('/')) { continue }
  if ($skl420Run.Text.Contains('\')) { continue }
  if ($skl420Run.Text.Contains('Paragon')) { continue }
  $skl420Slot = $skl420Run.Text
  $skl420SlotOffset = $skl420Run.Offset
  break
}
if ($skl420Slot -eq '') {
  foreach ($skl420Run in $skl420Family) {
    if ($skl420Run.Text.Contains('Paragon_Proto_Retarget')) { $skl420Slot = $skl420Run.Text; $skl420SlotOffset = $skl420Run.Offset; break }
  }
}
if ($skl420Slot -ne '') { Write-Output ("PHI SKL420 SLOT CANDIDATE: " + $skl420Slot + " offset=" + $skl420SlotOffset) } else { Write-Output 'PHI SKL420 SLOT CANDIDATE: NONE' }
Write-Output '--- SECTION 3: REGISTRY DEPENDENCY FORM ---'
$skl420DepPy = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('aW1wb3J0IHVucmVhbAoKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHN0cihzKSArICdcbicpCgpTS0VMID0gJy9HYW1lL1BhcmFnb25Db3VudGVzcy9DaGFyYWN0ZXJzL0hlcm9lcy9Db3VudGVzcy9NZXNoZXMvU19Db3VudGVzc19Ta2VsZXRvbicKVEdUTkFNRSA9ICdQYXJhZ29uX1Byb3RvX1JldGFyZ2V0JwoKZGVmIGRlcHNfd2l0aChyZWdpc3RyeSwgaGFyZCwgc29mdCk6CiAgICB0cnk6CiAgICAgICAgb3B0cyA9IHVucmVhbC5Bc3NldFJlZ2lzdHJ5RGVwZW5kZW5jeU9wdGlvbnMoaW5jbHVkZV9oYXJkX3BhY2thZ2VfcmVmZXJlbmNlcz1oYXJkLCBpbmNsdWRlX3NvZnRfcGFja2FnZV9yZWZlcmVuY2VzPXNvZnQsIGluY2x1ZGVfc2VhcmNoYWJsZV9uYW1lcz1GYWxzZSwgaW5jbHVkZV9oYXJkX21hbmFnZW1lbnRfcmVmZXJlbmNlcz1GYWxzZSwgaW5jbHVkZV9zb2Z0X21hbmFnZW1lbnRfcmVmZXJlbmNlcz1GYWxzZSkKICAgICAgICByZXMgPSByZWdpc3RyeS5nZXRfZGVwZW5kZW5jaWVzKFNLRUwsIG9wdHMpCiAgICBleGNlcHQgRXhjZXB0aW9uOgogICAgICAgIHJlcyA9IE5vbmUKICAgIGlmIHJlcyBpcyBOb25lOgogICAgICAgIHJldHVybiBOb25lCiAgICBuYW1lcyA9IFtdCiAgICBmb3IgZCBpbiByZXM6CiAgICAgICAgdHJ5OgogICAgICAgICAgICBuYW1lcy5hcHBlbmQoc3RyKGQpKQogICAgICAgIGV4Y2VwdCBFeGNlcHRpb246CiAgICAgICAgICAgIHBhc3MKICAgIHJldHVybiBuYW1lcwoKcmVnaXN0cnkgPSBOb25lCnRyeToKICAgIHJlZ2lzdHJ5ID0gdW5yZWFsLkFzc2V0UmVnaXN0cnlIZWxwZXJzLmdldF9hc3NldF9yZWdpc3RyeSgpCmV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgIHcoJ1BISSBTS0w0MjAgUkVHSVNUUlkgTk9URTogcmVnaXN0cnkgaGFuZGxlIHJlZnVzZWQ6ICcgKyBzdHIoZSkpCgppZiByZWdpc3RyeSBpcyBOb25lOgogICAgdygnUEhJIFNLTDQyMCBERVAgVU5SRVNPTFZFRCcpCmVsc2U6CiAgICBhbGxfZGVwcyA9IGRlcHNfd2l0aChyZWdpc3RyeSwgVHJ1ZSwgVHJ1ZSkKICAgIGlmIGFsbF9kZXBzIGlzIE5vbmU6CiAgICAgICAgdHJ5OgogICAgICAgICAgICBwbGFpbiA9IHJlZ2lzdHJ5LmdldF9kZXBlbmRlbmNpZXMoU0tFTCkKICAgICAgICAgICAgYWxsX2RlcHMgPSBbc3RyKGQpIGZvciBkIGluIHBsYWluXSBpZiBwbGFpbiBpcyBub3QgTm9uZSBlbHNlIE5vbmUKICAgICAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgICAgIHcoJ1BISSBTS0w0MjAgUkVHSVNUUlkgTk9URTogcGxhaW4gZm9ybSByZWZ1c2VkOiAnICsgc3RyKGUpKQogICAgICAgICAgICBhbGxfZGVwcyA9IE5vbmUKICAgIGhhcmRfZGVwcyA9IGRlcHNfd2l0aChyZWdpc3RyeSwgVHJ1ZSwgRmFsc2UpCiAgICBzb2Z0X2RlcHMgPSBkZXBzX3dpdGgocmVnaXN0cnksIEZhbHNlLCBUcnVlKQogICAgaWYgYWxsX2RlcHMgaXMgTm9uZToKICAgICAgICB3KCdQSEkgU0tMNDIwIERFUCBVTlJFU09MVkVEJykKICAgIGVsc2U6CiAgICAgICAgdygnUEhJIFNLTDQyMCBERVAgQUxMIENPVU5UPScgKyBzdHIobGVuKGFsbF9kZXBzKSkpCiAgICAgICAgZm9yIGQgaW4gc29ydGVkKHNldChhbGxfZGVwcykpOgogICAgICAgICAgICB3KCdQSEkgU0tMNDIwIERFUDogJyArIGQpCiAgICAgICAgaW5fYWxsID0gMSBpZiBhbnkoVEdUTkFNRSBpbiBkIGZvciBkIGluIGFsbF9kZXBzKSBlbHNlIDAKICAgICAgICBpbl9oYXJkID0gMAogICAgICAgIGlmIGhhcmRfZGVwcyBpcyBub3QgTm9uZToKICAgICAgICAgICAgaW5faGFyZCA9IDEgaWYgYW55KFRHVE5BTUUgaW4gZCBmb3IgZCBpbiBoYXJkX2RlcHMpIGVsc2UgMAogICAgICAgIGluX3NvZnQgPSAwCiAgICAgICAgaWYgc29mdF9kZXBzIGlzIG5vdCBOb25lOgogICAgICAgICAgICBpbl9zb2Z0ID0gMSBpZiBhbnkoVEdUTkFNRSBpbiBkIGZvciBkIGluIHNvZnRfZGVwcykgZWxzZSAwCiAgICAgICAgdygnUEhJIFNLTDQyMCBERVAgSU4gQUxMPScgKyBzdHIoaW5fYWxsKSkKICAgICAgICB3KCdQSEkgU0tMNDIwIERFUCBIQVJEIEhJVD0nICsgc3RyKGluX2hhcmQpKQogICAgICAgIHcoJ1BISSBTS0w0MjAgREVQIFNPRlQgSElUPScgKyBzdHIoaW5fc29mdCkpCncoJ1BISSBTS0w0MjAgUkVHSVNUUlkgUkVBRCBDT01QTEVURScpCm91dC5jbG9zZSgpCg=='))
$skl420DepOut = "$skl420Base\Saved\phi_skl420_dep.txt"
$skl420DepPy = $skl420DepPy.Replace('OUTFILE', "'$skl420DepOut'")
Set-Content "$skl420Base\Saved\phi_skl420_dep.py" -Value $skl420DepPy -Encoding UTF8
Remove-Item $skl420DepOut -ErrorAction SilentlyContinue
& $skl420CmdExe $skl420Uproj -run=pythonscript -script="$skl420Base\Saved\phi_skl420_dep.py" -unattended -nopause -nosplash *> "$skl420Base\Saved\skl420_dep.log"
$skl420DepType = 'UNRESOLVED'
$skl420DepInAll = -1
$skl420DepHard = -1
$skl420DepSoft = -1
if (Test-Path $skl420DepOut) {
  $skl420DepLines = @(Get-Content $skl420DepOut)
  $skl420DepLines | Write-Output
  $skl420LineAll = $skl420DepLines | Where-Object { $_ -like 'PHI SKL420 DEP IN ALL=*' } | Select-Object -First 1
  if ($skl420LineAll) { $skl420DepInAll = [int]($skl420LineAll.Substring($skl420LineAll.IndexOf('=') + 1).Trim()) }
  $skl420LineHard = $skl420DepLines | Where-Object { $_ -like 'PHI SKL420 DEP HARD HIT=*' } | Select-Object -First 1
  if ($skl420LineHard) { $skl420DepHard = [int]($skl420LineHard.Substring($skl420LineHard.IndexOf('=') + 1).Trim()) }
  $skl420LineSoft = $skl420DepLines | Where-Object { $_ -like 'PHI SKL420 DEP SOFT HIT=*' } | Select-Object -First 1
  if ($skl420LineSoft) { $skl420DepSoft = [int]($skl420LineSoft.Substring($skl420LineSoft.IndexOf('=') + 1).Trim()) }
  if ($skl420DepInAll -eq 0) { $skl420DepType = 'NOT RECORDED' }
  elseif ($skl420DepHard -eq 1 -and $skl420DepSoft -eq 1) { $skl420DepType = 'HARD AND SOFT' }
  elseif ($skl420DepHard -eq 1) { $skl420DepType = 'HARD' }
  elseif ($skl420DepSoft -eq 1) { $skl420DepType = 'SOFT' }
  elseif ($skl420DepInAll -eq 1) { $skl420DepType = 'OTHER FLAGS' }
} else {
  Write-Output 'NO SKL420 DEP OUTPUT FILE'
  Select-String -Path "$skl420Base\Saved\skl420_dep.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 8 | ForEach-Object { $_.Line.Trim() } | Write-Output
}
Write-Output ("PHI SKL420 DEP TYPE=" + $skl420DepType)
Write-Output '--- SECTION 4: SKELETON LOAD AND ITS LOG ---'
$skl420LoadPy = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('aW1wb3J0IHVucmVhbAoKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHN0cihzKSArICdcbicpCgpTS0VMID0gJy9HYW1lL1BhcmFnb25Db3VudGVzcy9DaGFyYWN0ZXJzL0hlcm9lcy9Db3VudGVzcy9NZXNoZXMvU19Db3VudGVzc19Ta2VsZXRvbicKb2JqID0gTm9uZQpsb2FkX25vdGUgPSAnJwp0cnk6CiAgICBvYmogPSB1bnJlYWwuRWRpdG9yQXNzZXRMaWJyYXJ5LmxvYWRfYXNzZXQoU0tFTCkKZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgbG9hZF9ub3RlID0gJ2xvYWQgcmVmdXNlZDogJyArIHN0cihlKQppZiBvYmogaXMgbm90IE5vbmU6CiAgICB0cnk6CiAgICAgICAgY2xzID0gb2JqLmdldF9jbGFzcygpCiAgICAgICAgdygnUEhJIFNLTDQyMCBMT0FERUQgQ0xBU1M9JyArIGNscy5nZXRfbmFtZSgpKQogICAgICAgIHcoJ1BISSBTS0w0MjAgTE9BREVEIENMQVNTIFBBVEg9JyArIGNscy5nZXRfcGF0aF9uYW1lKCkpCiAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgdygnUEhJIFNLTDQyMCBMT0FERUQgQ0xBU1MgVU5SRUFEQUJMRTogJyArIHN0cihlKSkKZWxzZToKICAgIHcoJ1BISSBTS0w0MjAgTE9BRCBOT05FJykKICAgIGlmIGxvYWRfbm90ZToKICAgICAgICB3KCdQSEkgU0tMNDIwIExPQUQgTk9URTogJyArIGxvYWRfbm90ZSkKdygnUEhJIFNLTDQyMCBMT0FEIFJFQUQgQ09NUExFVEUnKQpvdXQuY2xvc2UoKQo='))
$skl420LoadOut = "$skl420Base\Saved\phi_skl420_load.txt"
$skl420LoadPy = $skl420LoadPy.Replace('OUTFILE', "'$skl420LoadOut'")
Set-Content "$skl420Base\Saved\phi_skl420_load.py" -Value $skl420LoadPy -Encoding UTF8
Remove-Item $skl420LoadOut -ErrorAction SilentlyContinue
& $skl420CmdExe $skl420Uproj -run=pythonscript -script="$skl420Base\Saved\phi_skl420_load.py" -unattended -nopause -nosplash *> "$skl420Base\Saved\skl420_load.log"
if (Test-Path $skl420LoadOut) {
  Get-Content $skl420LoadOut | Write-Output
} else {
  Write-Output 'NO SKL420 LOAD OUTPUT FILE'
  Select-String -Path "$skl420Base\Saved\skl420_load.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 8 | ForEach-Object { $_.Line.Trim() } | Write-Output
}
$skl420LogHits = @(Select-String -Path "$skl420Base\Saved\skl420_load.log" -Pattern 'Retarget|Failed|Unable|Missing|\bRig\b' -ErrorAction SilentlyContinue | Select-Object -Last 40)
Write-Output ("PHI SKL420 LOAD LOG HIT COUNT=" + $skl420LogHits.Count)
if ($skl420LogHits.Count -eq 0) { Write-Output 'PHI SKL420 LOAD LOG LINES NONE' }
$skl420LogHits | ForEach-Object { Write-Output ("LOAD LOG: " + $_.Line.Trim()) }
Write-Output '--- SECTION 5: VERDICT ---'
if ($skl420Slot -ne '' -and $skl420DepType -ne 'UNRESOLVED') {
  Write-Output ("PHI SKL420 VERDICT: SKELETON REFERENCE slot=" + $skl420Slot + " dep=" + $skl420DepType)
} else {
  Write-Output ("PHI SKL420 VERDICT: REFERENCE FORM UNREADABLE family strings=" + $skl420Family.Count + " script strings=" + $skl420ScriptCount + " dep=" + $skl420DepType)
}
Write-Output 'JOB 420 DONE'
```
