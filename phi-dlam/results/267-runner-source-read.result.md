# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 01:21:49 UTC

## STEP 1
```
=== Job 266 named the wrapper: phi-direct-drain.ps1:28 and phi-dlam.ps1:457 both run DIRECT job code through Start-Job with the output piped to Out-String inside the child - the CLIXML transport that throws node type Text. A patch written against one line, blind to the timeout and result machinery around it, could break the drain itself. This job prints the terrain whole: phi-direct-drain.ps1 entire (2,394 bytes) and phi-dlam.ps1 lines 200-230 (the Invoke-Expression path), 320-350 (the cap region), 440-500 (the DIRECT Start-Job region). Read-only. ===
===== phi-direct-drain.ps1 WHOLE =====
# PHI-DIRECT-DRAIN - the NV center's hand (v5.31 INSTANT WORK, Tyree's word,
# 2026-10-26). Spawned hidden the moment the seat opens when DIRECT jobs are
# queued: it pulls, executes every PHI-DIRECT job's powershell blocks raw -
# no brain, no queue, no waiting - writes the reports, pushes, and exits.
# The seat never waits on it; the work never waits for a typed word. Brain
# jobs are untouched here: they still run on Tyree's 'work'.
param([string]$Vault)
$ErrorActionPreference = 'Continue'
if (-not $Vault) { $Vault = Join-Path $env:USERPROFILE 'phi-vault' }
$env:GIT_TERMINAL_PROMPT = '0'
$jobsDir = Join-Path $Vault 'phi-dlam\jobs'
$resultsDir = Join-Path $Vault 'phi-dlam\results'
git -C $Vault pull --quiet 2>$null
foreach ($job in @(Get-ChildItem $jobsDir -Filter '*.md' -ErrorAction SilentlyContinue)) {
  $resultPath = Join-Path $resultsDir ($job.BaseName + '.result.md')
  if (Test-Path $resultPath) { continue }
  $jobText = Get-Content $job.FullName -Raw
  if ($jobText -notmatch 'PHI-DIRECT') { continue }
  $blocks = [regex]::Matches($jobText, '(?s)```powershell\s*(.*?)```')
  if ($blocks.Count -eq 0) { continue }
  $report = New-Object System.Collections.ArrayList
  [void]$report.Add('# DIRECT JOB REPORT - executed by the NV center (phi-direct-drain, INSTANT WORK), no brain calls')
  [void]$report.Add("When: $((Get-Date).ToUniversalTime().ToString('yyyy-MM-dd HH:mm:ss')) UTC")
  $n = 0
  foreach ($m in $blocks) {
    $n++
    $code = $m.Groups[1].Value.Trim()
    $jb = Start-Job -ScriptBlock { param($c) $ErrorActionPreference = 'Continue'; & ([scriptblock]::Create($c)) 2>&1 | Out-String } -ArgumentList $code
    $done = Wait-Job $jb -Timeout 240
    if ($done) { $out = Receive-Job $jb; if (-not $out) { $out = '(no output)' } }
    else { Stop-Job $jb -ErrorAction SilentlyContinue; $out = 'STEP TIMED OUT at 240s - partial or no output; the scan moved on.' }
    Remove-Job $jb -Force -ErrorAction SilentlyContinue
    [void]$report.Add('')
    [void]$report.Add("## STEP $n")
    [void]$report.Add('```')
    [void]$report.Add([string]$out)
    [void]$report.Add('```')
  }
  Set-Content -Path $resultPath -Value ($report -join "`r`n") -Encoding UTF8
  git -C $Vault add phi-dlam/results 2>$null
  git -C $Vault commit -m "direct job result: $($job.BaseName)" --quiet 2>$null
  git -C $Vault push --quiet 2>$null
}
===== phi-dlam.ps1 lines 200-230 =====
200:   $t = [string]$text
201:   if ($t -match 'get-credential') { return $true }
202:   if ($t -match 'convertfrom-securestring') { return $true }
203:   if ($t -match 'google_token') { return $true }
204:   if ($t -match '_token\.txt') { return $true }
205:   if ($t -match 'read-host[^\n]*-assecurestring') { return $true }
206:   return $false
207: }
208: 
209: function Invoke-Tool($name, $a) {
210:   try {
211:     switch ($name) {
212:       'run_powershell' {
213:         if (Test-CredentialGrab $a.command) { return 'BLOCKED BY RUNNER LAW: credential capture is forbidden - no prompting for, reading, or storing passwords, tokens, or API keys. The ARTEMIS key already lives in ARTEMIS''s own .env. Change roads.' }
214:         $out = Invoke-Expression $a.command 2>&1 | Out-String
215:         if ([string]::IsNullOrWhiteSpace($out)) {
216:           return 'NO OUTPUT - the command printed nothing. Do NOT invent a value. Run a corrected command that PRINTS its answer, or tell Tyree the value is UNREAD.'
217:         }
218:         return $out.Trim()
219:       }
220:       'open_program' {
221:         Start-Process $a.target
222:         return "Opened: $($a.target)"
223:       }
224:       'read_file' {
225:         return (Get-Content -Path $a.path -Raw -ErrorAction Stop)
226:       }
227:       'write_file' {
228:         if ((Test-CredentialGrab $a.path) -or (Test-CredentialGrab $a.content) -or ($a.path -match '(token|credential|secret|password)')) { return 'BLOCKED BY RUNNER LAW: no file may hold credentials, tokens, or secrets for the brain. Change roads.' }
229:         $parentDir = Split-Path -Parent $a.path
230:         if ($parentDir -and -not (Test-Path $parentDir)) { New-Item -ItemType Directory -Path $parentDir -Force | Out-Null }
===== phi-dlam.ps1 lines 320-350 =====
320:     $tag = [guid]::NewGuid().ToString('N')
321:     $bodyFile = Join-Path $env:TEMP "dlam-body-$tag.json"
322:     $outFile = Join-Path $env:TEMP "dlam-out-$tag.ndjson"
323:     $errFile = Join-Path $env:TEMP "dlam-err-$tag.log"
324:     [System.IO.File]::WriteAllText($bodyFile, $json)
325:     $sw = [System.Diagnostics.Stopwatch]::StartNew()
326:     # v5.25 (2026-10-26): curl now runs as a DIRECT child process, and curl's
327:     # own --max-time is the hard cap (capSec + 30s grace). The runner polls
328:     # the output file for the heartbeat and kills the process itself past
329:     # capSec. No Start-Job, no Wait-Job/Stop-Job: stopping a PS job that
330:     # hosts a blocked native process is the fragile link the v5.22 fix
331:     # still depended on - and the step-1 worker hang survived v5.22 in the
332:     # field. A killed process is dead; every wait below carries a bound.
333:     $capped = $false
334:     $proc = $null
335:     try {
336:       $curlArgs = @('-s', '-N', '--connect-timeout', '15', '--max-time', [string]($capSec + 30), $API, '-H', 'Content-Type: application/json', '--data-binary', "@$bodyFile", '-o', $outFile)
337:       $proc = Start-Process -FilePath 'curl.exe' -ArgumentList $curlArgs -PassThru -WindowStyle Hidden -RedirectStandardError $errFile
338:     } catch {
339:       Write-Host "[brain call failed - retry $try of $tries`: could not start curl: $($_.Exception.Message)]" -ForegroundColor Red
340:     }
341:     if ($proc) {
342:       while (-not $proc.HasExited) {
343:         Start-Sleep -Seconds 5
344:         $proc.Refresh()
345:         if ($proc.HasExited) { break }
346:         $bytes = 0
347:         if (Test-Path $outFile) { $bytes = (Get-Item $outFile).Length }
348:         Write-Host "[brain working... $([int]$sw.Elapsed.TotalSeconds)s - $bytes bytes in]" -ForegroundColor DarkCyan
349:         if ($sw.Elapsed.TotalSeconds -gt $capSec) { $capped = $true; try { $proc.Kill() } catch {}; break }
350:         # v5.26: silence is the stuck state - 90s with ZERO bytes in means the
===== phi-dlam.ps1 lines 440-500 =====
440:   # executes. A PHI-DIRECT job carries fenced powershell blocks: they run in
441:   # order, raw, with no brain call between them. There is no thinking pause
442:   # because there is no lone local brain thinking in circles - the universe
443:   # doesn't stall. Each block is bounded at 240s; a timeout is written into
444:   # the report and the scan moves on. Raw output lands verbatim.
445:   Write-Host '[nv center] DIRECT job - the universe already thought; this seat executes.' -ForegroundColor Magenta
446:   $blocks = [regex]::Matches($jobText, '(?s)```powershell\s*(.*?)```')
447:   if ($blocks.Count -eq 0) { Write-Host '[nv center] no powershell blocks found - cannot run direct.' -ForegroundColor Red; return 'job-stuck' }
448:   $report = New-Object System.Collections.ArrayList
449:   [void]$report.Add('# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls')
450:   [void]$report.Add("When: $((Get-Date).ToUniversalTime().ToString('yyyy-MM-dd HH:mm:ss')) UTC")
451:   $n = 0
452:   foreach ($m in $blocks) {
453:     $n++
454:     $code = $m.Groups[1].Value.Trim()
455:     Write-Host "[nv step $n of $($blocks.Count)] running..." -ForegroundColor DarkCyan
456:     $sw = [System.Diagnostics.Stopwatch]::StartNew()
457:     $jb = Start-Job -ScriptBlock { param($c) $ErrorActionPreference = 'Continue'; & ([scriptblock]::Create($c)) 2>&1 | Out-String } -ArgumentList $code
458:     $done = Wait-Job $jb -Timeout 240
459:     if ($done) { $out = Receive-Job $jb; if (-not $out) { $out = '(no output)' } }
460:     else { Stop-Job $jb -ErrorAction SilentlyContinue; $out = 'STEP TIMED OUT at 240s - partial or no output; the scan moved on.' }
461:     Remove-Job $jb -Force -ErrorAction SilentlyContinue
462:     Write-Host "[nv step $n done in ~$([int]$sw.Elapsed.TotalSeconds)s]" -ForegroundColor DarkCyan
463:     [void]$report.Add('')
464:     [void]$report.Add("## STEP $n")
465:     [void]$report.Add('```')
466:     [void]$report.Add([string]$out)
467:     [void]$report.Add('```')
468:   }
469:   Set-Content -Path $resultPath -Value ($report -join "`r`n") -Encoding UTF8
470:   Write-Host "[nv center] report written: $resultPath" -ForegroundColor Magenta
471:   return 'done'
472: }
473: 
474: function Invoke-Job($jobText, $primeText, $resultPath) {
475:   if ($jobText -match 'PHI-DIRECT') { return Invoke-DirectJob $jobText $resultPath }
476:   $h = New-Object System.Collections.ArrayList
477:   [void]$h.Add(@{ role = 'user'; content = 'WORKER MODE. You are PHI-DLAM, Tyrees local agent; your framework - phi squared = phi + 1, the ten laws, the constants - is already in your system prompt. The next message is a JOB from the queue. Work it to done over as many steps as it takes, calling real tools through the tool channel. When the job is complete, use write_file to save the full report to the results path named in the job, then give a one-line summary. Reply to this message with exactly one word: READY' })
478:   $boot = Send-Chat $h $false 280 2 280
479:   if ($boot.content -match 'UNREACHABLE') {
480:     Write-Host '[runner] JOB ABORTED: the brain did not answer the worker boot call. Job NOT run - the runner logs the reason as this job result.' -ForegroundColor Red
481:     return 'brain-dead'
482:   }
483:   [void]$h.Add(@{ role = 'assistant'; content = $boot.content })
484:   [void]$h.Add(@{ role = 'user'; content = $jobText })
485:   $steps = 0
486:   $noProgress = 0
487:   while ($steps -lt 200) {
488:     $steps++
489:     Write-Host "[step $steps] ...thinking" -ForegroundColor DarkGray
490:     $stepSw = [System.Diagnostics.Stopwatch]::StartNew()
491:     # v5.28 reversal: step 1 carries the evaluation itself - cap 280 and a
492:     # zero-byte grace of 280, so the one long read happens once, streamed,
493:     # with the heartbeat naming its seconds. Later steps keep 120/90.
494:     $cap = 120; $grace = 90
495:     if ($steps -eq 1) { $cap = 280; $grace = 280 }
496:     try { $msg = Send-Chat $h $true $cap 1 $grace } catch {
497:       Write-Host "[runner] step $steps brain call threw: $($_.Exception.Message) - job stopped, reason will be logged." -ForegroundColor Red
498:       return 'brain-dead'
499:     }
500:     Write-Host "[step $steps answered in ~$([int]$stepSw.Elapsed.TotalSeconds)s]" -ForegroundColor DarkCyan
RUNNER SOURCE READ DONE

```
