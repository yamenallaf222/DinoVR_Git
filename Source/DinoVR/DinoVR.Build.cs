// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DinoVR : ModuleRules
{
	public DinoVR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" , "NavigationSystem" ,"GameplayTasks"});
	}
}
