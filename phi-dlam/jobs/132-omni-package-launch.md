<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
git pull --no-rebase --no-edit 2>&1 | Select-Object -Last 1
Write-Output "=== OMNI package launch (behind VEIL's cook) ==="
$uat = Get-Process -Name "AutomationTool", "RunUAT" -ErrorAction SilentlyContinue
$cooking = Get-CimInstance Win32_Process -Filter "Name='UnrealEditor-Cmd.exe' OR Name='AutomationTool.exe'" -ErrorAction SilentlyContinue | Where-Object { $_.CommandLine -match "BuildCookRun|cook" }
if (Test-Path "D:\Builds\VEIL-A7\Windows") { Write-Output "VEIL-A7 archive EXISTS: D:\Builds\VEIL-A7\Windows" } else { Write-Output "VEIL-A7 archive not present yet" }
if ($cooking) {
    Write-Output "A cook is still running - OMNI launch held this drain"
    $cooking | ForEach-Object { $_.CommandLine.Substring(0, [Math]::Min(160, $_.CommandLine.Length)) }
} else {
    Write-Output "No cook running - mutex free. Launching OMNI package in the open."
    $uatExe = "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat"
    $args = "BuildCookRun -project=`"D:\OMNI-UE\OMNI.uproject`" -noP4 -platform=Win64 -clientconfig=Development -cook -allmaps -build -stage -pak -archive -archivedirectory=`"D:\Builds\OMNI-A7`" -unattended"
    $p = Start-Process -FilePath $uatExe -ArgumentList $args -RedirectStandardOutput "D:\OMNI-UE\Saved\package-omni-a7.log" -RedirectStandardError "D:\OMNI-UE\Saved\package-omni-a7.err.log" -PassThru
    Write-Output "OMNI UAT launched pid=$($p.Id) - runs in the open past the job bound; archive target D:\Builds\OMNI-A7"
}
Write-Output "=== JOB 132 DONE ==="
```
