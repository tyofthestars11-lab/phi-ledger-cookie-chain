<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CROSSING REPAIR - THE MEGA-VOLUME COMES OFF THE SPAWN COLUMN - MERGED BASE ONLY (Authored from job 347s per-tick prints, read whole. The shape, exact: at both redrop columns she first stands at floor contact - z=97.5, capsule bottom on the z=0 surface - with FindFloor naming StaticMeshActor_0 at floorDist=-42.0, embedded, refusing blocking and walkable; ONE tick later she is displaced downward in a single jump with no velocity behind it - 97.5 to -220.2 in VEIL DROP1, 97.5 to -220.3 in VEIL DROP2 - then falls clean under gravity. That is penetration ejection: the pawn lands INSIDE a volume and the movement solver pushes her out through its bottom. Job 347s column census names the volume: StaticMeshActor_0, bounds top=10085.1 base=-138.3, the one actor whose bounds contain BOTH test columns - a mega-volume standing over the spawn plaza and the slab column alike. The true ground (top exactly 0) stands underneath it. THIS JOB, merged base only: an editor commandlet censuses every static-mesh actor whose bounds contain the spawn column, prints mesh and collision for each, and sets collision to NO_COLLISION on exactly those matching the mega-volume criteria (bounds contain the column, top above 1000, base below 0), then saves the level. The map is backed up first. Then a full recook and the standalone proof: the v2 sampler still stands in the Character source, so the DROP prints themselves verify the repair - she holds at floor contact or walks, no one-tick jump. If no actor matches the criteria, the job stops before the cook with the census printed. OMNI-UE is not touched: the repair lands once, on the merged base.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 356 DEFERRED'; return }
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$proj = 'D:\VEIL'; $arch = 'D:\Builds\VEIL\VEIL_DONE'
$umap = Get-ChildItem "$proj\Content" -Recurse -Filter 'VEILDistrict.umap' -File | Select-Object -First 1
Copy-Item $umap.FullName "$($umap.FullName).phi-backup-356" -Force
Write-Output 'VEILDISTRICT BACKED UP (.phi-backup-356)'
$py = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOiBvdXQud3JpdGUocyArICdcbicpCmxlcyA9IHVucmVhbC5nZXRfZWRpdG9yX3N1YnN5c3RlbSh1bnJlYWwuTGV2ZWxFZGl0b3JTdWJzeXN0ZW0pCnRyeToKICAgIGxlcy5sb2FkX2xldmVsKE1BUFBBVEgpCiAgICB3KCdQSEkgQ1JPU1NGSVggbGV2ZWwgbG9hZGVkOiAnICsgTUFQUEFUSCkKZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgdygnUEhJIENST1NTRklYIGxvYWQgZXJyb3I6ICcgKyBzdHIoZSkpCmZpeGVkID0gMApmb3IgYSBpbiB1bnJlYWwuRWRpdG9yTGV2ZWxMaWJyYXJ5LmdldF9hbGxfbGV2ZWxfYWN0b3JzKCk6CiAgICBpZiAnU3RhdGljTWVzaEFjdG9yJyBub3QgaW4gYS5nZXRfY2xhc3MoKS5nZXRfbmFtZSgpOgogICAgICAgIGNvbnRpbnVlCiAgICBjb21wID0gYS5nZXRfY29tcG9uZW50X2J5X2NsYXNzKHVucmVhbC5TdGF0aWNNZXNoQ29tcG9uZW50KQogICAgaWYgbm90IGNvbXA6CiAgICAgICAgY29udGludWUKICAgIGIgPSBhLmdldF9jb21wb25lbnRzX2JvdW5kaW5nX2JveChUcnVlKQogICAgY29udGFpbnMgPSAoYi5taW4ueCA8PSAwLjAgPD0gYi5tYXgueCkgYW5kIChiLm1pbi55IDw9IDAuMCA8PSBiLm1heC55KQogICAgbWVnYSA9IChiLm1heC56ID4gMTAwMC4wKSBhbmQgKGIubWluLnogPCAwLjApCiAgICBpZiBjb250YWluczoKICAgICAgICBtZXNoID0gY29tcC5nZXRfZWRpdG9yX3Byb3BlcnR5KCdzdGF0aWNfbWVzaCcpCiAgICAgICAgdygnUEhJIENST1NTRklYIENPTFVNTiBBQ1RPUjogbmFtZT0nICsgYS5nZXRfbmFtZSgpICsgJyB0b3A9JyArIGZvcm1hdChiLm1heC56LCAnLjFmJykgKyAnIGJhc2U9JyArIGZvcm1hdChiLm1pbi56LCAnLjFmJykgKyAnIG1lc2g9JyArIChtZXNoLmdldF9uYW1lKCkgaWYgbWVzaCBlbHNlICdub25lJykgKyAnIGNvbGxpc2lvbj0nICsgc3RyKGNvbXAuZ2V0X2VkaXRvcl9wcm9wZXJ0eSgnY29sbGlzaW9uX2VuYWJsZWQnKSkpCiAgICAgICAgaWYgbWVnYToKICAgICAgICAgICAgY29tcC5zZXRfY29sbGlzaW9uX2VuYWJsZWQodW5yZWFsLkNvbGxpc2lvbkVuYWJsZWQuTk9fQ09MTElTSU9OKQogICAgICAgICAgICB3KCdQSEkgQ1JPU1NGSVggQ09MTElTSU9OIE9GRjogJyArIGEuZ2V0X25hbWUoKSArICcgbm93PScgKyBzdHIoY29tcC5nZXRfZWRpdG9yX3Byb3BlcnR5KCdjb2xsaXNpb25fZW5hYmxlZCcpKSkKICAgICAgICAgICAgZml4ZWQgKz0gMQp3KCdQSEkgQ1JPU1NGSVggYWN0b3JzIGZpeGVkOiAnICsgc3RyKGZpeGVkKSkKdHJ5OgogICAgbGVzLnNhdmVfY3VycmVudF9sZXZlbCgpCiAgICB3KCdQSEkgQ1JPU1NGSVggU0FWRUQnKQpleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICB3KCdQSEkgQ1JPU1NGSVggc2F2ZSBlcnJvcjogJyArIHN0cihlKSkKb3V0LmNsb3NlKCkK'))
$py = $py.Replace('MAPPATH', "'/Game/Maps/VEILDistrict'").Replace('OUTFILE', "'D:\VEIL\Saved\phi_crossfix_out.txt'")
Set-Content "$proj\Saved\phi_crossfix.py" -Value $py -Encoding UTF8
Remove-Item "$proj\Saved\phi_crossfix_out.txt" -ErrorAction SilentlyContinue
$uproj = Get-ChildItem $proj -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
& $cmdexe $uproj -run=pythonscript -script="$proj\Saved\phi_crossfix.py" -unattended -nopause -nosplash *> "$proj\Saved\crossfix356.log"
if (Test-Path "$proj\Saved\phi_crossfix_out.txt") { Get-Content "$proj\Saved\phi_crossfix_out.txt" | Write-Output } else { Write-Output 'NO CROSSFIX OUTPUT FILE'; Write-Output 'JOB 356 STOPPED'; return }
$fixlog = Get-Content "$proj\Saved\phi_crossfix_out.txt" -Raw
if ($fixlog -notmatch 'actors fixed: [1-9]') { Write-Output 'NO MEGA-VOLUME MATCHED - no cook runs.'; Write-Output 'JOB 356 STOPPED BEFORE COOK'; return }
$cooklog = "$proj\Saved\crossfixcook356.log"
$p = Start-Process $uat -ArgumentList @('BuildCookRun', "-project=$uproj", '-noP4', '-platform=Win64', '-clientconfig=Development', '-build', '-cook', '-stage', '-pak', '-archive', "-archivedirectory=$arch") -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $cooklog -RedirectStandardError "$cooklog.err"
"UAT exit: $($p.ExitCode)" | Write-Output
Select-String -Path $cooklog -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|Error:' | Select-Object -Last 5 | ForEach-Object { $_.Line.Trim() } | Write-Output
$exe = "$arch\Windows\VEIL.exe"
if (Test-Path $exe) { $fi = Get-Item $exe; "exe modified $($fi.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss'))" | Write-Output
  $proc = Start-Process $exe -ArgumentList @('-PhiStandaloneProof') -PassThru -WindowStyle Hidden
  Start-Sleep -Seconds 30
  $logs = Get-ChildItem "$proj\Saved\Logs", "$arch\Windows\VEIL\Saved\Logs" -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  if ($logs) { Select-String -Path $logs.FullName -Pattern 'PHI CROSS2|PHI FLOOR DIAG' | Select-Object -Last 120 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
  Get-Process VEIL -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
} else { Write-Output 'EXE MISSING AFTER CROSSFIX COOK' }
Write-Output 'JOB 356 DONE'
```
