# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 23:34:27 UTC

## STEP 1
```
=== Job 214 finally executed the deep read - and named two instrument faults, both now corrected. (1) Python print() never reaches this lanes console capture (the scripts earlier lines ran and vanished; only UE_LOG lines and tracebacks surface) - this script writes every finding to D:\VEIL\Saved\abp_deep_out.txt and the job prints that file. (2) The census crashed at AssetData.object_path, which UE 5.8 does not expose; paths are built from package_name + asset_name instead. Same questions as always: ABP parentage via registry tags, graph inventory incl. the AnimGraph, node visibility, Countess pack animation census. ===
[2026.10.27-23.34.33:180][  0]LogObj: Error: LoadConfig (/Script/EngineSettings.Default__GeneralProjectSettings): import failed for ProjectID in: 451B8EAC-A89D-495A-A347-31670EA913C3
[2026.10.27-23.34.34:933][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] COMPILER ERROR: failed building connection with 'Object Reference is not compatible with Object Reference.' at  Set Character
[2026.10.27-23.34.34:935][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  Object  and  ReturnValue : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.34.34:935][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  AsCountess Player Character  no longer exists on node  Bad cast node . Please refresh node or break links to remove pin.
[2026.10.27-23.34.34:935][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  Object  and  ReturnValue : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.34.34:935][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  AsCountess Player Character  no longer exists on node  Bad cast node . Please refresh node or break links to remove pin.
[2026.10.27-23.34.34:935][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ResetCombo . Please refresh node or break links to remove pin.
[2026.10.27-23.34.34:935][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  Target  no longer exists on node  ResetCombo . Please refresh node or break links to remove pin.
[2026.10.27-23.34.34:935][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Could not find a function named "ResetCombo" in 'Countess_AnimBlueprint'.
[2026.10.27-23.34.34:935][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  ReturnValue  and  Object : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.34.34:935][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ComboAttackSave . Please refresh node or break links to remove pin.
[2026.10.27-23.34.34:935][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  Target  no longer exists on node  ComboAttackSave . Please refresh node or break links to remove pin.
[2026.10.27-23.34.34:935][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Could not find a function named "ComboAttackSave" in 'Countess_AnimBlueprint'.
[2026.10.27-23.34.34:936][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  ReturnValue  and  Object : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.34.34:936][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  Object  and  ReturnValue : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.34.34:936][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  AsCountess Player Character  no longer exists on node  Bad cast node . Please refresh node or break links to remove pin.
[2026.10.27-23.34.34:936][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  ReturnValue  and  Object : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.34.34:937][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] This blueprint (self) is not compatible with ' Target ', therefore that pin must have a connection.
[2026.10.27-23.34.34:938][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Attacking_Event_0  : unable to determine expected signature - is the delegate pin connected?
[2026.10.27-23.34.34:938][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Event Dispatcher has no property  Assign <invalid delegate>
[2026.10.27-23.34.34:938][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Failed to create property K2Node_CreateDelegate_OutputDelegate from  <None>  due to a bad or unknown type (Delegate)
[2026.10.27-23.34.34:939][  0]LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Attacking_Event_0  Signature Error: Unable to determine expected signature - is the delegate pin connected?
[2026.10.27-23.34.36:784][  0]LogPython: Warning: ABPDEEP function_graphs ERROR: AnimBlueprint: Failed to find property 'function_graphs' for attribute 'function_graphs' on 'AnimBlueprint'
[2026.10.27-23.34.36:784][  0]LogPython: Warning: ABPDEEP macro_graphs ERROR: AnimBlueprint: Failed to find property 'macro_graphs' for attribute 'macro_graphs' on 'AnimBlueprint'
[2026.10.27-23.34.36:784][  0]LogPython: Warning: ABPDEEP delegate_signature_graphs ERROR: AnimBlueprint: Failed to find property 'delegate_signature_graphs' for attribute 'delegate_signature_graphs' on 'AnimBlueprint'
[2026.10.27-23.34.36:784][  0]LogPython: Warning: ABPDEEP ubergraph_pages ERROR: AnimBlueprint: Failed to find property 'ubergraph_pages' for attribute 'ubergraph_pages' on 'AnimBlueprint'
[2026.10.27-23.34.36:784][  0]LogPython: Warning: ABPDEEP animation_graphs ERROR: AnimBlueprint: Failed to find property 'animation_graphs' for attribute 'animation_graphs' on 'AnimBlueprint'
[2026.10.27-23.34.36:798][  0]LogInit: Display: Warning/Error Summary (Unique only)
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogObj: Error: LoadConfig (/Script/EngineSettings.Default__GeneralProjectSettings): import failed for ProjectID in: 451B8EAC-A89D-495A-A347-31670EA913C3
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] COMPILER ERROR: failed building connection with 'Object Reference is not compatible with Object Reference.' at  Set Character
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  Object  and  ReturnValue : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  AsCountess Player Character  no longer exists on node  Bad cast node . Please refresh node or break links to remove pin.
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ResetCombo . Please refresh node or break links to remove pin.
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  Target  no longer exists on node  ResetCombo . Please refresh node or break links to remove pin.
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Could not find a function named "ResetCombo" in 'Countess_AnimBlueprint'.
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  ReturnValue  and  Object : This cast has an invalid target type (was the class deleted without a redirect?).
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ComboAttackSave . Please refresh node or break links to remove pin.
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  Target  no longer exists on node  ComboAttackSave . Please refresh node or break links to remove pin.
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Could not find a function named "ComboAttackSave" in 'Countess_AnimBlueprint'.
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] This blueprint (self) is not compatible with ' Target ', therefore that pin must have a connection.
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Attacking_Event_0  : unable to determine expected signature - is the delegate pin connected?
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Event Dispatcher has no property  Assign <invalid delegate>
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Failed to create property K2Node_CreateDelegate_OutputDelegate from  <None>  due to a bad or unknown type (Delegate)
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Attacking_Event_0  Signature Error: Unable to determine expected signature - is the delegate pin connected?
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogPython: Warning: ABPDEEP function_graphs ERROR: AnimBlueprint: Failed to find property 'function_graphs' for attribute 'function_graphs' on 'AnimBlueprint'
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogPython: Warning: ABPDEEP macro_graphs ERROR: AnimBlueprint: Failed to find property 'macro_graphs' for attribute 'macro_graphs' on 'AnimBlueprint'
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogPython: Warning: ABPDEEP delegate_signature_graphs ERROR: AnimBlueprint: Failed to find property 'delegate_signature_graphs' for attribute 'delegate_signature_graphs' on 'AnimBlueprint'
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogPython: Warning: ABPDEEP ubergraph_pages ERROR: AnimBlueprint: Failed to find property 'ubergraph_pages' for attribute 'ubergraph_pages' on 'AnimBlueprint'
[2026.10.27-23.34.36:798][  0]LogInit: Display: LogPython: Warning: ABPDEEP animation_graphs ERROR: AnimBlueprint: Failed to find property 'animation_graphs' for attribute 'animation_graphs' on 'AnimBlueprint'
[2026.10.27-23.34.36:799][  0]LogInit: Display: Failure - 22 error(s), 102 warning(s)
commandlet exit: 1
--- abp_deep_out.txt ---
ABPDEEP asset found: True
ABPDEEP tag ParentClass = None
ABPDEEP tag NativeParentClass = None
ABPDEEP tag GeneratedClass = None
ABPDEEP tag Skeleton = None
ABPDEEP tag TargetSkeleton = None
ABPDEEP loaded: True
ABPDEEP class: AnimBlueprint
ABPDEEP function_graphs ERROR: AnimBlueprint: Failed to find property 'function_graphs' for attribute 'function_graphs' on 'AnimBlueprint'
ABPDEEP macro_graphs ERROR: AnimBlueprint: Failed to find property 'macro_graphs' for attribute 'macro_graphs' on 'AnimBlueprint'
ABPDEEP delegate_signature_graphs ERROR: AnimBlueprint: Failed to find property 'delegate_signature_graphs' for attribute 'delegate_signature_graphs' on 'AnimBlueprint'
ABPDEEP ubergraph_pages ERROR: AnimBlueprint: Failed to find property 'ubergraph_pages' for attribute 'ubergraph_pages' on 'AnimBlueprint'
ABPDEEP animation_graphs ERROR: AnimBlueprint: Failed to find property 'animation_graphs' for attribute 'animation_graphs' on 'AnimBlueprint'
ABPDEEP CENSUS total assets under /Game/ParagonCountess: 2729
ABPDEEP CENSUS AimOffsetBlendSpace: 2
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/Idle_AO.Idle_AO
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/TravelMode_AO.TravelMode_AO
ABPDEEP CENSUS AnimBlueprint: 1
ABPDEEP CENSUS AnimMontage: 4
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/LevelStart_Montage.LevelStart_Montage
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Primary_Attack_A_Normal_Montage.Primary_Attack_A_Normal_Montage
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Primary_Attack_B_Normal_Montage.Primary_Attack_B_Normal_Montage
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Primary_Attack_Normal_Montage.Primary_Attack_Normal_Montage
ABPDEEP CENSUS AnimSequence: 234
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_E.Ability_E
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_E_Jog_Fwd.Ability_E_Jog_Fwd
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_E_Jog_Fwd_MSA.Ability_E_Jog_Fwd_MSA
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_E_MSA.Ability_E_MSA
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_E_target.Ability_E_target
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_E_target_additive.Ability_E_target_additive
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_E_target_transition.Ability_E_target_transition
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_E_target_transition_MSA.Ability_E_target_transition_MSA
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_Q.Ability_Q
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_Q_Jog_Fwd.Ability_Q_Jog_Fwd
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_Q_Jog_Fwd_MSA.Ability_Q_Jog_Fwd_MSA
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_Q_MSA.Ability_Q_MSA
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_Q_target.Ability_Q_target
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_Q_target_additive.Ability_Q_target_additive
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_Q_target_transition.Ability_Q_target_transition
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_Q_target_transition_MSA.Ability_Q_target_transition_MSA
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_RMB.Ability_RMB
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_RMB_InMotion.Ability_RMB_InMotion
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_RMB_InMotion_MSA.Ability_RMB_InMotion_MSA
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_R_Jog_Fwd.Ability_R_Jog_Fwd
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_R_Jog_Fwd_MSA.Ability_R_Jog_Fwd_MSA
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_R_target.Ability_R_target
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_R_target_additive.Ability_R_target_additive
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_R_target_transition.Ability_R_target_transition
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_R_target_transition_MSA.Ability_R_target_transition_MSA
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_Ultimate.Ability_Ultimate
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_Ultimate_InMotion.Ability_Ultimate_InMotion
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Ability_Ultimate_MSA.Ability_Ultimate_MSA
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/Idle_AO_CC.Idle_AO_CC
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/Idle_AO_CD.Idle_AO_CD
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/Idle_AO_CU.Idle_AO_CU
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/Idle_AO_LBC.Idle_AO_LBC
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/Idle_AO_LBD.Idle_AO_LBD
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/Idle_AO_LBU.Idle_AO_LBU
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/Idle_AO_LC.Idle_AO_LC
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/Idle_AO_LD.Idle_AO_LD
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/Idle_AO_LU.Idle_AO_LU
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/Idle_AO_RBC.Idle_AO_RBC
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/Idle_AO_RBD.Idle_AO_RBD
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/AimOffsets/Idle_AO_RBU.Idle_AO_RBU
ABPDEEP CENSUS BlendSpace: 8
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Blendspaces/JogBwdSlopeLean.JogBwdSlopeLean
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Blendspaces/JogFwdSlopeLean.JogFwdSlopeLean
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Blendspaces/JogLeftSlopeLean.JogLeftSlopeLean
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Blendspaces/JogRightSlopeLean.JogRightSlopeLean
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Blendspaces/SprintBwdSlopeLean.SprintBwdSlopeLean
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Blendspaces/SprintFwdSlopeLean.SprintFwdSlopeLean
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Blendspaces/SprintLeftSlopeLean.SprintLeftSlopeLean
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Blendspaces/SprintRightSlopeLean.SprintRightSlopeLean
ABPDEEP CENSUS BlendSpace1D: 1
ABPDEEP   /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Blendspaces/TurnInPlace.TurnInPlace
ABPDEEP CENSUS DialogueVoice: 3
ABPDEEP CENSUS DialogueWave: 595
ABPDEEP CENSUS MapBuildDataRegistry: 3
ABPDEEP CENSUS Material: 85
ABPDEEP CENSUS MaterialFunction: 65
ABPDEEP CENSUS MaterialInstanceConstant: 42
ABPDEEP CENSUS MaterialParameterCollection: 2
ABPDEEP CENSUS ObjectRedirector: 420
ABPDEEP CENSUS ParticleSystem: 40
ABPDEEP CENSUS PhysicsAsset: 4
ABPDEEP CENSUS Rig: 1
ABPDEEP CENSUS SkeletalMesh: 5
ABPDEEP CENSUS Skeleton: 1
ABPDEEP CENSUS SoundCue: 298
ABPDEEP CENSUS SoundWave: 662
ABPDEEP CENSUS StaticMesh: 22
ABPDEEP CENSUS SubsurfaceProfile: 5
ABPDEEP CENSUS Texture2D: 218
ABPDEEP CENSUS TextureCube: 2
ABPDEEP CENSUS VectorFieldStatic: 3
ABPDEEP CENSUS World: 3
ABPDEEP DONE

```
