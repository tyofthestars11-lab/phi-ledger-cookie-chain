<!-- PHI-DIRECT -->
```powershell
Write-Output '=== JOB 526 - THE INPUT SEAT READ WHOLE (Ground: his hands report the game as it plays now: the sticks move her, A jumps, L2 pushes her forward which is a binding standing in the wrong place, and attack does not exist under his hands at all - no swing, no lance. The character source holds every binding as it stands after the legacy road was seated beside the enhanced one. This job prints the binding lines and the attack lines from the character source and header, numbered, so the fix authors against the true map: what L2 is actually bound to, whether the attack handlers exist, and which road they hang from. Every variable carries the p526 prefix.) ==='
$p526files = @('D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCharacter.cpp', 'D:\VEIL-OMNI\Source\VEIL\Public\Character\VEILCharacter.h')
foreach ($p526f in $p526files) {
  Write-Output ('FILE ' + $p526f)
  $p526lines = Get-Content $p526f -ErrorAction SilentlyContinue
  Write-Output ('LINES=' + ($p526lines | Measure-Object).Count)
  $p526i = 0
  foreach ($p526line in $p526lines) {
    $p526i = $p526i + 1
    if ($p526line -match 'Bind|InputAction|InputComponent|Attack|Swing|Lance|Trigger|Shoulder|Gamepad|Jump|MoveForward|MoveRight') { Write-Output ('B526 ' + $p526i + ': ' + $p526line.Trim()) }
  }
}
Write-Output 'PHI P526 VERDICT: INPUT SEAT PRINTED ABOVE'
Write-Output 'JOB 526 DONE'
```
