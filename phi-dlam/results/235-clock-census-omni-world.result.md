# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 00:09:37 UTC

## STEP 1
```
=== Job 234s twin for OMNI: identical reflection commandlet in the OMNI module, map OMNIWorld. Both games carry the same frozen-clock signature (PC ticks, real DeltaSeconds, TimeSeconds 0.00, pawn Tick 0), so both WorldSettings classes get read in the engines own property names - no invented spellings. Same run also reflects UNavigationSystemV1s Build/Lock function names for the nav lock. ===
Build.cs patched: editor-only UnrealEd + NavigationSystem deps added at the end of the module constructor (backup in src-backup-235).
Commandlet source written: Public\ClockCensusCommandlet.h + Private\ClockCensusCommandlet.cpp
Result: Succeeded
[2026.10.28-00.10.08:150][  0]LogObj: Error: LoadConfig (/Script/EngineSettings.Default__GeneralProjectSettings): import failed for ProjectID in: DC5E4CF1-FD4D-485E-98F1-2B96AF43DB4C
[2026.10.28-00.10.11:596][  0]LogInit: Display: Warning/Error Summary (Unique only)
[2026.10.28-00.10.11:596][  0]LogInit: Display: LogObj: Error: LoadConfig (/Script/EngineSettings.Default__GeneralProjectSettings): import failed for ProjectID in: DC5E4CF1-FD4D-485E-98F1-2B96AF43DB4C
[2026.10.28-00.10.11:596][  0]LogInit: Display: Failure - 1 error(s), 4 warning(s)
--- clock_census_OMNIWorld.txt ---
CLOCKCENSUS map=/Game/Maps/OMNIWorld loaded=1
WORLD OMNIWorld
== UWorld (clock words) ==
PROP AuthorityGameMode = None
PROP GameState = None
PROP ComponentsThatNeedPreEndOfFrameSync_AsyncTick = ()
PROP ComponentsThatNeedEndOfFrameUpdate_AsyncTick = 
== AWorldSettings (ALL properties) ==
PROP VisibilityCellSize = 200
PROP VisibilityAggressiveness = VIS_LeastAggressive
PROP bPrecomputeVisibility = False
PROP bPlaceCellsOnlyAlongCameraTracks = False
PROP bEnableWorldBoundsChecks = True
PROP bEnableNavigationSystem = True
PROP bEnableAISystem = True
PROP bUseAutomaticUGCNavigation = False
PROP bEnableWorldComposition = False
PROP bUseClientSideLevelStreamingVolumes = False
PROP bEnableWorldOriginRebasing = False
PROP bWorldGravitySet = False
PROP bGlobalGravitySet = False
PROP bMinimizeBSPSections = False
PROP bForceNoPrecomputedLighting = False
PROP bForceVolumetricLightmapsOnly = False
PROP bHighPriorityLoading = False
PROP bHighPriorityLoadingLocal = False
PROP bOverrideDefaultBroadphaseSettings = False
PROP bGenerateSingleClusterForLevel = False
PROP bAllowTimeDilation = True
PROP DynamicLoadingRangeScaling = (InitialDynamicLoadingRangeScaling=100.000000,DynamicLoadingRangeScalingDuration=10.000000)
PROP bHideEnableStreamingWarning = False
PROP bIncludeGridSizeInNameForFoliageActors = False
PROP bIncludeGridSizeInNameForPartitionedActors = False
PROP bReuseAddressAndPort = False
PROP AISystemClass = /Script/AIModule.AISystem
PROP LevelInstancePivotOffset = (X=0.000000,Y=0.000000,Z=0.000000)
PROP NavigationSystemConfig = /Script/NavigationSystem.NavigationSystemModuleConfig'/Game/Maps/OMNIWorld.OMNIWorld:PersistentLevel.WorldSettings.NavigationSystemModuleConfig_0'
PROP NavigationSystemConfigOverride = None
PROP WorldPartition = None
PROP InstancedFoliageGridSize = 25600
PROP bShowInstancedFoliageGrid = False
PROP LandscapeSplineMeshesGridSize = 25600
PROP NavigationDataChunkGridSize = 102400
PROP NavigationDataBuilderLoadingCellSize = 409600
PROP DefaultPlacementGridSize = 25600
PROP BaseNavmeshDataLayers = 
PROP WorldToMeters = 100.000000
PROP KillZ = -1048575.000000
PROP KillZDamageType = /Script/Engine.BlueprintGeneratedClass'/Engine/EngineDamageTypes/DmgTypeBP_Environmental.DmgTypeBP_Environmental_C'
PROP WorldGravityZ = -980.000000
PROP GlobalGravityZ = 0.000000
PROP DefaultPhysicsVolumeClass = /Script/CoreUObject.Class'/Script/Engine.DefaultPhysicsVolume'
PROP PhysicsCollisionHandlerClass = None
PROP DefaultGameMode = None
PROP GameNetworkManagerClass = /Script/CoreUObject.Class'/Script/Engine.GameNetworkManager'
PROP PackedLightAndShadowMapTextureSize = 1024
PROP DefaultColorScale = (X=1.000000,Y=1.000000,Z=1.000000)
PROP DefaultMaxDistanceFieldOcclusionDistance = 600.000000
PROP GlobalDistanceFieldViewDistance = 20000.000000
PROP DynamicIndirectShadowsSelfShadowingIntensity = 0.800000
PROP LightmassSettings = (StaticLightingLevelScale=1.000000,NumIndirectLightingBounces=3,NumSkyLightingBounces=1,IndirectLightingQuality=1.000000,IndirectLightingSmoothness=1.000000,EnvironmentColor=(B=0,G=0,R=0,A=0),EnvironmentIntensity=1.000000,EmissiveBoost=1.000000,DiffuseBoost=1.000000,bCompressLightmaps=True,VolumetricLightmapDetailCellSize=200.000000,VolumetricLightmapMaximumBrickMemoryMb=30.000000,VolumetricLightmapLoadingCellSize=3200.000000,VolumetricLightmapSphericalHarmonicSmoothing=0.020000,VolumeLightSamplePlacementScale=1.000000,DirectIlluminationOcclusionFraction=0.500000,IndirectIlluminationOcclusionFraction=1.000000,OcclusionExponent=1.000000,FullyOccludedSamplesFraction=1.000000,MaxOcclusionDistance=200.000000)
PROP VolumetricLightmapLoadingRange = 6400.000000
PROP NaniteSettings = (bAllowMaskedMaterials=True)
PROP DefaultReverbSettings = (bApplyReverb=True,Volume=0.500000,FadeTime=2.000000)
PROP DefaultAmbientZoneSettings = (bIsWorldSettings=True,ExteriorVolume=1.000000,ExteriorTime=0.500000,ExteriorLPF=20000.000000,ExteriorLPFTime=0.500000,InteriorVolume=1.000000,InteriorTime=0.500000,InteriorLPF=20000.000000,InteriorLPFTime=0.500000)
PROP DefaultBaseSoundMix = None
PROP HLODSetupAsset = None
PROP OverrideBaseMaterial = None
PROP HierarchicalLODSetup = 
PROP NumHLODLevels = 0
PROP HLODBakingTransform = (Rotation=(X=0.000000,Y=0.000000,Z=0.000000,W=1.000000),Translation=(X=0.000000,Y=0.000000,Z=0.000000),Scale3D=(X=1.000000,Y=1.000000,Z=1.000000))
PROP BookMarks = None
PROP TimeDilation = 1.000000
PROP CinematicTimeDilation = 1.000000
PROP DemoPlayTimeDilation = 1.000000
PROP MinGlobalTimeDilation = 0.000100
PROP MaxGlobalTimeDilation = 20.000000
PROP MinCinematicTimeDilation = 0.000100
PROP MaxCinematicTimeDilation = 20.000000
PROP MinUndilatedFrameTime = 0.000500
PROP MaxUndilatedFrameTime = 0.400000
PROP BroadphaseSettings = (MBPBounds=(Min=(X=0.000000,Y=0.000000,Z=0.000000),Max=(X=0.000000,Y=0.000000,Z=0.000000),IsValid=False),MBPOuterBounds=(Min=(X=0.000000,Y=0.000000,Z=0.000000),Max=(X=0.000000,Y=0.000000,Z=0.000000),IsValid=False),MBPNumSubdivs=2)
PROP ReplicationViewers = 
PROP AssetUserData = 
PROP AssetUserDataEditorOnly = 
PROP PauserPlayerState = None
PROP DefaultWorldPartitionSettings = ()
PROP MaxNumberOfBookmarks = 10
PROP DefaultBookmarkClass = /Script/CoreUObject.Class'/Script/Engine.BookMark'
PROP BookmarkArray = (None,None,None,None,None,None,None,None,None,None)
PROP LastBookmarkClass = /Script/CoreUObject.Class'/Script/Engine.BookMark'
PROP DefaultBookmark = None
PROP bEnableHierarchicalLODSystem = True
PROP bEnableLargeWorlds = False
PROP SpriteComponent = None
PROP PrimaryActorTick = (bStartWithTickEnabled=True,bAllowTickOnDedicatedServer=True)
PROP bNetTemporary = False
PROP bOnlyRelevantToOwner = False
PROP bAlwaysRelevant = True
PROP bReplicateMovement = False
PROP bCallPreReplication = True
PROP bCallPreReplicationForReplay = True
PROP bHidden = False
PROP bTearOff = False
PROP bForceNetAddressable = False
PROP LevelInstanceType = None
PROP LevelInstanceFlags = None
PROP bIsMainWorldOnly = False
PROP bIgnoreInPIE = False
PROP bForceDuplicateInPIE = False
PROP bExchangedRoles = False
PROP bNetLoadOnClient = True
PROP bNetUseOwnerRelevancy = False
PROP bRelevantForNetworkReplays = True
PROP bRelevantForLevelBounds = True
PROP bReplayRewindable = True
PROP bAllowTickBeforeBeginPlay = True
PROP bAutoDestroyWhenFinished = False
PROP bCanBeDamaged = False
PROP bBlockInput = False
PROP bCollideWhenPlacing = False
PROP bFindCameraComponentWhenViewTarget = True
PROP bGenerateOverlapEventsDuringLevelStreaming = False
PROP bIgnoresOriginShifting = False
PROP bEnableAutoLODGeneration = False
PROP bIsEditorOnlyActor = False
PROP bReplicates = True
PROP bCanBeInCluster = False
PROP bMigratingAsset = False
PROP bAllowReceiveTickEventOnDedicatedServer = True
PROP bReplicateUsingRegisteredSubObjectList = False
PROP bActorEnableCollision = True
PROP bActorIsBeingDestroyed = False
PROP bAsyncPhysicsTickEnabled = False
PROP UpdateOverlapsMethodDuringLevelStreaming = UseConfigDefault
PROP DefaultUpdateOverlapsMethodDuringLevelStreaming = OnlyUpdateMovable
PROP RemoteRole = ROLE_SimulatedProxy
PROP InitialLifeSpan = 0.000000
PROP CustomTimeDilation = 1.000000
PROP RayTracingGroupId = -1
PROP GridPlacement = None
PROP RuntimeGrid = None
PROP AttachmentReplication = (LocationOffset=(X=0.000000,Y=0.000000,Z=0.000000),RelativeScale3D=(X=0.000000,Y=0.000000,Z=0.000000),RotationOffset=(Pitch=0.000000,Yaw=0.000000,Roll=0.000000))
PROP ReplicatedMovement = ()
PROP Owner = None
PROP NetDriverName = GameNetDriver
PROP Role = ROLE_Authority
PROP NetDormancy = DORM_Awake
PROP SpawnCollisionHandlingMethod = AlwaysSpawn
PROP AutoReceiveInput = Disabled
PROP InputPriority = 0
PROP InputComponent = None
PROP NetTag = 0
PROP NetCullDistanceSquared = 225000000.000000
PROP NetUpdateFrequency = 10.000000
PROP MinNetUpdateFrequency = 2.000000
PROP NetPriority = 1.000000
PROP PhysicsReplicationMode = Default
PROP Instigator = None
PROP Children = 
PROP RootComponent = None
PROP PivotOffset = (X=0.000000,Y=0.000000,Z=0.000000)
PROP HLODLayer = None
PROP ObjectsDetachedFromExternalPackage = 
PROP Layers = 
PROP ParentComponentActor = None
PROP ParentComponent = None
PROP ActorGuid = 98D14CEC4841E2E9B3B179A9885A77F6
PROP ActorInstanceGuid = 00000000000000000000000000000000
PROP ContentBundleGuid = 00000000000000000000000000000000
PROP DataLayers = 
PROP DataLayerAssets = 
PROP ExternalDataLayerAsset = None
PROP GroupActor = None
PROP SpriteScale = 1.000000
PROP HiddenEditorViews = 0
PROP ActorLabel = WorldSettings
PROP FolderPath = None
PROP FolderGuid = 00000000000000000000000000000000
PROP bHiddenEd = False
PROP bIsEditorPreviewActor = False
PROP bHiddenEdLayer = False
PROP bHiddenEdLevel = False
PROP bLockLocation = False
PROP bActorLabelEditable = False
PROP bEditable = True
PROP bListedInSceneOutliner = True
PROP bOptimizeBPComponentData = False
PROP bCanPlayFromHere = False
PROP bIsSpatiallyLoaded = False
PROP bHiddenEdTemporary = False
PROP bForceExternalActorLevelReferenceForPIE = False
PROP Tags = 
PROP OnTakeAnyDamage = ()
PROP OnTakePointDamage = ()
PROP OnTakeRadialDamage = ()
PROP OnActorBeginOverlap = ()
PROP OnActorEndOverlap = ()
PROP OnBeginCursorOver = ()
PROP OnEndCursorOver = ()
PROP OnClicked = ()
PROP OnReleased = ()
PROP OnInputTouchBegin = ()
PROP OnInputTouchEnd = ()
PROP OnInputTouchEnter = ()
PROP OnInputTouchLeave = ()
PROP OnActorHit = ()
PROP OnDestroyed = ()
PROP OnEndPlay = ()
PROP InstanceComponents = 
PROP BlueprintCreatedComponents = 
--- nav_api_census_OMNIWorld.txt ---
== UNavigationSystemV1 reflected functions (build/lock) ==
FUNC IsNavigationBeingBuiltOrLocked
== NavSystem instance (nav words) ==
PROP MainNavData = /Script/NavigationSystem.RecastNavMesh'/Game/Maps/OMNIWorld.OMNIWorld:PersistentLevel.RecastNavMesh-Default'
PROP AbstractNavData = /Script/NavigationSystem.AbstractNavData'/Game/Maps/OMNIWorld.OMNIWorld:PersistentLevel.AbstractNavData-Default'
PROP bAutoCreateNavigationData = True
PROP bSpawnNavDataInNavBoundsLevel = False
PROP bAllowClientSideNavigation = True
PROP bShouldDiscardSubLevelNavData = True
PROP bSupportRebuilding = True
PROP bDirtyNavDataPackageOnNavigationGenerationFinished = False
PROP bWaitForAsyncLoadingBeforeBuildingNavigationAutomatically = True
PROP bInitialBuildingLocked = False
PROP bSkipAgentHeightCheckWhenPickingNavData = False
PROP bGenerateNavigationOnlyAroundNavigationInvokers = False
PROP GatheringNavModifiersWarningLimitTime = -1.000000
PROP BuildBounds = (Min=(X=0.000000,Y=0.000000,Z=0.000000),Max=(X=0.000000,Y=0.000000,Z=0.000000),IsValid=False)
PROP NavDataSet = ("/Script/NavigationSystem.RecastNavMesh'/Game/Maps/OMNIWorld.OMNIWorld:PersistentLevel.RecastNavMesh-Default'")
PROP NavDataRegistrationQueue = 
PROP OnNavDataRegisteredEvent = ()
PROP OnNavigationGenerationFinishedDelegate = ()

```
