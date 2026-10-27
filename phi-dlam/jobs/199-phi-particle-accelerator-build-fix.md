# Job 199 — Phi Particle Accelerator: Build.cs dependency-name fix, re-copy, rebuild both

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$eng = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Write-Output '=== Job 197 found a seventh delivered break, in the Build.cs itself: it named the dependency list PublicDependencies, which does not exist on UE 5.8 ModuleRules - both builds failed CS0103 at (9,9), Result: Failed (RulesError), no DLLs. The vault copies now use the real member name PublicDependencyModuleNames. This job re-copies the plugin into both projects and rebuilds both editors. ==='
foreach ($g in @(@('VEIL','D:\VEIL'), @('OMNI','D:\OMNI-UE'))) {
  $name = $g[0]; $proj = $g[1]
  $dst = "$proj\Plugins\PhiParticleAccelerator"
  Copy-Item "C:\Users\Admin\phi-vault\veil\$name\Plugins\PhiParticleAccelerator\*" -Destination $dst -Recurse -Force
  Write-Output "--- $name Build.cs dependency line on disk ---"
  Select-String -Path "$dst\Source\PhiParticleAccelerator\PhiParticleAccelerator.Build.cs" -Pattern 'Dependency' | ForEach-Object { $_.Line.Trim() }
  $build = & $eng "$($name)Editor" Win64 Development "-Project=$proj\$name.uproject" -WaitMutex 2>&1
  $build | Select-String -Pattern 'Result:|error|Error' | ForEach-Object { $_.Line }
  $dll = "$dst\Binaries\Win64\UnrealEditor-PhiParticleAccelerator.dll"
  if (Test-Path $dll) { Write-Output "$name PLUGIN DLL: $((Get-Item $dll).Length) bytes at $dll" } else { Write-Output "$name PLUGIN DLL: ABSENT" }
}
```
