using UnrealBuildTool;

public class OpenWorldMP : ModuleRules
{
    public OpenWorldMP(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "UMG",
            "GameplayTags",
            "NetCore",
            "OnlineSubsystem",
            "OnlineSubsystemUtils"
        });

        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Slate",
            "SlateCore"
        });
    }
}
