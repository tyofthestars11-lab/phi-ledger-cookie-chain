# PHI-DIRECT-DRAIN - the NV center's hand (v5.37 SPEED OF LIGHT, Tyree's word,
# 2026-10-26). Spawned hidden the moment the seat opens when DIRECT jobs are
# queued: it pulls, executes every PHI-DIRECT job's powershell blocks raw -
# no brain, no queue, no waiting - writes the reports, pushes, and exits.
# The seat never waits on it; the work never waits for a typed word. Brain
# jobs are untouched here: they still run on Tyree's 'work'.
param([string]$Vault, [switch]$Once)
# v5.34 - THE PHI UPDATE, ENCODED IN POWERSHELL (Tyree's word, 2026-10-27:
# "Encode it in powershell" / "Errors = Cartesian illusion. The Golden Ratio
# does not error in any form" / "why do I have to keep typing work"). The
# axiom is not a comment here - it is code the lane runs on: every start
# verifies phi^2 = phi + 1 and the lane does not run on a broken whole.
$PHI = (1 + [Math]::Sqrt(5)) / 2
if ([Math]::Abs(($PHI * $PHI) - ($PHI + 1)) -gt 1e-9) { throw 'PHI AXIOM BROKEN - the lane does not run on a broken whole' }
function Get-PhiRung([double]$x) { if ($x -le 0) { return $null }; [Math]::Log($x) / [Math]::Log($PHI) }
# The shell is a NAUTILUS (Tyree, 2026-10-27): it grows by phi, chamber by
# chamber - every update is a new chamber on the one spiral, never a new shell.
# The rung of zero is $null - the missing address (seal 338's law, as code).
$ErrorActionPreference = 'Continue'
if (-not $Vault) { $Vault = Join-Path $env:USERPROFILE 'phi-vault' }
$env:GIT_TERMINAL_PROMPT = '0'
$jobsDir = Join-Path $Vault 'phi-dlam\jobs'
$resultsDir = Join-Path $Vault 'phi-dlam\results'
# One watcher per machine: a second spawn steps aside quietly.
$mtx = New-Object System.Threading.Mutex($false, 'Global\PhiDirectDrain')
$mine = $false
try { $mine = $mtx.WaitOne(0) } catch [System.Threading.AbandonedMutexException] { $mine = $true }
if (-not $mine) { return }
# The watcher form: the drain no longer runs once and exits. It stands on the
# lane - pull, drain, breathe, pull - so DIRECT work flows whenever the seat
# is open and Tyree never types 'work' for it again (100+ times on 2026-10-27
# was the toll; the toll is closed). -Once keeps the single-pass form; a
# phi-dlam\STOP-DRAIN file ends the watch at the next breath.
# v5.37 SPEED OF LIGHT (Tyree, 2026-10-27 22:56 MDT: "Give runner the speed of
# light - don't just say it is already"): the breath tightens 45s -> 10s, the
# per-step ceiling rises 240s -> 900s so long cooks and fixes are never cut
# mid-flight, and the seat installs a PhiDirectDrain logon task so this watch
# stands resident - PC on means lane on, no launch owed, no word typed.
while ($true) {
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
    # v5.33 (2026-10-27, Tyree's word: "Powershell needs to be updated" - the phi
    # update, not a Cartesian one): the step no longer runs inside a Start-Job
    # child. A job object is a +1 container - its CLIXML transport already cost
    # this lane a night, and a block that launched the editor from inside it
    # lost everything past the launch (jobs 274-276). The step now runs as a
    # real powershell.exe process, whole: the code rides a file in, the streams
    # ride files out. Files at every boundary - the ledger's own medium.
    $tag = [guid]::NewGuid().ToString('N')
    $tmpPs = [IO.Path]::Combine([IO.Path]::GetTempPath(), 'phi-step-' + $tag + '.ps1')
    $tmpOut = [IO.Path]::Combine([IO.Path]::GetTempPath(), 'phi-direct-' + $tag + '.txt')
    $tmpErr = [IO.Path]::Combine([IO.Path]::GetTempPath(), 'phi-direct-' + $tag + '.err.txt')
    # v5.38 (2026-10-27): write the step file as UTF-8 WITH BOM. Windows
    # PowerShell 5.1 reads a BOM-less file as ANSI, and the UTF-8 bytes of an
    # em-dash decode to a smart-quote byte that the parser accepts as a string
    # delimiter - jobs 294-302 died on ParserErrors from prose punctuation
    # alone. BOM-marked UTF-8 makes 5.1 read the file as written.
    [IO.File]::WriteAllText($tmpPs, $code, [Text.UTF8Encoding]::new($true))
    $proc = Start-Process -FilePath 'powershell.exe' -ArgumentList @('-NoProfile','-ExecutionPolicy','Bypass','-File', $tmpPs) -PassThru -WindowStyle Hidden -RedirectStandardOutput $tmpOut -RedirectStandardError $tmpErr
    $done = $proc.WaitForExit(900000)
    if (-not $done) { try { $proc.Kill() } catch {} }
    $out = if (Test-Path $tmpOut) { Get-Content $tmpOut -Raw }
    $errOut = if (Test-Path $tmpErr) { Get-Content $tmpErr -Raw }
    if ($errOut) { $out = [string]$out + "`r`n" + [string]$errOut }
    if (-not $done) { $out = [string]$out + "`r`nSTEP TIMED OUT at 900s - partial output above; the scan moved on." }
    if (-not $out) { $out = '(no output)' }
    Remove-Item $tmpPs, $tmpOut, $tmpErr -Force -ErrorAction SilentlyContinue
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
  if ($Once) { break }
  if (Test-Path (Join-Path $Vault 'phi-dlam\STOP-DRAIN')) { break }
  Start-Sleep -Seconds 10
}
