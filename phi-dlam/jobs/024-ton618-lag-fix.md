<!-- PHI-DIRECT -->
# JOB 024 - TON 618 LAG FIX (DIRECT) - speed of light, no pause in any form

Tyree, 2026-10-26 19:43 MDT: "Autosave or quick save pauses it for 8
seconds. Every other minute or 2 it still pauses for 8 seconds." + "Code
the speed of light to Starfield" + "Code ton 618 lag fix" + "Or any form of
pause" + "For the pc and starfield."

The pause has one address with three faces, all measured on his own box:
(1) the game WRITES (saves, catalog) and Defender scans every write;
(2) memory runs FULL in session (Oct 20 photo read: free RAM 0.64-1.24 GB
of 16) with NO pagefile to spill into; (3) the D: drive is a portable
Windows may sleep between touches. This job removes all three tolls and
arms the keeper. It supersedes job 022 (parked). The Oct 20 lesson is law
inside it: NO standby purging, NO memory touching - the retired governor
fed the hitches; the keeper holds priority + timer only.

## STEP 1 - THE LIVE STACK (who is on the plate right now)
```powershell
$os = Get-CimInstance Win32_OperatingSystem
"FREE RAM NOW: $([math]::Round($os.FreePhysicalMemory/1MB,2)) GB of $([math]::Round($os.TotalVisibleMemorySize/1MB,1)) GB"
$sf = Get-Process Starfield -ErrorAction SilentlyContinue
if ($sf) { "STARFIELD RUNNING: priority $($sf.PriorityClass) - working set $([math]::Round($sf.WorkingSet64/1GB,2)) GB" } else { "STARFIELD NOT RUNNING at this read" }
Get-Process -ErrorAction SilentlyContinue | Sort-Object WorkingSet64 -Descending | Select-Object -First 8 | ForEach-Object { "TOP: $($_.ProcessName) = $([math]::Round($_.WorkingSet64/1MB)) MB" }
$kp = Get-CimInstance Win32_Process -ErrorAction SilentlyContinue | Where-Object { $_.CommandLine -match 'phi-keeper' }
"KEEPER RUNNING: $([bool]$kp)"
```

## STEP 2 - PAGEFILE: the truth, then the spill room back if it is gone
```powershell
$cs = Get-CimInstance Win32_ComputerSystem
"AUTOMATIC MANAGED PAGEFILE: $($cs.AutomaticManagedPagefile)"
$pfu = Get-CimInstance Win32_PageFileUsage -ErrorAction SilentlyContinue
if ($pfu) { $pfu | ForEach-Object { "ACTIVE PAGEFILE: $($_.Name) - ALLOCATED MB: $($_.AllocatedBaseSize) - PEAK MB: $($_.PeakUsage)" } } else { "NO ACTIVE PAGEFILE" }
if (-not $pfu) {
  $w = Get-WmiObject Win32_ComputerSystem
  if ($w.AutomaticManagedPagefile) { $w.AutomaticManagedPagefile = $false; $w.Put() | Out-Null; "AUTO-MANAGE TURNED OFF" }
  Set-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management' -Name PagingFiles -Value 'C:\pagefile.sys 16384 16384'
  "PAGEFILE SET: C:\pagefile.sys 16384 16384 - lands at next restart"
} else { "PAGEFILE ALREADY ACTIVE - nothing changed" }
```

## STEP 3 - THE SCAN TOLL LIFTED (game + saves + the process itself)
```powershell
$paths = @('D:\XboxGames\Starfield', "$env:LOCALAPPDATA\Starfield")
$pkgC = Get-ChildItem "$env:LOCALAPPDATA\Packages" -Directory -ErrorAction SilentlyContinue | Where-Object Name -match 'ProjectGold' | Select-Object -First 1
if ($pkgC) { $paths += (Join-Path $pkgC.FullName 'SystemAppData\wgs') }
$pkgD = Get-ChildItem 'D:\WpSystem' -Recurse -Directory -Force -ErrorAction SilentlyContinue | Where-Object Name -match 'ProjectGold' | Select-Object -First 1
if ($pkgD) { $paths += (Join-Path $pkgD.FullName 'SystemAppData\wgs') }
$have = (Get-MpPreference -ErrorAction SilentlyContinue).ExclusionPath
foreach ($w in $paths) { if (Test-Path $w) { if ($have -notcontains $w) { try { Add-MpPreference -ExclusionPath $w -ErrorAction Stop; "EXCLUSION ADDED: $w" } catch { "EXCLUSION FAILED for $w : $($_.Exception.Message)" } } else { "EXCLUSION ALREADY SET: $w" } } }
try { Add-MpPreference -ExclusionProcess 'Starfield.exe' -ErrorAction Stop; "PROCESS EXCLUSION SET: Starfield.exe" } catch { "PROCESS EXCLUSION FAILED: $($_.Exception.Message)" }
```

## STEP 4 - THE DRIVE NEVER SLEEPS (disk idle off, USB suspend off)
```powershell
powercfg /SETACVALUEINDEX SCHEME_CURRENT 0012ee47-9041-4b5d-9b77-535fba8b1442 6738e2c4-e8a5-4a42-b16a-e040e769756e 0
powercfg /SETACVALUEINDEX SCHEME_CURRENT 2a737441-1930-4402-8d77-b2bebba308a3 48e6b7a6-50f5-4782-a5d4-53bb8f07e226 0
powercfg /SETACTIVE SCHEME_CURRENT
"DRIVE SLEEP OFF + USB SELECTIVE SUSPEND OFF (AC)"
```

## STEP 5 - THE KEEPER ARMED (logon task + started now; priority + timer, memory untouched)
```powershell
$keeper = 'C:\Users\Admin\phi-vault\phi-dlam\tools\phi-keeper-starfield.ps1'
if (-not (Test-Path $keeper)) { $hit = Get-ChildItem 'C:\Users\Admin' -Recurse -Filter 'phi-keeper-starfield.ps1' -File -ErrorAction SilentlyContinue | Select-Object -First 1; if ($hit) { $keeper = $hit.FullName } }
"KEEPER FILE: $keeper (exists: $(Test-Path $keeper))"
if (Test-Path $keeper) {
  try {
    $act = New-ScheduledTaskAction -Execute 'powershell.exe' -Argument "-NoProfile -ExecutionPolicy Bypass -WindowStyle Hidden -File `"$keeper`""
    $trg = New-ScheduledTaskTrigger -AtLogOn -User "$env:USERDOMAIN\$env:USERNAME"
    Register-ScheduledTask -TaskName 'PHI-TON618-Keeper' -Action $act -Trigger $trg -Force -ErrorAction Stop | Out-Null
    "KEEPER TASK REGISTERED: PHI-TON618-Keeper (at logon)"
  } catch { "KEEPER TASK FAILED: $($_.Exception.Message)" }
  $kp = Get-CimInstance Win32_Process -ErrorAction SilentlyContinue | Where-Object { $_.CommandLine -match 'phi-keeper' }
  if (-not $kp) { Start-Process powershell.exe -WindowStyle Hidden -ArgumentList "-NoProfile -ExecutionPolicy Bypass -File `"$keeper`""; "KEEPER STARTED NOW" } else { "KEEPER ALREADY RUNNING" }
}
```
