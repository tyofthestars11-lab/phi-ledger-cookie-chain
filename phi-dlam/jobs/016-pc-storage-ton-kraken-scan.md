<!-- PHI-DIRECT -->
# JOB 016 - PC STORAGE / TON KRAKEN SCAN (DIRECT - NV CENTER EXECUTION)

Authored by the universe seat (Golden Ratio Muse) on Tyree's word, 2026-10-26.
This is a DIRECT job: the powershell blocks below run in order, raw, with no
brain calls between them. REPORT ONLY - this job deletes nothing, moves
nothing, compresses nothing. Tyree names what dies; the scan only measures.

## LAW (Tyree, 2026-10-26)
- C: is the fast drive: 476 GB total, was 34 GB free at first read (7.1%).
  On 2026-10-13 (job 001) C: read exactly 100.4 GB free - about 66 GB LANDED
  in 13 days. Naming that growth is this scan's first purpose.
- Starfield was reinstalled toward D: by Tyree's own hand (Xbox app); other
  Xbox games moved to D: the same way. The scan reads the state as it stands.
- Vortex: the PROGRAM is on C: (small); the mod staging/downloads live on D:.
  Mod ground (My Games\Starfield, Vortex folders) is MEASURED, never touched.

## STEP 1 - DISKS: which stone serves which letter + special files
```powershell
Get-PhysicalDisk | ForEach-Object { "DISK: $($_.FriendlyName) | $($_.MediaType) | $([math]::Round($_.Size/1GB,1)) GB | $($_.HealthStatus)" }
Get-Partition | Where-Object DriveLetter | ForEach-Object { "PARTITION: $($_.DriveLetter): on Disk $($_.DiskNumber)" }
Get-CimInstance Win32_LogicalDisk -Filter "DriveType=3" | ForEach-Object { "DRIVE $($_.DeviceID) total $([math]::Round($_.Size/1GB,1)) GB free $([math]::Round($_.FreeSpace/1GB,1)) GB" }
'pagefile.sys','hiberfil.sys','swapfile.sys' | ForEach-Object { $f = Get-Item "C:\$_" -Force -ErrorAction SilentlyContinue; if ($f) { "$_ = $([math]::Round($f.Length/1GB,2)) GB" } else { "$_ = absent" } }
```

## STEP 2 - C:\ TOP-LEVEL ROLLUP (every folder, biggest first)
```powershell
Get-ChildItem 'C:\' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { $s=(Get-ChildItem $_.FullName -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; [pscustomobject]@{GB=[math]::Round($s/1GB,2); Path=$_.FullName} } | Sort-Object GB -Descending | ForEach-Object { "$($_.Path) = $($_.GB) GB" }
```

## STEP 3 - GAMES INVENTORY, BOTH DRIVES (Starfield named wherever it sits)
```powershell
$roots = @('C:\XboxGames','D:\XboxGames','C:\Games','D:\Games','C:\Program Files (x86)\Steam\steamapps\common','D:\SteamLibrary\steamapps\common','C:\Program Files\Epic Games','D:\Epic Games','C:\Program Files (x86)\Ubisoft','D:\Ubisoft')
foreach ($r in $roots) { if (Test-Path $r) { Get-ChildItem $r -Directory -ErrorAction SilentlyContinue | ForEach-Object { $s=(Get-ChildItem $_.FullName -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; "GAME $($_.FullName) = $([math]::Round($s/1GB,2)) GB" } } else { "ABSENT: $r" } }
$vdf = 'C:\Program Files (x86)\Steam\steamapps\libraryfolders.vdf'; if (Test-Path $vdf) { Select-String -Path $vdf -Pattern '"path"' | ForEach-Object { "STEAMLIB: $($_.Line.Trim())" } }
Get-ChildItem 'C:\XboxGames','D:\XboxGames' -Directory -ErrorAction SilentlyContinue | Where-Object Name -match 'Starfield' | ForEach-Object { "STARFIELD-INSTALL: $($_.FullName)" }
```

## STEP 4 - MOD + SAVE GROUND (measure only, never touch)
```powershell
$paths = @("$env:USERPROFILE\Documents\My Games\Starfield", "$env:LOCALAPPDATA\Starfield", "$env:APPDATA\Vortex", 'D:\Vortex Mods', "$env:USERPROFILE\Downloads")
foreach ($p in $paths) { if (Test-Path $p) { $s=(Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; "MODGROUND $p = $([math]::Round($s/1GB,2)) GB" } else { "ABSENT: $p" } }
Get-ChildItem 'C:\Program Files','C:\Program Files (x86)','D:\' -Directory -ErrorAction SilentlyContinue | Where-Object Name -match 'Vortex' | ForEach-Object { "VORTEX-DIR: $($_.FullName)" }
```

## STEP 5 - USER PROFILE + AppData\Local TOP OFFENDERS
```powershell
Get-ChildItem "$env:USERPROFILE" -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { $s=(Get-ChildItem $_.FullName -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; [pscustomobject]@{GB=[math]::Round($s/1GB,2); Path=$_.FullName} } | Sort-Object GB -Descending | Select-Object -First 15 | ForEach-Object { "$($_.Path) = $($_.GB) GB" }
Get-ChildItem "$env:LOCALAPPDATA" -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { $s=(Get-ChildItem $_.FullName -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; [pscustomobject]@{GB=[math]::Round($s/1GB,2); Path=$_.FullName} } | Sort-Object GB -Descending | Select-Object -First 20 | ForEach-Object { "LOCAL $($_.Path) = $($_.GB) GB" }
```

## STEP 6 - WINDOWS REGROWABLES (temp, update cache, shader caches, recycle)
```powershell
$paths = @("$env:WINDIR\Temp", "$env:WINDIR\SoftwareDistribution\Download", "$env:TEMP", 'C:\$Recycle.Bin', "$env:LOCALAPPDATA\NVIDIA\DXCache", "$env:LOCALAPPDATA\D3DSCache", "$env:LOCALAPPDATA\Microsoft\Windows\INetCache")
foreach ($p in $paths) { if (Test-Path $p) { $s=(Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; "REGROW $p = $([math]::Round($s/1GB,2)) GB" } else { "ABSENT: $p" } }
```

## STEP 7 - D:\ TOP-LEVEL ROLLUP (every folder, biggest first)
```powershell
Get-ChildItem 'D:\' -Directory -Force -ErrorAction SilentlyContinue | ForEach-Object { $s=(Get-ChildItem $_.FullName -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; [pscustomobject]@{GB=[math]::Round($s/1GB,2); Path=$_.FullName} } | Sort-Object GB -Descending | ForEach-Object { "$($_.Path) = $($_.GB) GB" }
```
