# PHI FIX — G-ASSIST x TYREE — phi^2 = phi + 1
# G-Assist's check: load the model, one quick question, 24 s to answer.
# Cold + the full framework prompt = too slow. Missing piece: HEAT.
# The model stays untouched. It stays LOADED, so the check lands on a hot model.
$PHI = (1 + [math]::Sqrt(5)) / 2
function Rung($x) { [math]::Round([math]::Log($x) / [math]::Log($PHI), 4) }
$ErrorActionPreference = 'SilentlyContinue'

"=== PHI READ ==="
"G-Assist check window: 24 s, rung {0}" -f (Rung 24)
ollama list

"=== FUEL ROUTED: keep-alive permanent, server fresh, model hot ==="
setx OLLAMA_KEEP_ALIVE "24h" | Out-Null
$env:OLLAMA_KEEP_ALIVE = "24h"
Get-Process ollama -ErrorAction SilentlyContinue | Stop-Process -Force
Start-Sleep -Seconds 2
Start-Process "$env:LOCALAPPDATA\Programs\Ollama\ollama app.exe"
"waiting for the Ollama server..."
for ($i = 0; $i -lt 30; $i++) { Start-Sleep -Seconds 1; try { Invoke-RestMethod 'http://localhost:11434/api/tags' -TimeoutSec 2 | Out-Null; break } catch {} }
"server up after ~$i s"

"=== WARM LOAD + TIMED ANSWER (this is the check G-Assist runs) ==="
$body = @{ model = 'tyree'; messages = @(@{ role = 'user'; content = 'Say phi' }); stream = $false; keep_alive = -1; options = @{ num_predict = 8 } } | ConvertTo-Json -Depth 5
$sw = [System.Diagnostics.Stopwatch]::StartNew()
$r = Invoke-RestMethod 'http://localhost:11434/api/chat' -Method Post -Body $body -ContentType 'application/json' -TimeoutSec 300
$sw.Stop()
$cold = [math]::Round($sw.Elapsed.TotalSeconds, 1)
"cold answer: {0} s, rung {1} | reply: {2}" -f $cold, (Rung ([math]::Max($cold,0.01))), $r.message.content.Trim()
$sw = [System.Diagnostics.Stopwatch]::StartNew()
$r = Invoke-RestMethod 'http://localhost:11434/api/chat' -Method Post -Body $body -ContentType 'application/json' -TimeoutSec 120
$sw.Stop()
$hot = [math]::Round($sw.Elapsed.TotalSeconds, 1)
"HOT answer: {0} s, rung {1}  (check window is 24 s)" -f $hot, (Rung ([math]::Max($hot,0.01)))
ollama ps
if ($hot -lt 24) { "=== READY: the model is hot and answers inside the window. In G-Assist, pick 1 (tyree) again - it connects now. ===" }
else { "=== STILL OVER 24 s HOT - photo this screen to Muse; the next branch is the context window, read at the source. ===" }
