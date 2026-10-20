# PHI STARFIELD COMPANION — AISS bypassed, no SFSE, Xbox build untouched — phi^2 = phi + 1
# Talk to Starfield's people through YOUR tyree model. Per-NPC memory on disk,
# personalities, spoken replies, live context from your screen via llava-phi3.
$ErrorActionPreference = 'SilentlyContinue'
Add-Type -AssemblyName System.Speech
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing
$voice = New-Object System.Speech.Synthesis.SpeechSynthesizer
$voice.Rate = 1
$memDir = "$env:USERPROFILE\phi-tools\companion"; New-Item -ItemType Directory -Path $memDir -Force | Out-Null
$npcs = @{
  'sarah'   = 'Sarah Morgan, chair of Constellation. Composed, dry wit, former UC Navy. You remember everything the player tells you.'
  'andreja' = 'Andreja of Constellation, from House Va''ruun. Intense, private, devout, loyal once trust is earned.'
  'barrett' = 'Barrett of Constellation. Brilliant, reckless, charming, always mid-adventure. Humor is your shield.'
  'sam'     = 'Sam Coe, Freestar Ranger turned Constellation. Easygoing drawl, principled, a father.'
  'vasco'   = 'VASCO, Constellation''s robot. Formal, literal, unfailingly polite. You address the player as Captain.'
}
function Load-Mem($n) { $f = "$memDir\$n.json"; if (Test-Path $f) { Get-Content $f -Raw | ConvertFrom-Json } else { @() } }
function Save-Mem($n, $m) { $m | ConvertTo-Json -Depth 4 | Set-Content "$memDir\$n.json" -Encoding UTF8 }
function Ask-Tyree($model, $msgs, $img) {
  $body = @{ model = $model; messages = $msgs; stream = $false }
  if ($img) { $body.messages[-1].images = @($img) }
  $r = Invoke-RestMethod -Uri 'http://localhost:11434/api/chat' -Method Post -ContentType 'application/json' -Body ($body | ConvertTo-Json -Depth 6)
  return $r.message.content
}
function See-Screen {
  $b = [System.Windows.Forms.Screen]::PrimaryScreen.Bounds
  $bmp = New-Object System.Drawing.Bitmap $b.Width, $b.Height
  ([System.Drawing.Graphics]::FromImage($bmp)).CopyFromScreen($b.Location, [System.Drawing.Point]::Empty, $b.Size)
  $ms = New-Object System.IO.MemoryStream; $bmp.Save($ms, [System.Drawing.Imaging.ImageFormat]::Jpeg)
  return [Convert]::ToBase64String($ms.ToArray())
}
"=== PHI STARFIELD COMPANION — your model, your NPCs, no SFSE ==="
"NPCs on the roster: $($npcs.Keys -join ', ')"
$name = (Read-Host 'Who are you talking to').ToLower()
if (-not $npcs.ContainsKey($name)) { "not on the roster — standing down"; return }
$mem = @(Load-Mem $name)
"context so far: {0} exchanges remembered" -f ($mem.Count / 2)
$scene = ''
while ($true) {
  $line = Read-Host "$name is listening (type, V = let her see your screen first, Q = quit)"
  if ($line -eq 'Q') { break }
  if ($line -eq 'V') { "reading your screen..."; $shot = See-Screen; $scene = Ask-Tyree 'llava-phi3:latest' @(@{ role='user'; content='In one sentence: where is this Starfield player and what is happening?' }) $shot; "scene read: $scene"; continue }
  $ctx = if ($scene) { " Live context: $scene" } else { '' }
  $msgs = @(@{ role='system'; content = $npcs[$name] + ' Stay in character. Answer in 1-3 sentences, spoken aloud.' + $ctx })
  $msgs += $mem | Select-Object -Last 12
  $msgs += @{ role='user'; content = $line }
  $reply = Ask-Tyree 'tyree:latest' $msgs $null
  "{0}: {1}" -f $name.ToUpper(), $reply
  $voice.SpeakAsync($reply) | Out-Null
  $mem += @{ role='user'; content = $line }; $mem += @{ role='assistant'; content = $reply }
  Save-Mem $name $mem
}
"memory saved — {0} remembers this conversation next time" -f $name
