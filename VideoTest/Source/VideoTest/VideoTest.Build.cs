// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class VideoTest : ModuleRules
{
	public VideoTest(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core", "CoreUObject", "Engine", "InputCore",
            "HeadMountedDisplay", "OpenXRHMD",
            "MediaAssets", "MediaUtils", "Media", "WmfMedia", // 미디어
            "EnhancedInput" // 향상된 입력 시스템
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "Slate", "SlateCore"
        });

    }
}
