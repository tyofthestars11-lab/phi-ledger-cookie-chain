# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-29 02:40:52 UTC

## STEP 1
```
=== JOB 544 - HUNT THE REAL LINK CALL AND LINK THE LEVELS (Ground: job 542 redesigned the world and saved it, but its link check printed the add call missing on the world object, so the levels still stand unlinked. This job sweeps the editor modules for a streaming level add call, tries each one it finds against the OMNIWorld and VEILWorld maps, and saves only if a link call lands. The job also greps the engine headers for the same call names, so the next step reads the engine itself if Python holds nothing. No game relaunch rides this job. Every variable carries the p544 prefix.) ===
WORLD LAUNCHED pid=27356
CMD POLLS=2 exited=True
PAGE WORLD544 PAGE OPEN
PAGE LEVEL LOADED
PAGE MOD EditorLevelUtils ATTRS=3
PAGE ATTR EditorLevelUtils.add_level_to_world
PAGE ATTR EditorLevelUtils.add_level_to_world_with_transform
PAGE ATTR EditorLevelUtils.create_new_streaming_level
PAGE MOD LevelEditorSubsystem ATTRS=0
PAGE MOD EditorLoadingAndSavingUtils ATTRS=0
PAGE MOD EditorAssetLibrary ATTRS=0
PAGE MOD EditorLevelLibrary ATTRS=0
PAGE WORLD VEILDistrict
PAGE LINK CALL THREW add_level_to_world /Game/Maps/OMNIWorld: add_level_to_world() required argument 'level_streaming_class' (pos 3) not found
PAGE LINK CALL THREW add_level_to_world /Game/Maps/OMNIWorld: add_level_to_world() required argument 'level_package_name' (pos 2) not found
PAGE LINK CALL THREW add_level_to_world /Game/Maps/OMNIWorld: EditorLevelUtils: Failed to convert parameter 'level_streaming_class' when calling function 'EditorLevelUtils.K2_AddLevelToWorld' on 'Default__EditorLevelUtils'
PAGE   TypeError: NativizeProperty: Cannot nativize 'bool' as 'LevelStreamingClass' (ClassProperty)
PAGE     TypeError: NativizeClass: Cannot nativize 'bool' as 'Class' (allowed Class type: 'LevelStreaming')
PAGE       TypeError: NativizeObject: Cannot nativize 'bool' as 'Object' (allowed Class type: 'Class')
PAGE LINK CALL THREW add_level_to_world_with_transform /Game/Maps/OMNIWorld: add_level_to_world_with_transform() required argument 'level_streaming_class' (pos 3) not found
PAGE LINK CALL THREW add_level_to_world_with_transform /Game/Maps/OMNIWorld: add_level_to_world_with_transform() required argument 'level_package_name' (pos 2) not found
PAGE LINK CALL THREW add_level_to_world_with_transform /Game/Maps/OMNIWorld: add_level_to_world_with_transform() required argument 'level_transform' (pos 4) not found
PAGE LINK CALL THREW create_new_streaming_level /Game/Maps/OMNIWorld: EditorLevelUtils: Failed to convert parameter 'level_streaming_class' when calling function 'EditorLevelUtils.CreateNewStreamingLevel' on 'Default__EditorLevelUtils'
PAGE   TypeError: NativizeProperty: Cannot nativize 'World' as 'LevelStreamingClass' (ClassProperty)
PAGE     TypeError: NativizeClass: Cannot nativize 'World' as 'Class' (allowed Class type: 'LevelStreaming')
PAGE       TypeError: NativizeObject: Cannot nativize 'World' as 'Object' (allowed Class type: 'Class')
PAGE LINK CALL THREW create_new_streaming_level /Game/Maps/OMNIWorld: EditorLevelUtils: Failed to convert parameter 'level_streaming_class' when calling function 'EditorLevelUtils.CreateNewStreamingLevel' on 'Default__EditorLevelUtils'
PAGE   TypeError: NativizeProperty: Cannot nativize 'str' as 'LevelStreamingClass' (ClassProperty)
PAGE     TypeError: NativizeClass: Cannot nativize 'str' as 'Class' (allowed Class type: 'LevelStreaming')
PAGE       TypeError: NativizeObject: Cannot nativize 'str' as 'Object' (allowed Class type: 'Class')
PAGE LINK CALL THREW create_new_streaming_level /Game/Maps/OMNIWorld: EditorLevelUtils: Failed to convert parameter 'level_streaming_class' when calling function 'EditorLevelUtils.CreateNewStreamingLevel' on 'Default__EditorLevelUtils'
PAGE   TypeError: NativizeProperty: Cannot nativize 'World' as 'LevelStreamingClass' (ClassProperty)
PAGE     TypeError: NativizeClass: Cannot nativize 'World' as 'Class' (allowed Class type: 'LevelStreaming')
PAGE       TypeError: NativizeObject: Cannot nativize 'World' as 'Object' (allowed Class type: 'Class')
PAGE LINK NOT DONE /Game/Maps/OMNIWorld
PAGE LINK CALL THREW add_level_to_world /Game/Maps/VEILWorld: add_level_to_world() required argument 'level_streaming_class' (pos 3) not found
PAGE LINK CALL THREW add_level_to_world /Game/Maps/VEILWorld: add_level_to_world() required argument 'level_package_name' (pos 2) not found
PAGE LINK CALL THREW add_level_to_world /Game/Maps/VEILWorld: EditorLevelUtils: Failed to convert parameter 'level_streaming_class' when calling function 'EditorLevelUtils.K2_AddLevelToWorld' on 'Default__EditorLevelUtils'
PAGE   TypeError: NativizeProperty: Cannot nativize 'bool' as 'LevelStreamingClass' (ClassProperty)
PAGE     TypeError: NativizeClass: Cannot nativize 'bool' as 'Class' (allowed Class type: 'LevelStreaming')
PAGE       TypeError: NativizeObject: Cannot nativize 'bool' as 'Object' (allowed Class type: 'Class')
PAGE LINK CALL THREW add_level_to_world_with_transform /Game/Maps/VEILWorld: add_level_to_world_with_transform() required argument 'level_streaming_class' (pos 3) not found
PAGE LINK CALL THREW add_level_to_world_with_transform /Game/Maps/VEILWorld: add_level_to_world_with_transform() required argument 'level_package_name' (pos 2) not found
PAGE LINK CALL THREW add_level_to_world_with_transform /Game/Maps/VEILWorld: add_level_to_world_with_transform() required argument 'level_transform' (pos 4) not found
PAGE LINK CALL THREW create_new_streaming_level /Game/Maps/VEILWorld: EditorLevelUtils: Failed to convert parameter 'level_streaming_class' when calling function 'EditorLevelUtils.CreateNewStreamingLevel' on 'Default__EditorLevelUtils'
PAGE   TypeError: NativizeProperty: Cannot nativize 'World' as 'LevelStreamingClass' (ClassProperty)
PAGE     TypeError: NativizeClass: Cannot nativize 'World' as 'Class' (allowed Class type: 'LevelStreaming')
PAGE       TypeError: NativizeObject: Cannot nativize 'World' as 'Object' (allowed Class type: 'Class')
PAGE LINK CALL THREW create_new_streaming_level /Game/Maps/VEILWorld: EditorLevelUtils: Failed to convert parameter 'level_streaming_class' when calling function 'EditorLevelUtils.CreateNewStreamingLevel' on 'Default__EditorLevelUtils'
PAGE   TypeError: NativizeProperty: Cannot nativize 'str' as 'LevelStreamingClass' (ClassProperty)
PAGE     TypeError: NativizeClass: Cannot nativize 'str' as 'Class' (allowed Class type: 'LevelStreaming')
PAGE       TypeError: NativizeObject: Cannot nativize 'str' as 'Object' (allowed Class type: 'Class')
PAGE LINK CALL THREW create_new_streaming_level /Game/Maps/VEILWorld: EditorLevelUtils: Failed to convert parameter 'level_streaming_class' when calling function 'EditorLevelUtils.CreateNewStreamingLevel' on 'Default__EditorLevelUtils'
PAGE   TypeError: NativizeProperty: Cannot nativize 'World' as 'LevelStreamingClass' (ClassProperty)
PAGE     TypeError: NativizeClass: Cannot nativize 'World' as 'Class' (allowed Class type: 'LevelStreaming')
PAGE       TypeError: NativizeObject: Cannot nativize 'World' as 'Object' (allowed Class type: 'Class')
PAGE LINK NOT DONE /Game/Maps/VEILWorld
PAGE LINKED=0
PAGE SAVE SKIPPED - NO LINK CALL
PAGE WORLD544 DONE
HEADER 	UFUNCTION(BlueprintCallable, Category = "Editor Scripting | Level Creation", meta=(DisplayName="Add Level to World", ScriptName="AddLevelToWorld"))
HEADER 	static ULevelStreaming* K2_AddLevelToWorld(UWorld* World, const FString& LevelPackageName, UPARAM(meta = (AllowAbstract = "false")) TSubclassOf<ULevelStreaming> LevelStreamingClass)
HEADER 		return AddLevelToWorld(World, *LevelPackageName, LevelStreamingClass, FTransform::Identity);
HEADER 	UFUNCTION(BlueprintCallable, Category = "Editor Scripting | Level Creation", meta=(DisplayName="Add Level to World with Transform", ScriptName="AddLevelToWorldWithTransform"))
HEADER 	static ULevelStreaming* K2_AddLevelToWorldWithTransform(UWorld* World, const FString& LevelPackageName, UPARAM(meta = (AllowAbstract = "false")) TSubclassOf<ULevelStreaming> LevelStreamingClass, const FTransform& LevelTransform)
HEADER 	UE_API void AddStreamingLevel(ULevelStreaming* StreamingLevelToAdd);
HEADER 	UE_API void AddStreamingLevels(TArrayView<ULevelStreaming* const> StreamingLevelsToAdd);	
HEADER 	DECLARE_EVENT_ThreeParams(UWorld, FAddLevelToWorldExtensionEvent, ULevel* /*InLevel*/, const bool /*bWaitForCompletion*/, bool& /*bOutHasCompleted*/);
HEADER 	FAddLevelToWorldExtensionEvent AddLevelToWorldExtensionEvent;
HEADER 	FAddLevelToWorldExtensionEvent& OnAddLevelToWorldExtension()
PHI P544 VERDICT: LINK PAGE PRINTED ABOVE
JOB 544 DONE

```
