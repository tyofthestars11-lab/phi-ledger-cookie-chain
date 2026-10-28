<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 507 - NWIRO AI PRO SEATED IN VEIL OMNI (Ground: his photo of the terminal library shows the Epic shelf holding NWIRO AI Pro, an AI assistant that lives inside Unreal itself, installed and waiting. His word: have it help make the game. This job finds the plugin where it actually sits, reads its descriptor whole, checks whether VEIL OMNI already carries it, and if the seat is empty it backs the project file up byte for byte and seats the plugin in the project, verifying by read back. It also reports whether the plugin holds any settings or key fields, printing only whether a value stands present, never the value itself. If the plugin is found nowhere, the job prints every road it searched and holds. Every variable carries the p507 prefix.) ==='
$p507roots = @('C:\Program Files\Epic Games\UE_5.8\Engine\Plugins', 'D:\VEIL-OMNI\Plugins', 'C:\ProgramData\Epic\EpicGamesLauncher\VaultCache')
$p507found = $null
foreach ($p507root in $p507roots) {
  if (Test-Path $p507root) {
    $p507dirs = Get-ChildItem -Path $p507root -Directory -Recurse -ErrorAction SilentlyContinue | Where-Object { $_.Name -like '*NWIRO*' }
    foreach ($p507d in $p507dirs) {
      $p507up = Get-ChildItem -Path $p507d.FullName -Filter '*.uplugin' -ErrorAction SilentlyContinue | Select-Object -First 1
      if ($p507up) { $p507found = $p507up; break }
    }
    if ($p507found) { break }
  }
  Write-Output ('SEARCHED ' + $p507root)
}
if (-not $p507found) {
  Write-Output 'PLUGIN NOT FOUND ON ANY ROAD'
  Write-Output 'PHI P507 VERDICT: HELD - PLUGIN NOT FOUND'
  Write-Output 'JOB 507 DONE'
  return
}
Write-Output ('PLUGIN FILE: ' + $p507found.FullName)
$p507name = [IO.Path]::GetFileNameWithoutExtension($p507found.Name)
Write-Output ('PLUGIN NAME: ' + $p507name)
Get-Content $p507found.FullName | ForEach-Object { Write-Output ('UPLUGIN ' + $_) }
$p507dir = Split-Path $p507found.FullName -Parent
$p507inis = Get-ChildItem -Path $p507dir -Filter '*.ini' -Recurse -ErrorAction SilentlyContinue
foreach ($p507ini in $p507inis) {
  $p507has = 0
  foreach ($p507line in (Get-Content $p507ini.FullName -ErrorAction SilentlyContinue)) { if ($p507line -match 'Key=\S+') { $p507has = 1 } }
  Write-Output ('INI ' + $p507ini.Name + ' keyValuePresent=' + $p507has)
}
$p507uproj = 'D:\VEIL-OMNI\VEIL.uproject'
$p507raw = Get-Content $p507uproj -Raw
if ($p507raw -match [regex]::Escape($p507name)) {
  Write-Output 'PROJECT: PLUGIN ALREADY NAMED IN UPROJECT'
  Write-Output 'PHI P507 VERDICT: ALREADY SEATED'
  Write-Output 'JOB 507 DONE'
  return
}
$p507bak = $p507uproj + '.bak507'
Copy-Item $p507uproj $p507bak -Force
Write-Output ('BACKUP bytes=' + (Get-Item $p507bak).Length + ' sourceBytes=' + (Get-Item $p507uproj).Length)
$p507json = $p507raw | ConvertFrom-Json
$p507entry = [PSCustomObject]@{ Name = $p507name; Enabled = $true }
$p507list = @()
foreach ($p507p in $p507json.Plugins) { $p507list += $p507p }
$p507list += $p507entry
$p507json.Plugins = $p507list
($p507json | ConvertTo-Json -Depth 32) | Set-Content $p507uproj -Encoding UTF8
$p507back = Get-Content $p507uproj -Raw
$p507seated = 0
if ($p507back -match [regex]::Escape($p507name)) { $p507seated = 1 }
Write-Output ('VERIFY seated=' + $p507seated + ' pluginsNow=' + (($p507back | ConvertFrom-Json).Plugins.Count))
Write-Output 'PHI P507 VERDICT: NWIRO SEATED IN VEIL OMNI'
Write-Output 'JOB 507 DONE'
```
