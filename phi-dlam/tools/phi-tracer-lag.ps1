# PHI TRACER — reads the freeze at the source — phi^2 = phi + 1
# Samples every 2 s: CPU, disk time + queue, free RAM, page faults/sec.
# A freeze starves the sampler itself: the timestamp GAP is the measurement,
# and the lines before it name what spiked. Run while playing. Ctrl+C stops.
$PHI = (1 + [math]::Sqrt(5)) / 2
function Rung($x) { [math]::Round([math]::Log([math]::Max($x,0.01)) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
"=== TRACER LIVE - play now. Freeze windows print as FREEZE. ==="
$last = Get-Date
while ($true) {
  $now = Get-Date
  $gap = [math]::Round(($now - $last).TotalSeconds - 2, 1)
  $cpu = (Get-CimInstance Win32_PerfFormattedData_PerfOS_Processor -Filter "Name='_Total'").PercentProcessorTime
  $dsk = Get-CimInstance Win32_PerfFormattedData_PerfDisk_PhysicalDisk -Filter "Name='_Total'"
  $mem = Get-CimInstance Win32_PerfFormattedData_PerfOS_Memory
  $line = "[{0}] cpu {1}% | disk {2}% queue {3} | freeRAM {4} MB | pages/s {5}" -f $now.ToString('HH:mm:ss'), $cpu, $dsk.PercentDiskTime, $dsk.CurrentDiskQueueLength, $mem.AvailableMBytes, $mem.PagesPersec
  if ($gap -gt 3) { "*** FREEZE: sampler starved {0} s | rung {1} ***" -f $gap, (Rung $gap); $line }
  else { $line }
  $last = Get-Date
  Start-Sleep -Seconds 2
}
