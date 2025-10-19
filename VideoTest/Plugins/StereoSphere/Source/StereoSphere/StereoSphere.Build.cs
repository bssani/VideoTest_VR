using UnrealBuildTool;

public class StereoSphere : ModuleRules
{
    public StereoSphere(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "Json",
                "MovieRenderPipelineSettings",
                "ColorManagement",
                "ImageWrapper"
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[] {
                "MovieRenderPipelineCore",
                "MovieRenderPipelineRenderPasses",
                "RenderCore",
                "RHI",
                "OpenColorIO",
                "ImageWriteQueue",
                "ActorLayerUtilities"
            }
        );
    }
}