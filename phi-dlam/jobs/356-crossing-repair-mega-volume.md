<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CROSSING REPAIR - THE MEGA-VOLUME COMES OFF THE SPAWN COLUMN - MERGED BASE ONLY - AMENDED TO THE 100 PERCENT GATE (Tyrees correction, 2026-10-28: We dont build the package and whatever until 100 percent done. This job as first filed carried a UAT cook and a packaged-exe proof; that half is STRUCK by his word. The repair itself is unchanged: authored from job 347s per-tick prints - at both redrop columns she stands at floor contact z=97.5 with FindFloor naming StaticMeshActor_0 at floorDist=-42.0 embedded, then ONE tick later is displaced downward with no velocity behind it, 97.5 to -220.2 and -220.3 - penetration ejection from the mega-volume whose bounds, top=10085.1 base=-138.3, contain both columns, with the true ground at top exactly 0 underneath. The commandlet censuses every static-mesh actor whose bounds contain the spawn column, sets collision NO_COLLISION on exactly the mega-volume matches, and saves the level; the map is backed up first. The proof is IN-PROJECT, per the gate: the editor target compiles so the proof runs current code, then the editor runs the project in -game mode and the v2 sampler prints from the project log - she holds at floor contact or walks, no one-tick jump. NO PACKAGE IS BUILT BY THIS JOB. If no actor matches the criteria, the job stops with the census printed. OMNI-UE is not touched: the repair lands once, on the merged base.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 356 DEFERRED'; return }
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$proj = 'D:\VEIL'
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
if ($fixlog -notmatch 'actors fixed: [1-9]') { Write-Output 'NO MEGA-VOLUME MATCHED - no proof runs.'; Write-Output 'JOB 356 STOPPED'; return }
& $buildbat VEILEditor Win64 Development "-Project=$uproj" -WaitMutex -NoHotReload *> "$proj\Saved\crossfixbuild356.log"
"EDITOR BUILD exit: $LASTEXITCODE" | Write-Output
Select-String -Path "$proj\Saved\crossfixbuild356.log" -Pattern 'Result: Succeeded|Result: Failed|error C[0-9]+|ERROR:' | Select-Object -Last 5 | ForEach-Object { $_.Line.Trim() } | Write-Output
if ($LASTEXITCODE -ne 0) { Write-Output 'EDITOR BUILD FAILED - no proof runs.'; Write-Output 'JOB 356 STOPPED'; return }
$proc = Start-Process $cmdexe -ArgumentList @($uproj, '/Game/Maps/VEILDistrict', '-game', '-PhiStandaloneProof', '-unattended', '-nopause', '-nosplash') -PassThru -WindowStyle Hidden
Start-Sleep -Seconds 45
Get-Process UnrealEditor-Cmd -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
$logs = Get-ChildItem "$proj\Saved\Logs" -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($logs) { Select-String -Path $logs.FullName -Pattern 'PHI CROSS2|PHI FLOOR DIAG' | Select-Object -Last 120 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
Write-Output 'JOB 356 DONE'
```
