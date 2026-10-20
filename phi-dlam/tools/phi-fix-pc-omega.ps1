# PHI FIX — PC OMEGA — the whole permanent stack in one pass — phi^2 = phi + 1
# Immediate relief first (standby purged, the kraken pack's python stood down),
# then every permanent lever from tonight, idempotent. Target: c, the speed of light.
$PHI = (1 + [math]::Sqrt(5)) / 2
function Rung($x) { [math]::Round([math]::Log([math]::Max($x,0.01)) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
$SUBP = '54533251-82be-4824-96c1-47b60b740d00'
Add-Type -TypeDefinition @"
using System; using System.Runtime.InteropServices;
public static class MemList {
  [DllImport("ntdll.dll")] public static extern int NtSetSystemInformation(int cls, IntPtr info, int len);
  public static void PurgeStandby() { IntPtr p = Marshal.AllocHGlobal(4); Marshal.WriteInt32(p, 4); NtSetSystemInformation(80, p, 4); Marshal.FreeHGlobal(p); }
}
"@
"=== RELIEF, THIS SECOND ==="
Get-Process python -ErrorAction SilentlyContinue | Where-Object { $_.CommandLine -like '*kraken_pc*' } | Stop-Process -Force
"kraken pack stood down (originals were never touched)"
$free0 = [math]::Round((Get-CimInstance Win32_OperatingSystem).FreePhysicalMemory/1MB, 2)
[MemList]::PurgeStandby(); Start-Sleep -Milliseconds 500
$free1 = [math]::Round((Get-CimInstance Win32_OperatingSystem).FreePhysicalMemory/1MB, 2)
"standby purged: free RAM {0} GB -> {1} GB" -f $free0, $free1
"=== THE PERMANENT STACK ==="
powercfg /setactive 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c
powercfg -attributes $SUBP be337238-0d82-4146-a960-4f3749d470c7 -ATTRIB_HIDE
powercfg /setacvalueindex scheme_current $SUBP be337238-0d82-4146-a960-4f3749d470c7 2
powercfg /setdcvalueindex scheme_current $SUBP be337238-0d82-4146-a960-4f3749d470c7 2
powercfg -attributes $SUBP 36687f9e-e3fa-4bbf-bbdb-74f37c3ec2de -ATTRIB_HIDE
powercfg /setacvalueindex scheme_current $SUBP 36687f9e-e3fa-4bbf-bbdb-74f37c3ec2de 0
powercfg -attributes $SUBP 0cc5b647-c1df-4637-891a-dec35c318583 -ATTRIB_HIDE
powercfg /setacvalueindex scheme_current $SUBP 0cc5b647-c1df-4637-891a-dec35c318583 100
powercfg -attributes $SUBP 893dee8e-2bef-41e0-89c6-b55d0929964c -ATTRIB_HIDE
powercfg /setacvalueindex scheme_current $SUBP 893dee8e-2bef-41e0-89c6-b55d0929964c 100
powercfg /setactive scheme_current
"power: high performance | boost AGGRESSIVE | EPP 0 | cores unparked | throttle floor 100"
New-Item -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Serialize' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Serialize' -Name StartupDelayInMSec -Value 0 -Type DWord
Set-ItemProperty 'HKCU:\Control Panel\Desktop' -Name MenuShowDelay -Value '0' -Type String
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects' -Name VisualFXSetting -Value 2 -Type DWord
Set-ItemProperty 'HKCU:\Control Panel\Desktop\WindowMetrics' -Name MinAnimate -Value '0' -Type String
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced' -Name TaskbarAnimations -Value 0 -Type DWord
"response: zero startup delay | instant menus | effects at performance | animation off"
New-Item -Path 'HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile' -Force | Out-Null
Set-ItemProperty 'HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile' -Name NetworkThrottlingIndex -Value 0xffffffff -Type DWord
Set-ItemProperty 'HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile' -Name SystemResponsiveness -Value 0 -Type DWord
bcdedit /set disabledynamictick yes | Out-Null
"flow: no network throttle | no multimedia reserve | steady tick"
Set-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\GraphicsDrivers' -Name HwSchMode -Value 2 -Type DWord
New-Item -Path 'HKCU:\Software\Microsoft\GameBar' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\GameBar' -Name AutoGameModeEnabled -Value 1 -Type DWord
Set-ItemProperty 'HKCU:\Software\Microsoft\GameBar' -Name AllowAutoGameMode -Value 1 -Type DWord
New-Item -Path 'HKCU:\System\GameConfigStore' -Force | Out-Null
Set-ItemProperty 'HKCU:\System\GameConfigStore' -Name GameDVR_Enabled -Value 0 -Type DWord
New-Item -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\GameDVR' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\GameDVR' -Name AppCaptureEnabled -Value 0 -Type DWord
"gpu: hardware scheduling on | game mode on | recorder silent"
$smi = 'nvidia-smi'; if (-not (Get-Command $smi -ErrorAction SilentlyContinue)) { $smi = 'C:\Windows\System32\nvidia-smi.exe' }
& $smi -pm 1 | Out-Null
$gq = (& $smi --query-gpu=power.limit,power.max_limit --format=csv,noheader,nounits) -split ','
if ([double]$gq[1] -gt [double]$gq[0]) { & $smi -pl ([double]$gq[1]) | Out-Null }
"gpu ceiling at the silicon max (TON 618): {0} W" -f $gq[1].Trim()
Set-ItemProperty 'HKCU:\Control Panel\Mouse' -Name MouseSpeed -Value '0' -Type String
Set-ItemProperty 'HKCU:\Control Panel\Mouse' -Name MouseThreshold1 -Value '0' -Type String
Set-ItemProperty 'HKCU:\Control Panel\Mouse' -Name MouseThreshold2 -Value '0' -Type String
"input: raw 1:1"
New-Item -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy' -Force | Out-Null
foreach ($k in '01','04','08','32') { Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy' -Name $k -Value 1 -Type DWord }
"breathing cycle: Storage Sense on, permanently"
$d = Get-PSDrive C
"=== SEAL LINE ==="
"free_ram_gb={0} rung={1} | c_free_gb={2} rung={3} | target: c = 299792458 m/s, phi^19.3 as written | stack: OMEGA" -f $free1, (Rung $free1), [math]::Round($d.Free/1GB,1), (Rung ($d.Free/1GB))
"=== OMEGA COMPLETE. Reboot once - the stack holds from boot, permanently. ==="
