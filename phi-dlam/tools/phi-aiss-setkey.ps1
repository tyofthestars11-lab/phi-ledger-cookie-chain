# PHI AISS SETKEY — seats the OpenRouter key into AISS's config ON THIS MACHINE ONLY — phi^2 = phi + 1
# The key is typed/pasted at the prompt here, written to Data\AISS\config.json here, and never leaves this PC.
$ErrorActionPreference = 'SilentlyContinue'
"=== PHI AISS SETKEY ==="
$cands = @(
  'C:\XboxGames\Starfield\Content\Data\AISS\config.json',
  "$env:USERPROFILE\Documents\My Games\Starfield\Data\AISS\config.json"
)
$cfg = $cands | Where-Object { Test-Path $_ } | Select-Object -First 1
if (-not $cfg) { "AISS config.json not found in either Data seat — AISS data layer not deployed right now. Standing down."; return }
"config found: $cfg"
Copy-Item $cfg "$cfg.phi-backup" -Force
$key = Read-Host 'Paste the OpenRouter key (sk-or-...) — it is written only into this config, on this PC'
if (-not $key -or $key -notmatch '^sk-or-') { "that does not read as an OpenRouter key — nothing written"; return }
$raw = Get-Content $cfg -Raw
if ($raw -match '"[^"]*[Aa]pi[_-]?[Kk]ey"\s*:\s*"[^"]*"') {
  $new = [regex]::Replace($raw, '("[^"]*[Aa]pi[_-]?[Kk]ey"\s*:\s*")[^"]*"', "`${1}$key`"", 1)
  Set-Content $cfg $new -Encoding UTF8
  "key seated into the config's api-key field (backup at config.json.phi-backup)"
} else {
  Set-Content (Join-Path (Split-Path $cfg) 'phi-openrouter-key.txt') $key -Encoding ASCII
  "no api-key field matched in config.json — the key waits beside it as phi-openrouter-key.txt in the AISS folder, and the config stays untouched"
}
"=== DONE — provider chair filled. The game-side still waits on the bridge (the option renders; the native layer is the port's deep half). ==="
