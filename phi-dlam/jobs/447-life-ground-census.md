<!-- PHI-DIRECT -->
```powershell
Write-Output '=== LIFE GROUND CENSUS 447 - THE PACKS, THE BUILDER INSTRUMENTS, AND THE SESSION EXIT, READ BEFORE THE LIFE TRANCHES (Ground: job 446 censused the project whole and the packs stand rich: Iceland Environment 82 files, Sicka EnvPack2 593 files, LavaMat 46, and four Paragon bodies with their animations, Greystone, Murdock, Revenant, Minions, beside Countess, yet the entered world still renders primitives because nothing seats the packs into the entered map. Tyree word whole: render the world and actors, add all necessary addons, we need immersion, the world must come to life, add DNA, like the universe is alive, not cold and still. The life tranches author from printed ground only, so this census prints three sections. One, the asset paths: skeletal meshes and animation blueprints under the four Paragon packs, capped at 60 lines, and static meshes under Sicka and Iceland, capped at 60, every path a full Content path the seating code can load. Two, the builder instruments: the SpawnBlock signature line from VEILWorldBuilder cpp, every mesh and material LoadObject literal in that file capped at 30, and the GameMode lines where the quest statues and givers are spawned, capped at 30, so the DNA helix and the actor seating are authored against the standing spawn shape. Three, the session exit: the whole VEIL log grepped for exit and pause lines capped at 25, and the tail of the smoke443 log capped at 30, because job 445 found the newest project log ending in a clean exit and no fatal record, and the Start press outcome must be named from the record whole. The verdict in one line: LIFE CENSUS with the paragon path count, the env path count, and whether an exit line stands. This job is read only and every variable carries the lc447 prefix.) ==='
$lc447root = 'D:\VEIL-OMNI'
$lc447content = Join-Path $lc447root 'Content'
$lc447par = 0
foreach ($lc447pack in @('ParagonGreystone', 'ParagonMurdock', 'ParagonRevenant', 'ParagonMinions')) {
  $lc447dir = Join-Path $lc447content $lc447pack
  if (Test-Path $lc447dir) {
    $lc447hits = @(Get-ChildItem $lc447dir -Recurse -File -ErrorAction SilentlyContinue | Where-Object { $_.Name -match 'SK_|_Anim|AnimBP|_ABP' } | Select-Object -First 15)
    foreach ($lc447h in $lc447hits) { Write-Output ('PARAGON ' + $lc447pack + ' ' + $lc447h.FullName.Substring($lc447content.Length)); $lc447par += 1 }
  }
}
$lc447env = 0
foreach ($lc447pack in @('Sicka_EnvPack2', 'Iceland_Environment')) {
  $lc447dir = Join-Path $lc447content $lc447pack
  if (Test-Path $lc447dir) {
    $lc447hits = @(Get-ChildItem $lc447dir -Recurse -File -Filter '*.uasset' -ErrorAction SilentlyContinue | Select-Object -First 30)
    foreach ($lc447h in $lc447hits) { Write-Output ('ENV ' + $lc447pack + ' ' + $lc447h.FullName.Substring($lc447content.Length)); $lc447env += 1 }
  }
}
$lc447bld = Join-Path $lc447root 'Source\VEIL\VEILWorldBuilder.cpp'
if (Test-Path $lc447bld) {
  $lc447sig = @(Select-String -Path $lc447bld -Pattern 'SpawnBlock\(' -ErrorAction SilentlyContinue | Select-Object -First 3)
  foreach ($lc447s in $lc447sig) { Write-Output ('SIG ' + $lc447s.Line.Trim()) }
  $lc447loads = @(Select-String -Path $lc447bld -Pattern 'LoadObject|FObjectFinder|/Game/|/Engine/' -ErrorAction SilentlyContinue | Select-Object -First 30)
  foreach ($lc447l in $lc447loads) { Write-Output ('LOAD ' + $lc447l.LineNumber.ToString() + ' ' + $lc447l.Line.Trim()) }
}
$lc447gm = Join-Path $lc447root 'Source\VEIL\VEILGameMode.cpp'
if (Test-Path $lc447gm) {
  $lc447spawns = @(Select-String -Path $lc447gm -Pattern 'SpawnActor|Statue|Giver|SpawnStat' -ErrorAction SilentlyContinue | Select-Object -First 30)
  foreach ($lc447s2 in $lc447spawns) { Write-Output ('GMSPAWN ' + $lc447s2.LineNumber.ToString() + ' ' + $lc447s2.Line.Trim()) }
}
$lc447log = Join-Path $lc447root 'Saved\Logs\VEIL.log'
$lc447exit = 0
if (Test-Path $lc447log) {
  $lc447el = @(Select-String -Path $lc447log -Pattern 'RequestExit|QuitGame|ViewportClosed|PHI PAUSE|TogglePause' -ErrorAction SilentlyContinue | Select-Object -First 25)
  foreach ($lc447e in $lc447el) { Write-Output ('EXIT ' + $lc447e.Line.Trim()); $lc447exit += 1 }
}
$lc447smoke = Join-Path $lc447root 'Saved\smoke443.log'
if (Test-Path $lc447smoke) { Write-Output '--- SMOKE443 TAIL ---'; Get-Content $lc447smoke -Tail 30 | ForEach-Object { Write-Output ('SMK ' + $_) } }
Write-Output ('PHI LC447 VERDICT: LIFE CENSUS paragon_paths=' + $lc447par + ' env_paths=' + $lc447env + ' exit_lines=' + $lc447exit)
Write-Output 'JOB 447 DONE'
```
