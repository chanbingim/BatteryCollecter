// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class a : ModuleRules
{
	public a(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                
				//"And so on..."
			}
        );

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "UMG", "Slate", "SlateCore", "Widget", "GamePlay","OnlineSubsystemSteam", "OnlineSubsystem"});
	}
}
