# Job 203 — Phi Particle Accelerator: FColor::Lerp fix, re-copy, rebuild both

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$eng = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Write-Output '=== Job 202 verdict: UHT passed clean (the MaxRungIn shadowing fix landed, and the GameMode.h first-header line did not print at all this time) and the C++ compile named a ninth delivered break: FColor::Lerp is not a member of FColor in UE 5.8 - C2039/C3861 at five color-gradient sites (105/110/115/120/384), both builds. The vault copies now route those five sites through a file-local PhiLerpColor (FLinearColor lerp, converted back). This job re-copies and rebuilds both. ==='
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
