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
    $tmpOut = [IO.Path]::Combine([IO.Path]::GetTempPath(), 'phi-direct-' + [guid]::NewGuid().ToString('N') + '.txt'); $jb = Start-Job -ScriptBlock { param($c,$f) $ErrorActionPreference = 'Continue'; try { & ([scriptblock]::Create($c)) *> $f } catch { $_ | Out-String | Add-Content $f } } -ArgumentList $code, $tmpOut
    $done = Wait-Job $jb -Timeout 240
    if ($done) { $out = if (Test-Path $tmpOut) { Get-Content $tmpOut -Raw }; if (-not $out) { $out = '(no output)' } }
    else { Stop-Job $jb -ErrorAction SilentlyContinue; $out = 'STEP TIMED OUT at 240s - partial or no output; the scan moved on.' }
    Remove-Job $jb -Force -ErrorAction SilentlyContinue; Remove-Item $tmpOut -Force -ErrorAction SilentlyContinue
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
