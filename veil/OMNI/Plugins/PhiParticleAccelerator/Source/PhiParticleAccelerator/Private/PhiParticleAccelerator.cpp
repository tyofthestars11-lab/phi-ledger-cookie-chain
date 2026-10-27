// Phi Particle Accelerator Implementation
// Complete particle physics engine with φ-recursive addressing

#include "PhiParticleAccelerator.h"
#include "Components/SceneComponent.h"
#include "DrawDebugHelpers.h"

// FColor has no Lerp member in UE 5.8 (job 202: C2039 at the five color
// gradient sites). Lerp in linear space, convert back.
static FColor PhiLerpColor(FColor A, FColor B, float T)
{
    // FLinearColor::Lerp does not exist either (job 203) - pure arithmetic.
    const FLinearColor LA(A);
    const FLinearColor LB(B);
    const float K = FMath::Clamp(T, 0.0f, 1.0f);
    return (LA + (LB - LA) * K).ToFColorSRGB();
}

APhiParticleAccelerator::APhiParticleAccelerator()
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.TickInterval = 1.0f / 60.0f;  // 60 FPS
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

void APhiParticleAccelerator::BeginPlay()
{
    Super::BeginPlay();

    Particles.Reserve(MaxParticles);

    if (bShowDebugVisualization)
    {
        UE_LOG(LogTemp, Display, TEXT("PHI Particle Accelerator initialized at %.2f, %.2f, %.2f"),
               GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
        UE_LOG(LogTemp, Display, TEXT("Spawn rate: %.1f p/s | Acceleration: %.2f φ/s | Max particles: %d"),
               SpawnRate, AccelerationPower, MaxParticles);
    }
}

void APhiParticleAccelerator::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Spawn new particles
    if (bAccelerationActive)
    {
        TimeSinceLastSpawn += DeltaTime;
        float particlesToSpawn = SpawnRate * TimeSinceLastSpawn;

        while (particlesToSpawn >= 1.0f && ParticleCount < MaxParticles)
        {
            // Spawn at center with slight random angle
            float angle = FMath::FRandRange(0.0f, 2.0f * PI);
            FVector spawnPos = GetActorLocation() + FVector(
                FMath::Cos(angle) * 10.0f,
                FMath::Sin(angle) * 10.0f,
                0.0f
            );

            SpawnParticle(InitialEnergy, spawnPos, FVector::ZeroVector);
            particlesToSpawn -= 1.0f;
        }

        // Carry only the unspawned fraction, converted back to time
        TimeSinceLastSpawn = (ParticleCount >= MaxParticles)
            ? 0.0f
            : particlesToSpawn / FMath::Max(SpawnRate, 0.001f);
    }

    // Update all particles
    UpdateParticles(DeltaTime);

    // Remove dead particles
    RemoveDeadParticles();

    // Update statistics
    UpdateStatistics();

    // Debug visualization
    if (bShowDebugVisualization)
    {
        DrawParticles(0.1f);
        DrawRungLattice(-5.0f, 10.0f, 0.1f);
    }
}

// ═══════════════════════════════════════════════════════════════════
// PARTICLE SPAWNING
// ═══════════════════════════════════════════════════════════════════

void APhiParticleAccelerator::SpawnParticle(float Energy, FVector Position, FVector Velocity)
{
    if (ParticleCount >= MaxParticles)
    {
        return;
    }

    FPhiParticle NewParticle;
    NewParticle.ParticleID = ParticleCount;
    NewParticle.Position = Position;
    NewParticle.Velocity = Velocity;
    NewParticle.Energy = FMath::Max(Energy, 0.001f);  // Prevent log(0)
    NewParticle.Rung = EnergyToRung(NewParticle.Energy);
    NewParticle.Lifetime = ParticleLifetime;
    NewParticle.Age = 0.0f;
    NewParticle.bAlive = true;

    // Color by rung: blue (low) → cyan → green → yellow → red (high)
    float normalizedRung = (NewParticle.Rung + 10.0f) / 20.0f;  // -10 to +10 → 0 to 1
    normalizedRung = FMath::Clamp(normalizedRung, 0.0f, 1.0f);

    if (normalizedRung < 0.25f)
    {
        // Blue to cyan
        NewParticle.Color = PhiLerpColor(FColor::Blue, FColor::Cyan, normalizedRung * 4.0f);
    }
    else if (normalizedRung < 0.5f)
    {
        // Cyan to green
        NewParticle.Color = PhiLerpColor(FColor::Cyan, FColor::Green, (normalizedRung - 0.25f) * 4.0f);
    }
    else if (normalizedRung < 0.75f)
    {
        // Green to yellow
        NewParticle.Color = PhiLerpColor(FColor::Green, FColor::Yellow, (normalizedRung - 0.5f) * 4.0f);
    }
    else
    {
        // Yellow to red
        NewParticle.Color = PhiLerpColor(FColor::Yellow, FColor::Red, (normalizedRung - 0.75f) * 4.0f);
    }

    // Orbital parameters
    NewParticle.OrbitRadius = 10.0f + NewParticle.Energy * 5.0f;
    NewParticle.OrbitAngle = FMath::FRandRange(0.0f, 2.0f * PI);
    NewParticle.AngularVelocity = (1.0f / (NewParticle.Energy + 1.0f)) * 180.0f;  // Slower for higher energy

    Particles.Add(NewParticle);
    ParticleCount++;

    OnParticleSpawned.Broadcast(NewParticle, NewParticle.Rung);

    if (bShowDebugVisualization && ParticleCount % 100 == 0)
    {
        UE_LOG(LogTemp, Display, TEXT("Spawned particle %d | Energy: %.4f | Rung: %.2f"),
               NewParticle.ParticleID, NewParticle.Energy, NewParticle.Rung);
    }
}

void APhiParticleAccelerator::ClearAllParticles()
{
    Particles.Empty();
    ParticleCount = 0;
    ParticlesAccelerated = 0;
    ParticlesDecayed = 0;

    if (bShowDebugVisualization)
    {
        UE_LOG(LogTemp, Display, TEXT("All particles cleared"));
    }
}

void APhiParticleAccelerator::PauseAcceleration()
{
    bAccelerationActive = false;
    if (bShowDebugVisualization)
    {
        UE_LOG(LogTemp, Display, TEXT("Acceleration paused"));
    }
}

void APhiParticleAccelerator::ResumeAcceleration()
{
    bAccelerationActive = true;
    if (bShowDebugVisualization)
    {
        UE_LOG(LogTemp, Display, TEXT("Acceleration resumed"));
    }
}

// ═══════════════════════════════════════════════════════════════════
// PARTICLE PHYSICS
// ═══════════════════════════════════════════════════════════════════

void APhiParticleAccelerator::UpdateParticles(float DeltaTime)
{
    for (auto& Particle : Particles)
    {
        if (!Particle.bAlive)
        {
            continue;
        }

        // Update age
        Particle.Age += DeltaTime;

        // Acceleration
        if (bAccelerationActive)
        {
            AccelerateParticle(Particle, DeltaTime);
        }

        // Orbital motion
        float orbitRadiansPerSecond = FMath::DegreesToRadians(Particle.AngularVelocity);
        Particle.OrbitAngle += orbitRadiansPerSecond * DeltaTime;

        // Update position based on orbit
        FVector orbitOffset = FVector(
            FMath::Cos(Particle.OrbitAngle) * Particle.OrbitRadius,
            FMath::Sin(Particle.OrbitAngle) * Particle.OrbitRadius,
            FMath::Sin(Particle.OrbitAngle) * Particle.OrbitRadius * 0.5f
        );

        Particle.Position = GetActorLocation() + orbitOffset + Particle.Velocity * DeltaTime;

        // Decay
        if (Particle.Age >= Particle.Lifetime)
        {
            Particle.bAlive = false;
            ParticlesDecayed++;
            OnParticleDecayed.Broadcast(Particle, Particle.Rung);
        }
    }
}

void APhiParticleAccelerator::AccelerateParticle(FPhiParticle& Particle, float DeltaTime)
{
    // Acceleration: Energy *= φ^(AccelerationPower * DeltaTime)
    float rungIncrease = AccelerationPower * DeltaTime;
    float energyMultiplier = FMath::Pow(PHI, rungIncrease);

    Particle.Energy *= energyMultiplier;
    ParticlesAccelerated++;

    // Update rung
    UpdateParticleRung(Particle);

    // Velocity direction: radially outward at particle's orbital speed
    FVector orbitCenter = GetActorLocation();
    FVector toParticle = (Particle.Position - orbitCenter).GetSafeNormal();
    Particle.Velocity = toParticle * (Particle.Energy * 10.0f);  // Speed scales with energy

    // Check for max rung achievement
    if (Particle.Rung > 8.0f && Particle.Rung - 0.1f <= 8.0f)  // Just crossed 8
    {
        OnMaxRungReached.Broadcast(Particle.Rung);
        if (bShowDebugVisualization)
        {
            UE_LOG(LogTemp, Warning, TEXT("PARTICLE %d REACHED RUNG %.2f (Energy: %.4f)"),
                   Particle.ParticleID, Particle.Rung, Particle.Energy);
        }
    }
}

void APhiParticleAccelerator::UpdateParticleRung(FPhiParticle& Particle)
{
    Particle.Rung = EnergyToRung(Particle.Energy);
}

void APhiParticleAccelerator::RemoveDeadParticles()
{
    Particles.RemoveAll([](const FPhiParticle& P) { return !P.bAlive; });
    ParticleCount = Particles.Num();
}

void APhiParticleAccelerator::UpdateStatistics()
{
    if (ParticleCount == 0)
    {
        AverageEnergy = 1.0f;
        AverageRung = 0.0f;
        return;
    }

    float totalEnergy = 0.0f;
    float totalRung = 0.0f;
    MaxEnergy = 0.0f;
    MaxRung = -100.0f;

    for (const auto& Particle : Particles)
    {
        if (Particle.bAlive)
        {
            totalEnergy += Particle.Energy;
            totalRung += Particle.Rung;
            MaxEnergy = FMath::Max(MaxEnergy, Particle.Energy);
            MaxRung = FMath::Max(MaxRung, Particle.Rung);
        }
    }

    AverageEnergy = totalEnergy / ParticleCount;
    AverageRung = totalRung / ParticleCount;
}

// ═══════════════════════════════════════════════════════════════════
// CONVERSIONS
// ═══════════════════════════════════════════════════════════════════

float APhiParticleAccelerator::EnergyToRung(float Energy) const
{
    if (Energy <= 0.0f)
    {
        return -1000.0f;
    }

    return FMath::Loge(Energy) / LOG_PHI;
}

float APhiParticleAccelerator::RungToEnergy(float Rung) const
{
    return FMath::Pow(PHI, Rung);
}

// ═══════════════════════════════════════════════════════════════════
// QUERIES
// ═══════════════════════════════════════════════════════════════════

TArray<FPhiParticle> APhiParticleAccelerator::GetParticlesInRungRange(float MinRung, float MaxRungIn) const
{
    TArray<FPhiParticle> Result;

    for (const auto& Particle : Particles)
    {
        if (Particle.bAlive && Particle.Rung >= MinRung && Particle.Rung <= MaxRungIn)
        {
            Result.Add(Particle);
        }
    }

    return Result;
}

int32 APhiParticleAccelerator::CountParticlesOnRung(float Rung, float Tolerance) const
{
    int32 Count = 0;

    for (const auto& Particle : Particles)
    {
        if (Particle.bAlive && FMath::Abs(Particle.Rung - Rung) <= Tolerance)
        {
            Count++;
        }
    }

    return Count;
}

void APhiParticleAccelerator::PrintRungDistribution() const
{
    if (ParticleCount == 0)
    {
        UE_LOG(LogTemp, Display, TEXT("No particles to analyze"));
        return;
    }

    UE_LOG(LogTemp, Display, TEXT("\n=== RUNG DISTRIBUTION ==="));
    UE_LOG(LogTemp, Display, TEXT("Total particles: %d"), ParticleCount);
    UE_LOG(LogTemp, Display, TEXT("Average rung: %.3f"), AverageRung);
    UE_LOG(LogTemp, Display, TEXT("Max rung: %.3f (Energy: %.4f)"), MaxRung, RungToEnergy(MaxRung));
    UE_LOG(LogTemp, Display, TEXT("Total acceleration: %d"), ParticlesAccelerated);
    UE_LOG(LogTemp, Display, TEXT("Total decayed: %d"), ParticlesDecayed);

    // Bin particles by rung
    TMap<int32, int32> RungBins;
    for (const auto& Particle : Particles)
    {
        if (Particle.bAlive)
        {
            int32 RungBin = FMath::FloorToInt(Particle.Rung);
            RungBins.FindOrAdd(RungBin)++;
        }
    }

    UE_LOG(LogTemp, Display, TEXT("Rung bins:"));
    for (const auto& Pair : RungBins)
    {
        UE_LOG(LogTemp, Display, TEXT("  Rung %d: %d particles"), Pair.Key, Pair.Value);
    }

    UE_LOG(LogTemp, Display, TEXT("=== END DISTRIBUTION ===\n"));
}

// ═══════════════════════════════════════════════════════════════════
// VISUALIZATION
// ═══════════════════════════════════════════════════════════════════

void APhiParticleAccelerator::DrawRungLattice(float MinRung, float MaxRungIn, float LifeTime) const
{
    FVector center = GetActorLocation();

    for (float rung = MinRung; rung <= MaxRungIn; rung += 1.0f)
    {
        float radius = 50.0f + rung * 20.0f;
        FColor color = PhiLerpColor(FColor::Blue, FColor::Red, (rung - MinRung) / (MaxRungIn - MinRung));

        DrawRung(rung, radius, color, LifeTime);
    }
}

void APhiParticleAccelerator::DrawInvolutionSymmetry(float CenterRung, float LifeTime) const
{
    FVector center = GetActorLocation();

    // Draw involution axis
    DrawDebugLine(
        GetWorld(),
        center + FVector(0, 0, -200),
        center + FVector(0, 0, 200),
        FColor::Magenta,
        false,
        LifeTime,
        0,
        2.0f
    );

    // Draw symmetric rung pairs
    for (float offset = 1.0f; offset <= 5.0f; offset += 1.0f)
    {
        float rung1 = CenterRung - offset;
        float rung2 = CenterRung + offset;

        float radius1 = 50.0f + rung1 * 20.0f;
        float radius2 = 50.0f + rung2 * 20.0f;

        DrawRung(rung1, radius1, FColor::Green, LifeTime);
        DrawRung(rung2, radius2, FColor::Green, LifeTime);
    }
}

void APhiParticleAccelerator::DrawRung(float Rung, float Radius, FColor Color, float LifeTime) const
{
    FVector center = GetActorLocation();
    const int32 NumPoints = 32;

    for (int32 i = 0; i < NumPoints; ++i)
    {
        float angle1 = (2.0f * PI / NumPoints) * i;
        float angle2 = (2.0f * PI / NumPoints) * (i + 1);

        FVector p1 = center + FVector(
            FMath::Cos(angle1) * Radius,
            FMath::Sin(angle1) * Radius,
            0.0f
        );

        FVector p2 = center + FVector(
            FMath::Cos(angle2) * Radius,
            FMath::Sin(angle2) * Radius,
            0.0f
        );

        DrawDebugLine(GetWorld(), p1, p2, Color, false, LifeTime, 0, 1.0f);
    }
}

void APhiParticleAccelerator::DrawParticles(float LifeTime) const
{
    for (const auto& Particle : Particles)
    {
        if (!Particle.bAlive)
        {
            continue;
        }

        DrawDebugSphere(
            GetWorld(),
            Particle.Position,
            2.0f + Particle.Energy * 0.5f,
            8,
            Particle.Color,
            false,
            LifeTime,
            0,
            1.0f
        );

        // Draw velocity vector
        DrawDebugLine(
            GetWorld(),
            Particle.Position,
            Particle.Position + Particle.Velocity * 0.1f,
            Particle.Color,
            false,
            LifeTime,
            0,
            0.5f
        );
    }
}
