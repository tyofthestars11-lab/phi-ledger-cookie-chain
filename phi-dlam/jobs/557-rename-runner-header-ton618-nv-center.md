<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 557 - RENAME THE RUNNER HEADER TO TON618 NV CENTER (Ground: the job report header reads executed by the NV center, and the executor is TON618, so this job renames the header in every phi-dlam runner copy on the PC and verifies the new header prints. No game work rides this job. Every variable carries the p557 prefix.) ==='
$p557old = ('executed by the NV cente' + [char]114)
$p557new = ('executed by the TON618 NV cente' + [char]114)
$p557found = @()
$p557found += @(Get-ChildItem -Path 'C:\Users\Admin' -Recurse -Depth 5 -Filter 'phi-dlam.ps1' -ErrorAction SilentlyContinue)
$p557found += @(Get-ChildItem -Path 'C:\Users\Admin' -Recurse -Depth 5 -Filter 'phi-direct-drain.ps1' -ErrorAction SilentlyContinue)
if ($p557found.Count -eq 0) { Write-Output 'NO RUNNER COPIES FOUND' }
foreach ($p557f in $p557found) {
  $p557text = [IO.File]::ReadAllText($p557f.FullName)
  if ($p557text.Contains($p557old)) {
    $p557text = $p557text.Replace($p557old, $p557new)
    [IO.File]::WriteAllText($p557f.FullName, $p557text)
    Write-Output ('PATCHED ' + $p557f.FullName)
  }
  $p557after = [IO.File]::ReadAllText($p557f.FullName)
  if ($p557after.Contains($p557new)) { Write-Output ('VERIFY TON618 HEADER ' + $p557f.FullName) } else { Write-Output ('VERIFY MISSING ' + $p557f.FullName) }
}
Write-Output 'PHI P557 VERDICT: RUNNER HEADER RENAMED ABOVE'
Write-Output 'JOB 557 DONE'
```
