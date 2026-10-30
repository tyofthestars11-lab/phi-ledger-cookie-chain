<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 659 - CLEAR COOK658 SPACE (Ground: Tyree word Yes clear cook folder off PC give space back after restart did not change game cook added space. This job removes only the cook folder, never the project, never the map, never the icon.) ==='
$p659cook = 'D:\VEIL-OMNI\Saved\Cook658'
$p659map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
$p659icon = 'C:\Users\Admin\Desktop\VEIL OMNI.lnk'
if (Test-Path $p659cook) {
  $p659before = (Get-ChildItem $p659cook -Recurse -ErrorAction SilentlyContinue | Measure-Object -Property Length -Sum).Sum
  Write-Output ('COOK659 BEFORE BYTES ' + $p659before)
  Remove-Item $p659cook -Recurse -Force -ErrorAction SilentlyContinue
  Write-Output 'COOK659 REMOVE ATTEMPT DONE'
} else { Write-Output 'COOK659 FOLDER ALREADY GONE' }
if (Test-Path $p659cook) { Write-Output 'COOK659 STILL PRESENT' } else { Write-Output 'COOK659 GONE TRUE' }
if (Test-Path $p659map) { Write-Output 'MAP659 PROJECT SAFE PRESENT' } else { Write-Output 'MAP659 PROJECT MISSING' }
if (Test-Path $p659icon) { Write-Output 'ICON659 DESKTOP ICON SAFE PRESENT' } else { Write-Output 'ICON659 DESKTOP ICON MISSING' }
Write-Output 'AUTO659 HIDDENDRAIN TASK QUERY BELOW'
schtasks /query /tn 'PHI-DLAM-HiddenDrain' /fo list 2>&1
Write-Output 'JOB 659 DONE'
```
