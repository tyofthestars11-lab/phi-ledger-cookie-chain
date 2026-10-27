# Job 216 — Plugin diagnosis in the clean room: does the quarantined plugin crash a blank project on its own

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== The games are unblocked (job 213); the plugin now gets diagnosed in isolation, where it can block nothing. The quarantined VEIL copy (sources + built DLL, exactly as it stood in the project) goes into a blank project with no ABP and no game content, and the startup proof runs. Pre-registered read: crash reproduces here = the plugin build itself carries the defect, and the next step bisects its code; blank project starts = the defect lives in the interaction, and the plugin returns to the games only after that interaction is named. ==='
New-Item -ItemType Directory -Force -Path 'D:\_PhiTest\Plugins' | Out-Null
@'
{
    "FileVersion": 3,
    "EngineAssociation": "5.8",
    "Category": "Games",
    "Description": "Clean-room plugin diagnosis project. No modules, no content.",
    "Plugins": [ { "Name": "PhiParticleAccelerator", "Enabled": true } ]
}
'@ | Set-Content -Path 'D:\_PhiTest\PhiTest.uproject' -Encoding UTF8
if (Test-Path 'D:\_PhiTest\Plugins\PhiParticleAccelerator') { Remove-Item 'D:\_PhiTest\Plugins\PhiParticleAccelerator' -Recurse -Force }
Copy-Item 'D:\_PhiHolding\VEIL\Plugins\PhiParticleAccelerator' -Destination 'D:\_PhiTest\Plugins\PhiParticleAccelerator' -Recurse -Force
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\_PhiTest\PhiTest.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\startup_proof.py' -unattended -nopause 2>&1 | Select-String -Pattern 'STARTUPPROOF|PhiParticleAccelerator|Critical error|Fatal|Error' | ForEach-Object { $_.Line }
Write-Output "CLEAN-ROOM EXIT: $LASTEXITCODE"
```
