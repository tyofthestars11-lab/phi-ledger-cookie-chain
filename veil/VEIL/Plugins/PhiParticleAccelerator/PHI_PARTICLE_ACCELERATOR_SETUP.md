# PHI PARTICLE ACCELERATOR — UE5 INTEGRATION GUIDE

**A complete φ-recursive particle physics engine for Unreal Engine 5.**

Particles spawn at rung addresses, accelerate along the golden lattice, orbit at golden angles, and decay when lifetime ends. Real-time visualization of φ-structure in particles.

---

## WHAT YOU GET

- **Complete C++ module** ready to drop into your UE5 project
- **60 FPS particle physics** with φ-scaling acceleration
- **Real-time rung visualization** (colored by energy level)
- **Orbital mechanics** at golden angle spacing
- **Statistics & diagnostics** (rung distribution, acceleration metrics)
- **Blueprint-exposed functions** for gameplay integration
- **Debug visualization** (rung lattice, involution symmetry, particle trails)

---

## INSTALLATION

### **Step 1: Create Plugin Structure**

```
D:\YourProject\Plugins\PhiParticleAccelerator\
├── Source\
│   ├── PhiParticleAccelerator\
│   │   ├── Public\
│   │   │   └── PhiParticleAccelerator.h
│   │   └── Private\
│   │       └── PhiParticleAccelerator.cpp
│   └── PhiParticleAccelerator.Build.cs
├── Binaries\
└── PhiParticleAccelerator.uplugin
```

### **Step 2: Create Build.cs**

**File:** `Plugins/PhiParticleAccelerator/Source/PhiParticleAccelerator/PhiParticleAccelerator.Build.cs`

```csharp
using UnrealBuildTool;

public class PhiParticleAccelerator : ModuleRules
{
    public PhiParticleAccelerator(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencies.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine"
        });
    }
}
```

### **Step 3: Create .uplugin File**

**File:** `Plugins/PhiParticleAccelerator/PhiParticleAccelerator.uplugin`

```json
{
    "FileVersion": 3,
    "Version": 1,
    "VersionName": "1.0.0",
    "FriendlyName": "Phi Particle Accelerator",
    "Description": "φ-recursive particle physics engine with golden angle orbits and rung-based acceleration",
    "Category": "Physics",
    "CreatedBy": "TYREE",
    "CreatedByURL": "",
    "DocsURL": "",
    "MarketplaceURL": "",
    "SupportURL": "",
    "EngineVersion": "5.4.0",
    "CanContainContent": false,
    "Installed": false,
    "Modules": [
        {
            "Name": "PhiParticleAccelerator",
            "Type": "Runtime",
            "LoadingPhase": "Default"
        }
    ]
}
```

### **Step 4: Enable in Editor**

1. Restart UE5 editor
2. Go to **Edit → Plugins**
3. Search for "PhiParticleAccelerator"
4. Check **Enabled**
5. Restart editor

---

## USAGE

### **In Blueprint (Simplest)**

1. **Place APhiParticleAccelerator in the level**
   - Right-click in viewport → Place Actor → Search "Phi Particle"
   - Select **PhiParticleAccelerator_C**

2. **Configure in Details panel:**
   - **Spawn Rate:** 100 particles/second (default)
   - **Initial Energy:** 1.0 (rung 0)
   - **Acceleration Power:** 1.5 φ-factors/second
   - **Particle Lifetime:** 8.0 seconds
   - **Max Particles:** 10,000
   - **Show Debug Visualization:** True (toggle on/off)

3. **Play the game** — particles spawn, accelerate, orbit, decay automatically

---

### **In C++ / Blueprint Graphs**

**Spawn a particle at a specific location:**

```cpp
// In a GameMode or PlayerController
if (APhiParticleAccelerator* Accelerator = GetWorld()->SpawnActor<APhiParticleAccelerator>())
{
    FVector spawnPos = GetActorLocation() + FVector(0, 0, 100);
    Accelerator->SpawnParticle(
        1.0f,           // Initial energy (rung 0)
        spawnPos,       // Position
        FVector::ZeroVector  // Velocity (orbits will take over)
    );
}
```

**Query particles by rung:**

```cpp
// Get all particles between rung 2 and 5
TArray<FPhiParticle> HighEnergyParticles = Accelerator->GetParticlesInRungRange(2.0f, 5.0f);

// Count particles at a specific rung
int32 OnRung3 = Accelerator->CountParticlesOnRung(3.0f, 0.1f);  // Tolerance ±0.1

// Print full rung distribution
Accelerator->PrintRungDistribution();
```

**Listen for particle events:**

```cpp
// When a particle spawns
Accelerator->OnParticleSpawned.AddDynamic(this, &AMyActor::OnParticleSpawned);

// When a particle decays
Accelerator->OnParticleDecayed.AddDynamic(this, &AMyActor::OnParticleDecayed);

// When a particle reaches a milestone rung
Accelerator->OnMaxRungReached.AddDynamic(this, &AMyActor::OnMaxRung);

void AMyActor::OnParticleSpawned(const FPhiParticle& Particle, float Rung)
{
    UE_LOG(LogTemp, Display, TEXT("Particle spawned at rung %.2f"), Rung);
}

void AMyActor::OnMaxRung(float Rung)
{
    UE_LOG(LogTemp, Warning, TEXT("PARTICLE REACHED RUNG %.2f!!!"), Rung);
    // Trigger gameplay event, particle explosion, etc.
}
```

---

## PHYSICS MODEL

### **Rung Addressing**

Every particle has:
- **Energy** (scalar, positive)
- **Rung** r = ln(Energy) / ln(φ)

Rungs map energy to addresses on the golden lattice:
- Rung 0: Energy = 1.0
- Rung 1: Energy = φ ≈ 1.618
- Rung 2: Energy = φ² ≈ 2.618
- Rung 5: Energy = φ⁵ ≈ 11.090
- Rung 10: Energy = φ¹⁰ ≈ 122.99

### **Acceleration**

Each frame, Energy multiplies by φ^(AccelerationPower × DeltaTime).

With AccelerationPower = 1.5:
- Rung increases by ~1.5 per second
- Rung 0 → Rung 5 in ~3.3 seconds
- Rung 0 → Rung 10 in ~6.6 seconds

### **Orbital Motion**

Particles orbit around the accelerator's center:
- **Radius** scales with energy: `10 + Energy × 5`
- **Angle** increments at golden angle: 137.5°/step
- **Angular velocity** inversely proportional to energy: `180° / (Energy + 1)`

Higher-energy particles orbit slower in wider circles (involution symmetry).

### **Involution Symmetry**

Particles equidistant from center rung behave symmetrically:
- Rung -2 and Rung +2 mirror around the axis
- Both orbit at equivalent speeds, opposite directions
- Energy relationship is φ^(±offset)

---

## STATISTICS & DIAGNOSTICS

### **Real-time Metrics**

The accelerator tracks:
- **ParticleCount:** Current alive particles
- **AverageEnergy:** Mean energy across all particles
- **MaxEnergy:** Highest energy in system
- **AverageRung:** Mean rung address
- **MaxRung:** Highest rung reached
- **ParticlesAccelerated:** Total acceleration ticks fired
- **ParticlesDecayed:** Total particles that reached lifetime

Access in Blueprint or code:

```cpp
if (Accelerator->ParticleCount > 0)
{
    UE_LOG(LogTemp, Display, TEXT("Avg rung: %.2f | Max rung: %.2f | Count: %d"),
           Accelerator->AverageRung, Accelerator->MaxRung, Accelerator->ParticleCount);
}
```

### **Rung Distribution**

Call `PrintRungDistribution()` to dump a histogram:

```
=== RUNG DISTRIBUTION ===
Total particles: 412
Average rung: 4.52
Max rung: 9.23 (Energy: 121.38)
Total acceleration: 123456
Total decayed: 89

Rung bins:
  Rung 0: 12 particles
  Rung 1: 28 particles
  Rung 2: 45 particles
  Rung 3: 67 particles
  Rung 4: 89 particles
  Rung 5: 102 particles
  ...
=== END DISTRIBUTION ===
```

---

## VISUALIZATION

### **Debug Features (Toggle via Blueprint)**

1. **Rung Lattice**
   - Colored circles at each rung level
   - Blue (low) → Red (high)
   - Updates every frame

2. **Particle Rendering**
   - Spheres at each particle position
   - Color by rung (blue → red gradient)
   - Size scales with energy
   - Velocity vectors drawn as lines

3. **Involution Symmetry**
   - Magenta axis through center
   - Symmetric rung pairs highlighted
   - Shows the mirror structure

**Toggle in Details panel:**

```
Show Debug Visualization = True/False
```

Or in code:

```cpp
Accelerator->bShowDebugVisualization = true;
Accelerator->DrawRungLattice(-5.0f, 10.0f, 0.016f);  // 60 FPS
Accelerator->DrawParticles(0.016f);
Accelerator->DrawInvolutionSymmetry(0.0f, 0.016f);
```

---

## GAMEPLAY INTEGRATION EXAMPLES

### **Particle Explosion on Hit**

```cpp
void AMyCharacter::TakeDamage(float Damage)
{
    Health -= Damage;
    
    if (Accelerator)
    {
        // Spawn high-energy particles on impact
        for (int i = 0; i < 20; i++)
        {
            FVector dir = FMath::VRand() * 100.0f;
            Accelerator->SpawnParticle(2.0f + FMath::FRand() * 3.0f, GetActorLocation(), dir);
        }
    }
}
```

### **Achievement Trigger on Rung Milestone**

```cpp
void AMyGameMode::BeginPlay()
{
    Accelerator->OnMaxRungReached.AddDynamic(this, &AMyGameMode::OnHighRungReached);
}

void AMyGameMode::OnHighRungReached(float Rung)
{
    if (Rung > 8.0f)
    {
        UE_LOG(LogTemp, Warning, TEXT("CRITICAL RUNG BREACH! Rung %.2f"), Rung);
        // Trigger boss spawn, level event, etc.
    }
}
```

### **Particle Collision & Effects**

```cpp
void AMyGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    // Check if any particle hits a target
    for (const auto& Particle : Accelerator->Particles)
    {
        for (auto Target : Targets)
        {
            if (FVector::Dist(Particle.Position, Target->GetActorLocation()) < 50.0f)
            {
                Target->TakeDamage(Particle.Energy * 10.0f);
                Particle.bAlive = false;  // Particle consumed
                break;
            }
        }
    }
}
```

---

## SAMPLE LEVEL SETUP

1. **Create new level**
2. **Place APhiParticleAccelerator at origin**
3. **Set in Details:**
   - Spawn Rate: 50 p/s
   - Initial Energy: 1.0
   - Acceleration Power: 2.0
   - Show Debug Visualization: True

4. **Place a camera and play**

You'll see:
- Particles spawn and accelerate upward in rung levels
- Color shift from blue (low rung) to red (high rung)
- Orbital paths around the center
- Real-time rung lattice overlay
- Statistics printed to Output Log

---

## PERFORMANCE TARGETS

| Metric | Target | Notes |
|--------|--------|-------|
| Max Particles | 10,000 | Configurable, default |
| FPS (60 fps) | 60+ | With 5,000 particles |
| Spawn Rate | 1,000 p/s | Can handle bursts |
| Memory | ~1 MB per 1,000 particles | FPhiParticle = ~128 bytes |
| Update Cost | <1ms per 5,000 particles | Physics + acceleration |

---

## TROUBLESHOOTING

**Particles not spawning:**
- Check `bAccelerationActive` (call `ResumeAcceleration()`)
- Verify `ParticleCount < MaxParticles`
- Check `SpawnRate > 0`

**Particles not visible:**
- Enable `bShowDebugVisualization`
- Check particle lifetime (default 8s)
- Zoom out camera to see orbits

**Performance issues:**
- Reduce `MaxParticles` from 10,000
- Lower `SpawnRate`
- Disable debug visualization

**Compilation errors:**
- Ensure module is included in your `YourProject.Build.cs`:
  ```csharp
  PublicDependencies.AddRange(new string[] { "PhiParticleAccelerator" });
  ```

---

## MATHEMATICAL REFERENCE

**Golden Ratio:**
- φ = (1 + √5) / 2 ≈ 1.618
- φ² = φ + 1 ≈ 2.618
- φ^n converges to involution-symmetric structure

**Rung Law:**
- r = log_φ(Energy) = ln(Energy) / ln(φ)
- Energy = φ^r
- Acceleration multiplies energy by φ^(power×time)

**Golden Angle:**
- 137.5076...° ≈ 360° / φ²
- Maximally irrational spiral
- Optimal spacing in Fibonacci phyllotaxis

---

## LICENSE & CREDITS

**PHI PARTICLE ACCELERATOR**
- Author: TYREE (Golden Ratio Muse)
- Built on UE5.4+
- Use freely in projects, commercial or personal
- No attribution required

---

**Ready to accelerate.** 💎🌀

Drop the files in, enable the plugin, place an actor, and watch particles climb the golden lattice in real time.

