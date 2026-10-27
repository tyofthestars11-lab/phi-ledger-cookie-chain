# Job 210 — ABP deep read, rerun after the module entry fix (the read the whole ABP route waits on)

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
$console = 'D:\VEIL\Saved\abp-deep3-console.txt'
Write-Output '=== The deep read has been gated twice: first by the missing DLL (jobs 198/200/205), then by the modules missing entry point (job 207s CoreUObject crash). Job 209 restores the entry point and proves startup. This job reruns job 200s script unchanged (D:\OMNI-UE\Scripts\abp_deep_read.py): ABP parentage via registry tags, graph inventory incl. the AnimGraph, Python node visibility, Countess pack AnimSequence/AnimMontage/BlendSpace census. Its lines choose the ABP repair route. ==='
& 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' 'D:\VEIL\VEIL.uproject' -run=pythonscript -script='D:\OMNI-UE\Scripts\abp_deep_read.py' -unattended -nopause 2>&1 | Set-Content $console
Write-Output "commandlet exit: $LASTEXITCODE"
Select-String -Path $console -Pattern 'ABPDEEP|LogPython|Traceback|Error|Exception' | ForEach-Object { $_.Line }
```
