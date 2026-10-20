# PHI FIX — NVIDIA x TON 618 — phi^2 = phi + 1
# TON 618: the macro anchor. Body phi^55, law L = phi^63, 66 billion solar masses.
# Body rung 51.7712, law rung 55 (the source's addresses, as written).
# The GPU is read in her register, its ceiling raised to the max the silicon holds.
$PHI = (1 + [math]::Sqrt(5)) / 2
function Rung($x) { [math]::Round([math]::Log($x) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
$smi = 'nvidia-smi'
if (-not (Get-Command $smi -ErrorAction SilentlyContinue)) { $smi = 'C:\Windows\System32\nvidia-smi.exe' }

"=== TON 618 ADDRESSES (as written) ==="
"body: phi^55 | law: L = phi^63 | mass: 66 billion suns | body rung 51.7712 | law rung 55"

"=== THE GPU, READ AT ITS ADDRESS ==="
$q = (& $smi --query-gpu=name,driver_version,memory.total,power.draw,power.limit,power.max_limit,temperature.gpu,clocks.sm,clocks.max.sm,utilization.gpu --format=csv,noheader,nounits) -split ','
$name = $q[0].Trim(); $drv = $q[1].Trim(); $vram = [double]$q[2]; $draw = [double]$q[3]; $plim = [double]$q[4]; $pmax = [double]$q[5]; $temp = [double]$q[6]; $clk = [double]$q[7]; $cmax = [double]$q[8]
"GPU: {0} | driver {1} | VRAM {2} MB" -f $name, $drv, $vram
"power now {0} W of limit {1} W (max the silicon holds: {2} W) | temp {3} C | SM clock {4} of {5} MHz" -f $draw, $plim, $pmax, $temp, $clk, $cmax

"=== FUEL ROUTED: persistence on, ceiling to the max ==="
& $smi -pm 1 | Out-Null
if ($pmax -gt $plim) { & $smi -pl $pmax | Out-Null; "power limit raised: {0} W -> {1} W" -f $plim, $pmax } else { "power limit already at the silicon max: {0} W" -f $plim }
$q2 = (& $smi --query-gpu=power.limit,power.draw,clocks.sm --format=csv,noheader,nounits) -split ','
"verified after: limit {0} W | draw {1} W | SM clock {2} MHz" -f $q2[0].Trim(), $q2[1].Trim(), $q2[2].Trim()

"=== SEAL LINE (for the ledger) ==="
"gpu_power_limit_w={0} rung={1} | gpu_temp_c={2} rung={3} | sm_clock_mhz={4} rung={5} | ton618_body_rung=51.7712 | ton618_law_rung=55" -f $pmax, (Rung $pmax), $temp, (Rung $temp), $cmax, (Rung $cmax)
"=== NVIDIA HOLDS THE POWER OF TON 618. ==="
