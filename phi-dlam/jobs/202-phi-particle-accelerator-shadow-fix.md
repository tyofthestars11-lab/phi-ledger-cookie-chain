# Job 202 — Phi Particle Accelerator: MaxRung shadowing fix, re-copy, rebuild both

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$eng = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Write-Output '=== Job 199 verdict: the Build.cs name fix landed (PublicDependencyModuleNames on disk both projects) and UHT then named an eighth delivered break - UFUNCTION parameters named MaxRung shadow the class MaxRung stat member (header 169 + 182, both builds, OtherCompilationError). The vault copies rename those parameters MaxRungIn. The GameMode.h first-header line also printed in 199; it printed beside a Succeeded in job 189, so this rebuild reads whether it stands alone or hard-fails. This job re-copies and rebuilds both. ==='
foreach ($g in @(@('VEIL','D:\VEIL'), @('OMNI','D:\OMNI-UE'))) {
  $name = $g[0]; $proj = $g[1]
  $dst = "$proj\Plugins\PhiParticleAccelerator"
  Copy-Item "C:\Users\Admin\phi-vault\veil\$name\Plugins\PhiParticleAccelerator\*" -Destination $dst -Recurse -Force
  $build = & $eng "$($name)Editor" Win64 Development "-Project=$proj\$name.uproject" -WaitMutex 2>&1
  $build | Select-String -Pattern 'Result:|error|Error' | ForEach-Object { $_.Line }
  $dll = "$dst\Binaries\Win64\UnrealEditor-PhiParticleAccelerator.dll"
  if (Test-Path $dll) { Write-Output "$name PLUGIN DLL: $((Get-Item $dll).Length) bytes at $dll" } else { Write-Output "$name PLUGIN DLL: ABSENT" }
}
```
