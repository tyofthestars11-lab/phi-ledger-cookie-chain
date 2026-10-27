# Job 201 — ProjectID read: DefaultGame.ini vs .uproject, both games (Meta AI ex.1's one new lead, read-first)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== ProjectID read, both games: the cook error names VEIL 451B8EAC-A89D-495A-A347-31670EA913C3 and OMNI DC5E4CF1-FD4D-485E-98F1-2B96AF43DB4C, and the project files on disk read correct. Meta AI seat claims the staged DefaultGame.ini GeneralProjectSettings ProjectID is the mismatch the cook actually reads. One read settles it: every ProjectID line in every Config ini, plus each .uproject in full. No writes. ==='
foreach ($g in @(@('VEIL','D:\VEIL'), @('OMNI','D:\OMNI-UE'))) {
  $name = $g[0]; $proj = $g[1]
  Write-Output "--- $name .uproject (full) ---"
  Get-Content "$proj\$name.uproject" -Raw
  Write-Output "--- $name ProjectID lines in Config ---"
  $hits = Select-String -Path "$proj\Config\*.ini" -Pattern 'ProjectID' -ErrorAction SilentlyContinue
  if ($hits) { $hits | ForEach-Object { "$($_.Filename): $($_.Line.Trim())" } } else { Write-Output 'NO ProjectID line in any Config ini' }
}
```
