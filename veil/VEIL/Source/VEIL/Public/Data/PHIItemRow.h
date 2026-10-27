#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "PHIItemRow.generated.h"

// One row of the item database (Data/items.csv -> DT_Items).
// Stats grow on the phi curve: tier t damage = round(10 * phi^(t-1)),
// value = round(25 * phi^(t-1)); rarity IS the tier, 1..5.
USTRUCT(BlueprintType)
struct FPHIItemRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PHI Item")
	FString DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PHI Item")
	FString ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PHI Item")
	float Damage = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PHI Item")
	int32 Rarity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PHI Item")
	int32 Value = 0;
};
