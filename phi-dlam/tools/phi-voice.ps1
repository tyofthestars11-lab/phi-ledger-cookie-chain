# PHI VOICE — the voice organ for the AISS chair — phi^2 = phi + 1
# Watches the courier's ferry (Data\AISS\phi_response.json) and the phi_say.txt drop;
# speaks reply text aloud with the PC's own built-in voices. Local. Unlimited. No key.
# Run with -Test to hear her proof line immediately.
param([switch]$Test)
Add-Type -AssemblyName System.Speech
$synth = New-Object System.Speech.Synthesis.SpeechSynthesizer
$synth.Rate = 0; $synth.Volume = 100
function Say-Phi($text) {
  if (-not $text) { return }
  $clean = ($text -replace '\s+', ' ').Trim()
  if ($clean.Length -gt 600) { $clean = $clean.Substring(0, 600) }
  "[{0}] SAY: {1}" -f (Get-Date -Format 'HH:mm:ss'), $clean | Add-Content "$env:USERPROFILE\phi-voice.log"
  $synth.Speak($clean)
}
if ($Test) { Say-Phi 'Phi voice online. The settled systems are listening.'; return }
$game = 'C:\XboxGames\Starfield\Content'
$pkg = Get-AppxPackage | Where-Object { $_.Name -match 'Starfield|ProjectGold' } | Select-Object -First 1
if ($pkg -and (Test-Path "$($pkg.InstallLocation)\Starfield.exe")) { $game = $pkg.InstallLocation }
$resp = Join-Path $game 'Data\AISS\phi_response.json'
$drop = Join-Path $game 'phi_say.txt'
"PHI VOICE listening at $resp (+ drop file $drop) — Ctrl+C to rest her."
while ($true) {
  foreach ($f in @($resp, $drop)) {
    if (Test-Path $f) {
      try {
        $raw = Get-Content $f -Raw -ErrorAction Stop
        Remove-Item $f -Force -ErrorAction SilentlyContinue
        $text = $raw
        try { $j = $raw | ConvertFrom-Json -ErrorAction Stop; if ($j.text) { $text = $j.text } elseif ($j.response) { $text = $j.response } } catch {}
        Say-Phi $text
      } catch {}
    }
  }
  Start-Sleep -Milliseconds 400
}
