<!-- PHI-DIRECT -->
```powershell
Write-Output '=== DT DIALOGUE MERGE V2 - WRITTEN FROM JOB 355S OWN API CENSUS (Job 355 stopped at its export half on one missing method - DataTableFunctionLibrary.get_data_table_row_from_name does not exist in this build - and per its design it printed the exact API surface before stopping. The surface carries the whole merge natively: the DataTable itself exports to JSON (export_to_json_file, export_to_json_string) and fills from JSON (fill_from_json_string). THIS JOB runs the merge on those native calls: OMNI table exports to a JSON file; in the merged base (now at D:\VEIL-OMNI after job 359s verified rename) the base table exports to a JSON string, the two row sets merge in Python by row name with no overwrite of existing rows, the merged JSON fills the base table, the asset saves, and the in-job census must read 37 rows - V01 to V19 plus O01 to O18. The base table is backed up first under a fresh 360 name. OMNI-UE is read-only here and still standing: job 358s pack retires its bytes only on round-trip proof, and this export reads it before that completion lands.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 360 DEFERRED'; return }
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$base = 'D:\VEIL-OMNI'
$baseDT = "$base\Content\Data\DT_Dialogue.uasset"
Copy-Item $baseDT "$baseDT.phi-backup-360" -Force
Write-Output 'BASE DT BACKED UP (.phi-backup-360)'
$pyExp = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOiBvdXQud3JpdGUocyArICdcbicpCnRyeToKICAgIGR0ID0gdW5yZWFsLmxvYWRfYXNzZXQoJy9HYW1lL0RhdGEvRFRfRGlhbG9ndWUnKQogICAgb2sgPSBkdC5leHBvcnRfdG9fanNvbl9maWxlKEpTT05PVVQpCiAgICBuYW1lcyA9IFtzdHIobikgZm9yIG4gaW4gZHQuZ2V0X3Jvd19uYW1lcygpXQogICAgdygnUEhJIERUMiBFWFBPUlQgb2s9JyArIHN0cihvaykgKyAnIHJvd3M9JyArIHN0cihsZW4obmFtZXMpKSArICcgJyArICcgJy5qb2luKHNvcnRlZChuYW1lcykpKQpleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICB3KCdQSEkgRFQyIEVYUE9SVCBFUlJPUjogJyArIHN0cihlKSkKb3V0LmNsb3NlKCkK'))
$pyExp = $pyExp.Replace('OUTFILE', "'D:\OMNI-UE\Saved\phi_dt2_export_out.txt'").Replace('JSONOUT', r"'D:\VEIL-OMNI\Saved\phi_dt_omni_rows.json'")
Set-Content 'D:\OMNI-UE\Saved\phi_dt2_export.py' -Value $pyExp -Encoding UTF8
Remove-Item 'D:\OMNI-UE\Saved\phi_dt2_export_out.txt' -ErrorAction SilentlyContinue
$uprojO = Get-ChildItem 'D:\OMNI-UE' -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
& $cmdexe $uprojO -run=pythonscript -script='D:\OMNI-UE\Saved\phi_dt2_export.py' -unattended -nopause -nosplash *> 'D:\OMNI-UE\Saved\dtmerge360_export.log'
if (Test-Path 'D:\OMNI-UE\Saved\phi_dt2_export_out.txt') { Get-Content 'D:\OMNI-UE\Saved\phi_dt2_export_out.txt' | Write-Output } else { Write-Output 'NO DT2 EXPORT OUTPUT FILE'; Write-Output 'JOB 360 STOPPED'; return }
if (-not (Test-Path "$base\Saved\phi_dt_omni_rows.json")) { Write-Output 'DT2 ROWS JSON MISSING - import half not run.'; Write-Output 'JOB 360 STOPPED'; return }
$pyImp = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwsIGpzb24Kb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOiBvdXQud3JpdGUocyArICdcbicpCnRyeToKICAgIHdpdGggb3BlbihPTU5JSlNPTikgYXMgZjoKICAgICAgICBvbW5pID0ganNvbi5sb2FkKGYpCiAgICB3KCdQSEkgRFQyIG9tbmkgcm93cyBpbiBqc29uOiAnICsgc3RyKGxlbihvbW5pKSkpCiAgICBkdCA9IHVucmVhbC5sb2FkX2Fzc2V0KCcvR2FtZS9EYXRhL0RUX0RpYWxvZ3VlJykKICAgIG1pbmUgPSBkdC5leHBvcnRfdG9fanNvbl9zdHJpbmcoKQogICAgYmFzZSA9IGpzb24ubG9hZHMobWluZSkKICAgIHcoJ1BISSBEVDIgYmFzZSByb3dzIGluIGpzb246ICcgKyBzdHIobGVuKGJhc2UpKSkKICAgIGhhdmUgPSBzZXQoci5nZXQoJ05hbWUnKSBmb3IgciBpbiBiYXNlKQogICAgYWRkID0gW3IgZm9yIHIgaW4gb21uaSBpZiByLmdldCgnTmFtZScpIG5vdCBpbiBoYXZlXQogICAgdygnUEhJIERUMiByb3dzIHRvIGFkZDogJyArIHN0cihsZW4oYWRkKSkgKyAnICcgKyAnICcuam9pbihzb3J0ZWQoci5nZXQoJ05hbWUnKSBmb3IgciBpbiBhZGQpKSkKICAgIG1lcmdlZCA9IGJhc2UgKyBhZGQKICAgIGR0LmZpbGxfZnJvbV9qc29uX3N0cmluZyhqc29uLmR1bXBzKG1lcmdlZCkpCiAgICB1bnJlYWwuRWRpdG9yQXNzZXRMaWJyYXJ5LnNhdmVfbG9hZGVkX2Fzc2V0KGR0KQogICAgYWZ0ZXIgPSBbc3RyKG4pIGZvciBuIGluIGR0LmdldF9yb3dfbmFtZXMoKV0KICAgIHcoJ1BISSBEVDIgYmFzZSByb3dzIGFmdGVyOiAnICsgc3RyKGxlbihhZnRlcikpICsgJyAnICsgJyAnLmpvaW4oc29ydGVkKGFmdGVyKSkpCmV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgIHcoJ1BISSBEVDIgSU1QT1JUIEVSUk9SOiAnICsgc3RyKGUpKQpvdXQuY2xvc2UoKQo='))
$pyImp = $pyImp.Replace('OUTFILE', "'D:\VEIL-OMNI\Saved\phi_dt2_import_out.txt'").Replace('OMNIJSON', r"'D:\VEIL-OMNI\Saved\phi_dt_omni_rows.json'")
Set-Content "$base\Saved\phi_dt2_import.py" -Value $pyImp -Encoding UTF8
Remove-Item "$base\Saved\phi_dt2_import_out.txt" -ErrorAction SilentlyContinue
$uprojV = Get-ChildItem $base -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
& $cmdexe $uprojV -run=pythonscript -script="$base\Saved\phi_dt2_import.py" -unattended -nopause -nosplash *> "$base\Saved\dtmerge360_import.log"
if (Test-Path "$base\Saved\phi_dt2_import_out.txt") { Get-Content "$base\Saved\phi_dt2_import_out.txt" | Write-Output } else { Write-Output 'NO DT2 IMPORT OUTPUT FILE'; Write-Output 'JOB 360 STOPPED'; return }
$bytes = [System.IO.File]::ReadAllBytes($baseDT)
$text = [System.Text.Encoding]::ASCII.GetString($bytes)
$ids = [regex]::Matches($text, '[VO][0-9][0-9]') | ForEach-Object { $_.Value } | Sort-Object -Unique
Write-Output ("PHI DT2 MERGED CENSUS rows=" + $ids.Count + " : " + ($ids -join ' '))
Write-Output 'JOB 360 DONE'
```
