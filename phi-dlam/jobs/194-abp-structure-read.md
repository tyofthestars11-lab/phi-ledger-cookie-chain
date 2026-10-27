<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = "Continue"
Set-Location "C:\Users\Admin\phi-vault"
if (Test-Path ".git\MERGE_HEAD") { git commit --no-edit }
git pull 2>&1 | Select-Object -Last 1
Write-Output "=== the AnimBlueprint's structure, read before any repair is chosen (job 190's census: one asset, four entanglements with the missing Paragon BP class) ==="
@'
import unreal
abp = unreal.load_asset("/Game/ParagonCountess/Characters/Heroes/Countess/Countess_AnimBlueprint")
print("ABP loaded:", abp)
if abp:
    print("ABP class:", abp.get_class().get_name())
    try:
        print("ABP target skeleton:", abp.get_editor_property("target_skeleton"))
    except Exception as e:
        print("ABP target skeleton: unreadable -", e)
    gen = abp.generated_class()
    print("ABP generated class:", gen.get_name() if gen else None)
    if gen:
        print("ABP parent class:", gen.get_super_class().get_name() if gen.get_super_class() else None)
        print("ABP parent path:", gen.get_super_class().get_path_name() if gen.get_super_class() else None)
    for sub in ("graphs", "function_graphs", "delegate_signature_graphs"):
        try:
            gs = abp.get_editor_property(sub)
            print("ABP %s: %s" % (sub, [g.get_name() for g in gs] if gs else gs))
        except Exception as e:
            print("ABP %s: unreadable - %s" % (sub, e))
'@ | Set-Content "D:\OMNI-UE\Scripts\abp_read.py" -Encoding UTF8
$UEC = "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe"
& $UEC "D:\VEIL\VEIL.uproject" -run=pythonscript -script="D:\OMNI-UE\Scripts\abp_read.py" -abslog="D:\VEIL\Saved\abpread.log" 2>&1 | Out-Null
Select-String -Path "D:\VEIL\Saved\abpread.log" -Pattern "ABP |Traceback|Exception" | ForEach-Object { $_.Line }
Write-Output "=== JOB 194 DONE ==="
```
