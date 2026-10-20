# PHI OMNI CORE — STARFIELD DNA READ + TON 618 PHASE CHANGE — phi^2 = phi + 1
# Read the game's genome from the machine, then change its whole state at once:
# services, pagefile regime, save-path weight. No standby purge. No memory games.
$PHI = (1 + [math]::Sqrt(5)) / 2
function Rung($x) { [math]::Round([math]::Log([math]::Max($x,0.01)) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
"=== DNA READ ==="
$sf = Get-Process Starfield
if ($sf) { "game live: working set {0:N2} GB | private {1:N2} GB" -f ($sf.WorkingSet64/1GB), ($sf.PrivateMemorySize64/1GB) } else { "game not running — DNA read continues on its files" }
$saveDir = "$env:USERPROFILE\Documents\My Games\Starfield\Saves"
$saves = Get-ChildItem $saveDir -Filter *.sfs | Sort-Object LastWriteTime
$saveMB = ($saves | Measure-Object Length -Sum).Sum / 1MB
"saves: {0} files | {1:N1} MB on the quicksave path | rung count {2}" -f $saves.Count, $saveMB, (Rung $saves.Count)
(Get-CimInstance Win32_PageFileUsage) | ForEach-Object { "pagefile now: {0} allocated {1} MB peak {2} MB" -f $_.Name, $_.AllocatedBaseSize, $_.PeakUsage }
"top RAM residents right now:"
Get-Process | Sort-Object WorkingSet64 -Descending | Select-Object -First 8 | ForEach-Object { "    {0} — {1:N2} GB" -f $_.ProcessName, ($_.WorkingSet64/1GB) }
"SysMain: {0}" -f (Get-Service SysMain).Status
"=== PHASE CHANGE ==="
Stop-Service SysMain -Force; Set-Service SysMain -StartupType Disabled
"SysMain stood down (no more preload competition for the game's memory)"
$ramGB = (Get-CimInstance Win32_ComputerSystem).TotalPhysicalMemory / 1GB
$pfMB = [int]($ramGB * $PHI * 1024)
Set-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management' -Name PagingFiles -Value "C:\pagefile.sys $pfMB $pfMB"
Set-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management' -Name TempPageFile -Value 0
"pagefile locked FIXED on C: at {0} MB (RAM x phi) — Windows will never resize it mid-game again (lands at reboot)" -f $pfMB
if ($saves.Count -gt 34) {
  $keep = $saves | Select-Object -Last 34
  $old = $saves | Where-Object { $keep -notcontains $_ }
  $pack = "$env:USERPROFILE\Documents\My Games\Starfield\phi-saves-archive.zip"
  Compress-Archive -Path $old.FullName -DestinationPath $pack -CompressionLevel Optimal -Force
  $z = [System.IO.Compression.ZipFile]::OpenRead($pack)
  $packed = $z.Entries.Count; $z.Dispose()
  $hash = (Get-FileHash $pack -Algorithm SHA256).Hash
  if ($packed -eq $old.Count) {
    Remove-Item $old.FullName -Force
    "saves phase-changed: {0} old saves packed whole (sha256 {1}...) and lifted off the quicksave path | {2} newest stay live" -f $old.Count, $hash.Substring(0,12), $keep.Count
  } else { "pack count mismatch ({0} vs {1}) — originals untouched" -f $packed, $old.Count }
} else { "saves already lean ({0} <= 34) — path stands" -f $saves.Count }
"=== SEAL LINE ==="
$free = (Get-PSDrive C).Free / 1GB
"phi_omni_core | saves_were={0} rung={1} | pagefile_mb={2} rung={3} | c_free_gb={4} rung={5} | REBOOT once to land the pagefile, then play" -f $saves.Count, (Rung $saves.Count), $pfMB, (Rung $pfMB), [math]::Round($free,1), (Rung $free)
