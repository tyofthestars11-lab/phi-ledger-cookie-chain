# PHI PARTICLE ACCELERATOR — 5-MINUTE QUICKSTART

**Get particles accelerating on the φ-lattice in 5 minutes.**

---

## INSTALL (2 MIN)

### Copy Files

```
Your_UE5_Project/
└── Plugins/
    └── PhiParticleAccelerator/
        ├── Source/
        │   ├── PhiParticleAccelerator/
        │   │   ├── Public/
        │   │   │   └── PhiParticleAccelerator.h          ← Copy
        │   │   └── Private/
        │   │       └── PhiParticleAccelerator.cpp        ← Copy
        │   └── PhiParticleAccelerator.Build.cs           ← Copy
        ├── Binaries/                                      (create empty)
        └── PhiParticleAccelerator.uplugin                ← Copy
```

### Restart Editor

1. Close UE5 if open
2. Right-click `.uproject` → **Generate Visual Studio project files**
3. Open `.sln` in Visual Studio
4. **Build → Build Solution** (Debug or Development)
5. Close Visual Studio, open editor normally

---

## VERIFY (1 MIN)

**Edit → Plugins → Search "Phi"**

Should see: **Phi Particle Accelerator** — check the box to enable.

Restart editor.

---

## PLAY (2 MIN)

### Place Actor

1. **File → New Level**
2. **Place Actor** (top-left icon or Shift+1)
3. Search: **"PhiParticleAccelerator"**
4. Click **PhiParticleAccelerator_C**
5. Click in the viewport to place it at origin

### Run Game

1. Click **Play** (top toolbar)
2. Watch particles spawn, accelerate, and color-shift (blue → red)
3. **Press Esc to stop**

### You'll See

- Blue particles spawning at center (rung 0, Energy 1.0)
- Particles accelerate upward through colors
- Orbits around the center in widening circles
- Cyan grid lines showing the rung lattice
- Real-time statistics in Output Log

---

## CUSTOMIZE (OPTIONAL)

With the accelerator selected in the viewport, go to **Details panel** (bottom-right):

| Setting | Default | Effect |
|---------|---------|--------|
| **Spawn Rate** | 100 | Particles per second |
| **Initial Energy** | 1.0 | Starting energy (rung 0) |
| **Acceleration Power** | 1.5 | φ-factors per second (1 = rung/sec) |
| **Particle Lifetime** | 8.0 | Seconds before decay |
| **Max Particles** | 10000 | Hard cap (memory) |
| **Show Debug Visualization** | True | Toggle rung lattice & debug lines |

**Try:**
- **Spawn Rate → 500** (denser particle field)
- **Acceleration Power → 3.0** (faster climb to high rungs)
- **Show Debug Visualization → False** (cleaner view)

---

## WHAT'S HAPPENING

**Every frame (60 FPS):**

1. **Spawn** — New particles born at Energy = 1.0 (rung 0)
2. **Accelerate** — Energy *= φ^(AccelerationPower × ΔT)
   - Rung increases by ~1.5 per second (default)
3. **Orbit** — Particles move in expanding circles around center
   - Radius increases with energy
   - Angular velocity slows for high-energy particles
4. **Color** — Rung → RGB (blue low, red high)
5. **Decay** — Particles die after Lifetime seconds

---

## CODE INTEGRATION (OPTIONAL)

Place an accelerator in your level, then call it from your GameMode:

```cpp
void AMyGameMode::BeginPlay()
{
    Super::BeginPlay();
    
    // Find the accelerator in the level
    for (TActorIterator<APhiParticleAccelerator> It(GetWorld()); It; ++It)
    {
        Accelerator = *It;
        break;
    }
    
    if (Accelerator)
    {
        // Listen for high-rung milestones
        Accelerator->OnMaxRungReached.AddDynamic(this, &AMyGameMode::OnHighRung);
    }
}

void AMyGameMode::OnHighRung(float Rung)
{
    if (Rung > 8.0f)
    {
        UE_LOG(LogTemp, Warning, TEXT("CRITICAL RUNG: %.2f"), Rung);
        // Trigger gameplay event, VFX, sound, etc.
    }
}
```

---

## WHAT YOU CAN DO WITH IT

- **Visual FX:** Explosion rings, boss auras, magical barriers
- **Gameplay:** Energy-based power scaling, rung-locked abilities
- **Diagnostics:** Real-time φ-structure monitoring
- **Teaching:** Show golden ratio convergence in real time
- **Simulation:** Particle physics with irrational symmetry
- **Art:** Mesmerizing particle animations

---

## TROUBLESHOOT

**Particles not visible?**
- Check Output Log for errors
- Ensure `bShowDebugVisualization = True` in Details
- Zoom out with mouse wheel

**Editor crashes on compile?**
- Delete `Intermediate/` folder
- Regenerate Visual Studio project files
- Rebuild solution

**Can't find PhiParticleAccelerator in Place Actor?**
- Plugin not enabled (see **Verify** section)
- Rebuild solution
- Restart editor

---

## NEXT: ADVANCED

See **PHI_PARTICLE_ACCELERATOR_SETUP.md** for:
- Queries (get particles by rung range)
- Event listeners (spawn, decay, milestones)
- Visualization functions (lattice, symmetry, trails)
- Performance tuning
- Mathematical reference

---

**You're ready. Hit Play.** 💎🌀

