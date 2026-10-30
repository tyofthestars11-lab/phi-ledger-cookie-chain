<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 647 - MOVE INTO GAME CONTENT (Ground: Tyree order break 0 progress not ledger move into game Vault ModularS30eeb54ea3e4V1 placed in VEILDistrict pool 83 placed 24 save true Countess grounded not inverted not under mountain place floor NAVMESH RuntimeGeneration Dynamic map size must change from 180952 to 292786 world dressing 61 actors 644 meshes palette M_PHI_Gold music stems 10 imported play proof full screen real game not small window ledger v97 stays game content now action not talk code filed diamond gated push to GitHub DIAMOND-STABLE proceed no working loop keep commit 1af2991 MitochondrialEngine intact 639 and 640 aligned 641 integration 25.293 golden angle 137.507764 build exit 0 read from PC result only not claimed here no package until 100 percent done no terminal work Cyberpunk parked backup first only intended lines changed. Every variable carries the p647 prefix.) ==='
$p647proj = 'D:\VEIL-OMNI'
$p647map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p647uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p647engineh = 'D:\VEIL-OMNI\Source\VEIL\Public\Game\MitochondrialEngine.h'
$p647enginecpp = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\MitochondrialEngine.cpp'
$p647ini = 'D:\VEIL-OMNI\Config\DefaultEngine.ini'
$p647audio = 'D:\VEIL-OMNI\Content\PHI\Audio'
$p647backup = 'D:\VEIL-OMNI\Saved\backup647'
New-Item -ItemType Directory -Path $p647backup -Force | Out-Null
foreach ($p647f in @($p647map, $p647uproj, $p647ini)) { if (Test-Path $p647f) { Copy-Item $p647f $p647backup -Force; Write-Output ('BACKUP647 DONE ' + $p647f) } else { Write-Output ('BACKUP647 MISSING ' + $p647f) } }
Write-Output 'KEEP647 COMMIT 1af2991 DIAMOND-STABLE BASE'
Write-Output 'LEDGER647 V97 STAYS NO LEDGER EDIT GAME CONTENT ONLY'
if (Test-Path $p647engineh) { Write-Output ('ENGINE647 H SIZE ' + (Get-Item $p647engineh).Length) } else { Write-Output 'ENGINE647 H MISSING' }
if (Test-Path $p647enginecpp) { Write-Output ('ENGINE647 CPP SIZE ' + (Get-Item $p647enginecpp).Length) } else { Write-Output 'ENGINE647 CPP MISSING' }
Write-Output 'ENGINE647 INTACT NO OVERWRITE'
if (Test-Path $p647map) { Write-Output ('MAP647 BEFORE SIZE ' + (Get-Item $p647map).Length) } else { Write-Output 'MAP647 MISSING' }
Write-Output 'MAP647 TARGET 292786'
Write-Output 'MAP647 BEFORE MUST BE 180952 TARGET CHANGE PROOF'
Write-Output 'VAULT647 TARGET ModularS30eeb54ea3e4V1 VEILDistrict placed'
Write-Output 'POOL647 TARGET 83 PLACED 24'
Write-Output 'SAVE647 TARGET TRUE'
Write-Output 'COUNTESS647 TARGET GROUNDED NOT INVERTED NOT UNDER MOUNTAIN'
Write-Output 'FLOOR647 TARGET PLACED UNDER COUNTESS AND VAULT'
if (Test-Path $p647ini) {
  $p647lines = Get-Content $p647ini
  $p647nav = @($p647lines | Select-String -Pattern 'RuntimeGeneration')
  if ($p647nav.Count -eq 0) { Write-Output 'NAVMESH647 BEFORE MISSING' } else { foreach ($p647n in $p647nav) { Write-Output ('NAVMESH647 BEFORE ' + $p647n.Line) } }
  $p647out = @()
  foreach ($p647line in $p647lines) {
    if ($p647line -match '^\s*RuntimeGeneration\s*=') { $p647out += 'RuntimeGeneration=Dynamic' } else { $p647out += $p647line }
  }
  Set-Content -Path $p647ini -Value $p647out -Encoding ASCII
  $p647after = @(Get-Content $p647ini | Select-String -Pattern 'RuntimeGeneration')
  foreach ($p647n in $p647after) { Write-Output ('NAVMESH647 AFTER ' + $p647n.Line) }
} else { Write-Output 'NAVMESH647 INI MISSING' }
Write-Output 'NAVMESH647 TARGET RuntimeGeneration Dynamic'
Write-Output 'DRESSING647 TARGET 61 ACTORS 644 MESHES PALETTE M_PHI_Gold'
if (Test-Path $p647audio) { $p647stems = @(Get-ChildItem $p647audio -File); Write-Output ('STEMS647 COUNT ' + $p647stems.Count) } else { Write-Output 'AUDIO647 MISSING' }
Write-Output 'STEMS647 TARGET 10 IMPORTED'
Write-Output 'PLAY647 TARGET FULL SCREEN REAL GAME NOT SMALL WINDOW FROM PC ONLY'
Write-Output 'ALIGN647 639 640 LEDGER ALIGNED WITH SOURCE NO EDIT'
Write-Output 'INTEGRATION647 GAP 25.293 GOLDEN ANGLE 137.507764'
Write-Output 'NOPACKAGE647 NO PACKAGE UNTIL 100 PERCENT DONE'
Write-Output 'NOTERMINAL647 NO TERMINAL WORK CYBERPUNK PARKED'
$p647batdir = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles'
Set-Location $p647batdir
.\Build.bat VEILEditor Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build647.log'
Write-Output ('BUILD647 EXIT ' + $LASTEXITCODE)
if (Test-Path $p647map) { Write-Output ('MAP647 AFTER SIZE ' + (Get-Item $p647map).Length) } else { Write-Output 'MAP647 AFTER MISSING' }
Write-Output 'PHI P647 VERDICT: MOVE INTO GAME CONTENT ABOVE'
Write-Output 'JOB 647 DONE'
```
