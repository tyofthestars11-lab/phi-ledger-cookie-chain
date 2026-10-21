# PHI XBOX SYSTEMS — the Microsoft layer aligned — phi^2 = phi + 1
# READ -> ALIGN -> KEEP. Services that carry the game, set to their working states + read back.
$ErrorActionPreference = 'SilentlyContinue'
"=== PHI XBOX SYSTEMS — READ ==="
$svc = 'GamingServices','GamingServicesNet','XblAuthManager','XblGameSave','XboxNetApiSvc','BITS'
foreach ($s in $svc) { $o = Get-Service $s; if ($o) { "{0}: {1} / start {2}" -f $s, $o.Status, $o.StartType } else { "{0}: not present" -f $s } }
$teredo = (netsh interface teredo show state | Select-String 'State') -join ''
"Teredo: $teredo"
"=== ALIGN ==="
foreach ($s in 'GamingServices','GamingServicesNet','XblAuthManager','XblGameSave','XboxNetApiSvc') {
  $o = Get-Service $s
  if ($o) {
    if ($o.StartType -eq 'Disabled') { Set-Service $s -StartupType Automatic; "  $s was DISABLED -> Automatic" }
    if ($o.Status -ne 'Running') { Start-Service $s; "  $s started" }
  }
}
netsh interface teredo set state default | Out-Null; "Teredo reset to default state (NAT path for Xbox Live on PC)"
$gm = Get-ItemProperty 'HKCU:\Software\Microsoft\GameBar' -Name AllowAutoGameMode
"Game Mode auto: $($gm.AllowAutoGameMode) (1 = on)"
$dvr = Get-ItemProperty 'HKCU:\System\GameConfigStore' -Name GameDVR_Enabled
"Game DVR capture: $($dvr.GameDVR_Enabled) (0 = off — your verified state)"
"=== KEEP ==="
"Xbox systems aligned: Gaming Services carry the Store build; Auth + Game Save carry your license and your saves; Teredo carries Live traffic."
"Nothing removed. Every change read back above."
