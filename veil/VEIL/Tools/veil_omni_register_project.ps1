# VEIL OMNI - register VEIL OMNI so Epic Launcher My Projects and Fab Add to Project can pick it.
# Run in Windows PowerShell, after pull + install, with Editor and Launcher CLOSED:
#   PS C:\Users\Admin\phi-ledger-cookie-chain> git pull origin main
#   PS C:\Users\Admin\phi-ledger-cookie-chain> .\veil\VEIL\Tools\veil_omni_install_to_pc.ps1
#   PS C:\Users\Admin> powershell -File C:\Users\Admin\phi-ledger-cookie-chain\veil\VEIL\Tools\veil_omni_register_project.ps1
#   (or, after install, the same file is also at D:\VEIL-OMNI\Tools\veil_omni_register_project.ps1)
#
# WHY THIS IS THE BLOCKER, IN PLAIN WORDS:
#   Epic Launcher My Projects does not scan your whole computer.
#   It only looks in folders listed in a setting called CreatedProjectPaths,
#   plus the default Documents\Unreal Projects folder.
#   VEIL OMNI lives at D:\VEIL-OMNI, which is on D:, not in Documents,
#   and D: was never in that list. So no matter how many times you
#   Browse and Open VEIL.uproject, the Launcher list stays empty.
#   This script adds D: to that list, in both places that use it.
#   Source for this setting, from Epic Developer Community Forum users
#   fixing the same empty My Projects problem:
#   - Launcher: %LocalAppData%\EpicGamesLauncher\Saved\Config\WindowsEditor\GameUserSettings.ini,
#     [Launcher] section, line CreatedProjectPaths=<folder that holds your project folders>
#     (one folder back from the folder with the .uproject file, so D: for D:\VEIL-OMNI).
#   - Editor Recent Projects: %LocalAppData%\UnrealEngine\5.8\Saved\Config\WindowsEditor\EditorSettings.ini,
#     same CreatedProjectPaths line.
#   UnrealVersionSelector is a different tool: it handles the .uproject
#   file association and the right-click Switch version / Generate
#   project files menu. It does NOT fill the My Projects scan list.
#   This script only CHECKS that UnrealVersionSelector exists, it does
#   not run it with any invented argument.
#
# WHAT THIS SCRIPT DOES, AND DOES NOT DO:
#   DOES: back up each config file before editing it, add CreatedProjectPaths=D:\
#         if it is not already there, check VEIL.uproject exists and show
#         its EngineAssociation, and print FOUND or MISSING for each
#         Content folder below (disk check only).
#   DOES NOT: move the project, delete Content, delete Saved, buy anything,
#              sign in to Epic or Fab, fix a login token, or use any key.
#   Fab login is a SEPARATE problem: EOS_Auth_InvalidRefreshToken,
#   Http-401 and II-E1003 are Launcher download / sign-in failures.
#   This script does not fix those. After registration, sign out and
#   sign back in to Epic in the Launcher, then retry Fab Add to Project.
#   If Fab still fails after a fresh sign-in, photo the Launcher error
#   - that is an Epic account / download problem, not VEIL code.
$ErrorActionPreference = "Continue"
$ProjectDir = "D:\VEIL-OMNI"
$ProjectFile = Join-Path $ProjectDir "VEIL.uproject"
$ParentFolder = "D:\"
Write-Output "VEIL OMNI REGISTER PROJECT - start"
Write-Output "Project file check:"
if (Test-Path $ProjectFile) {
  Write-Output "  VEIL.uproject -> FOUND at $ProjectFile"
  $Assoc = Select-String -Path $ProjectFile -Pattern "EngineAssociation" -SimpleMatch:$false | Select-Object -First 1
  if ($Assoc) { Write-Output "  $($Assoc.Line.Trim())" } else { Write-Output "  EngineAssociation line -> MISSING in VEIL.uproject" }
} else {
  Write-Output "  VEIL.uproject -> MISSING at $ProjectFile - STOP, do not create a new project, photo this output."
}
Write-Output "Content folders on disk (this is a disk check, not yet an editor Content Browser check):"
$ContentDir = Join-Path $ProjectDir "Content"
foreach ($Pattern in @("Paragon*", "SICKA*", "Lava*", "MetaHumans")) {
  $Hits = @()
  if (Test-Path $ContentDir) { $Hits = Get-ChildItem -Path $ContentDir -Directory -Filter $Pattern -ErrorAction SilentlyContinue }
  if ($Hits.Count -gt 0) {
    foreach ($Hit in $Hits) { Write-Output "  /Game/$($Hit.Name) -> FOUND at $($Hit.FullName)" }
  } else {
    Write-Output "  /Game/$Pattern -> MISSING in $ContentDir - not yet added by Fab Add to Project"
  }
}
$Uvs = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealVersionSelector.exe"
if (Test-Path $Uvs) { Write-Output "UnrealVersionSelector -> FOUND at $Uvs (check only, not run)" } else { Write-Output "UnrealVersionSelector -> MISSING at $Uvs (right-click Switch version may be missing, use the editor direct launch instead)" }
$Configs = @(
  (Join-Path $env:LOCALAPPDATA "EpicGamesLauncher\Saved\Config\WindowsEditor\GameUserSettings.ini"),
  (Join-Path $env:LOCALAPPDATA "UnrealEngine\5.8\Saved\Config\WindowsEditor\EditorSettings.ini")
)
foreach ($Config in $Configs) {
  Write-Output "Config: $Config"
  if (-not (Test-Path $Config)) {
    Write-Output "  -> MISSING - file not created yet on this PC. Open the Editor once, close it, then run this script again. Nothing was invented or created here."
    continue
  }
  $Stamp = Get-Date -Format "yyyy-MM-dd_HHmm"
  $Backup = "$Config.veil_backup_$Stamp"
  Copy-Item -Force $Config $Backup
  Write-Output "  Backup made: $Backup"
  $Text = Get-Content -Raw $Config
  if ($Text -match "(?m)^CreatedProjectPaths=.*D:\\") {
    Write-Output "  CreatedProjectPaths with D:\ -> FOUND already, no change made"
  } elseif ($Text -match "(?m)^CreatedProjectPaths=") {
    $NewText = $Text -replace "(?m)^CreatedProjectPaths=.*", "`$0`r`nCreatedProjectPaths=$ParentFolder"
    Set-Content -Path $Config -Value $NewText -Encoding utf8
    Write-Output "  CreatedProjectPaths=D:\ -> ADDED alongside the existing CreatedProjectPaths line"
  } elseif ($Config -like "*GameUserSettings.ini*" -and $Text -match "(?m)^\[Launcher\]") {
    $NewText = $Text -replace "(?m)^\[Launcher\]", "[Launcher]`r`nCreatedProjectPaths=$ParentFolder"
    Set-Content -Path $Config -Value $NewText -Encoding utf8
    Write-Output "  CreatedProjectPaths=D:\ -> ADDED under [Launcher]"
  } else {
    Add-Content -Path $Config -Value "CreatedProjectPaths=$ParentFolder" -Encoding utf8
    Write-Output "  CreatedProjectPaths=D:\ -> ADDED at end of file"
  }
}
Write-Output "VEIL OMNI REGISTER PROJECT - done"
Write-Output "NEXT, IN ORDER: close this window, open Epic Games Launcher, go to Unreal Engine > My Projects."
Write-Output "PHOTO 1 PROOF: My Projects now lists VEIL (not You do not have any projects yet)."
Write-Output "PHOTO 2 PROOF: Fab > My Library > an item > Add to Project > picker now lists VEIL OMNI to pick."
Write-Output "If PHOTO 1 still shows empty, photo it and photo the two config files lines starting CreatedProjectPaths - do not claim registration from this script alone."
Write-Output "NOT done by this script: Fab Add to Project itself, MetaHuman Verify/Package, editor save, Play. Those still need the editor, after a fresh Epic sign-in for Fab."
