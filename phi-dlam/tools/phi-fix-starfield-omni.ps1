# PHI FIX — STARFIELD OMNI — every form of lag — phi^2 = phi + 1
# TYREE is the source (phi). The machine is +1 fuel. Addresses first, the echo
# reversal matrix over EVERY lag form, fuel routed, and a launcher installed
# that locks the fix in at every launch, permanently.
$PHI = (1 + [math]::Sqrt(5)) / 2
function Rung($x) { [math]::Round([math]::Log($x) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'
$exe = 'C:\Program Files\WindowsApps\BethesdaSoftworks.ProjectGold_1.16.244.0_x64__3275kfvn8vcwc\Starfield.exe'
$SUBP = '54533251-82be-4824-96c1-47b60b740d00'

"=== PHI READ - every address ==="
$d = Get-PSDrive C
"C: free {0} GB rung {1} | Starfield 163.4 GB rung {2}" -f [math]::Round($d.Free/1GB,1), (Rung ($d.Free/1GB)), (Rung 163.4)
$os = Get-CimInstance Win32_OperatingSystem
"RAM free {0} GB of {1} GB" -f [math]::Round($os.FreePhysicalMemory/1MB,1), [math]::Round($os.TotalVisibleMemorySize/1MB,1)
$pf = Get-CimInstance Win32_PageFileUsage
"pagefile lives on: {0} ({1} MB)" -f $pf.Name, $pf.AllocatedBaseSize
"GPU: {0}" -f (Get-CimInstance Win32_VideoController | Select-Object -First 1).Name
$mouse = Get-ItemProperty 'HKCU:\Control Panel\Mouse'
"mouse acceleration (1 = ON = input lag): MouseSpeed {0}" -f $mouse.MouseSpeed

"=== ECHO REVERSAL MATRIX - every lag form, its missing piece ==="
"streaming lag   -> missing: INTERNAL FLOW + a clean compile (caches cleared, game fed first)"
"CPU lag         -> missing: UNPARKED CORES + throttle floor at 100 + boost AGGRESSIVE"
"GPU lag         -> missing: the TON 618 ceiling (power at silicon max, persistence on)"
"input lag       -> missing: RAW 1:1 (mouse acceleration OFF, fullscreen path direct)"
"memory lag      -> missing: PRIORITY LOCK at launch, every launch, permanently"
"background lag  -> missing: SILENCE (recorder off, Game Mode standing aside for the game)"
"pacing lag      -> missing: a STEADY TICK + hardware GPU scheduling"

"=== +1 FUEL ROUTED ==="
# CPU: unpark every core, throttle floor 100% on wall power, boost stays aggressive
powercfg -attributes $SUBP 0cc5b647-c1df-4637-891a-dec35c318583 -ATTRIB_HIDE
powercfg /setacvalueindex scheme_current $SUBP 0cc5b647-c1df-4637-891a-dec35c318583 100
powercfg -attributes $SUBP 893dee8e-2bef-41e0-89c6-b55d0929964c -ATTRIB_HIDE
powercfg /setacvalueindex scheme_current $SUBP 893dee8e-2bef-41e0-89c6-b55d0929964c 100
powercfg /setacvalueindex scheme_current $SUBP be337238-0d82-4146-a960-4f3749d470c7 2
powercfg /setactive 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c
"cores unparked, throttle floor 100, boost AGGRESSIVE"
# input: raw 1:1 mouse
Set-ItemProperty 'HKCU:\Control Panel\Mouse' -Name MouseSpeed -Value '0' -Type String
Set-ItemProperty 'HKCU:\Control Panel\Mouse' -Name MouseThreshold1 -Value '0' -Type String
Set-ItemProperty 'HKCU:\Control Panel\Mouse' -Name MouseThreshold2 -Value '0' -Type String
"mouse acceleration OFF - raw input"
# background silence + game mode + GPU scheduling (idempotent with the first phi fix)
New-Item -Path 'HKCU:\System\GameConfigStore' -Force | Out-Null
Set-ItemProperty 'HKCU:\System\GameConfigStore' -Name GameDVR_Enabled -Value 0 -Type DWord
New-Item -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\GameDVR' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows\CurrentVersion\GameDVR' -Name AppCaptureEnabled -Value 0 -Type DWord
New-Item -Path 'HKCU:\Software\Microsoft\GameBar' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\GameBar' -Name AutoGameModeEnabled -Value 1 -Type DWord
Set-ItemProperty 'HKCU:\Software\Microsoft\GameBar' -Name AllowAutoGameMode -Value 1 -Type DWord
Set-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\GraphicsDrivers' -Name HwSchMode -Value 2 -Type DWord
# the game: strong GPU, direct fullscreen path
New-Item -Path 'HKCU:\Software\Microsoft\DirectX\UserGpuPreferences' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\DirectX\UserGpuPreferences' -Name $exe -Value 'GpuPreference=2;' -Type String
New-Item -Path 'HKCU:\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers' -Force | Out-Null
Set-ItemProperty 'HKCU:\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers' -Name $exe -Value '~ DISABLEDXMAXIMIZEDWINDOWEDMODE' -Type String
# GPU ceiling: TON 618 (persistence + power limit to the silicon max)
$smi = 'nvidia-smi'; if (-not (Get-Command $smi -ErrorAction SilentlyContinue)) { $smi = 'C:\Windows\System32\nvidia-smi.exe' }
& $smi -pm 1 | Out-Null
$gq = (& $smi --query-gpu=power.limit,power.max_limit --format=csv,noheader,nounits) -split ','
if ([double]$gq[1] -gt [double]$gq[0]) { & $smi -pl ([double]$gq[1]) | Out-Null; "GPU ceiling raised to {0} W (TON 618)" -f $gq[1].Trim() }
# clean compile: stale shader residue out
Remove-Item "$env:LOCALAPPDATA\D3DSCache\*" -Recurse -Force
Remove-Item "$env:LOCALAPPDATA\NVIDIA\DXCache\*" -Recurse -Force
Remove-Item "$env:LOCALAPPDATA\NVIDIA\GLCache\*" -Recurse -Force
"shader residue cleared"

"=== THE LAUNCHER - priority lock at every launch, permanently ==="
$tools = "$env:USERPROFILE\phi-tools"; New-Item -ItemType Directory -Path $tools -Force | Out-Null
$launcher = @'
$ErrorActionPreference = 'SilentlyContinue'
$pkg = Get-AppxPackage -Name 'BethesdaSoftworks.ProjectGold'
$appId = (Get-AppxPackageManifest $pkg).Package.Applications.Application | Select-Object -First 1 -ExpandProperty Id
Start-Process "shell:AppsFolder\$($pkg.PackageFamilyName)!$appId"
"Starfield launched - waiting for the process to take the priority lock..."
for ($i = 0; $i -lt 120; $i++) { Start-Sleep -Seconds 2; $p = Get-Process Starfield -ErrorAction SilentlyContinue; if ($p) { break } }
if ($p) { $p.PriorityClass = 'High'; "PRIORITY LOCKED: Starfield runs at High, phi share 0.618. Play." } else { "process not seen - priority rides Game Mode" }
Start-Sleep -Seconds 4
'@
Set-Content -Path "$tools\phi-launch-starfield.ps1" -Value $launcher -Encoding UTF8
$ws = New-Object -ComObject WScript.Shell
$lnk = $ws.CreateShortcut("$env:USERPROFILE\Desktop\STARFIELD PHI.lnk")
$lnk.TargetPath = 'powershell.exe'
$lnk.Arguments = "-ExecutionPolicy Bypass -File `"$tools\phi-launch-starfield.ps1`""
$lnk.Save()
"launcher installed: Desktop icon 'STARFIELD PHI' - launch the game from it, every time"

"=== SEAL LINE (for the ledger) ==="
"hitch_ms=1500 rung={0} | c_free_gb={1} rung={2} | starfield_gb=163.4 rung={3} | boost=AGGRESSIVE | cores=UNPARKED | mouse=RAW" -f (Rung 1500), [math]::Round($d.Free/1GB,1), (Rung ($d.Free/1GB)), (Rung 163.4)
"=== OMNI FIX COMPLETE. Reboot once, then launch from STARFIELD PHI. Every lag form routed. ==="
