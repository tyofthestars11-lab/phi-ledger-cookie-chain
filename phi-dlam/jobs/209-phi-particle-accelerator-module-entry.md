# Job 209 — Phi Particle Accelerator: module entry point, rebuild, and a startup proof (not just a build proof)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$eng = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Write-Output '=== Job 206 landed the builds (Succeeded x2, DLL 146432 bytes both projects) - and jobs 207/208 proved the next break at RUNTIME: the module loads, then "could not be initialized successfully after it was loaded", and every editor commandlet dies with a CoreUObject access violation (exit 3). The vault sources name the cause: the delivered package contains no IMPLEMENT_MODULE anywhere - a Runtime module DLL with no entry point. The vault copies now carry Private/PhiParticleAcceleratorModule.cpp with IMPLEMENT_MODULE(FDefaultModuleImpl, PhiParticleAccelerator). This job re-copies, rebuilds both, then proves STARTUP - a one-line Python commandlet that must print and exit 0 - because a build alone no longer counts as the plugin standing. ==='
foreach ($g in @(@('VEIL','D:\VEIL'), @('OMNI','D:\OMNI-UE'))) {
  $name = $g[0]; $proj = $g[1]
  $dst = "$proj\Plugins\PhiParticleAccelerator"
  Copy-Item "C:\Users\Admin\phi-vault\veil\$name\Plugins\PhiParticleAccelerator\*" -Destination $dst -Recurse -Force
  $build = & $eng "$($name)Editor" Win64 Development "-Project=$proj\$name.uproject" -WaitMutex 2>&1
  $build | Select-String -Pattern 'Result:|error|Error' | ForEach-Object { $_.Line }
  $dll = "$dst\Binaries\Win64\UnrealEditor-PhiParticleAccelerator.dll"
  if (Test-Path $dll) { Write-Output "$name PLUGIN DLL: $((Get-Item $dll).Length) bytes" } else { Write-Output "$name PLUGIN DLL: ABSENT" }
}
Set-Content -Path 'D:\OMNI-UE\Scripts\startup_proof.py' -Value "print('STARTUPPROOF editor started with plugin loaded')" -Encoding UTF8
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\startup_proof.py' -unattended -nopause 2>&1 | Select-String -Pattern 'STARTUPPROOF|PhiParticleAccelerator|Critical error|Fatal' | ForEach-Object { $_.Line }
Write-Output "startup proof exit: $LASTEXITCODE"
```
