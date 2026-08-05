// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BattleTest : ModuleRules
{
	public BattleTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
