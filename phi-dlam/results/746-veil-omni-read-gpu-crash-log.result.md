# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-30 22:09:07 UTC

## STEP 1
```
=== WHOLE JOB 746 - READ GPU CRASH LOG (Ground: Tyree clicked the game and his screen showed an Error dialog, GPU Crashed or D3D Device Removed, check log for GPU state information, GPU mini dump written to D VEIL-OMNI Saved Logs D3D12.0.2026.10.30-16.06.32.nv-gpudmp. This job reads only: that dump file presence and size, the newest VEIL log tail 100 lines searched for GPU, D3D, Crash, Fatal, the Logs folder list for 2026-10-30 files, VEIL exe processes. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ===
DUMP746 PRESENT False
LOG746 FILE VEIL_2.log SIZE 97854 WRITE 10/30/2026 16:09:07
LOG746 FILE AutoSDKInfo.json SIZE 12551 WRITE 10/30/2026 16:09:05
LOG746 FILE AutoSDKInfo.txt SIZE 4134 WRITE 10/30/2026 16:09:05
LOG746 FILE VEIL_SEAT745_cmd_err.log SIZE 0 WRITE 10/30/2026 16:09:04
LOG746 FILE VEIL_SEAT745_cmd_out.log SIZE 0 WRITE 10/30/2026 16:09:04
LOG746 FILE VEIL_2-backup-2026.10.30-22.08.56.log SIZE 493891 WRITE 10/30/2026 16:08:56
LOG746 FILE cef3.log SIZE 2427 WRITE 10/30/2026 16:08:55
LOG746 FILE AutoSDKInfo-backup-2026.10.30-22.07.44.json SIZE 12551 WRITE 10/30/2026 16:07:44
LOG746 FILE AutoSDKInfo-backup-2026.10.30-22.07.44.txt SIZE 4134 WRITE 10/30/2026 16:07:44
LOG746 FILE VEIL_2-backup-2026.10.30-22.06.53.log SIZE 372291 WRITE 10/30/2026 16:06:53
LOG746 FILE cef3-backup-2026.10.30-22.05.20.log SIZE 441 WRITE 10/30/2026 16:05:20
LOG746 FILE AutoSDKInfo-backup-2026.10.30-22.05.13.txt SIZE 4134 WRITE 10/30/2026 16:05:13
LOG746 FILE AutoSDKInfo-backup-2026.10.30-22.05.13.json SIZE 12551 WRITE 10/30/2026 16:05:13
LOG746 FILE VEIL_2-backup-2026.10.30-21.51.02.log SIZE 309120 WRITE 10/30/2026 15:51:02
LOG746 FILE VEIL_SEAT743_cmd_out.log SIZE 39012 WRITE 10/30/2026 15:51:01
VEIL746 LOG PRESENT True
VEIL746 TERM GPU LINES 18
VEIL746 LINE LogModuleManager: InternalLoadLibrary: 'GPUTextureTransfer' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Media/MediaIOFramework/Binaries/Win64/UnrealEditor-GPUTextureTransfer.dll')
VEIL746 LINE LogModuleManager: InternalLoadLibrary: 'GPUReshape' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/GPUReshape/Binaries/Win64/UnrealEditor-GPUReshape.dll')
VEIL746 LINE LogWindows: Failed to load 'WinPixGpuCapturer.dll' (GetLastError=126)
VEIL746 LINE LogWindows: File 'WinPixGpuCapturer.dll' does not exist
VEIL746 LINE LogModuleManager: InternalLoadLibrary: 'ExrReaderGpu' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Media/ImgMedia/Binaries/Win64/UnrealEditor-ExrReaderGpu.dll')
VEIL746 LINE LogInit: OS: Windows 11 (26H2) [10.0.26300.9818] (), CPU: 12th Gen Intel(R) Core(TM) i5-12400F, GPU: NVIDIA GeForce RTX 3050
VEIL746 LINE [2026.10.30-21.11.41:167][  0]LogConfig: Set CVar [[r.GPUCrashDebugging:0]]
VEIL746 LINE [2026.10.30-21.11.41:168][  0]LogConfig: Set CVar [[r.Streaming.AmortizeCPUToGPUCopy:0]]
VEIL746 LINE [2026.10.30-21.11.41:666][  0]LogCsvProfiler: Display: Metadata set : gpu=""
VEIL746 LINE [2026.10.30-21.11.41:667][  0]LogCsvProfiler: Display: Metadata set : gpudriver=""
VEIL746 LINE [2026.10.30-21.11.47:506][  0]LogNNERuntimeORT:   D3D12:     n/a (checked in CanCreateModelGPU)
VEIL746 LINE [2026.10.30-21.11.47:506][  0]LogNNERuntimeORT:   GPU: n/a (checked in CanCreateModelGPU)
VEIL746 LINE [2026.10.30-21.11.48:737][  0]LogModuleManager: InternalLoadLibrary: 'DumpGPUServices' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/DumpGPUServices/Binaries/Win64/UnrealEditor-DumpGPUServices.dll')
VEIL746 LINE [2026.10.30-21.11.49:531][  0]LogGameFeatures: Loading 325 BuiltIn GameFeaturePlugins. Not Amortized. [AudioInsights, AudioInsightsRuntime, AudioModulationInsights, BaseMaterial, Bridge, ChaosCloth, ChaosClothAssetDataflowNodes, ChaosClothAssetEditorCore, ChaosClothAsset, ChaosInsights, ChaosOutfitAsset, ChaosVD, Chooser, CmdLinkServer, DerivedDataBuildController, Dataflow, EnhancedInput, IoStoreInsights, MassInsights, MeshPainting, Mutable, PCG, RenderGraphInsights, RenderTraceInsights, TextureGraph, UbaController, TraceUtilities, WorldMetrics, XGEController, OodleNetwork, DatasmithContent, GLTFExporter, VariantManager, VariantManagerContent, Cascade, Niagara, NiagaraInsights, NiagaraPreviewContent, NiagaraSimCaching, InterchangeAssets, InterchangeEditor, MetaHuman, Interchange, MetaHumanCharacter, EOSShared, MetaHumanCoreTech, MetaHumanSDK, OnlineServices, OnlineBase, OnlineSubsystem, OnlineSubsystemNull, AssetManagerEditor, OnlineSubsystemUtils, AssetReferenceRestrictions, BlueprintMaterialTextureNodes, BlueprintHeaderView, ChangelistReview, ColorGrading, ConsoleVariables, CryptoKeys, DataValidation, EditorDebugTools, CurveEditorTools, EditorScriptingUtilities, EngineAssetDefinitions, FacialAnimation, GameplayTagsEditor, GeometryMode, ImageWidgets, MaterialAnalyzer, MacGraphicsSwitching, MaterialAssetWizard, MobileLauncherProfileWizard, ModelingToolsEditorMode, MeshLODToolset, PluginBrowser, ProxyLODPlugin, SequencerAnimTools, StylusInput, SpeedTreeImporter, UMGWidgetPreview, UVEditor, WorldPartitionHLODUtilities, TcpMessaging, UdpMessaging, AutomatedPerfTestTools, AlembicImporter, Nwiro, ActorSequence, LevelSequenceEditor, SequencerScripting, SequenceValidator, TemplateSequence, LauncherChunkInstaller, ActorLayerUtilities, AndroidMoviePlayer, AndroidFileServer, AndroidPermission, AndroidDeviceProfileSelector, AppleImageUtils, AppleMoviePlayer, ArchVisCharacter, AssetTags, AudioCapture, AudioSynesthesia, CableComponent, AudioWidgets, ChunkDownloader, ComputeFramework, CustomMeshComponent, DataRegistry, ExampleDeviceProfileSelector, GameFeatures, GameplayAbilities, GeometryCache, GeometryScripting, GeometryProcessing, GoogleCloudMessaging, GooglePAD, HDRIBackdrop, HairStrands, InputDebugging, LinuxDeviceProfileSelector, IOSDeviceProfileSelector, LocationServicesBPLibrary, MeshModelingToolset, Metasound, ModelViewViewModel, MobilePatchingUtils, ModularGameplay, MsQuic, PropertyAccessEditor, PropertyBindingUtils, ProceduralMeshComponent, ResonanceAudio, RigVM, SignificanceManager, ScriptableToolsFramework, SkeletalMerging, SoundFields, StateTree, Synthesis, WaveTable, WebBrowserWidget, WebMMoviePlayer, WindowsDeviceProfileSelector, WorldConditions, WindowsMoviePlayer, XRBase, NNERuntimeORT, NNEDenoiser, InterchangeTests, Paper2D, AISupport, EnvironmentQueryEditor, ACLPlugin, AnimatorKit, AnimationModifierLibrary, AnimationData, AnimationWarping, BlendSpaceMotionAnalysis, ControlRig, BlendStack, ControlRigModules, ControlRigSpline, DNACalib, DeformerGraph, EaseCurveTool, GameplayInsights, IKRig, LiveLink, LiveLinkDevice, LiveLinkHub, PhysicsControl, PoseSearch, PerformanceCaptureCore, MotionWarping, RigLogic, SkeletalMeshModelingTools, TweeningUtils, EngineCameras, CompositeCore, CameraShakePreviewer, GameplayCameras, OpenColorIO, AnimationSharing, CodeLiteSourceCodeAccess, CLionSourceCodeAccess, GitSourceControl, DumpGPUServices, GPUReshape, KDevelopSourceCodeAccess, N10XSourceCodeAccess, NamingTokens, NullSourceCodeAccess, PixWinPlugin, PerforceSourceControl, PluginUtils, ProjectLauncher, PlasticSourceControl, RenderDocPlugin, PropertyAccessNode, RiderSourceCodeAccess, SubversionSourceControl, UObjectPlugin, VisualStudioCodeSourceCodeAccess, VisualStudioSourceCodeAccess, XCodeSourceCodeAccess, AdvancedRenamer, AutomationUtils, BackChannel, ChaosCaching, Buoyancy, ChaosEditor, ChaosNiagara, ChaosSolverPlugin, ChaosUserDataPT, CharacterAI, ControlFlows, CommonConversation, ControlRigPhysics, EditorDataStorage, EditorPerformance, EditorDataStorageFeatures, EditorTelemetry, EditorTRSGizmo, Fracture, FullBodyIK, GeometryDataflow, GeometryCollectionPlugin, GeometryFlow, GizmoFramework, GlobalConfigurationData, HttpInsights, Landmass, LiveLinkControlRig, LevelSequenceNavigatorBridge, LowLevelNetTrace, MeshModelingToolsetExp, LocalizableMessage, MeshResizing, MessageBusTester, ModelContextProtocol, MutableAssetUserData, NFORDenoise, NNERuntimeBasicCpu, PlatformCrypto, PlanarCut, PythonScriptPlugin, RuntimeTelemetry, SemanticSearch, SequenceNavigator, SkeletalReduction, ToolPresets, ToolsetRegistry, Water, AndroidMedia, AvfMedia, ElectraCDM, D3D12VideoDecodersElectra, ElectraPlayer, ElectraCodecs, ElectraUtil, ImgMedia, ElectraSubtitles, MediaCompositing, MediaPlate, MediaIOFramework, MediaPlayerEditor, MediaProfile, MP4Utilities, OpusDecoderElectra, TmvMedia, WmfMedia, WebMMedia, CameraCalibrationCore, CaptureData, LensComponent, Takes, BaseCharacterFXEditor, OnlineSubsystemGooglePlay, FileSandbox, CaptureManagerCore, CaptureManagerEditor, ConcertMain, OnlineSubsystemIOS, ContentBrowserAssetDataSource, ContentBrowserFileDataSource, ContentBrowserClassDataSource, AllToolsets, AIModuleToolset, ConfigSettingsToolset, AnimationAssistantToolset, AutomationTestToolset, ConversationToolset, DataflowAgent, DataRegistryToolset, GameFeaturesToolset, GameplayTagsToolset, EditorToolset, GASToolsets, MCPClientToolset, NiagaraToolsets, PCGToolset, PhysicsToolsets, PluginToolset, SemanticSearchToolset, StateTreeToolset, SlateInspectorToolset, WorldConditionsToolset, UMGToolSet, Scribble, InterchangeAxfAssets, XInputDevice, StreamingADA, SQLiteCore, PortableObjectFileDataSource, ARUtilities, LightMixer, ObjectMixer, ConcertSyncClient, ConcertSyncCore, AppleARKitFaceSupport, ConcertSharedSlate, AppleARKit].
VEIL746 LINE [2026.10.30-21.11.49:538][  0]LogNiagara: UAV Float16 is not supported, compressed GPU emitters will be disabled.
VEIL746 TERM D3D LINES 17
VEIL746 LINE LogConfig: CVar [[D3D12.Bindless.ResourceDescriptorHeapSize:32768]] deferred - dummy variable created
VEIL746 LINE [2026.10.30-21.11.41:167][  0]LogConfig: CVar [[D3D12.Bindless.SamplerDescriptorHeapSize:2048]] deferred - dummy variable created
VEIL746 LINE [2026.10.30-21.11.41:167][  0]LogConfig: CVar [[D3D12.Bindless.ResourceDescriptorHeapSize:32768]] deferred - dummy variable created
VEIL746 LINE [2026.10.30-21.11.41:167][  0]LogConfig: CVar [[D3D12.Bindless.SamplerDescriptorHeapSize:2048]] deferred - dummy variable created
VEIL746 LINE [2026.10.30-21.11.41:666][  0]LogCsvProfiler: Display: Metadata set : shaderplatform="PCD3D_SM6"
VEIL746 LINE [2026.10.30-21.11.41:829][  0]LogModuleManager: InternalLoadLibrary: 'ShaderFormatD3D' ('C:/Program Files/Epic Games/UE_5.8/Engine/Binaries/Win64/UnrealEditor-ShaderFormatD3D.dll')
VEIL746 LINE [2026.10.30-21.11.45:097][  0]LogShaderCompilers: Display: Compiling shader autogen file: D:/VEIL-OMNI/Intermediate/ShaderAutogen/PCD3D_SM6/AutogenShaderHeaders.ush
VEIL746 LINE [2026.10.30-21.11.46:241][  0]LogShaderCompilers: Display: Compiling shader autogen file: D:/VEIL-OMNI/Intermediate/ShaderAutogen/PCD3D_SM5/AutogenShaderHeaders.ush
VEIL746 LINE [2026.10.30-21.11.47:506][  0]LogNNERuntimeORT:   RHI D3D12: no
VEIL746 LINE [2026.10.30-21.11.47:506][  0]LogNNERuntimeORT:   D3D12:     n/a (checked in CanCreateModelGPU)
VEIL746 LINE [2026.10.30-21.11.49:479][  0]LogAssetRegistry: Warning: Invalid duplicate copies of ExternalActor /Game/ThirdPerson/Maps/ThirdPersonMap.ThirdPersonMap:PersistentLevel.ActorFolder_UID_7B7009C3-45D3D6DD-94D3429E-1D79C034. Resolve by deleting the package that is invalid. Chosing alphabetically for this process.
VEIL746 LINE [2026.10.30-21.11.49:531][  0]LogGameFeatures: Loading 325 BuiltIn GameFeaturePlugins. Not Amortized. [AudioInsights, AudioInsightsRuntime, AudioModulationInsights, BaseMaterial, Bridge, ChaosCloth, ChaosClothAssetDataflowNodes, ChaosClothAssetEditorCore, ChaosClothAsset, ChaosInsights, ChaosOutfitAsset, ChaosVD, Chooser, CmdLinkServer, DerivedDataBuildController, Dataflow, EnhancedInput, IoStoreInsights, MassInsights, MeshPainting, Mutable, PCG, RenderGraphInsights, RenderTraceInsights, TextureGraph, UbaController, TraceUtilities, WorldMetrics, XGEController, OodleNetwork, DatasmithContent, GLTFExporter, VariantManager, VariantManagerContent, Cascade, Niagara, NiagaraInsights, NiagaraPreviewContent, NiagaraSimCaching, InterchangeAssets, InterchangeEditor, MetaHuman, Interchange, MetaHumanCharacter, EOSShared, MetaHumanCoreTech, MetaHumanSDK, OnlineServices, OnlineBase, OnlineSubsystem, OnlineSubsystemNull, AssetManagerEditor, OnlineSubsystemUtils, AssetReferenceRestrictions, BlueprintMaterialTextureNodes, BlueprintHeaderView, ChangelistReview, ColorGrading, ConsoleVariables, CryptoKeys, DataValidation, EditorDebugTools, CurveEditorTools, EditorScriptingUtilities, EngineAssetDefinitions, FacialAnimation, GameplayTagsEditor, GeometryMode, ImageWidgets, MaterialAnalyzer, MacGraphicsSwitching, MaterialAssetWizard, MobileLauncherProfileWizard, ModelingToolsEditorMode, MeshLODToolset, PluginBrowser, ProxyLODPlugin, SequencerAnimTools, StylusInput, SpeedTreeImporter, UMGWidgetPreview, UVEditor, WorldPartitionHLODUtilities, TcpMessaging, UdpMessaging, AutomatedPerfTestTools, AlembicImporter, Nwiro, ActorSequence, LevelSequenceEditor, SequencerScripting, SequenceValidator, TemplateSequence, LauncherChunkInstaller, ActorLayerUtilities, AndroidMoviePlayer, AndroidFileServer, AndroidPermission, AndroidDeviceProfileSelector, AppleImageUtils, AppleMoviePlayer, ArchVisCharacter, AssetTags, AudioCapture, AudioSynesthesia, CableComponent, AudioWidgets, ChunkDownloader, ComputeFramework, CustomMeshComponent, DataRegistry, ExampleDeviceProfileSelector, GameFeatures, GameplayAbilities, GeometryCache, GeometryScripting, GeometryProcessing, GoogleCloudMessaging, GooglePAD, HDRIBackdrop, HairStrands, InputDebugging, LinuxDeviceProfileSelector, IOSDeviceProfileSelector, LocationServicesBPLibrary, MeshModelingToolset, Metasound, ModelViewViewModel, MobilePatchingUtils, ModularGameplay, MsQuic, PropertyAccessEditor, PropertyBindingUtils, ProceduralMeshComponent, ResonanceAudio, RigVM, SignificanceManager, ScriptableToolsFramework, SkeletalMerging, SoundFields, StateTree, Synthesis, WaveTable, WebBrowserWidget, WebMMoviePlayer, WindowsDeviceProfileSelector, WorldConditions, WindowsMoviePlayer, XRBase, NNERuntimeORT, NNEDenoiser, InterchangeTests, Paper2D, AISupport, EnvironmentQueryEditor, ACLPlugin, AnimatorKit, AnimationModifierLibrary, AnimationData, AnimationWarping, BlendSpaceMotionAnalysis, ControlRig, BlendStack, ControlRigModules, ControlRigSpline, DNACalib, DeformerGraph, EaseCurveTool, GameplayInsights, IKRig, LiveLink, LiveLinkDevice, LiveLinkHub, PhysicsControl, PoseSearch, PerformanceCaptureCore, MotionWarping, RigLogic, SkeletalMeshModelingTools, TweeningUtils, EngineCameras, CompositeCore, CameraShakePreviewer, GameplayCameras, OpenColorIO, AnimationSharing, CodeLiteSourceCodeAccess, CLionSourceCodeAccess, GitSourceControl, DumpGPUServices, GPUReshape, KDevelopSourceCodeAccess, N10XSourceCodeAccess, NamingTokens, NullSourceCodeAccess, PixWinPlugin, PerforceSourceControl, PluginUtils, ProjectLauncher, PlasticSourceControl, RenderDocPlugin, PropertyAccessNode, RiderSourceCodeAccess, SubversionSourceControl, UObjectPlugin, VisualStudioCodeSourceCodeAccess, VisualStudioSourceCodeAccess, XCodeSourceCodeAccess, AdvancedRenamer, AutomationUtils, BackChannel, ChaosCaching, Buoyancy, ChaosEditor, ChaosNiagara, ChaosSolverPlugin, ChaosUserDataPT, CharacterAI, ControlFlows, CommonConversation, ControlRigPhysics, EditorDataStorage, EditorPerformance, EditorDataStorageFeatures, EditorTelemetry, EditorTRSGizmo, Fracture, FullBodyIK, GeometryDataflow, GeometryCollectionPlugin, GeometryFlow, GizmoFramework, GlobalConfigurationData, HttpInsights, Landmass, LiveLinkControlRig, LevelSequenceNavigatorBridge, LowLevelNetTrace, MeshModelingToolsetExp, LocalizableMessage, MeshResizing, MessageBusTester, ModelContextProtocol, MutableAssetUserData, NFORDenoise, NNERuntimeBasicCpu, PlatformCrypto, PlanarCut, PythonScriptPlugin, RuntimeTelemetry, SemanticSearch, SequenceNavigator, SkeletalReduction, ToolPresets, ToolsetRegistry, Water, AndroidMedia, AvfMedia, ElectraCDM, D3D12VideoDecodersElectra, ElectraPlayer, ElectraCodecs, ElectraUtil, ImgMedia, ElectraSubtitles, MediaCompositing, MediaPlate, MediaIOFramework, MediaPlayerEditor, MediaProfile, MP4Utilities, OpusDecoderElectra, TmvMedia, WmfMedia, WebMMedia, CameraCalibrationCore, CaptureData, LensComponent, Takes, BaseCharacterFXEditor, OnlineSubsystemGooglePlay, FileSandbox, CaptureManagerCore, CaptureManagerEditor, ConcertMain, OnlineSubsystemIOS, ContentBrowserAssetDataSource, ContentBrowserFileDataSource, ContentBrowserClassDataSource, AllToolsets, AIModuleToolset, ConfigSettingsToolset, AnimationAssistantToolset, AutomationTestToolset, ConversationToolset, DataflowAgent, DataRegistryToolset, GameFeaturesToolset, GameplayTagsToolset, EditorToolset, GASToolsets, MCPClientToolset, NiagaraToolsets, PCGToolset, PhysicsToolsets, PluginToolset, SemanticSearchToolset, StateTreeToolset, SlateInspectorToolset, WorldConditionsToolset, UMGToolSet, Scribble, InterchangeAxfAssets, XInputDevice, StreamingADA, SQLiteCore, PortableObjectFileDataSource, ARUtilities, LightMixer, ObjectMixer, ConcertSyncClient, ConcertSyncCore, AppleARKitFaceSupport, ConcertSharedSlate, AppleARKit].
VEIL746 LINE [2026.10.30-21.11.50:100][  0]LogModuleManager: InternalLoadLibrary: 'D3D12VideoDecodersElectra' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Media/D3D12VideoDecodersElectra/Binaries/Win64/UnrealEditor-D3D12VideoDecodersElectra.dll')
VEIL746 LINE [2026.10.30-21.11.50:106][  0]LogD3D12VideoDecodersElectra: D3D12 video decoding will not be used since no supported format was found.
VEIL746 LINE [2026.10.30-21.11.50:473][  0]LogInit: Display: LogAssetRegistry: Warning: Invalid duplicate copies of ExternalActor /Game/ThirdPerson/Maps/ThirdPersonMap.ThirdPersonMap:PersistentLevel.ActorFolder_UID_7B7009C3-45D3D6DD-94D3429E-1D79C034. Resolve by deleting the package that is invalid. Chosing alphabetically for this process.
VEIL746 TERM Crash LINES 7
VEIL746 LINE LogWindows: Started CrashReportClient (pid=78568)
VEIL746 LINE LogWindows: Custom abort handler registered for crash reporting.
VEIL746 LINE LogInit: Session CrashGUID >====================================================
VEIL746 LINE          Session CrashGUID >   UECC-Windows-7CFFF0BA4801744666D88C9A0A9FBA6C
VEIL746 LINE          Session CrashGUID >====================================================
VEIL746 LINE LogModuleManager: InternalLoadLibrary: 'CrashDiagnostics' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/EditorPerformance/Binaries/Win64/UnrealEditor-CrashDiagnostics.dll')
VEIL746 LINE [2026.10.30-21.11.41:167][  0]LogConfig: Set CVar [[r.GPUCrashDebugging:0]]
VEIL746 TERM Fatal LINES 0
VEIL746 LOG TAIL 100
[2026.10.30-21.11.50:370][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/ConversationToolset/Content/Python/init_unreal.py... took 5.711 ms (total: 134.372 ms)
[2026.10.30-21.11.50:370][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AnimationAssistantToolset/Content/Python/init_unreal.py... started...
[2026.10.30-21.11.50:401][  0]LogModelContextProtocol: Tool search enabled: registered 3 meta-tools (44 toolsets discoverable via list_toolsets)
[2026.10.30-21.11.50:401][  0]LogToolsetRegistry: Display: Registering Toolset animation_toolset.toolsets.controlrig.ControlRigTools
[2026.10.30-21.11.50:408][  0]LogModelContextProtocol: Tool search enabled: registered 3 meta-tools (45 toolsets discoverable via list_toolsets)
[2026.10.30-21.11.50:408][  0]LogToolsetRegistry: Display: Registering Toolset animation_toolset.toolsets.sequencer.SequencerTools
[2026.10.30-21.11.50:409][  0]LogModelContextProtocol: Tool search enabled: registered 3 meta-tools (46 toolsets discoverable via list_toolsets)
[2026.10.30-21.11.50:409][  0]LogToolsetRegistry: Display: Registering Toolset animation_toolset.toolsets.keyframing.SequencerKeyframingTools
[2026.10.30-21.11.50:413][  0]LogModelContextProtocol: Tool search enabled: registered 3 meta-tools (47 toolsets discoverable via list_toolsets)
[2026.10.30-21.11.50:413][  0]LogToolsetRegistry: Display: Registering Toolset animation_toolset.toolsets.controlrig_sequencer.SequencerControlRigTools
[2026.10.30-21.11.50:414][  0]LogModelContextProtocol: Tool search enabled: registered 3 meta-tools (48 toolsets discoverable via list_toolsets)
[2026.10.30-21.11.50:414][  0]LogToolsetRegistry: Display: Registering Toolset animation_toolset.toolsets.outliner.SequencerOutlinerTools
[2026.10.30-21.11.50:415][  0]LogModelContextProtocol: Tool search enabled: registered 3 meta-tools (49 toolsets discoverable via list_toolsets)
[2026.10.30-21.11.50:415][  0]LogToolsetRegistry: Display: Registering Toolset animation_toolset.toolsets.conditions.SequencerConditionTools
[2026.10.30-21.11.50:415][  0]LogModelContextProtocol: Tool search enabled: registered 3 meta-tools (50 toolsets discoverable via list_toolsets)
[2026.10.30-21.11.50:415][  0]LogToolsetRegistry: Display: Registering Toolset animation_toolset.toolsets.custom_bindings.SequencerCustomBindingTools
[2026.10.30-21.11.50:416][  0]LogModelContextProtocol: Tool search enabled: registered 3 meta-tools (51 toolsets discoverable via list_toolsets)
[2026.10.30-21.11.50:416][  0]LogToolsetRegistry: Display: Registering Toolset animation_toolset.toolsets.import_export.SequencerImportExportTools
[2026.10.30-21.11.50:436][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AnimationAssistantToolset/Content/Python/init_unreal.py... took 65.707 ms (total: 200.079 ms)
[2026.10.30-21.11.50:436][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AIModuleToolset/Content/Python/init_unreal.py... started...
[2026.10.30-21.11.50:439][  0]LogModelContextProtocol: Tool search enabled: registered 3 meta-tools (52 toolsets discoverable via list_toolsets)
[2026.10.30-21.11.50:439][  0]LogToolsetRegistry: Display: Registering Toolset aimodule_toolset.toolsets.behavior_tree.BehaviorTreeTools
[2026.10.30-21.11.50:440][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AIModuleToolset/Content/Python/init_unreal.py... took 3.920 ms (total: 204.000 ms)
[2026.10.30-21.11.50:440][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... started...
[2026.10.30-21.11.50:441][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... took 734 us (total: 204.734 ms)
[2026.10.30-21.11.50:441][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... started...
[2026.10.30-21.11.50:444][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... took 3.194 ms (total: 207.929 ms)
[2026.10.30-21.11.50:444][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... started...
[2026.10.30-21.11.50:456][  0]LogPython: registering <class 'ControlRigWorkflows.workflow_deformation_rig_preset.provider'>

[2026.10.30-21.11.50:467][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... took 22.431 ms (total: 230.361 ms)
[2026.10.30-21.11.50:467][  0]LogPython: Python enabled via IPythonScriptPlugin::ForceEnablePythonAtRuntime: D:\build\++UE5\Sync\Engine\Plugins\Experimental\PythonScriptPlugin\Source\PythonScriptPlugin\Private\PythonScriptCommandlet.cpp(43:30) int __cdecl UPythonScriptCommandlet::Main(const class FString &)
[2026.10.30-21.11.50:467][  0]SourceControl: Revision control is disabled
[2026.10.30-21.11.50:467][  0]LogPythonScriptCommandlet: Display: Running Python script: D:\VEIL-OMNI\Saved\seat719.py
[2026.10.30-21.11.50:468][  0]LogPython: SEAT719 START
[2026.10.30-21.11.50:469][  0]LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:70: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
  world = unreal.EditorLevelLibrary.get_editor_world()

[2026.10.30-21.11.50:469][  0]LogPython: SEAT719 WORLD: /Temp/Untitled_0.Untitled
[2026.10.30-21.11.50:469][  0]LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:74: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
  before = unreal.EditorLevelLibrary.get_all_level_actors()

[2026.10.30-21.11.50:470][  0]LogPython: SEAT719 ACTORS BEFORE: 0
[2026.10.30-21.11.50:470][  0]LogPython: SEAT719 MAP NOT LOADED, STOP
[2026.10.30-21.11.50:470][  0]LogPythonScriptCommandlet: Display: Python script executed successfully
[2026.10.30-21.11.50:470][  0]LogCore: Engine exit requested (reason: Commandlet PythonScriptCommandlet_0 finished execution (result 0))
[2026.10.30-21.11.50:470][  0]LogInit: Display: 
[2026.10.30-21.11.50:470][  0]LogInit: Display: Warning/Error Summary (Unique only)
[2026.10.30-21.11.50:471][  0]LogInit: Display: -----------------------------------
[2026.10.30-21.11.50:471][  0]LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.TSR.History.ScreenPercentage' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '66.6667'
[2026.10.30-21.11.50:471][  0]LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.Shadow.Virtual.MaxPhysicalPages' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '2048'
[2026.10.30-21.11.50:472][  0]LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.Lumen.Reflections.Allow' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '1'
[2026.10.30-21.11.50:472][  0]LogInit: Display: LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
[2026.10.30-21.11.50:472][  0]LogInit: Display: LogMetaHumanCharacterEditor: Warning: MetaHuman Optional Content folder not found. MetaHuman Creator plugin initialized with limited features.
[2026.10.30-21.11.50:473][  0]LogInit: Display: LogAssetRegistry: Warning: Invalid duplicate copies of ExternalActor /Game/ThirdPerson/Maps/ThirdPersonMap.ThirdPersonMap:PersistentLevel.ActorFolder_UID_7B7009C3-45D3D6DD-94D3429E-1D79C034. Resolve by deleting the package that is invalid. Chosing alphabetically for this process.
	Discarding: /Game/ModularS30eeb54ea3e4V1/data/Content/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/C/7N/FDH7Y28CQFXDK8P6MM1HXM
	Keeping:    /Game/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/C/7N/FDH7Y28CQFXDK8P6MM1HXM
[2026.10.30-21.11.50:473][  0]LogInit: Display: LogAssetRegistry: Warning: Invalid duplicate copies of ExternalActor /Game/ThirdPerson/Maps/ThirdPersonMap.ThirdPersonMap:PersistentLevel.ActorFolder_UID_963EC3EB-4002CCE9-759E2EBA-541A873A. Resolve by deleting the package that is invalid. Chosing alphabetically for this process.
	Discarding: /Game/ModularS30eeb54ea3e4V1/data/Content/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/4/VW/TY7TSUER9KKGHX2BMKSL0L
	Keeping:    /Game/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/4/VW/TY7TSUER9KKGHX2BMKSL0L
[2026.10.30-21.11.50:473][  0]LogInit: Display: LogAssetRegistry: Warning: Invalid duplicate copies of ExternalActor /Game/ThirdPerson/Maps/ThirdPersonMap.ThirdPersonMap:PersistentLevel.ActorFolder_UID_7D23E5AE-4C2A421F-86AF6986-D87E6D05. Resolve by deleting the package that is invalid. Chosing alphabetically for this process.
	Discarding: /Game/ModularS30eeb54ea3e4V1/data/Content/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/9/KN/KHZG97SS6AL73U7AXDWH6J
	Keeping:    /Game/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/9/KN/KHZG97SS6AL73U7AXDWH6J
[2026.10.30-21.11.50:474][  0]LogInit: Display: LogAssetRegistry: Warning: Invalid duplicate copies of ExternalActor /Game/ThirdPerson/Maps/ThirdPersonMap.ThirdPersonMap:PersistentLevel.ActorFolder_UID_EBA23F82-48252949-750E4391-1A3A1CDD. Resolve by deleting the package that is invalid. Chosing alphabetically for this process.
	Discarding: /Game/ModularS30eeb54ea3e4V1/data/Content/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/6/D8/3MZ6M1DB94VN44C87D65WR
	Keeping:    /Game/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/6/D8/3MZ6M1DB94VN44C87D65WR
[2026.10.30-21.11.50:474][  0]LogInit: Display: LogAssetRegistry: Warning: Invalid duplicate copies of ExternalActor /Game/ThirdPerson/Maps/ThirdPersonMap.ThirdPersonMap:PersistentLevel.ActorFolder_UID_C73F09FC-4215536B-1DCE2A9E-0A830C70. Resolve by deleting the package that is invalid. Chosing alphabetically for this process.
	Discarding: /Game/ModularS30eeb54ea3e4V1/data/Content/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/6/TK/PIQ0B2FNWR15P52TECP27A
	Keeping:    /Game/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/6/TK/PIQ0B2FNWR15P52TECP27A
[2026.10.30-21.11.50:475][  0]LogInit: Display: LogAssetRegistry: Warning: Invalid duplicate copies of ExternalActor /Game/ThirdPerson/Maps/ThirdPersonMap.ThirdPersonMap:PersistentLevel.ActorFolder_UID_D075E5BA-49330D3E-C2503D81-A7CF88D1. Resolve by deleting the package that is invalid. Chosing alphabetically for this process.
	Discarding: /Game/ModularS30eeb54ea3e4V1/data/Content/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/E/GP/22PD314FCWY4ZK61DE3XZC
	Keeping:    /Game/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/E/GP/22PD314FCWY4ZK61DE3XZC
[2026.10.30-21.11.50:475][  0]LogInit: Display: LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:70: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
  world = unreal.EditorLevelLibrary.get_editor_world()

[2026.10.30-21.11.50:476][  0]LogInit: Display: LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:74: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
  before = unreal.EditorLevelLibrary.get_all_level_actors()

[2026.10.30-21.11.50:476][  0]LogInit: Display: 
[2026.10.30-21.11.50:477][  0]LogInit: Display: Success - 0 error(s), 13 warning(s)
[2026.10.30-21.11.50:477][  0]LogInit: Display: 
Execution of commandlet took:  0.23 seconds, PeakPhysMemoryMB=2088 MB, PeakVirtMemoryMB=1881 MB
[2026.10.30-21.11.50:477][  0]LogCore: Engine exit requested (reason: EngineExit() was called; note: exit was already requested)
[2026.10.30-21.11.50:477][  0]LogStaticMesh: Abandoning remaining async distance field tasks for shutdown
[2026.10.30-21.11.50:477][  0]LogStaticMesh: Abandoning remaining async card representation tasks for shutdown
[2026.10.30-21.11.50:477][  0]MassEntity: New Page: MassEntity
[2026.10.30-21.11.50:477][  0]LogMovieScene: USequencerBakeSubsystem subsystem deinitialized.
[2026.10.30-21.11.50:477][  0]LogTedsSettings: UTedsSettingsEditorSubsystem::Deinitialize
[2026.10.30-21.11.50:477][  0]LogToolsetRegistry: Display: Unregistering Toolset ToolsetRegistry.AgentSkillToolset
[2026.10.30-21.11.50:478][  0]LogModelContextProtocol: Tool search enabled: registered 3 meta-tools (51 toolsets discoverable via list_toolsets)
[2026.10.30-21.11.50:478][  0]LogLevelSequenceEditor: LevelSequenceEditor subsystem deinitialized.
[2026.10.30-21.11.50:478][  0]LogToolsetRegistry: Display: Unregistering Toolset AutomationTestToolset.AutomationTestToolset
[2026.10.30-21.11.50:478][  0]LogModelContextProtocol: Tool search enabled: registered 3 meta-tools (50 toolsets discoverable via list_toolsets)
[2026.10.30-21.11.50:478][  0]LogToolsetRegistry: Display: Unregistering Toolset SlateInspectorToolset.SlateInspectorToolset
[2026.10.30-21.11.50:478][  0]LogModelContextProtocol: Tool search enabled: registered 3 meta-tools (49 toolsets discoverable via list_toolsets)
[2026.10.30-21.11.50:478][  0]LogRuntimeTelemetry: Recording EnginePreExit events
[2026.10.30-21.11.50:479][  0]LogGameFeatures: Shutting down game features subsystem
[2026.10.30-21.11.50:479][  0]LogExit: Preparing to exit.
[2026.10.30-21.11.50:602][  0]LogUObjectHash: Compacting FUObjectHashTables data took   1.69ms
[2026.10.30-21.15.01:321][  0]LogDerivedDataCache: C:/Users/Admin/AppData/Local/UnrealEngine/Common/DerivedDataCache: Maintenance finished in +00:01:16.235 and deleted 0 files with total size 0 MiB and 0 empty folders. Scanned 40365 files in 41338 folders with total size 4253 MiB.
UNREAL TELLS, NOT JOB START LINES.
WHOLE JOB DONE.

```
