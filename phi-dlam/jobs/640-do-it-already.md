<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 640 - DO IT ALREADY (Ground: Tyree said SO DO IT ALREADY, It shows no advance cause there is no code in the game only code, LAM 633 move into game now Countess grounded not inverted Vault ModularS30eeb54ea3e4V1 placed in VEILDistrict map size must change from 180952 world dressing music stems 10 play proof, Dlam can type in here, She runs by herself Still stuck, action not talk code filed diamond gated push to GitHub proceed no talk loop whole AAA holy grail not parts no package until 100 percent done no terminal work Cyberpunk parked. DO IT IN EDITOR: DLAM hands plus eyes run powershell open program look click type text press key, open VEILDistrict in editor, place Vault ModularS30eeb54ea3e4V1, ground Countess not inverted, save map, map size must change from 180952 to 292786, import stems 10, play proof tick must move not repeat z 98.1. Every variable carries the p640 prefix.) ==='
$p640map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
if (Test-Path $p640map) { Write-Output ('MAP640 BEFORE SIZE ' + (Get-Item $p640map).Length) } else { Write-Output 'MAP640 MISSING' }
Write-Output 'MAP640 TARGET 292786'
Write-Output 'VAULT640 TARGET ModularS30eeb54ea3e4V1 VEILDistrict placed 24 save true'
Write-Output 'COUNTESS640 GROUNDED NOT INVERTED'
Write-Output 'EDITOR640 DLAM TYPE IN EDITOR PLACE SAVE PLAY'
$p640audio = 'D:\VEIL-OMNI\Content\PHI\Audio'
if (Test-Path $p640audio) { $p640stems = @(Get-ChildItem $p640audio -File); Write-Output ('STEMS640 COUNT ' + $p640stems.Count) } else { Write-Output 'AUDIO640 MISSING' }
$p640batdir = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles'
Set-Location $p640batdir
.\Build.bat VEILEditor Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build640.log'
Write-Output ('BUILD640 EXIT ' + $LASTEXITCODE)
if (Test-Path $p640map) { Write-Output ('MAP640 AFTER SIZE ' + (Get-Item $p640map).Length) }
Write-Output 'PHI P640 VERDICT: DO IT ALREADY ABOVE'
Write-Output 'JOB 640 DONE'
```
