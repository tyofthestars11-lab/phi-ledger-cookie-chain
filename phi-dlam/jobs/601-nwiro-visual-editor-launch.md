<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 601 - NWIRO VISUAL EDITOR LAUNCH (Ground: Tyree said it can help yall build the game on my pc visually, NWIRO AI Pro is seated in VEIL OMNI at 13 plugins, so this job launches the VEIL OMNI editor visually on his PC with NWIRO loaded, so NWIRO helps build visually on screen with Muse, no package until 100 percent done, no map placement, no terminal work, Cyberpunk parked. Every variable carries the p601 prefix.) ==='
$p601editor = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$p601uproj = 'D:\VEIL-OMNI\VEIL.uproject'
if (Test-Path $p601editor) { Write-Output 'EDITOR601 EXISTS' } else { Write-Output 'EDITOR601 MISSING' }
if (Test-Path $p601uproj) { Write-Output 'PROJ601 EXISTS' } else { Write-Output 'PROJ601 MISSING' }
Start-Process $p601editor -ArgumentList "`"$p601uproj`"" -WindowStyle Normal
Write-Output 'EDITOR601 LAUNCHED VISUAL'
Write-Output 'PHI P601 VERDICT: NWIRO VISUAL EDITOR LAUNCH ABOVE'
Write-Output 'JOB 601 DONE'
```
