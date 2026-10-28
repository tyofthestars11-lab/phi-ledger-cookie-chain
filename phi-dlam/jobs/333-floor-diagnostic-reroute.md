<!-- PHI-DIRECT -->
```powershell
Write-Output '=== FLOOR DIAGNOSTIC v2 - REROUTE OF 332 (332s patch missed: ANCHOR MISS tick block end in both games - its block-end search assumed bare-LF line endings and the sources are CRLF, so nothing was written and the recooks ran unpatched code. REROUTE law: the matcher is rebuilt CRLF-safe in this same motion - the diagnostic now inserts BEFORE the tickproof UE_LOG line, located by walking back to its line start, and the write is verified by reading PHI FLOOR DIAG back from the file before any build runs. Same diagnostic, same rebuild+cook+proof tail as 332.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - diagnostic job deferred.'; Write-Output 'DIAG JOB DEFERRED'; return }

foreach ($g in @(@('VEIL','D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp'), @('OMNI','D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp'))) {
  $name = $g[0]; $file = $g[1]
  "##### PATCH $name : $file #####" | Write-Output
  if (-not (Test-Path $file)) { Write-Output 'GM FILE NOT FOUND'; continue }
  $src = [System.IO.File]::ReadAllText($file)
  if ($src.Contains('PHI FLOOR DIAG')) { Write-Output 'ALREADY PATCHED'; continue }
  $anchor = 'UE_LOG(LogTemp, Display, TEXT("PHI PC TICKPROOF:'
  $idx = $src.IndexOf($anchor)
  if ($idx -lt 0) { Write-Output 'ANCHOR MISS: tickproof log line'; continue }
  $lineStart = $src.LastIndexOf("`n", $idx) + 1
  if (-not $src.Contains('Components/CapsuleComponent.h')) {
    $fi = $src.IndexOf('#include')
    $fe = $src.IndexOf("`n", $fi) + 1
    $incs = '#include "Components/CapsuleComponent.h"' + "`r`n" + '#include "GameFramework/CharacterMovementComponent.h"' + "`r`n" + '#include "Engine/StaticMeshActor.h"' + "`r`n" + '#include "EngineUtils.h"' + "`r`n"
    $src = $src.Substring(0, $fe) + $incs + $src.Substring($fe)
    $idx = $src.IndexOf($anchor)
    $lineStart = $src.LastIndexOf("`n", $idx) + 1
  }
  $diag = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CQlzdGF0aWMgZmxvYXQgUGhpRGlhZ0Nsb2NrID0gMC5mOwoJCVBoaURpYWdDbG9jayArPSBEZWx0YVNlY29uZHM7CgkJaWYgKFBoaURpYWdDbG9jayA+PSA2LmYgJiYgUGhpRGlhZ0Nsb2NrIDwgMTAwMC5mKQoJCXsKCQkJUGhpRGlhZ0Nsb2NrID0gMjAwMC5mOwoJCQlpZiAoQUNoYXJhY3RlciogRGlhZ1Bhd24gPSBDYXN0PEFDaGFyYWN0ZXI+KEdldFBhd24oKSkpCgkJCXsKCQkJCVVDYXBzdWxlQ29tcG9uZW50KiBDYXAgPSBEaWFnUGF3bi0+R2V0Q2Fwc3VsZUNvbXBvbmVudCgpOwoJCQkJVUNoYXJhY3Rlck1vdmVtZW50Q29tcG9uZW50KiBDTW92ZSA9IERpYWdQYXduLT5HZXRDaGFyYWN0ZXJNb3ZlbWVudCgpOwoJCQkJVUVfTE9HKExvZ1RlbXAsIERpc3BsYXksIFRFWFQoIlBISSBGTE9PUiBESUFHOiB3b3JsZD0lcyBjYXBFbmFibGVkPSVkIGNhcFByb2ZpbGU9JXMgbW92ZU1vZGU9JWQgb25Hcm91bmQ9JWQgZmxvb3JCbG9jaz0lZCBmbG9vckFjdG9yPSVzIiksCgkJCQkJKkdldFdvcmxkKCktPkdldE5hbWUoKSwKCQkJCQlDYXAgPyAoaW50MzIpQ2FwLT5HZXRDb2xsaXNpb25FbmFibGVkKCkgOiAtMSwKCQkJCQlDYXAgPyAqQ2FwLT5HZXRDb2xsaXNpb25Qcm9maWxlTmFtZSgpLlRvU3RyaW5nKCkgOiBURVhUKCJub25lIiksCgkJCQkJQ01vdmUgPyAoaW50MzIpQ01vdmUtPk1vdmVtZW50TW9kZSA6IC0xLCAoQ01vdmUgJiYgQ01vdmUtPklzTW92aW5nT25Hcm91bmQoKSkgPyAxIDogMCwKCQkJCQkoQ01vdmUgJiYgQ01vdmUtPkN1cnJlbnRGbG9vci5iQmxvY2tpbmdIaXQpID8gMSA6IDAsCgkJCQkJKENNb3ZlICYmIENNb3ZlLT5DdXJyZW50Rmxvb3IuSGl0UmVzdWx0LkdldEFjdG9yKCkpID8gKkNNb3ZlLT5DdXJyZW50Rmxvb3IuSGl0UmVzdWx0LkdldEFjdG9yKCktPkdldE5hbWUoKSA6IFRFWFQoIm5vbmUiKSk7CgkJCQljb25zdCBGVmVjdG9yIFBhd25Mb2MgPSBEaWFnUGF3bi0+R2V0QWN0b3JMb2NhdGlvbigpOwoJCQkJRkhpdFJlc3VsdCBUcmFjZUhpdDsKCQkJCWNvbnN0IEZWZWN0b3IgVHJhY2VTdGFydChQYXduTG9jLlgsIFBhd25Mb2MuWSwgNTAwLmYpOwoJCQkJY29uc3QgRlZlY3RvciBUcmFjZUVuZChQYXduTG9jLlgsIFBhd25Mb2MuWSwgLTUwMC5mKTsKCQkJCWNvbnN0IGJvb2wgYlRyYWNlID0gR2V0V29ybGQoKS0+TGluZVRyYWNlU2luZ2xlQnlDaGFubmVsKFRyYWNlSGl0LCBUcmFjZVN0YXJ0LCBUcmFjZUVuZCwgRUNDX1dvcmxkU3RhdGljKTsKCQkJCVVFX0xPRyhMb2dUZW1wLCBEaXNwbGF5LCBURVhUKCJQSEkgRkxPT1IgVFJBQ0U6IGhpdD0lZCBhY3Rvcj0lcyBoaXRaPSUuMWYgcGF3blo9JS4xZiIpLAoJCQkJCWJUcmFjZSA/IDEgOiAwLCBUcmFjZUhpdC5HZXRBY3RvcigpID8gKlRyYWNlSGl0LkdldEFjdG9yKCktPkdldE5hbWUoKSA6IFRFWFQoIm5vbmUiKSwKCQkJCQlUcmFjZUhpdC5Mb2NhdGlvbi5aLCBQYXduTG9jLlopOwoJCQkJaW50MzIgUHJpbnRlZCA9IDA7CgkJCQlmb3IgKFRBY3Rvckl0ZXJhdG9yPEFTdGF0aWNNZXNoQWN0b3I+IEl0KEdldFdvcmxkKCkpOyBJdDsgKytJdCkKCQkJCXsKCQkJCQlGVmVjdG9yIE9yaWdpbjsgRlZlY3RvciBFeHRlbnQ7CgkJCQkJSXQtPkdldEFjdG9yQm91bmRzKGZhbHNlLCBPcmlnaW4sIEV4dGVudCk7CgkJCQkJaWYgKEZNYXRoOjpBYnMoT3JpZ2luLlggLSBQYXduTG9jLlgpIDwgMjUwMC5mICYmIEZNYXRoOjpBYnMoT3JpZ2luLlkgLSBQYXduTG9jLlkpIDwgMjUwMC5mICYmIFByaW50ZWQgPCAxMikKCQkJCQl7CgkJCQkJCSsrUHJpbnRlZDsKCQkJCQkJVUVfTE9HKExvZ1RlbXAsIERpc3BsYXksIFRFWFQoIlBISSBGTE9PUiBBQ1RPUjogbmFtZT0lcyB0b3A9JS4xZiBiYXNlPSUuMWYgbG9jPVg9JS4wZiBZPSUuMGYgWj0lLjBmIGNvbGxFbmFibGVkPSVkIiksCgkJCQkJCQkqSXQtPkdldE5hbWUoKSwgT3JpZ2luLlogKyBFeHRlbnQuWiwgT3JpZ2luLlogLSBFeHRlbnQuWiwgT3JpZ2luLlgsIE9yaWdpbi5ZLCBPcmlnaW4uWiwKCQkJCQkJCUl0LT5HZXRTdGF0aWNNZXNoQ29tcG9uZW50KCkgPyAoaW50MzIpSXQtPkdldFN0YXRpY01lc2hDb21wb25lbnQoKS0+R2V0Q29sbGlzaW9uRW5hYmxlZCgpIDogLTEpOwoJCQkJCX0KCQkJCX0KCQkJfQoJCX0='))
  $src = $src.Substring(0, $lineStart) + $diag + "`r`n" + $src.Substring($lineStart)
  Copy-Item $file "$file.phi-backup-333" -Force
  [System.IO.File]::WriteAllText($file, $src)
  $check = [System.IO.File]::ReadAllText($file)
  if ($check.Contains('PHI FLOOR DIAG')) { Write-Output 'PATCHED + VERIFIED in file' } else { Write-Output 'PATCH WRITE FAILED VERIFY' }
}
Write-Output 'PATCH PHASE DONE'

$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
foreach ($g in @(@('VEIL','D:\VEIL','D:\Builds\VEIL\VEIL_DONE','VEIL.exe'), @('OMNI','D:\OMNI-UE','D:\Builds\OMNI\OMNI_DONE','OMNI.exe'))) {
  $name = $g[0]; $proj = $g[1]; $arch = $g[2]; $exename = $g[3]
  "##### BUILD+PROOF $name #####" | Write-Output
  $uproj = Get-ChildItem $proj -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
  $cooklog = "$proj\Saved\diagcook333.log"
  $p = Start-Process $uat -ArgumentList @('BuildCookRun', "-project=$uproj", '-noP4', '-platform=Win64', '-clientconfig=Development', '-build', '-cook', '-stage', '-pak', '-archive', "-archivedirectory=$arch") -Wait -PassThru -WindowStyle Hidden -RedirectStandardOutput $cooklog -RedirectStandardError "$cooklog.err"
  "UAT exit: $($p.ExitCode)" | Write-Output
  Select-String -Path $cooklog -Pattern 'BUILD SUCCESSFUL|BUILD FAILED|AutomationTool exiting|error C[0-9]+|Error:' | Select-Object -Last 6 | ForEach-Object { $_.Line.Trim() } | Write-Output
  $exe = "$arch\Windows\$exename"
  if (Test-Path $exe) { $fi = Get-Item $exe; "exe modified $($fi.LastWriteTime.ToString('yyyy-MM-dd HH:mm:ss'))" | Write-Output
    $proc = Start-Process $exe -ArgumentList @('-PhiStandaloneProof') -PassThru -WindowStyle Hidden
    Start-Sleep -Seconds 40
    $logs = Get-ChildItem "$proj\Saved\Logs", "$arch\Windows\$name\Saved\Logs" -Filter '*.log' -File -ErrorAction SilentlyContinue | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    if ($logs) { Select-String -Path $logs.FullName -Pattern 'PHI FLOOR DIAG|PHI FLOOR TRACE|PHI FLOOR ACTOR|PHI MOVE TEST|PHI CENSUS' | Select-Object -Last 22 | ForEach-Object { $_.Line.Trim() } | Write-Output } else { Write-Output 'NO PROOF LOG FOUND' }
    Get-Process $name -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
  } else { Write-Output 'EXE MISSING AFTER DIAG COOK' }
}
Write-Output 'DIAG JOB DONE'
```
