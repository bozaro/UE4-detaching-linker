using UnrealBuildTool;
using System.Collections.Generic;

public class GameServerTarget : TargetRules
{
    public GameServerTarget(TargetInfo Target)
    {
        Type = TargetType.Server;
    }

    public override bool GetSupportedPlatforms(ref List<UnrealTargetPlatform> OutPlatforms)
    {
        return UnrealBuildTool.UnrealBuildTool.GetAllServerPlatforms(ref OutPlatforms, false);
    }

    public override void SetupBinaries(
        TargetInfo Target,
        ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
        ref List<string> OutExtraModuleNames
        )
    {
        OutExtraModuleNames.Add("W1");
    }
}
