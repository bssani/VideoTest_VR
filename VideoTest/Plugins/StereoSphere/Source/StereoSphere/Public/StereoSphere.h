#pragma once

#include "MoviePipelineImagePassBase.h"
#include "OpenColorIODisplayExtension.h"
#include "MoviePipelineImageSequenceOutput.h"
#include "ActorLayerUtilities.h"
#include "StereoSphere.generated.h"

#define LOCTEXT_NAMESPACE "StereoSphere"

class UTextureRenderTarget2D;
struct FImageOverlappedAccumulator;
class FSceneViewFamily;
class FSceneView;
struct FAccumulatorPool;


USTRUCT(BlueprintType)
struct FPanoramicPostProcessPass
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool bEnabled = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	TSoftObjectPtr<UMaterialInterface> Material;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Use High Precision (32-bit) Output")
	bool bHighPrecisionOutput = false;
};



UENUM()
enum class ERenderPass :uint8
{
	Lit = 0,
	Unlit,
	DetailLighting,
	LightingOnly,
	ReflectionsOnly,
	PathTracer
};


UENUM(BlueprintType)
enum class ESurroundingType : uint8
{

	Hemisphere UMETA(DisplayName = "180 Degree"),

	OmniDirectional,
};

UENUM(BlueprintType)
enum class ETextureSampingMethod : uint8
{

	Billinear,

	Bicubic,
};

UENUM(BlueprintType)
enum class EAlignType :uint8
{
	Side_by_Side,
	Top_Bottom,
};

struct FCombineSettings
{
	ESurroundingType SurroundingType;
	EAlignType AlignType;
	ETextureSampingMethod SampingMethod;
	FString RenderPassName;
	bool bStereo;
	bool bSavePresetShot;
};

struct FPanoPane : public UMoviePipelineImagePassBase::IViewCalcPayload
{

	FVector OriginalCameraLocation;

	FVector PrevOriginalCameraLocation;

	FRotator OriginalCameraRotation;

	FRotator PrevOriginalCameraRotation;

	FRotator RelativeRotation;
	float NearClippingPlane;


	float EyeSeparation;
	float EyeConvergenceDistance;


	float HorizontalFieldOfView;
	float VerticalFieldOfView;

	FIntPoint Resolution;


	FVector CameraLocation;
	FVector PrevCameraLocation;
	FRotator CameraRotation;
	FRotator PrevCameraRotation;


	int32 NumHorizontalSteps;
	int32 NumVerticalSteps;


	int32 HorizontalStepIndex;

	int32 VerticalStepIndex;

	int32 EyeIndex;
	int32 SceneViewIndex;
	float OverlapPercentage;

	int32 GetAbsoluteIndex() const
	{
		const int32 EyeOffset = EyeIndex == -1 ? 0 : EyeIndex;
		if (EyeOffset == 0)
		{
			return (VerticalStepIndex * NumHorizontalSteps) + HorizontalStepIndex;
		}
		return (NumVerticalSteps + VerticalStepIndex) * NumHorizontalSteps + HorizontalStepIndex;
	}
};


struct FPanoramicImagePixelDataPayload : public FImagePixelDataPayload
{
	virtual TSharedRef<FImagePixelDataPayload> Copy() const override
	{
		return MakeShared<FPanoramicImagePixelDataPayload>(*this);
	}

	virtual FIntPoint GetAccumulatorSize() const override
	{
		return Pane.Resolution;
	}

	virtual FIntPoint GetOverlapPaddedSize() const override
	{
		const FIntPoint Result = Pane.Resolution;
		return Result;
	}

	virtual bool GetOverlapPaddedSizeIsValid(const FIntPoint InRawSize) const override
	{

		const FIntPoint Result = Pane.Resolution;
		return InRawSize == Result;
	}

	virtual void GetWeightFunctionParams(MoviePipeline::FTileWeight1D& WeightFunctionX, MoviePipeline::FTileWeight1D& WeightFunctionY) const override
	{
		WeightFunctionX.InitHelper(0, Pane.Resolution.X, 0);
		WeightFunctionY.InitHelper(0, Pane.Resolution.Y, 0);
	}

	FPanoPane Pane;
};






UCLASS(BlueprintType)
class UStereoSphere : public UMoviePipelineImagePassBase
{
	GENERATED_BODY()

public:
	UStereoSphere(const FString& InRenderPassName);
	UStereoSphere() :UStereoSphere(TEXT("StereoSphere")) {};


	virtual void PostLoad() override;

	~UStereoSphere();
public:

	virtual void SetupImpl(const MoviePipeline::FMoviePipelineRenderPassInitSettings& InPassInitSettings) override;
	virtual void RenderSample_GameThreadImpl(const FMoviePipelineRenderPassMetrics& InSampleState) override;
	virtual void TeardownImpl() override;
#if WITH_EDITOR
	virtual FText GetDisplayText() const override
	{
		{ return NSLOCTEXT("StereoSphere", "StereoSphereSetting_Lit", "StereoSphereSetting"); }
	}
	virtual FText GetFooterText(UMoviePipelineExecutorJob* InJob) const override;
#endif
	virtual void GetViewShowFlags(FEngineShowFlags& OutShowFlag, EViewModeIndex& OutViewModeIndex) const;
	virtual void MoviePipelineRenderShowFlagOverride(FEngineShowFlags& OutShowFlag) override;
	virtual void GatherOutputPassesImpl(TArray<FMoviePipelinePassIdentifier>& ExpectedRenderPasses) override;
	virtual bool IsAntiAliasingSupported() const { return true; }
	virtual int32 GetOutputFileSortingOrder() const override { return 0; }
	virtual bool IsAlphaInTonemapperRequiredImpl() const override { return bAccumulatorIncludesAlpha; }
	virtual FSceneViewStateInterface* GetSceneViewStateInterface(IViewCalcPayload* OptPayload) override;
	virtual void AddViewExtensions(FSceneViewFamilyContext& InContext, FMoviePipelineRenderPassMetrics& InOutSampleState) override;
	virtual bool IsAutoExposureAllowed(const FMoviePipelineRenderPassMetrics& InSampleState) const override { return false; }
	virtual FSceneView* GetSceneViewForSampleState(FSceneViewFamily* ViewFamily, FMoviePipelineRenderPassMetrics& InOutSampleState, IViewCalcPayload* OptPayload = nullptr) override;
	virtual TWeakObjectPtr<UTextureRenderTarget2D> GetOrCreateViewRenderTarget(const FIntPoint& InSize, IViewCalcPayload* OptPayload = nullptr) override;
	virtual TSharedPtr<FMoviePipelineSurfaceQueue, ESPMode::ThreadSafe> GetOrCreateSurfaceQueue(const FIntPoint& InSize, IViewCalcPayload* OptPayload = nullptr) override;
	virtual void ValidateStateImpl() override;
	static void AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector);

	FString GetCameraName() const;

	bool IsUsingDataLayers() const;

	int32 GetNumStencilLayers() const;

	TArray<FString> GetStencilLayerNames() const;

	bool IsActorInAnyStencilLayer(AActor* InActor) const;

	bool IsActorInLayer(AActor* InActor, int32 InLayerIndex) const;

	FSoftObjectPath GetValidDataLayerByIndex(const int32 InIndex) const;

	TFunction<void(TUniquePtr<FImagePixelData>&&)> MakeForwardingEndPoint(const FMoviePipelinePassIdentifier InPassIdentifier, FPanoPane& InPane, const FMoviePipelineRenderPassMetrics& InSampleState);

	void PathTracerValidationImpl();
	bool CheckIfPathTracerIsSupported() const;
	virtual void PostRendererSubmission(const FMoviePipelineRenderPassMetrics& InSampleState, const FMoviePipelinePassIdentifier InPassIdentifier, const int32 InSortingOrder, FPanoPane& InPane, FCanvas& InCanvas);
	void GetFieldOfView(float& OutHorizontal, float& OutVertical) const;
	FIntPoint GetPaneResolution(const FIntPoint& InSize) const;
	FIntPoint GetPayloadPaneResolution(const FIntPoint& InSize, IViewCalcPayload* OptPayload) const;

	void StereoValidationImpl();

	virtual void UpdateTelemetry(FMoviePipelineShotRenderTelemetry* InTelemetry) const override;
private:

	FString GetNameForPostProcessMaterial(const UMaterialInterface* InMaterial);
public:

	const FString RenderPassName;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StereoSphere Settings", DisplayName = "Surrounding Type")
	ESurroundingType SurroundingType = ESurroundingType::OmniDirectional;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StereoSphere Settings")
	ETextureSampingMethod SampingMethod = ETextureSampingMethod::Billinear;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Enable Depth Of Field", Category = "StereoSphere Settings", meta = (UIMin = "50", ClampMin = "50", ClampMax = "240", Delta = "10"))
	bool bEnableDepthOfField = true;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StereoSphere Settings", meta = (UIMin = "50", ClampMin = "50", ClampMax = "240", Delta = "10"))
	int32 QualityImprovementPercentage = 100;




	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StereoSphere Settings", meta = (UIMin = "3", ClampMin = "3", ClampMax = "100"))
	int32 NumHorizontalSteps = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StereoSphereSettings", meta = (UIMin = "3", ClampMin = "3", ClampMax = "12"))
	int32 NumVerticalSteps = 3;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StereoSphere Settings", meta = (UIMin = "20", ClampMin = "20", ClampMax = "100", Delta = "5"))
	int32 OverlapPercentage = 50;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "StereoSphere Settings", meta = (UIMin = "-1", ClampMin = "-1", ClampMax = "0", Delta = "0.1"))
	float TextureSharpnessBias = 0.0f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "StereoSphere Settings", meta = (UIMin = "0", ClampMin = "0", ClampMax = "1", Delta = "0.1"))
	float OverscanPercentage = 0.0f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "StereoSphere Settings")
	float HorzFieldOfView = 0.f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "StereoSphere Settings")
	float VertFieldOfView = 0.f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "StereoSphere Settings")
	bool bAllocateHistoryPerPane = true;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereo Settings", DisplayName = "Enable Stereo")
	bool bStereo = false;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereo Settings", meta = (HideEditConditionToggle, EditCondition = "bStereo"))
	EAlignType AlignType = EAlignType::Top_Bottom;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereo Settings", meta = (HideEditConditionToggle, EditCondition = "bStereo"))
	bool bFlipEyes = false;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Stereo Settings", meta = (HideEditConditionToggle, EditCondition = "bStereo"))
	float EyeSeparation = 6.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Stereo Settings", meta = (HideEditConditionToggle, EditCondition = "bStereo"))
	float EyeConvergenceDistance = 195.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Alpha Settings")
	bool bAccumulatorIncludesAlpha = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Post Processing")
	bool bDisableMultisampleEffects = false;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PostProcess Render Materials Data")
	TArray<FPanoramicPostProcessPass> AdditionalPostProcessMaterials;


	UPROPERTY(Transient, DuplicateTransient)
	TSet<TObjectPtr<UMaterialInterface>> ActiveHighPrecisionPostProcessMaterials;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stencil Clip Layers")
	bool bRenderMainPass;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stencil Clip Layers")
	bool bAddDefaultLayer = false;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stencil Clip Layers")
	TArray<FActorLayer> ActorLayers;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowedClasses = "/Script/Engine.DataLayerAsset"), Category = "Stencil Clip Layers")
	TArray<FSoftObjectPath> DataLayers;
protected:

	UPROPERTY(Transient, DuplicateTransient)
	TArray<TObjectPtr<UMaterialInterface>> ActivePostProcessMaterials;

	UPROPERTY(Transient, DuplicateTransient)
	TObjectPtr<UMaterialInterface> StencilLayerMaterial;

	struct FPaneViewStateData
	{

		TArray<FSceneViewStateReference> SceneViewStates;
	};

	TArray<FPaneViewStateData> PaneViewStateData;


	TOptional<int32> PreviousCustomDepthValue;


	TSharedPtr<FAccumulatorPool, ESPMode::ThreadSafe> AccumulatorPool;




	TSharedPtr<FOpenColorIODisplayExtension, ESPMode::ThreadSafe> OCIOSceneViewExtension;


	TSharedPtr<MoviePipeline::IMoviePipelineOutputMerger> PanoramicOutputBlender;
	bool bHasWarnedSettings = false;

	FCombineSettings CombineSettings;

public:

	static FString StencilLayerMaterialAsset;
	static FString DefaultDepthAsset;
	static FString DefaultMotionVectorsAsset;

private:

	TArray<FString> UniqueStencilLayerNames;
	UPROPERTY()
	TMap<UMoviePipelineImageSequenceOutputBase*, bool> PrevSequenceOutputBases;

	int32 FinalHorizontalSteps;
	int32 FinalVerticalSteps;
};


UCLASS(BlueprintType)
class UStereoSphere_PathTracer :public UStereoSphere
{
	GENERATED_BODY()
public:
	UStereoSphere_PathTracer() :UStereoSphere(TEXT("StereoSphere_PathTracer")) {}
#if WITH_EDITOR
	virtual FText GetDisplayText() const override;

#endif
	virtual bool IsAntiAliasingSupported() const { return false; }
	virtual void GetViewShowFlags(FEngineShowFlags& OutShowFlag, EViewModeIndex& OutViewModeIndex) const override
	{
		OutShowFlag = FEngineShowFlags(EShowFlagInitMode::ESFIM_Game);
		OutShowFlag.SetPathTracing(true);
		OutShowFlag.SetMotionBlur(!bReferenceMotionBlur);
		OutViewModeIndex = EViewModeIndex::VMI_PathTracing;
	}
	virtual void ValidateStateImpl() override;
	virtual void SetupImpl(const MoviePipeline::FMoviePipelineRenderPassInitSettings& InPassInitSettings) override;
	virtual int32 GetOutputFileSortingOrder() const override { return 1; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reference Motion Blur")
	bool bReferenceMotionBlur = false;
};

UCLASS(BlueprintType)
class UStereoSphere_Unlit :public UStereoSphere
{
	GENERATED_BODY()
public:
	UStereoSphere_Unlit() :UStereoSphere(TEXT("StereoSphere_Unlit")) {};
#if WITH_EDITOR
	virtual FText GetDisplayText() const override;
#endif

	virtual void GetViewShowFlags(FEngineShowFlags& OutShowFlag, EViewModeIndex& OutViewModeIndex) const override
	{
		OutShowFlag = FEngineShowFlags(EShowFlagInitMode::ESFIM_Game);
		OutViewModeIndex = EViewModeIndex::VMI_Unlit;
	}
	virtual int32 GetOutputFileSortingOrder() const override { return 2; }
};

UCLASS(BlueprintType)
class UStereoSphere_DetailLighting :public UStereoSphere
{
	GENERATED_BODY()
public:
	UStereoSphere_DetailLighting() :UStereoSphere(TEXT("StereoSphere_DetailLighting")) {}
#if WITH_EDITOR
	virtual FText GetDisplayText() const override;
#endif
	virtual int32 GetOutputFileSortingOrder() const override { return 3; }
	virtual void GetViewShowFlags(FEngineShowFlags& OutShowFlag, EViewModeIndex& OutViewModeIndex) const override
	{
		OutShowFlag = FEngineShowFlags(EShowFlagInitMode::ESFIM_Game);
		OutShowFlag.SetLightingOnlyOverride(true);
		OutViewModeIndex = EViewModeIndex::VMI_Lit_DetailLighting;
	}
};

UCLASS(BlueprintType)
class UStereoSphere_LightingOnly :public UStereoSphere
{
	GENERATED_BODY()
public:
	UStereoSphere_LightingOnly() :UStereoSphere(TEXT("StereoSphere_LightingOnly")) {}

#if WITH_EDITOR
	virtual FText GetDisplayText() const override;
#endif
	virtual int32 GetOutputFileSortingOrder() const override { return 4; }
	virtual void GetViewShowFlags(FEngineShowFlags& OutShowFlag, EViewModeIndex& OutViewModeIndex) const override
	{
		OutShowFlag = FEngineShowFlags(EShowFlagInitMode::ESFIM_Game);
		OutShowFlag.SetLightingOnlyOverride(true);
		OutViewModeIndex = EViewModeIndex::VMI_LightingOnly;
	}
};



UCLASS(BlueprintType)
class UStereoSphere_ReflectionsOnly :public UStereoSphere
{
	GENERATED_BODY()
public:
	UStereoSphere_ReflectionsOnly() :UStereoSphere(TEXT("StereoSphere_ReflectionsOnly")) {}

#if WITH_EDITOR
	virtual FText GetDisplayText() const override;
#endif

	virtual void GetViewShowFlags(FEngineShowFlags& OutShowFlag, EViewModeIndex& OutViewModeIndex) const override
	{
		OutShowFlag = FEngineShowFlags(EShowFlagInitMode::ESFIM_Game);
		OutShowFlag.SetReflectionOverride(true);
		OutViewModeIndex = EViewModeIndex::VMI_ReflectionOverride;
	}
	virtual int32 GetOutputFileSortingOrder() const override { return 5; }
};

#undef LOCTEXT_NAMESPACE