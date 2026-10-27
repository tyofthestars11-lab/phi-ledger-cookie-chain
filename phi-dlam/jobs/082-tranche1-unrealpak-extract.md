<!-- PHI-DIRECT -->
# JOB 082 - TRANCHE 1 REDO: UNREALPAK EXTRACTION + VAULT INVENTORY (DIRECT)

Job 075's read: the feature packs are on this install, but its
extraction used PowerShell's zip reader on .upack files - a .upack is
an Unreal pak, not a zip ("End of Central Directory record could not
be found"), so nothing landed. And StarterContent.upack is NOT
PRESENT on this 5.8 install. This job uses the right tool -
UnrealPak.exe - extracts TP_ThirdPerson + TP_ThirdPersonBP, copies
the Content trees whole into BOTH projects, inventories the
TemplateResources fallback tree (Door 1b) and the Epic VaultCache
(19.5 GB of free assets already downloaded: Paragon characters,
FabLibrary items), and reports every body/material path verbatim.

```powershell
$ErrorActionPreference = 'Continue'
$up = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealPak.exe'
$fp = 'C:\Program Files\Epic Games\UE_5.8\FeaturePacks'
foreach ($pack in 'TP_ThirdPerson','TP_ThirdPersonBP') {
  $stage = "D:\packstage-$pack"
  & $up "$fp\$pack.upack" -Extract $stage
  "EXTRACTED $pack -> $stage"
  if (Test-Path "$stage\Content") {
    robocopy "$stage\Content" 'D:\VEIL\Content' /E /NFL /NDL /NJH | Out-Null
    robocopy "$stage\Content" 'D:\OMNI-UE\Content' /E /NFL /NDL /NJH | Out-Null
    "COPIED $pack Content -> VEIL + OMNI"
  } else { "NO Content TREE IN $pack"; Get-ChildItem $stage -Recurse -Directory -ErrorAction SilentlyContinue | Select-Object -First 10 | ForEach-Object { $_.FullName } }
}
"=== DOOR 1B: TEMPLATERESOURCES CHARACTER ASSETS ==="
$tr = 'C:\Program Files\Epic Games\UE_5.8\Templates\TemplateResources'
if (Test-Path $tr) { Get-ChildItem $tr -Recurse -Include 'SKM_*.uasset','SK_*.uasset','ABP_*.uasset' -ErrorAction SilentlyContinue | ForEach-Object { "TEMPLATE: $($_.FullName)" } } else { "NO TemplateResources" }
"=== VAULTCACHE: FREE AAA ALREADY ON THIS DISK ==="
Get-ChildItem 'C:\ProgramData\Epic\EpicGamesLauncher\VaultCache' -Directory -ErrorAction SilentlyContinue | ForEach-Object {
  $sz = (Get-ChildItem $_.FullName -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
  "{0} = {1:N2} GB" -f $_.Name, ($sz/1GB)
  Get-ChildItem $_.FullName -Recurse -Include 'SK_*.uasset','SKM_*.uasset' -ErrorAction SilentlyContinue | Select-Object -First 4 | ForEach-Object { "  BODY: $($_.FullName)" }
}
"=== VERBATIM PATHS NOW IN VEIL Content ==="
Get-ChildItem 'D:\VEIL\Content' -Recurse -Include 'SKM_*.uasset','SK_*.uasset','ABP_*.uasset' -ErrorAction SilentlyContinue | ForEach-Object { "BODY: $($_.FullName)" }
Get-ChildItem 'D:\VEIL\Content' -Recurse -Include 'M_*.uasset','MI_*.uasset' -ErrorAction SilentlyContinue | Select-Object -First 40 | ForEach-Object { "MAT: $($_.FullName)" }
"=== JOB 082 DONE ==="
```
