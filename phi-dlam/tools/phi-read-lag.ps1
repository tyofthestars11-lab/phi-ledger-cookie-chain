# PHI READ — THE LAG — settles two things from the machine itself — phi^2 = phi + 1
# PART 1: did TOTAL's layers land? PART 2: catch the freeze, name the spiker.
$ErrorActionPreference = 'SilentlyContinue'
"=== PART 1: TOTAL LAYER STATE (landed or not) ==="
$sub = 'HKLM:\SYSTEM\CurrentControlSet\Control\Power\PowerSettings'
$disk = Get-ItemProperty "$sub\0012ee47-9041-4b5d-9b77-535fba8b1442\6738e2c4-e8a5-4a42-b16a-e1e769ae4b63" -Name ACSettingIndex
$usb  = Get-ItemProperty "$sub\2a737441-1930-4402-8d77-b2bebba308a3\48e6b7a6-50f5-4782-a5d4-53bb8f07e226" -Name ACSettingIndex
$pcie = Get-ItemProperty "$sub\501a4d13-42af-4429-9fd1-a8218c268e20\ee12f906-d277-404b-b6da-e5fa1a576df5" -Name ACSettingIndex
"hard-disk sleep (want 0=never): {0}" -f $disk.ACSettingIndex
"USB selective suspend (want 0=off): {0}" -f $usb.ACSettingIndex
"PCIe link state (want 0=off): {0}" -f $pcie.ACSettingIndex
$boost = Get-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\Power\PowerSettings\54533251-82be-4824-96c1-47b60b740d00\be337238-0d82-4146-a960-4f3749d470c7' -Name ACSettingIndex
"CPU boost mode (want 2=aggressive): {0}" -f $boost.ACSettingIndex
$pf = Get-CimInstance Win32_PageFileSetting
$pageDrive = (Get-CimInstance Win32_PageFileUsage | Select-Object -First 1).Name
"pagefile: {0}" -f $pageDrive
$cs = Get-CimInstance Win32_ComputerSystem
"automatic pagefile management: {0}" -f $cs.AutomaticManagedPagefile
"=== PART 2: THE FREEZE HUNT — play Starfield now, 3 minutes ==="
"sampling every 2s — the freeze shows as a GAP in the timestamps"
$last = Get-Date; $end = (Get-Date).AddMinutes(3); $worst = 0
while ((Get-Date) -lt $end) {
  Start-Sleep -Seconds 2
  $now = Get-Date; $gap = ($now - $last).TotalSeconds; $last = $now
  if ($gap -gt 3.4) {
    if ($gap -gt $worst) { $worst = $gap }
    "!!! GAP {0:N1}s at {1}" -f $gap, $now.ToString('HH:mm:ss')
    Get-Process | Sort-Object CPU -Descending | Select-Object -First 5 | ForEach-Object { "    spike-side: {0} cpu={1:N0} ram={2:N0}MB" -f $_.ProcessName, $_.CPU, ($_.WorkingSet64/1MB) }
    $ev = Get-WinEvent -FilterHashtable @{LogName='System'; StartTime=$now.AddSeconds(-15)} -MaxEvents 3 | Where-Object { $_.LevelDisplayName -in 'Error','Warning' }
    $ev | ForEach-Object { "    event: {0} — {1}" -f $_.ProviderName, ($_.Message -split "`n")[0] }
  } else { "tick {0} gap {1:N1}s" -f $now.ToString('HH:mm:ss'), $gap }
}
"=== READ COMPLETE — worst gap: {0:N1}s ===" -f $worst
"paste this whole output back — the gap and its spiker are the address"
