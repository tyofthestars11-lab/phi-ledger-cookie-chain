<!-- PHI-DIRECT -->
# JOB 045 - STARFIELD DIRECT DEPLOY (DIRECT, guarded, self-verifying)

Tyree's word: deploy all of it, correctly, for Starfield - direct,
because Vortex's registry lives in a LevelDB store its own GUI can't
repair (purge blocked: "solve any setup problems first"; settings page
fails to render). Job 041 inventoried staging on disk: 18 mod folders
intact. This job carries them the way Vortex deployment would - staged
contents copied into the game's Data, preserving layout - and writes
the plugin list to match.

SKIPPED BY PLATFORM (SFSE has no seat on the Game Pass build; their
files stay in staging): DiskCacheEnabler-SFSE, FTTU_SFSE,
Weapon-Power-Mod-SFSE.
SPECIAL: the ASI Loader's dll goes to the game Content root (beside
Starfield.exe), not Data.
GUARDS: stops if Starfield is running. Backs up Plugins.txt and a
pre-deploy Data listing first. Nothing is deleted anywhere.

## STEP 1 - GUARDED CARRY + PLUGIN LIST + VERIFY
```powershell
if (Get-Process -Name Starfield -ErrorAction SilentlyContinue) { "GUARD STOP: Starfield is running - no deploy under a live game."; return }
$staging = "$env:APPDATA\Vortex\starfield\mods"
$data = 'D:\XboxGames\Starfield\Content\Data'
$content = 'D:\XboxGames\Starfield\Content'
$bk = 'C:\Users\Admin\phi-vault-backups\pre-deploy-2026-10-26'
New-Item -ItemType Directory -Path $bk -Force | Out-Null
$pt = "$env:LOCALAPPDATA\Starfield\Plugins.txt"
if (Test-Path $pt) { Copy-Item $pt "$bk\Plugins.txt.before" -Force; "PLUGINS BACKED UP: $((Get-Item $pt).Length) bytes" }
(Get-ChildItem $data -Recurse -File | ForEach-Object { $_.FullName.Substring($data.Length) }) | Set-Content "$bk\data-listing-before.txt"
"DATA FILES BEFORE: $((Get-ChildItem $data -Recurse -File).Count)"
$mods = @(
 'All In One (For all) 1v8-290-1v8-1724258825',
 'EXE V0.7-340-0-7-1697120543',
 'Gergel Ebanex 1.3.1 for SAF 14425 1.3.1 2026-08-23T19-01Z XWUnshBNp',
 'Improved Combat AI-1392-1-4-1777419381',
 'More Ownable Ships-791-1-3-1701681185',
 'No More Temple Puzzles-4570-1-0-1-1696351077',
 'SETI v0.3.1-11480-0-3-1-1728673629',
 'Sit to Add Ship to Fleet-6493-0-2-5-1776532555',
 'SnuSnuField 13329 7.1.2 2026-07-30T16-39Z Siqx4gHh6',
 'Sprint Stuttering Fix-884-1-0-6-1750021820',
 'Starfield Community Patch-1-1-0-0-1727729773',
 'StarUI Workbench 4966 1.3.1 2026-09-10T00-52Z qd5Tg9FpV',
 'Undelayed Menu - Latest Version-404-1-0-6-1724715645',
 "X2357's AISS - AI Settled Systems 17392 3.77 2026-10-08T21-37Z oc1PyZMxY"
)
foreach ($m in $mods) {
  $src = Join-Path $staging $m
  if (Test-Path $src) { robocopy $src $data /E /NFL /NDL /NJH /NJS | Out-Null; "CARRIED: $m" } else { "MISSING IN STAGING: $m" }
}
$loader = Join-Path $staging 'Ultimate-ASI-Loader-NoPDB_x64'
if (Test-Path $loader) {
  Get-ChildItem $loader -File | ForEach-Object {
    if ($_.Extension -eq '.dll') { Copy-Item $_.FullName (Join-Path $content $_.Name) -Force; "LOADER TO CONTENT ROOT: $($_.Name)" }
    else { Copy-Item $_.FullName (Join-Path $data $_.Name) -Force; "LOADER FILE TO DATA: $($_.Name)" }
  }
}
$plugins = @('StarfieldCommunityPatch.esm','GergelEbanex.esm','Improved Combat AI.esm','MoreOwnableShips.esm','SETI_ShipLights_by_BosDragon.esm','Sit To Add Ship.esm','SnuSnuField.esm','x2357aiss.esm')
$plugins | Set-Content $pt -Encoding ASCII
"PLUGINS.TXT WRITTEN: $($plugins.Count) plugins"
"DATA FILES AFTER: $((Get-ChildItem $data -Recurse -File).Count)"
"PLUGIN FILES IN DATA:"
foreach ($p in $plugins) { "$p : $(Test-Path (Join-Path $data $p))" }
```
