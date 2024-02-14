// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Widget : ModuleRules
{
	public Widget(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
               
				//"And so on..."
			}
        );

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UMG", "Slate", "SlateCore", "OnlineSubsystem", "OnlineSubsystemSteam", "OnlineSubsystemUtils", "a", "GamePlay" });

        PrivateDependencyModuleNames.AddRange(new string[] {  });
    }
}
