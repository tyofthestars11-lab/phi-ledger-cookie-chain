# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 19:12:22 UTC

## STEP 1
```
=== BUILDER REGION AND NPC CENSUS 474 - THE GROUND THE LIFE TRANCHE STANDS ON (Ground: Tyree holds the full game explanation and his Pi adds a witness read pointing at population, quests, streaming and campaign wiring, and the accepted kernel is the Nest populated with living NPCs and its first quest. Before that tranche is authored, its ground gets read whole, because the population seat must stand on the builder real region list and the real Paragon mesh paths, never on a generic shape. One, this job prints every builder function signature in VEILWorldBuilder h and cpp, the Build family whole, so the record names which regions the builder already knows, Hub and any Nest or Spire among them. Two, it prints the GameMode spawn region, forty lines from the builder spawn down through the givers, fragments and cache, the exact seat where population already rides. Three, it censuses the Paragon mesh shelves: for Greystone, Murdock, Revenant and the Minions, the skeletal mesh uasset names under each pack, first entries each, so the NPC bodies get cited by their true paths. The verdict in one line: REGION CENSUS with the builder function count. Read only, and every variable carries the rc474 prefix.) ===
SIG VEILWorldBuilder.h 6 // lighting rig (sun, sky, fog). The GameMode spawns it and calls BuildWorld()
SIG VEILWorldBuilder.h 24 AVEILWorldBuilder();
SIG VEILWorldBuilder.h 27 void BuildWorld();
SIG VEILWorldBuilder.h 33 void BuildLighting();
SIG VEILWorldBuilder.h 34 void BuildDistrict();
SIG VEILWorldBuilder.h 35 void BuildHub();
SIG VEILWorldBuilder.cpp 22 AVEILWorldBuilder::AVEILWorldBuilder()
SIG VEILWorldBuilder.cpp 78 void AVEILWorldBuilder::BuildLighting()
SIG VEILWorldBuilder.cpp 143 void AVEILWorldBuilder::BuildDistrict()
SIG VEILWorldBuilder.cpp 211 void AVEILWorldBuilder::BuildHub()
SIG VEILWorldBuilder.cpp 240 void AVEILWorldBuilder::BuildWorld()
SIG VEILWorldBuilder.cpp 268 BuildLighting();
SIG VEILWorldBuilder.cpp 269 BuildDistrict();
SIG VEILWorldBuilder.cpp 270 BuildHub();
GM LINES=354
GM 70 // or the game opened with. Then seat the runner on the plaza and wake
GM 71 // the first machines around him.
GM 72 // Placed worlds (the district / generated-world levels) already hold
GM 73 // the city as real actors - the runtime builder stands down there, so
GM 74 // one world is never built twice. On bare maps it still raises it.
GM 75 const bool bPlacedWorld = GetWorld()->GetName().Contains(TEXT("District"))
GM 76 || GetWorld()->GetName().Contains(TEXT("World"));
GM 77 AVEILWorldBuilder* Builder = bPlacedWorld ? nullptr
GM 78 : GetWorld()->SpawnActor<AVEILWorldBuilder>(
GM 79 FVector::ZeroVector, FRotator::ZeroRotator);
GM 80 if (Builder)
GM 81 {
GM 82 Builder->BuildWorld();
GM 83 if (APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0))
GM 84 {
GM 85 Pawn->SetActorLocation(Builder->PlazaCenter);
GM 86 }
GM 87 for (int32 i = 0; i < 3; ++i)
GM 88 {
GM 89 const float Angle = (2.f * PI / 3.f) * i;
GM 90 const FVector Loc(FMath::Cos(Angle) * 950.f,
GM 91 FMath::Sin(Angle) * 950.f, 240.f);
GM 92 if (AVEILFactionAgent* Agent =
GM 93 GetWorld()->SpawnActor<AVEILFactionAgent>(
GM 94 AVEILFactionAgent::StaticClass(), Loc,
GM 95 FRotator(0.f, -Angle * 180.f / PI, 0.f)))
GM 96 {
GM 97 Agent->SpawnDefaultController();
GM 98 }
GM 99 }
GM 100 }
GM 101 
GM 102 // Seed the world systems with the authored starting data.
GM 103 // OMNI RPG content: the three statues on the plaza ring, three
GM 104 // fragments out in the streets, the cache at the south wall. The
GM 105 // quest system (UOMNIQuestSystem) runs the chain between them.
GM 106 {
GM 107 const TCHAR* Names[3] = { TEXT("Keeper"), TEXT("Seer"), TEXT("Cartographer") };
GM 108 const FVector Spots[3] = {
GM 109 FVector(900.f, 0.f, 10.f), FVector(-450.f, 780.f, 10.f), FVector(-450.f, -780.f, 10.f) };
GM 110 const float Yaws[3] = { 180.f, -60.f, 60.f };
GM 111 for (int32 i = 0; i < 3; ++i)
GM 112 {
GM 113 const FTransform T(FRotator(0.f, Yaws[i], 0.f), Spots[i]);
GM 114 if (AOMNIQuestGiver* Giver = GetWorld()->SpawnActorDeferred<AOMNIQuestGiver>(
GM 115 AOMNIQuestGiver::StaticClass(), T))
GM 116 {
GM 117 Giver->GiverName = FName(Names[i]);
GM 118 Giver->FinishSpawning(T);
GM 119 }
GM 120 }
GM 121 const FVector Shards[3] = {
GM 122 FVector(2000.f, 500.f, 260.f), FVector(-2000.f, -900.f, 260.f), FVector(600.f, -2100.f, 260.f) };
GM 123 for (int32 i = 0; i < 3; ++i)
GM 124 {
GM 125 GetWorld()->SpawnActor<AOMNIFragment>(
GM 126 AOMNIFragment::StaticClass(), Shards[i], FRotator::ZeroRotator);
GM 127 }
GM 128 GetWorld()->SpawnActor<AOMNICache>(
GM 129 AOMNICache::StaticClass(), FVector(0.f, -6200.f, 10.f), FRotator::ZeroRotator);
GM 130 }
GM 131 if (UVEILDiscoveryManager* Discovery = GetWorld()->GetSubsystem<UVEILDiscoveryManager>())
GM 132 {
GM 133 for (const FVEILMystery& Mystery : MysteriesToRegister)
GM 134 {
GM 135 Discovery->RegisterMystery(Mystery);
GM 136 }
GM 137 Discovery->OnMysterySolved.AddDynamic(this, &AVEILGameMode::HandleMysterySolved);
GM 138 }
GM 139 
GM 140 if (UVEILFactionManager* Factions = GetWorld()->GetSubsystem<UVEILFactionManager>())
PACK ParagonGreystone sk=0
PACK ParagonMurdock sk=0
PACK ParagonRevenant sk=0
PACK ParagonMinions sk=1
SK /Game/ParagonMinions/Characters/Minions/Down_Minions/Meshes/SK_Minion_Lane_Super
PHI RC474 VERDICT: REGION CENSUS sigs=14
JOB 474 DONE

```
