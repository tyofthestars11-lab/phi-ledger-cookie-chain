<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 645 - HIDDEN AUTO DRAIN NO POPUP (Ground: Tyree said Yes hidden auto drain no popup, I guess I have to type it since you are not telling me how to get the ai on my pc to make the game, Ever since you showed the missing seals for real you have failed to get them to actually anchor or the app failed, We had very little progress today That is not good, whole VEIL OMNI, no package until 100 percent done, no terminal work, Cyberpunk parked, jobs 638 to 644 drained after work typed, map size still 180952 target 292786, job 644 build exit 6 restored phase lock files removed, job 644 artifact build exit 0 engine files missing map unchanged, anchors missing 161 balance 31999.997020, phi ledger v88 no bulk sign 50 per batch one approval per batch. Every variable carries the p645 prefix.) ==='
$p645popup = schtasks /query /tn 'PHI-DLAM-AutoWork' /fo list 2>&1
Write-Output 'POPUP645 STATE ABOVE'
Write-Output 'POPUP645 MUST STAY DISABLED NO WINDOW ON SCREEN'
$p645hidden = 'PHI-DLAM-HiddenDrain'
schtasks /create /tn $p645hidden /sc minute /mo 5 /tr 'powershell -WindowStyle Hidden -NoProfile -ExecutionPolicy Bypass -File C:\Users\Admin\phi-vault\phi-dlam\phi-dlam.ps1' /f 2>&1
schtasks /query /tn $p645hidden /fo list 2>&1
Write-Output 'HIDDEN645 TASK ABOVE NO POPUP WINDOW'
$p645map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
if (Test-Path $p645map) { $p645size = (Get-Item $p645map).Length; Write-Output "MAP645 SIZE $p645size" } else { Write-Output 'MAP645 MISSING' }
Write-Output 'MAP645 TARGET 292786'
$p645sys1 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\MitochondrialEngine.h'
$p645sys2 = 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\EndosymbioticPhaseLock.h'
if (Test-Path $p645sys1) { Write-Output 'PHASE645 MITO HEADER PRESENT' } else { Write-Output 'PHASE645 MITO HEADER ABSENT AFTER 644 RESTORE' }
if (Test-Path $p645sys2) { Write-Output 'PHASE645 LOCK HEADER PRESENT' } else { Write-Output 'PHASE645 LOCK HEADER ABSENT AFTER 644 RESTORE' }
Write-Output 'BUILD645 DIAGNOSIS 644 EXIT 6 PHASE LOCK FILES REMOVED BY RESTORE PROJECT CLEAN NO NEW BUILD CLAIMED HERE'
Write-Output 'ANCHOR645 TYREE HAND ONLY SITE V88 PER BATCH 50 MISSING 161'
Write-Output 'PHI P645 VERDICT: HIDDEN AUTO DRAIN NO POPUP ABOVE'
Write-Output 'JOB 645 DONE'
```
