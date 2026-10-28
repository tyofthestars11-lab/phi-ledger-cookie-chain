# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 22:05:43 UTC

## STEP 1
```
=== REVERSE READ 499 - THE INPUT CHAIN AND THE ANIMATION SEAT READ FROM THE SOURCE ITSELF (Ground: in the green build the character moves on keys and glides - the body travels while the walking animation never plays - and the controller answers nothing in gameplay. Epic portal Module 2 of Your First Hour teaches Enhanced Input as the seated road, so this job reverse reads the actual source on the PC: the whole input binding function, the whole fallback context builder, the tick proof region, every line that seats the mesh animation class, and the header input members, each printed with its line number, plus the newest game log lines at the animation and input addresses. Read only - nothing written, nothing patched. The fix seats from these prints in the same motion. Every variable carries the pr499 prefix.) ===
CPP lines=691
SPAN SetupPlayerInputComponent starts line 279
SRC 279: void AVEILCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
SRC 280: {
SRC 281: Super::SetupPlayerInputComponent(PlayerInputComponent);
SRC 282: 
SRC 283: // PHI 442: possession runs before BeginPlay, so the binds below read
SRC 284: // actions that stand unbuilt at this hour and their null guards skip
SRC 285: // every bind. Build the standing fallback here, at the bind itself.
SRC 286: if (!MoveAction || !DefaultMappingContext)
SRC 287: {
SRC 288: BuildFallbackInput();
SRC 289: }
SRC 290: 
SRC 291: // 1st/3rd person toggle: V on keyboard, right-stick click (R3) on the pad.
SRC 292: PlayerInputComponent->BindKey(EKeys::V, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
SRC 293: PlayerInputComponent->BindKey(EKeys::Gamepad_RightThumbstick, IE_Pressed, this, &AVEILCharacter::ToggleCameraMode);
SRC 294: 
SRC 295: if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
SRC 296: {
SRC 297: if (MoveAction)   EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Move);
SRC 298: if (LookAction)   EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AVEILCharacter::Look);
SRC 299: if (JumpAction)
SRC 300: {
SRC 301: EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
SRC 302: EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
SRC 303: }
SRC 304: if (SprintAction)
SRC 305: {
SRC 306: EIC->BindAction(SprintAction, ETriggerEvent::Started, this, &AVEILCharacter::StartSprint);
SRC 307: EIC->BindAction(SprintAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopSprint);
SRC 308: }
SRC 309: if (DodgeAction)  EIC->BindAction(DodgeAction, ETriggerEvent::Started, this, &AVEILCharacter::DoDodge);
SRC 310: if (AimAction)
SRC 311: {
SRC 312: EIC->BindAction(AimAction, ETriggerEvent::Started, this, &AVEILCharacter::StartAim);
SRC 313: EIC->BindAction(AimAction, ETriggerEvent::Completed, this, &AVEILCharacter::StopAim);
SRC 314: }
SRC 315: if (FireAction)   EIC->BindAction(FireAction, ETriggerEvent::Started, this, &AVEILCharacter::Fire);
SRC 316: if (InteractAction) EIC->BindAction(InteractAction, ETriggerEvent::Started, this, &AVEILCharacter::Interact);
SRC 317: }
SRC 318: }
SRC 319: 
SRC 320: void AVEILCharacter::Tick(float DeltaSeconds)
SRC 321: {
SRC 322: {
SRC 323: static float PadProofAcc = 0.f;
SPAN BuildFallbackInput starts line 169
SRC 169: BuildFallbackInput();
SRC 170: }
SRC 171: 
SRC 172: if (APlayerController* PC = Cast<APlayerController>(Controller))
SRC 173: {
SRC 174: if (UEnhancedInputLocalPlayerSubsystem* Sub =
SRC 175: ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
SRC 176: {
SRC 177: if (DefaultMappingContext)
SRC 178: {
SRC 179: Sub->AddMappingContext(DefaultMappingContext, 0);
SRC 180: }
SRC 181: }
SRC 182: }
SRC 183: // PHI 480: the built context is seated at BeginPlay as the second road.
SRC 184: if (APlayerController* Phi480PC = Cast<APlayerController>(GetController()))
SRC 185: {
SRC 186: if (ULocalPlayer* Phi480LP = Phi480PC->GetLocalPlayer())
SRC 187: {
SRC 188: if (UEnhancedInputLocalPlayerSubsystem* Phi480Sub = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Phi480LP))
SRC 189: {
SRC 190: if (BuiltMappingContext && !Phi480Sub->HasMappingContext(BuiltMappingContext)) { Phi480Sub->AddMappingContext(BuiltMappingContext, 0); }
SRC 191: UE_LOG(LogTemp, Display, TEXT("PHI INPUT SEAT: beginplay"));
SRC 192: }
SRC 193: }
SRC 194: }
SRC 195: }
SRC 196: 
SRC 197: void AVEILCharacter::BuildFallbackInput()
SRC 198: {
SRC 199: // Build the full control scheme in code - keyboard/mouse AND Xbox pad.
SRC 200: // Used only when no editor-made Input assets are assigned.
SRC 201: auto MakeAction = [this](const FName Name, EInputActionValueType Type) -> UInputAction*
SRC 202: {
SRC 203: UInputAction* Action = NewObject<UInputAction>(this, Name, RF_Transient);
SRC 204: Action->ValueType = Type;
SRC 205: BuiltActions.Add(Action);
SRC 206: return Action;
SRC 207: };
SRC 208: 
SRC 209: MoveAction = MakeAction(TEXT("IA_Move"), EInputActionValueType::Axis2D);
SRC 210: LookAction = MakeAction(TEXT("IA_Look"), EInputActionValueType::Axis2D);
SRC 211: JumpAction = MakeAction(TEXT("IA_Jump"), EInputActionValueType::Boolean);
SRC 212: SprintAction = MakeAction(TEXT("IA_Sprint"), EInputActionValueType::Boolean);
SRC 213: DodgeAction = MakeAction(TEXT("IA_Dodge"), EInputActionValueType::Boolean);
SPAN ::Tick starts line 320
SRC 320: void AVEILCharacter::Tick(float DeltaSeconds)
SRC 321: {
SRC 322: {
SRC 323: static float PadProofAcc = 0.f;
SRC 324: static int PadProofCount = 0;
SRC 325: PadProofAcc += DeltaSeconds;
SRC 326: if (PadProofAcc > 2.f && PadProofCount < 60)
SRC 327: {
SRC 328: PadProofAcc = 0.f; PadProofCount++;
SRC 329: if (APlayerController* PPC = Cast<APlayerController>(GetController()))
SRC 330: {
SRC 331: float LX = PPC->GetInputAnalogKeyState(EKeys::Gamepad_LeftX);
SRC 332: float LY = PPC->GetInputAnalogKeyState(EKeys::Gamepad_LeftY);
SRC 333: float RX = PPC->GetInputAnalogKeyState(EKeys::Gamepad_RightX);
SRC 334: int FA = PPC->IsInputKeyDown(EKeys::Gamepad_FaceButton_Bottom) ? 1 : 0;
SRC 335: int HasBuilt = -1; int HasDef = -1;
SRC 336: if (ULocalPlayer* LP = PPC->GetLocalPlayer()) { if (UEnhancedInputLocalPlayerSubsystem* ES = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()) { HasBuilt = (BuiltMappingContext && ES->HasMappingContext(BuiltMappingContext)) ? 1 : 0; HasDef = (DefaultMappingContext && ES->HasMappingContext(DefaultMappingContext)) ? 1 : 0; } }
SRC 337: UE_LOG(LogTemp, Display, TEXT("PHI PAD PROOF: n=%d lx=%.2f ly=%.2f rx=%.2f faceA=%d hasBuilt=%d hasDef=%d"), PadProofCount, LX, LY, RX, FA, HasBuilt, HasDef);
SRC 338: }
SRC 339: }
SRC 340: }
SRC 341: Super::Tick(DeltaSeconds);
SRC 342: {
SRC 343: static int32 PhiTick365 = 0;
SRC 344: PhiTick365++;
SRC 345: if (PhiTick365 == 5 || PhiTick365 == 30 || PhiTick365 == 60 || PhiTick365 == 120)
SRC 346: {
SRC 347: const FVector CapW365 = GetCapsuleComponent()->GetComponentLocation();
SRC 348: const FVector MeshW365 = GetMesh()->GetComponentLocation();
SRC 349: const FRotator MeshR365 = GetMesh()->GetComponentRotation();
SRC 350: const FFindFloorResult& Fl365 = GetCharacterMovement()->CurrentFloor;
SRC 351: }
SRC 352: }
SRC 353: // PHI CROSSING SAMPLER V2 (jobs 341/342): per-tick shape of the displacement from spawn, a column census at both redrop points, and a redrop onto the PHI_GROUND slab column whose top is z=0.
SRC 354: {
SRC 355: static float PhiC2Clock = 0.f;
SRC 356: static int32 PhiC2Tick = 0;
SRC 357: static int32 PhiC2Stage = 0;
SRC 358: static int32 PhiC2Window = 0;
SRC 359: static FVector PhiC2Spawn = FVector::ZeroVector;
SRC 360: PhiC2Clock += DeltaSeconds;
SRC 361: ++PhiC2Tick;
SRC 362: auto PhiC2Line = [this](const TCHAR* Tag, float Dt) {
SRC 363: FFindFloorResult PhiF;
SRC 364: GetCharacterMovement()->FindFloor(GetActorLocation(), PhiF, false);
ANIMLINE 103: // The Countess: mesh, skeleton and AnimBlueprint all resolve in
ANIMLINE 104: // the ParagonCountess tree (job 116's triangle). Manny's mesh never
ANIMLINE 105: // carried a skeleton in this seat; the Countess closes the triangle.
ANIMLINE 111: TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess"));
ANIMLINE 113: TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed"));
ANIMLINE 121: GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
ANIMLINE 125: UE_LOG(LogVEIL, Warning, TEXT("PHI BODY: Countess pose sequence not found - mesh set, animation unassigned."));
ANIMLINE 129: UE_LOG(LogVEIL, Log, TEXT("PHI BODY: Countess skeletal mesh is the runner's body."));
ANIMLINE 133: UE_LOG(LogVEIL, Warning, TEXT("PHI BODY FALLBACK: SM_Countess not found - primitive runner body stands."));
ANIMLINE 153: if (UAnimSequence* PoseSeq = LoadObject<UAnimSequence>(nullptr, TEXT("/Game/ParagonCountess/Characters/Heroes/Countess/Animations/Idle_Relaxed.Idle_Relaxed")))
ANIMLINE 476: GetMesh()->GetAnimClass() ? *GetMesh()->GetAnimClass()->GetName() : TEXT("none"),
HDR 13: class UInputMappingContext;
HDR 14: class UInputAction;
HDR 15: struct FInputActionValue;
HDR 41: virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
HDR 115: TObjectPtr<UInputMappingContext> DefaultMappingContext;
HDR 118: TObjectPtr<UInputAction> MoveAction;
HDR 121: TObjectPtr<UInputAction> LookAction;
HDR 124: TObjectPtr<UInputAction> JumpAction;
HDR 127: TObjectPtr<UInputAction> SprintAction;
HDR 130: TObjectPtr<UInputAction> DodgeAction;
HDR 133: TObjectPtr<UInputAction> AimAction;
HDR 136: TObjectPtr<UInputAction> FireAction;
HDR 139: TObjectPtr<UInputAction> InteractAction;
HDR 142: void Move(const FInputActionValue& Value);
HDR 143: void Look(const FInputActionValue& Value);
HDR 159: TObjectPtr<UInputMappingContext> BuiltMappingContext;
HDR 162: TArray<TObjectPtr<UInputAction>> BuiltActions;
LOG D:\VEIL-OMNI\Saved\Logs\VEIL.log bytes=487229
ILOG LogPluginManager: Mounting Engine plugin EnhancedInput
ILOG [2026.10.28-21.42.21:847][  0]LogModuleManager: InternalLoadLibrary: 'EnhancedInput' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/EnhancedInput/Binaries/Win64/UnrealEditor-EnhancedInput.dll')
ILOG [2026.10.28-21.42.21:849][  0]LogModuleManager: InternalLoadLibrary: 'InputBlueprintNodes' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/EnhancedInput/Binaries/Win64/UnrealEditor-InputBlueprintNodes.dll')
ILOG [2026.10.28-21.42.26:214][  0]LogModuleManager: InternalLoadLibrary: 'InputEditor' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/EnhancedInput/Binaries/Win64/UnrealEditor-InputEditor.dll')
ILOG [2026.10.28-21.42.30:915][  0]LogGameFeatures: Loading 317 BuiltIn GameFeaturePlugins. Not Amortized. [AudioInsights, BaseMaterial, AudioInsightsRuntime, Bridge, AudioModulationInsights, ChaosCloth, ChaosClothAsset, ChaosClothAssetDataflowNodes, ChaosClothAssetEditorCore, ChaosInsights, ChaosOutfitAsset, ChaosVD, CmdLinkServer, Dataflow, DerivedDataBuildController, EnhancedInput, IoStoreInsights, MassInsights, MeshPainting, Mutable, PCG, RenderGraphInsights, TextureGraph, RenderTraceInsights, TraceUtilities, UbaController, WorldMetrics, XGEController, ACLPlugin, AnimatorKit, ControlRig, AnimationModifierLibrary, DeformerGraph, DNACalib, AnimationData, BlendSpaceMotionAnalysis, IKRig, ControlRigModules, GameplayInsights, ControlRigSpline, EaseCurveTool, LiveLink, LiveLinkDevice, PhysicsControl, LiveLinkHub, RigLogic, SkeletalMeshModelingTools, TweeningUtils, UdpMessaging, LauncherChunkInstaller, PerformanceCaptureCore, AssetManagerEditor, TcpMessaging, ChangelistReview, AssetReferenceRestrictions, BlueprintHeaderView, ColorGrading, BlueprintMaterialTextureNodes, ConsoleVariables, OodleNetwork, CryptoKeys, CurveEditorTools, EditorScriptingUtilities, GeometryMode, EditorDebugTools, EngineAssetDefinitions, ImageWidgets, FacialAnimation, GameplayTagsEditor, DataValidation, MeshLODToolset, ModelingToolsEditorMode, MacGraphicsSwitching, MobileLauncherProfileWizard, MaterialAssetWizard, MaterialAnalyzer, PluginBrowser, ProxyLODPlugin, StylusInput, SequencerAnimTools, SpeedTreeImporter, UVEditor, UMGWidgetPreview, WorldPartitionHLODUtilities, AutomatedPerfTestTools, DatasmithContent, VariantManagerContent, GLTFExporter, NNEDenoiser, VariantManager, NNERuntimeORT, CameraCalibrationCore, CaptureData, LensComponent, Takes, InterchangeAssets, InterchangeEditor, Interchange, CompositeCore, OpenColorIO, AnimationSharing, DumpGPUServices, CLionSourceCodeAccess, CodeLiteSourceCodeAccess, GitSourceControl, NamingTokens, GPUReshape, PlasticSourceControl, KDevelopSourceCodeAccess, N10XSourceCodeAccess, PixWinPlugin, NullSourceCodeAccess, ProjectLauncher, PerforceSourceControl, PluginUtils, PropertyAccessNode, RenderDocPlugin, RiderSourceCodeAccess, SubversionSourceControl, UObjectPlugin, XCodeSourceCodeAccess, VisualStudioSourceCodeAccess, VisualStudioCodeSourceCodeAccess, AdvancedRenamer, AutomationUtils, BackChannel, Buoyancy, ChaosCaching, ChaosEditor, ChaosNiagara, ChaosSolverPlugin, ChaosUserDataPT, CharacterAI, ControlRigPhysics, CommonConversation, EditorDataStorage, EditorDataStorageFeatures, EditorPerformance, EditorTRSGizmo, ControlFlows, EditorTelemetry, Fracture, GeometryCollectionPlugin, GeometryFlow, FullBodyIK, GeometryDataflow, GlobalConfigurationData, GizmoFramework, HttpInsights, Landmass, MeshModelingToolsetExp, LevelSequenceNavigatorBridge, LiveLinkControlRig, LocalizableMessage, MeshResizing, LowLevelNetTrace, MessageBusTester, ModelContextProtocol, MutableAssetUserData, NFORDenoise, NNERuntimeBasicCpu, PlanarCut, PlatformCrypto, PythonScriptPlugin, RuntimeTelemetry, SequenceNavigator, SemanticSearch, SkeletalReduction, ToolsetRegistry, ToolPresets, Water, AlembicImporter, MetaHumanCoreTech, MetaHuman, MetaHumanCharacter, MetaHumanSDK, Cascade, Niagara, NiagaraSimCaching, NiagaraPreviewContent, ActorLayerUtilities, NiagaraInsights, AppleImageUtils, AndroidFileServer, AndroidDeviceProfileSelector, AndroidMoviePlayer, AppleMoviePlayer, AndroidPermission, AudioWidgets, AudioSynesthesia, AssetTags, AudioCapture, ComputeFramework, CableComponent, ChunkDownloader, CustomMeshComponent, ArchVisCharacter, GameplayAbilities, GeometryCache, GeometryProcessing, GeometryScripting, GoogleCloudMessaging, DataRegistry, GooglePAD, HairStrands, ExampleDeviceProfileSelector, InputDebugging, LinuxDeviceProfileSelector, IOSDeviceProfileSelector, GameFeatures, MeshModelingToolset, Metasound, LocationServicesBPLibrary, MsQuic, ModelViewViewModel, ModularGameplay, MobilePatchingUtils, ProceduralMeshComponent, PropertyBindingUtils, PropertyAccessEditor, ResonanceAudio, ScriptableToolsFramework, RigVM, SoundFields, StateTree, SignificanceManager, SkeletalMerging, Synthesis, WaveTable, WebMMoviePlayer, XRBase, EOSShared, OnlineServices, WindowsDeviceProfileSelector, OnlineBase, WindowsMoviePlayer, WorldConditions, OnlineSubsystemNull, OnlineSubsystemUtils, OnlineSubsystem, InterchangeTests, AndroidMedia, AvfMedia, ElectraCodecs, ElectraPlayer, ElectraUtil, D3D12VideoDecodersElectra, ElectraCDM, ElectraSubtitles, ImgMedia, MediaCompositing, MediaIOFramework, MediaPlate, MediaPlayerEditor, MediaProfile, MP4Utilities, OpusDecoderElectra, TmvMedia, ActorSequence, WebMMedia, LevelSequenceEditor, Paper2D, SequencerScripting, SequenceValidator, TemplateSequence, WmfMedia, AISupport, EnvironmentQueryEditor, EngineCameras, GameplayCameras, CameraShakePreviewer, ConcertMain, Scribble, InterchangeAxfAssets, XInputDevice, CaptureManagerEditor, CaptureManagerCore, AllToolsets, AIModuleToolset, ConfigSettingsToolset, AutomationTestToolset, AnimationAssistantToolset, EditorToolset, GameFeaturesToolset, DataflowAgent, DataRegistryToolset, ConversationToolset, GASToolsets, GameplayTagsToolset, MCPClientToolset, PhysicsToolsets, PCGToolset, PluginToolset, SemanticSearchToolset, NiagaraToolsets, SlateInspectorToolset, StateTreeToolset, UMGToolSet, WorldConditionsToolset, SQLiteCore, OnlineSubsystemIOS, ContentBrowserFileDataSource, ContentBrowserClassDataSource, StreamingADA, ContentBrowserAssetDataSource, BaseCharacterFXEditor, ObjectMixer, LightMixer, FileSandbox, ARUtilities, PortableObjectFileDataSource, OnlineSubsystemGooglePlay, ConcertSyncClient, ConcertSyncCore, AppleARKit, ConcertSharedSlate, AppleARKitFaceSupport].
ILOG [2026.10.28-21.42.31:844][  0]LogContentValidation: Adding native validator /Script/InputBlueprintNodes.EnhancedInputUserWidgetValidator
ILOG [2026.10.28-21.44.23:892][548]LogEnhancedInput: Enhanced Input local player subsystem has initialized the user settings!
PHI PR499 VERDICT: REVERSE READ DONE
JOB 499 DONE

```
