# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 23:17:54 UTC

## STEP 1
```
=== JOB 513 - THE BLACK WORLD READ AT ITS ADDRESS (Ground: his hands closed the controller question in the game own window - the pad arrives there; the editor was the wall. What stands open in his photo is the world itself: the runner, the monument, the ground all render as black shapes against a blue sky, for hours. Everything stands and nothing is lit or textured. This job reads the two witnesses that name the fault: the fresh log the standalone window just wrote, pulled for its pad proof, its body check, and every material or load warning line; and the world builder source at the exact lines where blocks take their material and tint. Nothing is patched here - the print names the address and the fix files from it in the same motion. Every variable carries the p513 prefix.) ===
LOG VEIL.log at 10/28/2026 17:17:42
WARN LogWindows: Failed to load 'aqProf.dll' (GetLastError=126)
WARN LogWindows: Failed to load 'VtuneApi.dll' (GetLastError=126)
WARN LogWindows: Failed to load 'VtuneApi32e.dll' (GetLastError=126)
WARN LogPluginManager: Mounting Engine plugin BaseMaterial
WARN LogPluginManager: Mounting Engine plugin BlueprintMaterialTextureNodes
WARN LogPluginManager: Mounting Engine plugin MaterialAnalyzer
WARN LogPluginManager: Mounting Engine plugin MaterialAssetWizard
WARN LogWindows: Failed to load 'WinPixGpuCapturer.dll' (GetLastError=126)
WARN LogDevObjectVersion:   Dev-PhysicsMaterial-Chaos (B68FC16E-8B1B-42E2-B453-215C058844FE): 1
WARN [2026.10.28-23.03.12:440][  0]LogConfig: CVar [[VisualizeCalibrationColorMaterialPath:/Engine/EngineMaterials/PPM_DefaultCalibrationColor.PPM_DefaultCalibrationColor]] deferred - dummy variable created
WARN [2026.10.28-23.03.12:440][  0]LogConfig: CVar [[VisualizeCalibrationGrayscaleMaterialPath:/Engine/EngineMaterials/PPM_DefaultCalibrationGrayscale.PPM_DefaultCalibrationGrayscale]] deferred - dummy variable created
WARN [2026.10.28-23.03.12:442][  0]LogConfig: CVar [[FixedBootOrder:/Script/Engine/Default__MaterialInterface]] deferred - dummy variable created
WARN [2026.10.28-23.03.12:442][  0]LogConfig: CVar [[ClassesExcludedOnDedicatedServer:MaterialExpression]] deferred - dummy variable created
WARN [2026.10.28-23.03.12:442][  0]LogConfig: CVar [[VersionedIntRValues:r.MaterialEditor.LWCTruncateMode]] deferred - dummy variable created
WARN [2026.10.28-23.03.12:477][  0]LogConfig: Set CVar [[r.MaterialQualityLevel:1 ; High quality]]
WARN [2026.10.28-23.03.12:477][  0]LogConfig: Set CVar [[r.AnisotropicMaterials:1]]
WARN [2026.10.28-23.03.12:493][  0]LogConfig: Set CVar [[r.PSOPrecache.KeepInMemoryForActiveMaterials:1]]
WARN [2026.10.28-23.03.38:428][  0]LogMaterial: Display: Missing cached shadermap for /Engine/EngineMaterials/WorldGridMaterial.WorldGridMaterial in PCD3D_SM6, Default, SM6, Editor (DDC key hash: 333808e2fdc0e5b52041b7e2f748a668c8c8f704), compiling. Is special engine material.
WARN [2026.10.28-23.03.38:895][  0]LogMaterial: Display: Missing cached shadermap for /Engine/EngineMaterials/DefaultDeferredDecalMaterial.DefaultDeferredDecalMaterial in PCD3D_SM6, Default, SM6, Editor (DDC key hash: 1f446a79eb02135e3c897c382cfde3629abfcbf0), compiling. 
WARN [2026.10.28-23.03.38:989][  0]LogMaterial: Display: Missing cached shadermap for /Engine/EngineMaterials/DefaultLightFunctionMaterial.DefaultLightFunctionMaterial in PCD3D_SM6, Default, SM6, Editor (DDC key hash: d67b6c967b87f60d759ffbab4545ee07902e31ad), compiling. 
WARN [2026.10.28-23.03.39:053][  0]LogMaterial: Display: Missing cached shadermap for /Engine/EngineMaterials/DefaultPostProcessMaterial.DefaultPostProcessMaterial in PCD3D_SM6, Default, SM6, Editor (DDC key hash: aee77630869c28a243af6c85a960190275ceda2c), compiling. 
WARN [2026.10.28-23.03.45:593][  0]LogModuleManager: InternalLoadLibrary: 'MaterialBaking' ('C:/Program Files/Epic Games/UE_5.8/Engine/Binaries/Win64/UnrealEditor-MaterialBaking.dll')
WARN [2026.10.28-23.03.47:530][  0]LogModuleManager: InternalLoadLibrary: 'MaterialEditor' ('C:/Program Files/Epic Games/UE_5.8/Engine/Binaries/Win64/UnrealEditor-MaterialEditor.dll')
WARN [2026.10.28-23.03.47:643][  0]LogModuleManager: InternalLoadLibrary: 'BlueprintMaterialTextureNodes' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Editor/BlueprintMaterialTextureNodes/Binaries/Win64/UnrealEditor-BlueprintMaterialTextureNodes.dll')
WARN [2026.10.28-23.03.52:572][  0]LogModuleManager: InternalLoadLibrary: 'MaterialAnalyzer' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Editor/MaterialAnalyzer/Binaries/Win64/UnrealEditor-MaterialAnalyzer.dll')
WARN COUNT SHOWN=25
BUILDER LINES=306
B513 17: #include "Materials/MaterialInstanceDynamic.h"
B513 40: UStaticMeshComponent* AVEILWorldBuilder::SpawnBlock(const FVector& Location,
B513 41: const FVector& Scale, UStaticMesh* Mesh, const FLinearColor& Tint,
B513 42: float EmissiveStrength)
B513 56: // Tint through a dynamic instance of whatever material the shape ships
B513 57: // with. The parameter writes are guarded by the material itself: a
B513 58: // material without the parameter simply keeps its authored look.
B513 59: if (UMaterialInterface* Base = Comp->GetMaterial(0))
B513 61: UMaterialInstanceDynamic* MID =
B513 62: UMaterialInstanceDynamic::Create(Base, Block);
B513 65: MID->SetVectorParameterValue(TEXT("Color"), Tint);
B513 66: MID->SetVectorParameterValue(TEXT("BaseColor"), Tint);
B513 67: if (EmissiveStrength > 0.f)
B513 69: MID->SetVectorParameterValue(TEXT("EmissiveColor"),
B513 70: Tint * EmissiveStrength);
B513 72: Comp->SetMaterial(0, MID);
B513 91: Light->SetIntensity(3.2f);
B513 111: Comp->SetIntensity(0.5f);
B513 124: // sun and sky above, not from tinting the fog against spec.
B513 136: Comp->SetIntensity(90000.f);
B513 148: const FLinearColor GroundTint(0.08f, 0.08f, 0.11f);
B513 149: const FLinearColor TowerTint(0.23f, 0.25f, 0.38f);
B513 150: const FLinearColor TowerTintWarm(0.34f, 0.24f, 0.16f);
B513 151: const FLinearColor PlazaTint(0.30f, 0.23f, 0.10f);
B513 152: const FLinearColor GoldTint(1.0f, 0.78f, 0.30f);
B513 155: SpawnBlock(FVector(0.f, 0.f, -50.f), FVector(160.f, 160.f, 1.f),
B513 156: CubeMesh, GroundTint, 0.f);
B513 159: SpawnBlock(FVector(0.f, 0.f, 4.f), FVector(11.f, 11.f, 0.08f),
B513 160: CylinderMesh, PlazaTint, 0.f);
B513 176: SpawnBlock(Loc, Scale, CubeMesh,
B513 177: (Towers % 3 == 0) ? TowerTintWarm : TowerTint, 0.f);
B513 181: SpawnBlock(FVector(Loc.X, Loc.Y, Height + 12.f),
B513 183: CubeMesh, GoldTint, 2.5f);
B513 189: SpawnBlock(FVector(Loc.X, Loc.Y, Height * 0.55f),
B513 191: CubeMesh, GoldTint, 1.4f);
B513 198: SpawnBlock(FVector(0.f, -2600.f, 1350.f), FVector(3.2f, 3.2f, 27.f),
B513 199: CubeMesh, TowerTint, 0.f);
B513 200: SpawnBlock(FVector(0.f, -2600.f, 2760.f), FVector(1.5f, 1.5f, 1.5f),
B513 201: SphereMesh, GoldTint, 3.5f);
B513 217: const FLinearColor GoldTint(1.0f, 0.78f, 0.30f);
B513 218: const FLinearColor RoadTint(0.16f, 0.13f, 0.07f);
B513 226: SpawnBlock(Loc, Scale, CubeMesh, RoadTint, 0.f);
B513 235: SpawnBlock(Loc, FVector(1.2f, 1.2f, 5.2f), CubeMesh, GoldTint, 2.0f);
B513 245: const FLinearColor GoldTint(1.0f, 0.78f, 0.30f);
B513 257: SpawnBlock(S1, FVector(1.1f, 1.1f, 1.1f), SphereMesh, GoldTint, 3.0f);
B513 258: SpawnBlock(S2, FVector(1.1f, 1.1f, 1.1f), SphereMesh, GoldTint, 3.0f);
B513 265: SpawnBlock(Mid, BarScale, CubeMesh, GoldTint, 1.8f);
B513 269: SpawnBlock(FVector(Base.X, Base.Y, 1720.f), FVector(2.2f, 2.2f, 2.2f), SphereMesh, GoldTint, 4.0f);
PHI P513 VERDICT: BLACK WORLD READ PRINTED ABOVE
JOB 513 DONE

```
