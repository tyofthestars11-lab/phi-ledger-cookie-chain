<!-- PHI-DIRECT -->
```powershell
Write-Output '=== DESKTOP DOOR CENSUS - READ-ONLY (Tyrees clarification on the Merge-it GO, 2026-10-28, his words: I dont want to see 2 different unreal games / We want one veil omni. The end state he SEES is one game: one door on his desktop - VEIL OMNI - The Last Signal - Path of Light - one project presented as the game, one package, one save. The two separate doors from job 088 (VEIL - The Last Signal / OMNI RPG) come down when the merged build stands playable in his hands, and the single door stands in their place - the parents themselves are never deleted on this word; they stand as archive unless he gives a separate explicit word at proof time. THIS JOB changes nothing: it reads the desktop as it stands tonight - every shortcut whose name matches VEIL or OMNI, with its target and arguments resolved - so the one-door swap at proof time is written from a read, not from memory.) ==='
$ws = New-Object -ComObject WScript.Shell
$desks = @([Environment]::GetFolderPath('Desktop'), "$env:PUBLIC\Desktop") | Select-Object -Unique
foreach ($desk in $desks) {
  if (-not (Test-Path $desk)) { continue }
  Get-ChildItem $desk -Filter '*.lnk' -File -ErrorAction SilentlyContinue | Where-Object { $_.Name -match 'VEIL|OMNI' } | ForEach-Object {
    $sc = $ws.CreateShortcut($_.FullName)
    Write-Output ("PHI DOOR: name=" + $_.Name + " target=" + $sc.TargetPath + " args=" + $sc.Arguments)
  }
  $all = (Get-ChildItem $desk -Filter '*.lnk' -File -ErrorAction SilentlyContinue).Count
  Write-Output "PHI DOOR DESKTOP: $desk total shortcuts=$all"
}
Write-Output 'JOB 345 DONE'
```
