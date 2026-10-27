<!-- PHI-DIRECT -->
# JOB 089 - CONTENT TREES: MANNEQUINS + PARAGON + ENVIRONMENT (DIRECT)

Job 082's inventory settled it: the feature packs are pointers
(manifest + previews, no Content). The real free content sits in
loose trees: TemplateResources Mannequins (SKM_Manny_Simple,
SKM_Quinn_Simple, SK_Mannequin, ABP_Unarmed + variant ABPs +
weapons) and the VaultCache (ParagonMinions 4.76 GB, SickaEnv
3.13 GB environment, ParagonGreystone 2.11 GB). This job copies
TREES WHOLE (never single files - reference graphs break silently)
into the projects and reports the in-project /Game paths verbatim.

```powershell
$ErrorActionPreference = 'Continue'
$tr = 'C:\Program Files\Epic Games\UE_5.8\Templates\TemplateResources\High\Characters\Content\Mannequins'
robocopy $tr 'D:\VEIL\Content\Mannequins' /E /NFL /NDL /NJH | Out-Null
robocopy $tr 'D:\OMNI-UE\Content\Mannequins' /E /NFL /NDL /NJH | Out-Null
"MANNEQUINS TREE -> VEIL + OMNI Content\Mannequins"
$vc = 'C:\ProgramData\Epic\EpicGamesLauncher\VaultCache'
robocopy "$vc\ParagonMinions\data\Content\ParagonMinions" 'D:\VEIL\Content\ParagonMinions' /E /NFL /NDL /NJH | Out-Null
"PARAGON MINIONS TREE -> VEIL Content\ParagonMinions"
robocopy "$vc\ParagonGreystone\data\Content" 'D:\VEIL\Content' /E /NFL /NDL /NJH | Out-Null
"PARAGON GREYSTONE CONTENT -> VEIL Content"
$sicka = Get-ChildItem $vc -Directory | Where-Object { $_.Name -like 'SickaEnv*' } | Select-Object -First 1
if ($sicka) { robocopy "$($sicka.FullName)\data\Content" 'D:\VEIL\Content' /E /NFL /NDL /NJH | Out-Null; "SICKA ENVIRONMENT CONTENT -> VEIL Content" }
"=== IN-PROJECT VERBATIM PATHS (/Game/...) ==="
foreach ($root in 'D:\VEIL\Content','D:\OMNI-UE\Content') {
  $proj = if ($root -like '*OMNI*') { 'OMNI' } else { 'VEIL' }
  Get-ChildItem $root -Recurse -Include 'SKM_*.uasset','SK_*.uasset','ABP_*.uasset' -ErrorAction SilentlyContinue | ForEach-Object { "BODY[$proj]: /Game/" + $_.FullName.Substring($root.Length + 1).Replace('\','/').Replace('.uasset','') }
  Get-ChildItem $root -Recurse -Include 'M_*.uasset','MI_*.uasset' -ErrorAction SilentlyContinue | Select-Object -First 30 | ForEach-Object { "MAT[$proj]: /Game/" + $_.FullName.Substring($root.Length + 1).Replace('\','/').Replace('.uasset','') }
}
"=== CONTENT SIZE NOW ==="
foreach ($root in 'D:\VEIL\Content','D:\OMNI-UE\Content') { $sz = (Get-ChildItem $root -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; "{0} = {1:N2} GB" -f $root, ($sz/1GB) }
"=== JOB 089 DONE ==="
```
