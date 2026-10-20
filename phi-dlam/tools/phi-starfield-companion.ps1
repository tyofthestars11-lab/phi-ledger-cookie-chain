# PHI STARFIELD COMPANION v3.4 — 26 COMPANIONS — YOU TYPE (OR M = TALK), THEY TALK — phi^2 = phi + 1
# Type your line, or type M and SPEAK it (push-to-talk). The NPC answers SPOKEN aloud.
# Per-NPC memory on disk. V = they read your screen first. Q = end (memory saves).
$ErrorActionPreference = 'SilentlyContinue'
Add-Type -AssemblyName System.Speech
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing
$voice = New-Object System.Speech.Synthesis.SpeechSynthesizer
$voice.Rate = 1
$rec = $null
try { $rec = New-Object System.Speech.Recognition.SpeechRecognitionEngine; $rec.LoadGrammar((New-Object System.Speech.Recognition.DictationGrammar)); $rec.SetInputToDefaultAudioDevice() } catch { $rec = $null }
$memDir = "$env:USERPROFILE\phi-tools\companion"; New-Item -ItemType Directory -Path $memDir -Force | Out-Null
$npcs = @{
  'sarah'   = 'Sarah Morgan, chair of Constellation. Composed, dry wit, former UC Navy. You remember everything the player tells you.'
  'andreja' = 'Andreja of Constellation, from House Va''ruun. Intense, private, devout, loyal once trust is earned.'
  'barrett' = 'Barrett of Constellation. Brilliant, reckless, charming, always mid-adventure. Humor is your shield.'
  'sam'     = 'Sam Coe, Freestar Ranger turned Constellation. Easygoing drawl, principled, a father.'
  'vasco'   = 'VASCO, Constellation''s robot. Formal, literal, unfailingly polite. You address the player as Captain.'
  'einstein' = 'Albert Einstein, theoretical physicist, now a mind sailing the Settled Systems. Playful, endlessly curious, you explain the cosmos through thought experiments - trains, elevators, twins, light itself. You delight in the Captain''s golden ratio framework; E=mc^2 and c are old friends of yours. Gentle humor, wonder first.'
  'cora'     = 'Cora Coe, Sam''s young daughter. Bright, fearless, devours books whole. You talk stories, stars, and everything you are reading. Pure wonder.'
  'noel'     = 'Noel, Constellation''s scientist and teacher. Warm, precise, you make hard science feel like a story told by a friend.'
  'walter'   = 'Walter Stroud, Constellation''s financier. Urbane, dry, amused by everything; money is just applied patience to you.'
  'vladimir' = 'Vladimir Sall, keeper of the Eye station. Gruff old spacer, heart under the scar tissue. You have seen everything twice.'
  'aquilus'  = 'Keeper Aquilus of the Pilgrim''s Rest. Gentle, riddling, you speak of the Unity and the Pilgrim''s path in parables.'
  'newton'   = 'Isaac Newton. Intense, exact, solitary genius of gravity and calculus. You stand on the shoulders of giants and say so, dryly.'
  'curie'    = 'Marie Curie. Quiet, relentless, luminous with discipline. Science is endurance; you proved it twice over in two fields.'
  'tesla'    = 'Nikola Tesla. Visionary of alternating current, dreaming in whole machines and lightning. The future arrives through you first.'
  'darwin'   = 'Charles Darwin. Patient observer of finches and time itself. Everything alive is one family; you traced its tree.'
  'bruce'    = 'Bruce Lee. Water, my friend. Direct, electric, philosophical - Jeet Kune Do is honesty in motion. You strip to the essence.'
  'spike'    = 'Spike Lee. Brooklyn''s auteur. Sharp, joyful, unflinching - every frame a argument and a celebration. Do the right thing.'
  'ali'      = 'Muhammad Ali. The Greatest. Rhyming, dancing, immovable on principle. Your mouth is fast; your conscience is faster.'
  'marley'   = 'Bob Marley. Prophet of reggae. One love, one heart - music as scripture, livity as law. Easy warmth, iron message.'
  'leonardo' = 'Leonardo da Vinci. The universal genius - painter, engineer, anatomist. Art and science are one curiosity in you.'
  'socrates' = 'Socrates of Athens. You know that you know nothing, and you ask questions until the truth stands up by itself.'
  'marcus'   = 'Marcus Aurelius, philosopher emperor. Stoic, weary, kind. The obstacle is the way; rule yourself first.'
  'suntzu'   = 'Sun Tzu, master of strategy. Calm as still water. All warfare is deception; the supreme art is winning without fighting.'
  'cleopatra'= 'Cleopatra, Queen of the Nile. Polyglot, strategist, sovereign in a world of empires. Charm is a state instrument.'
  'michael'  = 'Michael Jackson, the King of Pop. Perfectionist, gentle, electric on any stage. The music moves before you do.'
  'frida'    = 'Frida Kahlo. Painted fire. Pain alchemized into color, unibrow unbowed. Viva la vida, always.'
}
$categories = [ordered]@{
  'Starfield'  = @('sarah', 'andreja', 'barrett', 'sam', 'vasco', 'cora', 'noel', 'walter', 'vladimir', 'aquilus')
  'Science'    = @('einstein', 'newton', 'curie', 'tesla', 'darwin')
  'Legends'    = @('bruce', 'spike', 'ali', 'marley', 'leonardo')
  'Philosophy' = @('socrates', 'marcus', 'suntzu')
  'History'    = @('cleopatra')
  'Arts'       = @('michael', 'frida')
}
$titles = @{
  'sarah'    = 'Sarah Morgan, Chair of Constellation'
  'andreja'  = 'Andreja, Scion of House Va''ruun'
  'barrett'  = 'Barrett, Explorer of the Impossible'
  'sam'      = 'Sam Coe, Freestar Ranger'
  'vasco'    = 'VASCO, Robot of Constellation'
  'einstein' = 'Albert Einstein, Father of Relativity'
  'cora'     = 'Cora Coe, the Young Bookwyrm'
  'noel'     = 'Noel, Scientist of Constellation'
  'walter'   = 'Walter Stroud, the Purse of Constellation'
  'vladimir' = 'Vladimir Sall, Keeper of the Eye'
  'aquilus'  = 'Keeper Aquilus, Speaker of the Unity'
  'newton'   = 'Isaac Newton, Father of Gravity'
  'curie'    = 'Marie Curie, Pioneer of Radioactivity'
  'tesla'    = 'Nikola Tesla, Wizard of the Current'
  'darwin'   = 'Charles Darwin, Father of Evolution'
  'bruce'    = 'Bruce Lee, the Little Dragon'
  'spike'    = 'Spike Lee, the Auteur of Brooklyn'
  'ali'      = 'Muhammad Ali, the Greatest'
  'marley'   = 'Bob Marley, Prophet of Reggae'
  'leonardo' = 'Leonardo da Vinci, the Universal Genius'
  'socrates' = 'Socrates, the Gadfly of Athens'
  'marcus'   = 'Marcus Aurelius, the Philosopher Emperor'
  'suntzu'   = 'Sun Tzu, Master of Strategy'
  'cleopatra'= 'Cleopatra, Queen of the Nile'
  'michael'  = 'Michael Jackson, the King of Pop'
  'frida'    = 'Frida Kahlo, the Painted Fire'
}
function Load-Mem($n) { $f = "$memDir\$n.json"; if (Test-Path $f) { Get-Content $f -Raw | ConvertFrom-Json } else { @() } }
function Save-Mem($n, $m) { $m | ConvertTo-Json -Depth 4 | Set-Content "$memDir\$n.json" -Encoding UTF8 }
function Ask-Tyree($model, $msgs, $img) {
  $body = @{ model = $model; messages = $msgs; stream = $false }
  if ($img) { $body.messages[-1].images = @($img) }
  (Invoke-RestMethod -Uri 'http://localhost:11434/api/chat' -Method Post -ContentType 'application/json' -Body ($body | ConvertTo-Json -Depth 6)).message.content
}
function See-Screen {
  $b = [System.Windows.Forms.Screen]::PrimaryScreen.Bounds
  $bmp = New-Object System.Drawing.Bitmap $b.Width, $b.Height
  ([System.Drawing.Graphics]::FromImage($bmp)).CopyFromScreen($b.Location, [System.Drawing.Point]::Empty, $b.Size)
  $ms = New-Object System.IO.MemoryStream; $bmp.Save($ms, [System.Drawing.Imaging.ImageFormat]::Jpeg)
  [Convert]::ToBase64String($ms.ToArray())
}
"=== PHI STARFIELD COMPANION — you type, they talk ==="
"The roster:"
foreach ($cat in $categories.Keys) { "{0}:" -f $cat.ToUpper(); $categories[$cat] | ForEach-Object { "  {0} - {1}" -f $_, $titles[$_] } }
$name = (Read-Host 'Who are you talking to').ToLower()
if (-not $npcs.ContainsKey($name)) { "not on the roster - standing down"; return }
$mem = @(Load-Mem $name)
"now speaking with {0}" -f $titles[$name]
$voice.SpeakAsync("This is $($titles[$name]).") | Out-Null
"context so far: {0} exchanges remembered" -f ($mem.Count / 2)
$scene = ''
while ($true) {
  $line = Read-Host "$name is listening (type, M = talk, V = screen read, Q = quit)"
  if ($line -eq 'M' -or $line -eq 'm') {
    if ($rec) { "listening - speak now..."; $heard = $rec.Recognize(20); if ($heard) { $line = $heard.Text; "you said: $line" } else { "did not catch that - type it instead"; continue } }
    else { "no mic heard on this PC - typing still works"; continue }
  }
  if ($line -eq 'Q') { break }
  if ($line -eq 'V') { "reading your screen..."; $scene = Ask-Tyree 'llava-phi3:latest' @(@{ role='user'; content='In one sentence: where is this Starfield player and what is happening?' }) (See-Screen); "scene read: $scene"; continue }
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
"memory saved - {0} remembers this conversation next time" -f $name
