// OMNI: THE LAST SIGNAL - game target rules.
using UnrealBuildTool;
using System.Collections.Generic;

public class OMNITarget : TargetRules
{
	public OMNITarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V7;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_8;
		ExtraModuleNames.Add("OMNI");
	}
}
