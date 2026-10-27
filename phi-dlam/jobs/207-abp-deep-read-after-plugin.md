# Job 207 — ABP deep read, rerun after the plugin DLL exists (jobs 198/200/205 were all aborted by the missing DLL)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$dll = 'D:\VEIL\Plugins\PhiParticleAccelerator\Binaries\Win64\UnrealEditor-PhiParticleAccelerator.dll'
Write-Output '=== Jobs 198, 200 and 205 are now explained by one cause, proven by job 204: the console file ends at the plugin load error - with no PhiParticleAccelerator DLL, every editor commandlet in both projects aborts during startup (exit 1) and the Python script never executes. Job 206 rebuilds the plugin; if its DLL stands, this rerun of the deep read (job 200s script, unchanged) finally executes: ABP parentage via registry tags, graph inventory, node visibility, Countess pack animation census. If the DLL is still absent this job says so and stops - the read cannot run ahead of the plugin. ==='
if (-not (Test-Path $dll)) { Write-Output 'PLUGIN DLL STILL ABSENT - deep read cannot run; job 206s verdict governs.'; return }
Write-Output 'PLUGIN DLL PRESENT - running the deep read'
$console = 'D:\VEIL\Saved\abp-deep2-console.txt'
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\abp_deep_read.py' -unattended -nopause 2>&1 | Set-Content $console
Write-Output "commandlet exit: $LASTEXITCODE"
Select-String -Path $console -Pattern 'ABPDEEP|LogPython|Traceback|Error|Exception' | ForEach-Object { $_.Line }
```
