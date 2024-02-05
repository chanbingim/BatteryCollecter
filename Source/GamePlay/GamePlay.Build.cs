// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GamePlay : ModuleRules
{
	public GamePlay(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine"});

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
