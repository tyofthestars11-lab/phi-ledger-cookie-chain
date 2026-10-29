<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 576 - GAMESTATE FIXED WIRING (Ground: Job 573 proved the CrashFix plus GameState Fixed core build, job 574 staged Godmode Safe and Vault Dress not wired, so this job wires APHI GameState Fixed as the active GameState in VEILGameMode, backup first, only intended lines changed, brace and paren balance printed, build only if patched, no package, no map placement, no terminal work, Cyberpunk parked. Every variable carries the p576 prefix.) ==='
$p576proj = 'D:\VEIL-OMNI'
$p576modecpp = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp'
$p576modeh = 'D:\VEIL-OMNI\Source\VEIL\Public\Game\VEILGameMode.h'
$p576ini = 'D:\VEIL-OMNI\Config\DefaultEngine.ini'
$p576backup = 'D:\VEIL-OMNI\Saved\backup576'
New-Item -ItemType Directory -Path $p576backup -Force | Out-Null
foreach ($p576f in @($p576modecpp, $p576modeh, $p576ini)) { if (Test-Path $p576f) { Copy-Item $p576f $p576backup -Force; Write-Output ('BACKUP576 DONE ' + $p576f) } else { Write-Output ('BACKUP576 MISSING ' + $p576f) } }
$p576hits = @(Select-String -Path $p576modecpp, $p576modeh, $p576ini -Pattern 'GameState' -ErrorAction SilentlyContinue | Select-Object -First 40)
foreach ($p576h in $p576hits) { Write-Output ('GAMESTATE576 ' + $p576h.Path + ' ' + $p576h.LineNumber + ' ' + $p576h.Line.Trim()) }
$p576lines = @(Get-Content $p576modecpp -ErrorAction SilentlyContinue)
$p576idx = -1
for ($p576i = 0; $p576i -lt $p576lines.Count; $p576i++) { if ($p576lines[$p576i] -match 'GameStateClass') { $p576idx = $p576i } }
$p576patched = 0
if ($p576idx -ge 0) {
  $p576old = $p576lines[$p576idx]
  Write-Output ('OLD576 ' + $p576old.Trim())
  $p576newlist = @()
  $p576hasinc = 0
  foreach ($p576l in $p576lines) { if ($p576l -match 'PHI_GameState_Fixed') { $p576hasinc = 1 } }
  $p576incdone = 0
  for ($p576i = 0; $p576i -lt $p576lines.Count; $p576i++) {
    if ($p576i -eq $p576idx) { $p576newlist += '  GameStateClass = APHI_GameState_Fixed::StaticClass();' }
    else { $p576newlist += $p576lines[$p576i] }
    if (($p576hasinc -eq 0) -and ($p576incdone -eq 0) -and ($p576lines[$p576i] -match '#include')) { $p576newlist += '#include "Game/PHI_GameState_Fixed.h"'; $p576incdone = 1 }
  }
  Set-Content -Path $p576modecpp -Value $p576newlist -Encoding UTF8
  $p576patched = 1
  Write-Output 'PATCH576 GAMESTATE OK'
  Write-Output 'NEW576 GameStateClass = APHI_GameState_Fixed::StaticClass();'
} else { Write-Output 'PATCH576 NO CONSTRUCTOR LINE UNWIRED' }
$p576text = Get-Content $p576modecpp -Raw -ErrorAction SilentlyContinue
$p576open = @([regex]::Matches($p576text, '\{')).Count
$p576close = @([regex]::Matches($p576text, '\}')).Count
$p576popen = @([regex]::Matches($p576text, '\(')).Count
$p576pclose = @([regex]::Matches($p576text, '\)')).Count
Write-Output ('BRACE576 OPEN ' + $p576open + ' CLOSE ' + $p576close)
Write-Output ('PAREN576 OPEN ' + $p576popen + ' CLOSE ' + $p576pclose)
if ($p576patched -eq 1) {
  $p576buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
  $p576uproj = 'D:\VEIL-OMNI\VEIL.uproject'
  $p576log = 'D:\VEIL-OMNI\Saved\build576.log'
  & $p576buildbat VEILEditor Win64 Development -Project="$p576uproj" -WaitMutex -NoHotReload *> "$p576log"
  $p576ok = @(Select-String -Path $p576log -Pattern 'Succeeded' -ErrorAction SilentlyContinue | Select-Object -First 5)
  if ($p576ok.Count -gt 0) { Write-Output 'BUILD576 Result: Succeeded' } else { Write-Output 'BUILD576 Result: Failed' }
  Write-Output ('LOG576 ' + $p576log)
} else { Write-Output 'BUILD576 SKIPPED UNWIRED' }
Write-Output 'PHI P576 VERDICT: GAMESTATE FIXED WIRING ABOVE'
Write-Output 'JOB 576 DONE'
```
