# Job 206 — Phi Particle Accelerator: arithmetic lerp, re-copy, rebuild both (the DLL gates every editor read)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$eng = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Write-Output '=== Job 203 verdict: this seats own helper named FLinearColor::Lerp, which also does not exist in UE 5.8 (C2039 at the helper line, both builds). The vault copies now compute the gradient in pure arithmetic - (LA + (LB - LA) * clamp(T)).ToFColorSRGB() - no Lerp member anywhere. Stakes beyond the plugin: jobs 200/204/205 proved every editor commandlet in both projects ABORTS at startup while this plugin has no DLL (plugin load error, exit 1, scripts never run) - the ABP deep read and the WorldSettings read are both queued behind this build. This job re-copies and rebuilds both. ==='
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
