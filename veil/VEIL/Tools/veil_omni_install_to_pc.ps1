# VEIL OMNI - install coded game into Tyree's stuff, PC side.
# Run ONCE in Windows PowerShell, in the git clone (NOT in D:\VEIL-OMNI):
#   PS C:\Users\Admin> cd C:\Users\Admin\phi-ledger-cookie-chain
#   PS ...\phi-ledger-cookie-chain> git pull origin main
#   PS ...\phi-ledger-cookie-chain> .\veil\VEIL\Tools\veil_omni_install_to_pc.ps1
# What it does:
#  - Copies Source, Config, Tools, Data from veil\VEIL into D:\VEIL-OMNI
#    (same relative paths, so Source\VEIL\Private\... lands exactly).
#  - Backs up D:\VEIL-OMNI\Source and Config to D:\VEIL-OMNI\Backup_veil_omni_install_<date> first.
#  - NEVER overwrites D:\VEIL-OMNI\Content (maps, Fab assets, MetaHuman,
#    Paragon trees stay exactly as they are on PC).
#  - NEVER packages, cooks, or deletes the game. Packaging gate stands:
#    no package until 100% done in project.
#  - Prints every copied file, then prints the next editor steps.
#  - Does NOT register the project in Epic Launcher My Projects by
#    itself: opening VEIL.uproject (5.8.4, Windows x86) in the launcher
#    after this copy is the register step, and a previous Open did NOT
#    register it - if My Projects still shows empty after this, show
#    Muse a photo of Epic Launcher > Unreal Engine > My Projects.
$ErrorActionPreference = "Stop"
$RepoVeil = Join-Path $PSScriptRoot ".."
$Dest = "D:\VEIL-OMNI"
if (-not (Test-Path $Dest)) { throw "D:\VEIL-OMNI not found. Stop - do not create a new project." }
$Stamp = Get-Date -Format "yyyy-MM-dd_HHmm"
$Backup = Join-Path $Dest ("Backup_veil_omni_install_" + $Stamp)
New-Item -ItemType Directory -Force -Path $Backup | Out-Null
foreach ($Dir in @("Source", "Config")) {
  $Src = Join-Path $RepoVeil $Dir
  $Dst = Join-Path $Dest $Dir
  if (Test-Path $Dst) { Copy-Item -Recurse -Force $Dst (Join-Path $Backup $Dir) }
  if (Test-Path $Src) { Copy-Item -Recurse -Force $Src $Dest }
}
foreach ($Dir in @("Tools", "Data")) {
  $Src = Join-Path $RepoVeil $Dir
  if (Test-Path $Src) { Copy-Item -Recurse -Force $Src $Dest }
}
Copy-Item -Force (Join-Path $RepoVeil "VEIL.uproject") $Dest
Copy-Item -Force (Join-Path $RepoVeil "VEIL_OMNI_INSTALL_MAP.md") $Dest
Copy-Item -Force (Join-Path $RepoVeil "VEIL_METAHUMAN.md") $Dest
Write-Output "VEIL OMNI INSTALLED TO PC"
Write-Output "Backup: $Backup"
Write-Output "Copied: Source, Config, Tools, Data, VEIL.uproject (5.8.4, MetaHuman + MetaHumanCharacter), VEIL_OMNI_INSTALL_MAP.md, VEIL_METAHUMAN.md"
Write-Output "NOT touched: D:\VEIL-OMNI\Content (maps + Fab assets stay)"
Write-Output "NEXT (editor, already-open): py Tools\whole_verify_goal.py in Output Log Cmd, then Tools\veil_omni_load_and_link.py, save, Play, photo + log are proof. No package."
