// VEIL: THE LAST SIGNAL - editor target rules.
using UnrealBuildTool;
using System.Collections.Generic;

public class VEILEditorTarget : TargetRules
{
	public VEILEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V7;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_8;
		ExtraModuleNames.Add("VEIL");
	}
}
