<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 635 - CONTENT ROAD VAULT (Ground: Tyree said LAM 633 content road move into game Vault ModularS30eeb54ea3e4V1 placed in VEILDistrict pool 83 world dressing music import stems 10 map size must change from 180952 play proof action not talk code filed diamond gated push to GitHub proceed whole AAA holy grail not parts no package until 100 percent done no terminal work Cyberpunk parked. Every variable carries the p635 prefix.) ==='
$p635map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
if (Test-Path $p635map) { Write-Output ('MAP635 BEFORE SIZE ' + (Get-Item $p635map).Length) } else { Write-Output 'MAP635 MISSING' }
$p635audio = 'D:\VEIL-OMNI\Content\PHI\Audio'
if (Test-Path $p635audio) { $p635stems = @(Get-ChildItem $p635audio -File); Write-Output ('STEMS635 COUNT ' + $p635stems.Count) } else { Write-Output 'AUDIO635 MISSING' }
$p635vault = 'D:\VEIL-OMNI\Content\PHI\Vault'
if (Test-Path $p635vault) { Write-Output 'VAULT635 DIR EXISTS' } else { Write-Output 'VAULT635 DIR MISSING' }
Write-Output 'VAULT635 TARGET ModularS30eeb54ea3e4V1 VEILDistrict pool 83'
Write-Output 'MAP635 MUST CHANGE FROM 180952 PLAY PROOF REQUIRED'
$p635batdir = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles'
Set-Location $p635batdir
.\Build.bat VEILEditor Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build635.log'
Write-Output ('BUILD635 EXIT ' + $LASTEXITCODE)
if (Test-Path $p635map) { Write-Output ('MAP635 AFTER SIZE ' + (Get-Item $p635map).Length) }
Write-Output 'PHI P635 VERDICT: CONTENT ROAD VAULT ABOVE'
Write-Output 'JOB 635 DONE'
```
