<!-- PHI-DIRECT -->
# JOB 058 - OMNI RPG UNREAL: FIRST BUILD (DIRECT)

Tyree's word (2026-10-27): "Code both games for a real engine." OMNI RPG
now stands as an Unreal project in the repo (veil/OMNI - the proven module,
renamed whole, world builder included). This job stages it at D:\OMNI-UE
and starts its first editor build detached. Verdict sweep is job 059.

```powershell
$repo = 'C:\Users\Admin\phi-vault'
git -C $repo pull -q
robocopy (Join-Path $repo 'veil\OMNI') 'D:\OMNI-UE' /MIR /NFL /NDL /NJH /XD Binaries Intermediate Saved DerivedDataCache | Out-Null
"STAGED: D:\OMNI-UE from repo veil\OMNI"
$build = 'C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat'
Remove-Item 'D:\OMNI-UE\build1-out.log','D:\OMNI-UE\build1-err.log' -ErrorAction SilentlyContinue
$p = Start-Process -FilePath $build -ArgumentList 'OMNIEditor Win64 Development -Project="D:\OMNI-UE\OMNI.uproject" -WaitMutex -FromMsBuild' -RedirectStandardOutput 'D:\OMNI-UE\build1-out.log' -RedirectStandardError 'D:\OMNI-UE\build1-err.log' -PassThru -WindowStyle Hidden
"OMNI BUILD1 STARTED detached, PID $($p.Id)"
"=== JOB 058 DONE (verdict sweep is job 059) ==="
```
