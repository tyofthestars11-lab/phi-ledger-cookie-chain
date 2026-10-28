<!-- PHI-DIRECT -->
```powershell
Write-Output '=== DRIVE SPACE census (Tyree 2026-10-27 21:35 MDT: C cannot take Starfield back - space. Read-only: the measured free space on both drives and what the big residents of C are, so the record carries numbers instead of impressions. Nothing moved, nothing removed.) ==='
Get-PSDrive -PSProvider FileSystem | Where-Object { $_.Name -in @('C','D') } | ForEach-Object { "$($_.Name): free $([math]::Round($_.Free/1GB,2)) GB of $([math]::Round(($_.Used+$_.Free)/1GB,2)) GB" } | Write-Output
Write-Output '--- largest top-level residents of C (folder totals, may take a breath on big trees) ---'
Get-ChildItem 'C:\' -Directory -ErrorAction SilentlyContinue | ForEach-Object {
  $sum = (Get-ChildItem $_.FullName -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum
  [PSCustomObject]@{ Folder = $_.FullName; GB = [math]::Round($sum/1GB,2) }
} | Sort-Object GB -Descending | Select-Object -First 8 | Format-Table -AutoSize | Out-String | Write-Output
Write-Output 'DRIVE SPACE CENSUS DONE'
```
