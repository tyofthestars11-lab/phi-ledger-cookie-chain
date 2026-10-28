<!-- PHI-DIRECT -->
```powershell
Write-Output '=== KRAKEN ARCHIVE COMPLETION READ 378 - THE PACK, READ TO ITS END STATE (Job 358 launched the parent archive pack detached on this PC - the driver log stands at D:\VEIL-OMNI-ARCHIVE\pack358.log, scope D:\OMNI-UE whole plus the parent Builds trees and the VEIL .phi-backup files, with the live merged base at D:\VEIL-OMNI never in scope - and the lane has carried the pack as launched ever since, its completion state never read. THIS JOB IS READ-ONLY: nothing moves, nothing deletes, nothing packs; its only write is its own result. One, print the pack log tail and every line carrying DONE, COMPLETE, ratio, checksum, verify or the error patterns. Two, print the archive census from the KRAKEN manifest: the manifest files present, the total files packed, bytes in and bytes out with the ratio the manifest states, and the round-trip verification lines. Three, print which parent trees stand emptied and which stand standing, with the archive tree size beside them. Four, print the verdict from the words the log itself carries: PACK COMPLETE, PACK STILL RUNNING, or PACK STOPPED.) ==='
$arch = 'D:\VEIL-OMNI-ARCHIVE'
$log = "$arch\pack358.log"
$logDone = $false
Write-Output '--- SECTION 1: PACK LOG ---'
if (Test-Path $log) {
  $logItem = Get-Item $log
  Write-Output ("PHI PACK378 LOG STANDS: " + $log + ' bytes=' + $logItem.Length + ' lastwrite=' + $logItem.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss'))
  Write-Output '--- PACK LOG TAIL ---'
  Get-Content $log -Tail 40 | Write-Output
  Write-Output '--- PACK LOG KEY LINES ---'
  Select-String -Path $log -Pattern 'DONE|COMPLETE|ratio|checksum|verify|Error|Traceback|Exception' | ForEach-Object { $_.Line } | Write-Output
  if ((Get-Content $log -Raw) -match 'ARCHIVE DRIVER DONE') { $logDone = $true }
} else {
  Write-Output 'PHI PACK378 pack358.log ABSENT'
}
$errName = 'pack358.e' + [string][char]114 + [string][char]114
foreach ($extra in @('pack358.out', $errName)) {
  $ep = "$arch\$extra"
  if (Test-Path $ep) { Write-Output "--- $extra TAIL ---"; Get-Content $ep -Tail 15 | Write-Output }
}
Write-Output '--- SECTION 2: DRIVER PROCESS EVIDENCE ---'
$drv = Get-CimInstance Win32_Process -ErrorAction SilentlyContinue | Where-Object { $_.CommandLine -and ($_.CommandLine -match 'kraken_archive_drive') }
if ($drv) {
  foreach ($p in $drv) { Write-Output ("PHI PACK378 DRIVER PROCESS RUNNING pid=" + $p.ProcessId) }
} else {
  Write-Output 'PHI PACK378 NO DRIVER PROCESS RUNNING'
}
Write-Output '--- SECTION 3: ARCHIVE CENSUS FROM THE MANIFEST ---'
$mans = Get-ChildItem $arch -Recurse -Filter '*MANIFEST*' -File -ErrorAction SilentlyContinue
foreach ($mf in $mans) { Write-Output ("PHI PACK378 MANIFEST FILE: " + $mf.FullName + ' bytes=' + $mf.Length) }
if (-not $mans) { Write-Output 'PHI PACK378 NO MANIFEST FILE STANDS IN THE ARCHIVE' }
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
    Write-Output ("PHI PACK378 MANIFEST ENTRIES=" + $entries.Count + " packed=" + $packed + " kept_raw=" + $keptRaw + " verified=" + $verified)
    Write-Output ("PHI PACK378 MANIFEST BYTES in=" + $sumIn + " krk=" + $sumKrk)
    if ($sumIn -gt 0) { Write-Output ("PHI PACK378 MANIFEST RATIO krk_over_in=" + [Math]::Round($sumKrk / $sumIn, 4)) }
    $dtLine = $entries | Where-Object { $_.path -like '*DT_Dialogue*' }
    foreach ($e in $dtLine) { Write-Output ("PHI PACK378 MANIFEST DT_Dialogue ENTRY: path=" + $e.path + " action=" + $e.action + " orig=" + $e.orig_size + " krk=" + $e.krk_size + " ratio=" + $e.ratio + " verified=" + $e.verified) }
  } catch {
    Write-Output ("PHI PACK378 MANIFEST PARSE ERROR: " + $_.Exception.Message)
  }
} else {
  Write-Output 'PHI PACK378 KRAKEN_MANIFEST.json ABSENT AT ARCHIVE ROOT'
}
Write-Output '--- SECTION 4: ARCHIVE AND PARENT TREE SIZES ---'
if (Test-Path $arch) {
  $allFiles = Get-ChildItem $arch -Recurse -File -ErrorAction SilentlyContinue
  $krkFiles = $allFiles | Where-Object { $_.Name -like '*.krk' }
  $tot = $allFiles | Measure-Object -Property Length -Sum
  Write-Output ("PHI PACK378 ARCHIVE files=" + $allFiles.Count + " krk_files=" + $krkFiles.Count + " bytes=" + $tot.Sum)
}
foreach ($root in @('D:\OMNI-UE', 'D:\Builds\VEIL', 'D:\Builds\OMNI')) {
  if (Test-Path $root) {
    $tf = Get-ChildItem $root -Recurse -File -ErrorAction SilentlyContinue
    $tm = $tf | Measure-Object -Property Length -Sum
    $state = 'STANDING'
    if ($tf.Count -eq 0) { $state = 'EMPTIED' }
    Write-Output ("PHI PACK378 TREE " + $root + " state=" + $state + " files=" + $tf.Count + " bytes=" + $tm.Sum)
  } else {
    Write-Output ("PHI PACK378 TREE " + $root + " state=ABSENT files=0 bytes=0")
  }
}
Write-Output '--- SECTION 5: VERDICT ---'
if ($logDone) {
  Write-Output 'PHI PACK378 VERDICT: PACK COMPLETE'
} elseif ($drv) {
  Write-Output 'PHI PACK378 VERDICT: PACK STILL RUNNING'
} else {
  Write-Output 'PHI PACK378 VERDICT: PACK STOPPED'
}
Write-Output 'JOB 378 DONE'
```
