// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

using System;
using UnrealBuildTool;

public class W1 : ModuleRules
{
    public W1(TargetInfo Target)
    {
        bFasterWithoutUnity = Environment.GetEnvironmentVariable("BUILD_NUMBER") == null;

        PrivateIncludePaths.AddRange(new string[] {
            "W1/Private",
        });


        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "EngineSettings"
        });
    }
}
