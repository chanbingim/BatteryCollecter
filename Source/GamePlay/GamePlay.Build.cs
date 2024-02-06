// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GamePlay : ModuleRules
{
	public GamePlay(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                
				//"And so on..."
			}
        );

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine",  "OnlineSubsystem", "OnlineSubsystemUtils", "UMG", "Slate", "SlateCore", "a", "Widget" });

        PrivateDependencyModuleNames.AddRange(new string[] {});
    }
}
