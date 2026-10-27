// VEIL: THE LAST SIGNAL - game target rules.
using UnrealBuildTool;
using System.Collections.Generic;

public class VEILTarget : TargetRules
{
	public VEILTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V7;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_8;
		ExtraModuleNames.Add("VEIL");
	}
}
