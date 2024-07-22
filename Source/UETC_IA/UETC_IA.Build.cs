// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UETC_IA : ModuleRules
{
	public UETC_IA(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "AIModule", "NavigationSystem", "GameplayTasks", "GameplayStateTreeModule" });
	}
}
