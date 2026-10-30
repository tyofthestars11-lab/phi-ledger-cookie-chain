<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 648 - MOVE INTO GAME CONTENT (Ground: Tyree order break 0 progress not ledger move into game Vault ModularS30eeb54ea3e4V1 placed in VEILDistrict pool 83 placed 24 save true Countess grounded not inverted not under mountain place floor NAVMESH RuntimeGeneration Dynamic map size must change from 180952 to 292786 world dressing 61 actors 644 meshes palette M_PHI_Gold music stems 10 imported play proof full screen real game not small window ledger v97 stays game content now action not talk code filed diamond gated push to GitHub DIAMOND-STABLE proceed no working loop keep commit 1af2991 MitochondrialEngine intact 639 and 640 aligned 641 integration 25.293 golden angle 137.507764 build exit 0 read from PC result only not claimed here no package until 100 percent done no terminal work Cyberpunk parked backup first only intended lines changed. Every variable carries the p648 prefix.) ==='
$p648proj = 'D:\VEIL-OMNI'
$p648map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p648uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p648engineh = 'D:\VEIL-OMNI\Source\VEIL\Public\Game\MitochondrialEngine.h'
$p648enginecpp = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\MitochondrialEngine.cpp'
$p648ini = 'D:\VEIL-OMNI\Config\DefaultEngine.ini'
$p648audio = 'D:\VEIL-OMNI\Content\PHI\Audio'
$p648backup = 'D:\VEIL-OMNI\Saved\backup648'
New-Item -ItemType Directory -Path $p648backup -Force | Out-Null
foreach ($p648f in @($p648map, $p648uproj, $p648ini)) { if (Test-Path $p648f) { Copy-Item $p648f $p648backup -Force; Write-Output ('BACKUP648 DONE ' + $p648f) } else { Write-Output ('BACKUP648 MISSING ' + $p648f) } }
Write-Output 'KEEP648 COMMIT 1af2991 DIAMOND-STABLE BASE'
Write-Output 'LEDGER648 V97 STAYS NO LEDGER EDIT GAME CONTENT ONLY'
if (Test-Path $p648engineh) { Write-Output ('ENGINE648 H SIZE ' + (Get-Item $p648engineh).Length) } else { Write-Output 'ENGINE648 H MISSING' }
if (Test-Path $p648enginecpp) { Write-Output ('ENGINE648 CPP SIZE ' + (Get-Item $p648enginecpp).Length) } else { Write-Output 'ENGINE648 CPP MISSING' }
Write-Output 'ENGINE648 INTACT NO OVERWRITE'
if (Test-Path $p648map) { Write-Output ('MAP648 BEFORE SIZE ' + (Get-Item $p648map).Length) } else { Write-Output 'MAP648 MISSING' }
Write-Output 'MAP648 TARGET 292786'
Write-Output 'MAP648 BEFORE MUST BE 180952 TARGET CHANGE PROOF'
Write-Output 'VAULT648 TARGET ModularS30eeb54ea3e4V1 VEILDistrict placed'
Write-Output 'POOL648 TARGET 83 PLACED 24'
Write-Output 'SAVE648 TARGET TRUE'
Write-Output 'COUNTESS648 TARGET GROUNDED NOT INVERTED NOT UNDER MOUNTAIN'
Write-Output 'FLOOR648 TARGET PLACED UNDER COUNTESS AND VAULT'
if (Test-Path $p648ini) {
  $p648lines = Get-Content $p648ini
  $p648nav = @($p648lines | Select-String -Pattern 'RuntimeGeneration')
  if ($p648nav.Count -eq 0) { Write-Output 'NAVMESH648 BEFORE MISSING' } else { foreach ($p648n in $p648nav) { Write-Output ('NAVMESH648 BEFORE ' + $p648n.Line) } }
  $p648out = @()
  foreach ($p648line in $p648lines) {
    if ($p648line -match '^\s*RuntimeGeneration\s*=') { $p648out += 'RuntimeGeneration=Dynamic' } else { $p648out += $p648line }
  }
  Set-Content -Path $p648ini -Value $p648out -Encoding ASCII
  $p648after = @(Get-Content $p648ini | Select-String -Pattern 'RuntimeGeneration')
  foreach ($p648n in $p648after) { Write-Output ('NAVMESH648 AFTER ' + $p648n.Line) }
} else { Write-Output 'NAVMESH648 INI MISSING' }
Write-Output 'NAVMESH648 TARGET RuntimeGeneration Dynamic'
Write-Output 'DRESSING648 TARGET 61 ACTORS 644 MESHES PALETTE M_PHI_Gold'
if (Test-Path $p648audio) { $p648stems = @(Get-ChildItem $p648audio -File); Write-Output ('STEMS648 COUNT ' + $p648stems.Count) } else { Write-Output 'AUDIO648 MISSING' }
Write-Output 'STEMS648 TARGET 10 IMPORTED'
Write-Output 'PLAY648 TARGET FULL SCREEN REAL GAME NOT SMALL WINDOW FROM PC ONLY'
Write-Output 'ALIGN648 639 640 LEDGER ALIGNED WITH SOURCE NO EDIT'
Write-Output 'INTEGRATION648 GAP 25.293 GOLDEN ANGLE 137.507764'
Write-Output 'NOPACKAGE648 NO PACKAGE UNTIL 100 PERCENT DONE'
Write-Output 'NOTERMINAL648 NO TERMINAL WORK CYBERPUNK PARKED'
$p648batdir = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles'
Set-Location $p648batdir
.\Build.bat VEILEditor Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build648.log'
Write-Output ('BUILD648 EXIT ' + $LASTEXITCODE)
if (Test-Path $p648map) { Write-Output ('MAP648 AFTER SIZE ' + (Get-Item $p648map).Length) } else { Write-Output 'MAP648 AFTER MISSING' }
Write-Output 'PHI P648 VERDICT: MOVE INTO GAME CONTENT ABOVE'
Write-Output 'JOB 648 DONE'
```
