<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Add-Type -AssemblyName System.Speech
$synth = New-Object System.Speech.Synthesis.SpeechSynthesizer
Write-Output "=== INSTALLED VOICES ==="
$synth.GetInstalledVoices() | ForEach-Object { $_.VoiceInfo.Name }
function Pick-Voice($want) {
    foreach ($v in $synth.GetInstalledVoices()) {
        if ($v.VoiceInfo.Name -like "*$want*") { $synth.SelectVoice($v.VoiceInfo.Name); return $v.VoiceInfo.Name }
    }
    return "default"
}
$jobs = @(
    @{ Csv = "C:\Users\Admin\phi-vault\veil\VEIL\Data\dialogue.csv"; Out = "C:\Users\Admin\phi-vault\veil\voice\VEIL"; Proj = "D:\VEIL\Data\Voice" },
    @{ Csv = "C:\Users\Admin\phi-vault\veil\OMNI\Data\dialogue.csv"; Out = "C:\Users\Admin\phi-vault\veil\voice\OMNI"; Proj = "D:\OMNI-UE\Data\Voice" }
)
foreach ($j in $jobs) {
    New-Item -ItemType Directory -Force -Path $j.Out | Out-Null
    New-Item -ItemType Directory -Force -Path $j.Proj | Out-Null
    $rows = Import-Csv $j.Csv
    foreach ($r in $rows) {
        $spk = $r.Speaker
        if ($spk -eq "SEER" -or $spk -eq "NARRATOR") { $vn = Pick-Voice "Zira"; $synth.Rate = -1 }
        elseif ($spk -eq "WARDEN PRIME") { $vn = Pick-Voice "David"; $synth.Rate = -2 }
        elseif ($spk -eq "CARTOGRAPHER") { $vn = Pick-Voice "David"; $synth.Rate = -1 }
        else { $vn = Pick-Voice "David"; $synth.Rate = 0 }
        $wav = Join-Path $j.Out $r.VoiceFile
        $synth.SetOutputToWaveFile($wav)
        $synth.Speak($r.Line) | Out-Null
        $synth.SetOutputToNull()
        Copy-Item $wav (Join-Path $j.Proj $r.VoiceFile) -Force
        Write-Output "SPOKE $($r.'---') [$spk via $vn] -> $($r.VoiceFile)"
    }
}
$UE = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UE "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\VEIL\Scripts\import_voice.py" -unattended -nopause -nosplash -abslog="D:\VEIL\Saved\voice-import.log" 2>&1 | Out-Null
Write-Output "=== VEIL VOICE IMPORT ==="
Select-String -Path "D:\VEIL\Saved\voice-import.log" -Pattern "\[VOICE\]" | Select-Object -Last 4 | ForEach-Object { $_.Line }
& $UE "D:\OMNI-UE\OMNI.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\import_voice.py" -unattended -nopause -nosplash -abslog="D:\OMNI-UE\Saved\voice-import.log" 2>&1 | Out-Null
Write-Output "=== OMNI VOICE IMPORT ==="
Select-String -Path "D:\OMNI-UE\Saved\voice-import.log" -Pattern "\[VOICE\]" | Select-Object -Last 4 | ForEach-Object { $_.Line }
Write-Output "=== JOB 114 DONE ==="
```
