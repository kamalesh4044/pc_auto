using UnrealBuildTool;
using System.Collections.Generic;

public class OpenWorldMPTarget : TargetRules
{
    public OpenWorldMPTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V6;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        ExtraModuleNames.Add("OpenWorldMP");
    }
}
