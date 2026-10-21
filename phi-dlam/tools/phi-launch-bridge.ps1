# STARFIELD PHI LAUNCH BRIDGE — connects the stack to the Xbox + NVIDIA launchers — phi^2 = phi + 1
# SYSTEMS -> VORTEX (mod seat, ASI loader) -> BRAID -> STARFIELD via Xbox app seat -> NVIDIA APP
$ErrorActionPreference = 'SilentlyContinue'
$work = "$env:USERPROFILE\phi-tools"
"=== STARFIELD PHI — LAUNCH BRIDGE v2 ==="
if (Test-Path "$work\phi-xbox-systems.ps1") { & "$work\phi-xbox-systems.ps1"; "connected: XBOX SYSTEMS aligned" } else { "xbox systems layer not on this machine yet — skipped" }
$bray = Get-Process powershell | Where-Object { $_.MainWindowTitle -match 'ANYON|BRAID' }
if (-not $bray) {
  if (Test-Path "$work\phi-anyons-keeper.ps1") { Start-Process powershell -ArgumentList "-ExecutionPolicy Bypass -File `"$work\phi-anyons-keeper.ps1`"" -WindowStyle Minimized; "connected: FIBONACCI ANYON BRAID rising" }
}
$vortex = Get-StartApps | Where-Object { $_.Name -match 'Vortex' } | Select-Object -First 1
if ($vortex) { Start-Process explorer.exe "shell:AppsFolder\$($vortex.AppID)"; "connected: VORTEX open — mod seat (Game Pass ASI Loader rides it)" } else { "Vortex not found in Start apps — skipped" }
$pkg = Get-AppxPackage | Where-Object { $_.Name -match 'ProjectGold|Starfield' } | Select-Object -First 1
if ($pkg) {
  $manifest = $pkg | Get-AppxPackageManifest
  $appId = $manifest.Package.Applications.Application.Id | Select-Object -First 1
  Start-Process explorer.exe "shell:AppsFolder\$($pkg.PackageFamilyName)!$appId"
  "connected: STARFIELD launched through the Xbox app seat ($($pkg.Name))"
} else { "Starfield package not found on this machine — launch skipped" }
$nv = Get-StartApps | Where-Object { $_.Name -match 'NVIDIA' } | Select-Object -First 1
if ($nv) { Start-Process explorer.exe "shell:AppsFolder\$($nv.AppID)"; "connected: NVIDIA APP open — G-Assist awake beside the game" } else { "NVIDIA App not found in Start apps — skipped" }
"=== BRIDGE COMPLETE — the launchers are one door now ==="
