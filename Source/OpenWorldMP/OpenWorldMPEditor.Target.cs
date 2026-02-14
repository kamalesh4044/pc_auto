using UnrealBuildTool;
using System.Collections.Generic;

public class OpenWorldMPEditorTarget : TargetRules
{
    public OpenWorldMPEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
        ExtraModuleNames.Add("OpenWorldMP");
    }
}
