<!-- PHI-DIRECT -->
```powershell
Write-Output '=== SKELETON RIG PROPERTY NAME 424 - THE TRUE NAME OF THE RIG SLOT READ FROM THE SKELETON BYTES AROUND THE RIGCONFIG STRINGS AND FROM THE LOADED OBJECT ITSELF (Ground from job 422, read whole: clearing the Countess skeleton RigConfig slot held because the editor Python property read could not find the property under the names probed, rig_config and RigConfig, the read answering Failed to find property for attribute on Skeleton, and the skeleton was restored from its backup byte-identical at SHA-256 0513a4f18326f56412323568a6865fb61425d22706c55e4c40aa638471dbb941. Ground from job 420 stands beside it: the skeleton bytes carry the string RigConfig at offset 4884 and a RigConfiguration string at offset 4902, so a rig slot exists in the package even where the Python names missed it. One, the byte context prints every ASCII string standing within offsets 4600 to 5300 of the skeleton file, in file order with offsets, so the names neighbouring the two rig strings stand in print whole. Two, a pythonscript commandlet loads the skeleton and prints every attribute name the loaded object exposes through Python introspection carrying rig, config, skeleton, or retarget, uncapped and with the match count, then attempts get_editor_property on each candidate name in turn, RigConfig, rig_config, RigConfiguration, rig_configuration, Rig, and rig, printing HIT with the value rendered or MISS with the denial. Three, the loaded class property names carrying rig or config print the same way where the API offers that list, with the refusal printed where it does not. Four, the verdict in one line: PROPERTY FOUND with the exact name and its rendered value, or PROPERTY NOT EXPOSED with the introspection counts, so the clearing job that follows uses the name the engine itself answers to. Read-only throughout, the editor guard waits inside the job on the standing 100 second bound with a named hold, and every variable carries the rig424 prefix under the standing ban on automatic variable names.) ==='
$rig424Waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $rig424Waited -lt 10) { Start-Sleep -Seconds 10; $rig424Waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'PHI RIG424 NAMED HOLD: EDITOR STILL STANDING AFTER THE 100 SECOND IN-JOB WAIT - no commandlet launched into the contention'; Write-Output 'JOB 424 STOPPED'; return }
Write-Output 'PHI RIG424 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road'
$rig424Base = 'D:\VEIL-OMNI'
$rig424Uproj = "$rig424Base\VEIL.uproject"
$rig424CmdExe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$rig424MeshFolder = "$rig424Base\Content\ParagonCountess\Characters\Heroes\Countess\Meshes"
$rig424Target = Join-Path $rig424MeshFolder 'S_Countess_Skeleton.uasset'
if (-not (Test-Path $rig424Target)) {
  $rig424HitFile = Get-ChildItem (Join-Path $rig424Base 'Content') -Recurse -Filter 'S_Countess_Skeleton.uasset' -File -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($rig424HitFile) { $rig424Target = $rig424HitFile.FullName } else { $rig424Target = '' }
}
Write-Output '--- SECTION 1: BYTE CONTEXT OFFSETS 4600 TO 5300 ---'
if ($rig424Target -eq '') {
  Write-Output 'SKELETON FILE NOT FOUND UNDER THE MERGED BASE CONTENT TREE'
  Write-Output 'PHI RIG424 VERDICT: PROPERTY NOT EXPOSED - the skeleton file was not found, so no byte context and no property read could run'
  Write-Output 'JOB 424 DONE'
  return
}
Write-Output ("PHI RIG424 TARGET FILE: " + $rig424Target)
$rig424Bytes = [System.IO.File]::ReadAllBytes($rig424Target)
Write-Output ("PHI RIG424 SIZE BYTES=" + $rig424Bytes.Length)
$rig424RunStart = -1
$rig424RunText = ''
$rig424RangeCount = 0
for ($rig424I = 0; $rig424I -le $rig424Bytes.Length; $rig424I++) {
  $rig424Printable = 0
  if ($rig424I -lt $rig424Bytes.Length) {
    $rig424B = $rig424Bytes[$rig424I]
    if ($rig424B -ge 32 -and $rig424B -le 126) { $rig424Printable = 1 }
  }
  if ($rig424Printable -eq 1) {
    if ($rig424RunStart -lt 0) { $rig424RunStart = $rig424I; $rig424RunText = '' }
    $rig424RunText += [char]$rig424B
  } else {
    if ($rig424RunStart -ge 0 -and $rig424RunText.Length -ge 4) {
      if ($rig424RunStart -ge 4600 -and $rig424RunStart -le 5300) {
        Write-Output ("STRING @" + $rig424RunStart + ": " + $rig424RunText)
        $rig424RangeCount++
      }
    }
    $rig424RunStart = -1
    $rig424RunText = ''
  }
}
Write-Output ("RANGE STRING COUNT=" + $rig424RangeCount)
Write-Output '--- SECTION 2: PROPERTY ENUMERATION IN THE COMMANDLET ---'
$rig424Py = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('aW1wb3J0IHVucmVhbAoKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHN0cihzKSArICdcbicpCgpTS0VMID0gJy9HYW1lL1BhcmFnb25Db3VudGVzcy9DaGFyYWN0ZXJzL0hlcm9lcy9Db3VudGVzcy9NZXNoZXMvU19Db3VudGVzc19Ta2VsZXRvbicKCmRlZiByZW5kZXJfdmFsKHYpOgogICAgaWYgdiBpcyBOb25lOgogICAgICAgIHJldHVybiAnTk9ORScKICAgIHRyeToKICAgICAgICByZXR1cm4gdi5nZXRfcGF0aF9uYW1lKCkKICAgIGV4Y2VwdCBFeGNlcHRpb246CiAgICAgICAgcmV0dXJuIHN0cih2KVs6MjQwXQoKc2tlbCA9IE5vbmUKbG9hZF9ub3RlID0gJycKdHJ5OgogICAgc2tlbCA9IHVucmVhbC5FZGl0b3JBc3NldExpYnJhcnkubG9hZF9hc3NldChTS0VMKQpleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICBsb2FkX25vdGUgPSAnbG9hZCByZWZ1c2VkOiAnICsgc3RyKGUpCmlmIHNrZWwgaXMgTm9uZToKICAgIHcoJ1BISSBSSUc0MjQgTE9BRCBPSz0wJykKICAgIGlmIGxvYWRfbm90ZToKICAgICAgICB3KCdQSEkgUklHNDI0IExPQUQgTk9URTogJyArIGxvYWRfbm90ZSkKZWxzZToKICAgIHcoJ1BISSBSSUc0MjQgTE9BRCBPSz0xJykKICAgIHRyeToKICAgICAgICBjbHMgPSBza2VsLmdldF9jbGFzcygpCiAgICAgICAgdygnUEhJIFJJRzQyNCBMT0FERUQgQ0xBU1M9JyArIGNscy5nZXRfbmFtZSgpKQogICAgICAgIHcoJ1BISSBSSUc0MjQgTE9BREVEIENMQVNTIFBBVEg9JyArIGNscy5nZXRfcGF0aF9uYW1lKCkpCiAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgdygnUEhJIFJJRzQyNCBMT0FERUQgQ0xBU1MgVU5SRUFEQUJMRTogJyArIHN0cihlKVs6MjQwXSkKICAgIGtleXMgPSAoJ3JpZycsICdjb25maWcnLCAnc2tlbGV0b24nLCAncmV0YXJnZXQnKQogICAgbmFtZXMgPSBbXQogICAgdHJ5OgogICAgICAgIG5hbWVzID0gW24gZm9yIG4gaW4gZGlyKHNrZWwpIGlmIGFueShrIGluIG4ubG93ZXIoKSBmb3IgayBpbiBrZXlzKV0KICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICB3KCdQSEkgUklHNDI0IElOVFJPU1BFQ1RJT04gREVOSUFMOiAnICsgc3RyKGUpWzoyNDBdKQogICAgdygnUEhJIFJJRzQyNCBJTlRST1NQRUNUSU9OIE1BVENIIENPVU5UPScgKyBzdHIobGVuKG5hbWVzKSkpCiAgICBmb3IgbiBpbiBzb3J0ZWQobmFtZXMpOgogICAgICAgIHcoJ1BISSBSSUc0MjQgQVRUUjogJyArIG4pCiAgICBmb3IgY2FuZCBpbiAoJ1JpZ0NvbmZpZycsICdyaWdfY29uZmlnJywgJ1JpZ0NvbmZpZ3VyYXRpb24nLCAncmlnX2NvbmZpZ3VyYXRpb24nLCAnUmlnJywgJ3JpZycpOgogICAgICAgIHRyeToKICAgICAgICAgICAgdiA9IHNrZWwuZ2V0X2VkaXRvcl9wcm9wZXJ0eShjYW5kKQogICAgICAgICAgICB3KCdQSEkgUklHNDI0IEhJVCAnICsgY2FuZCArICcgdmFsdWU9JyArIHJlbmRlcl92YWwodikpCiAgICAgICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgICAgICAgICB3KCdQSEkgUklHNDI0IE1JU1MgJyArIGNhbmQgKyAnIGRlbmlhbD0nICsgc3RyKGUpWzoyNDBdKQogICAgdHJ5OgogICAgICAgIGNsczIgPSBza2VsLmdldF9jbGFzcygpCiAgICAgICAgY25hbWVzID0gW24gZm9yIG4gaW4gZGlyKGNsczIpIGlmIGFueShrIGluIG4ubG93ZXIoKSBmb3IgayBpbiBrZXlzKV0KICAgICAgICB3KCdQSEkgUklHNDI0IENMQVNTIEFUVFIgTUFUQ0ggQ09VTlQ9JyArIHN0cihsZW4oY25hbWVzKSkpCiAgICAgICAgZm9yIG4gaW4gc29ydGVkKGNuYW1lcyk6CiAgICAgICAgICAgIHcoJ1BISSBSSUc0MjQgQ0xBU1MgQVRUUjogJyArIG4pCiAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgdygnUEhJIFJJRzQyNCBDTEFTUyBMSVNUIFVOQVZBSUxBQkxFOiAnICsgc3RyKGUpWzoyNDBdKQp3KCdQSEkgUklHNDI0IFJFQUQgQ09NUExFVEUnKQpvdXQuY2xvc2UoKQo='))
$rig424Out = "$rig424Base\Saved\phi_rig424.txt"
$rig424Py = $rig424Py.Replace('OUTFILE', "'$rig424Out'")
Set-Content "$rig424Base\Saved\phi_rig424.py" -Value $rig424Py -Encoding UTF8
Remove-Item $rig424Out -ErrorAction SilentlyContinue
& $rig424CmdExe $rig424Uproj -run=pythonscript -script="$rig424Base\Saved\phi_rig424.py" -unattended -nopause -nosplash *> "$rig424Base\Saved\rig424.log"
$rig424HitName = ''
$rig424HitValue = ''
$rig424IntroCount = -1
$rig424MissCount = 0
if (Test-Path $rig424Out) {
  $rig424Lines = @(Get-Content $rig424Out)
  $rig424Lines | Write-Output
  $rig424LineIntro = $rig424Lines | Where-Object { $_ -like 'PHI RIG424 INTROSPECTION MATCH COUNT=*' } | Select-Object -First 1
  if ($rig424LineIntro) { $rig424IntroCount = [int]($rig424LineIntro.Substring($rig424LineIntro.IndexOf('=') + 1).Trim()) }
  $rig424LineHit = $rig424Lines | Where-Object { $_ -like 'PHI RIG424 HIT *' } | Select-Object -First 1
  if ($rig424LineHit) {
    $rig424HitRest = $rig424LineHit.Substring('PHI RIG424 HIT '.Length)
    $rig424HitSplit = $rig424HitRest.IndexOf(' value=')
    if ($rig424HitSplit -ge 0) { $rig424HitName = $rig424HitRest.Substring(0, $rig424HitSplit); $rig424HitValue = $rig424HitRest.Substring($rig424HitSplit + 7) } else { $rig424HitName = $rig424HitRest }
  }
  $rig424MissLines = @($rig424Lines | Where-Object { $_ -like 'PHI RIG424 MISS *' })
  $rig424MissCount = $rig424MissLines.Count
} else {
  Write-Output 'NO RIG424 OUTPUT FILE'
  Select-String -Path "$rig424Base\Saved\rig424.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 8 | ForEach-Object { $_.Line.Trim() } | Write-Output
}
Write-Output '--- SECTION 3: VERDICT ---'
if ($rig424HitName) {
  Write-Output ("PHI RIG424 VERDICT: PROPERTY FOUND name=" + $rig424HitName + " value=" + $rig424HitValue)
} else {
  Write-Output ("PHI RIG424 VERDICT: PROPERTY NOT EXPOSED introspection_matches=" + $rig424IntroCount + " candidate_misses=" + $rig424MissCount)
}
Write-Output 'JOB 424 DONE'
```
