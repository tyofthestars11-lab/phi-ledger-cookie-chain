<!-- PHI-DIRECT -->
```powershell
Write-Output '=== LIBRARY TRUTH PASS 471 - NO GHOSTS ON THE SHELF (Ground from Tyree screen, 2026-10-28, over the live v4 library: the Xbox section holds Cyberpunk 2077 and Phantom Liberty true, but also XboxGames and GameSave, which are system folders, not games, and Starfield with its ghost shell folder, and his verdict stands: Starfield should not be installed, aint no way. He is right on the record: the Starfield Premium refund was approved by Microsoft on 2026-10-27, order 8960417948, the license revoked by his own choice; what stands on D is leftover folders, and the folder sweep cannot tell a leftover from a living install. This pass teaches the catalog the difference, deleting nothing, moving nothing. One, the XboxGames sweep skips the junk seats by name, XboxGames itself, GameSave, and any ghost shell folder. Two, Starfield is cross checked against the registered packages: its package state prints as its own line, and when no Starfield package stands registered, its folders leave the catalog, because a revoked license is not an installed game; if a package does stand, the row stays and the print says why. Three, the shelf section is renamed XBOX GAMES in the current source, recompiled, and the panel relaunches on the true catalog. Steam, Epic and EA ride as before. The verdict in one line: TRUTH PASS with the counts and the Starfield state. Every variable carries the tp471 prefix.) ==='
$tp471dir = 'C:\Users\Admin\PhiTerminal'
$tp471rows = @()
$tp471nXbox = 0; $tp471nSteam = 0; $tp471nEpic = 0; $tp471nEa = 0
function Clean471($tp471s) { if ($null -eq $tp471s) { return '' }; return ($tp471s -replace '[|\r\n]', ' ').Trim() }
$tp471starPkg = @(Get-AppxPackage -ErrorAction SilentlyContinue | Where-Object { $_.Name -match 'Starfield|Bethesda' })
Write-Output ('STARFIELD PACKAGES=' + $tp471starPkg.Count)
foreach ($tp471p in $tp471starPkg) { Write-Output ('STARPKG ' + $tp471p.Name + ' ' + $tp471p.PackageFullName) }
$tp471junk = @('XboxGames', 'GameSave', 'Program Files', 'WindowsApps', 'Content')
foreach ($tp471root in @('D:\XboxGames', 'C:\XboxGames')) {
  if (Test-Path $tp471root) {
    foreach ($tp471f in @(Get-ChildItem $tp471root -Directory -ErrorAction SilentlyContinue)) {
      if ($tp471junk -contains $tp471f.Name) { Write-Output ('SKIP JUNK ' + $tp471f.Name); continue }
      if ($tp471f.Name -match 'ghost-shell') { Write-Output ('SKIP GHOST ' + $tp471f.Name); continue }
      if ($tp471f.Name -match '^Starfield' -and $tp471starPkg.Count -eq 0) { Write-Output ('SKIP REVOKED ' + $tp471f.Name); continue }
      $tp471rows += ((Clean471 $tp471f.Name) + '|XBOX GAMES||' + (Clean471 $tp471f.FullName)); $tp471nXbox += 1
    }
  }
}
try {
  $tp471steamRoot = 'C:\Program Files (x86)\Steam'
  $tp471libs = @($tp471steamRoot)
  $tp471vdf = Join-Path $tp471steamRoot 'steamapps\libraryfolders.vdf'
  if (Test-Path $tp471vdf) { foreach ($tp471m in [regex]::Matches((Get-Content $tp471vdf -Raw), '"path"\s+"([^"]+)"')) { $tp471libs += ($tp471m.Groups[1].Value -replace '\\\\', '\') } }
  foreach ($tp471lib in $tp471libs) {
    $tp471apps = Join-Path $tp471lib 'steamapps'
    if (Test-Path $tp471apps) {
      foreach ($tp471acf in @(Get-ChildItem $tp471apps -Filter 'appmanifest_*.acf' -ErrorAction SilentlyContinue)) {
        $tp471raw = Get-Content $tp471acf.FullName -Raw
        $tp471nm = [regex]::Match($tp471raw, '"name"\s+"([^"]+)"'); $tp471id = [regex]::Match($tp471raw, '"installdi[r]"\s+"([^"]+)"')
        if ($tp471nm.Success) { $tp471ip = ''; if ($tp471id.Success) { $tp471ip = Join-Path (Join-Path $tp471apps 'common') $tp471id.Groups[1].Value }; $tp471rows += ((Clean471 $tp471nm.Groups[1].Value) + '|STEAM||' + (Clean471 $tp471ip)); $tp471nSteam += 1 }
      }
    }
  }
} catch { }
try {
  $tp471man = 'C:\ProgramData\Epic\EpicGamesLauncher\Data\Manifests'
  if (Test-Path $tp471man) {
    foreach ($tp471it in @(Get-ChildItem $tp471man -Filter '*.item' -ErrorAction SilentlyContinue)) {
      try { $tp471j = Get-Content $tp471it.FullName -Raw | ConvertFrom-Json; $tp471pn = [IO.Path]::GetFileNameWithoutExtension($tp471j.LaunchExecutable); $tp471rows += ((Clean471 $tp471j.DisplayName) + '|EPIC|' + (Clean471 $tp471pn) + '|' + (Clean471 $tp471j.InstallLocation)); $tp471nEpic += 1 } catch { }
    }
  }
} catch { }
try {
  $tp471ea = 'C:\Program Files\EA Games'
  if (Test-Path $tp471ea) { foreach ($tp471f2 in @(Get-ChildItem $tp471ea -Directory -ErrorAction SilentlyContinue)) { $tp471rows += ((Clean471 $tp471f2.Name) + '|EA||' + (Clean471 $tp471f2.FullName)); $tp471nEa += 1 } }
} catch { }
$tp471games = Join-Path $tp471dir 'games.txt'
$tp471rows = @($tp471rows | Select-Object -Unique | Select-Object -First 400)
Set-Content -Path $tp471games -Value $tp471rows
Write-Output ('CATALOG xboxgames=' + $tp471nXbox + ' steam=' + $tp471nSteam + ' epic=' + $tp471nEpic + ' ea=' + $tp471nEa + ' total=' + $tp471rows.Count)
$tp471src = Join-Path $tp471dir 'PhiTerminal3.cs'
$tp471text = Get-Content $tp471src -Raw
$tp471g1 = ([regex]::Matches($tp471text, [regex]::Escape('"RUNNING NOW", "XBOX", "STEAM"'))).Count
Write-Output ('GROUP LINE=' + $tp471g1)
if ($tp471g1 -eq 1) {
  Copy-Item $tp471src ($tp471src + '.phi-backup-471') -Force
  $tp471text = $tp471text.Replace('"RUNNING NOW", "XBOX", "STEAM"', '"RUNNING NOW", "XBOX GAMES", "STEAM"')
  $tp471text = $tp471text.Replace('if (s.Contains("XBOX")) return "XBOX";', 'if (s.Contains("XBOX")) return "XBOX GAMES";')
  Set-Content -Path $tp471src -Value $tp471text -NoNewline
  Write-Output 'SECTION RENAMED XBOX GAMES'
}
$tp471old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
foreach ($tp471o in $tp471old) { Stop-Process -Id $tp471o.Id -Force -ErrorAction SilentlyContinue; Write-Output ('PANEL CLOSED pid=' + $tp471o.Id) }
Start-Sleep -Seconds 1
$tp471csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$tp471exe = Join-Path $tp471dir 'PhiTerminal.exe'
& $tp471csc /nologo /target:winexe /out:$tp471exe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $tp471src | ForEach-Object { Write-Output ('CSC ' + $_) }
$tp471exeBytes = 0; if (Test-Path $tp471exe) { $tp471exeBytes = (Get-Item $tp471exe).Length }
Write-Output ('EXE BYTES=' + $tp471exeBytes)
$tp471pid = 0; $tp471state = 'NOT-LAUNCHED'
if ($tp471exeBytes -gt 0) {
  $tp471proc = Start-Process -FilePath $tp471exe -WorkingDirectory $tp471dir -PassThru
  Start-Sleep -Seconds 4
  $tp471check = Get-Process -Id $tp471proc.Id -ErrorAction SilentlyContinue
  if ($tp471check) { $tp471state = 'STANDS'; $tp471pid = $tp471proc.Id } else { $tp471state = 'EXITED' }
}
$tp471log = Join-Path $tp471dir 'phi_terminal_universal.log'
if (Test-Path $tp471log) { Get-Content $tp471log -Tail 6 | ForEach-Object { Write-Output ('ULOG ' + $_) } }
Write-Output ('PHI TP471 VERDICT: TRUTH PASS state=' + $tp471state + ' pid=' + $tp471pid + ' games=' + $tp471rows.Count + ' starfield_pkgs=' + $tp471starPkg.Count)
Write-Output 'JOB 471 DONE'
```
