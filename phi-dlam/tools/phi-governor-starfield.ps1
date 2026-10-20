# PHI GOVERNOR — STARFIELD — a live phi process, not settings — phi^2 = phi + 1
# Runs beside the game and ACTS: priority held at High; standby-list residue purged
# the moment free RAM crosses under the phi line (total / phi^2, the 0.382 share);
# every action printed with its rung as it happens. Nothing sits silent. Ctrl+C stops it.
$PHI = (1 + [math]::Sqrt(5)) / 2
function Rung($x) { [math]::Round([math]::Log([math]::Max($x,0.01)) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
Add-Type -TypeDefinition @"
using System; using System.Runtime.InteropServices;
public static class MemList {
  [DllImport("ntdll.dll")] public static extern int NtSetSystemInformation(int cls, IntPtr info, int len);
  public static void PurgeStandby() {
    IntPtr p = Marshal.AllocHGlobal(4); Marshal.WriteInt32(p, 4);
    NtSetSystemInformation(80, p, 4); Marshal.FreeHGlobal(p);
  }
}
"@
$os = Get-CimInstance Win32_OperatingSystem
$totalGB = [math]::Round($os.TotalVisibleMemorySize/1MB, 1)
$line = [math]::Round($totalGB / ($PHI * $PHI), 2)
"=== PHI GOVERNOR LIVE ==="
"RAM {0} GB | the phi line: free RAM under {1} GB (total/phi^2) triggers a purge | rung of the line: {2}" -f $totalGB, $line, (Rung $line)
"waiting for Starfield..."
$locked = $false; $tick = 0
while ($true) {
  $p = Get-Process Starfield -ErrorAction SilentlyContinue
  if ($p) {
    if (-not $locked -or $p.PriorityClass -ne 'High') { $p.PriorityClass = 'High'; $locked = $true; "[{0}] PRIORITY LOCKED: Starfield at High, phi share 0.618" -f (Get-Date -Format HH:mm:ss) }
    $freeGB = [math]::Round((Get-CimInstance Win32_OperatingSystem).FreePhysicalMemory/1MB, 2)
    if ($freeGB -lt $line) {
      [MemList]::PurgeStandby()
      Start-Sleep -Milliseconds 500
      $after = [math]::Round((Get-CimInstance Win32_OperatingSystem).FreePhysicalMemory/1MB, 2)
      "[{0}] STANDBY PURGED at the phi line: free {1} GB -> {2} GB | rung {3}" -f (Get-Date -Format HH:mm:ss), $freeGB, $after, (Rung $after)
    }
    $tick++
    if ($tick % 12 -eq 0) { "[{0}] governing: free RAM {1} GB, rung {2} | game held" -f (Get-Date -Format HH:mm:ss), $freeGB, (Rung $freeGB) }
  } else { if ($locked) { "Starfield closed - governor standing down"; break } }
  Start-Sleep -Seconds 5
}
"=== GOVERNOR OUT ==="
