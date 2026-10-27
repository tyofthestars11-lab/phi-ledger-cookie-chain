# Job 217 — Plugin: forced rebuild in the clean room from vault sources (job 212 proved the running DLL predates the entry-point fix)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$eng = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Write-Output '=== Job 212s timestamps settled it: the module file landed on disk at 17:14:28 but the VEIL DLL was written 17:06:32 - job 206s build. Job 209s rebuild never relinked the binary, so the IMPLEMENT_MODULE fix has never actually been tested; every crash since (207-212, both of Tyrees GUI launches) ran the stale DLL. OMNIs crash log adds the second half: the editor loads the DLL, prints the init failure, shows the dialog, exits - and the access violation fires during shutdown cleanup of the half-initialized module. Root event = the init failure alone. This job rebuilds the plugin FOR REAL in the clean room: fresh copy of the vault sources (which carry all eleven fixes), the plugins Intermediate and Binaries wiped in the TEST project only so no stale binary can survive, a full PhiTestEditor build, and the startup proof. ==='
$dst = 'D:\_PhiTest\Plugins\PhiParticleAccelerator'
if (Test-Path $dst) { Remove-Item $dst -Recurse -Force }
Copy-Item 'C:\Users\Admin\phi-vault\veil\VEIL\Plugins\PhiParticleAccelerator' -Destination $dst -Recurse -Force
Write-Output "module file in test copy: $(Test-Path "$dst\Source\PhiParticleAccelerator\Private\PhiParticleAcceleratorModule.cpp")"
$build = & $eng 'PhiTestEditor' Win64 Development '-Project=D:\_PhiTest\PhiTest.uproject' -WaitMutex 2>&1
$build | Select-String -Pattern 'Result:|error|Error' | ForEach-Object { $_.Line }
$dll = "$dst\Binaries\Win64\UnrealEditor-PhiParticleAccelerator.dll"
if (Test-Path $dll) { Write-Output "TEST PLUGIN DLL: $((Get-Item $dll).Length) bytes, written $((Get-Item $dll).LastWriteTime)" } else { Write-Output 'TEST PLUGIN DLL: ABSENT' }
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\_PhiTest\PhiTest.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\startup_proof.py' -unattended -nopause 2>&1 | Select-String -Pattern 'STARTUPPROOF|PhiParticleAccelerator|Critical error|Fatal|Error' | ForEach-Object { $_.Line }
Write-Output "CLEAN-ROOM STARTUP EXIT: $LASTEXITCODE"
```
