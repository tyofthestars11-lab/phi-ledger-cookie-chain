<!-- PHI-DIRECT -->
# JOB 076 - THE R1 100 GB INVENTORY (DIRECT, READ-ONLY)

Tyree: R1's work "should be around 100 GB already" - yet the game on
screen looks like 0 GB. Find where the mass actually sits: every
Unreal project on the machine, the Epic VaultCache / Fab caches,
sample games, Megascans - paths and sizes, verbatim. Nothing moves,
nothing deletes, nothing launches.

```powershell
"=== ALL .uproject FILES (D: and C:\Users) ==="
Get-ChildItem 'D:\' -Recurse -Filter '*.uproject' -Depth 4 -ErrorAction SilentlyContinue | ForEach-Object { $_.FullName }
Get-ChildItem 'C:\Users\Admin' -Recurse -Filter '*.uproject' -Depth 4 -ErrorAction SilentlyContinue | ForEach-Object { $_.FullName }
"=== TOP-LEVEL SIZES ON D: ==="
Get-ChildItem 'D:\' -Directory -ErrorAction SilentlyContinue | ForEach-Object {
  $sum = (Get-ChildItem $_.FullName -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
  "{0} = {1} GB" -f $_.Name, [math]::Round($sum/1GB, 2)
}
"=== EPIC CACHES ==="
foreach ($d in 'C:\ProgramData\Epic\EpicGamesLauncher\VaultCache', "$env:LOCALAPPDATA\EpicGamesLauncher", "$env:LOCALAPPDATA\Fab", 'D:\Fab', 'D:\Megascans', "$env:USERPROFILE\Documents\Megascans", "$env:USERPROFILE\Documents\Unreal Projects") {
  if (Test-Path $d) {
    $sum = (Get-ChildItem $d -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
    "$d = $([math]::Round($sum/1GB,2)) GB"
    Get-ChildItem $d -Directory -ErrorAction SilentlyContinue | Select-Object -First 15 | ForEach-Object { "  $($_.Name)" }
  } else { "ABSENT: $d" }
}
"=== BIG FILES IN DOWNLOADS (>500 MB) ==="
Get-ChildItem "$env:USERPROFILE\Downloads" -File -ErrorAction SilentlyContinue | Where-Object { $_.Length -gt 500MB } | ForEach-Object { "$($_.Name) = $([math]::Round($_.Length/1GB,2)) GB" }
"=== JOB 076 DONE ==="
```
