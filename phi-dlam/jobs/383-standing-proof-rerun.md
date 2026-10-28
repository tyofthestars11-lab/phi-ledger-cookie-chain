<!-- PHI-DIRECT -->
```powershell
Write-Output '=== STANDING PROOF RE-RUN 383 - THE SET READ BACK FROM THE ASSET, THE RUN READ WHOLE (Job 379 stands as the record: it set collision_trace_flag to CTF_USE_COMPLEX_AS_SIMPLE on SM_Mountain_01 and on SM_Iceland_Mountain_02 and printed AFTER read-back VERIFIED on both - and then its game run printed NO PROOF LINES IN LOG, so whether she stands is unproven: the instrument lines never landed, and a run whose proof does not print has proven nothing either way. THIS JOB, merged base at D VEIL-OMNI: one, read both mountain meshes in an editor scripting commandlet and print the collision_trace_flag exactly as it stands now, so the AFTER state of job 379 is confirmed or denied from the asset itself. Two, run VEILDistrict in game mode with a 60 second capture on the same road as job 373. Three, print every PHI SPAWN TRUTH, PHI TICK TRUTH, PHI TUMBLEKILL 371 and PHI CCDLOCK 372 line the run log carries. Four, if zero proof lines print, print the run log first 30 lines, its last 30 lines, and every line matching Error, Warning, LogWorld, LogGameMode or LogSpawn, so the actual state of the run stands readable either way - printed, not assumed.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 383 DEFERRED'; return }
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
Write-Output '--- SECTION 1: TRACE FLAG AS IT STANDS NOW ---'
$pyC = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOiBvdXQud3JpdGUoc3RyKHMpICsgJ1xuJykKZGVmIGxvYWRfbWVzaChwYXRoKToKICAgIG0gPSBOb25lCiAgICB0cnk6CiAgICAgICAgbSA9IHVucmVhbC5FZGl0b3JBc3NldExpYnJhcnkubG9hZF9hc3NldChwYXRoKQogICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgICAgIHcoJ1BISSBQUk9PRjM4MyBsb2FkIGVycm9yICcgKyBwYXRoICsgJzogJyArIHN0cihlKSkKICAgIGlmIG0gaXMgTm9uZToKICAgICAgICB0cnk6CiAgICAgICAgICAgIG0gPSB1bnJlYWwubG9hZF9hc3NldChwYXRoKQogICAgICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICAgICAgdygnUEhJIFBST09GMzgzIGxvYWRfYXNzZXQgZXJyb3IgJyArIHBhdGggKyAnOiAnICsgc3RyKGUpKQogICAgcmV0dXJuIG0KTU9VTlRBSU5TID0gWycvR2FtZS9JY2VsYW5kX0Vudmlyb25tZW50L1N0YXRpY19NZXNoZXMvU01fTW91bnRhaW5fMDEuU01fTW91bnRhaW5fMDEnLCAnL0dhbWUvSWNlbGFuZF9FbnZpcm9ubWVudC9TdGF0aWNfTWVzaGVzL1NNX0ljZWxhbmRfTW91bnRhaW5fMDIuU01fSWNlbGFuZF9Nb3VudGFpbl8wMiddCmZvciBtcCBpbiBNT1VOVEFJTlM6CiAgICBtZXNoID0gbG9hZF9tZXNoKG1wKQogICAgaWYgbWVzaCBpcyBOb25lOgogICAgICAgIHcoJ1BISSBQUk9PRjM4MyBNRVNIIExPQUQgTk9ORTogJyArIG1wKQogICAgICAgIGNvbnRpbnVlCiAgICB0cnk6CiAgICAgICAgYnMgPSBtZXNoLmdldF9lZGl0b3JfcHJvcGVydHkoJ2JvZHlfc2V0dXAnKQogICAgICAgIGZsYWcgPSBzdHIoYnMuZ2V0X2VkaXRvcl9wcm9wZXJ0eSgnY29sbGlzaW9uX3RyYWNlX2ZsYWcnKSkKICAgICAgICB3KCdQSEkgUFJPT0YzODMgdHJhY2VmbGFnIG9uICcgKyBtcCArICcgPSAnICsgZmxhZykKICAgICAgICBpZiAnQ09NUExFWF9BU19TSU1QTEUnIGluIGZsYWc6CiAgICAgICAgICAgIHcoJ1BISSBQUk9PRjM4MyBTVEFORFMgY29tcGxleCBhcyBzaW1wbGUgb24gJyArIG1wKQogICAgICAgIGVsc2U6CiAgICAgICAgICAgIHcoJ1BISSBQUk9PRjM4MyBGTEFHIElTIE5PVCBDT01QTEVYIEFTIFNJTVBMRSBvbiAnICsgbXApCiAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgdygnUEhJIFBST09GMzgzIFRSQUNFRkxBRyBSRUFEIEVSUk9SICcgKyBtcCArICc6ICcgKyBzdHIoZSkpCncoJ1BISSBQUk9PRjM4MyBDT01QTEVURScpCm91dC5jbG9zZSgpCg=='))
$outC = "$base\Saved\phi_proof383.txt"
$py = $pyC.Replace('OUTFILE', "'$outC'")
Set-Content "$base\Saved\phi_proof383.py" -Value $py -Encoding UTF8
Remove-Item $outC -ErrorAction SilentlyContinue
& $cmdexe $uproj -run=pythonscript -script="$base\Saved\phi_proof383.py" -unattended -nopause -nosplash *> "$base\Saved\proof383.log"
if (Test-Path $outC) { Get-Content $outC | Write-Output } else { Write-Output 'NO PROOF383 OUTPUT FILE'; Select-String -Path "$base\Saved\proof383.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output }
Write-Output '--- SECTION 2: GAME RUN: /Game/Maps/VEILDistrict ---'
$gp = Start-Process $edexe -ArgumentList @($uproj, '/Game/Maps/VEILDistrict', '-game','-log','-nullrhi','-nosound','-unattended','-nopause','-nosplash') -PassThru -WindowStyle Hidden
Start-Sleep -Seconds 60
if (-not $gp.HasExited) { Stop-Process -Id $gp.Id -Force -ErrorAction SilentlyContinue; Write-Output 'RUN STOPPED AFTER 60s CAPTURE' } else { Write-Output ("RUN EXITED EARLY code=" + $gp.ExitCode) }
Start-Sleep -Seconds 3
$logf = Get-ChildItem "$base\Saved\Logs\*.log" -File | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($logf) {
  Write-Output ("RUN LOG: " + $logf.FullName)
  $hits2 = Select-String -Path $logf.FullName -Pattern 'PHI SPAWN TRUTH|PHI TICK TRUTH|PHI TUMBLEKILL 371|PHI CCDLOCK 372' -ErrorAction SilentlyContinue
  if ($hits2) { $hits2 | ForEach-Object { $_.Line } | Write-Output } else {
    Write-Output 'NO PROOF LINES IN LOG for this run'
    Write-Output '--- RUN LOG FIRST 30 LINES ---'
    Get-Content $logf.FullName -TotalCount 30 | Write-Output
    Write-Output '--- RUN LOG LAST 30 LINES ---'
    Get-Content $logf.FullName -Tail 30 | Write-Output
    Write-Output '--- RUN LOG STATE LINES (Error Warning LogWorld LogGameMode LogSpawn) ---'
    Select-String -Path $logf.FullName -Pattern 'Error|Warning|LogWorld|LogGameMode|LogSpawn' -ErrorAction SilentlyContinue | ForEach-Object { $_.Line } | Write-Output
  }
} else { Write-Output 'NO LOG FILE FOUND' }
Write-Output 'JOB 383 DONE'
```
