# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 07:42:13 UTC

## STEP 1
```
=== WORLDBUILDER SOURCE PULL - NAME THE MEGA-VOLUME AT ITS SPAWN SITE (Job 356 stopped clean: its editor commandlet censused the placed VEILDistrict map and NO static-mesh actor there contains the spawn column - the repair was aimed at the wrong venue, and the prints prove it. Job 347s census was a RUNTIME census: the district is built at runtime by AVEILWorldBuilder (job 351s read: the builder actor builds the playable district from engine primitives at runtime - ground, phi-scaled tower grid, plaza, beacon spire - and the GameMode spawns it and calls BuildWorld before anything else). StaticMeshActor_0 of the runtime census - loc (0,0,-50), bounds top=10085.1 base=-138.3, the volume she lands inside and gets ejected through - is a builder-spawned actor, and the repair belongs in the builders spawn math, not in the placed map. THIS JOB pulls the builder source whole from the merged base (now D:\VEIL-OMNI): VEILWorldBuilder.cpp and .h printed entire, plus the GameMode builder-spawn section, so the repair job is authored against the exact spawn code. Read-only; nothing is edited.) ===
BUILDER FILE: D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp bytes=8646
BUILDER FILE: D:\VEIL-OMNI\Source\VEIL\Public\World\VEILWorldBuilder.h bytes=1353
===== D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp (builder spawn section) =====
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "VEIL.h"
#include "World/VEILWorldBuilder.h"
#include "World/OMNIQuestContent.h"

// ---------------------------------------------------------------------------
---
	// one world is never built twice. On bare maps it still raises it.
	const bool bPlacedWorld = GetWorld()->GetName().Contains(TEXT("District"))
		|| GetWorld()->GetName().Contains(TEXT("World"));
	AVEILWorldBuilder* Builder = bPlacedWorld ? nullptr
		: GetWorld()->SpawnActor<AVEILWorldBuilder>(
			FVector::ZeroVector, FRotator::ZeroRotator);
	if (Builder)
---
	const bool bPlacedWorld = GetWorld()->GetName().Contains(TEXT("District"))
		|| GetWorld()->GetName().Contains(TEXT("World"));
	AVEILWorldBuilder* Builder = bPlacedWorld ? nullptr
		: GetWorld()->SpawnActor<AVEILWorldBuilder>(
			FVector::ZeroVector, FRotator::ZeroRotator);
	if (Builder)
	{
---
			FVector::ZeroVector, FRotator::ZeroRotator);
	if (Builder)
	{
		Builder->BuildWorld();
		if (APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0))
		{
			Pawn->SetActorLocation(Builder->PlazaCenter);
---
			const FVector Loc(FMath::Cos(Angle) * 950.f,
				FMath::Sin(Angle) * 950.f, 240.f);
			if (AVEILFactionAgent* Agent =
				GetWorld()->SpawnActor<AVEILFactionAgent>(
					AVEILFactionAgent::StaticClass(), Loc,
					FRotator(0.f, -Angle * 180.f / PI, 0.f)))
			{
---
		for (int32 i = 0; i < 3; ++i)
		{
			const FTransform T(FRotator(0.f, Yaws[i], 0.f), Spots[i]);
			if (AOMNIQuestGiver* Giver = GetWorld()->SpawnActorDeferred<AOMNIQuestGiver>(
				AOMNIQuestGiver::StaticClass(), T))
			{
				Giver->GiverName = FName(Names[i]);
---
			FVector(2000.f, 500.f, 260.f), FVector(-2000.f, -900.f, 260.f), FVector(600.f, -2100.f, 260.f) };
		for (int32 i = 0; i < 3; ++i)
		{
			GetWorld()->SpawnActor<AOMNIFragment>(
				AOMNIFragment::StaticClass(), Shards[i], FRotator::ZeroRotator);
		}
		GetWorld()->SpawnActor<AOMNICache>(
---
			GetWorld()->SpawnActor<AOMNIFragment>(
				AOMNIFragment::StaticClass(), Shards[i], FRotator::ZeroRotator);
		}
		GetWorld()->SpawnActor<AOMNICache>(
			AOMNICache::StaticClass(), FVector(0.f, -6200.f, 10.f), FRotator::ZeroRotator);
	}
	if (UVEILDiscoveryManager* Discovery = GetWorld()->GetSubsystem<UVEILDiscoveryManager>())
---
JOB 361 DONE

```
