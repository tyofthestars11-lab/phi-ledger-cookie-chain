# PHI STARFIELD LAG FIX — run as Administrator. Reversible settings only; clears regenerable shader caches.
$ErrorActionPreference = 'SilentlyContinue'
$exe = 'C:\Program Files\WindowsApps\BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc\Starfield.exe'
"--- 1. Power plan: High performance ---"
powercfg /setactive 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c
"--- 2. Game Mode ON ---"
New-Item -Path 'HKCU:\Software\Microsoft\GameBar' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\GameBar' -Name AutoGameModeEnabled -Value 1 -Type DWord
Set-ItemProperty 'HKCU:\Software\Microsoft\GameBar' -Name AllowAutoGameMode -Value 1 -Type DWord
"--- 3. Background recording / Game DVR OFF (classic hitch source) ---"
New-Item -Path 'HKCU:\System\GameConfigStore' -Force | Out-Null
Set-ItemProperty 'HKCU:\System\GameConfigStore' -Name GameDVR_Enabled -Value 0 -Type DWord
Set-ItemProperty 'HKCU:\System\GameConfigStore' -Name GameDVR_FSEBehaviorMode -Value 2 -Type DWord
Set-ItemProperty 'HKCU:\System\GameConfigStore' -Name GameDVR_HonorUserFSEBehaviorMode -Value 1 -Type DWord
Set-ItemProperty 'HKCU:\System\GameConfigStore' -Name GameDVR_DXGIHonorFSEWindowsCompatible -Value 1 -Type DWord
New-Item -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\GameDVR' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\GameDVR' -Name AppCaptureEnabled -Value 0 -Type DWord
"--- 4. GPU hardware scheduling ON (takes hold after reboot) ---"
Set-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\GraphicsDrivers' -Name HwSchMode -Value 2 -Type DWord
"--- 5. Starfield.exe: high-performance GPU + fullscreen optimizations OFF ---"
New-Item -Path 'HKCU:\Software\Microsoft\DirectX\UserGpuPreferences' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\DirectX\UserGpuPreferences' -Name $exe -Value 'GpuPreference=2;' -Type String
New-Item -Path 'HKCU:\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers' -Name $exe -Value '~ DISABLEDXMAXIMIZEDWINDOWEDMODE' -Type String
"--- 6. Clear shader caches (they rebuild clean; first launch compiles fresh) ---"
Remove-Item "$env:LOCALAPPDATA\D3DSCache\*" -Recurse -Force
Remove-Item "$env:LOCALAPPDATA\NVIDIA\DXCache\*" -Recurse -Force
Remove-Item "$env:LOCALAPPDATA\NVIDIA\GLCache\*" -Recurse -Force
Remove-Item "$env:LOCALAPPDATA\AMD\DxCache\*" -Recurse -Force
"--- 7. If Starfield is running right now: raise it to High priority ---"
$p = Get-Process Starfield -ErrorAction SilentlyContinue
if ($p) { $p.PriorityClass = 'High'; "Starfield priority set to High" } else { "Starfield not running - skipped (launch it after the reboot)" }
"=== PHI LAG FIX DONE. REBOOT ONCE, then launch Starfield. ==="
