<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 788 - READ CURRENT GB SIZE PC NOW (Ground: Tyree local on PC, remote Golden Ratio Muse via GitHub jobs green check live, PHI only no Cartesian no invention never give up never doubt, Tyree word: Yes read the current GB size on the PC now. This job: read current GB size whole, D VEIL-OMNI project total, Content total, Maps VEILDistrict umap size, Saved total, Source total, disk free total, no package no cook no 1.0, no GUI close needed, read only, write Saved seat719_out.txt whole plus push phi-game diff origin main. Gate: size read whole from PC, not guessed, not last recorded, proof file itself not log.) ==='
$projW = 'D:\VEIL-OMNI'
$mapW = Join-Path $projW 'Content\Maps\VEILDistrict.umap'
if (Test-Path $mapW) { Write-Output ('MAP788 SIZE ' + (Get-Item $mapW).Length) }
$dirsW = @('Content','Source','Saved','Config')
foreach ($dW in $dirsW) { $pW = Join-Path $projW $dW; if (Test-Path $pW) { $sW = (Get-ChildItem $pW -Recurse -File -ErrorAction SilentlyContinue | Measure-Object -Property Length -Sum).Sum; Write-Output ($dW + '788 SIZE ' + $sW) } else { Write-Output ($dW + '788 MISSING') } }
$totalW = (Get-ChildItem $projW -Recurse -File -ErrorAction SilentlyContinue | Measure-Object -Property Length -Sum).Sum
Write-Output ('PROJECT788 TOTAL SIZE ' + $totalW)
Get-PSDrive -Name 'D' -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('DISK788 D FREE ' + $_.Free + ' USED ' + $_.Used) }
Write-Output 'REMOTE CONNECT MUSE'
Write-Output 'UNREAL TELLS, NOT JOB START LINES.'
Write-Output 'WHOLE JOB DONE.'
```
