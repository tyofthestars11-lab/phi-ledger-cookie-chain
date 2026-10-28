<!-- PHI-DIRECT -->
```powershell
Write-Output '=== FLOOR DIAGNOSTIC INSIDE THE PACKAGE + REBUILD + RECOOK + PROOF - BOTH GAMES (Job 331 read the GameModes and configs whole: the world-builder teleport STANDS DOWN on the placed maps - District/World in the name means Builder is nullptr and the pawn is never teleported - and the ini files are clean. Every editor-side fact says she should stand, yet in the package she falls through a guaranteed pad. So this job asks PHYSICS ITSELF, inside the packaged game: it patches a one-shot PHI FLOOR DIAG into each PlayerControllers existing tickproof block - capsule collision state and profile, movement mode, CurrentFloor blocking state, a WorldStatic line trace down the exact column she falls through at spawn height, and every static mesh actor near that column with its top height and collision state AS THE PACKAGE SEES THEM. Anchor-verified string surgery with backups (.phi-backup-332); an anchor miss skips that game untouched. Then UAT rebuild+cook and the standalone proofs.) ==='
$waited = 0
while ((Get-Process UnrealEditor -ErrorAction SilentlyContinue) -and $waited -lt 8) { Start-Sleep -Seconds 15; $waited++ }
if (Get-Process UnrealEditor -ErrorAction SilentlyContinue) { Write-Output 'EDITOR STILL OPEN after 2 min - diagnostic job deferred.'; Write-Output 'DIAG JOB DEFERRED'; return }

$ErrorActionPreference = 'Continue'
foreach ($g in @(@('VEIL','D:\VEIL\Source\VEIL\Private\Game\VEILGameMode.cpp'), @('OMNI','D:\OMNI-UE\Source\OMNI\Private\Game\OMNIGameMode.cpp'))) {
  $name = $g[0]; $file = $g[1]
  "##### PATCH $name : $file #####" | Write-Output
  if (-not (Test-Path $file)) { Write-Output 'GM FILE NOT FOUND'; continue }
  $src = [System.IO.File]::ReadAllText($file)
  if ($src.Contains('PHI FLOOR DIAG')) { Write-Output 'ALREADY PATCHED'; continue }
  $incAnchor = '#include "TimerManager.h"'
  $tickAnchor = "GetWorldTimerManager().GetTimerRemaining(GPhiTimerHandle));"
  if (-not $src.Contains($incAnchor)) { Write-Output 'ANCHOR MISS: include'; continue }
  if (-not $src.Contains($tickAnchor)) { Write-Output 'ANCHOR MISS: tickproof'; continue }
  $src = $src.Replace($incAnchor, $incAnchor + "`r`n#include ""Components/CapsuleComponent.h""`r`n#include ""GameFramework/CharacterMovementComponent.h""`r`n#include ""Engine/StaticMeshActor.h""`r`n#include ""EngineUtils.h""")
  $diag = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String('CXN0YXRpYyBmbG9hdCBQaGlEaWFnQ2xvY2sgPSAwLmY7CglQaGlEaWFnQ2xvY2sgKz0gRGVsdGFTZWNvbmRzOwoJaWYgKFBoaURpYWdDbG9jayA+PSA2LmYgJiYgUGhpRGlhZ0Nsb2NrIDwgMTAwMC5mKQoJewoJCVBoaURpYWdDbG9jayA9IDIwMDAuZjsKCQlpZiAoQUNoYXJhY3RlciogRGlhZ1Bhd24gPSBDYXN0PEFDaGFyYWN0ZXI+KEdldFBhd24oKSkpCgkJewoJCQlVQ2Fwc3VsZUNvbXBvbmVudCogQ2FwID0gRGlhZ1Bhd24tPkdldENhcHN1bGVDb21wb25lbnQoKTsKCQkJVUNoYXJhY3Rlck1vdmVtZW50Q29tcG9uZW50KiBDTW92ZSA9IERpYWdQYXduLT5HZXRDaGFyYWN0ZXJNb3ZlbWVudCgpOwoJCQlVRV9MT0coTG9nVGVtcCwgRGlzcGxheSwgVEVYVCgiUEhJIEZMT09SIERJQUc6IHdvcmxkPSVzIGNhcEVuYWJsZWQ9JWQgY2FwUHJvZmlsZT0lcyBtb3ZlTW9kZT0lZCBvbkdyb3VuZD0lZCBmbG9vckJsb2NrPSVkIGZsb29yQWN0b3I9JXMiKSwKCQkJCSpHZXRXb3JsZCgpLT5HZXROYW1lKCksCgkJCQlDYXAgPyAoaW50MzIpQ2FwLT5HZXRDb2xsaXNpb25FbmFibGVkKCkgOiAtMSwKCQkJCUNhcCA/ICpDYXAtPkdldENvbGxpc2lvblByb2ZpbGVOYW1lKCkuVG9TdHJpbmcoKSA6IFRFWFQoIm5vbmUiKSwKCQkJCUNNb3ZlID8gKGludDMyKUNNb3ZlLT5Nb3ZlbWVudE1vZGUgOiAtMSwgKENNb3ZlICYmIENNb3ZlLT5Jc01vdmluZ09uR3JvdW5kKCkpID8gMSA6IDAsCgkJCQkoQ01vdmUgJiYgQ01vdmUtPkN1cnJlbnRGbG9vci5iQmxvY2tpbmdIaXQpID8gMSA6IDAsCgkJCQkoQ01vdmUgJiYgQ01vdmUtPkN1cnJlbnRGbG9vci5IaXRSZXN1bHQuR2V0QWN0b3IoKSkgPyAqQ01vdmUtPkN1cnJlbnRGbG9vci5IaXRSZXN1bHQuR2V0QWN0b3IoKS0+R2V0TmFtZSgpIDogVEVYVCgibm9uZSIpKTsKCQkJY29uc3QgRlZlY3RvciBQYXduTG9jID0gRGlhZ1Bhd24tPkdldEFjdG9yTG9jYXRpb24oKTsKCQkJRkhpdFJlc3VsdCBUcmFjZUhpdDsKCQkJY29uc3QgRlZlY3RvciBUcmFjZVN0YXJ0KFBhd25Mb2MuWCwgUGF3bkxvYy5ZLCA1MDAuZik7CgkJCWNvbnN0IEZWZWN0b3IgVHJhY2VFbmQoUGF3bkxvYy5YLCBQYXduTG9jLlksIC01MDAuZik7CgkJCWNvbnN0IGJvb2wgYlRyYWNlID0gR2V0V29ybGQoKS0+TGluZVRyYWNlU2luZ2xlQnlDaGFubmVsKFRyYWNlSGl0LCBUcmFjZVN0YXJ0LCBUcmFjZUVuZCwgRUNDX1dvcmxkU3RhdGljKTsKCQkJVUVfTE9HKExvZ1RlbXAsIERpc3BsYXksIFRFWFQoIlBISSBGTE9PUiBUUkFDRTogaGl0PSVkIGFjdG9yPSVzIGhpdFo9JS4xZiBwYXduWj0lLjFmIiksCgkJCQliVHJhY2UgPyAxIDogMCwgVHJhY2VIaXQuR2V0QWN0b3IoKSA/ICpUcmFjZUhpdC5HZXRBY3RvcigpLT5HZXROYW1lKCkgOiBURVhUKCJub25lIiksCgkJCQlUcmFjZUhpdC5Mb2NhdGlvbi5aLCBQYXduTG9jLlopOwoJCQlpbnQzMiBQcmludGVkID0gMDsKCQkJZm9yIChUQWN0b3JJdGVyYXRvcjxBU3RhdGljTWVzaEFjdG9yPiBJdChHZXRXb3JsZCgpKTsgSXQ7ICsrSXQpCgkJCXsKCQkJCUZWZWN0b3IgT3JpZ2luOyBGVmVjdG9yIEV4dGVudDsKCQkJCUl0LT5HZXRBY3RvckJvdW5kcyhmYWxzZSwgT3JpZ2luLCBFeHRlbnQpOwoJCQkJaWYgKEZNYXRoOjpBYnMoT3JpZ2luLlggLSBQYXduTG9jLlgpIDwgMjUwMC5mICYmIEZNYXRoOjpBYnMoT3JpZ2luLlkgLSBQYXduTG9jLlkpIDwgMjUwMC5mICYmIFByaW50ZWQgPCAxMikKCQkJCXsKCQkJCQkrK1ByaW50ZWQ7CgkJCQkJVUVfTE9HKExvZ1RlbXAsIERpc3BsYXksIFRFWFQoIlBISSBGTE9PUiBBQ1RPUjogbmFtZT0lcyB0b3A9JS4xZiBiYXNlPSUuMWYgbG9jPVg9JS4wZiBZPSUuMGYgWj0lLjBmIGNvbGxFbmFibGVkPSVkIiksCgkJCQkJCSpJdC0+R2V0TmFtZSgpLCBPcmlnaW4uWiArIEV4dGVudC5aLCBPcmlnaW4uWiAtIEV4dGVudC5aLCBPcmlnaW4uWCwgT3JpZ2luLlksIE9yaWdpbi5aLAoJCQkJCQlJdC0+R2V0U3RhdGljTWVzaENvbXBvbmVudCgpID8gKGludDMyKUl0LT5HZXRTdGF0aWNNZXNoQ29tcG9uZW50KCktPkdldENvbGxpc2lvbkVuYWJsZWQoKSA6IC0xKTsKCQkJCX0KCQkJfQoJCX0KCX0K'))
  $idx = $src.IndexOf($tickAnchor)
  $lineEnd = $src.IndexOf("`n", $idx)
  $blockEnd = $src.IndexOf("`n`t}`n}", $lineEnd)
  if ($blockEnd -lt 0) { Write-Output 'ANCHOR MISS: tick block end'; continue }
  $insertAt = $blockEnd + 4
  $src = $src.Substring(0, $insertAt) + "`r`n" + $diag + $src.Substring($insertAt)
  Copy-Item $file "$file.phi-backup-332" -Force
  [System.IO.File]::WriteAllText($file, $src)
  Write-Output 'PATCHED + backup written'
}
Write-Output 'PATCH PHASE DONE'

$uat = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat'
foreach ($g in @(@('VEIL','D:\VEIL','D:\Builds\VEIL\VEIL_DONE','VEIL.exe'), @('OMNI','D:\OMNI-UE','D:\Builds\OMNI\OMNI_DONE','OMNI.exe'))) {
  $name = $g[0]; $proj = $g[1]; $arch = $g[2]; $exename = $g[3]
  "##### BUILD+PROOF $name #####" | Write-Output
  $uproj = Get-ChildItem $proj -Filter '*.uproject' -File | Select-Object -First 1 -ExpandProperty FullName
  $cooklog = "$proj\Saved\diagcook332.log"
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
