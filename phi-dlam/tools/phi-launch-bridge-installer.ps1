# STARFIELD PHI LAUNCH BRIDGE INSTALLER — summon word: starphi — desktop icon: STARFIELD PHI
$tools = "$env:USERPROFILE\phi-tools"; New-Item -ItemType Directory -Path $tools -Force | Out-Null
Copy-Item $PSScriptRoot\phi-launch-bridge.ps1 "$tools\phi-launch-bridge.ps1" -Force
Set-Content -Path "$tools\starphi.cmd" -Value '@powershell.exe -ExecutionPolicy Bypass -File "%USERPROFILE%\phi-tools\phi-launch-bridge.ps1"' -Encoding ASCII
$userPath = [Environment]::GetEnvironmentVariable('Path', 'User')
if ($userPath -notlike "*$tools*") { [Environment]::SetEnvironmentVariable('Path', "$userPath;$tools", 'User'); "summon word registered: starphi" }
$ws = New-Object -ComObject WScript.Shell
$lnk = $ws.CreateShortcut("$env:USERPROFILE\Desktop\STARFIELD PHI.lnk")
$lnk.TargetPath = 'powershell.exe'; $lnk.Arguments = "-ExecutionPolicy Bypass -File `"$tools\phi-launch-bridge.ps1`""; $lnk.Save()
"STARFIELD PHI bridge installed — desktop icon + the word: starphi"
