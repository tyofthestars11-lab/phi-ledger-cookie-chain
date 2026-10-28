<!-- PHI-DIRECT -->
```powershell
Write-Output '=== RIG SLOT CLEAR 422 - THE LEGACY RIGCONFIG REFERENCE CLEARED FROM THE COUNTESS SKELETON AND VERIFIED FROM A FRESH LOAD (Ground from job 420, read whole: S_Countess_Skeleton.uasset at 44707 bytes with SHA-256 0513a4f18326f56412323568a6865fb61425d22706c55e4c40aa638471dbb941 carries the reference to the unloadable UE 4.19 era asset Paragon_Proto_Retarget in its slot named RigConfig at byte offset 4884, the registry records the dependency as HARD so the skeleton loads it every time, and its load log carries the warning Unable to load Paragon_Proto_Retarget because its class Rig does not exist. RigConfig is the legacy UE4 era skeleton rig slot, and the merged base animation runs on the Countess AnimBlueprint with the body proven in play, not on this legacy rig, so clearing the slot removes the hard reference and its warning together. One, the skeleton is backed up to the Saved folder as S_Countess_Skeleton.phi-backup-422 before any write, with the backup path and its size printed. Two, a pythonscript commandlet loads the skeleton and prints the RigConfig property exactly as read, its type name and its value rendered whole, the struct fields and the inner rig field value when the value is a struct, or the referenced object path when it is a direct reference. Three, the slot is cleared by the shape the read shows, a direct reference set to None or the struct inner rig field set to None with the struct set back, the property printed again from the same loaded object showing the reference empty, and the asset saved through the editor API with the save result printed. Four, a second fresh commandlet verifies the whole fix: the skeleton loaded again, the load log lines carrying Paragon_Proto_Retarget counted with zero expected, the RigConfig property read fresh with empty expected, and the registry referencers of Paragon_Proto_Retarget re-read with the skeleton gone expected and the count printed. Five, any failure after the backup, or a fresh read still showing the reference standing, restores the skeleton from the backup and prints SKELETON RESTORED with the reason before closing HELD. The verdict in one line: RIG SLOT CLEARED with the referencer and warning counts, or RIG SLOT HELD with the refusal named. Every variable carries the rig422 prefix under the standing ban on automatic variable names.) ==='
$rig422Waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $rig422Waited -lt 10) { Start-Sleep -Seconds 10; $rig422Waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'PHI RIG422 NAMED HOLD: EDITOR STILL STANDING AFTER THE 100 SECOND IN-JOB WAIT - no commandlet launched into the contention'; Write-Output 'JOB 422 STOPPED'; return }
Write-Output 'PHI RIG422 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road'
$rig422Base = 'D:\VEIL-OMNI'
$rig422Uproj = "$rig422Base\VEIL.uproject"
$rig422CmdExe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$rig422MeshFolder = "$rig422Base\Content\ParagonCountess\Characters\Heroes\Countess\Meshes"
$rig422Target = Join-Path $rig422MeshFolder 'S_Countess_Skeleton.uasset'
if (-not (Test-Path $rig422Target)) {
  $rig422Hit = Get-ChildItem (Join-Path $rig422Base 'Content') -Recurse -Filter 'S_Countess_Skeleton.uasset' -File -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($rig422Hit) { $rig422Target = $rig422Hit.FullName } else { $rig422Target = '' }
}
Write-Output '--- SECTION 1: TARGET AND BACKUP BEFORE ANY WRITE ---'
if ($rig422Target -eq '') {
  Write-Output 'SKELETON FILE NOT FOUND UNDER THE MERGED BASE CONTENT TREE'
  Write-Output 'PHI RIG422 VERDICT: RIG SLOT HELD - the skeleton file was not found, so no write was attempted and nothing was changed'
  Write-Output 'JOB 422 DONE'
  return
}
Write-Output ("PHI RIG422 TARGET FILE: " + $rig422Target)
$rig422Item = Get-Item $rig422Target
Write-Output ("PHI RIG422 SIZE BYTES=" + $rig422Item.Length)
$rig422Hash = (Get-FileHash $rig422Target -Algorithm SHA256).Hash.ToLower()
Write-Output ("PHI RIG422 SHA256: " + $rig422Hash)
$rig422Backup = "$rig422Base\Saved\S_Countess_Skeleton.phi-backup-422"
Copy-Item $rig422Target $rig422Backup -Force
if (-not (Test-Path $rig422Backup)) {
  Write-Output 'PHI RIG422 VERDICT: RIG SLOT HELD - the backup could not be written, so no write was attempted and nothing was changed'
  Write-Output 'JOB 422 DONE'
  return
}
$rig422BackupItem = Get-Item $rig422Backup
Write-Output ("PHI RIG422 BACKUP WRITTEN: " + $rig422Backup)
Write-Output ("PHI RIG422 BACKUP SIZE BYTES=" + $rig422BackupItem.Length)
Write-Output '--- SECTION 2: READ THE RIGCONFIG SLOT AND CLEAR IT (PART A) ---'
$rig422PyA = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('aW1wb3J0IHVucmVhbAoKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHN0cihzKSArICdcbicpCgpTS0VMID0gJy9HYW1lL1BhcmFnb25Db3VudGVzcy9DaGFyYWN0ZXJzL0hlcm9lcy9Db3VudGVzcy9NZXNoZXMvU19Db3VudGVzc19Ta2VsZXRvbicKCmRlZiByZW5kZXJfcmVmKHYpOgogICAgaWYgdiBpcyBOb25lOgogICAgICAgIHJldHVybiAnTk9ORScKICAgIHRyeToKICAgICAgICByZXR1cm4gdi5nZXRfcGF0aF9uYW1lKCkKICAgIGV4Y2VwdCBFeGNlcHRpb246CiAgICAgICAgcmV0dXJuIHN0cih2KQoKZGVmIHJlYWRfcHJvcChvYmopOgogICAgbGFzdF9lcnIgPSAnJwogICAgZm9yIG5hbWUgaW4gKCdyaWdfY29uZmlnJywgJ1JpZ0NvbmZpZycpOgogICAgICAgIHRyeToKICAgICAgICAgICAgcmV0dXJuIG9iai5nZXRfZWRpdG9yX3Byb3BlcnR5KG5hbWUpLCBuYW1lLCAnJwogICAgICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICAgICAgbGFzdF9lcnIgPSBzdHIoZSkKICAgIHJldHVybiBOb25lLCAnJywgbGFzdF9lcnIKCmRlZiByZWFkX2ZpZWxkKG9iaik6CiAgICBsYXN0X2VyciA9ICcnCiAgICBmb3IgbmFtZSBpbiAoJ3JpZycsICdSaWcnKToKICAgICAgICB0cnk6CiAgICAgICAgICAgIHJldHVybiBvYmouZ2V0X2VkaXRvcl9wcm9wZXJ0eShuYW1lKSwgbmFtZSwgJycKICAgICAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgICAgIGxhc3RfZXJyID0gc3RyKGUpCiAgICByZXR1cm4gTm9uZSwgJycsIGxhc3RfZXJyCgpza2VsID0gTm9uZQpsb2FkX25vdGUgPSAnJwp0cnk6CiAgICBza2VsID0gdW5yZWFsLkVkaXRvckFzc2V0TGlicmFyeS5sb2FkX2Fzc2V0KFNLRUwpCmV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgIGxvYWRfbm90ZSA9ICdsb2FkIHJlZnVzZWQ6ICcgKyBzdHIoZSkKaWYgc2tlbCBpcyBOb25lOgogICAgdygnUEhJIFJJRzQyMiBMT0FEIE9LPTAnKQogICAgaWYgbG9hZF9ub3RlOgogICAgICAgIHcoJ1BISSBSSUc0MjIgTE9BRCBOT1RFOiAnICsgbG9hZF9ub3RlKQplbHNlOgogICAgdygnUEhJIFJJRzQyMiBMT0FEIE9LPTEnKQogICAgdHJ5OgogICAgICAgIGNscyA9IHNrZWwuZ2V0X2NsYXNzKCkKICAgICAgICB3KCdQSEkgUklHNDIyIExPQURFRCBDTEFTUz0nICsgY2xzLmdldF9uYW1lKCkpCiAgICAgICAgdygnUEhJIFJJRzQyMiBMT0FERUQgQ0xBU1MgUEFUSD0nICsgY2xzLmdldF9wYXRoX25hbWUoKSkKICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICB3KCdQSEkgUklHNDIyIExPQURFRCBDTEFTUyBVTlJFQURBQkxFOiAnICsgc3RyKGUpKQogICAgdmFsLCBwcm9wX25hbWUsIHJlYWRfZXJyID0gcmVhZF9wcm9wKHNrZWwpCiAgICBpZiByZWFkX2VyciBhbmQgcHJvcF9uYW1lID09ICcnOgogICAgICAgIHcoJ1BISSBSSUc0MjIgUklHQ09ORklHIFJFQUQgRVJST1I6ICcgKyByZWFkX2VycikKICAgICAgICB3KCdQSEkgUklHNDIyIFJFQUQgT0s9MCcpCiAgICBlbHNlOgogICAgICAgIHcoJ1BISSBSSUc0MjIgUkVBRCBPSz0xJykKICAgICAgICB3KCdQSEkgUklHNDIyIFJJR0NPTkZJRyBQUk9QIE5BTUU6ICcgKyBwcm9wX25hbWUpCiAgICAgICAgdygnUEhJIFJJRzQyMiBSSUdDT05GSUcgVFlQRTogJyArIHR5cGUodmFsKS5fX25hbWVfXykKICAgICAgICB3KCdQSEkgUklHNDIyIFJJR0NPTkZJRyBWQUxVRTogJyArIHN0cih2YWwpKQogICAgICAgIGlzX3N0cnVjdCA9IDAKICAgICAgICByaWdfdmFsID0gTm9uZQogICAgICAgIGZpZWxkX25hbWUgPSAnJwogICAgICAgIGlmIHZhbCBpcyBub3QgTm9uZToKICAgICAgICAgICAgcmlnX3ZhbCwgZmllbGRfbmFtZSwgZmllbGRfZXJyID0gcmVhZF9maWVsZCh2YWwpCiAgICAgICAgICAgIGlmIGZpZWxkX2VyciA9PSAnJzoKICAgICAgICAgICAgICAgIGlzX3N0cnVjdCA9IDEKICAgICAgICAgICAgICAgIHcoJ1BISSBSSUc0MjIgUklHQ09ORklHIEZJRUxEIE5BTUU6ICcgKyBmaWVsZF9uYW1lKQogICAgICAgICAgICAgICAgdygnUEhJIFJJRzQyMiBSSUdDT05GSUcgRklFTEQgcmlnIFRZUEU6ICcgKyB0eXBlKHJpZ192YWwpLl9fbmFtZV9fKQogICAgICAgICAgICAgICAgdygnUEhJIFJJRzQyMiBSSUdDT05GSUcgRklFTEQgcmlnIFZBTFVFOiAnICsgcmVuZGVyX3JlZihyaWdfdmFsKSkKICAgICAgICB3KCdQSEkgUklHNDIyIFJJR0NPTkZJRyBJUyBTVFJVQ1Q9JyArIHN0cihpc19zdHJ1Y3QpKQogICAgICAgIGNsZWFyZWQgPSAwCiAgICAgICAgY2xlYXJfZXJyID0gJycKICAgICAgICB0cnk6CiAgICAgICAgICAgIGlmIHZhbCBpcyBOb25lOgogICAgICAgICAgICAgICAgY2xlYXJlZCA9IDEKICAgICAgICAgICAgZWxpZiBpc19zdHJ1Y3Q6CiAgICAgICAgICAgICAgICB2YWwuc2V0X2VkaXRvcl9wcm9wZXJ0eShmaWVsZF9uYW1lLCBOb25lKQogICAgICAgICAgICAgICAgc2tlbC5zZXRfZWRpdG9yX3Byb3BlcnR5KHByb3BfbmFtZSwgdmFsKQogICAgICAgICAgICAgICAgY2xlYXJlZCA9IDEKICAgICAgICAgICAgZWxzZToKICAgICAgICAgICAgICAgIHNrZWwuc2V0X2VkaXRvcl9wcm9wZXJ0eShwcm9wX25hbWUsIE5vbmUpCiAgICAgICAgICAgICAgICBjbGVhcmVkID0gMQogICAgICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICAgICAgY2xlYXJfZXJyID0gc3RyKGUpCiAgICAgICAgaWYgY2xlYXJfZXJyOgogICAgICAgICAgICB3KCdQSEkgUklHNDIyIENMRUFSIEVSUk9SOiAnICsgY2xlYXJfZXJyKQogICAgICAgIHcoJ1BISSBSSUc0MjIgQ0xFQVIgQVBQTElFRD0nICsgc3RyKGNsZWFyZWQpKQogICAgICAgIGFmdGVyLCBhZnRlcl9wcm9wLCBhZnRlcl9lcnIgPSByZWFkX3Byb3Aoc2tlbCkKICAgICAgICBhZnRlcl9lbXB0eSA9IDAKICAgICAgICBpZiBhZnRlcl9lcnIgYW5kIGFmdGVyX3Byb3AgPT0gJyc6CiAgICAgICAgICAgIHcoJ1BISSBSSUc0MjIgQUZURVIgUkVBRCBFUlJPUjogJyArIGFmdGVyX2VycikKICAgICAgICBlbHNlOgogICAgICAgICAgICB3KCdQSEkgUklHNDIyIFJJR0NPTkZJRyBBRlRFUiBUWVBFOiAnICsgdHlwZShhZnRlcikuX19uYW1lX18pCiAgICAgICAgICAgIHcoJ1BISSBSSUc0MjIgUklHQ09ORklHIEFGVEVSIFZBTFVFOiAnICsgc3RyKGFmdGVyKSkKICAgICAgICAgICAgaWYgYWZ0ZXIgaXMgTm9uZToKICAgICAgICAgICAgICAgIGFmdGVyX2VtcHR5ID0gMQogICAgICAgICAgICBlbHNlOgogICAgICAgICAgICAgICAgYWZ0ZXJfcmlnLCBhZnRlcl9maWVsZCwgYWZ0ZXJfZmllbGRfZXJyID0gcmVhZF9maWVsZChhZnRlcikKICAgICAgICAgICAgICAgIGlmIGFmdGVyX2ZpZWxkX2VyciA9PSAnJzoKICAgICAgICAgICAgICAgICAgICB3KCdQSEkgUklHNDIyIFJJR0NPTkZJRyBBRlRFUiBGSUVMRCByaWcgVkFMVUU6ICcgKyByZW5kZXJfcmVmKGFmdGVyX3JpZykpCiAgICAgICAgICAgICAgICAgICAgaWYgYWZ0ZXJfcmlnIGlzIE5vbmU6CiAgICAgICAgICAgICAgICAgICAgICAgIGFmdGVyX2VtcHR5ID0gMQogICAgICAgIHcoJ1BISSBSSUc0MjIgQUZURVIgRU1QVFk9JyArIHN0cihhZnRlcl9lbXB0eSkpCiAgICAgICAgc2F2ZV9vayA9IDAKICAgICAgICB0cnk6CiAgICAgICAgICAgIHNhdmVkMSA9IHVucmVhbC5FZGl0b3JBc3NldExpYnJhcnkuc2F2ZV9sb2FkZWRfYXNzZXQoc2tlbCkKICAgICAgICAgICAgdygnUEhJIFJJRzQyMiBTQVZFIExPQURFRCBBU1NFVCBSRVNVTFQ6ICcgKyBzdHIoc2F2ZWQxKSkKICAgICAgICAgICAgaWYgc2F2ZWQxOgogICAgICAgICAgICAgICAgc2F2ZV9vayA9IDEKICAgICAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgICAgIHcoJ1BISSBSSUc0MjIgU0FWRSBMT0FERUQgQVNTRVQgRVJST1I6ICcgKyBzdHIoZSkpCiAgICAgICAgaWYgc2F2ZV9vayA9PSAwOgogICAgICAgICAgICB0cnk6CiAgICAgICAgICAgICAgICBzYXZlZDIgPSB1bnJlYWwuRWRpdG9yQXNzZXRMaWJyYXJ5LnNhdmVfYXNzZXQoU0tFTCkKICAgICAgICAgICAgICAgIHcoJ1BISSBSSUc0MjIgU0FWRSBBU1NFVCBSRVNVTFQ6ICcgKyBzdHIoc2F2ZWQyKSkKICAgICAgICAgICAgICAgIGlmIHNhdmVkMjoKICAgICAgICAgICAgICAgICAgICBzYXZlX29rID0gMQogICAgICAgICAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgICAgICAgICB3KCdQSEkgUklHNDIyIFNBVkUgQVNTRVQgRVJST1I6ICcgKyBzdHIoZSkpCiAgICAgICAgdygnUEhJIFJJRzQyMiBTQVZFIE9LPScgKyBzdHIoc2F2ZV9vaykpCncoJ1BISSBSSUc0MjIgUEFSVCBBIENPTVBMRVRFJykKb3V0LmNsb3NlKCkK'))
$rig422OutA = "$rig422Base\Saved\phi_rig422_a.txt"
$rig422PyA = $rig422PyA.Replace('OUTFILE', "'$rig422OutA'")
Set-Content "$rig422Base\Saved\phi_rig422_a.py" -Value $rig422PyA -Encoding UTF8
Remove-Item $rig422OutA -ErrorAction SilentlyContinue
& $rig422CmdExe $rig422Uproj -run=pythonscript -script="$rig422Base\Saved\phi_rig422_a.py" -unattended -nopause -nosplash *> "$rig422Base\Saved\rig422_a.log"
$rig422LoadOk = 0
$rig422ReadOk = 0
$rig422ClearApplied = 0
$rig422AfterEmpty = 0
$rig422SaveOk = 0
$rig422PartAOk = 0
if (Test-Path $rig422OutA) {
  $rig422LinesA = @(Get-Content $rig422OutA)
  $rig422LinesA | Write-Output
  $rig422LineLoad = $rig422LinesA | Where-Object { $_ -like 'PHI RIG422 LOAD OK=*' } | Select-Object -First 1
  if ($rig422LineLoad) { $rig422LoadOk = [int]($rig422LineLoad.Substring($rig422LineLoad.IndexOf('=') + 1).Trim()) }
  $rig422LineRead = $rig422LinesA | Where-Object { $_ -like 'PHI RIG422 READ OK=*' } | Select-Object -First 1
  if ($rig422LineRead) { $rig422ReadOk = [int]($rig422LineRead.Substring($rig422LineRead.IndexOf('=') + 1).Trim()) }
  $rig422LineClear = $rig422LinesA | Where-Object { $_ -like 'PHI RIG422 CLEAR APPLIED=*' } | Select-Object -First 1
  if ($rig422LineClear) { $rig422ClearApplied = [int]($rig422LineClear.Substring($rig422LineClear.IndexOf('=') + 1).Trim()) }
  $rig422LineAfter = $rig422LinesA | Where-Object { $_ -like 'PHI RIG422 AFTER EMPTY=*' } | Select-Object -First 1
  if ($rig422LineAfter) { $rig422AfterEmpty = [int]($rig422LineAfter.Substring($rig422LineAfter.IndexOf('=') + 1).Trim()) }
  $rig422LineSave = $rig422LinesA | Where-Object { $_ -like 'PHI RIG422 SAVE OK=*' } | Select-Object -First 1
  if ($rig422LineSave) { $rig422SaveOk = [int]($rig422LineSave.Substring($rig422LineSave.IndexOf('=') + 1).Trim()) }
  if ($rig422LoadOk -eq 1 -and $rig422ReadOk -eq 1 -and $rig422ClearApplied -eq 1 -and $rig422AfterEmpty -eq 1 -and $rig422SaveOk -eq 1) { $rig422PartAOk = 1 }
} else {
  Write-Output 'NO RIG422 A OUTPUT FILE'
  Select-String -Path "$rig422Base\Saved\rig422_a.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 8 | ForEach-Object { $_.Line.Trim() } | Write-Output
}
if ($rig422PartAOk -eq 0) {
  Copy-Item $rig422Backup $rig422Target -Force
  Write-Output 'PHI RIG422 SKELETON RESTORED reason=part A did not print a completed clear with an empty after-read and a saved result; the flags stand in the part A lines above'
  Write-Output 'PHI RIG422 VERDICT: RIG SLOT HELD - the clear did not complete and verify inside part A, so the skeleton was restored from the backup'
  Write-Output 'JOB 422 DONE'
  return
}
Write-Output 'PHI RIG422 PART A GATE PASSED: clear applied, after-read empty, save result standing'
Write-Output '--- SECTION 3: FRESH VERIFICATION FROM A SECOND COMMANDLET (PART B) ---'
$rig422PyB = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('aW1wb3J0IHVucmVhbAoKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHN0cihzKSArICdcbicpCgpTS0VMID0gJy9HYW1lL1BhcmFnb25Db3VudGVzcy9DaGFyYWN0ZXJzL0hlcm9lcy9Db3VudGVzcy9NZXNoZXMvU19Db3VudGVzc19Ta2VsZXRvbicKUEtHID0gJy9HYW1lL1BhcmFnb25Db3VudGVzcy9DaGFyYWN0ZXJzL0hlcm9lcy9Db3VudGVzcy9NZXNoZXMvUGFyYWdvbl9Qcm90b19SZXRhcmdldCcKCmRlZiByZW5kZXJfcmVmKHYpOgogICAgaWYgdiBpcyBOb25lOgogICAgICAgIHJldHVybiAnTk9ORScKICAgIHRyeToKICAgICAgICByZXR1cm4gdi5nZXRfcGF0aF9uYW1lKCkKICAgIGV4Y2VwdCBFeGNlcHRpb246CiAgICAgICAgcmV0dXJuIHN0cih2KQoKZGVmIHJlYWRfcHJvcChvYmopOgogICAgbGFzdF9lcnIgPSAnJwogICAgZm9yIG5hbWUgaW4gKCdyaWdfY29uZmlnJywgJ1JpZ0NvbmZpZycpOgogICAgICAgIHRyeToKICAgICAgICAgICAgcmV0dXJuIG9iai5nZXRfZWRpdG9yX3Byb3BlcnR5KG5hbWUpLCBuYW1lLCAnJwogICAgICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICAgICAgbGFzdF9lcnIgPSBzdHIoZSkKICAgIHJldHVybiBOb25lLCAnJywgbGFzdF9lcnIKCmRlZiByZWFkX2ZpZWxkKG9iaik6CiAgICBsYXN0X2VyciA9ICcnCiAgICBmb3IgbmFtZSBpbiAoJ3JpZycsICdSaWcnKToKICAgICAgICB0cnk6CiAgICAgICAgICAgIHJldHVybiBvYmouZ2V0X2VkaXRvcl9wcm9wZXJ0eShuYW1lKSwgbmFtZSwgJycKICAgICAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgICAgIGxhc3RfZXJyID0gc3RyKGUpCiAgICByZXR1cm4gTm9uZSwgJycsIGxhc3RfZXJyCgpza2VsID0gTm9uZQpsb2FkX25vdGUgPSAnJwp0cnk6CiAgICBza2VsID0gdW5yZWFsLkVkaXRvckFzc2V0TGlicmFyeS5sb2FkX2Fzc2V0KFNLRUwpCmV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgIGxvYWRfbm90ZSA9ICdsb2FkIHJlZnVzZWQ6ICcgKyBzdHIoZSkKaWYgc2tlbCBpcyBOb25lOgogICAgdygnUEhJIFJJRzQyMiBGUkVTSCBMT0FEIE9LPTAnKQogICAgaWYgbG9hZF9ub3RlOgogICAgICAgIHcoJ1BISSBSSUc0MjIgRlJFU0ggTE9BRCBOT1RFOiAnICsgbG9hZF9ub3RlKQplbHNlOgogICAgdygnUEhJIFJJRzQyMiBGUkVTSCBMT0FEIE9LPTEnKQogICAgdHJ5OgogICAgICAgIGNscyA9IHNrZWwuZ2V0X2NsYXNzKCkKICAgICAgICB3KCdQSEkgUklHNDIyIEZSRVNIIExPQURFRCBDTEFTUz0nICsgY2xzLmdldF9uYW1lKCkpCiAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgdygnUEhJIFJJRzQyMiBGUkVTSCBMT0FERUQgQ0xBU1MgVU5SRUFEQUJMRTogJyArIHN0cihlKSkKICAgIHZhbCwgcHJvcF9uYW1lLCByZWFkX2VyciA9IHJlYWRfcHJvcChza2VsKQogICAgZnJlc2hfZW1wdHkgPSAwCiAgICBpZiByZWFkX2VyciBhbmQgcHJvcF9uYW1lID09ICcnOgogICAgICAgIHcoJ1BISSBSSUc0MjIgRlJFU0ggUkVBRCBFUlJPUjogJyArIHJlYWRfZXJyKQogICAgZWxzZToKICAgICAgICB3KCdQSEkgUklHNDIyIEZSRVNIIFJJR0NPTkZJRyBUWVBFOiAnICsgdHlwZSh2YWwpLl9fbmFtZV9fKQogICAgICAgIHcoJ1BISSBSSUc0MjIgRlJFU0ggUklHQ09ORklHIFZBTFVFOiAnICsgc3RyKHZhbCkpCiAgICAgICAgaWYgdmFsIGlzIE5vbmU6CiAgICAgICAgICAgIGZyZXNoX2VtcHR5ID0gMQogICAgICAgIGVsc2U6CiAgICAgICAgICAgIHJpZ192YWwsIGZpZWxkX25hbWUsIGZpZWxkX2VyciA9IHJlYWRfZmllbGQodmFsKQogICAgICAgICAgICBpZiBmaWVsZF9lcnIgPT0gJyc6CiAgICAgICAgICAgICAgICB3KCdQSEkgUklHNDIyIEZSRVNIIEZJRUxEIHJpZyBWQUxVRTogJyArIHJlbmRlcl9yZWYocmlnX3ZhbCkpCiAgICAgICAgICAgICAgICBpZiByaWdfdmFsIGlzIE5vbmU6CiAgICAgICAgICAgICAgICAgICAgZnJlc2hfZW1wdHkgPSAxCiAgICB3KCdQSEkgUklHNDIyIEZSRVNIIEVNUFRZPScgKyBzdHIoZnJlc2hfZW1wdHkpKQoKcmVmcyA9IE5vbmUKcmVnX25vdGUgPSAnJwp0cnk6CiAgICByZWdpc3RyeSA9IHVucmVhbC5Bc3NldFJlZ2lzdHJ5SGVscGVycy5nZXRfYXNzZXRfcmVnaXN0cnkoKQogICAgdHJ5OgogICAgICAgIG9wdHMgPSB1bnJlYWwuQXNzZXRSZWdpc3RyeURlcGVuZGVuY3lPcHRpb25zKGluY2x1ZGVfaGFyZF9wYWNrYWdlX3JlZmVyZW5jZXM9VHJ1ZSwgaW5jbHVkZV9zb2Z0X3BhY2thZ2VfcmVmZXJlbmNlcz1UcnVlLCBpbmNsdWRlX3NlYXJjaGFibGVfbmFtZXM9RmFsc2UsIGluY2x1ZGVfaGFyZF9tYW5hZ2VtZW50X3JlZmVyZW5jZXM9RmFsc2UsIGluY2x1ZGVfc29mdF9tYW5hZ2VtZW50X3JlZmVyZW5jZXM9RmFsc2UpCiAgICAgICAgcmVmcyA9IHJlZ2lzdHJ5LmdldF9yZWZlcmVuY2VycyhQS0csIG9wdHMpCiAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGUxOgogICAgICAgIHJlZ19ub3RlID0gJ29wdGlvbnMgZm9ybSByZWZ1c2VkOiAnICsgc3RyKGUxKQogICAgICAgIHJlZnMgPSByZWdpc3RyeS5nZXRfcmVmZXJlbmNlcnMoUEtHKQpleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICByZWdfbm90ZSA9IChyZWdfbm90ZSArICcgfCBwbGFpbiBmb3JtIHJlZnVzZWQ6ICcgKyBzdHIoZSkpIGlmIHJlZ19ub3RlIGVsc2Ugc3RyKGUpCiAgICByZWZzID0gTm9uZQppZiByZWdfbm90ZToKICAgIHcoJ1BISSBSSUc0MjIgUkVHSVNUUlkgTk9URTogJyArIHJlZ19ub3RlKQppZiByZWZzIGlzIE5vbmU6CiAgICB3KCdQSEkgUklHNDIyIFJFRkVSRU5DRVIgQ09VTlQ9LTEnKQplbHNlOgogICAgcmVmX25hbWVzID0gW10KICAgIGZvciBybiBpbiByZWZzOgogICAgICAgIHRyeToKICAgICAgICAgICAgcmVmX25hbWVzLmFwcGVuZChzdHIocm4pKQogICAgICAgIGV4Y2VwdCBFeGNlcHRpb246CiAgICAgICAgICAgIHBhc3MKICAgIHJlZl9uYW1lcyA9IHNvcnRlZChzZXQocmVmX25hbWVzKSkKICAgIHcoJ1BISSBSSUc0MjIgUkVGRVJFTkNFUiBDT1VOVD0nICsgc3RyKGxlbihyZWZfbmFtZXMpKSkKICAgIGlmIGxlbihyZWZfbmFtZXMpID09IDA6CiAgICAgICAgdygnUEhJIFJJRzQyMiBSRUZFUkVOQ0VSUyBFTVBUWScpCiAgICBmb3Igcm4gaW4gcmVmX25hbWVzOgogICAgICAgIHcoJ1BISSBSSUc0MjIgUkVGRVJFTkNFUjogJyArIHJuKQp3KCdQSEkgUklHNDIyIFJFR0lTVFJZIFJFQUQgQ09NUExFVEUnKQp3KCdQSEkgUklHNDIyIFBBUlQgQiBDT01QTEVURScpCm91dC5jbG9zZSgpCg=='))
$rig422OutB = "$rig422Base\Saved\phi_rig422_b.txt"
$rig422PyB = $rig422PyB.Replace('OUTFILE', "'$rig422OutB'")
Set-Content "$rig422Base\Saved\phi_rig422_b.py" -Value $rig422PyB -Encoding UTF8
Remove-Item $rig422OutB -ErrorAction SilentlyContinue
& $rig422CmdExe $rig422Uproj -run=pythonscript -script="$rig422Base\Saved\phi_rig422_b.py" -unattended -nopause -nosplash *> "$rig422Base\Saved\rig422_b.log"
$rig422FreshEmpty = 0
$rig422RefCount = -1
if (Test-Path $rig422OutB) {
  $rig422LinesB = @(Get-Content $rig422OutB)
  $rig422LinesB | Write-Output
  $rig422LineFresh = $rig422LinesB | Where-Object { $_ -like 'PHI RIG422 FRESH EMPTY=*' } | Select-Object -First 1
  if ($rig422LineFresh) { $rig422FreshEmpty = [int]($rig422LineFresh.Substring($rig422LineFresh.IndexOf('=') + 1).Trim()) }
  $rig422LineRefs = $rig422LinesB | Where-Object { $_ -like 'PHI RIG422 REFERENCER COUNT=*' } | Select-Object -First 1
  if ($rig422LineRefs) { $rig422RefCount = [int]($rig422LineRefs.Substring($rig422LineRefs.IndexOf('=') + 1).Trim()) }
} else {
  Write-Output 'NO RIG422 B OUTPUT FILE'
  Select-String -Path "$rig422Base\Saved\rig422_b.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 8 | ForEach-Object { $_.Line.Trim() } | Write-Output
}
$rig422Warn = @(Select-String -Path "$rig422Base\Saved\rig422_b.log" -Pattern 'Paragon_Proto_Retarget' -ErrorAction SilentlyContinue)
$rig422WarnCount = $rig422Warn.Count
Write-Output ("PHI RIG422 FRESH WARNING LINES COUNT=" + $rig422WarnCount)
$rig422Warn | ForEach-Object { Write-Output ("FRESH LOAD LOG: " + $_.Line.Trim()) }
Write-Output '--- SECTION 4: VERDICT ---'
if ($rig422RefCount -eq 0 -and $rig422FreshEmpty -eq 1 -and $rig422WarnCount -eq 0) {
  Write-Output ("PHI RIG422 VERDICT: RIG SLOT CLEARED referencers=" + $rig422RefCount + " warnings=" + $rig422WarnCount)
} else {
  Copy-Item $rig422Backup $rig422Target -Force
  Write-Output 'PHI RIG422 SKELETON RESTORED reason=the fresh verification still shows the reference standing; the counts stand in the verdict line below'
  Write-Output ("PHI RIG422 VERDICT: RIG SLOT HELD - fresh read still shows the reference standing referencers=" + $rig422RefCount + " fresh_empty=" + $rig422FreshEmpty + " warnings=" + $rig422WarnCount + "; skeleton restored from the backup")
}
Write-Output 'JOB 422 DONE'
```
