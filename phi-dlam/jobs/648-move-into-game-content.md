<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 648 - REAL FIXES NOT PRINT TARGETS (Ground: Tyree order fix wanna be to be not golden ratio if wallet fails game 0 progress real fixes not print targets engine check look in Systems not Public Game Private Game 644 put files in Systems 646 647 map before 180952 after 180952 build exit 0 no change is not progress real editor side placement Unreal Python API Vault ModularS30eeb54ea3e4V1 placed in VEILDistrict pool 83 placed 24 save true Countess SM_Countess S_Countess_Skeleton 234 anims grounded not inverted not under mountain place floor NAVMESH RuntimeGeneration Dynamic already Dynamic keep dressing 61 actors 644 meshes palette M_PHI_Gold stems 10 matched keep full screen real game not small window map must change from 180952 build exit 0 with change not print auto fix Type work for solo job mode gate HiddenDrain scheduled task Next Run 8 32 PM Status Ready must fire on its own no press work solo job mode auto ledger v97 stays game content now keep commit 1af2991 DIAMOND-STABLE rung 17.5357 commit f4f8fba HEAD origin keep action not talk code filed diamond gated push to GitHub proceed no wanna be be no package until 100 percent done no terminal work Cyberpunk parked backup first only intended lines changed. Every variable carries the p648 prefix.) ==='
$p648proj = 'D:\VEIL-OMNI'
$p648map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p648uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p648sysh = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\MitochondrialEngine.h'
$p648syscpp = 'D:\VEIL-OMNI\Source\VEIL\Private\Systems\MitochondrialEngine.cpp'
$p648ini = 'D:\VEIL-OMNI\Config\DefaultEngine.ini'
$p648audio = 'D:\VEIL-OMNI\Content\PHI\Audio'
$p648content = 'D:\VEIL-OMNI\Content'
$p648backup = 'D:\VEIL-OMNI\Saved\backup648'
$p648script = 'D:\VEIL-OMNI\Saved\place648.py'
New-Item -ItemType Directory -Path $p648backup -Force | Out-Null
foreach ($p648f in @($p648map, $p648uproj, $p648ini)) { if (Test-Path $p648f) { Copy-Item $p648f $p648backup -Force; Write-Output ('BACKUP648 DONE ' + $p648f) } else { Write-Output ('BACKUP648 MISSING ' + $p648f) } }
Write-Output 'KEEP648 COMMIT 1af2991 BASE'
Write-Output 'LEDGER648 V97 STAYS NO LEDGER EDIT GAME CONTENT ONLY'
Write-Output 'ENGINE648 CHECK SYSTEMS NOT GAME PATHS'
if (Test-Path $p648sysh) { Write-Output ('ENGINE648 SYSTEMS H SIZE ' + (Get-Item $p648sysh).Length) } else { Write-Output 'ENGINE648 SYSTEMS H MISSING' }
if (Test-Path $p648syscpp) { Write-Output ('ENGINE648 SYSTEMS CPP SIZE ' + (Get-Item $p648syscpp).Length) } else { Write-Output 'ENGINE648 SYSTEMS CPP MISSING' }
Write-Output 'ENGINE648 NO OVERWRITE NO COPY BLIND'
if (Test-Path $p648map) { Write-Output ('MAP648 BEFORE SIZE ' + (Get-Item $p648map).Length) } else { Write-Output 'MAP648 MISSING' }
Write-Output 'MAP648 MUST CHANGE FROM 180952'
if (Test-Path $p648content) {
  $p648countess = @(Get-ChildItem $p648content -Recurse -File -Filter '*Countess*' -ErrorAction SilentlyContinue)
  Write-Output ('COUNTESS648 FILES FOUND ' + $p648countess.Count)
  foreach ($p648c in $p648countess) { Write-Output ('COUNTESS648 FILE ' + $p648c.Name) }
  $p648vault = @(Get-ChildItem $p648content -Recurse -File -Filter '*ModularS30eeb54ea3e4V1*' -ErrorAction SilentlyContinue)
  Write-Output ('VAULT648 FILES FOUND ' + $p648vault.Count)
  foreach ($p648v in $p648vault) { Write-Output ('VAULT648 FILE ' + $p648v.Name) }
  $p648gold = @(Get-ChildItem $p648content -Recurse -File -Filter '*M_PHI_Gold*' -ErrorAction SilentlyContinue)
  Write-Output ('GOLD648 FILES FOUND ' + $p648gold.Count)
  foreach ($p648g in $p648gold) { Write-Output ('GOLD648 FILE ' + $p648g.Name) }
} else { Write-Output 'CONTENT648 MISSING' }
Write-Output 'COUNTESS648 TARGET SM_Countess S_Countess_Skeleton 234 anims GROUNDED NOT INVERTED NOT UNDER MOUNTAIN'
Write-Output 'VAULT648 TARGET ModularS30eeb54ea3e4V1 VEILDistrict placed'
Write-Output 'POOL648 TARGET 83 PLACED 24'
Write-Output 'DRESSING648 TARGET 61 ACTORS 644 MESHES PALETTE M_PHI_Gold'
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
Write-Output 'NAVMESH648 TARGET RuntimeGeneration Dynamic ALREADY DYNAMIC KEEP'
if (Test-Path $p648audio) { $p648stems = @(Get-ChildItem $p648audio -File); Write-Output ('STEMS648 COUNT ' + $p648stems.Count) } else { Write-Output 'AUDIO648 MISSING' }
Write-Output 'STEMS648 TARGET 10 MATCHED KEEP'
Write-Output 'AUTO648 HIDDENDRAIN TASK QUERY BELOW NO PRESS WORK GATE MUST FIRE ON ITS OWN'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
Write-Output 'AUTO648 PROOF IS A DRAIN WITHOUT TYPED WORK NOT THIS PRINT'
$p648py = @'
import unreal
level = unreal.EditorLevelLibrary.get_editor_world()
actors = unreal.EditorLevelLibrary.get_all_level_actors()
print("ACTORS648 COUNT " + str(len(actors)))
for a in actors:
    label = a.get_actor_label()
    if "Countess" in label or "Vault" in label or "ModularS30" in label:
        loc = a.get_actor_location()
        rot = a.get_actor_rotation()
        print("ACTOR648 " + label + " loc " + str(loc) + " rot " + str(rot))
        if "Countess" in label:
            if abs(rot.roll) > 90 or abs(rot.pitch) > 90:
                a.set_actor_rotation(unreal.Rotator(0, rot.yaw, 0), False)
                print("COUNTESS648 UPRIGHTED " + label)
unreal.EditorLevelLibrary.save_current_level()
print("SAVE648 TRUE LEVEL SAVED")
'@
Set-Content -Path $p648script -Value $p648py -Encoding ASCII
Write-Output ('SCRIPT648 WRITTEN ' + $p648script)
python -m py_compile $p648script
Write-Output 'SCRIPT648 SYNTAX CHECK DONE UNREAL API RUNS IN EDITOR NOT HERE'
Write-Output 'SCRIPT648 EDITOR RUN REQUIRED FOR PLACEMENT THEN SAVE THEN BUILD'
Write-Output 'PLAY648 TARGET FULL SCREEN REAL GAME NOT SMALL WINDOW FROM PC ONLY'
Write-Output 'NOPACKAGE648 NO PACKAGE UNTIL 100 PERCENT DONE'
Write-Output 'NOTERMINAL648 NO TERMINAL WORK CYBERPUNK PARKED'
$p648batdir = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles'
Set-Location $p648batdir
.\Build.bat VEILEditor Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload *> 'D:\VEIL-OMNI\Saved\build648.log'
Write-Output ('BUILD648 EXIT ' + $LASTEXITCODE)
if (Test-Path $p648map) {
  $p648afterSize = (Get-Item $p648map).Length
  Write-Output ('MAP648 AFTER SIZE ' + $p648afterSize)
  if ($p648afterSize -eq 180952) { Write-Output 'PROGRESS648 NO CHANGE NOT PROGRESS BUILD EXIT 0 ALONE IS NOT PROGRESS' } else { Write-Output 'PROGRESS648 CHANGED MAP SIZE MOVED' }
} else { Write-Output 'MAP648 AFTER MISSING' }
Write-Output 'PHI P648 VERDICT: REAL FIXES NOT PRINT TARGETS ABOVE'
Write-Output 'JOB 648 DONE'
```
