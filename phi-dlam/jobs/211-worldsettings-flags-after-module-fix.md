# Job 211 — WorldSettings tick flags, rerun after the module entry fix

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$console = 'D:\VEIL\Saved\ws-read3-console.txt'
Write-Output '=== Job 208s flag read died in the same CoreUObject crash as job 207 (the plugin modules missing entry point). Job 209 restores the entry point and proves startup. This job reruns job 205s script unchanged: WorldSettings bEnableWorldTick and Pauser as persisted in VEILWorld, VEILDistrict (under VEIL) and OMNIWorld (under OMNI) - the last two unread flags on the frozen-clock board. ==='
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\ws_read.py' -unattended -nopause 2>&1 | Set-Content $console
Write-Output "VEIL run exit: $LASTEXITCODE"
Select-String -Path $console -Pattern 'WSREAD|Error|Traceback|Exception' | ForEach-Object { $_.Line }
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\OMNI-UE\OMNI.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\ws_read.py' -unattended -nopause 2>&1 | Set-Content $console
Write-Output "OMNI run exit: $LASTEXITCODE"
Select-String -Path $console -Pattern 'WSREAD|Error|Traceback|Exception' | ForEach-Object { $_.Line }
```
