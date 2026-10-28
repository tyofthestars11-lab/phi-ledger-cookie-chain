<!-- PHI-DIRECT -->
```powershell
Write-Output '=== ONE-DOOR SWAP - ONE VEIL OMNI DOOR FOR THE RESTART (Tyrees order, 2026-10-28, side chat: I restart my pc. I should see one unreal game not 2. Job 345 censused the desktops and found NO game doors at all - 8 shortcuts on Admin Desktop, 12 on Public, none for either parent - so the swap is written from that read: this job re-censuses both desktops, takes down any shortcut that names a parent game (VEIL or OMNI as games on offer), and stands the single door: VEIL OMNI - The Last Signal - Path of Light, on the Admin Desktop. Per his correction the same hour - no package until 100 percent done - the door opens the ONE PROJECT directly in -game mode through the editor binary: it goes to the game, not to a package that does not exist yet and not into editor creative. When the finished game is packaged at the 100 percent gate, the door is repointed to the package in that motion. The shortcut is verified by read-back in the same job: target, arguments, and name printed from the .lnk itself.) ==='
$desktops = @("$env:USERPROFILE\Desktop", 'C:\Users\Public\Desktop')
$ws = New-Object -ComObject WScript.Shell
foreach ($d in $desktops) {
  Get-ChildItem $d -Filter '*.lnk' -File -ErrorAction SilentlyContinue | ForEach-Object {
    $isParent = ($_.Name -match 'VEIL' -or $_.Name -match 'OMNI') -and ($_.Name -notmatch 'VEIL OMNI')
    Write-Output ("PHI DOOR CENSUS: " + $_.Name + " parent=" + $isParent)
    if ($isParent) { Remove-Item $_.FullName -Force; Write-Output ("PHI DOOR REMOVED: " + $_.Name) }
  }
}
$uproj = Get-ChildItem 'D:\VEIL' -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
$editor = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$lnkPath = "$env:USERPROFILE\Desktop\VEIL OMNI - The Last Signal - Path of Light.lnk"
$lnk = $ws.CreateShortcut($lnkPath)
$lnk.TargetPath = $editor
$lnk.Arguments = '"' + $uproj + '" -game'
$lnk.WorkingDirectory = 'D:\VEIL'
$lnk.Description = 'VEIL OMNI - the one game (project, in -game mode; repoints to the package at the 100 percent gate)'
$lnk.Save()
if (Test-Path $lnkPath) {
  $chk = $ws.CreateShortcut($lnkPath)
  Write-Output ("PHI DOOR STANDS: " + $lnkPath)
  Write-Output ("PHI DOOR TARGET: " + $chk.TargetPath)
  Write-Output ("PHI DOOR ARGS: " + $chk.Arguments)
} else { Write-Output 'DOOR CREATE FAILED' }
$omniDoors = 0; $parentDoors = 0
foreach ($d in $desktops) {
  Get-ChildItem $d -Filter '*.lnk' -File -ErrorAction SilentlyContinue | ForEach-Object {
    if ($_.Name -match 'VEIL OMNI') { $omniDoors++ }
    elseif ($_.Name -match 'VEIL' -or $_.Name -match 'OMNI') { $parentDoors++ }
    Write-Output ("PHI DOOR AFTER: " + $_.Name)
  }
}
Write-Output "PHI DOOR FINAL: veil_omni_doors=$omniDoors parent_doors=$parentDoors"
Write-Output 'JOB 357 DONE'
```
