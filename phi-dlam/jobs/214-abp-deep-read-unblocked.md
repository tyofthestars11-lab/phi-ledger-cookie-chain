# Job 214 — ABP deep read, first run with an editor that starts (plugin quarantined by job 213)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$console = 'D:\VEIL\Saved\abp-deep4-console.txt'
Write-Output '=== Job 213 removed the plugin from the load path and proved both editors start. Every prior attempt at this read (198/200/207/210) was gated by that plugin. This job runs job 200s script unchanged (D:\OMNI-UE\Scripts\abp_deep_read.py): ABP parentage via registry tags, graph inventory incl. the AnimGraph, Python node visibility, Countess pack AnimSequence/AnimMontage/BlendSpace census. Its lines choose the ABP repair route. ==='
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\abp_deep_read.py' -unattended -nopause 2>&1 | Set-Content $console
Write-Output "commandlet exit: $LASTEXITCODE"
Select-String -Path $console -Pattern 'ABPDEEP|LogPython|Traceback|Error|Exception' | ForEach-Object { $_.Line }
```
