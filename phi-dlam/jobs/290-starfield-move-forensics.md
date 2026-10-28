<!-- PHI-DIRECT -->
```powershell
Write-Output '=== STARFIELD MOVE FORENSICS (Tyree 2026-10-27 21:36 MDT: "Which ai? Who moved it?" He installed Starfield on C, never moved it; the Xbox app now registers it to D:\XboxGames, last updated 10/26/2026. The lane record shows staging-folder moves only, never a game move. Windows itself logged every package operation: the AppX deployment log names the operation and its time. Read-only forensics - answer from the machines own record.) ==='
Write-Output '--- 1. AppX deployment operations for ProjectGold (newest 25) ---'
try {
  Get-WinEvent -LogName 'Microsoft-Windows-AppXDeploymentServer/Operational' -MaxEvents 3000 -ErrorAction Stop |
    Where-Object { $_.Message -match 'ProjectGold' } |
    Select-Object -First 25 |
    ForEach-Object { "$($_.TimeCreated) | id=$($_.Id) | $($_.Message.Substring(0, [Math]::Min(220, $_.Message.Length)) -replace '\s+',' ')" } | Write-Output
} catch { Write-Output "appx log read failed: $($_.Exception.Message)" }
Write-Output '--- 2. Filesystem birth certificates ---'
foreach ($p in @('D:\XboxGames\Starfield','D:\XboxGames\Starfield\Content')) {
  if (Test-Path $p) { $i = Get-Item $p; "$p | created $($i.CreationTime) | modified $($i.LastWriteTime)" | Write-Output }
}
$pkg = Get-AppxPackage | Where-Object { $_.Name -match 'ProjectGold' } | Select-Object -First 1
if ($pkg) { "package InstallLocation: $($pkg.InstallLocation)"; if (Test-Path $pkg.InstallLocation) { $i = Get-Item $pkg.InstallLocation; "package folder | created $($i.CreationTime) | modified $($i.LastWriteTime)" | Write-Output } }
Write-Output 'STARFIELD MOVE FORENSICS DONE'
```
