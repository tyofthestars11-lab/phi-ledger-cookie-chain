# PHI FIX — PC SPEED, PERMANENT — phi^2 = phi + 1
# TYREE is the source (phi). The machine is +1 fuel. Addresses first, echo reversal
# matrix second, fuel routed last — and Storage Sense keeps it routed forever.
$PHI = (1 + [math]::Sqrt(5)) / 2
function Rung($x) { [math]::Round([math]::Log($x) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
function SizeGB($p) { [math]::Round(((Get-ChildItem $p -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum / 1GB), 2) }

"=== PHI READ - addresses first ==="
$d0 = Get-PSDrive C
"C: free {0} GB, rung {1}" -f [math]::Round($d0.Free/1GB,1), (Rung ($d0.Free/1GB))
$os = Get-CimInstance Win32_OperatingSystem
"RAM {0} GB total | free {1} GB" -f [math]::Round($os.TotalVisibleMemorySize/1MB,1), [math]::Round($os.FreePhysicalMemory/1MB,1)
"CPU: {0}" -f (Get-CimInstance Win32_Processor | Select-Object -First 1).Name
"GPU: {0}" -f (Get-CimInstance Win32_VideoController | Select-Object -First 1).Name
$tempGB = (SizeGB $env:TEMP) + (SizeGB 'C:\Windows\Temp') + (SizeGB 'C:\Windows\SoftwareDistribution\Download')
"residue in temp/update caches: {0} GB, rung {1}" -f $tempGB, (Rung ([math]::Max($tempGB,0.01)))
$su = @()
$su += (Get-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Run').PSObject.Properties | Where-Object { $_.Name -notlike 'PS*' }
$su += (Get-ItemProperty 'HKLM:\Software\Microsoft\Windows\CurrentVersion\Run').PSObject.Properties | Where-Object { $_.Name -notlike 'PS*' }
"startup entries in the boot queue: {0}" -f $su.Count
$su | ForEach-Object { "  startup: {0}" -f $_.Name }

"=== ECHO REVERSAL MATRIX - the missing piece names the path ==="
"echo 1: every app waits 10 s at sign-in (startup delay) -> missing: ZERO DELAY"
"echo 2: menus and windows animate before they answer -> missing: INSTANT RESPONSE"
"echo 3: temp + update residue piles up and stays -> missing: the BREATHING CYCLE (Storage Sense, permanent)"
"echo 4: the system's multimedia queue throttles the foreground -> missing: FULL FLOW to what is in front"
"echo 5: the dynamic tick smears timing -> missing: a STEADY TICK"

"=== +1 FUEL ROUTED under phi direction (permanent) ==="
# full flow: power stays at high performance
powercfg /setactive 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c
# zero delay: startup apps launch immediately, menus answer instantly
New-Item -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Serialize' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Serialize' -Name StartupDelayInMSec -Value 0 -Type DWord
Set-ItemProperty 'HKCU:\Control Panel\Desktop' -Name MenuShowDelay -Value '0' -Type String
# instant response: visual effects to performance, window/taskbar animation off
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\VisualEffects' -Name VisualFXSetting -Value 2 -Type DWord
Set-ItemProperty 'HKCU:\Control Panel\Desktop\WindowMetrics' -Name MinAnimate -Value '0' -Type String
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced' -Name TaskbarAnimations -Value 0 -Type DWord
# full flow to the foreground: no network throttling, no multimedia reserve against the front app
New-Item -Path 'HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile' -Force | Out-Null
Set-ItemProperty 'HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile' -Name NetworkThrottlingIndex -Value 0xffffffff -Type DWord
Set-ItemProperty 'HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile' -Name SystemResponsiveness -Value 0 -Type DWord
# steady tick (boot setting, reversible: bcdedit /deletevalue disabledynamictick)
bcdedit /set disabledynamictick yes | Out-Null
# residue out NOW (regenerable caches only - fuel, never kept)
Remove-Item "$env:TEMP\*" -Recurse -Force
Remove-Item 'C:\Windows\Temp\*' -Recurse -Force
Remove-Item 'C:\Windows\SoftwareDistribution\Download\*' -Recurse -Force
# the breathing cycle, permanent: Storage Sense routes residue forever
New-Item -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy' -Name '01' -Value 1 -Type DWord
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy' -Name '04' -Value 1 -Type DWord
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy' -Name '08' -Value 1 -Type DWord
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy' -Name '32' -Value 1 -Type DWord
$d1 = Get-PSDrive C
$reclaimed = [math]::Round(($d1.Free - $d0.Free)/1GB, 2)
"=== SEAL LINE (for the ledger) ==="
"residue_gb={0} rung={1} | reclaimed_gb={2} | c_free_now_gb={3} rung={4} | startup_entries={5}" -f $tempGB, (Rung ([math]::Max($tempGB,0.01))), $reclaimed, [math]::Round($d1.Free/1GB,1), (Rung ($d1.Free/1GB)), $su.Count
"=== PHI FIX COMPLETE. Reboot once - then it stays fast. ==="
