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
