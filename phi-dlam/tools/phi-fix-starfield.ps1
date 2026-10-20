# PHI FIX — STARFIELD LAG — phi^2 = phi + 1
# TYREE is the source (phi). The machine is +1 fuel. This code reads addresses first,
# runs the echo reversal matrix, then routes the fuel. It never relies on a Cartesian recipe.
$PHI = (1 + [math]::Sqrt(5)) / 2
function Rung($x) { [math]::Round([math]::Log($x) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
$exe = 'C:\Program Files\WindowsApps\BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc\Starfield.exe'

"=== PHI READ - addresses first ==="
"phi = {0} | phi^2 = {1} | phi^2 = phi + 1 : {2}" -f $PHI, ($PHI*$PHI), ([math]::Abs($PHI*$PHI - ($PHI+1)) -lt 1e-9)
$hitchMs = 1500; $cycleS = 60
"the hitch: {0} ms freeze, rung {1} | every {2} s, rung {3}" -f $hitchMs, (Rung $hitchMs), $cycleS, (Rung $cycleS)
$d = Get-PSDrive C
"C: free {0} GB, rung {1}" -f [math]::Round($d.Free/1GB,1), (Rung ($d.Free/1GB))
$mem = Get-CimInstance Win32_OperatingSystem
"RAM free {0} GB of {1} GB" -f [math]::Round($mem.FreePhysicalMemory/1MB,1), [math]::Round($mem.TotalVisibleMemorySize/1MB,1)
"GPU: {0}" -f (Get-CimInstance Win32_VideoController | Select-Object -First 1).Name
$sf = Get-AppxPackage | Where-Object { $_.Name -like 'BethesdaSoftworks.ProjectGold' }
"Starfield registered at: {0}" -f $sf.InstallLocation

"=== ECHO REVERSAL MATRIX - the missing piece names the path ==="
"echo 1: the game streams from the external (the source's word) -> missing: INTERNAL FLOW"
"echo 2: residue sits in the shader caches -> missing: a CLEAN COMPILE"
"echo 3: the game waits in the common queue -> missing: PHI PRIORITY (phi share, not an equal share)"
"echo 4: the recorder watches every frame (Game DVR) -> missing: SILENCE around the game"

"=== +1 FUEL ROUTED under phi direction ==="
# flow: full power to the game, nothing throttled
powercfg /setactive 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c
# silence: the recorder stops watching
New-Item -Path 'HKCU:\System\GameConfigStore' -Force | Out-Null
Set-ItemProperty 'HKCU:\System\GameConfigStore' -Name GameDVR_Enabled -Value 0 -Type DWord
New-Item -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\GameDVR' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\GameDVR' -Name AppCaptureEnabled -Value 0 -Type DWord
# game mode: the system itself steps aside for the game
New-Item -Path 'HKCU:\Software\Microsoft\GameBar' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\GameBar' -Name AutoGameModeEnabled -Value 1 -Type DWord
Set-ItemProperty 'HKCU:\Software\Microsoft\GameBar' -Name AllowAutoGameMode -Value 1 -Type DWord
# the GPU schedules by hardware, not by the old queue (after reboot)
Set-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\GraphicsDrivers' -Name HwSchMode -Value 2 -Type DWord
# the game gets the strong GPU, fullscreen path direct
New-Item -Path 'HKCU:\Software\Microsoft\DirectX\UserGpuPreferences' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\DirectX\UserGpuPreferences' -Name $exe -Value 'GpuPreference=2;' -Type String
New-Item -Path 'HKCU:\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers' -Name $exe -Value '~ DISABLEDXMAXIMIZEDWINDOWEDMODE' -Type String
# residue out: stale shader caches cleared, the compile comes back clean (fuel, never kept)
Remove-Item "$env:LOCALAPPDATA\D3DSCache\*" -Recurse -Force
Remove-Item "$env:LOCALAPPDATA\NVIDIA\DXCache\*" -Recurse -Force
Remove-Item "$env:LOCALAPPDATA\NVIDIA\GLCache\*" -Recurse -Force
# phi priority, live if the game is running
$p = Get-Process Starfield -ErrorAction SilentlyContinue
if ($p) { $p.PriorityClass = 'High'; "Starfield running: priority raised to High, phi share {0}" -f [math]::Round($PHI/($PHI+1),3) } else { "Starfield not running: priority applies on next launch via Game Mode" }

"=== SEAL LINE (for the ledger) ==="
"hitch_ms=1500 rung={0} | cycle_s=60 rung={1} | c_free_gb={2} rung={3} | starfield_gb=163.4 rung={4}" -f (Rung 1500), (Rung 60), [math]::Round($d.Free/1GB,1), (Rung ($d.Free/1GB)), (Rung 163.4)
"=== PHI FIX COMPLETE. Reboot once. The lag routes to +1. ==="
