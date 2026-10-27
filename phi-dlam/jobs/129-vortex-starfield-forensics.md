<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Write-Output "=== Starfield installs on disk ==="
foreach ($p in @("D:\XboxGames", "D:\SteamLibrary\steamapps\common", "D:\Steam\steamapps\common", "C:\XboxGames", "D:\")) {
    if (Test-Path $p) {
        Get-ChildItem $p -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -like "*Starfield*" } | ForEach-Object { $_.FullName }
    }
}
Write-Output "=== Vortex process state ==="
$v = Get-Process -Name "Vortex" -ErrorAction SilentlyContinue
if ($v) { $v | ForEach-Object { "Vortex RUNNING pid=$($_.Id)" } } else { Write-Output "Vortex closed" }
Write-Output "=== Vortex state strings: starfield discovery + deployment ==="
$stateDir = "$env:APPDATA\Vortex\state"
if (Test-Path $stateDir) {
    Get-ChildItem $stateDir -Recurse -File -ErrorAction SilentlyContinue | Where-Object { $_.Name -match "\.(log|ldb)$" } | ForEach-Object {
        $hits = Select-String -Path $_.FullName -Pattern "deploymentMethod" -AllMatches -ErrorAction SilentlyContinue | Select-Object -First 2
        foreach ($h in $hits) { $t = $h.Line.Trim(); $t.Substring(0, [Math]::Min(260, $t.Length)) }
    }
    Get-ChildItem $stateDir -Recurse -File -ErrorAction SilentlyContinue | Where-Object { $_.Name -match "\.(log|ldb)$" } | ForEach-Object {
        $hits = Select-String -Path $_.FullName -Pattern "Starfield" -AllMatches -ErrorAction SilentlyContinue | Select-Object -First 2
        foreach ($h in $hits) { $t = $h.Line.Trim(); $t.Substring(0, [Math]::Min(260, $t.Length)) }
    }
} else { Write-Output "no state dir at $stateDir" }
Write-Output "=== Vortex staging / mods folders ==="
foreach ($p in @("$env:APPDATA\Vortex", "D:\Vortex Mods", "D:\Vortex", "C:\ProgramData\Vortex")) {
    if (Test-Path $p) { Get-ChildItem $p -Directory -ErrorAction SilentlyContinue | ForEach-Object { $_.FullName } }
}
Write-Output "=== JOB 129 DONE ==="
```
