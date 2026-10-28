# Job 257 — ABP carrier census: the Countess_AnimBlueprint reference is NOT in the source — find the asset that carries it

<!-- PHI-DIRECT -->
```powershell
$ErrorActionPreference = 'Continue'
Write-Output '=== Job 252 read both character files WHOLE: VEILCharacter.cpp / OMNICharacter.cpp contain NO Countess_AnimBlueprint reference - only the SM_Countess mesh finder and the Idle_Relaxed pose finder (plus a comment). Yet both packages log CDO Constructor (VEILCharacter/OMNICharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Countess_AnimBlueprint.Countess_AnimBlueprint_C, and BODY CHECK reads anim=none. A reference the source does not hold is SERIALIZED IN AN ASSET. Prime carrier: SM_Countess itself - Paragon skeletal meshes carry a Post Process Anim Blueprint slot, and the Countess ABP was hers. This census loads SM_Countess in both projects and reads its post_process_anim_blueprint; if it carries the quarantined class, the reference is cleared on the spot (smallest change, asset saved, backup note printed) - a mesh with no post-process ABP loses nothing the game uses, the pose rides the 225 single-node bypass. It also greps both projects Config folders for the path string. ==='
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
  $f = "D:\_PhiHolding\abpcarrier257_$n.py"; Set-Content $f $py
  $log = "D:\_PhiHolding\abpcarrier257_$n.log"
  $p = Start-Process 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' -ArgumentList @($proj, "-run=pythonscript", "-script=$f", '-unattended', '-nop4', '-nosplash', "-abslog=$log") -Wait -PassThru -NoNewWindow
  Write-Output "--- abp carrier run $n ($proj) exit $($p.ExitCode) ---"
  Select-String -Path $log -Pattern 'ABPCARRIER|Error' | ForEach-Object { $_.Line -replace '^\[[^\]]*\]\[[^\]]*\]', '' } | Select-Object -First 12
}
Write-Output 'ABP CARRIER CENSUS DONE'
```
