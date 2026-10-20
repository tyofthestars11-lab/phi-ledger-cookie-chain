# PHI FIX v2 — G-ASSIST x TYREE — STREAMING: the screen MOVES, nothing sits silent.
# G-Assist's check gives the model 24 s to answer. Cold = too slow. The model stays
# untouched and stays HOT; the warm-up streams token-by-token so progress is visible.
$ErrorActionPreference = 'SilentlyContinue'
setx OLLAMA_KEEP_ALIVE "24h" | Out-Null
$env:OLLAMA_KEEP_ALIVE = "24h"
try { Invoke-RestMethod 'http://localhost:11434/api/tags' -TimeoutSec 3 | Out-Null; "Ollama server: UP" }
catch { "Ollama server down - starting it now"; Start-Process "$env:LOCALAPPDATA\Programs\Ollama\ollama app.exe"; Start-Sleep -Seconds 8 }
$body = '{"model":"tyree","messages":[{"role":"user","content":"Say phi"}],"stream":true,"keep_alive":-1,"options":{"num_predict":8}}'
"=== STAGE 1: load + first answer (tokens stream live below - watch them move) ==="
$t0 = Get-Date
curl.exe -sN --max-time 280 http://localhost:11434/api/chat -H "Content-Type: application/json" -d $body
"`nSTAGE 1 done in {0} s" -f [math]::Round(((Get-Date)-$t0).TotalSeconds,1)
"=== STAGE 2: the timed HOT answer (this is the G-Assist check) ==="
$t0 = Get-Date
curl.exe -sN --max-time 120 http://localhost:11434/api/chat -H "Content-Type: application/json" -d $body
$hot = [math]::Round(((Get-Date)-$t0).TotalSeconds,1)
"`nHOT answer total: {0} s (G-Assist window: 24 s)" -f $hot
ollama ps
if ($hot -lt 24) { "=== READY: in G-Assist pick 1 (tyree) again - it connects now ===" } else { "=== STILL OVER 24 s HOT - photo this screen ===" }
