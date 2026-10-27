<!-- PHI-DIRECT -->
# JOB 047 - RESTORE PLUGIN LIST + TRUE STORE INVENTORY + VEIL DLL READ (DIRECT)

Job 045's own verify told the truth: all 14 target mods read MISSING in
staging at 22:10 MDT (job 041 had read them present at ~21:5x - the
store changed between the reads, during the Vortex purge attempts),
nothing carried, and the 8-plugin list it wrote names plugins that are
not in Data. First move: restore Plugins.txt from 045's own backup,
returning the game to its exact pre-deploy state. Then read the TRUE
current store so the re-deploy authors from what exists now: staging
as it stands, and the downloads archives (the mods' source form).
Last: the VEIL DLL check - build4 was running at 044's read.

## STEP 1 - RESTORE + INVENTORY + DLL READ
```powershell
$bk = 'C:\Users\Admin\phi-vault-backups\pre-deploy-2026-10-26\Plugins.txt.before'
$pt = "$env:LOCALAPPDATA\Starfield\Plugins.txt"
if (Test-Path $bk) { Copy-Item $bk $pt -Force; "PLUGINS.TXT RESTORED: $((Get-Item $pt).Length) bytes (pre-deploy state)" } else { "BACKUP MISSING - Plugins.txt left as-is" }
"STAGING NOW:"
$s = "$env:APPDATA\Vortex\starfield\mods"
if (Test-Path $s) { $d = Get-ChildItem $s -Directory; "staging folders: $($d.Count)"; $d | ForEach-Object { $_.Name } } else { "STAGING PATH ABSENT" }
"DOWNLOADS (starfield):"
$dl = "$env:APPDATA\Vortex\downloads\starfield"
if (Test-Path $dl) { $f = Get-ChildItem $dl -File; "archives: $($f.Count)"; $f | ForEach-Object { "$($_.Name) - $([math]::Round($_.Length/1MB,1)) MB" } } else { "DOWNLOADS PATH ABSENT at $dl" }
"DATA FILES NOW: $((Get-ChildItem 'D:\XboxGames\Starfield\Content\Data' -Recurse -File).Count)"
$dll = 'D:\VEIL\Binaries\Win64\UnrealEditor-VEIL.dll'
"VEIL DLL EXISTS: $(Test-Path $dll)"
if (Test-Path $dll) { $i = Get-Item $dll; "DLL: $($i.Length) bytes, written $($i.LastWriteTime)" }
"BUILD PROCESSES RUNNING: $(@(Get-Process -Name dotnet -ErrorAction SilentlyContinue).Count)"
if (Test-Path 'D:\VEIL\build4-out.log') { "BUILD4 TAIL:"; Get-Content 'D:\VEIL\build4-out.log' -Tail 12 }
```
