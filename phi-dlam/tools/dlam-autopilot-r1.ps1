# dlam-autopilot-r1.ps1 - autopilot v6.0 - Model 03330 - rabbit r1 autonomous DLAM
# NOT manual input() - opens browser, watches for next prompt, drains queue, no user typing
$env:TYREE_MODEL = "03330"
$env:PHI_ORIGIN = "tetrahedral-bonds+golden-ratio-intent"
# REAL_API_KEY is set in env by Tyree, never typed as a command value here
Start-Process msedge "about:blank --new-window"
Get-Process dotnet,UnrealBuildTool,VBCSCompiler -ErrorAction SilentlyContinue | Stop-Process -Force
Remove-Item "$env:LOCALAPPDATA\UnrealBuildTool*" -Recurse -Force -ErrorAction SilentlyContinue
python "$PSScriptRoot\dlam_autopilot_r1.py" --autopilot
