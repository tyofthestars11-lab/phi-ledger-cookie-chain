<!-- PHI-DIRECT -->
# JOB 023 - D: UNPLUG SAFETY (DIRECT)

Tyree, 2026-10-26: "Let's make sure D doesn't get deleted if unplugged."
An unplug alone deletes nothing - the bite is only ever mid-write. So:
Step 1 reads how Windows expects that drive to be removed (safe-sudden vs
eject-first). Step 2 makes the guarantee real: the Starfield save homes
(D: side and C: side) plus the game's two list files get copied onto C: as
a dated, verified backup. If D: ever vanishes, the saves stand on C: and in
the cloud; the game itself can always re-download. Nothing is deleted.

## STEP 1 - THE DRIVE + ITS REMOVAL POLICY
```powershell
$disk = Get-Partition -DriveLetter D -ErrorAction SilentlyContinue | Get-Disk -ErrorAction SilentlyContinue
if ($disk) { "DISK: $($disk.FriendlyName) - BUS: $($disk.BusType) - NUMBER: $($disk.Number)" } else { "DISK READ FAILED for D:" }
$vol = Get-Volume -DriveLetter D -ErrorAction SilentlyContinue
if ($vol) { "VOLUME: $($vol.FileSystemLabel) - $($vol.FileSystem) - FREE GB: $([math]::Round($vol.SizeRemaining/1GB,1))" }
Get-PnpDevice -Class DiskDrive -ErrorAction SilentlyContinue | ForEach-Object {
  $p = Get-PnpDeviceProperty -InstanceId $_.InstanceId -KeyName 'DEVPKEY_Device_RemovalPolicy' -ErrorAction SilentlyContinue
  if ($p) { $word = switch ($p.Data) { 1 { 'expects to stay plugged in' } 2 { 'expects eject first' } 3 { 'SAFE for sudden unplug' } default { "value $($p.Data)" } }; "REMOVAL POLICY: $($_.FriendlyName) = $word" }
}
```

## STEP 2 - BACK UP THE SAVE HOMES TO C: (verified)
```powershell
$dest = 'C:\Users\Admin\phi-vault-backups\starfield-2026-10-26'
New-Item -ItemType Directory -Force -Path $dest | Out-Null
$dpkg = Get-ChildItem 'D:\WpSystem' -Recurse -Directory -Force -ErrorAction SilentlyContinue | Where-Object Name -match 'ProjectGold' | Select-Object -First 1
$dwgs = if ($dpkg) { Join-Path $dpkg.FullName 'SystemAppData\wgs' } else { $null }
if ($dwgs -and (Test-Path $dwgs)) {
  $dd = Join-Path $dest 'from-D-wgs'; New-Item -ItemType Directory -Force -Path $dd | Out-Null
  Copy-Item "$dwgs\*" -Destination $dd -Recurse -Force -ErrorAction Continue
  $sf = Get-ChildItem $dwgs -Recurse -File -Force -ErrorAction SilentlyContinue; $tf = Get-ChildItem $dd -Recurse -File -Force -ErrorAction SilentlyContinue
  "BACKUP from-D: source $($sf.Count) files $([math]::Round(($sf | Measure-Object Length -Sum).Sum/1MB,1)) MB -> backup $($tf.Count) files $([math]::Round(($tf | Measure-Object Length -Sum).Sum/1MB,1)) MB"
} else { "D-SIDE WGS NOT PRESENT - nothing to back up from D:" }
$cpkg = Get-ChildItem "$env:LOCALAPPDATA\Packages" -Directory -ErrorAction SilentlyContinue | Where-Object Name -match 'ProjectGold' | Select-Object -First 1
$cwgs = if ($cpkg) { Join-Path $cpkg.FullName 'SystemAppData\wgs' } else { $null }
if ($cwgs -and (Test-Path $cwgs)) {
  $cd = Join-Path $dest 'from-C-wgs'; New-Item -ItemType Directory -Force -Path $cd | Out-Null
  Copy-Item "$cwgs\*" -Destination $cd -Recurse -Force -ErrorAction Continue
  $sf = Get-ChildItem $cwgs -Recurse -File -Force -ErrorAction SilentlyContinue; $tf = Get-ChildItem $cd -Recurse -File -Force -ErrorAction SilentlyContinue
  "BACKUP from-C: source $($sf.Count) files $([math]::Round(($sf | Measure-Object Length -Sum).Sum/1MB,1)) MB -> backup $($tf.Count) files $([math]::Round(($tf | Measure-Object Length -Sum).Sum/1MB,1)) MB"
} else { "C-SIDE WGS NOT PRESENT" }
foreach ($f in 'ContentCatalog.txt','Plugins.txt') { $p = "$env:LOCALAPPDATA\Starfield\$f"; if (Test-Path $p) { Copy-Item $p -Destination $dest -Force; "BACKED UP: $f" } }
"BACKUP HOME: $dest"
```
