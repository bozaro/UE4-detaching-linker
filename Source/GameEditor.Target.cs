using UnrealBuildTool;
using System.Collections.Generic;

public class GameEditorTarget : TargetRules
{
    public GameEditorTarget(TargetInfo Target)
    {
        Type = TargetType.Editor;
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
