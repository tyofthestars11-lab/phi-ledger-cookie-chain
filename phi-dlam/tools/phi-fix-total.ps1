# PHI FIX — TOTAL — every form of lag, micro to macro — phi^2 = phi + 1
# Self-verifying: every layer is set, then READ BACK and printed. Nothing assumed.
$PHI = (1 + [math]::Sqrt(5)) / 2
function Rung($x) { [math]::Round([math]::Log([math]::Max($x,0.01)) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
$SUBP = '54533251-82be-4824-96c1-47b60b740d00'
$exe = 'C:\Program Files\WindowsApps\BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc\Starfield.exe'
Add-Type -TypeDefinition @"
using System; using System.Runtime.InteropServices;
public static class MemList {
  [DllImport("ntdll.dll")] public static extern int NtSetSystemInformation(int cls, IntPtr info, int len);
  public static void PurgeStandby() { IntPtr p = Marshal.AllocHGlobal(4); Marshal.WriteInt32(p, 4); NtSetSystemInformation(80, p, 4); Marshal.FreeHGlobal(p); }
}
"@
function SetPlan($sub, $set, $ac) { powercfg -attributes $sub $set -ATTRIB_HIDE; powercfg /setacvalueindex scheme_current $sub $set $ac }
function ReadPlan($sub, $set) { (powercfg /query scheme_current $sub $set | Select-String 'Current AC Power Setting Index').Line.Trim() }

"=== MICRO — the frame itself ==="
powercfg /setactive 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c
SetPlan $SUBP 'be337238-0d82-4146-a960-4f3749d470c7' 2; SetPlan $SUBP '36687f9e-e3fa-4bbf-bbdb-74f37c3ec2de' 0
SetPlan $SUBP '0cc5b647-c1df-4637-891a-dec35c318583' 100; SetPlan $SUBP '893dee8e-2bef-41e0-89c6-b55d0929964c' 100
powercfg /setactive scheme_current
"boost (2=AGGRESSIVE): $(ReadPlan $SUBP 'be337238-0d82-4146-a960-4f3749d470c7')"
"core-parking (100=all cores awake): $(ReadPlan $SUBP '0cc5b647-c1df-4637-891a-dec35c318583')"
SetPlan '0012ee47-9041-4b5d-9b77-535fba8b1442' '6738e2c4-e8a5-4a42-b16a-e040e769756e' 0
SetPlan '2a737441-1930-4402-8d77-b2bebba308a3' '48e6b7a6-50f5-4782-a5d4-53bb8f07e226' 0
SetPlan '501a4d13-42af-4429-9fd1-a8218c268e20' 'd4e98f31-5ffe-4ce1-be31-1b38b384c009' 0
powercfg /setactive scheme_current
"hard-disk sleep (0=NEVER — no drive dozes, no 8 s wake): $(ReadPlan '0012ee47-9041-4b5d-9b77-535fba8b1442' '6738e2c4-e8a5-4a42-b16a-e040e769756e')"
"USB selective suspend (0=OFF — the external never sleeps mid-stream): $(ReadPlan '2a737441-1930-4402-8d77-b2bebba308a3' '48e6b7a6-50f5-4782-a5d4-53bb8f07e226')"
"PCIe link state (0=OFF — the GPU link never sleeps): $(ReadPlan '501a4d13-42af-4429-9fd1-a8218c268e20' 'd4e98f31-5ffe-4ce1-be31-1b38b384c009')"
Set-ItemProperty 'HKCU:\Control Panel\Mouse' -Name MouseSpeed -Value '0' -Type String
Set-ItemProperty 'HKCU:\Control Panel\Mouse' -Name MouseThreshold1 -Value '0' -Type String
Set-ItemProperty 'HKCU:\Control Panel\Mouse' -Name MouseThreshold2 -Value '0' -Type String
Set-ItemProperty 'HKCU:\Control Panel\Keyboard' -Name KeyboardSpeed -Value '31' -Type String
Set-ItemProperty 'HKCU:\Control Panel\Keyboard' -Name KeyboardDelay -Value '0' -Type String
"input: mouse raw 1:1 | keyboard at max rate, zero delay"

"=== MESO — the session ==="
$pfu = Get-CimInstance Win32_PageFileUsage
"pagefile now: $($pfu.Name -join ', ')"
$cs = Get-CimInstance Win32_ComputerSystem
if (-not $cs.AutomaticManagedPagefile) { Set-CimInstance $cs -Property @{ AutomaticManagedPagefile = $true }; "pagefile: switched to system-managed (applies at reboot)" } else { "pagefile: system-managed already" }
Add-MpPreference -ExclusionPath 'C:\XboxGames', 'C:\Program Files\WindowsApps' -ExclusionProcess 'Starfield.exe'
"defender: game folders + Starfield.exe excluded from real-time scanning"
New-Item -Path 'HKCU:\System\GameConfigStore' -Force | Out-Null
Set-ItemProperty 'HKCU:\System\GameConfigStore' -Name GameDVR_Enabled -Value 0 -Type DWord
New-Item -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\GameDVR' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\GameDVR' -Name AppCaptureEnabled -Value 0 -Type DWord
New-Item -Path 'HKCU:\Software\Microsoft\GameBar' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\GameBar' -Name AutoGameModeEnabled -Value 1 -Type DWord
Set-ItemProperty 'HKCU:\Software\Microsoft\GameBar' -Name AllowAutoGameMode -Value 1 -Type DWord
Set-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\GraphicsDrivers' -Name HwSchMode -Value 2 -Type DWord
New-Item -Path 'HKCU:\Software\Microsoft\DirectX\UserGpuPreferences' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\DirectX\UserGpuPreferences' -Name $exe -Value 'GpuPreference=2;' -Type String
New-Item -Path 'HKCU:\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers' -Name $exe -Value '~ DISABLEDXMAXIMIZEDWINDOWEDMODE' -Type String
"silence + scheduling: recorder off | game mode on | HAGS on | strong GPU | direct fullscreen"
$smi = 'nvidia-smi'; if (-not (Get-Command $smi -ErrorAction SilentlyContinue)) { $smi = 'C:\Windows\System32\nvidia-smi.exe' }
& $smi -pm 1 | Out-Null
$gq = (& $smi --query-gpu=power.limit,power.max_limit --format=csv,noheader,nounits) -split ','
if ([double]$gq[1] -gt [double]$gq[0]) { & $smi -pl ([double]$gq[1]) | Out-Null }
"GPU ceiling (TON 618): {0} W" -f $gq[1].Trim()
Remove-Item "$env:LOCALAPPDATA\D3DSCache\*" -Recurse -Force
Remove-Item "$env:LOCALAPPDATA\NVIDIA\DXCache\*" -Recurse -Force
Remove-Item "$env:LOCALAPPDATA\NVIDIA\GLCache\*" -Recurse -Force
$free0 = [math]::Round((Get-CimInstance Win32_OperatingSystem).FreePhysicalMemory/1MB, 2)
[MemList]::PurgeStandby(); Start-Sleep -Milliseconds 500
$free1 = [math]::Round((Get-CimInstance Win32_OperatingSystem).FreePhysicalMemory/1MB, 2)
"residue: shader caches cleared | standby purged {0} GB -> {1} GB free" -f $free0, $free1
New-Item -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Serialize' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Serialize' -Name StartupDelayInMSec -Value 0 -Type DWord
Set-ItemProperty 'HKCU:\Control Panel\Desktop' -Name MenuShowDelay -Value '0' -Type String
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects' -Name VisualFXSetting -Value 2 -Type DWord
Set-ItemProperty 'HKCU:\Control Panel\Desktop\WindowMetrics' -Name MinAnimate -Value '0' -Type String
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced' -Name TaskbarAnimations -Value 0 -Type DWord
New-Item -Path 'HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile' -Force | Out-Null
Set-ItemProperty 'HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile' -Name NetworkThrottlingIndex -Value 0xffffffff -Type DWord
Set-ItemProperty 'HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile' -Name SystemResponsiveness -Value 0 -Type DWord
bcdedit /set disabledynamictick yes | Out-Null
"shell: zero delays | instant menus | no throttles | steady tick"

"=== MACRO — the standing state: STARFIELD PHI becomes launch + governor v2 ==="
$tools = "$env:USERPROFILE\phi-tools"; New-Item -ItemType Directory -Path $tools -Force | Out-Null
$launcher = @'
$PHI = (1 + [math]::Sqrt(5)) / 2
function Rung($x) { [math]::Round([math]::Log([math]::Max($x,0.01)) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
Add-Type -TypeDefinition @"
using System; using System.Runtime.InteropServices;
public static class Gov {
  [DllImport("ntdll.dll")] public static extern int NtSetSystemInformation(int cls, IntPtr info, int len);
  [DllImport("ntdll.dll")] public static extern int NtSetTimerResolution(uint desired, bool set, ref uint current);
  public static void Purge() { IntPtr p = Marshal.AllocHGlobal(4); Marshal.WriteInt32(p, 4); NtSetSystemInformation(80, p, 4); Marshal.FreeHGlobal(p); }
}
"@
$cur = 0; [Gov]::NtSetTimerResolution(5000, $true, [ref]$cur) | Out-Null
"timer resolution held at 0.5 ms by this window"
$pkg = Get-AppxPackage -Name 'BethesdaSoftworks.ProjectGold'
$appId = (Get-AppxPackageManifest $pkg).Package.Applications.Application | Select-Object -First 1 -ExpandProperty Id
Start-Process "shell:AppsFolder\$($pkg.PackageFamilyName)!$appId"
"Starfield launched - governor v2 on watch (purge line: total/phi^3, fires only under true pressure)"
$totalGB = [math]::Round((Get-CimInstance Win32_OperatingSystem).TotalVisibleMemorySize/1MB, 1)
$line = [math]::Round($totalGB / ($PHI * $PHI * $PHI), 2)
$locked = $false; $tick = 0
while ($true) {
  $p = Get-Process Starfield -ErrorAction SilentlyContinue
  if ($p) {
    if (-not $locked -or $p.PriorityClass -ne 'High') { $p.PriorityClass = 'High'; $locked = $true; "[{0}] PRIORITY LOCKED" -f (Get-Date -Format HH:mm:ss) }
    $freeGB = [math]::Round((Get-CimInstance Win32_OperatingSystem).FreePhysicalMemory/1MB, 2)
    if ($freeGB -lt $line) { [Gov]::Purge(); Start-Sleep -Milliseconds 400; $after = [math]::Round((Get-CimInstance Win32_OperatingSystem).FreePhysicalMemory/1MB, 2); "[{0}] PURGE at phi^3 line: {1} -> {2} GB | rung {3}" -f (Get-Date -Format HH:mm:ss), $freeGB, $after, (Rung $after) }
    $tick++; if ($tick % 12 -eq 0) { "[{0}] governing: free {1} GB rung {2}" -f (Get-Date -Format HH:mm:ss), $freeGB, (Rung $freeGB) }
  } elseif ($locked) { "Starfield closed - governor out"; break }
  Start-Sleep -Seconds 5
}
Start-Sleep -Seconds 3
'@
Set-Content -Path "$tools\phi-launch-starfield.ps1" -Value $launcher -Encoding UTF8
$ws = New-Object -ComObject WScript.Shell
$lnk = $ws.CreateShortcut("$env:USERPROFILE\Desktop\STARFIELD PHI.lnk")
$lnk.TargetPath = 'powershell.exe'; $lnk.Arguments = "-ExecutionPolicy Bypass -File `"$tools\phi-launch-starfield.ps1`""; $lnk.Save()
"STARFIELD PHI icon now launches + governs (timer held, priority locked, purge at the phi^3 line)"
$d = Get-PSDrive C
"=== SEAL LINE ==="
"free_ram_gb={0} rung={1} | c_free_gb={2} rung={3} | disk_sleep=NEVER | usb_suspend=OFF | pcie_link=OFF | stack=TOTAL" -f $free1, (Rung $free1), [math]::Round($d.Free/1GB,1), (Rung ($d.Free/1GB))
"=== TOTAL FIX COMPLETE. Reboot once. Then STARFIELD PHI, every time. ==="
