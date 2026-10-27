<!-- PHI-DIRECT -->
# JOB 050 - VEIL SOURCE SYNC + BUILD6 (DIRECT)

Tyree's word: "just fix and continue." Job 048's forensics named the errors:
build4 died at the makefile stage on a duplicate filename (Source\VEIL\VEIL.cpp
vs Source\VEIL\Private\VEIL.cpp), and the PC's source tree has diverged from
the repo — PC-only files (VEILAssetStreamer.cpp, VEILUtilityAI.cpp) carry
broken includes and broken string literals that the repo copies do not have.
The repo is the source of truth again: this job backs up the PC tree, mirrors
the repo Source over it, and rebuilds.

## STEP 1 - STOP ANY RUNNING VEIL BUILD
```powershell
$procs = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
"BUILD PROCESSES BEFORE STOP: $(@($procs).Count)"
$procs | Stop-Process -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 2
$after = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match 'UnrealBuildTool|dotnet|cl|link' }
"BUILD PROCESSES AFTER STOP: $(@($after).Count)"
```

## STEP 2 - BACKUP PC SOURCE, PULL REPO, MIRROR SYNC
```powershell
$bak = 'C:\Users\Admin\phi-vault-backups\veil-source-pre-sync-2026-10-27'
if (Test-Path 'D:\VEIL\Source') {
  New-Item -ItemType Directory -Force -Path $bak | Out-Null
  Copy-Item 'D:\VEIL\Source\*' -Destination $bak -Recurse -Force
  "BACKED UP: D:\VEIL\Source -> $bak"
}
$repo = $null
foreach ($cand in @('C:\Users\Admin\phi-vault\phi-ledger-cookie-chain', 'C:\Users\Admin\phi-vault')) {
  if (Test-Path (Join-Path $cand 'veil\VEIL\Source\VEIL')) { $repo = $cand; break }
}
if (-not $repo) { "REPO NOT FOUND - sync aborted, build not started."; return }
git -C $repo pull -q
$srcDir = Join-Path $repo 'veil\VEIL\Source\VEIL'
robocopy $srcDir 'D:\VEIL\Source\VEIL' /MIR /NFL /NDL /NJH | Out-Null
"SYNCED: $srcDir -> D:\VEIL\Source\VEIL (mirror)"
"PC SOURCE FILES NOW: $((Get-ChildItem 'D:\VEIL\Source' -Recurse -File).Count)"
"DUPLICATE CHECK: root VEIL.cpp exists = $(Test-Path 'D:\VEIL\Source\VEIL\VEIL.cpp'); Private VEIL.cpp exists = $(Test-Path 'D:\VEIL\Source\VEIL\Private\VEIL.cpp')"
```

## STEP 3 - START BUILD6 DETACHED
```powershell
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Remove-Item 'D:\VEIL\build6-out.log','D:\VEIL\build6-err.log' -ErrorAction SilentlyContinue
$p = Start-Process -FilePath $build -ArgumentList 'VEILEditor Win64 Development -Project="D:\VEIL\VEIL.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\VEIL\build6-out.log' -RedirectStandardError 'D:\VEIL\build6-err.log' -PassThru -WindowStyle Hidden
"BUILD6 STARTED detached, PID $($p.Id) - logs D:\VEIL\build6-out.log / build6-err.log"
```
