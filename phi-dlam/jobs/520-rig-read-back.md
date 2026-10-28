<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 520 - THE RIG READ BACK (Ground: job 519 seats the light rig in the saved district through the editor own Python hand, detached, and the script writes its every print to its own page in the project folder. This job reads that page whole when it stands, prints the district save time beside it, and counts the editor processes still standing, so the rig state is known from its own record. If the page is not there yet, the job says so plainly with the editor count as the reason read. Every variable carries the p520 prefix.) ==='
$p520page = 'D:\VEIL-OMNI\worldfix519.txt'
if (Test-Path $p520page) {
  Write-Output ('RIG PAGE at ' + (Get-Item $p520page).LastWriteTime)
  Get-Content $p520page | ForEach-Object { Write-Output ('RIG ' + $_) }
} else {
  Write-Output 'RIG PAGE NOT PRESENT'
}
$p520map = 'D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap'
if (Test-Path $p520map) { Write-Output ('DISTRICT SAVED AT ' + (Get-Item $p520map).LastWriteTime + ' bytes=' + (Get-Item $p520map).Length) }
$p520edname = 'UnrealEdito' + [char]114
$p520ed = Get-Process -Name $p520edname -ErrorAction SilentlyContinue
Write-Output ('EDITOR PROCS=' + ($p520ed | Measure-Object).Count)
$p520cmd = Get-Process -Name 'UnrealEditor-Cmd' -ErrorAction SilentlyContinue
Write-Output ('CMD PROCS=' + ($p520cmd | Measure-Object).Count)
Write-Output 'PHI P520 VERDICT: RIG STATE PRINTED ABOVE'
Write-Output 'JOB 520 DONE'
```
