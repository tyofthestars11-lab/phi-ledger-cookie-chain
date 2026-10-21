# STARFIELD PHI LAUNCHER INSTALLER — the desktop icon STARFIELD PHI now opens the talk-and-click window
$tools = "$env:USERPROFILE\phi-tools"; New-Item -ItemType Directory -Path $tools -Force | Out-Null
Copy-Item $PSScriptRoot\phi-starfield-launcher.ps1 "$tools\phi-starfield-launcher.ps1" -Force
$ws = New-Object -ComObject WScript.Shell
$lnk = $ws.CreateShortcut("$env:USERPROFILE\Desktop\STARFIELD PHI.lnk")
$lnk.TargetPath = 'powershell.exe'; $lnk.Arguments = "-ExecutionPolicy Bypass -WindowStyle Hidden -File `"$tools\phi-starfield-launcher.ps1`""; $lnk.Save()
"STARFIELD PHI launcher installed — say 'STARFIELD PHI' to G-Assist, or click the desktop icon. Buttons, no typing."
