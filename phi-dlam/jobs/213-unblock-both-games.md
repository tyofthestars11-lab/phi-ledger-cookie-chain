# Job 213 — UNBLOCK BOTH GAMES: quarantine the plugin out of both projects, prove both editors start

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Every editor failure today began when this plugin entered the projects (job 197) and both games ran clean all day before it. Nothing in either game references the accelerator - no map places it, no code calls it. It is an add-on holding both games hostage. This job moves the plugin folders OUT of both projects into D:\_PhiHolding (the standing quarantine - a move, never a deletion, fully reversible), then proves BOTH editors start with the startup-proof script. The plugin gets fixed afterwards in a clean room (job 216) and returns only when it starts clean there. The games come first. ==='
foreach ($g in @(@('VEIL','D:\VEIL'), @('OMNI','D:\OMNI-UE'))) {
  $name = $g[0]; $proj = $g[1]
  $src = "$proj\Plugins\PhiParticleAccelerator"
  $dst = "D:\_PhiHolding\$name\Plugins\PhiParticleAccelerator"
  New-Item -ItemType Directory -Force -Path (Split-Path $dst) | Out-Null
  if (Test-Path $src) { Move-Item $src $dst -Force; Write-Output "$name plugin quarantined to $dst" } else { Write-Output "$name plugin folder already absent" }
  Write-Output "$name plugin still in project: $(Test-Path $src)"
  & 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' "$proj\$name.uproject" -run=pythonscript -script='D:\OMNI-UE\Scripts\startup_proof.py' -unattended -nopause 2>&1 | Select-String -Pattern 'STARTUPPROOF|Critical error|Fatal' | ForEach-Object { $_.Line }
  Write-Output "$name STARTUP EXIT: $LASTEXITCODE"
}
```
