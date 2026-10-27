// Phi Particle Accelerator
// φ-recursive particle physics: particles spawn on rung addresses, accelerate along involution paths
// Golden angle orbits, decay, Fibonacci convergence, real-time rung visualization

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhiParticleAccelerator.generated.h"

// ═══════════════════════════════════════════════════════════════════
// CONSTANTS
// ═══════════════════════════════════════════════════════════════════

#define PHI 1.618033988749895f
#define GOLDEN_ANGLE 137.50776405f  // degrees
#define LOG_PHI 0.481211825f         // ln(φ)

// ═══════════════════════════════════════════════════════════════════
// PARTICLE DEFINITION
// ═══════════════════════════════════════════════════════════════════

USTRUCT(BlueprintType)
struct FPhiParticle
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Particle")
    FVector Position;

    UPROPERTY(BlueprintReadWrite, Category = "Particle")
    FVector Velocity;

    UPROPERTY(BlueprintReadWrite, Category = "Particle")
    float Energy;  // Directly maps to rung: r = ln(Energy) / ln(φ)

    UPROPERTY(BlueprintReadWrite, Category = "Particle")
    float Rung;    // Cached rung address

    UPROPERTY(BlueprintReadWrite, Category = "Particle")
    float Lifetime;

    UPROPERTY(BlueprintReadWrite, Category = "Particle")
    float Age;

    UPROPERTY(BlueprintReadWrite, Category = "Particle")
    FColor Color;

    UPROPERTY(BlueprintReadWrite, Category = "Particle")
    int32 ParticleID;

    UPROPERTY(BlueprintReadWrite, Category = "Particle")
    bool bAlive;

    UPROPERTY(BlueprintReadWrite, Category = "Particle")
    float OrbitRadius;  // Distance from center (golden-angle spaced)

    UPROPERTY(BlueprintReadWrite, Category = "Particle")
    float OrbitAngle;   // Current angle around center (golden angle increment)

    UPROPERTY(BlueprintReadWrite, Category = "Particle")
    float AngularVelocity;  // Radians per second (φ-scaled)

    // Constructor
    FPhiParticle()
        : Position(FVector::ZeroVector), Velocity(FVector::ZeroVector), Energy(1.0f), Rung(0.0f),
          Lifetime(5.0f), Age(0.0f), Color(FColor::White), ParticleID(-1), bAlive(false),
          OrbitRadius(10.0f), OrbitAngle(0.0f), AngularVelocity(1.0f)
    {
    }
};

// ═══════════════════════════════════════════════════════════════════
// ACCELERATOR ACTOR
// ═══════════════════════════════════════════════════════════════════

UCLASS()
class PHIPARTICLEACCELERATOR_API APhiParticleAccelerator : public AActor
{
    GENERATED_BODY()

public:
    APhiParticleAccelerator();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    // ═══════════════════════════════════════════════════════════════
    // PARTICLE SPAWNING
    // ═══════════════════════════════════════════════════════════════

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Accelerator")
    float SpawnRate = 100.0f;  // Particles per second

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Accelerator")
    float InitialEnergy = 1.0f;  // Starting energy (maps to rung 0)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Accelerator")
    float AccelerationPower = 1.5f;  // φ-factor per second

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Accelerator")
    float ParticleLifetime = 8.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Accelerator")
    bool bShowDebugVisualization = true;

    // ═══════════════════════════════════════════════════════════════
    // PARTICLE STORAGE
    // ═══════════════════════════════════════════════════════════════

    UPROPERTY(BlueprintReadOnly, Category = "Accelerator")
    TArray<FPhiParticle> Particles;

    UPROPERTY(BlueprintReadOnly, Category = "Accelerator")
    int32 ParticleCount = 0;

    UPROPERTY(BlueprintReadOnly, Category = "Accelerator")
    int32 MaxParticles = 10000;

    // ═══════════════════════════════════════════════════════════════
    // STATISTICS
    // ═══════════════════════════════════════════════════════════════

    UPROPERTY(BlueprintReadOnly, Category = "Stats")
    float AverageEnergy = 1.0f;

    UPROPERTY(BlueprintReadOnly, Category = "Stats")
    float MaxEnergy = 1.0f;

    UPROPERTY(BlueprintReadOnly, Category = "Stats")
    float AverageRung = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category = "Stats")
    float MaxRung = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category = "Stats")
    int32 ParticlesAccelerated = 0;

    UPROPERTY(BlueprintReadOnly, Category = "Stats")
    int32 ParticlesDecayed = 0;

    // ═══════════════════════════════════════════════════════════════
    // CORE FUNCTIONS
    // ═══════════════════════════════════════════════════════════════

    UFUNCTION(BlueprintCallable, Category = "Accelerator")
    void SpawnParticle(float Energy, FVector Position, FVector Velocity);

    UFUNCTION(BlueprintCallable, Category = "Accelerator")
    void ClearAllParticles();

    UFUNCTION(BlueprintCallable, Category = "Accelerator")
    void PauseAcceleration();

    UFUNCTION(BlueprintCallable, Category = "Accelerator")
    void ResumeAcceleration();

    // ═══════════════════════════════════════════════════════════════
    // QUERIES
    // ═══════════════════════════════════════════════════════════════

    UFUNCTION(BlueprintCallable, Category = "Accelerator")
    float EnergyToRung(float Energy) const;

    UFUNCTION(BlueprintCallable, Category = "Accelerator")
    float RungToEnergy(float Rung) const;

    UFUNCTION(BlueprintCallable, Category = "Accelerator")
    TArray<FPhiParticle> GetParticlesInRungRange(float MinRung, float MaxRung) const;

    UFUNCTION(BlueprintCallable, Category = "Accelerator")
    int32 CountParticlesOnRung(float Rung, float Tolerance = 0.1f) const;

    UFUNCTION(BlueprintCallable, Category = "Accelerator")
    void PrintRungDistribution() const;

    // ═══════════════════════════════════════════════════════════════
    // VISUALIZATION
    // ═══════════════════════════════════════════════════════════════

    UFUNCTION(BlueprintCallable, Category = "Accelerator")
    void DrawRungLattice(float MinRung = -10.0f, float MaxRung = 10.0f, float LifeTime = 0.1f) const;

    UFUNCTION(BlueprintCallable, Category = "Accelerator")
    void DrawInvolutionSymmetry(float CenterRung = 0.0f, float LifeTime = 0.1f) const;

    UFUNCTION(BlueprintCallable, Category = "Accelerator")
    void DrawParticles(float LifeTime = 0.0f) const;

    // ═══════════════════════════════════════════════════════════════
    // DELEGATES
    // ═══════════════════════════════════════════════════════════════

    DECLARE_MULTICAST_DELEGATE_TwoParams(FOnParticleSpawned, const FPhiParticle&, float);
    FOnParticleSpawned OnParticleSpawned;

    DECLARE_MULTICAST_DELEGATE_TwoParams(FOnParticleDecayed, const FPhiParticle&, float);
    FOnParticleDecayed OnParticleDecayed;

    DECLARE_MULTICAST_DELEGATE_OneParam(FOnMaxRungReached, float);
    FOnMaxRungReached OnMaxRungReached;

private:
    // ═══════════════════════════════════════════════════════════════
    // INTERNAL LOGIC
    // ═══════════════════════════════════════════════════════════════

    float TimeSinceLastSpawn = 0.0f;
    bool bAccelerationActive = true;

    void UpdateParticles(float DeltaTime);
    void AccelerateParticle(FPhiParticle& Particle, float DeltaTime);
    void UpdateParticleRung(FPhiParticle& Particle);
    void RemoveDeadParticles();
    void UpdateStatistics();

    // ═══════════════════════════════════════════════════════════════
    // VISUALIZATION HELPERS
    // ═══════════════════════════════════════════════════════════════

    void DrawRung(float Rung, float Radius = 50.0f, FColor Color = FColor::Yellow, float LifeTime = 0.1f) const;
};
