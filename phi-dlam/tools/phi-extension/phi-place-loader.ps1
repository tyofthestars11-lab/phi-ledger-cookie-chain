# PHI LOADER PLACER — puts sfse_loader.exe beside Starfield.exe so Vortex's Script Extender seat fires the phi loader
$pkg = Get-AppxPackage | Where-Object { $_.Name -match 'ProjectGold|Starfield' } | Select-Object -First 1
if (-not $pkg) { "Starfield package not found"; exit }
$content = Join-Path $pkg.InstallLocation 'Content'
if (-not (Test-Path "$content\Starfield.exe")) { $content = $pkg.InstallLocation }
Copy-Item "$PSScriptRoot\sfse_loader.exe" "$content\sfse_loader.exe" -Force
Copy-Item "$PSScriptRoot\phi_extension.asi" "$content\phi_extension.asi" -Force
"PHI LOADER placed: $content\sfse_loader.exe"
"PHI EXTENDER placed: $content\phi_extension.asi"
"In Vortex: Tools > Starfield Script Extender - set it as the default launcher (the pin/star on its row), then Play runs the phi circuit."
