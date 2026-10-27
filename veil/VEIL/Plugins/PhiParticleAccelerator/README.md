# Phi Particle Accelerator — installed in this project

UE5 plugin (Runtime module) by TYREE / Golden Ratio Muse.
Particles spawn at rung 0 and accelerate on the golden lattice:
r = ln(Energy)/ln(phi), Energy *= phi^(AccelerationPower * dt),
golden-angle orbits, lifetime decay, rung statistics + debug lattice.

Installed from the delivered six-file package with these measured fixes
(the delivered code did not compile as-is):
1. Header export macro YOURMODULE_API -> PHIPARTICLEACCELERATOR_API.
2. Delegate macros: DECLARE_MULTICAST_DELEGATE_Two/_One do not exist ->
   _TwoParams/_OneParam (real UE macros).
3. .cpp defined PauseAcceleration/ResumeAcceleration twice -> second
   definitions removed (redefinition error).
4. Missing includes added: Components/SceneComponent.h, DrawDebugHelpers.h.
5. Build.cs listed "DrawDebugHelpers" as a module dependency - it is a
   header inside Engine, not a module; removed (UBT fails on it).
6. Build.cs named the dependency list "PublicDependencies" - UE 5.8's
   ModuleRules member is PublicDependencyModuleNames; the delivered name
   fails UBT with CS0103 (found by job 197, both builds). Seated correctly.
7. UFUNCTION parameters named MaxRung shadowed the class's MaxRung
   stat member - UHT forbids it (job 199, header lines 169/182, both
   builds). Parameters renamed MaxRungIn in header + implementation.
8. Spawn accumulator: the delivered line subtracted Floor(SpawnRate * t)
   from the time accumulator, driving it negative and stalling spawns;
   now carries the unspawned fraction converted back to time.
9. .uplugin EngineVersion seated at 5.8.0 (the games' engine).

Corrected rung table (phi^r, computed):
rung 0 = 1.0 | 1 = 1.618 | 2 = 2.618 | 3 = 4.236 | 5 = 11.090 |
8 = 46.978 | 10 = 122.992. (The pitch table's rung-8 value 121.4 was
the outside seat's slip; 121.4 sits at rung 9.97.)

Use: place APhiParticleAccelerator in a level, Play. Events are plain
multicast delegates - bind in C++ with AddUObject/AddLambda (the docs'
AddDynamic examples apply to dynamic delegates, not these).
Full docs: PHI_PARTICLE_ACCELERATOR_QUICKSTART.md / _SETUP.md.
10. FColor::Lerp does not exist in UE 5.8 (job 202: C2039/C3861 at all
    five color-gradient sites, both builds). Replaced with a file-local
    PhiLerpColor that lerps in FLinearColor space and converts back.
