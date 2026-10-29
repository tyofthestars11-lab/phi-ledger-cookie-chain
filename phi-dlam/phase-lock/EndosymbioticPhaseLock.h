// Endosymbiotic Phase-Lock — VEIL OMNI, LAM 633 / Job 641
// Player Host: nDNA rung 45.483
// Upgrade Nodes (engulfed bacteria): mtDNA rung 20.190
// Echo Gap: 25.293 — distance to traverse to integrate a node
// ATP generated: rung -14.438 — proton gradient, not a static bar
// Golden pitch angle: mu 17.0324 degrees
// Coherence time limit: rung -62.160 — structures dissolve if phase is not maintained
// Vault: ModularS30eeb54ea3e4V1, VEILDistrict, placed 24, save true
// Countess: grounded, not inverted
// Map: 180952 -> 292786 (180952 x phi)

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndosymbioticPhaseLock.generated.h"

UCLASS()
class VEIL_API AEndosymbioticPhaseLock : public AActor
{
    GENERATED_BODY()
public:
    AEndosymbioticPhaseLock();
    // Host rung, bound, not hand-typed in play: set from source read
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Phi|Host")
    float HostRung = 45.483f;
    // Node rung, +1 fuel engines
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Phi|Node")
    float NodeRung = 20.190f;
    // Echo gap: host - node, traverse to integrate
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Phi|Gap")
    float EchoGap = 25.293f;
    // ATP rung: proton gradient output
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Phi|ATP")
    float AtpRung = -14.438f;
    // Golden pitch angle, degrees
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Phi|Field")
    float GoldenPitchMu = 17.0324f;
    // Coherence limit rung
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Phi|Field")
    float CoherenceLimitRung = -62.160f;
    // Proton gradient: action pumps, phase locks, ATP generated; spend dips, restore equilibrium
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Phi|ATP")
    float ProtonGradient = 0.0f;
    UFUNCTION(BlueprintCallable, Category="Phi|ATP")
    void PumpProtons(float Amount);
    UFUNCTION(BlueprintCallable, Category="Phi|ATP")
    void SpendAtp(float Amount);
    UFUNCTION(BlueprintCallable, Category="Phi|Phase")
    bool MaintainPhase(float DeltaTime);
};
