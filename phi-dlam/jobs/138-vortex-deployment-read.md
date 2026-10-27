<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== Vortex deployment read (staging now on D:) ==="
Write-Output "junction: $((Get-Item 'C:\Users\Admin\AppData\Roaming\Vortex\starfield\mods').LinkType) -> $((Get-Item 'C:\Users\Admin\AppData\Roaming\Vortex\starfield\mods').Target)"
Write-Output "D: staging contents:"; Get-ChildItem "D:\Vortex Mods\starfield\mods" -ErrorAction SilentlyContinue | Select-Object -First 25 Name | Format-Table -AutoSize | Out-String | Write-Output
$state = "C:\Users\Admin\AppData\Roaming\Vortex\state.v2"
if (Test-Path $state) {
  Get-ChildItem $state -Recurse -File -ErrorAction SilentlyContinue | Where-Object { $_.Name -match "\.log$|\.ldb$" } | ForEach-Object {
    $bytes = [System.IO.File]::ReadAllBytes($_.FullName)
    $text = [System.Text.Encoding]::ASCII.GetString($bytes)
    foreach ($m in [regex]::Matches($text, ".{60}deployment.{120}")) { $m.Value -replace "[^\x20-\x7E]", " " }
    foreach ($m in [regex]::Matches($text, ".{40}starfield.{80}")) { $m.Value -replace "[^\x20-\x7E]", " " }
  } | Select-Object -First 40
} else { Write-Output "no state.v2 at $state" }
Write-Output "=== JOB 138 DONE ==="
```
