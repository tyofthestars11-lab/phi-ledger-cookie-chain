<!-- PHI-DIRECT -->
# JOB 041 - STARFIELD MANUAL-DEPLOY INVENTORY (DIRECT, read only)

Tyree's screen (photo, 2026-10-26 21:56 MDT) is the state: "No mods
currently deployed", "You need to select a deployment method in
settings" x2, and the selector lives on the Game settings page, which
fails to render - the GUI road is closed. Deployment will run direct:
staging -> Data, plugin list matched, authored from reads, not maps.

This job inventories exactly what a direct deployment must carry:
1. Every folder in staging (%APPDATA%\Vortex\starfield\mods) with its
   file count and the Data-relative file list (first 30 per mod),
   flagging plugin files (.esm/.esp/.esl) and .ba2 archives.
2. The current Plugins.txt (AppData\Local\Starfield) in full.
3. The current ContentCatalog.txt header (first 20 lines).
4. Data folder file count now (baseline for post-deploy verify).

## STEP 1 - STAGING + PLUGIN STATE INVENTORY
```powershell
$staging = "$env:APPDATA\Vortex\starfield\mods"
"STAGING MOD FOLDERS:"
Get-ChildItem $staging -Directory -ErrorAction SilentlyContinue | ForEach-Object {
  $files = Get-ChildItem $_.FullName -Recurse -File -ErrorAction SilentlyContinue
  $plugins = $files | Where-Object { $_.Extension -in '.esm','.esp','.esl' } | ForEach-Object { $_.Name }
  "MOD: $($_.Name) - $($files.Count) files - plugins: $($plugins -join ', ')"
}
"PLUGINS.TXT NOW:"
$pt = "$env:LOCALAPPDATA\Starfield\Plugins.txt"
if (Test-Path $pt) { Get-Content $pt } else { "ABSENT at $pt" }
$pt2 = "$env:APPDATA\..\Local\Packages\BethesdaSoftworks.ProjectGold_3275kfvn8vcwc\LocalState\Plugins.txt"
"DATA FILES NOW: " + (Get-ChildItem 'D:\XboxGames\Starfield\Content\Data' -File -ErrorAction SilentlyContinue).Count
```
