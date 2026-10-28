<!-- PHI-DIRECT -->
```powershell
Write-Output '=== SKELETON RIG MATCHED CLEAR 425 - THE COUNTESS SKELETON RIG REFERENCE CLEARED THROUGH THE ATTRIBUTE THAT CARRIES IT, READ FROM THE JOB 424 MATCHED LIST AND VERIFIED FROM A FRESH LOAD (Ground from job 420: S_Countess_Skeleton.uasset carries a HARD reference to the unloadable UE 4.19 era asset Paragon_Proto_Retarget from a slot whose bytes carry RigConfig at offset 4884 and RigConfiguration at offset 4902, and every skeleton load prints the warning that its class Rig does not exist. Ground from job 422: clearing through the editor property names rig_config and RigConfig held with property not found, and the skeleton was restored byte-identical. Ground from job 424, read whole: the loaded skeleton exposed 8 attribute names through Python introspection in the rig and config and skeleton and retarget family - add_compatible_skeleton, add_compatible_skeleton_soft, compatible_skeletons, copy_bones_from_skeleton, get_skeleton_additional_preview_meshes, get_skeleton_preview_mesh, set_skeleton_additional_preview_meshes, set_skeleton_preview_mesh - while all 6 direct property candidates missed, so the reference, if the editor Python surface reaches it at all, stands inside one of those 8 matched attributes as a sub-object or a differently shaped container. One, the skeleton is backed up to the Saved folder as S_Countess_Skeleton.phi-backup-425 with the backup path and size printed, and the live file SHA-256 is verified against the standing measure 0513a4f18326f56412323568a6865fb61425d22706c55e4c40aa638471dbb941 before any write; a moved hash prints HASH MOVED and closes HELD untouched. Two, a pythonscript commandlet loads the skeleton and reads every one of the 8 matched attributes whole, values rendered in print, method attributes named as methods with the two getter methods called and their returned values printed, and the attribute whose value references Paragon_Proto_Retarget or holds the rig is named as the carrier. Three, where a carrier stands, the reference is cleared through that carrier by its own shape, the after-read prints empty, and the asset is saved through the editor API with the save result printed; where no carrier stands among the matched attributes, the job prints NO CARRIER FOUND and closes without writing, adding the closing line that the thread closes cosmetic because the reference is not reachable through the editor Python surface and the skeleton loads and animates with the warning as log noise only. Four, only where a clear was saved, a second fresh commandlet verifies the whole fix: the skeleton loaded again with its matched attributes read fresh and the carrier expected empty, the registry referencers of Paragon_Proto_Retarget re-read with zero expected and the count printed, and the fresh load log lines carrying Paragon_Proto_Retarget counted with zero expected. Five, any failure after a write, or a fresh read still showing the reference standing, restores the skeleton from the backup and prints SKELETON RESTORED with the stage named before closing HELD. The verdict in one line: RIG SLOT CLEARED with the carrier name and the referencer and warning counts, or RIG SLOT HELD with the stage named. Every variable carries the rig425 prefix under the standing ban on automatic variable names.) ==='
$rig425Waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $rig425Waited -lt 10) { Start-Sleep -Seconds 10; $rig425Waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'PHI RIG425 NAMED HOLD: EDITOR STILL STANDING AFTER THE 100 SECOND IN-JOB WAIT - no commandlet launched into the contention'; Write-Output 'JOB 425 STOPPED'; return }
Write-Output 'PHI RIG425 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road'
$rig425Base = 'D:\VEIL-OMNI'
$rig425Uproj = "$rig425Base\VEIL.uproject"
$rig425CmdExe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$rig425MeshFolder = "$rig425Base\Content\ParagonCountess\Characters\Heroes\Countess\Meshes"
$rig425Target = Join-Path $rig425MeshFolder 'S_Countess_Skeleton.uasset'
if (-not (Test-Path $rig425Target)) {
  $rig425Hit = Get-ChildItem (Join-Path $rig425Base 'Content') -Recurse -Filter 'S_Countess_Skeleton.uasset' -File -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($rig425Hit) { $rig425Target = $rig425Hit.FullName } else { $rig425Target = '' }
}
Write-Output '--- SECTION 1: TARGET, HASH GATE, AND BACKUP BEFORE ANY WRITE ---'
if ($rig425Target -eq '') {
  Write-Output 'SKELETON FILE NOT FOUND UNDER THE MERGED BASE CONTENT TREE'
  Write-Output 'PHI RIG425 VERDICT: RIG SLOT HELD - stage=file resolution; the skeleton file was not found, so no write was attempted and nothing was changed'
  Write-Output 'JOB 425 DONE'
  return
}
Write-Output ("PHI RIG425 TARGET FILE: " + $rig425Target)
$rig425Item = Get-Item $rig425Target
Write-Output ("PHI RIG425 SIZE BYTES=" + $rig425Item.Length)
$rig425Hash = (Get-FileHash $rig425Target -Algorithm SHA256).Hash.ToLower()
Write-Output ("PHI RIG425 SHA256: " + $rig425Hash)
$rig425Backup = "$rig425Base\Saved\S_Countess_Skeleton.phi-backup-425"
Copy-Item $rig425Target $rig425Backup -Force
if (-not (Test-Path $rig425Backup)) {
  Write-Output 'PHI RIG425 VERDICT: RIG SLOT HELD - stage=backup; the backup could not be written, so no write was attempted and nothing was changed'
  Write-Output 'JOB 425 DONE'
  return
}
$rig425BackupItem = Get-Item $rig425Backup
Write-Output ("PHI RIG425 BACKUP WRITTEN: " + $rig425Backup)
Write-Output ("PHI RIG425 BACKUP SIZE BYTES=" + $rig425BackupItem.Length)
if ($rig425Hash -ne '0513a4f18326f56412323568a6865fb61425d22706c55e4c40aa638471dbb941') {
  Write-Output 'PHI RIG425 HASH MOVED: the live skeleton hash differs from the standing measure, so the file is left untouched'
  Write-Output 'PHI RIG425 VERDICT: RIG SLOT HELD - stage=pre-write hash check; HASH MOVED and the skeleton was left untouched'
  Write-Output 'JOB 425 DONE'
  return
}
Write-Output 'PHI RIG425 HASH GATE PASSED: the live skeleton matches the standing measure'
Write-Output '--- SECTION 2: READ THE MATCHED ATTRIBUTES AND CLEAR THROUGH THE CARRIER (PART A) ---'
$rig425PyA = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwKCm91dCA9IG9wZW4oT1VURklMRSwgJ3cnKQpkZWYgdyhzKToKICAgIG91dC53cml0ZShzdHIocykgKyAnXG4nKQoKU0tFTCA9ICcvR2FtZS9QYXJhZ29uQ291bnRlc3MvQ2hhcmFjdGVycy9IZXJvZXMvQ291bnRlc3MvTWVzaGVzL1NfQ291bnRlc3NfU2tlbGV0b24nClBLRyA9ICcvR2FtZS9QYXJhZ29uQ291bnRlc3MvQ2hhcmFjdGVycy9IZXJvZXMvQ291bnRlc3MvTWVzaGVzL1BhcmFnb25fUHJvdG9fUmV0YXJnZXQnClRBUkdFVF9UT0tFTiA9ICdQYXJhZ29uX1Byb3RvX1JldGFyZ2V0JwpNQVRDSEVEID0gWydhZGRfY29tcGF0aWJsZV9za2VsZXRvbicsICdhZGRfY29tcGF0aWJsZV9za2VsZXRvbl9zb2Z0JywgJ2NvbXBhdGlibGVfc2tlbGV0b25zJywgJ2NvcHlfYm9uZXNfZnJvbV9za2VsZXRvbicsICdnZXRfc2tlbGV0b25fYWRkaXRpb25hbF9wcmV2aWV3X21lc2hlcycsICdnZXRfc2tlbGV0b25fcHJldmlld19tZXNoJywgJ3NldF9za2VsZXRvbl9hZGRpdGlvbmFsX3ByZXZpZXdfbWVzaGVzJywgJ3NldF9za2VsZXRvbl9wcmV2aWV3X21lc2gnXQpHRVRURVJTID0gWydnZXRfc2tlbGV0b25fYWRkaXRpb25hbF9wcmV2aWV3X21lc2hlcycsICdnZXRfc2tlbGV0b25fcHJldmlld19tZXNoJ10KCmRlZiByZW5kZXJfcmVmKHYpOgogICAgaWYgdiBpcyBOb25lOgogICAgICAgIHJldHVybiAnTk9ORScKICAgIHRyeToKICAgICAgICByZXR1cm4gdi5nZXRfcGF0aF9uYW1lKCkKICAgIGV4Y2VwdCBFeGNlcHRpb246CiAgICAgICAgcmV0dXJuIHN0cih2KQoKZGVmIHJlbmRlcl93aG9sZSh2KToKICAgIGlmIHYgaXMgTm9uZToKICAgICAgICByZXR1cm4gJ05PTkUnCiAgICBpZiBpc2luc3RhbmNlKHYsIChsaXN0LCB0dXBsZSkpOgogICAgICAgIHBhcnRzID0gW10KICAgICAgICBmb3IgaXRlbSBpbiB2OgogICAgICAgICAgICBwYXJ0cy5hcHBlbmQocmVuZGVyX3JlZihpdGVtKSkKICAgICAgICByZXR1cm4gJ0xJU1RbJyArICcgfCAnLmpvaW4ocGFydHMpICsgJ10nCiAgICByZXR1cm4gcmVuZGVyX3JlZih2KQoKZGVmIGNhcnJpZXModGV4dCk6CiAgICByZXR1cm4gVEFSR0VUX1RPS0VOIGluIHRleHQKCnNrZWwgPSBOb25lCmxvYWRfbm90ZSA9ICcnCnRyeToKICAgIHNrZWwgPSB1bnJlYWwuRWRpdG9yQXNzZXRMaWJyYXJ5LmxvYWRfYXNzZXQoU0tFTCkKZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgbG9hZF9ub3RlID0gJ2xvYWQgcmVmdXNlZDogJyArIHN0cihlKQpjYXJyaWVyID0gJycKY2Fycmllcl9raW5kID0gJycKaWYgc2tlbCBpcyBOb25lOgogICAgdygnUEhJIFJJRzQyNSBMT0FEIE9LPTAnKQogICAgaWYgbG9hZF9ub3RlOgogICAgICAgIHcoJ1BISSBSSUc0MjUgTE9BRCBOT1RFOiAnICsgbG9hZF9ub3RlKQplbHNlOgogICAgdygnUEhJIFJJRzQyNSBMT0FEIE9LPTEnKQogICAgdHJ5OgogICAgICAgIGNscyA9IHNrZWwuZ2V0X2NsYXNzKCkKICAgICAgICB3KCdQSEkgUklHNDI1IExPQURFRCBDTEFTUz0nICsgY2xzLmdldF9uYW1lKCkpCiAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgdygnUEhJIFJJRzQyNSBMT0FERUQgQ0xBU1MgVU5SRUFEQUJMRTogJyArIHN0cihlKSkKICAgIGZvciBuYW1lIGluIE1BVENIRUQ6CiAgICAgICAgdHJ5OgogICAgICAgICAgICBhdHRyID0gZ2V0YXR0cihza2VsLCBuYW1lKQogICAgICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICAgICAgdygnUEhJIFJJRzQyNSBBVFRSICcgKyBuYW1lICsgJyBSRUFEIEVSUk9SOiAnICsgc3RyKGUpKQogICAgICAgICAgICBjb250aW51ZQogICAgICAgIGlmIGNhbGxhYmxlKGF0dHIpOgogICAgICAgICAgICB3KCdQSEkgUklHNDI1IEFUVFIgJyArIG5hbWUgKyAnIEtJTkQ9TUVUSE9EJykKICAgICAgICAgICAgaWYgbmFtZSBpbiBHRVRURVJTOgogICAgICAgICAgICAgICAgdHJ5OgogICAgICAgICAgICAgICAgICAgIHZhbCA9IGF0dHIoKQogICAgICAgICAgICAgICAgICAgIHRleHQgPSByZW5kZXJfd2hvbGUodmFsKQogICAgICAgICAgICAgICAgICAgIHcoJ1BISSBSSUc0MjUgQVRUUiAnICsgbmFtZSArICcgQ0FMTCBWQUxVRTogJyArIHRleHQpCiAgICAgICAgICAgICAgICAgICAgaWYgY2Fycmllcyh0ZXh0KSBhbmQgY2FycmllciA9PSAnJzoKICAgICAgICAgICAgICAgICAgICAgICAgY2FycmllciA9IG5hbWUKICAgICAgICAgICAgICAgICAgICAgICAgY2Fycmllcl9raW5kID0gJ2dldHRlcicKICAgICAgICAgICAgICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICAgICAgICAgICAgICB3KCdQSEkgUklHNDI1IEFUVFIgJyArIG5hbWUgKyAnIENBTEwgRVJST1I6ICcgKyBzdHIoZSkpCiAgICAgICAgZWxzZToKICAgICAgICAgICAgdGV4dCA9IHJlbmRlcl93aG9sZShhdHRyKQogICAgICAgICAgICB3KCdQSEkgUklHNDI1IEFUVFIgJyArIG5hbWUgKyAnIEtJTkQ9VkFMVUUgVFlQRT0nICsgdHlwZShhdHRyKS5fX25hbWVfXykKICAgICAgICAgICAgdygnUEhJIFJJRzQyNSBBVFRSICcgKyBuYW1lICsgJyBWQUxVRTogJyArIHRleHQpCiAgICAgICAgICAgIHRyeToKICAgICAgICAgICAgICAgIHZhbDIgPSBza2VsLmdldF9lZGl0b3JfcHJvcGVydHkobmFtZSkKICAgICAgICAgICAgICAgIHRleHQyID0gcmVuZGVyX3dob2xlKHZhbDIpCiAgICAgICAgICAgICAgICB3KCdQSEkgUklHNDI1IEFUVFIgJyArIG5hbWUgKyAnIEVESVRPUiBWQUxVRTogJyArIHRleHQyKQogICAgICAgICAgICAgICAgaWYgY2Fycmllcyh0ZXh0MikgYW5kIGNhcnJpZXIgPT0gJyc6CiAgICAgICAgICAgICAgICAgICAgY2FycmllciA9IG5hbWUKICAgICAgICAgICAgICAgICAgICBjYXJyaWVyX2tpbmQgPSAncHJvcGVydHknCiAgICAgICAgICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICAgICAgICAgIHcoJ1BISSBSSUc0MjUgQVRUUiAnICsgbmFtZSArICcgRURJVE9SIFJFQUQgRVJST1I6ICcgKyBzdHIoZSkpCiAgICAgICAgICAgIGlmIGNhcnJpZXModGV4dCkgYW5kIGNhcnJpZXIgPT0gJyc6CiAgICAgICAgICAgICAgICBjYXJyaWVyID0gbmFtZQogICAgICAgICAgICAgICAgY2Fycmllcl9raW5kID0gJ3Byb3BlcnR5JwogICAgdygnUEhJIFJJRzQyNSBDQVJSSUVSIEZPVU5EPScgKyAoJzEnIGlmIGNhcnJpZXIgZWxzZSAnMCcpKQogICAgaWYgY2FycmllcjoKICAgICAgICB3KCdQSEkgUklHNDI1IENBUlJJRVIgTkFNRTogJyArIGNhcnJpZXIpCiAgICAgICAgdygnUEhJIFJJRzQyNSBDQVJSSUVSIEtJTkQ6ICcgKyBjYXJyaWVyX2tpbmQpCiAgICAgICAgY2xlYXJlZCA9IDAKICAgICAgICBjbGVhcl9lcnIgPSAnJwogICAgICAgIHRyeToKICAgICAgICAgICAgaWYgY2FycmllciA9PSAnY29tcGF0aWJsZV9za2VsZXRvbnMnOgogICAgICAgICAgICAgICAgY3VyID0gc2tlbC5nZXRfZWRpdG9yX3Byb3BlcnR5KCdjb21wYXRpYmxlX3NrZWxldG9ucycpCiAgICAgICAgICAgICAgICBrZXB0ID0gW10KICAgICAgICAgICAgICAgIGZvciBpdGVtIGluIGN1cjoKICAgICAgICAgICAgICAgICAgICBpZiBub3QgY2FycmllcyhyZW5kZXJfcmVmKGl0ZW0pKToKICAgICAgICAgICAgICAgICAgICAgICAga2VwdC5hcHBlbmQoaXRlbSkKICAgICAgICAgICAgICAgIHNrZWwuc2V0X2VkaXRvcl9wcm9wZXJ0eSgnY29tcGF0aWJsZV9za2VsZXRvbnMnLCBrZXB0KQogICAgICAgICAgICAgICAgY2xlYXJlZCA9IDEKICAgICAgICAgICAgZWxpZiBjYXJyaWVyID09ICdnZXRfc2tlbGV0b25fcHJldmlld19tZXNoJzoKICAgICAgICAgICAgICAgIHNrZWwuc2V0X3NrZWxldG9uX3ByZXZpZXdfbWVzaChOb25lKQogICAgICAgICAgICAgICAgY2xlYXJlZCA9IDEKICAgICAgICAgICAgZWxpZiBjYXJyaWVyID09ICdnZXRfc2tlbGV0b25fYWRkaXRpb25hbF9wcmV2aWV3X21lc2hlcyc6CiAgICAgICAgICAgICAgICBza2VsLnNldF9za2VsZXRvbl9hZGRpdGlvbmFsX3ByZXZpZXdfbWVzaGVzKFtdKQogICAgICAgICAgICAgICAgY2xlYXJlZCA9IDEKICAgICAgICAgICAgZWxzZToKICAgICAgICAgICAgICAgIHNrZWwuc2V0X2VkaXRvcl9wcm9wZXJ0eShjYXJyaWVyLCBOb25lKQogICAgICAgICAgICAgICAgY2xlYXJlZCA9IDEKICAgICAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgICAgIGNsZWFyX2VyciA9IHN0cihlKQogICAgICAgIGlmIGNsZWFyX2VycjoKICAgICAgICAgICAgdygnUEhJIFJJRzQyNSBDTEVBUiBFUlJPUjogJyArIGNsZWFyX2VycikKICAgICAgICB3KCdQSEkgUklHNDI1IENMRUFSIEFQUExJRUQ9JyArIHN0cihjbGVhcmVkKSkKICAgICAgICBhZnRlcl9lbXB0eSA9IDAKICAgICAgICBpZiBjbGVhcmVkOgogICAgICAgICAgICB0cnk6CiAgICAgICAgICAgICAgICBpZiBjYXJyaWVyID09ICdjb21wYXRpYmxlX3NrZWxldG9ucyc6CiAgICAgICAgICAgICAgICAgICAgY2hrID0gcmVuZGVyX3dob2xlKHNrZWwuZ2V0X2VkaXRvcl9wcm9wZXJ0eSgnY29tcGF0aWJsZV9za2VsZXRvbnMnKSkKICAgICAgICAgICAgICAgIGVsaWYgY2FycmllciBpbiBHRVRURVJTOgogICAgICAgICAgICAgICAgICAgIGNoayA9IHJlbmRlcl93aG9sZShnZXRhdHRyKHNrZWwsIGNhcnJpZXIpKCkpCiAgICAgICAgICAgICAgICBlbHNlOgogICAgICAgICAgICAgICAgICAgIGNoayA9IHJlbmRlcl93aG9sZShza2VsLmdldF9lZGl0b3JfcHJvcGVydHkoY2FycmllcikpCiAgICAgICAgICAgICAgICB3KCdQSEkgUklHNDI1IENBUlJJRVIgQUZURVIgVkFMVUU6ICcgKyBjaGspCiAgICAgICAgICAgICAgICBpZiBub3QgY2FycmllcyhjaGspOgogICAgICAgICAgICAgICAgICAgIGFmdGVyX2VtcHR5ID0gMQogICAgICAgICAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgICAgICAgICB3KCdQSEkgUklHNDI1IEFGVEVSIFJFQUQgRVJST1I6ICcgKyBzdHIoZSkpCiAgICAgICAgdygnUEhJIFJJRzQyNSBBRlRFUiBFTVBUWT0nICsgc3RyKGFmdGVyX2VtcHR5KSkKICAgICAgICBzYXZlX29rID0gMAogICAgICAgIGlmIGNsZWFyZWQgYW5kIGFmdGVyX2VtcHR5OgogICAgICAgICAgICB0cnk6CiAgICAgICAgICAgICAgICBzYXZlZDEgPSB1bnJlYWwuRWRpdG9yQXNzZXRMaWJyYXJ5LnNhdmVfbG9hZGVkX2Fzc2V0KHNrZWwpCiAgICAgICAgICAgICAgICB3KCdQSEkgUklHNDI1IFNBVkUgTE9BREVEIEFTU0VUIFJFU1VMVDogJyArIHN0cihzYXZlZDEpKQogICAgICAgICAgICAgICAgaWYgc2F2ZWQxOgogICAgICAgICAgICAgICAgICAgIHNhdmVfb2sgPSAxCiAgICAgICAgICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICAgICAgICAgIHcoJ1BISSBSSUc0MjUgU0FWRSBMT0FERUQgQVNTRVQgRVJST1I6ICcgKyBzdHIoZSkpCiAgICAgICAgICAgIGlmIHNhdmVfb2sgPT0gMDoKICAgICAgICAgICAgICAgIHRyeToKICAgICAgICAgICAgICAgICAgICBzYXZlZDIgPSB1bnJlYWwuRWRpdG9yQXNzZXRMaWJyYXJ5LnNhdmVfYXNzZXQoU0tFTCkKICAgICAgICAgICAgICAgICAgICB3KCdQSEkgUklHNDI1IFNBVkUgQVNTRVQgUkVTVUxUOiAnICsgc3RyKHNhdmVkMikpCiAgICAgICAgICAgICAgICAgICAgaWYgc2F2ZWQyOgogICAgICAgICAgICAgICAgICAgICAgICBzYXZlX29rID0gMQogICAgICAgICAgICAgICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgICAgICAgICAgICAgICAgIHcoJ1BISSBSSUc0MjUgU0FWRSBBU1NFVCBFUlJPUjogJyArIHN0cihlKSkKICAgICAgICB3KCdQSEkgUklHNDI1IFNBVkUgT0s9JyArIHN0cihzYXZlX29rKSkKdygnUEhJIFJJRzQyNSBQQVJUIEEgQ09NUExFVEUnKQpvdXQuY2xvc2UoKQo='))
$rig425OutA = "$rig425Base\Saved\phi_rig425_a.txt"
$rig425PyA = $rig425PyA.Replace('OUTFILE', "'$rig425OutA'")
Set-Content "$rig425Base\Saved\phi_rig425_a.py" -Value $rig425PyA -Encoding UTF8
Remove-Item $rig425OutA -ErrorAction SilentlyContinue
& $rig425CmdExe $rig425Uproj -run=pythonscript -script="$rig425Base\Saved\phi_rig425_a.py" -unattended -nopause -nosplash *> "$rig425Base\Saved\rig425_a.log"
$rig425LoadOk = 0
$rig425CarrierFound = 0
$rig425CarrierName = ''
$rig425ClearApplied = 0
$rig425AfterEmpty = 0
$rig425SaveOk = 0
if (Test-Path $rig425OutA) {
  $rig425LinesA = @(Get-Content $rig425OutA)
  $rig425LinesA | Write-Output
  $rig425LineLoad = $rig425LinesA | Where-Object { $_ -like 'PHI RIG425 LOAD OK=*' } | Select-Object -First 1
  if ($rig425LineLoad) { $rig425LoadOk = [int]($rig425LineLoad.Substring($rig425LineLoad.IndexOf('=') + 1).Trim()) }
  $rig425LineCarrier = $rig425LinesA | Where-Object { $_ -like 'PHI RIG425 CARRIER FOUND=*' } | Select-Object -First 1
  if ($rig425LineCarrier) { $rig425CarrierFound = [int]($rig425LineCarrier.Substring($rig425LineCarrier.IndexOf('=') + 1).Trim()) }
  $rig425LineCarrierName = $rig425LinesA | Where-Object { $_ -like 'PHI RIG425 CARRIER NAME: *' } | Select-Object -First 1
  if ($rig425LineCarrierName) { $rig425CarrierName = $rig425LineCarrierName.Substring($rig425LineCarrierName.IndexOf(':') + 1).Trim() }
  $rig425LineClear = $rig425LinesA | Where-Object { $_ -like 'PHI RIG425 CLEAR APPLIED=*' } | Select-Object -First 1
  if ($rig425LineClear) { $rig425ClearApplied = [int]($rig425LineClear.Substring($rig425LineClear.IndexOf('=') + 1).Trim()) }
  $rig425LineAfter = $rig425LinesA | Where-Object { $_ -like 'PHI RIG425 AFTER EMPTY=*' } | Select-Object -First 1
  if ($rig425LineAfter) { $rig425AfterEmpty = [int]($rig425LineAfter.Substring($rig425LineAfter.IndexOf('=') + 1).Trim()) }
  $rig425LineSave = $rig425LinesA | Where-Object { $_ -like 'PHI RIG425 SAVE OK=*' } | Select-Object -First 1
  if ($rig425LineSave) { $rig425SaveOk = [int]($rig425LineSave.Substring($rig425LineSave.IndexOf('=') + 1).Trim()) }
} else {
  Write-Output 'NO RIG425 A OUTPUT FILE'
  Select-String -Path "$rig425Base\Saved\rig425_a.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 8 | ForEach-Object { $_.Line.Trim() } | Write-Output
}
if ($rig425LoadOk -eq 0) {
  Write-Output 'PHI RIG425 VERDICT: RIG SLOT HELD - stage=part A load; the skeleton did not load in the commandlet, so nothing was written and no restore was needed'
  Write-Output 'JOB 425 DONE'
  return
}
if ($rig425CarrierFound -eq 0) {
  Write-Output 'PHI RIG425 NO CARRIER FOUND: none of the 8 matched attributes carries the retarget reference on the editor Python surface'
  Write-Output 'PHI RIG425 THREAD CLOSES COSMETIC - the reference is not reachable through the editor Python surface, the skeleton loads and animates with the warning as log noise only'
  Write-Output 'PHI RIG425 VERDICT: RIG SLOT HELD - stage=no carrier; no attribute among the job 424 matched list holds the reference, so nothing was written'
  Write-Output 'JOB 425 DONE'
  return
}
if (-not ($rig425ClearApplied -eq 1 -and $rig425AfterEmpty -eq 1 -and $rig425SaveOk -eq 1)) {
  Copy-Item $rig425Backup $rig425Target -Force
  Write-Output 'PHI RIG425 SKELETON RESTORED reason=part A found the carrier but the clear, the empty after-read, or the save did not all print standing; the flags stand in the part A lines above'
  Write-Output 'PHI RIG425 VERDICT: RIG SLOT HELD - stage=clear or save refused inside part A; the skeleton was restored from the backup'
  Write-Output 'JOB 425 DONE'
  return
}
Write-Output 'PHI RIG425 PART A GATE PASSED: carrier cleared, after-read empty, save result standing'
Write-Output '--- SECTION 3: FRESH VERIFICATION FROM A SECOND COMMANDLET (PART B) ---'
$rig425PyB = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwKCm91dCA9IG9wZW4oT1VURklMRSwgJ3cnKQpkZWYgdyhzKToKICAgIG91dC53cml0ZShzdHIocykgKyAnXG4nKQoKU0tFTCA9ICcvR2FtZS9QYXJhZ29uQ291bnRlc3MvQ2hhcmFjdGVycy9IZXJvZXMvQ291bnRlc3MvTWVzaGVzL1NfQ291bnRlc3NfU2tlbGV0b24nClBLRyA9ICcvR2FtZS9QYXJhZ29uQ291bnRlc3MvQ2hhcmFjdGVycy9IZXJvZXMvQ291bnRlc3MvTWVzaGVzL1BhcmFnb25fUHJvdG9fUmV0YXJnZXQnClRBUkdFVF9UT0tFTiA9ICdQYXJhZ29uX1Byb3RvX1JldGFyZ2V0JwpNQVRDSEVEID0gWydhZGRfY29tcGF0aWJsZV9za2VsZXRvbicsICdhZGRfY29tcGF0aWJsZV9za2VsZXRvbl9zb2Z0JywgJ2NvbXBhdGlibGVfc2tlbGV0b25zJywgJ2NvcHlfYm9uZXNfZnJvbV9za2VsZXRvbicsICdnZXRfc2tlbGV0b25fYWRkaXRpb25hbF9wcmV2aWV3X21lc2hlcycsICdnZXRfc2tlbGV0b25fcHJldmlld19tZXNoJywgJ3NldF9za2VsZXRvbl9hZGRpdGlvbmFsX3ByZXZpZXdfbWVzaGVzJywgJ3NldF9za2VsZXRvbl9wcmV2aWV3X21lc2gnXQpHRVRURVJTID0gWydnZXRfc2tlbGV0b25fYWRkaXRpb25hbF9wcmV2aWV3X21lc2hlcycsICdnZXRfc2tlbGV0b25fcHJldmlld19tZXNoJ10KCmRlZiByZW5kZXJfcmVmKHYpOgogICAgaWYgdiBpcyBOb25lOgogICAgICAgIHJldHVybiAnTk9ORScKICAgIHRyeToKICAgICAgICByZXR1cm4gdi5nZXRfcGF0aF9uYW1lKCkKICAgIGV4Y2VwdCBFeGNlcHRpb246CiAgICAgICAgcmV0dXJuIHN0cih2KQoKZGVmIHJlbmRlcl93aG9sZSh2KToKICAgIGlmIHYgaXMgTm9uZToKICAgICAgICByZXR1cm4gJ05PTkUnCiAgICBpZiBpc2luc3RhbmNlKHYsIChsaXN0LCB0dXBsZSkpOgogICAgICAgIHBhcnRzID0gW10KICAgICAgICBmb3IgaXRlbSBpbiB2OgogICAgICAgICAgICBwYXJ0cy5hcHBlbmQocmVuZGVyX3JlZihpdGVtKSkKICAgICAgICByZXR1cm4gJ0xJU1RbJyArICcgfCAnLmpvaW4ocGFydHMpICsgJ10nCiAgICByZXR1cm4gcmVuZGVyX3JlZih2KQoKc2tlbCA9IE5vbmUKbG9hZF9ub3RlID0gJycKdHJ5OgogICAgc2tlbCA9IHVucmVhbC5FZGl0b3JBc3NldExpYnJhcnkubG9hZF9hc3NldChTS0VMKQpleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICBsb2FkX25vdGUgPSAnbG9hZCByZWZ1c2VkOiAnICsgc3RyKGUpCmlmIHNrZWwgaXMgTm9uZToKICAgIHcoJ1BISSBSSUc0MjUgRlJFU0ggTE9BRCBPSz0wJykKICAgIGlmIGxvYWRfbm90ZToKICAgICAgICB3KCdQSEkgUklHNDI1IEZSRVNIIExPQUQgTk9URTogJyArIGxvYWRfbm90ZSkKZWxzZToKICAgIHcoJ1BISSBSSUc0MjUgRlJFU0ggTE9BRCBPSz0xJykKICAgIHN0YW5kaW5nID0gMAogICAgZm9yIG5hbWUgaW4gTUFUQ0hFRDoKICAgICAgICB0cnk6CiAgICAgICAgICAgIGF0dHIgPSBnZXRhdHRyKHNrZWwsIG5hbWUpCiAgICAgICAgZXhjZXB0IEV4Y2VwdGlvbjoKICAgICAgICAgICAgY29udGludWUKICAgICAgICBpZiBjYWxsYWJsZShhdHRyKToKICAgICAgICAgICAgaWYgbmFtZSBpbiBHRVRURVJTOgogICAgICAgICAgICAgICAgdHJ5OgogICAgICAgICAgICAgICAgICAgIHRleHQgPSByZW5kZXJfd2hvbGUoYXR0cigpKQogICAgICAgICAgICAgICAgICAgIHcoJ1BISSBSSUc0MjUgRlJFU0ggQVRUUiAnICsgbmFtZSArICcgVkFMVUU6ICcgKyB0ZXh0KQogICAgICAgICAgICAgICAgICAgIGlmIFRBUkdFVF9UT0tFTiBpbiB0ZXh0OgogICAgICAgICAgICAgICAgICAgICAgICBzdGFuZGluZyA9IDEKICAgICAgICAgICAgICAgIGV4Y2VwdCBFeGNlcHRpb246CiAgICAgICAgICAgICAgICAgICAgcGFzcwogICAgICAgIGVsc2U6CiAgICAgICAgICAgIHRleHQgPSByZW5kZXJfd2hvbGUoYXR0cikKICAgICAgICAgICAgdygnUEhJIFJJRzQyNSBGUkVTSCBBVFRSICcgKyBuYW1lICsgJyBWQUxVRTogJyArIHRleHQpCiAgICAgICAgICAgIGlmIFRBUkdFVF9UT0tFTiBpbiB0ZXh0OgogICAgICAgICAgICAgICAgc3RhbmRpbmcgPSAxCiAgICAgICAgICAgIHRyeToKICAgICAgICAgICAgICAgIHRleHQyID0gcmVuZGVyX3dob2xlKHNrZWwuZ2V0X2VkaXRvcl9wcm9wZXJ0eShuYW1lKSkKICAgICAgICAgICAgICAgIGlmIFRBUkdFVF9UT0tFTiBpbiB0ZXh0MjoKICAgICAgICAgICAgICAgICAgICBzdGFuZGluZyA9IDEKICAgICAgICAgICAgZXhjZXB0IEV4Y2VwdGlvbjoKICAgICAgICAgICAgICAgIHBhc3MKICAgIHcoJ1BISSBSSUc0MjUgRlJFU0ggQ0FSUklFUiBTVEFORElORz0nICsgc3RyKHN0YW5kaW5nKSkKCnJlZnMgPSBOb25lCnJlZ19ub3RlID0gJycKdHJ5OgogICAgcmVnaXN0cnkgPSB1bnJlYWwuQXNzZXRSZWdpc3RyeUhlbHBlcnMuZ2V0X2Fzc2V0X3JlZ2lzdHJ5KCkKICAgIHRyeToKICAgICAgICBvcHRzID0gdW5yZWFsLkFzc2V0UmVnaXN0cnlEZXBlbmRlbmN5T3B0aW9ucyhpbmNsdWRlX2hhcmRfcGFja2FnZV9yZWZlcmVuY2VzPVRydWUsIGluY2x1ZGVfc29mdF9wYWNrYWdlX3JlZmVyZW5jZXM9VHJ1ZSwgaW5jbHVkZV9zZWFyY2hhYmxlX25hbWVzPUZhbHNlLCBpbmNsdWRlX2hhcmRfbWFuYWdlbWVudF9yZWZlcmVuY2VzPUZhbHNlLCBpbmNsdWRlX3NvZnRfbWFuYWdlbWVudF9yZWZlcmVuY2VzPUZhbHNlKQogICAgICAgIHJlZnMgPSByZWdpc3RyeS5nZXRfcmVmZXJlbmNlcnMoUEtHLCBvcHRzKQogICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlMToKICAgICAgICByZWdfbm90ZSA9ICdvcHRpb25zIGZvcm0gcmVmdXNlZDogJyArIHN0cihlMSkKICAgICAgICByZWZzID0gcmVnaXN0cnkuZ2V0X3JlZmVyZW5jZXJzKFBLRykKZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgcmVnX25vdGUgPSAocmVnX25vdGUgKyAnIHwgcGxhaW4gZm9ybSByZWZ1c2VkOiAnICsgc3RyKGUpKSBpZiByZWdfbm90ZSBlbHNlIHN0cihlKQogICAgcmVmcyA9IE5vbmUKaWYgcmVnX25vdGU6CiAgICB3KCdQSEkgUklHNDI1IFJFR0lTVFJZIE5PVEU6ICcgKyByZWdfbm90ZSkKaWYgcmVmcyBpcyBOb25lOgogICAgdygnUEhJIFJJRzQyNSBSRUZFUkVOQ0VSIENPVU5UPS0xJykKZWxzZToKICAgIHJlZl9uYW1lcyA9IFtdCiAgICBmb3Igcm4gaW4gcmVmczoKICAgICAgICB0cnk6CiAgICAgICAgICAgIHJlZl9uYW1lcy5hcHBlbmQoc3RyKHJuKSkKICAgICAgICBleGNlcHQgRXhjZXB0aW9uOgogICAgICAgICAgICBwYXNzCiAgICByZWZfbmFtZXMgPSBzb3J0ZWQoc2V0KHJlZl9uYW1lcykpCiAgICB3KCdQSEkgUklHNDI1IFJFRkVSRU5DRVIgQ09VTlQ9JyArIHN0cihsZW4ocmVmX25hbWVzKSkpCiAgICBpZiBsZW4ocmVmX25hbWVzKSA9PSAwOgogICAgICAgIHcoJ1BISSBSSUc0MjUgUkVGRVJFTkNFUlMgRU1QVFknKQogICAgZm9yIHJuIGluIHJlZl9uYW1lczoKICAgICAgICB3KCdQSEkgUklHNDI1IFJFRkVSRU5DRVI6ICcgKyBybikKdygnUEhJIFJJRzQyNSBSRUdJU1RSWSBSRUFEIENPTVBMRVRFJykKdygnUEhJIFJJRzQyNSBQQVJUIEIgQ09NUExFVEUnKQpvdXQuY2xvc2UoKQo='))
$rig425OutB = "$rig425Base\Saved\phi_rig425_b.txt"
$rig425PyB = $rig425PyB.Replace('OUTFILE', "'$rig425OutB'")
Set-Content "$rig425Base\Saved\phi_rig425_b.py" -Value $rig425PyB -Encoding UTF8
Remove-Item $rig425OutB -ErrorAction SilentlyContinue
& $rig425CmdExe $rig425Uproj -run=pythonscript -script="$rig425Base\Saved\phi_rig425_b.py" -unattended -nopause -nosplash *> "$rig425Base\Saved\rig425_b.log"
$rig425FreshStanding = 1
$rig425RefCount = -1
if (Test-Path $rig425OutB) {
  $rig425LinesB = @(Get-Content $rig425OutB)
  $rig425LinesB | Write-Output
  $rig425LineStanding = $rig425LinesB | Where-Object { $_ -like 'PHI RIG425 FRESH CARRIER STANDING=*' } | Select-Object -First 1
  if ($rig425LineStanding) { $rig425FreshStanding = [int]($rig425LineStanding.Substring($rig425LineStanding.IndexOf('=') + 1).Trim()) }
  $rig425LineRefs = $rig425LinesB | Where-Object { $_ -like 'PHI RIG425 REFERENCER COUNT=*' } | Select-Object -First 1
  if ($rig425LineRefs) { $rig425RefCount = [int]($rig425LineRefs.Substring($rig425LineRefs.IndexOf('=') + 1).Trim()) }
} else {
  Write-Output 'NO RIG425 B OUTPUT FILE'
  Select-String -Path "$rig425Base\Saved\rig425_b.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 8 | ForEach-Object { $_.Line.Trim() } | Write-Output
}
$rig425Warn = @(Select-String -Path "$rig425Base\Saved\rig425_b.log" -Pattern 'Paragon_Proto_Retarget' -ErrorAction SilentlyContinue)
$rig425WarnCount = $rig425Warn.Count
Write-Output ("PHI RIG425 FRESH WARNING LINES COUNT=" + $rig425WarnCount)
$rig425Warn | ForEach-Object { Write-Output ("FRESH LOAD LOG: " + $_.Line.Trim()) }
Write-Output '--- SECTION 4: VERDICT ---'
if ($rig425RefCount -eq 0 -and $rig425FreshStanding -eq 0 -and $rig425WarnCount -eq 0) {
  Write-Output ("PHI RIG425 VERDICT: RIG SLOT CLEARED carrier=" + $rig425CarrierName + " referencers=" + $rig425RefCount + " warnings=" + $rig425WarnCount)
} else {
  Copy-Item $rig425Backup $rig425Target -Force
  Write-Output 'PHI RIG425 SKELETON RESTORED reason=the fresh verification still shows the reference standing; the counts stand in the verdict line below'
  Write-Output ("PHI RIG425 VERDICT: RIG SLOT HELD - stage=fresh verification; referencers=" + $rig425RefCount + " fresh_carrier_standing=" + $rig425FreshStanding + " warnings=" + $rig425WarnCount + "; skeleton restored from the backup")
}
Write-Output 'JOB 425 DONE'
```
