# Job 261 — ABP carrier census (re-queue of 257 — 257 never executed: remoting transport break, "(no output)")

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 257 died at the runner transport (PSSessionStateBroken; result "(no output)") - nothing in it ran. Re-queued unchanged in substance: job 252 proved the character SOURCE holds no Countess_AnimBlueprint reference, yet both packages log the CDO Constructor failure - the reference is serialized in an asset. Prime carrier: SM_Countesss Post Process Anim Blueprint slot. Load the mesh in both projects, read the slot, clear it on the spot if it names the quarantined class (asset saved; the pose rides the 225 single-node bypass), and sweep both Config folders for the path string. ==='
foreach ($ini in (Get-ChildItem 'D:\VEIL\Config','D:\OMNI-UE\Config' -Filter *.ini -ErrorAction SilentlyContinue)) {
  $hit = Select-String -Path $ini.FullName -Pattern 'Countess_AnimBlueprint' -ErrorAction SilentlyContinue
  if ($hit) { Write-Output "INI HIT: $($ini.FullName)" }
}
Write-Output 'ini sweep done (silence above = no ini carries it)'
$py = @'
import unreal
mesh = unreal.load_asset("/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess")
if not mesh:
    unreal.log("ABPCARRIER SM_Countess FAILED TO LOAD")
else:
    try:
        pp = mesh.get_editor_property("post_process_anim_blueprint")
        unreal.log("ABPCARRIER post_process_anim_blueprint = %s" % (pp.get_path_name() if pp else "None"))
        if pp and "Countess_AnimBlueprint" in pp.get_path_name():
            mesh.set_editor_property("post_process_anim_blueprint", None)
            unreal.EditorAssetLibrary.save_loaded_asset(mesh)
            unreal.log("ABPCARRIER CLEARED on SM_Countess and asset saved - the quarantined class is no longer referenced by the body")
    except Exception as e:
        unreal.log("ABPCARRIER property path failed: %s" % str(e))
unreal.log("ABPCARRIER DONE")
'@
$n = 0
foreach ($proj in @('D:\VEIL\VEIL.uproject','D:\OMNI-UE\OMNI.uproject')) {
  $n++
  $f = "D:\_PhiHolding\abpcarrier261_$n.py"; Set-Content $f $py
  $log = "D:\_PhiHolding\abpcarrier261_$n.log"
  $p = Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' -ArgumentList @($proj, "-run=pythonscript", "-script=$f", '-unattended', '-nop4', '-nosplash', "-abslog=$log") -Wait -PassThru -NoNewWindow
  Write-Output "--- abp carrier run $n ($proj) exit $($p.ExitCode) ---"
  Select-String -Path $log -Pattern 'ABPCARRIER|Error' | ForEach-Object { $_.Line -replace '^\[[^\]]*\]\[[^\]]*\]', '' } | Select-Object -First 12
}
Write-Output 'ABP CARRIER CENSUS DONE'
```
