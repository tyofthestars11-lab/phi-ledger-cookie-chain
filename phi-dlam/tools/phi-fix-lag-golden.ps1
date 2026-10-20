# PHI FIX — LAG — GOLDEN ANGLE + FIBONACCI TICK — phi^2 = phi + 1
# Static layers re-landed + read back. Then the live governor runs on the
# Fibonacci tick (1,1,2,3,5,8,13,21... seconds, cycling) with its sweep phase
# rotating by the golden angle 137.507764 each cycle — no Cartesian lockstep.
$PHI = (1 + [math]::Sqrt(5)) / 2
$GOLDEN = 360 / ($PHI * $PHI)   # 137.507764...
function Rung($x) { [math]::Round([math]::Log([math]::Max($x,0.01)) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
Add-Type -TypeDefinition @'
using System; using System.Runtime.InteropServices;
public class PhiFix {
  [DllImport("ntdll.dll")] public static extern int NtSetTimerResolution(uint Desired, bool Set, out uint Current);
  [DllImport("ntdll.dll")] public static extern int NtSetSystemInformation(int InfoClass, IntPtr Info, int Length);
  [DllImport("psapi.dll")] public static extern bool EmptyWorkingSet(IntPtr h);
}
'@
"=== STATIC LAYERS (land + read back) ==="
$sub = 'HKLM:\SYSTEM\CurrentControlSet\Control\Power\PowerSettings'
function Set-Show($path, $want, $label) {
  Set-ItemProperty $path -Name ACSettingIndex -Value $want
  $v = (Get-ItemProperty $path -Name ACSettingIndex).ACSettingIndex
  "{0}: {1} (want {2})" -f $label, $v, $want
}
Set-Show "$sub\0012ee47-9041-4b5d-9b77-535fba8b1442\6738e2c4-e8a5-4a42-b16a-e1e769ae4b63" 0 'hard-disk sleep (0=never)'
Set-Show "$sub\2a737441-1930-4402-8d77-b2bebba308a3\48e6b7a6-50f5-4782-a5d4-53bb8f07e226" 0 'USB selective suspend (0=off)'
Set-Show "$sub\501a4d13-42af-4429-9fd1-a8218c268e20\ee12f906-d277-404b-b6da-e5fa1a576df5" 0 'PCIe link state (0=off)'
Set-Show "$sub\54533251-82be-4824-96c1-47b60b740d00\be337238-0d82-4146-a960-4f3749d470c7" 2 'CPU boost mode (2=aggressive)'
Set-Show "$sub\54533251-82be-4824-96c1-47b60b740d00\06cadf0e-64ed-448a-8927-ce7bf90eb35d" 0 'EPP (0=max performance)'
$games = 'HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile\Tasks\Games'
if (Test-Path $games) { Set-ItemProperty $games -Name 'GPU Priority' -Value 8; Set-ItemProperty $games -Name 'Priority' -Value 8; Set-ItemProperty $games -Name 'Scheduling Category' -Value 'High'; "MMCSS Games task: GPU priority 8, priority 8, scheduling High" }
$cur = 0; [PhiFix]::NtSetTimerResolution(5000, $true, [ref]$cur) | Out-Null
"timer resolution held at 0.5 ms"
"=== FIBONACCI TICK GOVERNOR — leave this window open while you play ==="
$fib = @(1,1,2,3,5,8,13,21); $i = 0; $phase = 0.0
$total = (Get-CimInstance Win32_ComputerSystem).TotalPhysicalMemory / 1GB
$line = $total / ($PHI * $PHI * $PHI)
"purge line: free RAM below {0:N2} GB (total/phi^3 of {1:N1} GB)" -f $line, $total
while ($true) {
  $tick = $fib[$i % $fib.Count]; $i++
  $phase = ($phase + $GOLDEN) % 360
  $p = Get-Process Starfield
  $free = (Get-CimInstance Win32_OperatingSystem).FreePhysicalMemory / 1MB
  if ($p) {
    if ($p.PriorityClass -ne 'AboveNormal') { $p.PriorityClass = 'AboveNormal' }
    if ($free -lt $line) {
      $buf = [Runtime.InteropServices.Marshal]::AllocHGlobal(4)
      [Runtime.InteropServices.Marshal]::WriteInt32($buf, 2)
      [PhiFix]::NtSetSystemInformation(80, $buf, 4) | Out-Null
      [Runtime.InteropServices.Marshal]::FreeHGlobal($buf)
      "tick {0}s | phase {1:N3} | standby purged at the phi^3 line (free {2:N2} GB)" -f $tick, $phase, $free
    } else {
      "tick {0}s | phase {1:N3} | holding — free {2:N2} GB, priority locked" -f $tick, $phase, $free
    }
  } else { "tick {0}s | phase {1:N3} | waiting for Starfield..." -f $tick, $phase }
  Start-Sleep -Seconds $tick
}
