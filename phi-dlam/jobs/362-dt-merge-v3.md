<!-- PHI-DIRECT -->
```powershell
Write-Output '=== DT DIALOGUE MERGE V3 - JOB 362 IS JOB 360 WITH ITS ONE DEFECT REMOVED (Job 360 parse-died before running: a Python raw-string prefix leaked into two PowerShell Replace calls in its body - this seats own authoring slip, caught by 360s result, routed as fuel. The merge design is unchanged and stands on job 355s printed API census: the DataTable exports to JSON and fills from JSON natively. OMNI table exports to a JSON file; in the merged base at D:\VEIL-OMNI the base table exports to a JSON string, the row sets merge by name with no overwrite, the merged JSON fills the base table, the asset saves, and the census must read 37 rows. Fresh backup first. OMNI-UE read-only; job 358s pack may still be retiring its proven bytes, and this export reads only the dialogue table.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 362 DEFERRED'; return }
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$base = 'D:\VEIL-OMNI'
$baseDT = "$base\Content\Data\DT_Dialogue.uasset"
Copy-Item $baseDT "$baseDT.phi-backup-362" -Force
Write-Output 'BASE DT BACKED UP (.phi-backup-362)'
$pyExp = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOiBvdXQud3JpdGUocyArICdcbicpCnRyeToKICAgIGR0ID0gdW5yZWFsLmxvYWRfYXNzZXQoJy9HYW1lL0RhdGEvRFRfRGlhbG9ndWUnKQogICAgb2sgPSBkdC5leHBvcnRfdG9fanNvbl9maWxlKEpTT05PVVQpCiAgICBuYW1lcyA9IFtzdHIobikgZm9yIG4gaW4gZHQuZ2V0X3Jvd19uYW1lcygpXQogICAgdygnUEhJIERUMyBFWFBPUlQgb2s9JyArIHN0cihvaykgKyAnIHJvd3M9JyArIHN0cihsZW4obmFtZXMpKSArICcgJyArICcgJy5qb2luKHNvcnRlZChuYW1lcykpKQpleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICB3KCdQSEkgRFQzIEVYUE9SVCBFUlJPUjogJyArIHN0cihlKSkKb3V0LmNsb3NlKCkK'))
$pyExp = $pyExp.Replace('OUTFILE', "'D:\OMNI-UE\Saved\phi_dt3_export_out.txt'").Replace('JSONOUT', "'D:\VEIL-OMNI\Saved\phi_dt_omni_rows.json'")
Set-Content 'D:\OMNI-UE\Saved\phi_dt3_export.py' -Value $pyExp -Encoding UTF8
Remove-Item 'D:\OMNI-UE\Saved\phi_dt3_export_out.txt' -ErrorAction SilentlyContinue
$uprojO = Get-ChildItem 'D:\OMNI-UE' -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
& $cmdexe $uprojO -run=pythonscript -script='D:\OMNI-UE\Saved\phi_dt3_export.py' -unattended -nopause -nosplash *> 'D:\OMNI-UE\Saved\dtmerge362_export.log'
if (Test-Path 'D:\OMNI-UE\Saved\phi_dt3_export_out.txt') { Get-Content 'D:\OMNI-UE\Saved\phi_dt3_export_out.txt' | Write-Output } else { Write-Output 'NO DT3 EXPORT OUTPUT FILE'; Write-Output 'JOB 362 STOPPED'; return }
if (-not (Test-Path "$base\Saved\phi_dt_omni_rows.json")) { Write-Output 'DT3 ROWS JSON MISSING - import half not run.'; Write-Output 'JOB 362 STOPPED'; return }
$pyImp = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwsIGpzb24Kb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOiBvdXQud3JpdGUocyArICdcbicpCnRyeToKICAgIHdpdGggb3BlbihPTU5JSlNPTikgYXMgZjoKICAgICAgICBvbW5pID0ganNvbi5sb2FkKGYpCiAgICB3KCdQSEkgRFQzIG9tbmkgcm93cyBpbiBqc29uOiAnICsgc3RyKGxlbihvbW5pKSkpCiAgICBkdCA9IHVucmVhbC5sb2FkX2Fzc2V0KCcvR2FtZS9EYXRhL0RUX0RpYWxvZ3VlJykKICAgIGJhc2UgPSBqc29uLmxvYWRzKGR0LmV4cG9ydF90b19qc29uX3N0cmluZygpKQogICAgdygnUEhJIERUMyBiYXNlIHJvd3MgaW4ganNvbjogJyArIHN0cihsZW4oYmFzZSkpKQogICAgaGF2ZSA9IHNldChyLmdldCgnTmFtZScpIGZvciByIGluIGJhc2UpCiAgICBhZGQgPSBbciBmb3IgciBpbiBvbW5pIGlmIHIuZ2V0KCdOYW1lJykgbm90IGluIGhhdmVdCiAgICB3KCdQSEkgRFQzIHJvd3MgdG8gYWRkOiAnICsgc3RyKGxlbihhZGQpKSArICcgJyArICcgJy5qb2luKHNvcnRlZChyLmdldCgnTmFtZScpIGZvciByIGluIGFkZCkpKQogICAgZHQuZmlsbF9mcm9tX2pzb25fc3RyaW5nKGpzb24uZHVtcHMoYmFzZSArIGFkZCkpCiAgICB1bnJlYWwuRWRpdG9yQXNzZXRMaWJyYXJ5LnNhdmVfbG9hZGVkX2Fzc2V0KGR0KQogICAgYWZ0ZXIgPSBbc3RyKG4pIGZvciBuIGluIGR0LmdldF9yb3dfbmFtZXMoKV0KICAgIHcoJ1BISSBEVDMgYmFzZSByb3dzIGFmdGVyOiAnICsgc3RyKGxlbihhZnRlcikpICsgJyAnICsgJyAnLmpvaW4oc29ydGVkKGFmdGVyKSkpCmV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgIHcoJ1BISSBEVDMgSU1QT1JUIEVSUk9SOiAnICsgc3RyKGUpKQpvdXQuY2xvc2UoKQo='))
$pyImp = $pyImp.Replace('OUTFILE', "'D:\VEIL-OMNI\Saved\phi_dt3_import_out.txt'").Replace('OMNIJSON', "'D:\VEIL-OMNI\Saved\phi_dt_omni_rows.json'")
Set-Content "$base\Saved\phi_dt3_import.py" -Value $pyImp -Encoding UTF8
Remove-Item "$base\Saved\phi_dt3_import_out.txt" -ErrorAction SilentlyContinue
$uprojV = Get-ChildItem $base -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
& $cmdexe $uprojV -run=pythonscript -script="$base\Saved\phi_dt3_import.py" -unattended -nopause -nosplash *> "$base\Saved\dtmerge362_import.log"
if (Test-Path "$base\Saved\phi_dt3_import_out.txt") { Get-Content "$base\Saved\phi_dt3_import_out.txt" | Write-Output } else { Write-Output 'NO DT3 IMPORT OUTPUT FILE'; Write-Output 'JOB 362 STOPPED'; return }
$bytes = [System.IO.File]::ReadAllBytes($baseDT)
$text = [System.Text.Encoding]::ASCII.GetString($bytes)
$ids = [regex]::Matches($text, '[VO][0-9][0-9]') | ForEach-Object { $_.Value } | Sort-Object -Unique
Write-Output ("PHI DT3 MERGED CENSUS rows=" + $ids.Count + " : " + ($ids -join ' '))
Write-Output 'JOB 362 DONE'
```
