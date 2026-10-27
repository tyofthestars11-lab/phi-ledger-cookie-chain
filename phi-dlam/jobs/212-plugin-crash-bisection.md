# Job 212 — Plugin crash bisection: did 209's fix land, what does the crash record name, does the plugin crash a clean room

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 209 rebuilt Succeeded x2 yet the startup proof died identically (plugin init error, CoreUObject AV, exit 3), and the DLL size did not move: 146432 bytes before and after. Three questions, one job. (1) Did the module file ever land on this disk, and when was the DLL actually written? (2) What does Epics own crash record (newest Saved/Crashes folder, OMNI) name as the faulting module? (3) Clean-room test: the identical plugin folder, copied whole from D:\VEIL, inside a blank project with no ABP, no game content - does the editor start? Pre-registered read: crash reproduces in the clean room = the plugin build itself is the seat. Clean room starts = VEIL/OMNI project state is the seat (the ABP compiler errors print before every crash, and its malformed delegate property is created inside CoreUObject). ==='
$mod = 'D:\VEIL\Plugins\PhiParticleAccelerator\Source\PhiParticleAccelerator\Private\PhiParticleAcceleratorModule.cpp'
if (Test-Path $mod) { Write-Output "MODULE FILE ON DISK: yes, written $((Get-Item $mod).LastWriteTime)" } else { Write-Output 'MODULE FILE ON DISK: NO - job 209s fix never landed' }
$dll = 'D:\VEIL\Plugins\PhiParticleAccelerator\Binaries\Win64\UnrealEditor-PhiParticleAccelerator.dll'
Write-Output "VEIL DLL: $((Get-Item $dll).Length) bytes, written $((Get-Item $dll).LastWriteTime)"
$crashes = Get-ChildItem 'D:\OMNI-UE\Saved\Crashes' -Directory -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($crashes) {
  Write-Output "--- newest crash folder: $($crashes.Name) ---"
  $ctx = Get-ChildItem $crashes.FullName -Filter '*.runtime-xml' -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($ctx) { Select-String -Path $ctx.FullName -Pattern 'ErrorMessage|CallStack|Module|PCallStack' | Select-Object -First 12 | ForEach-Object { $_.Line.Trim() } }
  $log = Get-ChildItem $crashes.FullName -Filter '*.log' -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($log) { Write-Output '--- crash log tail ---'; Get-Content $log.FullName -Tail 25 }
}
New-Item -ItemType Directory -Force -Path 'D:\_PhiTest\Plugins' | Out-Null
@'
{
    "FileVersion": 3,
    "EngineAssociation": "5.8",
    "Category": "Games",
    "Description": "Clean-room plugin bisection project. No modules, no content.",
    "Plugins": [ { "Name": "PhiParticleAccelerator", "Enabled": true } ]
}
'@ | Set-Content -Path 'D:\_PhiTest\PhiTest.uproject' -Encoding UTF8
Copy-Item 'D:\VEIL\Plugins\PhiParticleAccelerator' -Destination 'D:\_PhiTest\Plugins\PhiParticleAccelerator' -Recurse -Force
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\_PhiTest\PhiTest.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\startup_proof.py' -unattended -nopause 2>&1 | Select-String -Pattern 'STARTUPPROOF|PhiParticleAccelerator|Critical error|Fatal|Error' | ForEach-Object { $_.Line }
Write-Output "CLEAN-ROOM EXIT: $LASTEXITCODE"
```
