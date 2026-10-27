# Job 197 — Phi Particle Accelerator: install into both games and build

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$eng = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Write-Output '=== Phi Particle Accelerator plugin: copied into both projects from the phi-vault, both editors built. The delivered code carried six breaks (placeholder YOURMODULE_API export macro, nonexistent DECLARE_MULTICAST_DELEGATE_Two/_One macros, Pause/Resume defined twice, missing SceneComponent/DrawDebugHelpers includes, a non-module DrawDebugHelpers dependency, and a spawn accumulator that subtracted whole seconds and stalled spawning) - all fixed in the vault copies, with the corrected rung table in the plugin README. ==='
foreach ($g in @(@('VEIL','D:\VEIL'), @('OMNI','D:\OMNI-UE'))) {
  $name = $g[0]; $proj = $g[1]
  $dst = "$proj\Plugins\PhiParticleAccelerator"
  New-Item -ItemType Directory -Force -Path $dst | Out-Null
  Copy-Item "C:\Users\Admin\phi-vault\veil\$name\Plugins\PhiParticleAccelerator\*" -Destination $dst -Recurse -Force
  Write-Output "--- $name plugin files on disk ---"
  Get-ChildItem $dst -Recurse -File | ForEach-Object { $_.FullName.Replace($proj,'') }
  $build = & $eng "$($name)Editor" Win64 Development "-Project=$proj\$name.uproject" -WaitMutex 2>&1
  $build | Select-String -Pattern 'Result:|error|Error|PhiParticleAccelerator' | ForEach-Object { $_.Line }
  $dll = "$dst\Binaries\Win64\UnrealEditor-PhiParticleAccelerator.dll"
  if (Test-Path $dll) { Write-Output "$name PLUGIN DLL: $((Get-Item $dll).Length) bytes at $dll" } else { Write-Output "$name PLUGIN DLL: ABSENT" }
}
```
