# PHI STARFIELD COMPANION v2 — CONTROLLER + VOICE — AISS bypassed, no SFSE — phi^2 = phi + 1
# LB+RB together = talk | VIEW = she reads your screen | say "goodbye" = end.
# Your tyree model voices the NPC; memory persists per-NPC on disk; replies spoken.
$ErrorActionPreference = 'SilentlyContinue'
Add-Type -AssemblyName System.Speech
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing
$voice = New-Object System.Speech.Synthesis.SpeechSynthesizer; $voice.Rate = 1
$rec = New-Object System.Speech.Recognition.SpeechRecognitionEngine
$rec.LoadGrammar((New-Object System.Speech.Recognition.DictationGrammar))
$rec.SetInputToDefaultAudioDevice()
Add-Type -TypeDefinition @"
using System; using System.Runtime.InteropServices;
public struct XState { public uint dwPacketNumber; public ushort wButtons; public byte bLT, bRT; public short sLX, sLY, sRX, sRY; }
public static class Pad { [DllImport("xinput1_4.dll")] public static extern int XInputGetState(int i, ref XState s); }
"@
function PadButtons { $s = New-Object XState; if ([Pad]::XInputGetState(0, [ref]$s) -eq 0) { return $s.wButtons } return 0 }
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
  (Invoke-RestMethod -Uri 'http://localhost:11434/api/chat' -Method Post -ContentType 'application/json' -Body ($body | ConvertTo-Json -Depth 6)).message.content
}
function See-Screen {
  $b = [System.Windows.Forms.Screen]::PrimaryScreen.Bounds
  $bmp = New-Object System.Drawing.Bitmap $b.Width, $b.Height
  ([System.Drawing.Graphics]::FromImage($bmp)).CopyFromScreen($b.Location, [System.Drawing.Point]::Empty, $b.Size)
  $ms = New-Object System.IO.MemoryStream; $bmp.Save($ms, [System.Drawing.Imaging.ImageFormat]::Jpeg)
  [Convert]::ToBase64String($ms.ToArray())
}
function Speak($t) { $voice.Speak($t) }
"=== COMPANION v2 — controller + voice ==="
"Say a name to begin: $($npcs.Keys -join ', ') — or type it."
$name = $null
while (-not $name) {
  $r = $rec.Recognize(10)
  if ($r -and $npcs.ContainsKey($r.Text.Trim().ToLower())) { $name = $r.Text.Trim().ToLower() }
  else { $t = Read-Host 'name'; if ($npcs.ContainsKey($t.ToLower())) { $name = $t.ToLower() } }
}
$mem = @(Load-Mem $name)
Speak "This is $name. I remember $($mem.Count / 2) exchanges with you. Hold both bumpers and talk to me."
"talking with $name — LB+RB = talk | VIEW = scene read | say goodbye = end"
$scene = ''; $wasDown = $false
while ($true) {
  $b = PadButtons
  $talk = ($b -band 0x0300) -eq 0x0300
  if ($b -band 0x0020) { "reading your screen..."; $scene = Ask-Tyree 'llava-phi3:latest' @(@{ role='user'; content='In one sentence: where is this Starfield player and what is happening?' }) (See-Screen); "scene: $scene"; Speak "I see. $scene"; Start-Sleep -Milliseconds 800 }
  if ($talk -and -not $wasDown) {
    [Console]::Beep(880, 120)
    $heard = $rec.Recognize(15)
    if ($heard) {
      $line = $heard.Text
      "you: $line"
      if ($line -match 'goodbye|stop talking') { break }
      $ctx = if ($scene) { " Live context: $scene" } else { '' }
      $msgs = @(@{ role='system'; content = $npcs[$name] + ' Stay in character. Answer in 1-3 sentences, spoken aloud.' + $ctx })
      $msgs += $mem | Select-Object -Last 12
      $msgs += @{ role='user'; content = $line }
      $reply = Ask-Tyree 'tyree:latest' $msgs $null
      "{0}: {1}" -f $name.ToUpper(), $reply
      Speak $reply
      $mem += @{ role='user'; content = $line }; $mem += @{ role='assistant'; content = $reply }
      Save-Mem $name $mem
    }
  }
  $wasDown = $talk
  Start-Sleep -Milliseconds 120
}
"memory saved — $name remembers"
