<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CROSSING SAMPLER + REBUILD + PROOF - VEIL (Job 336 read whole: the Character source is CLEAN - constructor, BeginPlay and the full Tick printed end to end; the MOVE TEST only calls AddMovementInput; the Source-wide movement grep finds no teleport, no capsule tampering, no gravity or movement-mode writes on the pawn - only the decorative RunnerBody/RunnerVisor NoCollision lines, the dodge LaunchCharacter, and the GameMode builder teleport that stands down on placed maps. Every code address now stands read whole: pawn source, GameModes, configs, and the in-package physics state from 334/335 - capsule QueryAndPhysics/Pawn, floors trace-visible at top z=0.0, CurrentFloor never registering. The one interval no instrument has ever observed is the crossing itself: her first second. The earliest Z on record is already -12300 at move-test begin. THIS JOB watches the crossing with the engine's own floor finder: a sampler in the Character Tick prints, at 0.25/0.5/0.75/1.0/1.5/2.0 s of pawn tick time, her Z, vertical velocity, movement mode, and FindFloor's own verdict (blocking, walkable, floor distance, line distance, floor actor) plus CurrentFloor and the scaled capsule size; then at 8.0 s it re-drops her onto spawn X/Y at z=300 with zero velocity and samples the forced crossing at 8.25/8.5/8.75/9.0/10.0 s. The patch verifies itself by read-back before any build runs - a wrong anchor count or a failed verify stops this job BEFORE the cook.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 337 DEFERRED'; return }
$file = 'D:\VEIL\Source\VEIL\Private\Character\VEILCharacter.cpp'
if (-not (Test-Path $file)) { Write-Output 'CHARACTER FILE NOT FOUND'; return }
$src = [System.IO.File]::ReadAllText($file)
if ($src.Contains('PHI CROSSING SAMPLER')) { Write-Output 'SAMPLER ALREADY IN FILE' } else {
  $anchor = 'Super::Tick(DeltaSeconds);'
  $count = ($src -split [regex]::Escape($anchor)).Length - 1
  "TICK ANCHOR COUNT: $count" | Write-Output
  if ($count -ne 1) { Write-Output 'TICK ANCHOR NOT UNIQUE - no cook runs.'; Write-Output 'JOB 337 STOPPED BEFORE COOK'; return }
  $diag = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CS8vIFBISSBDUk9TU0lORyBTQU1QTEVSIChqb2JzIDMzNy8zMzgpOiB3YXRjaGVzIHRoZSBmYWxsJ3MgZmlyc3Qgc2Vjb25kcyBhbmQgYSBjb250cm9sbGVkIHJlLWRyb3AuCgl7CgkJc3RhdGljIGZsb2F0IFBoaUNyb3NzQ2xvY2sgPSAwLmY7CgkJc3RhdGljIGludDMyIFBoaUNyb3NzU3RhZ2UgPSAwOwoJCXN0YXRpYyBGVmVjdG9yIFBoaUNyb3NzU3Bhd24gPSBGVmVjdG9yOjpaZXJvVmVjdG9yOwoJCVBoaUNyb3NzQ2xvY2sgKz0gRGVsdGFTZWNvbmRzOwoJCWlmIChQaGlDcm9zc1N0YWdlID09IDApCgkJewoJCQlQaGlDcm9zc1NwYXduID0gR2V0QWN0b3JMb2NhdGlvbigpOwoJCQlQaGlDcm9zc1N0YWdlID0gMTsKCQkJVUVfTE9HKExvZ1RlbXAsIERpc3BsYXksIFRFWFQoIlBISSBDUk9TU0lORyBTUEFXTjogbG9jPSVzIiksICpQaGlDcm9zc1NwYXduLlRvU3RyaW5nKCkpOwoJCX0KCQlzdGF0aWMgY29uc3QgZmxvYXQgUGhpQ3Jvc3NUaW1lc1sxMl0gPSB7IDAuMjVmLCAwLjVmLCAwLjc1ZiwgMS4wZiwgMS41ZiwgMi4wZiwgOC4wZiwgOC4yNWYsIDguNWYsIDguNzVmLCA5LjBmLCAxMC4wZiB9OwoJCWlmIChQaGlDcm9zc1N0YWdlID49IDEgJiYgUGhpQ3Jvc3NTdGFnZSA8PSAxMiAmJiBQaGlDcm9zc0Nsb2NrID49IFBoaUNyb3NzVGltZXNbUGhpQ3Jvc3NTdGFnZSAtIDFdKQoJCXsKCQkJaWYgKFBoaUNyb3NzU3RhZ2UgPT0gNykKCQkJewoJCQkJU2V0QWN0b3JMb2NhdGlvbihGVmVjdG9yKFBoaUNyb3NzU3Bhd24uWCwgUGhpQ3Jvc3NTcGF3bi5ZLCAzMDAuZikpOwoJCQkJR2V0Q2hhcmFjdGVyTW92ZW1lbnQoKS0+VmVsb2NpdHkgPSBGVmVjdG9yOjpaZXJvVmVjdG9yOwoJCQkJVUVfTE9HKExvZ1RlbXAsIERpc3BsYXksIFRFWFQoIlBISSBDUk9TU0lORyBSRURST1A6IGxvYz0lcyIpLCAqR2V0QWN0b3JMb2NhdGlvbigpLlRvU3RyaW5nKCkpOwoJCQl9CgkJCUZGaW5kRmxvb3JSZXN1bHQgUGhpRmxvb3I7CgkJCUdldENoYXJhY3Rlck1vdmVtZW50KCktPkZpbmRGbG9vcihHZXRBY3RvckxvY2F0aW9uKCksIFBoaUZsb29yLCBmYWxzZSk7CgkJCVVFX0xPRyhMb2dUZW1wLCBEaXNwbGF5LCBURVhUKCJQSEkgQ1JPU1NJTkc6IHQ9JS4yZiB6PSUuMWYgdmVsWj0lLjFmIG1vZGU9JWQgZmluZEJsb2NrPSVkIGZpbmRXYWxrPSVkIGZsb29yRGlzdD0lLjFmIGxpbmVEaXN0PSUuMWYgZmxvb3JBY3Rvcj0lcyBjdXJCbG9jaz0lZCBjYXBIYWxmPSUuMWYgY2FwUmFkPSUuMWYiKSwKCQkJCVBoaUNyb3NzQ2xvY2ssIEdldEFjdG9yTG9jYXRpb24oKS5aLCBHZXRWZWxvY2l0eSgpLlosIChpbnQzMilHZXRDaGFyYWN0ZXJNb3ZlbWVudCgpLT5Nb3ZlbWVudE1vZGUsCgkJCQlQaGlGbG9vci5iQmxvY2tpbmdIaXQgPyAxIDogMCwgUGhpRmxvb3IuYldhbGthYmxlRmxvb3IgPyAxIDogMCwgUGhpRmxvb3IuRmxvb3JEaXN0LCBQaGlGbG9vci5MaW5lRGlzdCwKCQkJCVBoaUZsb29yLkhpdFJlc3VsdC5HZXRBY3RvcigpID8gKlBoaUZsb29yLkhpdFJlc3VsdC5HZXRBY3RvcigpLT5HZXROYW1lKCkgOiBURVhUKCJub25lIiksCgkJCQlHZXRDaGFyYWN0ZXJNb3ZlbWVudCgpLT5DdXJyZW50Rmxvb3IuYkJsb2NraW5nSGl0ID8gMSA6IDAsCgkJCQlHZXRDYXBzdWxlQ29tcG9uZW50KCktPkdldFNjYWxlZENhcHN1bGVIYWxmSGVpZ2h0KCksIEdldENhcHN1bGVDb21wb25lbnQoKS0+R2V0U2NhbGVkQ2Fwc3VsZVJhZGl1cygpKTsKCQkJKytQaGlDcm9zc1N0YWdlOwoJCX0KCX0K'))
  $idx = $src.IndexOf($anchor) + $anchor.Length
  $src = $src.Substring(0, $idx) + "`r`n" + $diag + $src.Substring($idx)
  Copy-Item $file "$file.phi-backup-337" -Force
  [System.IO.File]::WriteAllText($file, $src)
  $check = [System.IO.File]::ReadAllText($file)
  if ($check.Contains('PHI CROSSING SAMPLER')) { Write-Output 'SAMPLER PATCHED + VERIFIED in file' } else { Write-Output 'PATCH WRITE FAILED VERIFY - no cook runs.'; Write-Output 'JOB 337 STOPPED BEFORE COOK'; return }
}
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$proj = 'D:\VEIL'; $arch = 'D:\Builds\VEIL\VEIL_DONE'; $exename = 'VEIL.exe'; $name = 'VEIL'
$uproj = Get-ChildItem $proj -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
$cooklog = "$proj\Saved\crosscook337.log"
$p = Start-Process $uat -ArgumentList @('BuildCookRun', "-project=$uproj", '-noP4', '-platform=Win64', '-clientconfig=Development', '-build', '-cook', '-stage', '-pak', '-archive', "-archivedirectory=$arch") -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $cooklog -RedirectStandardError "$cooklog.err"
"UAT exit: $($p.ExitCode)" | Write-Output
Select-String -Path $cooklog -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|error C[0-9]+|Error:' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output
$exe = "$arch\Windows\$exename"
if (Test-Path $exe) { $fi = Get-Item $exe; "exe modified $($fi.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss'))" | Write-Output
  $proc = Start-Process $exe -ArgumentList @('-PhiStandaloneProof') -PassThru -WindowStyle Hidden
  Start-Sleep -Seconds 30
  $logs = Get-ChildItem "$proj\Saved\Logs", "$arch\Windows\$name\Saved\Logs" -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  if ($logs) { Select-String -Path $logs.FullName -Pattern 'PHI CROSSING|PHI MOVE TEST|PHI FLOOR DIAG|PHI CENSUS' | Select-Object -Last 40 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
  Get-Process $name -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
} else { Write-Output 'EXE MISSING AFTER CROSSING COOK' }
Write-Output 'JOB 337 DONE'
```
