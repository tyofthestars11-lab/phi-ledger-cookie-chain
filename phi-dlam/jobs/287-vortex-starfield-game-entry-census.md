<!-- PHI-DIRECT -->
```powershell
Write-Output '=== VORTEX STARFIELD - GAME ENTRY NOT FOUND census (Tyrees photos 2026-10-27 21:28 MDT: Play fails twice, error GameEntryNotFound thrown in Vortexs own renderer). Read-only: which link in the chain broke - the game install, the Xbox package registration, or Vortexs stored entry. Nothing is changed, nothing removed; his Creations and his save are not touched. ==='
Write-Output '--- 1. The game install on disk ---'
Get-ChildItem 'D:\XboxGames' -Directory -ErrorAction SilentlyContinue | Select-Object -ExpandProperty FullName | Write-Output
foreach ($p in @('D:\XboxGames\Starfield\Content\Starfield.exe','D:\XboxGames\Starfield\Starfield.exe')) {
  Write-Output "$p exists: $(Test-Path $p)"
}
Write-Output '--- 2. Xbox package registration (what Vortex discovery keys on) ---'
Get-AppxPackage | Where-Object { $_.Name -match 'Starfield|ProjectGold|Bethesda' } | ForEach-Object { "$($_.Name) | $($_.PackageFullName) | $($_.InstallLocation) | status=$($_.Status)" } | Write-Output
Get-AppxPackage -Name 'Microsoft.GamingServices' | ForEach-Object { "GamingServices | $($_.PackageFullName) | status=$($_.Status)" } | Write-Output
Get-Service -Name 'GamingServices*' -ErrorAction SilentlyContinue | ForEach-Object { "service $($_.Name): $($_.Status)" } | Write-Output
Write-Output '--- 3. Vortex log lines from tonight (the error in its own words) ---'
$logdir = Join-Path $env:APPDATA 'Vortex\logs'
if (Test-Path $logdir) {
  $log = Get-ChildItem $logdir -File | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  Write-Output "log: $($log.FullName) modified $($log.LastWriteTime)"
  Select-String -Path $log.FullName -Pattern 'GameEntryNotFound|game entry|starfield|discover' | Select-Object -Last 12 | ForEach-Object { $_.Line.Trim() } | Write-Output
} else { Write-Output 'no Vortex logs folder found' }
Write-Output '--- 4. Vortex state surface (list only, LevelDB stays closed) ---'
Get-ChildItem (Join-Path $env:APPDATA 'Vortex') -ErrorAction SilentlyContinue | Select-Object Name, LastWriteTime | Format-Table -AutoSize | Out-String | Write-Output
Write-Output 'VORTEX GAME ENTRY CENSUS DONE'
```
