// Endosymbiotic Phase-Lock — implementation, VEIL OMNI, LAM 633 / Job 641
#include "EndosymbioticPhaseLock.h"

AEndosymbioticPhaseLock::AEndosymbioticPhaseLock()
{
    PrimaryActorTick.bCanEverTick = true;
    EchoGap = HostRung - NodeRung; // 45.483 - 20.190 = 25.293
}

void AEndosymbioticPhaseLock::PumpProtons(float Amount)
{
    // Action pumps protons -> phase locks -> ATP generated (rung -14.438)
    ProtonGradient += Amount;
}

void AEndosymbioticPhaseLock::SpendAtp(float Amount)
{
    // Spend ATP -> phase dips -> equilibrium must be restored
    ProtonGradient -= Amount;
}

bool AEndosymbioticPhaseLock::MaintainPhase(float DeltaTime)
{
    // Coherence time limit rung -62.160: if phase is not maintained, structures dissolve
    // Return true while phase holds; caller dissolves the structure on false.
    return ProtonGradient >= 0.0f;
}
