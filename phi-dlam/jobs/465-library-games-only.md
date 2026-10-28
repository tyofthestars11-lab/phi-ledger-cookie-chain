<!-- PHI-DIRECT -->
```powershell
Write-Output '=== LIBRARY GAMES ONLY 465 - A GAMES SECTION, NOT AN APP DRAWER (Ground from Tyree screen, 2026-10-28: the v3 library stands and reads 45 games on the shelves, but its Xbox sweep took every Store package on the machine, Microsoft Family, Notepad Plus Plus, Python, LinkedIn, the Windows Web Experience Pack, all wearing the XBOX label, and his word stands: it has xbox and microsoft in one, I need games section. The catalog rule changes to game evidence only. Xbox games are read from the XboxGames folders themselves on D and C, every folder there is a game by his own all games on D law, named by its folder, which for Xbox PC titles is the real title. Steam, Epic and EA rows ride as built in 462. The Store package sweep leaves the catalog entirely; apps are not games and the shelf is a games shelf. One, this job rebuilds games txt from the four game sources with per source counts printed. Two, it renames the terminal section from XBOX to XBOX GAMES in PhiTerminal3 cs, count gated on the group list line and the GroupFor return, and recompiles the same exe. Three, it closes the standing panel, launches it fresh on the clean catalog, and prints the pid and the log tail, whose LIBRARY line now counts games only. The verdict in one line: GAMES ONLY with the counts and the state. Every variable carries the lg465 prefix.) ==='
$lg465dir = 'C:\Users\Admin\PhiTerminal'
$lg465rows = @()
$lg465nXbox = 0; $lg465nSteam = 0; $lg465nEpic = 0; $lg465nEa = 0
function Clean465($lg465s) { if ($null -eq $lg465s) { return '' }; return ($lg465s -replace '[|\r\n]', ' ').Trim() }
foreach ($lg465root in @('D:\XboxGames', 'C:\XboxGames')) {
  if (Test-Path $lg465root) { foreach ($lg465f in @(Get-ChildItem $lg465root -Directory -ErrorAction SilentlyContinue)) { $lg465rows += ((Clean465 $lg465f.Name) + '|XBOX GAMES||' + (Clean465 $lg465f.FullName)); $lg465nXbox += 1 } }
}
try {
  $lg465steamRoot = 'C:\Program Files (x86)\Steam'
  $lg465libs = @($lg465steamRoot)
  $lg465vdf = Join-Path $lg465steamRoot 'steamapps\libraryfolders.vdf'
  if (Test-Path $lg465vdf) { foreach ($lg465m in [regex]::Matches((Get-Content $lg465vdf -Raw), '"path"\s+"([^"]+)"')) { $lg465libs += ($lg465m.Groups[1].Value -replace '\\\\', '\') } }
  foreach ($lg465lib in $lg465libs) {
    $lg465apps = Join-Path $lg465lib 'steamapps'
    if (Test-Path $lg465apps) {
      foreach ($lg465acf in @(Get-ChildItem $lg465apps -Filter 'appmanifest_*.acf' -ErrorAction SilentlyContinue)) {
        $lg465raw = Get-Content $lg465acf.FullName -Raw
        $lg465nm = [regex]::Match($lg465raw, '"name"\s+"([^"]+)"'); $lg465id = [regex]::Match($lg465raw, '"installdi[r]"\s+"([^"]+)"')
        if ($lg465nm.Success) { $lg465ip = ''; if ($lg465id.Success) { $lg465ip = Join-Path (Join-Path $lg465apps 'common') $lg465id.Groups[1].Value }; $lg465rows += ((Clean465 $lg465nm.Groups[1].Value) + '|STEAM||' + (Clean465 $lg465ip)); $lg465nSteam += 1 }
      }
    }
  }
} catch { }
try {
  $lg465man = 'C:\ProgramData\Epic\EpicGamesLauncher\Data\Manifests'
  if (Test-Path $lg465man) {
    foreach ($lg465it in @(Get-ChildItem $lg465man -Filter '*.item' -ErrorAction SilentlyContinue)) {
      try { $lg465j = Get-Content $lg465it.FullName -Raw | ConvertFrom-Json; $lg465pn = [IO.Path]::GetFileNameWithoutExtension($lg465j.LaunchExecutable); $lg465rows += ((Clean465 $lg465j.DisplayName) + '|EPIC|' + (Clean465 $lg465pn) + '|' + (Clean465 $lg465j.InstallLocation)); $lg465nEpic += 1 } catch { }
    }
  }
} catch { }
try {
  $lg465ea = 'C:\Program Files\EA Games'
  if (Test-Path $lg465ea) { foreach ($lg465f2 in @(Get-ChildItem $lg465ea -Directory -ErrorAction SilentlyContinue)) { $lg465rows += ((Clean465 $lg465f2.Name) + '|EA||' + (Clean465 $lg465f2.FullName)); $lg465nEa += 1 } }
} catch { }
$lg465games = Join-Path $lg465dir 'games.txt'
$lg465rows = @($lg465rows | Select-Object -Unique | Select-Object -First 400)
Set-Content -Path $lg465games -Value $lg465rows
Write-Output ('CATALOG xboxgames=' + $lg465nXbox + ' steam=' + $lg465nSteam + ' epic=' + $lg465nEpic + ' ea=' + $lg465nEa + ' total=' + $lg465rows.Count)
$lg465src = Join-Path $lg465dir 'PhiTerminal3.cs'
$lg465text = Get-Content $lg465src -Raw
$lg465g1 = ([regex]::Matches($lg465text, [regex]::Escape('"RUNNING NOW", "XBOX", "STEAM"'))).Count
Write-Output ('GROUP LINE=' + $lg465g1)
if ($lg465g1 -ne 1) { Write-Output 'PHI LG465 VERDICT: GAMES ONLY SKIP group gate closed'; Write-Output 'JOB 465 DONE'; return }
Copy-Item $lg465src ($lg465src + '.phi-backup-465') -Force
$lg465text = $lg465text.Replace('"RUNNING NOW", "XBOX", "STEAM"', '"RUNNING NOW", "XBOX GAMES", "STEAM"')
$lg465text = $lg465text.Replace('if (s.Contains("XBOX")) return "XBOX";', 'if (s.Contains("XBOX")) return "XBOX GAMES";')
Set-Content -Path $lg465src -Value $lg465text -NoNewline
$lg465old = @(Get-Process -Name 'PhiTerminal' -ErrorAction SilentlyContinue)
foreach ($lg465o in $lg465old) { Stop-Process -Id $lg465o.Id -Force -ErrorAction SilentlyContinue; Write-Output ('PANEL CLOSED pid=' + $lg465o.Id) }
Start-Sleep -Seconds 1
$lg465csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$lg465exe = Join-Path $lg465dir 'PhiTerminal.exe'
& $lg465csc /nologo /target:winexe /out:$lg465exe /reference:System.Windows.Forms.dll /reference:System.Drawing.dll $lg465src | ForEach-Object { Write-Output ('CSC ' + $_) }
$lg465exeBytes = 0; if (Test-Path $lg465exe) { $lg465exeBytes = (Get-Item $lg465exe).Length }
Write-Output ('EXE BYTES=' + $lg465exeBytes)
$lg465pid = 0; $lg465state = 'NOT-LAUNCHED'
if ($lg465exeBytes -gt 0) {
  $lg465proc = Start-Process -FilePath $lg465exe -WorkingDirectory $lg465dir -PassThru
  Start-Sleep -Seconds 4
  $lg465check = Get-Process -Id $lg465proc.Id -ErrorAction SilentlyContinue
  if ($lg465check) { $lg465state = 'STANDS'; $lg465pid = $lg465proc.Id } else { $lg465state = 'EXITED' }
}
$lg465log = Join-Path $lg465dir 'phi_terminal_universal.log'
if (Test-Path $lg465log) { Get-Content $lg465log -Tail 8 | ForEach-Object { Write-Output ('ULOG ' + $_) } }
Write-Output ('PHI LG465 VERDICT: GAMES ONLY state=' + $lg465state + ' pid=' + $lg465pid + ' games=' + $lg465rows.Count)
Write-Output 'JOB 465 DONE'
```
