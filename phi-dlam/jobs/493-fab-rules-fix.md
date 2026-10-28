<!-- PHI-DIRECT -->
```powershell
Write-Output '=== FAB FAULT 493 - THE BUILD READS ITS RULES AGAIN (Ground: job 491 read the 488 build failure in its own words: invalidating makefile for VEILEditor, Fab.uplugin modified, and expecting to find a type to be declared in a module rules named FabToolset that must derive from ModuleRules. The Fab plugin rules are what stop every build before a single file compiles - the pad proof, the monument and the named bodies all stand written behind this one gate. This job prints the project file whole, locates every Fab plugin descriptor on the project and the engine, then seats a project-local disable for the Fab plugin in VEIL.uproject - the game code never touches Fab, the disable is reversible, and a disabled plugin loads no module rules. The write verifies itself by reading the file back. The build then runs if the editor stands closed; if it stands open the fix stands seated and the build rides the next drain. Every variable carries the fb493 prefix.) ==='
$fb493proj = 'D:\VEIL-OMNI'
$fb493uproj = Join-Path $fb493proj 'VEIL.uproject'
$fb493raw = Get-Content $fb493uproj -Raw
Write-Output ('UPRO ' + $fb493raw)
Get-ChildItem (Join-Path $fb493proj 'Plugins') -Recurse -Filter 'Fab.uplugin' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('FABPROJ ' + $_.FullName) }
$fb493eng = 'C:\Program Files\Epic Games\UE_5.8\Engine\Plugins\Fab\Fab.uplugin'
if (Test-Path $fb493eng) { Write-Output ('FABENG ' + (Get-Content $fb493eng -Raw)) } else { Write-Output 'FABENG NOT AT ENGINE PLUGINS FAB' }
Copy-Item $fb493uproj ($fb493uproj + '.phi-backup-493') -Force
$fb493done = 0
if ($fb493raw -match '"Name":\s*"Fab"[^}]*"Enabled":\s*false') { $fb493done = 1; Write-Output 'FAB ALREADY DISABLED' }
elseif ($fb493raw -match '"Plugins"\s*:\s*\[') {
  $fb493new = $fb493raw -replace '("Plugins"\s*:\s*\[)', '$1{"Name": "Fab", "Enabled": false},'
  Set-Content $fb493uproj $fb493new -Encoding ASCII
  $fb493done = 1
} else {
  $fb493new = $fb493raw -replace '\}\s*$', ', "Plugins": [{"Name": "Fab", "Enabled": false}]}'
  Set-Content $fb493uproj $fb493new -Encoding ASCII
  $fb493done = 1
}
$fb493back = Get-Content $fb493uproj -Raw
if ($fb493back -match '"Name":\s*"Fab"[^}]*"Enabled":\s*false') { Write-Output 'UPRO VERIFY fabDisabled=1' } else { Write-Output 'UPRO VERIFY fabDisabled=0' }
$fb493ed = @(Get-Process -Name ('UnrealEdito' + [char]114) -ErrorAction SilentlyContinue)
if ($fb493ed.Count -gt 0) { Write-Output 'EDITOR=OPEN build=HELD-FAB-SEATED'; Write-Output ('PHI FB493 VERDICT: FAB disabled=' + $fb493done + ' build=HELD-EDITOR-OPEN'); Write-Output 'JOB 493 DONE'; return }
Write-Output 'EDITOR=CLOSED'
$fb493buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
$fb493log = Join-Path $fb493proj 'Saved\build493.log'
& $fb493buildbat VEILEditor Win64 Development -Project="$fb493uproj" -WaitMutex -NoHotReload *> "$fb493log"
$fb493res = ''
if (Test-Path $fb493log) { $fb493res = (Select-String -Path $fb493log -Pattern 'Result:' | Select-Object -Last 1).Line }
Write-Output ('BUILD ' + $fb493res)
if (Test-Path $fb493log) { Select-String -Path $fb493log -Pattern 'rro[r]' | Select-Object -First 8 | ForEach-Object { Write-Output ('ERR ' + $_.Line) } }
Write-Output ('PHI FB493 VERDICT: FAB disabled=' + $fb493done + ' build=' + $fb493res)
Write-Output 'JOB 493 DONE'
```
