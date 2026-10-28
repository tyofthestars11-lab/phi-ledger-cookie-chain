<!-- PHI-DIRECT -->
```powershell
Write-Output '=== DT DIALOGUE MERGE REROUTE 376 - THE TABLE COMES OUT OF THE ARCHIVE AND THE 37 ROWS STAND (Job 362 stopped at its export half: loading the OMNI-UE DT_Dialogue returned None, because job 358 and its KRAKEN pack had already packed that asset into D:\VEIL-OMNI-ARCHIVE - the table was never lost, it stands packed with its manifest proof. Job 355 printed the API census this merge rides: the DataTable carries export_to_json_string and fill_from_json_string natively, and both tables share the one struct PHIDialogueRow with fields Speaker and Line - VEIL rows V01 to V19 in the base, OMNI rows O01 to O18 in the parent. THIS JOB, one motion: one, find the packed DT_Dialogue inside the archive by filename search and by the KRAKEN manifest, and print what stands. Two, restore it to its original path under D:\OMNI-UE Content with the kraken tooling the lane shipped for job 358, copied never moved out of the archive, and print the restored byte count. Three, export the OMNI table in its own project and the base table in the merged base at D:\VEIL-OMNI through export_to_json_string, print both struct names and both row censuses, and stop before any write if either load fails or a struct name differs from PHIDialogueRow. Four, merge with VEIL rows kept and OMNI rows appended only where the row name stands absent, print any skip, fill the base table from the merged JSON, save the base asset, and print the full merged census with the total count - 37 rows is the shape of done.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 376 DEFERRED'; return }
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$base = 'D:\VEIL-OMNI'
$arch = 'D:\VEIL-OMNI-ARCHIVE'
$omniDT = 'D:\OMNI-UE\Content\Data\DT_Dialogue.uasset'
$baseDT = "$base\Content\Data\DT_Dialogue.uasset"
Write-Output '--- SECTION 1: LOCATE THE PACKED TABLE IN THE ARCHIVE ---'
if (-not (Test-Path $arch)) { Write-Output 'ARCHIVE ROOT ABSENT'; Write-Output 'JOB 376 STOPPED'; return }
$hits = Get-ChildItem $arch -Recurse -File -ErrorAction SilentlyContinue | Where-Object { $_.Name -like '*DT_Dialogue*' }
foreach ($h in $hits) { Write-Output ("PHI DT376 ARCHIVE HIT: " + $h.FullName + ' bytes=' + $h.Length) }
if (-not $hits) { Write-Output 'PHI DT376 NO DT_Dialogue FILENAME STANDS IN THE ARCHIVE' }
$man = "$arch\KRAKEN_MANIFEST.json"
if (Test-Path $man) {
  Write-Output "PHI DT376 MANIFEST STANDS: $man"
  Select-String -Path $man -Pattern 'DT_Dialogue' | ForEach-Object { $_.Line.Trim() } | Write-Output
} else { Write-Output 'PHI DT376 KRAKEN MANIFEST ABSENT AT ARCHIVE ROOT' }
Write-Output '--- SECTION 2: RESTORE TO THE ORIGINAL PATH ---'
$needRestore = $true
if (Test-Path $omniDT) {
  $lenNow = (Get-Item $omniDT).Length
  Write-Output "PHI DT376 TABLE ALREADY STANDS AT ORIGINAL PATH bytes=$lenNow"
  $needRestore = $false
}
if ($needRestore) {
  $krkHit = $hits | Where-Object { $_.Name -eq 'DT_Dialogue.uasset.krk' -and $_.FullName -like '*\OMNI-UE\*' } | Select-Object -First 1
  if (-not $krkHit) { $krkHit = $hits | Where-Object { $_.Name -eq 'DT_Dialogue.uasset.krk' } | Select-Object -First 1 }
  $rawHit = $hits | Where-Object { $_.Name -eq 'DT_Dialogue.uasset' } | Select-Object -First 1
  if ($krkHit) {
    $tools = 'C:\Users\Admin\phi-vault\phi-dlam\tools\kraken_ton618.py'
    if (-not (Test-Path $tools)) { $tools = (Get-ChildItem 'C:\Users\Admin' -Recurse -Depth 5 -Filter 'kraken_ton618.py' -File -ErrorAction SilentlyContinue | Select-Object -First 1 -ExpandProperty FullName) }
    if (-not $tools) { Write-Output 'KRAKEN TOOLING FILE NOT FOUND ON THIS PC'; Write-Output 'JOB 376 STOPPED'; return }
    Write-Output "KRAKEN TOOL: $tools"
    $py = (Get-Command python -ErrorAction SilentlyContinue).Source
    if (-not $py) { $py = (Get-Command py -ErrorAction SilentlyContinue).Source }
    if (-not $py) { Write-Output 'PYTHON NOT FOUND'; Write-Output 'JOB 376 STOPPED'; return }
    Write-Output "PYTHON: $py"
    & $py -c "import numpy, zstandard; print('PHI KRAKEN DEPS OK')" 2>&1 | Write-Output
    if ($LASTEXITCODE -ne 0) {
      Write-Output 'DEPS MISSING - one install attempt'
      & $py -m pip install numpy zstandard 2>&1 | Select-Object -Last 3 | Write-Output
      & $py -c "import numpy, zstandard; print('PHI KRAKEN DEPS OK AFTER INSTALL')" 2>&1 | Write-Output
      if ($LASTEXITCODE -ne 0) { Write-Output 'TOOLING NOT READY - nothing restored.'; Write-Output 'JOB 376 STOPPED'; return }
    }
    $toolsDirFwd = (Split-Path $tools) -replace '\\', '/'
    $krkFwd = ($krkHit.FullName) -replace '\\', '/'
    $destKrk = 'D:\OMNI-UE\Content\Data\DT_Dialogue.uasset.krk'
    $destKrkFwd = $destKrk -replace '\\', '/'
    $outRestore = 'D:\OMNI-UE\Saved\phi_dt376_restore_out.txt'
    $pyR = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('aW1wb3J0IG9zLCBzeXMKc3lzLnBhdGguaW5zZXJ0KDAsIFRPT0xTRElSKQpvdXQgPSBvcGVuKE9VVEZJTEUsICd3JykKZGVmIHcocyk6IG91dC53cml0ZShzICsgJ1xuJykKdHJ5OgogICAgaW1wb3J0IHNodXRpbAogICAgaW1wb3J0IGtyYWtlbl90b242MTggYXMga3Jha2VuCiAgICBkZXN0ZGlyID0gb3MucGF0aC5kaXJuYW1lKERFU1RLUkspCiAgICBpZiBkZXN0ZGlyOgogICAgICAgIG9zLm1ha2VkaXJzKGRlc3RkaXIsIGV4aXN0X29rPVRydWUpCiAgICBzaHV0aWwuY29weWZpbGUoS1JLUEFUSCwgREVTVEtSSykKICAgIG9yaWcgPSBrcmFrZW4udW5wYWNrX2ZpbGUoREVTVEtSSykKICAgIHcoJ1BISSBEVDM3NiBSRVNUT1JFRDogJyArIG9yaWcgKyAnIGJ5dGVzPScgKyBzdHIob3MucGF0aC5nZXRzaXplKG9yaWcpKSkKZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgdygnUEhJIERUMzc2IFJFU1RPUkUgRVJST1I6ICcgKyBzdHIoZSkpCm91dC5jbG9zZSgpCg=='))
    $pyR = $pyR.Replace('DESTKRK', "'" + $destKrkFwd + "'").Replace('KRKPATH', "'" + $krkFwd + "'").Replace('TOOLSDIR', "'" + $toolsDirFwd + "'").Replace('OUTFILE', "'" + ($outRestore -replace '\\', '/') + "'")
    Set-Content 'D:\OMNI-UE\Saved\phi_dt376_restore.py' -Value $pyR -Encoding UTF8
    Remove-Item $outRestore -ErrorAction SilentlyContinue
    & $py 'D:\OMNI-UE\Saved\phi_dt376_restore.py' 2>&1 | Write-Output
    if (Test-Path $outRestore) { Get-Content $outRestore | Write-Output } else { Write-Output 'NO DT376 RESTORE OUTPUT FILE'; Write-Output 'JOB 376 STOPPED'; return }
  } elseif ($rawHit) {
    $destDir = Split-Path $omniDT
    if (-not (Test-Path $destDir)) { New-Item -ItemType Directory -Path $destDir -Force | Out-Null }
    Copy-Item $rawHit.FullName $omniDT -Force
    Write-Output "PHI DT376 RESTORED FROM KEPT-RAW ARCHIVE COPY: $omniDT"
  } else {
    Write-Output 'PHI DT376 NO PACKED OR KEPT-RAW TABLE FOUND - nothing to restore.'
    Write-Output 'JOB 376 STOPPED'; return
  }
  if (Test-Path $omniDT) {
    $restoredLen = (Get-Item $omniDT).Length
    Write-Output "PHI DT376 RESTORED BYTE COUNT: $restoredLen"
  } else {
    Write-Output 'PHI DT376 RESTORE DID NOT LAND THE TABLE'; Write-Output 'JOB 376 STOPPED'; return
  }
}
Write-Output '--- SECTION 3: EXPORT THE OMNI TABLE IN ITS OWN PROJECT ---'
Copy-Item $baseDT "$baseDT.phi-backup-376" -Force
Write-Output 'BASE DT BACKED UP (.phi-backup-376)'
$pyExp = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('aW1wb3J0IHVucmVhbCwganNvbgpvdXQgPSBvcGVuKE9VVEZJTEUsICd3JykKZGVmIHcocyk6IG91dC53cml0ZShzICsgJ1xuJykKdHJ5OgogICAgZHQgPSB1bnJlYWwubG9hZF9hc3NldCgnL0dhbWUvRGF0YS9EVF9EaWFsb2d1ZScpCiAgICBpZiBkdCBpcyBOb25lOgogICAgICAgIHcoJ1BISSBEVDM3NiBPTU5JIExPQUQgTk9ORScpCiAgICBlbHNlOgogICAgICAgIHN0cnVjdF9uYW1lID0gJ3Vua25vd24nCiAgICAgICAgdHJ5OgogICAgICAgICAgICBzdHJ1Y3RfbmFtZSA9IHN0cihkdC5nZXRfcm93X3N0cnVjdCgpLmdldF9uYW1lKCkpCiAgICAgICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgICAgICAgICB3KCdQSEkgRFQzNzYgT01OSSBTVFJVQ1QgUkVBRCBFUlJPUjogJyArIHN0cihlKSkKICAgICAgICB3KCdQSEkgRFQzNzYgT01OSSBTVFJVQ1Q6ICcgKyBzdHJ1Y3RfbmFtZSkKICAgICAgICBqcyA9IGR0LmV4cG9ydF90b19qc29uX3N0cmluZygpCiAgICAgICAgcm93cyA9IGpzb24ubG9hZHMoanMpCiAgICAgICAgbmFtZXMgPSBzb3J0ZWQoc3RyKHIuZ2V0KCdOYW1lJykpIGZvciByIGluIHJvd3MpCiAgICAgICAgdygnUEhJIERUMzc2IE9NTkkgUk9XUz0nICsgc3RyKGxlbihyb3dzKSkgKyAnIDogJyArICcgJy5qb2luKG5hbWVzKSkKICAgICAgICB3aXRoIG9wZW4oSlNPTk9VVCwgJ3cnKSBhcyBmOgogICAgICAgICAgICBmLndyaXRlKGpzKQogICAgICAgIHcoJ1BISSBEVDM3NiBPTU5JIEpTT04gV1JJVFRFTicpCmV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgIHcoJ1BISSBEVDM3NiBPTU5JIEVYUE9SVCBFUlJPUjogJyArIHN0cihlKSkKb3V0LmNsb3NlKCkK'))
$pyExp = $pyExp.Replace('OUTFILE', "'D:\OMNI-UE\Saved\phi_dt376_export_out.txt'").Replace('JSONOUT', "'D:\VEIL-OMNI\Saved\phi_dt376_omni_rows.json'")
Set-Content 'D:\OMNI-UE\Saved\phi_dt376_export.py' -Value $pyExp -Encoding UTF8
Remove-Item 'D:\OMNI-UE\Saved\phi_dt376_export_out.txt' -ErrorAction SilentlyContinue
Remove-Item "$base\Saved\phi_dt376_omni_rows.json" -ErrorAction SilentlyContinue
$uprojO = Get-ChildItem 'D:\OMNI-UE' -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
& $cmdexe $uprojO -run=pythonscript -script='D:\OMNI-UE\Saved\phi_dt376_export.py' -unattended -nopause -nosplash *> 'D:\OMNI-UE\Saved\dt376_export.log'
if (Test-Path 'D:\OMNI-UE\Saved\phi_dt376_export_out.txt') { $expOut = Get-Content 'D:\OMNI-UE\Saved\phi_dt376_export_out.txt'; $expOut | Write-Output } else { Write-Output 'NO DT376 EXPORT OUTPUT FILE'; Write-Output 'JOB 376 STOPPED'; return }
if (($expOut -join "`n") -match 'LOAD NONE') { Write-Output 'PHI DT376 OMNI TABLE STILL UNREADABLE AFTER RESTORE'; Write-Output 'JOB 376 STOPPED'; return }
if (($expOut -join "`n") -notmatch 'OMNI STRUCT: PHIDialogueRow') { Write-Output 'PHI DT376 OMNI STRUCT GATE FAILED - stop before any write'; Write-Output 'JOB 376 STOPPED'; return }
if (-not (Test-Path "$base\Saved\phi_dt376_omni_rows.json")) { Write-Output 'DT376 ROWS JSON MISSING - import half not run.'; Write-Output 'JOB 376 STOPPED'; return }
Write-Output '--- SECTION 4: MERGE IN THE MERGED BASE ---'
$pyImp = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('aW1wb3J0IHVucmVhbCwganNvbgpvdXQgPSBvcGVuKE9VVEZJTEUsICd3JykKZGVmIHcocyk6IG91dC53cml0ZShzICsgJ1xuJykKdHJ5OgogICAgd2l0aCBvcGVuKE9NTklKU09OKSBhcyBmOgogICAgICAgIG9tbmkgPSBqc29uLmxvYWQoZikKICAgIHcoJ1BISSBEVDM3NiBvbW5pIHJvd3MgaW4ganNvbjogJyArIHN0cihsZW4ob21uaSkpKQogICAgZHQgPSB1bnJlYWwubG9hZF9hc3NldCgnL0dhbWUvRGF0YS9EVF9EaWFsb2d1ZScpCiAgICBpZiBkdCBpcyBOb25lOgogICAgICAgIHcoJ1BISSBEVDM3NiBCQVNFIExPQUQgTk9ORScpCiAgICBlbHNlOgogICAgICAgIHN0cnVjdF9uYW1lID0gJ3Vua25vd24nCiAgICAgICAgdHJ5OgogICAgICAgICAgICBzdHJ1Y3RfbmFtZSA9IHN0cihkdC5nZXRfcm93X3N0cnVjdCgpLmdldF9uYW1lKCkpCiAgICAgICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgICAgICAgICB3KCdQSEkgRFQzNzYgQkFTRSBTVFJVQ1QgUkVBRCBFUlJPUjogJyArIHN0cihlKSkKICAgICAgICB3KCdQSEkgRFQzNzYgQkFTRSBTVFJVQ1Q6ICcgKyBzdHJ1Y3RfbmFtZSkKICAgICAgICBiYXNlID0ganNvbi5sb2FkcyhkdC5leHBvcnRfdG9fanNvbl9zdHJpbmcoKSkKICAgICAgICB3KCdQSEkgRFQzNzYgYmFzZSByb3dzIGluIGpzb246ICcgKyBzdHIobGVuKGJhc2UpKSkKICAgICAgICBoYXZlID0gc2V0KHN0cihyLmdldCgnTmFtZScpKSBmb3IgciBpbiBiYXNlKQogICAgICAgIGFkZCA9IFtdCiAgICAgICAgc2tpcCA9IFtdCiAgICAgICAgZm9yIHIgaW4gb21uaToKICAgICAgICAgICAgbiA9IHN0cihyLmdldCgnTmFtZScpKQogICAgICAgICAgICBpZiBuIGluIGhhdmU6CiAgICAgICAgICAgICAgICBza2lwLmFwcGVuZChuKQogICAgICAgICAgICBlbHNlOgogICAgICAgICAgICAgICAgYWRkLmFwcGVuZChyKQogICAgICAgIHcoJ1BISSBEVDM3NiByb3dzIHRvIGFkZDogJyArIHN0cihsZW4oYWRkKSkgKyAnIDogJyArICcgJy5qb2luKHNvcnRlZChzdHIoci5nZXQoJ05hbWUnKSkgZm9yIHIgaW4gYWRkKSkpCiAgICAgICAgdygnUEhJIERUMzc2IHJvd3Mgc2tpcHBlZCBhbHJlYWR5IHN0YW5kaW5nOiAnICsgc3RyKGxlbihza2lwKSkgKyAnIDogJyArICcgJy5qb2luKHNvcnRlZChza2lwKSkpCiAgICAgICAgaWYgc3RydWN0X25hbWUgIT0gJ1BISURpYWxvZ3VlUm93JzoKICAgICAgICAgICAgdygnUEhJIERUMzc2IFNUUlVDVCBNSVNNQVRDSCAtIE5PIFdSSVRFJykKICAgICAgICBlbHNlOgogICAgICAgICAgICBkdC5maWxsX2Zyb21fanNvbl9zdHJpbmcoanNvbi5kdW1wcyhiYXNlICsgYWRkKSkKICAgICAgICAgICAgdW5yZWFsLkVkaXRvckFzc2V0TGlicmFyeS5zYXZlX2xvYWRlZF9hc3NldChkdCkKICAgICAgICAgICAgYWZ0ZXIgPSBqc29uLmxvYWRzKGR0LmV4cG9ydF90b19qc29uX3N0cmluZygpKQogICAgICAgICAgICBuYW1lcyA9IHNvcnRlZChzdHIoci5nZXQoJ05hbWUnKSkgZm9yIHIgaW4gYWZ0ZXIpCiAgICAgICAgICAgIHcoJ1BISSBEVDM3NiBNRVJHRUQgUk9XUz0nICsgc3RyKGxlbihhZnRlcikpICsgJyA6ICcgKyAnICcuam9pbihuYW1lcykpCmV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgIHcoJ1BISSBEVDM3NiBJTVBPUlQgRVJST1I6ICcgKyBzdHIoZSkpCm91dC5jbG9zZSgpCg=='))
$pyImp = $pyImp.Replace('OUTFILE', "'D:\VEIL-OMNI\Saved\phi_dt376_import_out.txt'").Replace('OMNIJSON', "'D:\VEIL-OMNI\Saved\phi_dt376_omni_rows.json'")
Set-Content "$base\Saved\phi_dt376_import.py" -Value $pyImp -Encoding UTF8
Remove-Item "$base\Saved\phi_dt376_import_out.txt" -ErrorAction SilentlyContinue
$uprojV = Get-ChildItem $base -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
& $cmdexe $uprojV -run=pythonscript -script="$base\Saved\phi_dt376_import.py" -unattended -nopause -nosplash *> "$base\Saved\dt376_import.log"
if (Test-Path "$base\Saved\phi_dt376_import_out.txt") { Get-Content "$base\Saved\phi_dt376_import_out.txt" | Write-Output } else { Write-Output 'NO DT376 IMPORT OUTPUT FILE'; Write-Output 'JOB 376 STOPPED'; return }
$bytes = [System.IO.File]::ReadAllBytes($baseDT)
$text = [System.Text.Encoding]::ASCII.GetString($bytes)
$ids = [regex]::Matches($text, '[VO][0-9][0-9]') | ForEach-Object { $_.Value } | Sort-Object -Unique
Write-Output ("PHI DT376 FINAL CENSUS rows=" + $ids.Count + " : " + ($ids -join ' '))
Write-Output 'JOB 376 DONE'
```
