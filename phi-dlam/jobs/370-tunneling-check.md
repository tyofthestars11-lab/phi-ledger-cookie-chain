<!-- PHI-DIRECT -->
```powershell
Write-Output '=== TUNNELING CHECK 370 - THE INEQUALITY, PRINTED (Second study relay, folded whole into the same repair pass: collision is discrete time-stepping, and tunneling occurs when per-step travel exceeds floor collision thickness d - no sampled step ever intersects the floor. Fixes map onto the variables: substepping cuts the step, CCD sweeps the volume and solves for the contact root, and real collision depth widens the window - a 0-thickness plane makes the inequality true for ANY non-zero velocity. The inputs from his record: velocity v MEASURED - job 333 move test printed velBefore=4000.0 and velAfter=4025.2, the same scale printed in both parents across jobs 321, 322 and 333 - and gravity only grows it in the drop, because she is already falling at spawn and never stops. At 60 steps a second the analytic per-step travel is 4025.2 / 60 = 67.1 units, so the inequality is satisfied against any floor thinner than about 67 units, and trivially against a plane. Floor thickness d is the open variable this drain reads: job 367 asks the FloorMesh its collision at its own address, and job 369 prints its bounds and full thickness with the complex-as-simple set. THIS JOB is the pass check, merged base at D VEIL-OMNI: one, harvest d, the AFTER trace flag, the substepping verdict and the mesh CCD value from the drain own result files standing in the PC clone; if no thickness stands there, read the FloorMesh bounds directly in a read-only commandlet on the same hunt road as 369. Two, measure per-step travel empirically: a fresh game run on VEILDistrict under the job 365 instrument, the PHI TICK TRUTH capZ series parsed in order, successive per-tick falls printed, the maximum named. Three, print the verdict in the inequality own shape: TUNNEL ANALYTIC with v=4025.2 at 60 steps, TUNNEL EMPIRICAL with the measured maximum, TUNNEL MITIGATION with substepping and CCD as printed by 369 - PASS when per-step travel stands below d on either measure, or when substepping divides the step below d, or when CCD stands engaged on the mesh; FAIL names its own reroute in the print: the floor collision depth must rise above the per-step travel, the guide floor being 20 units of real depth as a minimum and 67 as the measured bar. If d stands unread in both roads, the verdict prints UNRESOLVED - D UNREAD and nothing is assumed. Printed, not assumed: that is the check.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 370 DEFERRED'; return }
$base = 'D:\VEIL-OMNI'
$uproj = "$base\VEIL.uproject"
$cmdexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$edexe = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
Write-Output '--- SECTION 0: HARVEST FROM THE DRAIN RECORD ---'
$d = $null
$subVerdict = 'absent'
$ccdVerdict = 'absent'
$rootFound = $null
foreach ($root in @('C:\Users\Admin\phi-vault', 'C:\Users\Admin\phi-ledger-cookie-chain')) {
  if (Test-Path "$root\phi-dlam\results") { $rootFound = $root; break }
}
if ($rootFound) {
  Write-Output ("RESULTS ROOT: " + $rootFound)
  $f369 = Get-ChildItem "$rootFound\phi-dlam\results" -Filter '369-*.result.md' -File -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($f369) {
    Write-Output ("HARVEST FILE: " + $f369.Name)
    Select-String -Path $f369.FullName -Pattern 'FLOORFIX369|SUBSTEPPING' | ForEach-Object { $_.Line.Trim() } | Write-Output
    $tm = Select-String -Path $f369.FullName -Pattern 'full thickness Z=([0-9.]+)' -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($tm) { $d = [double]$tm.Matches[0].Groups[1].Value; Write-Output ("HARVESTED d = " + $d) }
    if (Select-String -Path $f369.FullName -Pattern 'SUBSTEPPING SET|SUBSTEPPING ALREADY TRUE' -ErrorAction SilentlyContinue) { $subVerdict = 'on' }
    $cm = Select-String -Path $f369.FullName -Pattern 'CDO mesh use_ccd=(\S+)' -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($cm) { $ccdVerdict = $cm.Matches[0].Groups[1].Value; Write-Output ("HARVESTED mesh CCD = " + $ccdVerdict) }
  } else { Write-Output 'NO 369 RESULT IN CLONE - direct read road runs' }
  $f367 = Get-ChildItem "$rootFound\phi-dlam\results" -Filter '367-*.result.md' -File -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($f367) { Write-Output ("367 RESULT STANDS: " + $f367.Name) }
} else { Write-Output 'RESULTS FOLDER NOT FOUND IN CLONE CANDIDATES' }
Write-Output ("SUBSTEPPING VERDICT: " + $subVerdict)
if (-not $d) {
  Write-Output '--- SECTION 0B: DIRECT THICKNESS READ ---'
  $pyD = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CmltcG9ydCB1bnJlYWwKb3V0ID0gb3BlbihPVVRGSUxFLCAndycpCmRlZiB3KHMpOgogICAgb3V0LndyaXRlKHMgKyAnXG4nKQp0YXJnZXQgPSAnL0dhbWUvTWFwcy9Hcm91bmRlZF9EaXN0cmljdHMvRmxvb3JNZXNoJwptZXNoID0gdW5yZWFsLmxvYWRfYXNzZXQodGFyZ2V0KQppZiBub3QgbWVzaDoKICAgIGFyID0gdW5yZWFsLkFzc2V0UmVnaXN0cnlIZWxwZXJzLmdldF9hc3NldF9yZWdpc3RyeSgpCiAgICBhc3NldHMgPSBhci5nZXRfYXNzZXRzX2J5X3BhdGgoJy9HYW1lJywgVHJ1ZSkKICAgIGV4YWN0ID0gW10KICAgIGZvciBhZCBpbiBhc3NldHM6CiAgICAgICAgdHJ5OgogICAgICAgICAgICBjbHMgPSBzdHIoYWQuYXNzZXRfY2xhc3NfcGF0aC5hc3NldF9uYW1lKQogICAgICAgIGV4Y2VwdCBFeGNlcHRpb246CiAgICAgICAgICAgIGNscyA9ICcnCiAgICAgICAgaWYgY2xzID09ICdTdGF0aWNNZXNoJyBhbmQgc3RyKGFkLnBhY2thZ2VfbmFtZSkuc3BsaXQoJy8nKVstMV0gPT0gJ0Zsb29yTWVzaCc6CiAgICAgICAgICAgIGV4YWN0LmFwcGVuZChzdHIoYWQucGFja2FnZV9uYW1lKSkKICAgIGlmIGxlbihleGFjdCkgPT0gMToKICAgICAgICBtZXNoID0gdW5yZWFsLmxvYWRfYXNzZXQoZXhhY3RbMF0pCiAgICAgICAgdygnUEhJIFRVTk5FTDM3MCBodW50ZWQgZXhhY3Q6ICcgKyBleGFjdFswXSkKICAgIGVsc2U6CiAgICAgICAgdygnUEhJIFRVTk5FTDM3MCBGTE9PUk1FU0ggTk9UIFVOSVFVRUxZIEZPVU5EIGNvdW50PScgKyBzdHIobGVuKGV4YWN0KSkpCmlmIG1lc2g6CiAgICB3KCdQSEkgVFVOTkVMMzcwIE1FU0g6ICcgKyBtZXNoLmdldF9wYXRoX25hbWUoKSkKICAgIHRyeToKICAgICAgICBibmQgPSBtZXNoLmdldF9ib3VuZHMoKQogICAgICAgIHcoJ1BISSBUVU5ORUwzNzAgQk9VTkRTIGZ1bGwgdGhpY2tuZXNzIFo9JS4xZicgJSAoYm5kLmJveF9leHRlbnQueiAqIDIuMCkpCiAgICBleGNlcHQgRXhjZXB0aW9uIGFzIGU6CiAgICAgICAgdygnUEhJIFRVTk5FTDM3MCBCT1VORFMgcmVhZCBlcnJvcjogJyArIHN0cihlKSkKICAgIHRyeToKICAgICAgICBicyA9IG1lc2guZ2V0X2VkaXRvcl9wcm9wZXJ0eSgnYm9keV9zZXR1cCcpCiAgICAgICAgdygnUEhJIFRVTk5FTDM3MCB0cmFjZWZsYWc9JyArIHN0cihicy5nZXRfZWRpdG9yX3Byb3BlcnR5KCdjb2xsaXNpb25fdHJhY2VfZmxhZycpKSkKICAgIGV4Y2VwdCBFeGNlcHRpb24gYXMgZToKICAgICAgICB3KCdQSEkgVFVOTkVMMzcwIEJPRFlTRVRVUCByZWFkIGVycm9yOiAnICsgc3RyKGUpKQp3KCdQSEkgVFVOTkVMMzcwIENPTVBMRVRFJykKb3V0LmNsb3NlKCkK'))
  $outD = "$base\Saved\phi_tunnel370.txt"
  $py = $pyD.Replace('OUTFILE', "'$outD'")
  Set-Content "$base\Saved\phi_tunnel370.py" -Value $py -Encoding UTF8
  Remove-Item $outD -ErrorAction SilentlyContinue
  & $cmdexe $uproj -run=pythonscript -script="$base\Saved\phi_tunnel370.py" -unattended -nopause -nosplash *> "$base\Saved\tunnel370.log"
  if (Test-Path $outD) {
    Get-Content $outD | Write-Output
    $tm2 = Select-String -Path $outD -Pattern 'full thickness Z=([0-9.]+)' -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($tm2) { $d = [double]$tm2.Matches[0].Groups[1].Value; Write-Output ("DIRECT d = " + $d) }
  } else { Write-Output 'NO TUNNEL OUTPUT FILE'; Select-String -Path "$base\Saved\tunnel370.log" -Pattern 'Error|Traceback|Exception' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output }
}
Write-Output '--- SECTION 1: EMPIRICAL PER-STEP TRAVEL ---'
$gp = Start-Process $edexe -ArgumentList @($uproj, '/Game/Maps/VEILDistrict', '-game','-log','-nullrhi','-nosound','-unattended','-nopause','-nosplash') -PassThru -WindowStyle Hidden
Start-Sleep -Seconds 35
if (-not $gp.HasExited) { Stop-Process -Id $gp.Id -Force -ErrorAction SilentlyContinue; Write-Output 'RUN STOPPED AFTER 35s CAPTURE' } else { Write-Output ("RUN EXITED EARLY code=" + $gp.ExitCode) }
Start-Sleep -Seconds 3
$perMax = $null
$logf = Get-ChildItem "$base\Saved\Logs\*.log" -File | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($logf) {
  $hits = Select-String -Path $logf.FullName -Pattern 'PHI TICK TRUTH' -ErrorAction SilentlyContinue
  $series = @()
  foreach ($h in $hits) {
    $mm = [regex]::Match($h.Line, 'tick=(\d+) capZ=(-?[0-9.]+)')
    if ($mm.Success) { $series += @(@([int]$mm.Groups[1].Value, [double]$mm.Groups[2].Value)) }
  }
  Write-Output ("TICK SAMPLES: " + $series.Count)
  for ($i = 1; $i -lt $series.Count; $i++) {
    $gap = $series[$i][0] - $series[$i-1][0]
    if ($gap -gt 0) {
      $per = [Math]::Abs($series[$i][1] - $series[$i-1][1]) / $gap
      Write-Output ("PER-STEP tick " + $series[$i-1][0] + " to " + $series[$i][0] + ": " + [Math]::Round($per, 1))
      if ($null -eq $perMax -or $per -gt $perMax) { $perMax = $per }
    }
  }
  if ($null -ne $perMax) { Write-Output ("PER-STEP MAX: " + [Math]::Round($perMax, 1)) } else { Write-Output 'NO PER-STEP SAMPLES - instrument absent or pawn not the sampled instance' }
} else { Write-Output 'NO LOG FILE FOUND' }
Write-Output '--- SECTION 2: THE VERDICT ---'
$perAna = [Math]::Round(4025.2 / 60, 1)
Write-Output ("TUNNEL INPUTS: v=4025.2 (job 333 print, both parents) analytic per-step at 60 = " + $perAna)
if ($null -eq $d) {
  Write-Output 'TUNNEL VERDICT: UNRESOLVED - D UNREAD on both roads; nothing assumed.'
} else {
  Write-Output ("TUNNEL d = " + $d)
  $anaPass = $perAna -lt $d
  Write-Output ("TUNNEL ANALYTIC: per-step " + $perAna + " below d: " + $anaPass)
  $empPass = $false
  if ($null -ne $perMax) { $empPass = $perMax -lt $d; Write-Output ("TUNNEL EMPIRICAL: per-step max " + [Math]::Round($perMax, 1) + " below d: " + $empPass) } else { Write-Output 'TUNNEL EMPIRICAL: no samples this run' }
  $perSub = [Math]::Round($perAna / 6, 1)
  $subPass = ($subVerdict -eq 'on') -and ($perSub -lt $d)
  Write-Output ("TUNNEL MITIGATION SUBSTEP: engaged=" + $subVerdict + " divided step " + $perSub + " below d: " + $subPass)
  $ccdPass = ($ccdVerdict -eq 'True')
  Write-Output ("TUNNEL MITIGATION CCD (mesh): " + $ccdVerdict)
  if ($anaPass -or $empPass -or $subPass -or $ccdPass) { Write-Output 'TUNNEL VERDICT: PASS - the floor can catch her on at least one printed leg' } else { Write-Output 'TUNNEL VERDICT: FAIL - floor collision depth must rise above per-step travel (guide minimum 20 units real depth; measured bar 67.1)' }
}
Write-Output 'JOB 370 DONE'
```
