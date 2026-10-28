<!-- PHI-DIRECT -->
```powershell
Write-Output '=== SEAT THE DISTRICT 413 - THE REGION NAMES WRITTEN INTO THE STREAMING DEFAULTS AND VERIFIED FROM A FRESH LOAD (Job 411 stands as the record: the District class resolves as /Script/VEIL.District, a native class, and its StreamingLevelNames property reads empty from the class default object, so the runtime district streams nothing because the names were never written. This job censuses every World asset under /Game from the asset registry, reads the district defaults again, and writes the census-proven region names that are not the persistent district map itself into the streaming defaults through the editor API, then verifies the write from a second fresh commandlet process. If the fresh read stands empty, the job falls back to a source write: the region names inserted into the District constructor with a backup taken first and the inserted lines read back, the editor target compiled, and a third fresh read taken after the compile. The verdict names DISTRICT SEATED VIA DEFAULTS or DISTRICT SEATED VIA SOURCE with the names standing in the fresh read, or DISTRICT HELD with both refusals printed as evidence.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 10) { Start-Sleep -Seconds 10; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'PHI DISTRICT413 NAMED HOLD: EDITOR STILL STANDING AFTER THE 100 SECOND IN-JOB WAIT - no commandlet launched into the contention'; Write-Output 'JOB 413 STOPPED'; return }
Write-Output 'PHI DISTRICT413 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road'
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output '--- SECTION 1: MAP CENSUS, DEFAULTS READ, SEATING WRITE (ROAD A) ---'
$pyA = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('aW1wb3J0IHVucmVhbAoKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHN0cihzKSArICdcbicpCgpkZWYgdGV4dF9vZih2KToKICAgIHRyeToKICAgICAgICByZXR1cm4gc3RyKHYpCiAgICBleGNlcHQgRXhjZXB0aW9uOgogICAgICAgIHJldHVybiAnJwoKZGVmIGZpZWxkKG9iaiwgbmFtZSk6CiAgICB0cnk6CiAgICAgICAgcmV0dXJuIGdldGF0dHIob2JqLCBuYW1lKQogICAgZXhjZXB0IEV4Y2VwdGlvbjoKICAgICAgICByZXR1cm4gTm9uZQoKYXNzZXRzID0gW10KdHJ5OgogICAgcmVnaXN0cnkgPSB1bnJlYWwuQXNzZXRSZWdpc3RyeUhlbHBlcnMuZ2V0X2Fzc2V0X3JlZ2lzdHJ5KCkKICAgIHRyeToKICAgICAgICBmb3VuZF9hc3NldHMgPSByZWdpc3RyeS5nZXRfYWxsX2Fzc2V0cygpCiAgICBleGNlcHQgRXhjZXB0aW9uOgogICAgICAgIGZvdW5kX2Fzc2V0cyA9IFtdCiAgICAgICAgZm9yIHBhY2thZ2VfcGF0aCBpbiB1bnJlYWwuRWRpdG9yQXNzZXRMaWJyYXJ5Lmxpc3RfYXNzZXRzKCcvR2FtZScsIHJlY3Vyc2l2ZT1UcnVlLCBpbmNsdWRlX2ZvbGRlcj1GYWxzZSk6CiAgICAgICAgICAgIHRyeToKICAgICAgICAgICAgICAgIGZvdW5kX2Fzc2V0cy5hcHBlbmQocmVnaXN0cnkuZ2V0X2Fzc2V0X2J5X3BhY2thZ2VfbmFtZShwYWNrYWdlX3BhdGgpKQogICAgICAgICAgICBleGNlcHQgRXhjZXB0aW9uOgogICAgICAgICAgICAgICAgcGFzcwogICAgZm9yIGRhdGEgaW4gZm91bmRfYXNzZXRzOgogICAgICAgIGlmIGRhdGEgaXMgTm9uZToKICAgICAgICAgICAgY29udGludWUKICAgICAgICBwYWNrYWdlID0gdGV4dF9vZihmaWVsZChkYXRhLCAncGFja2FnZV9uYW1lJykpCiAgICAgICAgbmFtZSA9IHRleHRfb2YoZmllbGQoZGF0YSwgJ2Fzc2V0X25hbWUnKSkKICAgICAgICBjbGFzc19wYXRoID0gZmllbGQoZGF0YSwgJ2Fzc2V0X2NsYXNzX3BhdGgnKQogICAgICAgIGNsYXNzX25hbWUgPSAnJwogICAgICAgIGlmIGNsYXNzX3BhdGggaXMgbm90IE5vbmU6CiAgICAgICAgICAgIGNsYXNzX25hbWUgPSB0ZXh0X29mKGZpZWxkKGNsYXNzX3BhdGgsICdhc3NldF9uYW1lJykpCiAgICAgICAgICAgIGlmIG5vdCBjbGFzc19uYW1lOgogICAgICAgICAgICAgICAgY2xhc3NfbmFtZSA9IHRleHRfb2YoY2xhc3NfcGF0aCkKICAgICAgICBhc3NldHMuYXBwZW5kKChwYWNrYWdlLCBuYW1lLCBjbGFzc19uYW1lKSkKZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgdygnUEhJIERJU1RSSUNUNDEzIFJFR0lTVFJZIEVSUk9SOiAnICsgc3RyKGUpKQoKd29ybGRzID0gc29ydGVkKFthIGZvciBhIGluIGFzc2V0cyBpZiBhWzJdID09ICdXb3JsZCcgYW5kIGFbMF0uc3RhcnRzd2l0aCgnL0dhbWUnKV0sIGtleT1sYW1iZGEgeDogeFswXSkKdygnUEhJIERJU1RSSUNUNDEzIE1BUCBDT1VOVD0nICsgc3RyKGxlbih3b3JsZHMpKSkKZm9yIHBhY2thZ2UsIG5hbWUsIGNsYXNzX25hbWUgaW4gd29ybGRzOgogICAgdygnUEhJIERJU1RSSUNUNDEzIE1BUCBwYWNrYWdlPScgKyBwYWNrYWdlICsgJyBuYW1lPScgKyBuYW1lKQoKY2xzID0gTm9uZQp0cnk6CiAgICBjbHMgPSB1bnJlYWwubG9hZF9jbGFzcyhOb25lLCAnL1NjcmlwdC9WRUlMLkRpc3RyaWN0JykKZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgdygnUEhJIERJU1RSSUNUNDEzIENMQVNTIExPQUQgRVJST1I6ICcgKyBzdHIoZSkpCmNkbyA9IE5vbmUKaWYgY2xzIGlzIG5vdCBOb25lOgogICAgdHJ5OgogICAgICAgIGNkbyA9IHVucmVhbC5nZXRfZGVmYXVsdF9vYmplY3QoY2xzKQogICAgZXhjZXB0IEV4Y2VwdGlvbjoKICAgICAgICB0cnk6CiAgICAgICAgICAgIGNkbyA9IGNscy5nZXRfZGVmYXVsdF9vYmplY3QoKQogICAgICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICAgICAgdygnUEhJIERJU1RSSUNUNDEzIENETyBFUlJPUjogJyArIHN0cihlKSkKaWYgY2RvIGlzIE5vbmU6CiAgICB3KCdQSEkgRElTVFJJQ1Q0MTMgVkVSRElDVDogQ0xBU1MgVU5SRVNPTFZFRCcpCmVsc2U6CiAgICBjdXJyZW50ID0gW10KICAgIHRyeToKICAgICAgICByYXcgPSBjZG8uZ2V0X2VkaXRvcl9wcm9wZXJ0eSgnc3RyZWFtaW5nX2xldmVsX25hbWVzJykKICAgICAgICBjdXJyZW50ID0gW3N0cih4KSBmb3IgeCBpbiByYXddIGlmIHJhdyBpcyBub3QgTm9uZSBlbHNlIFtdCiAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgdygnUEhJIERJU1RSSUNUNDEzIFJFQUQgRVJST1I6ICcgKyBzdHIoZSkpCiAgICAgICAgY3VycmVudCA9IFtdCiAgICB3KCdQSEkgRElTVFJJQ1Q0MTMgQkVGT1JFIENPVU5UPScgKyBzdHIobGVuKGN1cnJlbnQpKSkKICAgIGZvciB2IGluIGN1cnJlbnQ6CiAgICAgICAgdygnUEhJIERJU1RSSUNUNDEzIEJFRk9SRSBOQU1FOiAnICsgdikKICAgIHJlZ2lvbiA9IFthWzBdIGZvciBhIGluIHdvcmxkcyBpZiBhWzFdIGluICgnT01OSVdvcmxkJywgJ1ZFSUxXb3JsZCcpXQogICAgdygnUEhJIERJU1RSSUNUNDEzIE5BTUVTIFRPIFdSSVRFIENPVU5UPScgKyBzdHIobGVuKHJlZ2lvbikpKQogICAgZm9yIHYgaW4gcmVnaW9uOgogICAgICAgIHcoJ1BISSBESVNUUklDVDQxMyBXUklURSBOQU1FOiAnICsgdikKICAgIGlmIG5vdCByZWdpb246CiAgICAgICAgdygnUEhJIERJU1RSSUNUNDEzIFNFVCBTS0lQUEVEOiBOTyBDRU5TVVMtUFJPVkVOIFJFR0lPTiBNQVBTJykKICAgIGVsc2U6CiAgICAgICAgdHJ5OgogICAgICAgICAgICBjZG8uc2V0X2VkaXRvcl9wcm9wZXJ0eSgnc3RyZWFtaW5nX2xldmVsX25hbWVzJywgcmVnaW9uKQogICAgICAgICAgICB3KCdQSEkgRElTVFJJQ1Q0MTMgU0VUIE9LJykKICAgICAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgICAgIHcoJ1BISSBESVNUUklDVDQxMyBTRVQgRVJST1I6ICcgKyBzdHIoZSkpCiAgICAgICAgdHJ5OgogICAgICAgICAgICBiYWNrID0gY2RvLmdldF9lZGl0b3JfcHJvcGVydHkoJ3N0cmVhbWluZ19sZXZlbF9uYW1lcycpCiAgICAgICAgICAgIGJhY2sgPSBbc3RyKHgpIGZvciB4IGluIGJhY2tdIGlmIGJhY2sgaXMgbm90IE5vbmUgZWxzZSBbXQogICAgICAgICAgICB3KCdQSEkgRElTVFJJQ1Q0MTMgQUZURVIgU0VUIENPVU5UPScgKyBzdHIobGVuKGJhY2spKSkKICAgICAgICAgICAgZm9yIHYgaW4gYmFjazoKICAgICAgICAgICAgICAgIHcoJ1BISSBESVNUUklDVDQxMyBBRlRFUiBTRVQgTkFNRTogJyArIHYpCiAgICAgICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgICAgICAgICB3KCdQSEkgRElTVFJJQ1Q0MTMgQUZURVIgU0VUIFJFQUQgRVJST1I6ICcgKyBzdHIoZSkpCiAgICAgICAgdHJ5OgogICAgICAgICAgICBzYXZlZCA9IHVucmVhbC5FZGl0b3JBc3NldExpYnJhcnkuc2F2ZV9sb2FkZWRfYXNzZXQoY2RvKQogICAgICAgICAgICB3KCdQSEkgRElTVFJJQ1Q0MTMgU0FWRSBMT0FERUQgQVNTRVQgUkVTVUxUOiAnICsgc3RyKHNhdmVkKSkKICAgICAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgICAgIHcoJ1BISSBESVNUUklDVDQxMyBTQVZFIEVSUk9SOiAnICsgc3RyKGUpKQp3KCdQSEkgRElTVFJJQ1Q0MTMgQ09NUExFVEUnKQpvdXQuY2xvc2UoKQo='))
$outA = "$base\Saved\phi_district413_a.txt"
$pyA = $pyA.Replace('OUTFILE', "'$outA'")
Set-Content "$base\Saved\phi_district413_a.py" -Value $pyA -Encoding UTF8
Remove-Item $outA -ErrorAction SilentlyContinue
& $cmdexe $uproj -run=pythonscript -script="$base\Saved\phi_district413_a.py" -unattended -nopause -nosplash *> "$base\Saved\district413_a.log"
if (Test-Path $outA) { Get-Content $outA | Write-Output } else { Write-Output 'NO DISTRICT413 A OUTPUT FILE'; Select-String -Path "$base\Saved\district413_a.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 8 | ForEach-Object { $_.Line.Trim() } | Write-Output }
Write-Output '--- SECTION 2: FRESH READ (ROAD A VERDICT) ---'
$pyB = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('aW1wb3J0IHVucmVhbAoKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHN0cihzKSArICdcbicpCgpjbHMgPSBOb25lCnRyeToKICAgIGNscyA9IHVucmVhbC5sb2FkX2NsYXNzKE5vbmUsICcvU2NyaXB0L1ZFSUwuRGlzdHJpY3QnKQpleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICB3KCdQSEkgRElTVFJJQ1Q0MTMgRlJFU0ggQ0xBU1MgTE9BRCBFUlJPUjogJyArIHN0cihlKSkKY2RvID0gTm9uZQppZiBjbHMgaXMgbm90IE5vbmU6CiAgICB0cnk6CiAgICAgICAgY2RvID0gdW5yZWFsLmdldF9kZWZhdWx0X29iamVjdChjbHMpCiAgICBleGNlcHQgRXhjZXB0aW9uOgogICAgICAgIHRyeToKICAgICAgICAgICAgY2RvID0gY2xzLmdldF9kZWZhdWx0X29iamVjdCgpCiAgICAgICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgICAgICAgICB3KCdQSEkgRElTVFJJQ1Q0MTMgRlJFU0ggQ0RPIEVSUk9SOiAnICsgc3RyKGUpKQp2YWxzID0gW10KaWYgY2RvIGlzIG5vdCBOb25lOgogICAgdHJ5OgogICAgICAgIHJhdyA9IGNkby5nZXRfZWRpdG9yX3Byb3BlcnR5KCdzdHJlYW1pbmdfbGV2ZWxfbmFtZXMnKQogICAgICAgIHZhbHMgPSBbc3RyKHgpIGZvciB4IGluIHJhd10gaWYgcmF3IGlzIG5vdCBOb25lIGVsc2UgW10KICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICB3KCdQSEkgRElTVFJJQ1Q0MTMgRlJFU0ggUkVBRCBFUlJPUjogJyArIHN0cihlKSkKdygnUEhJIERJU1RSSUNUNDEzIEZSRVNIIFJFQUQgQ09VTlQ9JyArIHN0cihsZW4odmFscykpKQpmb3IgdiBpbiB2YWxzOgogICAgdygnUEhJIERJU1RSSUNUNDEzIEZSRVNIIE5BTUU6ICcgKyB2KQp3KCdQSEkgRElTVFJJQ1Q0MTMgRlJFU0ggQ09NUExFVEUnKQpvdXQuY2xvc2UoKQo='))
$outB = "$base\Saved\phi_district413_fresh.txt"
$pyB = $pyB.Replace('OUTFILE', "'$outB'")
Set-Content "$base\Saved\phi_district413_fresh.py" -Value $pyB -Encoding UTF8
Remove-Item $outB -ErrorAction SilentlyContinue
& $cmdexe $uproj -run=pythonscript -script="$base\Saved\phi_district413_fresh.py" -unattended -nopause -nosplash *> "$base\Saved\district413_fresh.log"
if (Test-Path $outB) { Get-Content $outB | Write-Output } else { Write-Output 'NO DISTRICT413 FRESH OUTPUT FILE'; Select-String -Path "$base\Saved\district413_fresh.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 8 | ForEach-Object { $_.Line.Trim() } | Write-Output }
$freshCount = 0
$freshNames = @()
if (Test-Path $outB) {
  $countLine = Select-String -Path $outB -Pattern 'FRESH READ COUNT=(\d+)' | Select-Object -First 1
  if ($countLine) { $freshCount = [int]$countLine.Matches[0].Groups[1].Value }
  $freshNames = @(Select-String -Path $outB -Pattern 'FRESH NAME: ' | ForEach-Object { $_.Line -replace '.*FRESH NAME: ', '' })
}
if ($freshCount -gt 0) {
  Write-Output ('PHI DISTRICT413 VERDICT: DISTRICT SEATED VIA DEFAULTS names=[' + ($freshNames -join ', ') + ']')
  Write-Output 'JOB 413 DONE'
  return
}
Write-Output 'PHI DISTRICT413 ROAD A: FRESH READ EMPTY - the defaults did not persist; road B runs'
Write-Output '--- SECTION 3: ROAD B - SOURCE CONSTRUCTOR WRITE ---'
$regionPkgs = @()
if (Test-Path $outA) {
  foreach ($hitLine in (Select-String -Path $outA -Pattern 'MAP package=')) {
    $mm = [regex]::Match($hitLine.Line, 'package=(\S+) name=(\S+)')
    if ($mm.Success -and ($mm.Groups[2].Value -eq 'OMNIWorld' -or $mm.Groups[2].Value -eq 'VEILWorld')) { $regionPkgs += $mm.Groups[1].Value }
  }
}
Write-Output ('PHI DISTRICT413 ROAD B REGION COUNT=' + $regionPkgs.Count)
foreach ($p in $regionPkgs) { Write-Output ('PHI DISTRICT413 ROAD B REGION: ' + $p) }
$cppFiles = Get-ChildItem "$base\Source" -Recurse -File -Include '*.cpp' | Where-Object { $_.Name -like '*District*' }
if ((-not $cppFiles) -or $regionPkgs.Count -eq 0) {
  Write-Output 'PHI DISTRICT413 VERDICT: DISTRICT HELD - road A fresh read empty (evidence above); road B found no District cpp or no census-proven region names'
  Write-Output 'JOB 413 DONE'
  return
}
$cpp = $cppFiles[0]
Write-Output ('PHI DISTRICT413 ROAD B FILE: ' + $cpp.FullName)
$backup = $cpp.FullName + '.phi-backup-413'
Copy-Item $cpp.FullName $backup -Force
Write-Output ('PHI DISTRICT413 BACKUP WRITTEN: ' + $backup)
$lines = @(Get-Content $cpp.FullName)
$ctorIdx = -1
for ($i = 0; $i -lt $lines.Count; $i++) { if ($lines[$i] -match 'ADistrict::ADistrict') { $ctorIdx = $i; break } }
if ($ctorIdx -lt 0) {
  Write-Output 'PHI DISTRICT413 VERDICT: DISTRICT HELD - no ADistrict constructor line found in the District cpp; the backup stands untouched beside it'
  Write-Output 'JOB 413 DONE'
  return
}
$braceIdx = -1
for ($i = $ctorIdx; $i -lt $lines.Count; $i++) { if ($lines[$i].Contains('{')) { $braceIdx = $i; break } }
if ($braceIdx -lt 0) {
  Write-Output 'PHI DISTRICT413 VERDICT: DISTRICT HELD - no constructor opening brace found in the District cpp; the backup stands untouched beside it'
  Write-Output 'JOB 413 DONE'
  return
}
$insert = @()
foreach ($p in $regionPkgs) { $insert += ('    StreamingLevelNames.Add(TEXT("' + $p + '"));') }
$newLines = @()
$newLines += $lines[0..$braceIdx]
$newLines += $insert
if ($braceIdx + 1 -lt $lines.Count) { $newLines += $lines[($braceIdx + 1)..($lines.Count - 1)] }
Set-Content $cpp.FullName -Value $newLines -Encoding UTF8
Write-Output 'PHI DISTRICT413 INSERTED LINES READ BACK:'
Select-String -Path $cpp.FullName -Pattern 'StreamingLevelNames' | ForEach-Object { Write-Output ($_.LineNumber.ToString() + ': ' + $_.Line.Trim()) }
Write-Output '--- SECTION 4: COMPILE (ROAD B, PART 1) ---'
$buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
& $buildbat VEILEditor Win64 Development -Project="$uproj" -WaitMutex -NoHotReload *> "$base\Saved\build413.log"
$buildCode = $LASTEXITCODE
if ($buildCode -ne 0) {
  Write-Output ('PHI DISTRICT413 BUILD FAILED code=' + $buildCode)
  Select-String -Path "$base\Saved\build413.log" -Pattern 'error|Error|FAILED' | Select-Object -Last 12 | ForEach-Object { $_.Line.Trim() } | Write-Output
  Copy-Item $backup $cpp.FullName -Force
  Write-Output 'PHI DISTRICT413 SOURCE RESTORED FROM BACKUP AFTER COMPILE FAILURE'
  Write-Output 'PHI DISTRICT413 VERDICT: DISTRICT HELD - road A fresh read empty; road B compile failed (compiler lines above); source restored from the backup'
  Write-Output 'JOB 413 DONE'
  return
}
Write-Output 'PHI DISTRICT413 BUILD SUCCEEDED'
Write-Output '--- SECTION 5: FRESH READ AFTER COMPILE (ROAD B VERDICT) ---'
$pyC = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('aW1wb3J0IHVucmVhbAoKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHN0cihzKSArICdcbicpCgpjbHMgPSBOb25lCnRyeToKICAgIGNscyA9IHVucmVhbC5sb2FkX2NsYXNzKE5vbmUsICcvU2NyaXB0L1ZFSUwuRGlzdHJpY3QnKQpleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICB3KCdQSEkgRElTVFJJQ1Q0MTMgRlJFU0ggQ0xBU1MgTE9BRCBFUlJPUjogJyArIHN0cihlKSkKY2RvID0gTm9uZQppZiBjbHMgaXMgbm90IE5vbmU6CiAgICB0cnk6CiAgICAgICAgY2RvID0gdW5yZWFsLmdldF9kZWZhdWx0X29iamVjdChjbHMpCiAgICBleGNlcHQgRXhjZXB0aW9uOgogICAgICAgIHRyeToKICAgICAgICAgICAgY2RvID0gY2xzLmdldF9kZWZhdWx0X29iamVjdCgpCiAgICAgICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgICAgICAgICB3KCdQSEkgRElTVFJJQ1Q0MTMgRlJFU0ggQ0RPIEVSUk9SOiAnICsgc3RyKGUpKQp2YWxzID0gW10KaWYgY2RvIGlzIG5vdCBOb25lOgogICAgdHJ5OgogICAgICAgIHJhdyA9IGNkby5nZXRfZWRpdG9yX3Byb3BlcnR5KCdzdHJlYW1pbmdfbGV2ZWxfbmFtZXMnKQogICAgICAgIHZhbHMgPSBbc3RyKHgpIGZvciB4IGluIHJhd10gaWYgcmF3IGlzIG5vdCBOb25lIGVsc2UgW10KICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICB3KCdQSEkgRElTVFJJQ1Q0MTMgRlJFU0ggUkVBRCBFUlJPUjogJyArIHN0cihlKSkKdygnUEhJIERJU1RSSUNUNDEzIEZSRVNIIFJFQUQgQ09VTlQ9JyArIHN0cihsZW4odmFscykpKQpmb3IgdiBpbiB2YWxzOgogICAgdygnUEhJIERJU1RSSUNUNDEzIEZSRVNIIE5BTUU6ICcgKyB2KQp3KCdQSEkgRElTVFJJQ1Q0MTMgRlJFU0ggQ09NUExFVEUnKQpvdXQuY2xvc2UoKQo='))
$outC = "$base\Saved\phi_district413_fresh2.txt"
$pyC = $pyC.Replace('OUTFILE', "'$outC'")
Set-Content "$base\Saved\phi_district413_fresh2.py" -Value $pyC -Encoding UTF8
Remove-Item $outC -ErrorAction SilentlyContinue
& $cmdexe $uproj -run=pythonscript -script="$base\Saved\phi_district413_fresh2.py" -unattended -nopause -nosplash *> "$base\Saved\district413_fresh2.log"
if (Test-Path $outC) { Get-Content $outC | Write-Output } else { Write-Output 'NO DISTRICT413 FRESH2 OUTPUT FILE'; Select-String -Path "$base\Saved\district413_fresh2.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 8 | ForEach-Object { $_.Line.Trim() } | Write-Output }
$fresh2Count = 0
$fresh2Names = @()
if (Test-Path $outC) {
  $countLine2 = Select-String -Path $outC -Pattern 'FRESH READ COUNT=(\d+)' | Select-Object -First 1
  if ($countLine2) { $fresh2Count = [int]$countLine2.Matches[0].Groups[1].Value }
  $fresh2Names = @(Select-String -Path $outC -Pattern 'FRESH NAME: ' | ForEach-Object { $_.Line -replace '.*FRESH NAME: ', '' })
}
if ($fresh2Count -gt 0) {
  Write-Output ('PHI DISTRICT413 VERDICT: DISTRICT SEATED VIA SOURCE names=[' + ($fresh2Names -join ', ') + ']')
} else {
  Write-Output 'PHI DISTRICT413 VERDICT: DISTRICT HELD - road A fresh read empty; road B compiled clean but the fresh read still stands empty'
}
Write-Output 'JOB 413 DONE'
```
