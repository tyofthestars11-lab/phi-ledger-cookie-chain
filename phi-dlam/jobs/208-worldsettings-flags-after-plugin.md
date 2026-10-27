# Job 208 — WorldSettings tick flags, rerun after the plugin DLL exists (job 205 was aborted by the same gate)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$dll = 'D:\VEIL\Plugins\PhiParticleAccelerator\Binaries\Win64\UnrealEditor-PhiParticleAccelerator.dll'
Write-Output '=== Job 205 produced no WSREAD lines at all: both of its commandlet runs aborted at the PhiParticleAccelerator plugin load error (exit 1) before the script executed - the same gate jobs 204/207 named. If job 206 landed the DLL, this rerun of the WorldSettings flag read (job 205s script, unchanged) executes: bEnableWorldTick and Pauser as persisted in VEILWorld, VEILDistrict and OMNIWorld. If the DLL is still absent this job says so and stops. ==='
if (-not (Test-Path $dll)) { Write-Output 'PLUGIN DLL STILL ABSENT - flag read cannot run; job 206s verdict governs.'; return }
Write-Output 'PLUGIN DLL PRESENT - running the flag read'
$console = 'D:\VEIL\Saved\ws-read2-console.txt'
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\ws_read.py' -unattended -nopause 2>&1 | Set-Content $console
Write-Output "VEIL run exit: $LASTEXITCODE"
Select-String -Path $console -Pattern 'WSREAD|Error|Traceback|Exception' | ForEach-Object { $_.Line }
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\OMNI-UE\OMNI.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\ws_read.py' -unattended -nopause 2>&1 | Set-Content $console
Write-Output "OMNI run exit: $LASTEXITCODE"
Select-String -Path $console -Pattern 'WSREAD|Error|Traceback|Exception' | ForEach-Object { $_.Line }
```
