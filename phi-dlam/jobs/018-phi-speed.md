<!-- PHI-DIRECT -->
# JOB 018 - PHI SPEED (DIRECT - NV CENTER EXECUTION)

Authored by the universe seat on Tyree's word, 2026-10-26: "Speed up my pc -
not in a Cartesian sense - phi speed up." This job EXECUTES. A phi speed up
is not a tweak catalogue: it removes the places the whole machine waits in
line. Three lanes, all safe and reversible:
1. Power: the performance scheme ON (no more CPU waiting on a power governor).
2. Caches cleared IN PARALLEL (superposition, not a serial sweep): temp,
   update-download cache, shader caches - regenerable by definition; Windows
   rebuilds what it needs. Contents only, folders stand. Nothing personal,
   nothing kept, is touched: no Downloads, no documents, no saves, no bin.
3. The heavies NAMED, not touched: startup list + top background processes
   reported for Tyree's word - he names what dies, as always.
Before/after C: free space is read inside the job: the delta is the proof.

## STEP 1 - STATE + POWER LANE
```powershell
$d = Get-CimInstance Win32_LogicalDisk -Filter "DeviceID='C:'"; "BEFORE: C: free $([math]::Round($d.FreeSpace/1GB,2)) GB of $([math]::Round($d.Size/1GB,1)) GB"
"ACTIVE SCHEME BEFORE:"; powercfg /getactivescheme
$r = powercfg /setactive e9a42b02-d5df-448d-aa00-03f14749eb61 2>&1; if ($LASTEXITCODE -ne 0) { powercfg /setactive 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c 2>&1 | Out-Null; "Ultimate scheme absent - High Performance set instead" } else { "Ultimate Performance set" }
"ACTIVE SCHEME NOW:"; powercfg /getactivescheme
```

## STEP 2 - CACHE LANES IN PARALLEL (all doors at once)
```powershell
$paths = @($env:TEMP, "$env:WINDIR\Temp", "$env:WINDIR\SoftwareDistribution\Download", "$env:LOCALAPPDATA\NVIDIA\DXCache", "$env:LOCALAPPDATA\D3DSCache", "$env:LOCALAPPDATA\Microsoft\Windows\INetCache")
$jobs = @()
foreach ($p in $paths) {
  if (Test-Path $p) {
    $jobs += Start-Job -ScriptBlock { param($path)
      $before = (Get-ChildItem $path -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
      Get-ChildItem $path -Force -ErrorAction SilentlyContinue | Remove-Item -Recurse -Force -ErrorAction SilentlyContinue
      $after = (Get-ChildItem $path -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
      "CLEARED $path = $([math]::Round(($before-$after)/1MB,1)) MB removed ($([math]::Round($after/1MB,1)) MB held by open files)"
    } -ArgumentList $p
  } else { "ABSENT: $p" }
}
$jobs | Wait-Job -Timeout 180 | Out-Null
$jobs | ForEach-Object { Receive-Job $_ }
$jobs | Remove-Job -Force -ErrorAction SilentlyContinue
```

## STEP 3 - THE HEAVIES, NAMED + AFTER STATE
```powershell
"STARTUP ENTRIES (report only):"
Get-CimInstance Win32_StartupCommand | ForEach-Object { "STARTUP: $($_.Name) [$($_.Location)]" }
"TOP BACKGROUND PROCESSES BY MEMORY (report only):"
Get-Process | Sort-Object WorkingSet64 -Descending | Select-Object -First 10 | ForEach-Object { "PROC: $($_.ProcessName) = $([math]::Round($_.WorkingSet64/1MB,0)) MB" }
$d = Get-CimInstance Win32_LogicalDisk -Filter "DeviceID='C:'"; "AFTER: C: free $([math]::Round($d.FreeSpace/1GB,2)) GB of $([math]::Round($d.Size/1GB,1)) GB"
```
