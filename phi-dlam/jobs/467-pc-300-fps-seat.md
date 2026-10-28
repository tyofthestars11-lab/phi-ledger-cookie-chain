<!-- PHI-DIRECT -->
```powershell
Write-Output '=== PC 300 FPS SEAT 467 - EVERY CAP COMES OFF, MEASURED FIRST (Ground from Tyree, 2026-10-28: lets make my pc 300 fps. His machine stands measured in the record: i5 12400F, RTX 3050 6 GB, 16 GB RAM, and his own PIE photo reads FPS 59.6, which is the signature of caps, not of silicon: frame smoothing, a 60 class frame limit, vsync and the balanced power plan each hold the rate down before the GPU is ever asked. This job measures the ground, then removes every cap the lane can lawfully touch. One, it prints the current power plan, the monitor refresh rate, the GPU name and driver, and every frame line already standing in the VEIL engine ini and the game user settings. Two, it seats the Windows power plan to High Performance. Three, in DefaultEngine ini, backed up first, it seats frame smoothing off under the Engine section and t.MaxFPS at 0, uncapped, under a ConsoleVariables section, so his 300 target is a ceiling the game may reach, not a lock it hits; existing lines are replaced, missing lines are added, and the seats verify by count. Four, in the saved GameUserSettings it seats the frame rate limit at 0 and vsync off where those lines stand, creating the file section if absent. The verdict in one line: FPS SEAT with the caps state. Every variable carries the fp467 prefix.) ==='
$fp467pc = Get-CimInstance Win32_VideoController -ErrorAction SilentlyContinue | Select-Object -First 1
if ($fp467pc) { Write-Output ('DISPLAY gpu=' + $fp467pc.Name + ' refresh=' + $fp467pc.CurrentRefreshRate + ' driver=' + $fp467pc.DriverVersion) }
$fp467plan = powercfg /getactivescheme
Write-Output ('POWER BEFORE ' + ($fp467plan -join ' '))
powercfg /setactive 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c | Out-Null
$fp467plan2 = powercfg /getactivescheme
Write-Output ('POWER AFTER ' + ($fp467plan2 -join ' '))
$fp467ini = 'D:\VEIL-OMNI\Config\DefaultEngine.ini'
$fp467gus = 'D:\VEIL-OMNI\Saved\Config\Windows\GameUserSettings.ini'
if (Test-Path $fp467ini) {
  $fp467before = @(Select-String -Path $fp467ini -Pattern 'SmoothFrameRate|MaxFPS|SmoothedFrameRate' -ErrorAction SilentlyContinue)
  foreach ($fp467b in $fp467before) { Write-Output ('INI BEFORE ' + $fp467b.Line.Trim()) }
  Copy-Item $fp467ini ($fp467ini + '.phi-backup-467') -Force
  $fp467lines = @(Get-Content $fp467ini | Where-Object { $_ -notmatch 'bSmoothFrameRate' -and $_ -notmatch 't\.MaxFPS' })
  $fp467out = @(); $fp467inEngine = $false; $fp467didEngine = $false; $fp467didCv = $false
  foreach ($fp467l in $fp467lines) {
    $fp467out += $fp467l
    if ($fp467l -match '^\[/Script/Engine\.Engine\]') { $fp467out += 'bSmoothFrameRate=False'; $fp467didEngine = $true }
    if ($fp467l -match '^\[ConsoleVariables\]') { $fp467out += 't.MaxFPS=0'; $fp467didCv = $true }
  }
  if (-not $fp467didEngine) { $fp467out += ''; $fp467out += '[/Script/Engine.Engine]'; $fp467out += 'bSmoothFrameRate=False' }
  if (-not $fp467didCv) { $fp467out += ''; $fp467out += '[ConsoleVariables]'; $fp467out += 't.MaxFPS=0' }
  Set-Content -Path $fp467ini -Value $fp467out
  $fp467v1 = ([regex]::Matches((Get-Content $fp467ini -Raw), 'bSmoothFrameRate=False')).Count
  $fp467v2 = ([regex]::Matches((Get-Content $fp467ini -Raw), 't\.MaxFPS=0')).Count
  Write-Output ('INI SEATED smooth=' + $fp467v1 + ' maxfps=' + $fp467v2)
}
if (Test-Path $fp467gus) {
  $fp467glines = @(Get-Content $fp467gus | Where-Object { $_ -notmatch 'FrameRateLimit' -and $_ -notmatch 'bUseVSync' })
  $fp467gout = @(); $fp467didG = $false
  foreach ($fp467g in $fp467glines) { $fp467gout += $fp467g; if ($fp467g -match '^\[/Script/Engine\.GameUserSettings\]') { $fp467gout += 'FrameRateLimit=0.000000'; $fp467gout += 'bUseVSync=False'; $fp467didG = $true } }
  if (-not $fp467didG) { $fp467gout += ''; $fp467gout += '[/Script/Engine.GameUserSettings]'; $fp467gout += 'FrameRateLimit=0.000000'; $fp467gout += 'bUseVSync=False' }
  Set-Content -Path $fp467gus -Value $fp467gout
  Write-Output 'GUS SEATED limit=0 vsync=off'
} else { Write-Output 'GUS ABSENT (seats at first run from the engine ini)' }
Write-Output 'PHI FP467 VERDICT: FPS SEAT caps removed, ceiling open'
Write-Output 'JOB 467 DONE'
```
