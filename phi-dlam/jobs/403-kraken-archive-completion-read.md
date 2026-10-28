<!-- PHI-DIRECT -->
```powershell
Write-Output '=== KRAKEN ARCHIVE COMPLETION READ 403 - THE PACK, THREE HOURS ON (Job 358 launched the parent archive pack detached on this PC - driver pid 5684, script kraken_archive_driver.py, log at D:\VEIL-OMNI-ARCHIVE\pack358.log and manifest at D:\VEIL-OMNI-ARCHIVE\KRAKEN_MANIFEST.json - and job 378 read it still running: 12087 entries, all verified, bytes in 24226504444, bytes krk 3261478835, ratio 0.1346, with D:\OMNI-UE and both Builds trees still standing. THIS JOB IS READ-ONLY and changes nothing: one, print whether the pack driver still stands, with pid and start time. Two, print the last 25 lines of the pack log. Three, print the manifest summary - entries, packed, kept raw, verified, bytes in, bytes krk, and the ratio computed from those two byte counts to four decimals. Four, census the parent trees - D:\OMNI-UE, D:\VEIL if it stands, and the Builds trees job 378 named - each STANDING with its file count and byte total, or ABSENT. Five, print the verdict in one line: PACK DONE when the log carries its completion print and the driver no longer stands, or PACK STILL RUNNING with the last log line as the evidence.) ==='
$arch = 'D:\VEIL-OMNI-ARCHIVE'
$log = "$arch\pack358.log"
Write-Output '--- SECTION 1: DRIVER PROCESS ---'
$drvFound = $false
$p5684 = Get-Process -Id 5684 -ErrorAction SilentlyContinue
if ($p5684) {
  $drvFound = $true
  Write-Output ("PHI PACK403 DRIVER PID5684 STANDING name=" + $p5684.ProcessName + " start=" + $p5684.StartTime.ToString('yyyy-MM-dd HH:mm:ss'))
} else {
  Write-Output 'PHI PACK403 DRIVER PID5684 NOT STANDING'
}
$drv = Get-CimInstance Win32_Process -ErrorAction SilentlyContinue | Where-Object { $_.CommandLine -and ($_.CommandLine -match 'kraken_archive_drive') }
if ($drv) {
  foreach ($p in $drv) {
    $drvFound = $true
    Write-Output ("PHI PACK403 DRIVER BY COMMAND LINE pid=" + $p.ProcessId + " start=" + ([Management.ManagementDateTimeConverter]::ToDateTime($p.CreationDate)).ToString('yyyy-MM-dd HH:mm:ss'))
  }
} else {
  Write-Output 'PHI PACK403 NO PROCESS CARRIES THE PACK SCRIPT NAME'
}
Write-Output '--- SECTION 2: PACK LOG TAIL ---'
$logDone = $false
$lastLine = ''
if (Test-Path $log) {
  $logItem = Get-Item $log
  Write-Output ("PHI PACK403 LOG STANDS: " + $log + ' bytes=' + $logItem.Length + ' lastwrite=' + $logItem.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss'))
  Get-Content $log -Tail 25 | Write-Output
  $lastLine = Get-Content $log -Tail 1
  if ((Get-Content $log -Raw) -match 'ARCHIVE DRIVER DONE') { $logDone = $true }
} else {
  Write-Output 'PHI PACK403 pack358.log ABSENT'
}
Write-Output '--- SECTION 3: MANIFEST SUMMARY ---'
$manPath = "$arch\KRAKEN_MANIFEST.json"
if (Test-Path $manPath) {
  try {
    $man = Get-Content $manPath -Raw | ConvertFrom-Json
    $entries = @($man.entries)
    $packed = 0; $keptRaw = 0; $verified = 0; $sumIn = 0; $sumKrk = 0
    foreach ($e in $entries) {
      if ($e.action -eq 'packed') { $packed++ }
      if ($e.action -like 'kept_raw*') { $keptRaw++ }
      if ($e.verified -eq $true) { $verified++ }
      if ($null -ne $e.orig_size) { $sumIn += [int64]$e.orig_size }
      if ($null -ne $e.krk_size) { $sumKrk += [int64]$e.krk_size }
    }
    Write-Output ("PHI PACK403 MANIFEST entries=" + $entries.Count + " packed=" + $packed + " kept_raw=" + $keptRaw + " verified=" + $verified)
    Write-Output ("PHI PACK403 MANIFEST BYTES in=" + $sumIn + " krk=" + $sumKrk)
    if ($sumIn -gt 0) { Write-Output ("PHI PACK403 MANIFEST RATIO krk_over_in=" + ('{0:F4}' -f ($sumKrk / $sumIn))) }
  } catch {
    Write-Output ("PHI PACK403 MANIFEST PARSE ERROR: " + $_.Exception.Message)
  }
} else {
  Write-Output 'PHI PACK403 KRAKEN_MANIFEST.json ABSENT AT ARCHIVE ROOT'
}
Write-Output '--- SECTION 4: PARENT TREE CENSUS ---'
foreach ($root in @('D:\OMNI-UE', 'D:\VEIL', 'D:\Builds\VEIL', 'D:\Builds\OMNI')) {
  if (Test-Path $root) {
    $tf = Get-ChildItem $root -Recurse -File -ErrorAction SilentlyContinue
    $tm = $tf | Measure-Object -Property Length -Sum
    Write-Output ("PHI PACK403 TREE " + $root + " state=STANDING files=" + $tf.Count + " bytes=" + $tm.Sum)
  } else {
    Write-Output ("PHI PACK403 TREE " + $root + " state=ABSENT")
  }
}
Write-Output '--- SECTION 5: VERDICT ---'
if ($logDone -and -not $drvFound) {
  Write-Output 'PHI PACK403 VERDICT: PACK DONE'
} else {
  Write-Output 'PHI PACK403 VERDICT: PACK STILL RUNNING'
  if ($lastLine) { Write-Output ("LAST LOG LINE AS EVIDENCE: " + $lastLine) } else { Write-Output 'NO LOG LINE STANDS AS EVIDENCE' }
}
Write-Output 'JOB 403 DONE'
```
