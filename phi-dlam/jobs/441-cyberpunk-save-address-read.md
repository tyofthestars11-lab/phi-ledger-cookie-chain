<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CYBERPUNK SAVE ADDRESS READ 441 - THE SAVES STAND AT THE PACKAGE ADDRESS, NOT THE CLASSIC ONE (Ground read whole from job 437: the phi terminal stands placed, and its census of the classic save home, Saved Games CD Projekt Red Cyberpunk 2077, printed SAVE COUNT 0. The game itself stands as an Xbox package, named by job 437 from the package itself: CDPROJEKTSA dot 4d0e9834, full name carrying version 2.5.2.0 x64 and the publisher suffix 0xkrdv0gjmk28, installed under Program Files WindowsApps. Xbox format games keep their saves at the package address under LocalAppData Packages, in the SystemAppData wgs containers, so that is where this job reads. One, it lists the package folders under LocalAppData Packages whose names carry CDPROJEKTSA, with their names whole. Two, inside each, it walks the SystemAppData and LocalState trees and prints every folder and file with size, capped at 80 lines, so the save containers stand measured: their count, their total bytes, and their newest write time. Three, the verdict in one line: SAVE ADDRESS READ with the container count and total bytes, or SAVE ADDRESS EMPTY with the stage named. This job is read only, nothing is written or moved, and every variable carries the sa441 prefix.) ==='
$sa441pkgs = Join-Path $env:LOCALAPPDATA 'Packages'
$sa441dirs = @(Get-ChildItem $sa441pkgs -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -like '*CDPROJEKTSA*' })
Write-Output ('PACKAGE FOLDERS=' + $sa441dirs.Count)
foreach ($sa441d in $sa441dirs) { Write-Output ('PKGDIR: ' + $sa441d.Name) }
$sa441files = 0
$sa441bytes = 0
$sa441newest = $null
$sa441printed = 0
foreach ($sa441d in $sa441dirs) {
  foreach ($sa441sub in @('SystemAppData', 'LocalState', 'LocalCache')) {
    $sa441path = Join-Path $sa441d.FullName $sa441sub
    if (Test-Path $sa441path) {
      Write-Output ('TREE: ' + $sa441sub + ' stands')
      $sa441items = @(Get-ChildItem $sa441path -Recurse -File -ErrorAction SilentlyContinue)
      foreach ($sa441f in $sa441items) {
        $sa441files += 1; $sa441bytes += $sa441f.Length
        if ($null -eq $sa441newest -or $sa441f.LastWriteTime -gt $sa441newest) { $sa441newest = $sa441f.LastWriteTime }
        if ($sa441printed -lt 80) { Write-Output ('FILE ' + $sa441sub + ': ' + $sa441f.Name + ' bytes=' + $sa441f.Length); $sa441printed += 1 }
      }
    } else { Write-Output ('TREE: ' + $sa441sub + ' absent') }
  }
}
Write-Output ('SAVE FILES=' + $sa441files + ' TOTAL BYTES=' + $sa441bytes + ' NEWEST=' + $sa441newest)
if ($sa441files -gt 0) { Write-Output ('PHI SA441 VERDICT: SAVE ADDRESS READ files=' + $sa441files + ' bytes=' + $sa441bytes) } else { Write-Output 'PHI SA441 VERDICT: SAVE ADDRESS EMPTY stage=no-save-files-at-package-address' }
Write-Output 'JOB 441 DONE'
```
