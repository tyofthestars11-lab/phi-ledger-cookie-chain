# PHI KEEPER — STARFIELD — priority + timer ONLY. Zero memory touching. — phi^2 = phi + 1
# Born from the 2026-10-20 photo read: free RAM 0.64-1.24 GB in session, and the
# golden governor's standby purge fired every tick under that pressure, forcing
# re-faults. The keeper never purges, never empties, never touches memory.
$ErrorActionPreference = 'SilentlyContinue'
Add-Type -TypeDefinition @'
using System; using System.Runtime.InteropServices;
public class PhiKeep { [DllImport("ntdll.dll")] public static extern int NtSetTimerResolution(uint Desired, bool Set, out uint Current); }
'@
$cur = 0; [PhiKeep]::NtSetTimerResolution(5000, $true, [ref]$cur) | Out-Null
"PHI KEEPER live — timer 0.5 ms held. It will only hold Starfield's priority. Memory is never touched."
$fib = @(1,1,2,3,5,8,13,21); $i = 0
while ($true) {
  $tick = $fib[$i % $fib.Count]; $i++
  $p = Get-Process Starfield
  if ($p) {
    if ($p.PriorityClass -ne 'AboveNormal') { $p.PriorityClass = 'AboveNormal'; "priority locked: AboveNormal" }
    $free = (Get-CimInstance Win32_OperatingSystem).FreePhysicalMemory / 1MB
    "tick {0}s | free RAM {1:N2} GB | hands off memory" -f $tick, $free
  } else { "tick {0}s | waiting for Starfield..." -f $tick }
  Start-Sleep -Seconds $tick
}
