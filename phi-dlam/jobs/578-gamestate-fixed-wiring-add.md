<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 578 - GAMESTATE FIXED WIRING ADD (Ground: Job 576 found no GameStateClass line to replace in VEILGameMode, build skipped unwired, so this job adds the GameStateClass line inside the VEILGameMode constructor body, backup first, full list rebuild only, only intended lines changed, brace and paren balance printed, build only if patched, no package, no map placement, no terminal work, Cyberpunk parked. Every variable carries the p578 prefix.) ==='
$p578modecpp = 'D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp'
$p578backup = 'D:\VEIL-OMNI\Saved\backup578'
New-Item -ItemType Directory -Path $p578backup -Force | Out-Null
if (Test-Path $p578modecpp) { Copy-Item $p578modecpp $p578backup -Force; Write-Output 'BACKUP578 DONE' } else { Write-Output 'BACKUP578 MISSING' }
$p578lines = @(Get-Content $p578modecpp -ErrorAction SilentlyContinue)
$p578ctor = -1
for ($p578i = 0; $p578i -lt $p578lines.Count; $p578i++) { if ($p578lines[$p578i] -match 'AVEILGameMode::AVEILGameMode') { $p578ctor = $p578i } }
Write-Output ('CTOR578 LINE ' + $p578ctor)
$p578brace = -1
if ($p578ctor -ge 0) { for ($p578i = $p578ctor; $p578i -lt $p578lines.Count; $p578i++) { if (($p578brace -eq -1) -and ($p578lines[$p578i] -match '\{')) { $p578brace = $p578i } } }
Write-Output ('BRACE578 LINE ' + $p578brace)
$p578patched = 0
if ($p578brace -ge 0) {
  $p578hasinc = 0
  foreach ($p578l in $p578lines) { if ($p578l -match 'PHI_GameState_Fixed') { $p578hasinc = 1 } }
  $p578newlist = @()
  $p578incdone = 0
  for ($p578i = 0; $p578i -lt $p578lines.Count; $p578i++) {
    $p578newlist += $p578lines[$p578i]
    if (($p578hasinc -eq 0) -and ($p578incdone -eq 0) -and ($p578lines[$p578i] -match '#include')) { $p578newlist += '#include "Game/PHI_GameState_Fixed.h"'; $p578incdone = 1 }
    if ($p578i -eq $p578brace) { $p578newlist += '  GameStateClass = APHI_GameState_Fixed::StaticClass();' }
  }
  Set-Content -Path $p578modecpp -Value $p578newlist -Encoding UTF8
  $p578patched = 1
  Write-Output 'PATCH578 GAMESTATE ADD OK'
  Write-Output 'NEW578 GameStateClass = APHI_GameState_Fixed::StaticClass();'
} else { Write-Output 'PATCH578 NO CTOR BODY UNWIRED' }
$p578text = Get-Content $p578modecpp -Raw -ErrorAction SilentlyContinue
$p578open = @([regex]::Matches($p578text, '\{')).Count
$p578close = @([regex]::Matches($p578text, '\}')).Count
$p578popen = @([regex]::Matches($p578text, '\(')).Count
$p578pclose = @([regex]::Matches($p578text, '\)')).Count
Write-Output ('BRACE578 OPEN ' + $p578open + ' CLOSE ' + $p578close)
Write-Output ('PAREN578 OPEN ' + $p578popen + ' CLOSE ' + $p578pclose)
if ($p578patched -eq 1) {
  $p578buildbat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
  $p578uproj = 'D:\VEIL-OMNI\VEIL.uproject'
  $p578log = 'D:\VEIL-OMNI\Saved\build578.log'
  & $p578buildbat VEILEditor Win64 Development -Project="$p578uproj" -WaitMutex -NoHotReload *> "$p578log"
  $p578ok = @(Select-String -Path $p578log -Pattern 'Succeeded' -ErrorAction SilentlyContinue | Select-Object -First 5)
  if ($p578ok.Count -gt 0) { Write-Output 'BUILD578 Result: Succeeded' } else { Write-Output 'BUILD578 Result: Failed' }
  Write-Output ('LOG578 ' + $p578log)
} else { Write-Output 'BUILD578 SKIPPED UNWIRED' }
Write-Output 'PHI P578 VERDICT: GAMESTATE FIXED WIRING ADD ABOVE'
Write-Output 'JOB 578 DONE'
```
