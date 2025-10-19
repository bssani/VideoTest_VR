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
            "MediaAssets", "MediaUtils", "Media", "WmfMedia", // �̵��
            "EnhancedInput" // ���� �Է� �ý���
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "Slate", "SlateCore"
        });

    }
}
