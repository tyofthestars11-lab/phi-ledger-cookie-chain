<!-- PHI-DIRECT -->
```powershell
Write-Output '=== ADDON AND ASSET GROUND CENSUS 446 - WHAT STANDS IN THE PROJECT BEFORE THE RENDER TRANCHES (Ground from Tyree hands and screen, 2026-10-28: the controller works and the world he enters reads as bare shapes, a dark pillar, a sphere, white template mountains, plain ground. His word: render the world and actors, add all necessary addons, and the free store for Unreal, whose name is Fab. Ground from the standing code: the default map is VEILDistrict, a placed world, and on placed worlds the runtime builder stands down by its own rule, so the entered world is the template stage itself; the project already carries real packs beside the primitives, ParagonCountess for the runner body and a Polyart tree that holds the input assets, and job 313 enabled the editor toolsets, MCP and PCG among them. This census measures the ground the render tranches will be authored from. One, it prints the uproject plugin list whole, every enabled addon by name. Two, it censuses Content by top folder: file counts and total bytes per folder, capped at 40 folders, so the standing packs stand measured. Three, it censuses the Polyart tree one level down the same way, capped at 40. Four, it checks the Epic Games Launcher and Fab presence on the PC by their standing folders, names only. Five, the verdict in one line: ADDON ASSET CENSUS with the plugin count and the content folder count. This job is read only and every variable carries the ag446 prefix.) ==='
$ag446root = 'D:\VEIL-OMNI'
$ag446uproj = Join-Path $ag446root 'VEIL.uproject'
$ag446plugCount = 0
if (Test-Path $ag446uproj) {
  $ag446raw = Get-Content $ag446uproj -Raw
  $ag446names = [regex]::Matches($ag446raw, '"Name"\s*:\s*"([^"]+)"')
  foreach ($ag446m in $ag446names) { Write-Output ('PLUGIN ' + $ag446m.Groups[1].Value); $ag446plugCount += 1 }
}
Write-Output ('PLUGIN NAMES=' + $ag446plugCount)
$ag446content = Join-Path $ag446root 'Content'
$ag446folders = @()
if (Test-Path $ag446content) {
  $ag446tops = @(Get-ChildItem $ag446content -Directory -ErrorAction SilentlyContinue)
  foreach ($ag446t in $ag446tops) {
    $ag446files = @(Get-ChildItem $ag446t.FullName -Recurse -File -ErrorAction SilentlyContinue)
    $ag446bytes = 0; foreach ($ag446f in $ag446files) { $ag446bytes += $ag446f.Length }
    $ag446folders += $ag446t.Name
    Write-Output ('CONTENT ' + $ag446t.Name + ' files=' + $ag446files.Count + ' bytes=' + $ag446bytes)
  }
  $ag446rootFiles = @(Get-ChildItem $ag446content -File -ErrorAction SilentlyContinue)
  Write-Output ('CONTENT ROOT FILES=' + $ag446rootFiles.Count)
}
$ag446poly = Join-Path $ag446content 'Polyart'
if (Test-Path $ag446poly) {
  $ag446subs = @(Get-ChildItem $ag446poly -Directory -Recurse -Depth 2 -ErrorAction SilentlyContinue)
  $ag446subs | Select-Object -First 40 | ForEach-Object { Write-Output ('POLYART ' + $_.FullName.Substring($ag446poly.Length)) }
} else { Write-Output 'POLYART: absent at Content root' }
$ag446launcher = @(Get-ChildItem 'C:\Program Files\Epic Games' -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -like 'Launch*' }).Count -gt 0
$ag446fab = Test-Path (Join-Path $ag446root 'Plugins')
Write-Output ('LAUNCHER STANDS=' + $ag446launcher + ' PROJECT PLUGINS FOLDER=' + $ag446fab)
if (Test-Path (Join-Path $ag446root 'Plugins')) { Get-ChildItem (Join-Path $ag446root 'Plugins') -Directory -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('PROJ PLUGIN ' + $_.Name) } }
Write-Output ('PHI AG446 VERDICT: ADDON ASSET CENSUS plugins=' + $ag446plugCount + ' content_folders=' + $ag446folders.Count)
Write-Output 'JOB 446 DONE'
```
