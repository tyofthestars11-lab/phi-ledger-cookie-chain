<!-- PHI-DIRECT -->
```powershell
Write-Output '=== CROSSING SAMPLER V2 + REBUILD + PROOF - VEIL (Jobs 337/338 read whole, the pair complete: in BOTH packages she is already deep below ground at her first tick - VEIL spawn printed Z=-547.625 against PlayerStart Z=120, OMNI Z=-1005.449 against Z=120 - and at the controlled redrop to Z=300 the floor finder names one actor for a single instant at floorDist=-42.0 and refuses it in the same line, findBlock=0 findWalk=0, then floorActor=none for the whole fall. The displacement inside the first redrop interval stands off its own velocity in both games: VEIL 300 to -250.6 in 0.25 s ending at velZ=-245.9, OMNI 300 to -343.6 in 0.26 s ending at velZ=-250.7; every interval after matches its velocity. THIS JOB reads the displacement's SHAPE: it replaces the v1 sampler (removal verified in-file before any new write) with a v2 that prints EVERY tick for her first 90 ticks - tick number, dt, Z, velZ, movement mode, FindFloor verdict, CurrentFloor - then at 8 s censuses every static-mesh actor whose bounds contain the spawn column (name, top, base, location) and redrops her there with per-tick prints for 45 ticks, then at 12 s censuses the PHI_GROUND slab column at (128,-416) from job 328 and redrops her onto it at Z=300 with per-tick prints for 45 ticks. Two outcomes, each naming its repair: if she lands on the slab column, the fault is local to the spawn columns and the standing actors the census names; if she falls through the slab column in per-tick view, the displacement's shape - one jump or continuous - is printed frame by frame and the repair is written against exactly that shape. The patch verifies itself by read-back before any build runs; a wrong anchor count, an incomplete v1 removal, or a failed verify stops this job BEFORE the cook. VEIL is the merged base: this fix is written here first; OMNI runs the identical instrument as job 342, filed in the same motion.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - job deferred.'; Write-Output 'JOB 341 DEFERRED'; return }
$file = 'D:\VEIL\Source\VEIL\Private\Character\VEILCharacter.cpp'
if (-not (Test-Path $file)) { Write-Output 'CHARACTER FILE NOT FOUND'; return }
$src = [System.IO.File]::ReadAllText($file)
if ($src.Contains('PHI CROSSING SAMPLER V2')) { Write-Output 'SAMPLER V2 ALREADY IN FILE' } else {
  if ($src.Contains('PHI CROSSING SAMPLER (jobs 337/338)')) {
    $mi = $src.IndexOf('// PHI CROSSING SAMPLER (jobs 337/338)')
    $ls = $mi; while ($ls -gt 0 -and $src[$ls - 1] -ne "`n") { $ls-- }
    $bi = $src.IndexOf('{', $mi)
    $depth = 0; $ei = -1
    for ($i = $bi; $i -lt $src.Length; $i++) { if ($src[$i] -eq '{') { $depth++ } elseif ($src[$i] -eq '}') { $depth--; if ($depth -eq 0) { $ei = $i; break } } }
    if ($ei -lt 0) { Write-Output 'V1 BLOCK END NOT FOUND - no cook runs.'; Write-Output 'JOB 341 STOPPED BEFORE COOK'; return }
    $src = $src.Substring(0, $ls) + $src.Substring($ei + 1)
    if ($src.Contains('PhiCrossClock')) { Write-Output 'V1 REMOVAL INCOMPLETE - no cook runs.'; Write-Output 'JOB 341 STOPPED BEFORE COOK'; return }
    Write-Output 'V1 SAMPLER REMOVED + VERIFIED'
  }
  if (-not $src.Contains('EngineUtils.h')) {
    $nl = $src.IndexOf("`n")
    $src = $src.Substring(0, $nl + 1) + "#include `"EngineUtils.h`"`r`n#include `"Engine/StaticMeshActor.h`"`r`n" + $src.Substring($nl + 1)
    Write-Output 'INCLUDES ADDED'
  }
  $anchor = 'Super::Tick(DeltaSeconds);'
  $count = ($src -split [regex]::Escape($anchor)).Length - 1
  "TICK ANCHOR COUNT: $count" | Write-Output
  if ($count -ne 1) { Write-Output 'TICK ANCHOR NOT UNIQUE - no cook runs.'; Write-Output 'JOB 341 STOPPED BEFORE COOK'; return }
  $diag = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CS8vIFBISSBDUk9TU0lORyBTQU1QTEVSIFYyIChqb2JzIDM0MS8zNDIpOiBwZXItdGljayBzaGFwZSBvZiB0aGUgZGlzcGxhY2VtZW50IGZyb20gc3Bhd24sIGEgY29sdW1uIGNlbnN1cyBhdCBib3RoIHJlZHJvcCBwb2ludHMsIGFuZCBhIHJlZHJvcCBvbnRvIHRoZSBQSElfR1JPVU5EIHNsYWIgY29sdW1uIHdob3NlIHRvcCBpcyB6PTAuCgl7CgkJc3RhdGljIGZsb2F0IFBoaUMyQ2xvY2sgPSAwLmY7CgkJc3RhdGljIGludDMyIFBoaUMyVGljayA9IDA7CgkJc3RhdGljIGludDMyIFBoaUMyU3RhZ2UgPSAwOwoJCXN0YXRpYyBpbnQzMiBQaGlDMldpbmRvdyA9IDA7CgkJc3RhdGljIEZWZWN0b3IgUGhpQzJTcGF3biA9IEZWZWN0b3I6Olplcm9WZWN0b3I7CgkJUGhpQzJDbG9jayArPSBEZWx0YVNlY29uZHM7CgkJKytQaGlDMlRpY2s7CgkJYXV0byBQaGlDMkxpbmUgPSBbdGhpc10oY29uc3QgVENIQVIqIFRhZywgZmxvYXQgRHQpIHsKCQkJRkZpbmRGbG9vclJlc3VsdCBQaGlGOwoJCQlHZXRDaGFyYWN0ZXJNb3ZlbWVudCgpLT5GaW5kRmxvb3IoR2V0QWN0b3JMb2NhdGlvbigpLCBQaGlGLCBmYWxzZSk7CgkJCVVFX0xPRyhMb2dUZW1wLCBEaXNwbGF5LCBURVhUKCJQSEkgQ1JPU1MyICVzOiB0aWNrPSVkIGR0PSUuNGYgej0lLjFmIHZlbFo9JS4xZiBtb2RlPSVkIGZpbmRCbG9jaz0lZCBmaW5kV2Fsaz0lZCBmbG9vckRpc3Q9JS4xZiBmbG9vckFjdG9yPSVzIGN1ckJsb2NrPSVkIiksIFRhZywgUGhpQzJUaWNrLCBEdCwgR2V0QWN0b3JMb2NhdGlvbigpLlosIEdldFZlbG9jaXR5KCkuWiwgKGludDMyKUdldENoYXJhY3Rlck1vdmVtZW50KCktPk1vdmVtZW50TW9kZSwgUGhpRi5iQmxvY2tpbmdIaXQgPyAxIDogMCwgUGhpRi5iV2Fsa2FibGVGbG9vciA/IDEgOiAwLCBQaGlGLkZsb29yRGlzdCwgUGhpRi5IaXRSZXN1bHQuR2V0QWN0b3IoKSA/ICpQaGlGLkhpdFJlc3VsdC5HZXRBY3RvcigpLT5HZXROYW1lKCkgOiBURVhUKCJub25lIiksIEdldENoYXJhY3Rlck1vdmVtZW50KCktPkN1cnJlbnRGbG9vci5iQmxvY2tpbmdIaXQgPyAxIDogMCk7CgkJfTsKCQlhdXRvIFBoaUMyQ29sdW1uID0gW3RoaXNdKGZsb2F0IFgsIGZsb2F0IFkpIHsKCQkJZm9yIChUQWN0b3JJdGVyYXRvcjxBU3RhdGljTWVzaEFjdG9yPiBJdChHZXRXb3JsZCgpKTsgSXQ7ICsrSXQpCgkJCXsKCQkJCUZCb3ggUGhpQiA9IEl0LT5HZXRDb21wb25lbnRzQm91bmRpbmdCb3godHJ1ZSk7CgkJCQlpZiAoWCA+PSBQaGlCLk1pbi5YICYmIFggPD0gUGhpQi5NYXguWCAmJiBZID49IFBoaUIuTWluLlkgJiYgWSA8PSBQaGlCLk1heC5ZKQoJCQkJewoJCQkJCVVFX0xPRyhMb2dUZW1wLCBEaXNwbGF5LCBURVhUKCJQSEkgQ1JPU1MyIENPTFVNTjogeD0lLjBmIHk9JS4wZiBhY3Rvcj0lcyB0b3A9JS4xZiBiYXNlPSUuMWYgbG9jPSVzIiksIFgsIFksICpJdC0+R2V0TmFtZSgpLCBQaGlCLk1heC5aLCBQaGlCLk1pbi5aLCAqSXQtPkdldEFjdG9yTG9jYXRpb24oKS5Ub1N0cmluZygpKTsKCQkJCX0KCQkJfQoJCX07CgkJaWYgKFBoaUMyU3RhZ2UgPT0gMCkKCQl7CgkJCVBoaUMyU3Bhd24gPSBHZXRBY3RvckxvY2F0aW9uKCk7CgkJCVBoaUMyU3RhZ2UgPSAxOwoJCQlVRV9MT0coTG9nVGVtcCwgRGlzcGxheSwgVEVYVCgiUEhJIENST1NTMiBTUEFXTjogbG9jPSVzIiksICpQaGlDMlNwYXduLlRvU3RyaW5nKCkpOwoJCX0KCQlpZiAoUGhpQzJTdGFnZSA9PSAxKQoJCXsKCQkJUGhpQzJMaW5lKFRFWFQoIlRJQ0siKSwgRGVsdGFTZWNvbmRzKTsKCQkJaWYgKFBoaUMyVGljayA+PSA5MCkgeyBQaGlDMlN0YWdlID0gMjsgfQoJCX0KCQllbHNlIGlmIChQaGlDMlN0YWdlID09IDIgJiYgUGhpQzJDbG9jayA+PSA4LmYpCgkJewoJCQlQaGlDMkNvbHVtbihQaGlDMlNwYXduLlgsIFBoaUMyU3Bhd24uWSk7CgkJCVNldEFjdG9yTG9jYXRpb24oRlZlY3RvcihQaGlDMlNwYXduLlgsIFBoaUMyU3Bhd24uWSwgMzAwLmYpKTsKCQkJR2V0Q2hhcmFjdGVyTW92ZW1lbnQoKS0+VmVsb2NpdHkgPSBGVmVjdG9yOjpaZXJvVmVjdG9yOwoJCQlVRV9MT0coTG9nVGVtcCwgRGlzcGxheSwgVEVYVCgiUEhJIENST1NTMiBSRURST1AxOiBsb2M9JXMiKSwgKkdldEFjdG9yTG9jYXRpb24oKS5Ub1N0cmluZygpKTsKCQkJUGhpQzJXaW5kb3cgPSAwOwoJCQlQaGlDMlN0YWdlID0gMzsKCQl9CgkJZWxzZSBpZiAoUGhpQzJTdGFnZSA9PSAzKQoJCXsKCQkJUGhpQzJMaW5lKFRFWFQoIkRST1AxIiksIERlbHRhU2Vjb25kcyk7CgkJCWlmICgrK1BoaUMyV2luZG93ID49IDQ1KSB7IFBoaUMyU3RhZ2UgPSA0OyB9CgkJfQoJCWVsc2UgaWYgKFBoaUMyU3RhZ2UgPT0gNCAmJiBQaGlDMkNsb2NrID49IDEyLmYpCgkJewoJCQlQaGlDMkNvbHVtbigxMjguZiwgLTQxNi5mKTsKCQkJU2V0QWN0b3JMb2NhdGlvbihGVmVjdG9yKDEyOC5mLCAtNDE2LmYsIDMwMC5mKSk7CgkJCUdldENoYXJhY3Rlck1vdmVtZW50KCktPlZlbG9jaXR5ID0gRlZlY3Rvcjo6WmVyb1ZlY3RvcjsKCQkJVUVfTE9HKExvZ1RlbXAsIERpc3BsYXksIFRFWFQoIlBISSBDUk9TUzIgUkVEUk9QMjogbG9jPSVzIiksICpHZXRBY3RvckxvY2F0aW9uKCkuVG9TdHJpbmcoKSk7CgkJCVBoaUMyV2luZG93ID0gMDsKCQkJUGhpQzJTdGFnZSA9IDU7CgkJfQoJCWVsc2UgaWYgKFBoaUMyU3RhZ2UgPT0gNSkKCQl7CgkJCVBoaUMyTGluZShURVhUKCJEUk9QMiIpLCBEZWx0YVNlY29uZHMpOwoJCQlpZiAoKytQaGlDMldpbmRvdyA+PSA0NSkgeyBQaGlDMlN0YWdlID0gNjsgfQoJCX0KCX0K'))
  $idx = $src.IndexOf($anchor) + $anchor.Length
  $src = $src.Substring(0, $idx) + "`r`n" + $diag + $src.Substring($idx)
  Copy-Item $file "$file.phi-backup-341" -Force
  [System.IO.File]::WriteAllText($file, $src)
  $check = [System.IO.File]::ReadAllText($file)
  if ($check.Contains('PHI CROSSING SAMPLER V2') -and -not $check.Contains('PhiCrossClock')) { Write-Output 'SAMPLER V2 PATCHED + VERIFIED in file' } else { Write-Output 'PATCH WRITE FAILED VERIFY - no cook runs.'; Write-Output 'JOB 341 STOPPED BEFORE COOK'; return }
}
$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
$proj = 'D:\VEIL'; $arch = 'D:\Builds\VEIL\VEIL_DONE'; $exename = 'VEIL.exe'; $name = 'VEIL'
$uproj = Get-ChildItem $proj -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
$cooklog = "$proj\Saved\crosscook341.log"
$p = Start-Process $uat -ArgumentList @('BuildCookRun', "-project=$uproj", '-noP4', '-platform=Win64', '-clientconfig=Development', '-build', '-cook', '-stage', '-pak', '-archive', "-archivedirectory=$arch") -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $cooklog -RedirectStandardError "$cooklog.err"
"UAT exit: $($p.ExitCode)" | Write-Output
Select-String -Path $cooklog -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|error C[0-9]+|Error:' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output
$exe = "$arch\Windows\$exename"
if (Test-Path $exe) { $fi = Get-Item $exe; "exe modified $($fi.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss'))" | Write-Output
  $proc = Start-Process $exe -ArgumentList @('-PhiStandaloneProof') -PassThru -WindowStyle Hidden
  Start-Sleep -Seconds 30
  $logs = Get-ChildItem "$proj\Saved\Logs", "$arch\Windows\$name\Saved\Logs" -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
  if ($logs) { Select-String -Path $logs.FullName -Pattern 'PHI CROSS2|PHI MOVE TEST|PHI FLOOR DIAG|PHI CENSUS' | Select-Object -Last 220 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
  Get-Process $name -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
} else { Write-Output 'EXE MISSING AFTER CROSS2 COOK' }
Write-Output 'JOB 341 DONE'
```
