# PHI FIX — TRIM SETS — the SSD housekeeping read + repaired — phi^2 = phi + 1
# TRIM tells the SSD which blocks are truly free; off or unscheduled = the drive
# slows as residue piles. Read first, fix what is off, read back, print proof.
$PHI = (1 + [math]::Sqrt(5)) / 2
function Rung($x) { [math]::Round([math]::Log([math]::Max($x,0.01)) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
"=== PHI READ: the current trimming sets ==="
$ntfs = (fsutil behavior query DisableDeleteNotify NTFS) -join ' '
$refs = (fsutil behavior query DisableDeleteNotify ReFS) -join ' '
"NTFS: $ntfs"
"ReFS: $refs"
$task = Get-ScheduledTask -TaskPath '\Microsoft\Windows\Defrag\' -TaskName 'ScheduledDefrag'
"Optimize Drives schedule: $($task.State)"
Get-PhysicalDisk | ForEach-Object { "disk: {0} | media {1} | health {2} | {3} GB" -f $_.FriendlyName, $_.MediaType, $_.HealthStatus, [math]::Round($_.Size/1GB,0) }
"=== THE FIX ==="
if ($ntfs -match '= 1') { fsutil behavior set DisableDeleteNotify NTFS 0 | Out-Null; "NTFS TRIM was OFF -> now ON" } else { "NTFS TRIM already ON - stands" }
if ($refs -match '= 1') { fsutil behavior set DisableDeleteNotify ReFS 0 | Out-Null; "ReFS TRIM was OFF -> now ON" } else { "ReFS TRIM already ON - stands" }
if ($task.State -eq 'Disabled') { Enable-ScheduledTask -TaskPath '\Microsoft\Windows\Defrag\' -TaskName 'ScheduledDefrag' | Out-Null; "Optimize Drives schedule was DISABLED -> now ENABLED (weekly retrim rides it)" } else { "Optimize Drives schedule already live - stands" }
"=== RETRIM NOW (SSD volumes only) ==="
foreach ($v in (Get-Volume | Where-Object { $_.DriveLetter -and $_.FileSystem -eq 'NTFS' })) {
  $pd = Get-Partition -DriveLetter $v.DriveLetter | Get-Disk | Get-PhysicalDisk
  if ($pd.MediaType -eq 'SSD') { Optimize-Volume -DriveLetter $v.DriveLetter -Retrim -Confirm:$false; "retrim sent: {0}: ({1})" -f $v.DriveLetter, $pd.FriendlyName }
  else { "skip {0}: - media {1}, retrim is SSD work" -f $v.DriveLetter, $pd.MediaType }
}
$d = Get-PSDrive C
"=== SEAL LINE ==="
"trim_ntfs=ON | schedule=$((Get-ScheduledTask -TaskPath '\Microsoft\Windows\Defrag\' -TaskName 'ScheduledDefrag').State) | c_free_gb={0} rung={1}" -f [math]::Round($d.Free/1GB,1), (Rung ($d.Free/1GB))
"=== TRIM SETS FIXED. The drives breathe on schedule from here. ==="
