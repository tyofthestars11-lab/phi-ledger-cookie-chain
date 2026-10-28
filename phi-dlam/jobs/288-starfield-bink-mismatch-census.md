<!-- PHI-DIRECT -->
```powershell
Write-Output '=== STARFIELD BINK MISMATCH census (Tyrees photos 2026-10-27 21:31 MDT: direct launch fails - "The procedure entry point BinkNextFrame could not be located" in the ProjectGold 1.16.244.0 package, crash 0xc0000139 STATUS_ENTRYPOINT_NOT_FOUND). The exe expects a Bink export the loaded DLL does not carry: a version mismatch in the install folder, the signature of the foreign patch files Tyree traced the break to. Read-only census: every bink DLL in reach, its version and size, and where a matching one lives. Nothing changed, nothing removed. ==='
$pkg = Get-AppxPackage | Where-Object { $_.Name -match 'ProjectGold|Bethesda' } | Select-Object -First 1
if ($pkg) { Write-Output "package: $($pkg.PackageFullName)"; Write-Output "install: $($pkg.InstallLocation)" }
$roots = @()
if ($pkg -and $pkg.InstallLocation) { $roots += $pkg.InstallLocation }
$roots += 'D:\XboxGames\Starfield\Content'
foreach ($r in $roots) {
  Write-Output "--- root: $r (exists: $(Test-Path $r)) ---"
  if (Test-Path $r) {
    Get-ChildItem $r -Filter 'bink*.dll' -ErrorAction SilentlyContinue | ForEach-Object { "BINK: $($_.FullName) | $($_.Length) bytes | filever $($_.VersionInfo.FileVersion) | modified $($_.LastWriteTime)" } | Write-Output
    $exe = Join-Path $r 'Starfield.exe'
    if (Test-Path $exe) { $e = Get-Item $exe; "EXE: $exe | $($e.Length) bytes | filever $($e.VersionInfo.FileVersion) | modified $($e.LastWriteTime)" | Write-Output }
    Get-ChildItem $r -Filter '*.dll' -ErrorAction SilentlyContinue | Measure-Object | ForEach-Object { "dll count in root: $($_.Count)" } | Write-Output
  }
}
Write-Output '--- any other bink2w64.dll on the system (candidate matching copies) ---'
foreach ($d in @('C:\Program Files (x86)\Steam\steamapps\common','D:\SteamLibrary\steamapps\common','D:\XboxGames')) {
  if (Test-Path $d) { Get-ChildItem $d -Recurse -Filter 'bink2w64.dll' -ErrorAction SilentlyContinue | Select-Object -First 8 | ForEach-Object { "CANDIDATE: $($_.FullName) | $($_.Length) bytes | filever $($_.VersionInfo.FileVersion)" } | Write-Output }
}
Write-Output 'STARFIELD BINK CENSUS DONE'
```
