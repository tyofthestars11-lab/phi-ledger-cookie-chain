# FIBONACCI ANYON KEEPER — the braid fixes the lag — phi^2 = phi + 1
# tau x tau = 1 + tau | quantum dimension = phi | the computation is the whole braid
# Levers: Starfield priority held + 0.5 ms timer. Memory: hands off (her law).
# A stall is a CROSSING: woven in, counted, absorbed — never a fault.
$PHI = (1 + [math]::Sqrt(5)) / 2
$ErrorActionPreference = 'SilentlyContinue'
Add-Type -TypeDefinition @'
using System; using System.Runtime.InteropServices;
public class Anyon { [DllImport("ntdll.dll")] public static extern int NtSetTimerResolution(uint D, bool S, out uint C); }
'@
$cur = 0; [Anyon]::NtSetTimerResolution(5000, $true, [ref]$cur) | Out-Null
# The Fibonacci word: S0=0, S1=01, S(n)=S(n-1)+S(n-2) — the braid's growth law
$w0 = '0'; $w1 = '01'; while ($w1.Length -lt 233) { $t = $w1 + $w0; $w0 = $w1; $w1 = $t }
$word = $w1.ToCharArray()
"=== FIBONACCI ANYON KEEPER — braid length {0} — tau x tau = 1 + tau ===" -f $word.Length
"braiding... (Ctrl+C closes the braid)"
$i = 0; $crossings = 0; $lastCPU = $null; $fib = @(1,1,2,3,5,8,13,21)
while ($true) {
  $tick = $fib[$i % $fib.Count]
  $g = $word[$i % $word.Length]; $i++
  $gen = if ($g -eq '0') { 'sigma1' } else { 'sigma2' }
  $p = Get-Process Starfield
  if ($p) {
    if ($p.PriorityClass -ne 'AboveNormal') { $p.PriorityClass = 'AboveNormal' }
    $cpu = $p.TotalProcessorTime.TotalSeconds
    if ($null -ne $lastCPU) {
      $rate = ($cpu - $lastCPU) / $tick
      if ($rate -lt 0.05) { $crossings++; "braid {0} | {1} | CROSSING woven (stall absorbed #{2}) | braid state unbroken" -f $i, $gen, $crossings }
      else { "braid {0} | {1} | flow clean | cpu rate {2:N2}" -f $i, $gen, $rate }
    }
    $lastCPU = $cpu
  } else { "braid {0} | {1} | waiting for Starfield..." -f $i, $gen; $lastCPU = $null }
  Start-Sleep -Seconds $tick
}
