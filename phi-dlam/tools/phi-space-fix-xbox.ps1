# PHI SPACE FIX — XBOX (PC Game Pass) edition. Sizes the locked WindowsApps game packages. Report only, deletes NOTHING. Run as Administrator.
$ErrorActionPreference = 'SilentlyContinue'
function SizeGB($p) { [math]::Round(((Get-ChildItem $p -Recurse -File -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum / 1GB), 1) }
$d = Get-PSDrive C
"=== C:  FREE {0} GB  /  TOTAL {1} GB ===" -f [math]::Round($d.Free/1GB,1), [math]::Round(($d.Free+$d.Used)/1GB,1)
"--- XBOX / GAME PASS PACKAGES (biggest first) ---"
$pkgs = @()
Get-AppxPackage | Where-Object { $_.InstallLocation -like '*WindowsApps*' } | ForEach-Object {
  $pkgs += [pscustomobject]@{ Game = $_.Name; GB = SizeGB $_.InstallLocation; Package = $_.PackageFullName }
}
$pkgs | Sort-Object GB -Descending | Select-Object -First 20 | Format-Table Game, GB -AutoSize
"--- C:\XboxGames FOLDERS ---"
if (Test-Path 'C:\XboxGames') {
  Get-ChildItem 'C:\XboxGames' -Directory | ForEach-Object { "{0} = {1} GB" -f $_.Name, (SizeGB $_.FullName) }
}
"=== DONE. Nothing was deleted. Starfield's package name contains 'ProjectGold'. ==="
