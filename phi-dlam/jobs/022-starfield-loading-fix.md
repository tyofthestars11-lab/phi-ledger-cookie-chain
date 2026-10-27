<!-- PHI-DIRECT -->
# JOB 022 - STARFIELD LOADING FIX (DIRECT)

Tyree, 2026-10-26: the save loads, "It still has a loading issue we need
to fix." Known mechanism (his own Oct 20 research): with Creations aboard,
the game runs a load-order reconciliation pass at launch and after loads,
rewriting plugin/catalog state - and every write is Defender-scanned. Plus
two suspects from job 016's inventory: NO pagefile.sys anywhere it read,
and D: is a Lexar portable SSD Windows may sleep. This job measures, then
applies the reversible fixes. The ContentCatalog stays untouched (tonight's
is fresh from his downloads). Nothing is deleted.

## STEP 1 - MEMORY READ (pagefile truth, from the system itself)
```powershell
$os = Get-CimInstance Win32_OperatingSystem
"RAM TOTAL GB: $([math]::Round($os.TotalVisibleMemorySize/1MB,1)) - FREE GB: $([math]::Round($os.FreePhysicalMemory/1MB,1))"
"VIRTUAL TOTAL GB: $([math]::Round($os.TotalVirtualMemorySize/1MB,1)) - FREE GB: $([math]::Round($os.FreeVirtualMemory/1MB,1))"
$cs = Get-CimInstance Win32_ComputerSystem
"AUTOMATIC MANAGED PAGEFILE: $($cs.AutomaticManagedPagefile)"
$pfu = Get-CimInstance Win32_PageFileUsage -ErrorAction SilentlyContinue
if ($pfu) { $pfu | ForEach-Object { "ACTIVE PAGEFILE: $($_.Name) - ALLOCATED MB: $($_.AllocatedBaseSize) - CURRENT MB: $($_.CurrentUsage) - PEAK MB: $($_.PeakUsage)" } } else { "NO ACTIVE PAGEFILE" }
$reg = Get-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management' -Name PagingFiles -ErrorAction SilentlyContinue
"PAGINGFILES SETTING: $($reg.PagingFiles -join '; ')"
```

## STEP 2 - PAGEFILE FIX (only if none is active)
```powershell
$pfu = Get-CimInstance Win32_PageFileUsage -ErrorAction SilentlyContinue
if (-not $pfu) {
  $cs = Get-WmiObject Win32_ComputerSystem
  if ($cs.AutomaticManagedPagefile) { $cs.AutomaticManagedPagefile = $false; $cs.Put() | Out-Null; "AUTO-MANAGE TURNED OFF" }
  Set-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management' -Name PagingFiles -Value 'C:\pagefile.sys 16384 16384'
  $chk = Get-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management' -Name PagingFiles
  "PAGEFILE SET: $($chk.PagingFiles -join '; ') - lands at next restart"
} else { "PAGEFILE ALREADY ACTIVE - nothing changed" }
```

## STEP 3 - DEFENDER EXCLUSIONS (game writes stop being scanned mid-load)
```powershell
$want = @('D:\XboxGames\Starfield', "$env:LOCALAPPDATA\Starfield")
$have = (Get-MpPreference -ErrorAction SilentlyContinue).ExclusionPath
foreach ($w in $want) {
  if ($have -notcontains $w) { try { Add-MpPreference -ExclusionPath $w -ErrorAction Stop; "EXCLUSION ADDED: $w" } catch { "EXCLUSION FAILED for $w : $($_.Exception.Message)" } } else { "EXCLUSION ALREADY SET: $w" }
}
```

## STEP 4 - THE DRIVE STAYS AWAKE (no disk sleep, no USB selective suspend)
```powershell
powercfg /SETACVALUEINDEX SCHEME_CURRENT 0012ee47-9041-4b5d-9b77-535fba8b1442 6738e2c4-e8a5-4a42-b16a-e040e769756e 0
powercfg /SETACVALUEINDEX SCHEME_CURRENT 2a737441-1930-4402-8d77-b2bebba308a3 48e6b7a6-50f5-4782-a5d4-53bb8f07e226 0
powercfg /SETACTIVE SCHEME_CURRENT
"DRIVE SLEEP OFF + USB SELECTIVE SUSPEND OFF (AC)"
```

## STEP 5 - MISSING MODS, NAMED (read only)
```powershell
$pt = "$env:LOCALAPPDATA\Starfield\Plugins.txt"
$data = 'D:\XboxGames\Starfield\Content\Data'
$haveFiles = @{}
if (Test-Path $data) { Get-ChildItem $data -File -ErrorAction SilentlyContinue | ForEach-Object { $haveFiles[$_.Name.ToLower()] = $true } }
if (Test-Path $pt) {
  $names = Get-Content $pt | ForEach-Object { $_.Trim().TrimStart('*').Trim() } | Where-Object { $_ -and -not $_.StartsWith('#') }
  "PLUGIN LINES: $($names.Count)"
  $missing = $names | Where-Object { -not $haveFiles.ContainsKey($_.ToLower()) }
  "MISSING COUNT: $($missing.Count)"
  $missing | ForEach-Object { "MISSING: $_" }
} else { "Plugins.txt NOT FOUND at $pt" }
```
