<!-- PHI-DIRECT -->
# JOB 075 - FEATURE PACK INVENTORY + EXTRACTION INTO VEIL (DIRECT)

Tyree's verdict on the standing build: "This isn't a game." Correct -
the systems are real (his own screenshot's log: WORLD BUILT, input
map active) but the world wears debug materials: BasicShapeMaterial
carries a grid texture, so towers render as dark boxes and the plaza
as tan checker, and the hero is a cylinder. A real game needs real
content. Unreal ships feature packs with the engine - the ThirdPerson
pack (Mannequin character + animations) and StarterContent (real
surface materials/textures). This job inventories the packs on this
install and extracts what exists into D:\VEIL\Content, then reports
the exact asset paths so the wiring is written from evidence.

```powershell
$fp = 'C:\Program Files\Epic Games\UE_5.8\FeaturePacks'
"=== FEATURE PACKS ON THIS INSTALL ==="
Get-ChildItem $fp -Filter '*.upack' -ErrorAction SilentlyContinue | ForEach-Object { "$($_.Name) ($([math]::Round($_.Length/1MB,1)) MB)" }
"=== EXTRACT ==="
foreach ($name in 'TP_ThirdPerson.upack','TP_ThirdPersonBP.upack','StarterContent.upack') {
  $src = Join-Path $fp $name
  if (Test-Path $src) {
    $stage = "D:\pack-$($name -replace '\.upack','')"
    Remove-Item $stage -Recurse -Force -ErrorAction SilentlyContinue
    Copy-Item $src "$stage.zip" -Force
    Expand-Archive "$stage.zip" -DestinationPath $stage -Force
    "EXTRACTED $name -> $stage"
    Get-ChildItem $stage -Directory | ForEach-Object { "  root: $($_.Name)" }
    $content = Get-ChildItem $stage -Recurse -Directory -Filter 'Content' | Select-Object -First 1
    if ($content) {
      robocopy $content.FullName 'D:\VEIL\Content' /E /NFL /NDL /NJH | Out-Null
      "COPIED into D:\VEIL\Content from $name"
    }
  } else { "NOT PRESENT: $name" }
}
"=== MANNEQUIN / CHARACTER ASSETS NOW IN VEIL ==="
Get-ChildItem 'D:\VEIL\Content' -Recurse -ErrorAction SilentlyContinue | Where-Object { $_.Name -match 'SKM_|SK_|Manny|Quinn|ABP_' } | Select-Object -First 25 | ForEach-Object { $_.FullName.Replace('D:\VEIL\Content\','') }
"=== SURFACE MATERIALS NOW IN VEIL (first 30) ==="
Get-ChildItem 'D:\VEIL\Content' -Recurse -Filter 'M_*.uasset' -ErrorAction SilentlyContinue | Select-Object -First 30 | ForEach-Object { $_.FullName.Replace('D:\VEIL\Content\','') }
"=== JOB 075 DONE ==="
```
