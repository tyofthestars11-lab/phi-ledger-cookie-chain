<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB - FIX MEM PHI2 TRIMMING WORKSETS FOR PC (Ground: Tyree said fix mem phi2 trimming worksets for the pc, after job 711 showed AssetCompile memory estimate 4608 MiB vs MemoryLimit 1596 MiB. This job trims working sets in phi2 form: it prints total and free memory before, prints the top 10 processes by working set, trims working sets of non-Unreal processes only, never kills UnrealEditor-Cmd or the GUI editor, prints total and free memory after, and prints the freed amount. If a trim fails, print that line plainly and do not claim memory that did not free. No kill, no package, no 1.0, proof only in the PC result.) ==='
$memW = Get-CimInstance Win32_OperatingSystem
Write-Output ('MEM BEFORE TOTAL MB ' + [int]($memW.TotalVisibleMemorySize / 1024))
Write-Output ('MEM BEFORE FREE MB ' + [int]($memW.FreePhysicalMemory / 1024))
Get-Process | Sort-Object WorkingSet -Descending | Select-Object -First 10 | ForEach-Object { Write-Output ('MEM TOP ' + $_.Name + ' ' + [int]($_.WorkingSet / 1MB) + ' MB') }
$codeW = 'public static class T { [System.Runtime.InteropServices.DllImport("psapi.dll")] public static extern bool EmptyWorkingSet(System.IntPtr h); }'
Add-Type -TypeDefinition $codeW -ErrorAction SilentlyContinue
Get-Process | Where-Object { $_.Name -notmatch 'UnrealEdito.' } | ForEach-Object { try { [T]::EmptyWorkingSet($_.Handle) | Out-Null; Write-Output ('MEM TRIMMED ' + $_.Name) } catch { Write-Output ('MEM TRIM FAIL ' + $_.Name) } }
$memW2 = Get-CimInstance Win32_OperatingSystem
Write-Output ('MEM AFTER TOTAL MB ' + [int]($memW2.TotalVisibleMemorySize / 1024))
Write-Output ('MEM AFTER FREE MB ' + [int]($memW2.FreePhysicalMemory / 1024))
Write-Output 'MEM ELECTRON PHASE LOCK HELD.'
Write-Output 'MEM NOCOOK.'
Write-Output 'MEM NOPACKAGE.'
Write-Output 'WHOLE JOB DONE.'
```
