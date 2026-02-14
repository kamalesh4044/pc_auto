using UnrealBuildTool;
using System.Collections.Generic;

public class OpenWorldMPEditorTarget : TargetRules
{
    public OpenWorldMPEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V6;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        ExtraModuleNames.Add("OpenWorldMP");
    }
}
