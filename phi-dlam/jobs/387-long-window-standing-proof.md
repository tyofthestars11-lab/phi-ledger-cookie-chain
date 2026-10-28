<!-- PHI-DIRECT -->
```powershell
Write-Output '=== LONG-WINDOW STANDING PROOF 387 - THE FIVEFOLD WINDOW, THE BUILD GIVEN TIME TO FINISH, THE PROOF READ WHOLE (Job 383 stands as the record: the complex-as-simple set stands confirmed from the asset itself on both mountain meshes, CTF_USE_COMPLEX_AS_SIMPLE on SM_Mountain_01 and on SM_Iceland_Mountain_02 - and its 60 second game run again printed NO PROOF LINES, because the run log shows the game still building static mesh collision at capture end, the final lines standing inside the build of SM_Iceland_Mountain_02 at 8388608 tris, so the run never reached pawn spawn inside the window. Job 373 under the old collision printed its proof lines on the same launch road, so the instrument and the road stand proven; the complex collision build is what eats the window. THIS JOB, merged base at D VEIL-OMNI: one, read both mountain meshes in an editor scripting commandlet and print the collision_trace_flag exactly as it stands now, the brief asset check. Two, run VEILDistrict in game mode with a 300 second capture, five times the 383 window, on the same launch road as jobs 373 and 383. Three, read the run log in its parts: count every static mesh building progress line and print the first and the last with their timestamps, print every PHI SPAWN TRUTH, PHI TICK TRUTH, PHI TUMBLEKILL 371 and PHI CCDLOCK 372 line, and print the last 15 lines of the log. Four, print the verdict in its true shape: PROOF LINES LANDED with the tick series, floorBlock and capZ across the ticks standing as the standing read - or BUILD STILL IN PROGRESS AT CAPTURE END, with the last building line printed as the evidence.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 387 DEFERRED'; return }
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
Write-Output '--- SECTION 1: TRACE FLAG AS IT STANDS NOW ---'
$pyC = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOiBvdXQud3JpdGUoc3RyKHMpICsgJ1xuJykKZGVmIGxvYWRfbWVzaChwYXRoKToKICAgIG0gPSBOb25lCiAgICB0cnk6CiAgICAgICAgbSA9IHVucmVhbC5FZGl0b3JBc3NldExpYnJhcnkubG9hZF9hc3NldChwYXRoKQogICAgZXhjZXB0IEV4Y2VwdGlvbiBhcyBlOgogICAgICAgIHcoJ1BISSBQUk9PRjM4NyBsb2FkIGVycm9yICcgKyBwYXRoICsgJzogJyArIHN0cihlKSkKICAgIGlmIG0gaXMgTm9uZToKICAgICAgICB0cnk6CiAgICAgICAgICAgIG0gPSB1bnJlYWwubG9hZF9hc3NldChwYXRoKQogICAgICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICAgICAgdygnUEhJIFBST09GMzg3IGxvYWRfYXNzZXQgZXJyb3IgJyArIHBhdGggKyAnOiAnICsgc3RyKGUpKQogICAgcmV0dXJuIG0KTU9VTlRBSU5TID0gWycvR2FtZS9JY2VsYW5kX0Vudmlyb25tZW50L1N0YXRpY19NZXNoZXMvU01fTW91bnRhaW5fMDEuU01fTW91bnRhaW5fMDEnLCAnL0dhbWUvSWNlbGFuZF9FbnZpcm9ubWVudC9TdGF0aWNfTWVzaGVzL1NNX0ljZWxhbmRfTW91bnRhaW5fMDIuU01fSWNlbGFuZF9Nb3VudGFpbl8wMiddCmZvciBtcCBpbiBNT1VOVEFJTlM6CiAgICBtZXNoID0gbG9hZF9tZXNoKG1wKQogICAgaWYgbWVzaCBpcyBOb25lOgogICAgICAgIHcoJ1BISSBQUk9PRjM4NyBNRVNIIExPQUQgTk9ORTogJyArIG1wKQogICAgICAgIGNvbnRpbnVlCiAgICB0cnk6CiAgICAgICAgYnMgPSBtZXNoLmdldF9lZGl0b3JfcHJvcGVydHkoJ2JvZHlfc2V0dXAnKQogICAgICAgIGZsYWcgPSBzdHIoYnMuZ2V0X2VkaXRvcl9wcm9wZXJ0eSgnY29sbGlzaW9uX3RyYWNlX2ZsYWcnKSkKICAgICAgICB3KCdQSEkgUFJPT0YzODcgdHJhY2VmbGFnIG9uICcgKyBtcCArICcgPSAnICsgZmxhZykKICAgICAgICBpZiAnQ09NUExFWF9BU19TSU1QTEUnIGluIGZsYWc6CiAgICAgICAgICAgIHcoJ1BISSBQUk9PRjM4NyBTVEFORFMgY29tcGxleCBhcyBzaW1wbGUgb24gJyArIG1wKQogICAgICAgIGVsc2U6CiAgICAgICAgICAgIHcoJ1BISSBQUk9PRjM4NyBGTEFHIElTIE5PVCBDT01QTEVYIEFTIFNJTVBMRSBvbiAnICsgbXApCiAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgdygnUEhJIFBST09GMzg3IFRSQUNFRkxBRyBSRUFEIEVSUk9SICcgKyBtcCArICc6ICcgKyBzdHIoZSkpCncoJ1BISSBQUk9PRjM4NyBDT01QTEVURScpCm91dC5jbG9zZSgpCg=='))
$outC = "$base\Saved\phi_proof387.txt"
$py = $pyC.Replace('OUTFILE', "'$outC'")
Set-Content "$base\Saved\phi_proof387.py" -Value $py -Encoding UTF8
Remove-Item $outC -ErrorAction SilentlyContinue
& $cmdexe $uproj -run=pythonscript -script="$base\Saved\phi_proof387.py" -unattended -nopause -nosplash *> "$base\Saved\proof387.log"
if (Test-Path $outC) { Get-Content $outC | Write-Output } else { Write-Output 'NO PROOF387 OUTPUT FILE'; Select-String -Path "$base\Saved\proof387.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output }
Write-Output '--- SECTION 2: GAME RUN: /Game/Maps/VEILDistrict (300s capture) ---'
$gp = Start-Process $edexe -ArgumentList @($uproj, '/Game/Maps/VEILDistrict', '-game','-log','-nullrhi','-nosound','-unattended','-nopause','-nosplash') -PassThru -WindowStyle Hidden
Start-Sleep -Seconds 300
if (-not $gp.HasExited) { Stop-Process -Id $gp.Id -Force -ErrorAction SilentlyContinue; Write-Output 'RUN STOPPED AFTER 300s CAPTURE' } else { Write-Output ("RUN EXITED EARLY code=" + $gp.ExitCode) }
Start-Sleep -Seconds 3
Write-Output '--- SECTION 3: RUN LOG READ ---'
$logf = Get-ChildItem "$base\Saved\Logs\*.log" -File | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($logf) {
  Write-Output ("RUN LOG: " + $logf.FullName)
  $build = @(Select-String -Path $logf.FullName -Pattern 'LogStaticMesh|LogAsyncCompilation' -ErrorAction SilentlyContinue)
  Write-Output ("PHI PROOF387 BUILD PROGRESS LINES count=" + $build.Count)
  if ($build.Count -gt 0) {
    Write-Output '--- FIRST BUILD PROGRESS LINE ---'
    $build[0].Line | Write-Output
    Write-Output '--- LAST BUILD PROGRESS LINE ---'
    $build[$build.Count - 1].Line | Write-Output
  } else { Write-Output 'NO BUILD PROGRESS LINES IN LOG' }
  $hits = @(Select-String -Path $logf.FullName -Pattern 'PHI SPAWN TRUTH|PHI TICK TRUTH|PHI TUMBLEKILL 371|PHI CCDLOCK 372' -ErrorAction SilentlyContinue)
  if ($hits.Count -gt 0) { Write-Output '--- PROOF LINES ---'; $hits | ForEach-Object { $_.Line } | Write-Output } else { Write-Output 'NO PROOF LINES IN LOG for this run' }
  Write-Output '--- RUN LOG LAST 15 LINES ---'
  Get-Content $logf.FullName -Tail 15 | Write-Output
  Write-Output '--- VERDICT ---'
  if ($hits.Count -gt 0) {
    Write-Output 'PHI PROOF387 VERDICT: PROOF LINES LANDED'
    Write-Output '--- TICK SERIES ---'
    $hits | Where-Object { $_.Line -match 'PHI TICK TRUTH' } | ForEach-Object { $_.Line } | Write-Output
  } else {
    Write-Output 'PHI PROOF387 VERDICT: BUILD STILL IN PROGRESS AT CAPTURE END'
    if ($build.Count -gt 0) { Write-Output 'LAST BUILD LINE AS EVIDENCE:'; $build[$build.Count - 1].Line | Write-Output } else { Write-Output 'NO BUILD LINE STANDS AS EVIDENCE' }
  }
} else { Write-Output 'NO LOG FILE FOUND' }
Write-Output 'JOB 387 DONE'
```
