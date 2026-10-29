<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 569 - TXT NOTES VERIFICATION READ (Ground: The read-only TXT supersedes the Python file for jobs 558 559 560, and it carries new notes to verify by reading, so this job prints the actual GameDefaultMap, the Maps folder files with sizes, the PHI Palette material files, and the navmesh mentions in source, no copy, no write, no re-run of 558 559 560. Every variable carries the p569 prefix.) ==='
$p569config = 'D:\VEIL-OMNI\Config'
if (Test-Path $p569config) {
  $p569inis = Get-ChildItem -Path $p569config -Filter '*.ini' -File -ErrorAction SilentlyContinue
  foreach ($p569ini in $p569inis) {
    Write-Output ('CONFIG FILE ' + $p569ini.FullName)
    @(Select-String -Path $p569ini.FullName -Pattern 'GameDefaultMap|EditorStartupMap|GameStateClass' | Select-Object -First 20) | ForEach-Object { Write-Output ('MAP LINE ' + $_.Line.Trim()) }
  }
} else { Write-Output 'NO CONFIG FOLDER FOUND' }
$p569maps = 'D:\VEIL-OMNI\Content\Maps'
if (Test-Path $p569maps) {
  $p569mapfiles = Get-ChildItem -Path $p569maps -File -ErrorAction SilentlyContinue
  foreach ($p569m in $p569mapfiles) { Write-Output ('MAP FILE ' + $p569m.Name + ' BYTES ' + $p569m.Length) }
} else { Write-Output 'NO MAPS FOLDER FOUND' }
$p569palette = 'D:\VEIL-OMNI\Content\PHI\Palette'
if (Test-Path $p569palette) {
  $p569pal = Get-ChildItem -Path $p569palette -File -ErrorAction SilentlyContinue
  foreach ($p569p in $p569pal) { Write-Output ('PALETTE FILE ' + $p569p.Name) }
} else { Write-Output 'NO PALETTE FOLDER FOUND' }
$p569srcroot = 'D:\VEIL-OMNI\Source\VEIL'
if (Test-Path $p569srcroot) {
  @(Get-ChildItem -Path $p569srcroot -Recurse -File -ErrorAction SilentlyContinue | Select-String -Pattern 'NavMesh|BuildNavigation' | Select-Object -First 30) | ForEach-Object { Write-Output ('NAVMESH LINE ' + $_.Path + ' ' + $_.Line.Trim()) }
} else { Write-Output 'NO SOURCE FOLDER FOUND' }
Write-Output 'PHI P569 VERDICT: TXT NOTES VERIFICATION READ ABOVE'
Write-Output 'JOB 569 DONE'
```
