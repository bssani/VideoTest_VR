

#include "StereoSphere.h"
#include "MoviePipelineOutputBase.h"
#include "Engine/TextureRenderTarget2D.h"
#include "SceneView.h"
#include "MovieRenderPipelineDataTypes.h"
#include "GameFramework/PlayerController.h"
#include "EngineModule.h"
#include "Engine/World.h"
#include "Engine/TextureRenderTarget.h"
#include "MoviePipeline.h"
#include "MovieRenderOverlappedImage.h"
#include "MovieRenderPipelineCoreModule.h"
#include "ImagePixelData.h"
#include "Containers/Array.h"
#include "FinalPostProcessSettings.h"
#include "MoviePipelineOutputSetting.h"
#include "Math/Quat.h"
#include "StereoBlend.h"
#include "MoviePipelineAntiAliasingSetting.h"
#include "MoviePipelineOutputBuilder.h"
#include "SceneManagement.h"
#include "TextureResource.h"
#include "MoviePipelineQueue.h"
#include "MoviePipelineRenderPass.h"
#include "EngineUtils.h"
#include "ImageUtils.h"
#include "MoviePipelineHighResSetting.h"
#include "MoviePipelineImageSequenceOutput.h"
#include "ActorLayerUtilities.h"
#include "WorldPartition/DataLayer/DataLayerAsset.h"
#include "MoviePipelineDeferredPasses.h"
#include "Interfaces/Interface_PostProcessVolume.h"
#include "Components/PrimitiveComponent.h"
#include "Materials/Material.h"
#include "Async/Async.h"



#include UE_INLINE_GENERATED_CPP_BY_NAME(StereoSphere)



FString UStereoSphere::StencilLayerMaterialAsset = TEXT("/StereoSphere/Materials/MoviePipeline_StencilCutout.MoviePipeline_StencilCutout");
FString UStereoSphere::DefaultDepthAsset = TEXT("/StereoSphere/Materials/MovieRenderQueue_WorldDepth.MovieRenderQueue_WorldDepth");
FString UStereoSphere::DefaultMotionVectorsAsset = TEXT("/StereoSphere/Materials/MovieRenderQueue_MotionVectors.MovieRenderQueue_MotionVectors");


namespace MoviePipeline
{
	namespace Panoramic
	{

		static TArray<float> HorizontalDistributeValuesInInterval(float InMin, float InMax, int32 InNumDivisions)
		{
			TArray<float> Results;
			float Delta = (InMax - InMin) / static_cast<float>(FMath::Max(InNumDivisions, 1));
			float CurrentValue = InMax - Delta;

			for (int32 Index = 0; Index < InNumDivisions; Index++)
			{
				Results.Add(CurrentValue);

				CurrentValue -= Delta;
			}
			return Results;
		};

		static TArray<float> DistributeValuesInInterval(float InMin, float InMax, int InNumDivisions)
		{
			TArray<float> Results;
			float Delta = (InMax - InMin) / static_cast<float>(FMath::Max(InNumDivisions, 1));
			if (InNumDivisions % 2 != 0)
			{
				for (int i = InNumDivisions; i >= 1; --i)
				{
					float Value = Delta * int(i / 2);
					if (i % 2 == 0)
					{
						Results.Add(Value);
					}
					else
					{
						Results.Add(-Value);
					}
				}
			}
			else
			{
				for (int i = InNumDivisions; i >= 1; --i)
				{
					float Value = Delta / 2 + Delta * int((i - 1) / 2);
					if (i % 2 == 0)
					{
						Results.Add(Value);
					}
					else
					{
						Results.Add(-Value);
					}
				}
			}
			return Results;
		}


		void GetCameraOrientationForStereo(FVector& OutLocation, FRotator& OutRotation, FRotator& RelativeRotation,
			const FPanoPane& InPane, const bool bInPrevPosition, int32 InStereoIndex, ESurroundingType SurroundingType, bool bflip)
		{


			float HorizontalRotationDeg;

			float VerticalRotationDeg;

			TArray<float> YawValues;
			const TArray<float> PitchValues = MoviePipeline::Panoramic::DistributeValuesInInterval(-90.0, 90, InPane.NumVerticalSteps);
			if (SurroundingType == ESurroundingType::Hemisphere)
			{
				YawValues = MoviePipeline::Panoramic::DistributeValuesInInterval(-90, 90, InPane.NumHorizontalSteps);
			}
			else
			{
				YawValues = MoviePipeline::Panoramic::HorizontalDistributeValuesInInterval(0, 360, InPane.NumHorizontalSteps);
			}

			HorizontalRotationDeg = YawValues[InPane.HorizontalStepIndex];
			VerticalRotationDeg = PitchValues[InPane.VerticalStepIndex];


			const FQuat HorizontalRotQuat = FQuat(FVector::UnitZ(), FMath::DegreesToRadians(HorizontalRotationDeg));

			const FQuat VerticalRotQuat = FQuat(FVector::UnitY(), FMath::DegreesToRadians(VerticalRotationDeg));
			const FRotator SourceRot = bInPrevPosition ? InPane.PrevOriginalCameraRotation : InPane.OriginalCameraRotation;

			RelativeRotation = FRotator(HorizontalRotQuat * VerticalRotQuat);
			RelativeRotation = FRotator(RelativeRotation.Pitch, RelativeRotation.Yaw, 0);
			FQuat RotationResult = FQuat(SourceRot) * FQuat(RelativeRotation);
			OutRotation = FRotator(RotationResult);

			if (InStereoIndex < 0)
			{
				OutLocation = bInPrevPosition ? InPane.PrevOriginalCameraLocation : InPane.OriginalCameraLocation;
			}
			else
			{
				check(InStereoIndex == 0 || InStereoIndex == 1);
				if (SurroundingType == ESurroundingType::Hemisphere)
				{
					OutLocation = bInPrevPosition ? InPane.PrevOriginalCameraLocation : InPane.OriginalCameraLocation;
				}
				else
				{
					float FilpValue = bflip ? -1.0 : 1.0;
					float EyeOffset = InStereoIndex == 0 ? (-InPane.EyeSeparation / 2.f) * FilpValue : (InPane.EyeSeparation / 2.f) * FilpValue;
					OutLocation = bInPrevPosition ? InPane.PrevOriginalCameraLocation : InPane.OriginalCameraLocation;

					OutLocation += RotationResult.RotateVector(FVector(0.f, EyeOffset, 0.f));
				}
			}
		}
	}
}

UStereoSphere::UStereoSphere(const FString& InRenderPassName)
	:RenderPassName(InRenderPassName)
	, EyeConvergenceDistance(EyeSeparation * 30.f)
{

	PassIdentifier = FMoviePipelinePassIdentifier(InRenderPassName);
	TArray<FString>  DefaultPostProcessMaterials;
	DefaultPostProcessMaterials.Add(DefaultDepthAsset);
	DefaultPostProcessMaterials.Add(DefaultMotionVectorsAsset);

	for (FString& MaterialPath : DefaultPostProcessMaterials)
	{
		FPanoramicPostProcessPass& NewPass = AdditionalPostProcessMaterials.AddDefaulted_GetRef();
		NewPass.Material = TSoftObjectPtr<UMaterialInterface>(FSoftObjectPath(MaterialPath));
		NewPass.bEnabled = false;
		NewPass.bHighPrecisionOutput = MaterialPath.Equals(DefaultDepthAsset);
	}

	bRenderMainPass = true;
}

void UStereoSphere::PostLoad()
{
	Super::PostLoad();
}

UStereoSphere::~UStereoSphere()
{

	ActivePostProcessMaterials.Reset();
	ActiveHighPrecisionPostProcessMaterials.Reset();

	UniqueStencilLayerNames.Reset();

	OCIOSceneViewExtension.Reset();
	OCIOSceneViewExtension = nullptr;

	PanoramicOutputBlender.Reset();
	PanoramicOutputBlender = nullptr;
	AccumulatorPool.Reset();
	AccumulatorPool = nullptr;

	for (FPaneViewStateData& PaneData : PaneViewStateData)
	{
		for (int32 Index = 0; Index < PaneData.SceneViewStates.Num(); Index++)
		{
			FSceneViewStateInterface* Ref = PaneData.SceneViewStates[Index].GetReference();
			if (Ref)
			{
				Ref->ClearMIDPool();
			}
			PaneData.SceneViewStates[Index].Destroy();
		}
	}
	PaneViewStateData.Reset();
	PaneViewStateData.Empty();

	if (PreviousCustomDepthValue.IsSet())
	{

		IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.CustomDepth"));
		if (CVar)
		{

			if (CVar->GetInt() != PreviousCustomDepthValue.GetValue())
			{
				UE_LOG(LogMovieRenderPipeline, Log, TEXT("Restoring custom depth/stencil value to: %d"), PreviousCustomDepthValue.GetValue());
				CVar->Set(PreviousCustomDepthValue.GetValue(), EConsoleVariableFlags::ECVF_SetByProjectSetting);
			}
		}
	}


	if (!PrevSequenceOutputBases.IsEmpty())
	{

		AsyncTask(ENamedThreads::GameThread, [LocalData = MoveTemp(PrevSequenceOutputBases), this]()mutable
			{
				for (TPair<UMoviePipelineImageSequenceOutputBase*, bool>& Pair : LocalData)
				{
					Pair.Key->SetIsEnabled(Pair.Value);
				}
			});
	}
	PrevSequenceOutputBases.Reset();
	PrevSequenceOutputBases.Empty();
}

void UStereoSphere::StereoValidationImpl()
{
	FTextBuilder TextBuilder;
	if (SurroundingType == ESurroundingType::OmniDirectional)
	{
		if (NumHorizontalSteps < 12)
		{
			const FText WarnningText2 = NSLOCTEXT("StereoSphere", "Number of HorizontalSteps too less", "Num of Horizental Steps too less for OmniDirectional stereo,atleast 12 Horizontal Steps");
			ValidationResults.Add(WarnningText2);
			ValidationState = EMoviePipelineValidationState::Warnings;
		}
	}


}

void UStereoSphere::ValidateStateImpl()
{
	Super::ValidateStateImpl();
	if (bStereo)
	{
		StereoValidationImpl();
	}
}

void UStereoSphere::GetViewShowFlags(FEngineShowFlags& OutShowFlag, EViewModeIndex& OutViewModeIndex) const
{
	OutViewModeIndex = EViewModeIndex::VMI_Lit;
}

void UStereoSphere::MoviePipelineRenderShowFlagOverride(FEngineShowFlags& OutShowFlag)
{

	if (bDisableMultisampleEffects)
	{
		OutShowFlag.SetAntiAliasing(false);
		OutShowFlag.SetDepthOfField(false);
		OutShowFlag.SetMotionBlur(false);
		OutShowFlag.SetBloom(false);
		OutShowFlag.SetSceneColorFringe(false);
	}


	OutShowFlag.SetVignette(false);
	OutShowFlag.SetSceneColorFringe(false);

	OutShowFlag.SetPhysicalMaterialMasks(false);

}

void UStereoSphere::SetupImpl(const MoviePipeline::FMoviePipelineRenderPassInitSettings& InPassInitSettings)
{
	CombineSettings.bStereo = bStereo;
	CombineSettings.SurroundingType = SurroundingType;
	CombineSettings.AlignType = AlignType;
	CombineSettings.SampingMethod = SampingMethod;
	CombineSettings.RenderPassName = RenderPassName;

	if (UMoviePipelineDeferredPassBase* DeferredPass = GetPipeline()->GetPipelinePrimaryConfig()->FindSetting<UMoviePipelineDeferredPassBase>())
	{
		GetPipeline()->GetPipelinePrimaryConfig()->RemoveSetting(DeferredPass);
	}


	Super::SetupImpl(InPassInitSettings);

	LLM_SCOPE_BYNAME(TEXT("MoviePipeline/StereoSphereSetup"));

	if (SurroundingType == ESurroundingType::Hemisphere)
	{
		FinalHorizontalSteps = NumHorizontalSteps / 2;
		FinalVerticalSteps = NumVerticalSteps;
	}
	else
	{
		FinalHorizontalSteps = NumHorizontalSteps;
		FinalVerticalSteps = NumVerticalSteps;
	}


	if (bAddDefaultLayer && (GetNumStencilLayers() == 0))
	{

		UE_LOG(LogMovieRenderPipeline, Error, TEXT("The 'Add Default Layer' deferred rendering option requires at least one Actor or Data Layer to be specified."));

		GetPipeline()->Shutdown(true);
		return;
	}


	{

		TSoftObjectPtr<UMaterialInterface> StencilMatRef = TSoftObjectPtr<UMaterialInterface>(FSoftObjectPath(StencilLayerMaterialAsset));

		StencilLayerMaterial = StencilMatRef.LoadSynchronous();

		if (!StencilLayerMaterial)
		{

			UE_LOG(LogMovieRenderPipeline, Error, TEXT("Failed to load Stencil Mask material, stencil layers will be incorrect. Path: %s"), *StencilMatRef.ToString());
		}
	}

	for (FPanoramicPostProcessPass& AdditionalPass : AdditionalPostProcessMaterials)
	{

		if (AdditionalPass.bEnabled)
		{

			UMaterialInterface* Material = AdditionalPass.Material.LoadSynchronous();

			if (Material)
			{


				ActivePostProcessMaterials.Add(Material);
				if (AdditionalPass.bHighPrecisionOutput)
				{
					ActiveHighPrecisionPostProcessMaterials.Add(Material);
				}
			}
		}
	}

	if (UMoviePipelineExecutorShot* CurrentShot = GetPipeline()->GetActiveShotList()[GetPipeline()->GetCurrentShotIndex()])
	{

		if (UMoviePipelineHighResSetting* HighResSetting = GetPipeline()->FindOrAddSettingForShot<UMoviePipelineHighResSetting>(CurrentShot))
		{
			HighResSetting->TextureSharpnessBias = TextureSharpnessBias;
		}

	}

	{
		IConsoleVariable* ScreenPercentageCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.ScreenPercentage"));
		ScreenPercentageCVar->Set(QualityImprovementPercentage, ECVF_SetByConsole);
	}



	int32 StereoMultiplier = bStereo ? 2 : 1;

	int32 TotalNumberOfAccumulators = 0;
	if (bAllocateHistoryPerPane)
	{
		for (int32 EyeIndex = 0; EyeIndex < StereoMultiplier; EyeIndex++)
		{
			for (int32 VerticalIndex = 0; VerticalIndex < FinalVerticalSteps; VerticalIndex++)
			{

				for (int32 HorizontalIndex = 0; HorizontalIndex < FinalHorizontalSteps; HorizontalIndex++)
				{
					FPaneViewStateData& PaneData = PaneViewStateData.AddDefaulted_GetRef();
					const FIntPoint PaneResolution = GetPaneResolution(InPassInitSettings.BackbufferResolution);
					GetOrCreateViewRenderTarget(PaneResolution);
					GetOrCreateSurfaceQueue(PaneResolution);

					if (bRenderMainPass)
					{
						PaneData.SceneViewStates.AddDefaulted();
						TotalNumberOfAccumulators++;
					}


					if (GetNumStencilLayers() > 0 && bAddDefaultLayer)
					{
						PaneData.SceneViewStates.AddDefaulted();
						TotalNumberOfAccumulators++;
					}

					for (int32 Index = 0; Index < GetNumStencilLayers(); Index++)
					{
						PaneData.SceneViewStates.AddDefaulted();
						TotalNumberOfAccumulators++;
					}

					for (int32 Index = 0; Index < PaneData.SceneViewStates.Num(); Index++)
					{
						PaneData.SceneViewStates[Index].Allocate(InPassInitSettings.FeatureLevel);
					}
				}
			}
		}
	}

	int32 PoolSize = (TotalNumberOfAccumulators + (ActivePostProcessMaterials.Num() * FinalHorizontalSteps * FinalVerticalSteps) + 1) * StereoMultiplier;

	AccumulatorPool = MakeShared<TAccumulatorPool<FImageOverlappedAccumulator>, ESPMode::ThreadSafe>(PoolSize);

	PreviousCustomDepthValue.Reset();

	OCIOSceneViewExtension = FSceneViewExtensions::NewExtension<FOpenColorIODisplayExtension>();

	PanoramicOutputBlender = MakeShared<FStereoBlend>(GetPipeline()->OutputBuilder, CombineSettings, InPassInitSettings.BackbufferResolution);




	const bool bEnableStencilPass = bAddDefaultLayer || GetNumStencilLayers() > 0;
	if (bEnableStencilPass)
	{
		IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.CustomDepth"));
		if (CVar)
		{
			PreviousCustomDepthValue = CVar->GetInt();
			const int32 CustomDepthWithStencil = 3;
			if (PreviousCustomDepthValue != CustomDepthWithStencil)
			{

				UE_LOG(LogMovieRenderPipeline, Log, TEXT("Overriding project custom depth/stencil value to support a stencil pass."));



				CVar->Set(CustomDepthWithStencil, EConsoleVariableFlags::ECVF_SetByProjectSetting);
			}
		}
	}


	if (IsUsingDataLayers())
	{
		for (FSoftObjectPath DataLayerAssetPath : DataLayers)
		{
			UDataLayerAsset* DataLayerAsset = Cast<UDataLayerAsset>(DataLayerAssetPath.TryLoad());
			if (DataLayerAsset)
			{
				UniqueStencilLayerNames.Add(DataLayerAsset->GetName());
			}
		}
	}
	else
	{
		for (const FActorLayer& Layer : ActorLayers)
		{
			UniqueStencilLayerNames.Add(Layer.Name.ToString());
		}
	}

	UE::MoviePipeline::DeduplicateNameArray(UniqueStencilLayerNames);


	bHasWarnedSettings = false;

}

void UStereoSphere::TeardownImpl()
{

	ActivePostProcessMaterials.Reset();
	ActiveHighPrecisionPostProcessMaterials.Reset();
	UniqueStencilLayerNames.Reset();

	for (FPaneViewStateData& PaneData : PaneViewStateData)
	{
		for (int32 Index = 0; Index < PaneData.SceneViewStates.Num(); Index++)
		{
			FSceneViewStateInterface* Ref = PaneData.SceneViewStates[Index].GetReference();
			if (Ref)
			{
				Ref->ClearMIDPool();
			}
			PaneData.SceneViewStates[Index].Destroy();
		}
	}
	PaneViewStateData.Reset();


	OCIOSceneViewExtension.Reset();
	OCIOSceneViewExtension = nullptr;

	PanoramicOutputBlender.Reset();
	PanoramicOutputBlender = nullptr;


	if (PreviousCustomDepthValue.IsSet())
	{

		IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.CustomDepth"));
		if (CVar)
		{

			if (CVar->GetInt() != PreviousCustomDepthValue.GetValue())
			{
				UE_LOG(LogMovieRenderPipeline, Log, TEXT("Restoring custom depth/stencil value to: %d"), PreviousCustomDepthValue.GetValue());
				CVar->Set(PreviousCustomDepthValue.GetValue(), EConsoleVariableFlags::ECVF_SetByProjectSetting);
			}
		}
	}

	if (!PrevSequenceOutputBases.IsEmpty())
	{

		AsyncTask(ENamedThreads::GameThread, [LocalData = MoveTemp(PrevSequenceOutputBases), this]()mutable
			{
				for (TPair<UMoviePipelineImageSequenceOutputBase*, bool>& Pair : LocalData)
				{
					Pair.Key->SetIsEnabled(Pair.Value);
				}
			});
	}
	PrevSequenceOutputBases.Reset();
	PrevSequenceOutputBases.Empty();
	Super::TeardownImpl();
}


void UStereoSphere::AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector)
{
	Super::AddReferencedObjects(InThis, Collector);
	UStereoSphere& This = *CastChecked<UStereoSphere>(InThis);

	for (FPaneViewStateData& PaneData : This.PaneViewStateData)
	{
		for (int32 Index = 0; Index < PaneData.SceneViewStates.Num(); Index++)
		{
			FSceneViewStateInterface* Ref = PaneData.SceneViewStates[Index].GetReference();
			if (Ref)
			{
				Ref->AddReferencedObjects(Collector);
			}
		}
	}

}



FSceneViewStateInterface* UStereoSphere::GetSceneViewStateInterface(IViewCalcPayload* OptPayload)
{
	FPanoPane* PanoPane = (FPanoPane*)OptPayload;
	check(PanoPane);
	if (bAllocateHistoryPerPane)
	{
		FPaneViewStateData& PaneData = PaneViewStateData[PanoPane->GetAbsoluteIndex()];
		return PaneData.SceneViewStates[PanoPane->SceneViewIndex].GetReference();
	}
	return nullptr;
}


void UStereoSphere::GatherOutputPassesImpl(TArray<FMoviePipelinePassIdentifier>& ExpectedRenderPasses)
{
	FMoviePipelinePassIdentifier PanoPassIdentifier;
	PanoPassIdentifier.Name = PassIdentifier.Name;
	PanoPassIdentifier.CameraName = GetCameraName();
	if (bRenderMainPass)
	{
		ExpectedRenderPasses.Add(PanoPassIdentifier);
	}
	TArray<FString> RenderPasses;

	for (UMaterialInterface* Materal : ActivePostProcessMaterials)
	{
		if (Materal)
		{
			RenderPasses.Add(GetNameForPostProcessMaterial(Materal));
		}
	}

	for (const FString& Pass : RenderPasses)
	{
		ExpectedRenderPasses.Add(FMoviePipelinePassIdentifier(PanoPassIdentifier.Name + Pass, GetCameraName()));
	}

	if (GetNumStencilLayers() > 0 && bAddDefaultLayer)
	{
		ExpectedRenderPasses.Add(FMoviePipelinePassIdentifier(PanoPassIdentifier.Name + TEXT("DefaultLayer"), GetCameraName()));
	}
	for (const FString& StencilLayerName : GetStencilLayerNames())
	{
		ExpectedRenderPasses.Add(FMoviePipelinePassIdentifier(PanoPassIdentifier.Name + StencilLayerName, PanoPassIdentifier.CameraName));
	}
}

void UStereoSphere::AddViewExtensions(FSceneViewFamilyContext& InContext, FMoviePipelineRenderPassMetrics& InOutSampleState)
{

	if (InOutSampleState.OCIOConfiguration && InOutSampleState.OCIOConfiguration->bIsEnabled)
	{
		FOpenColorIODisplayConfiguration* OCIOConfigNew = const_cast<FMoviePipelineRenderPassMetrics&>(InOutSampleState).OCIOConfiguration;
		FOpenColorIODisplayConfiguration& OCIOConfigCurrent = OCIOSceneViewExtension->GetDisplayConfiguration();


		if (OCIOConfigNew->ColorConfiguration.ConfigurationSource && OCIOConfigNew->ColorConfiguration.ConfigurationSource != OCIOConfigCurrent.ColorConfiguration.ConfigurationSource)
		{
			OCIOSceneViewExtension->SetDisplayConfiguration(*OCIOConfigNew);
		}
		InContext.ViewExtensions.Add(OCIOSceneViewExtension.ToSharedRef());
	}
}



FIntPoint UStereoSphere::GetPaneResolution(const FIntPoint& InSize) const
{


	float HorizontalFov;
	float VerticalFov;
	GetFieldOfView(HorizontalFov, VerticalFov);



	float HorizontalRes;
	if (SurroundingType == ESurroundingType::Hemisphere)
	{
		HorizontalRes = (HorizontalFov / 180.0f) * InSize.X * (1.0 + OverscanPercentage);
	}
	else
	{
		HorizontalRes = (HorizontalFov / 360.0f) * InSize.X * (1.0 + OverscanPercentage);
	}
	float Intermediate = FMath::Tan(FMath::DegreesToRadians(VerticalFov) * 0.5f) / FMath::Tan(FMath::DegreesToRadians(HorizontalFov) * 0.5f);
	float VerticalRes = HorizontalRes * Intermediate;
	return FIntPoint(FMath::CeilToInt(HorizontalRes), FMath::CeilToInt(VerticalRes));
}

void UStereoSphere::GetFieldOfView(float& OutHorizontal, float& OutVertical) const
{

	float HorizontalFOV;
	if (SurroundingType == ESurroundingType::Hemisphere)
	{
		HorizontalFOV = FMath::Min(180.0f / FinalHorizontalSteps * (1 + OverlapPercentage * 0.01), 150);
	}
	else
	{
		HorizontalFOV = FMath::Min(380.0f / FinalHorizontalSteps * (1 + OverlapPercentage * 0.01), 150);
	}
	OutHorizontal = HorzFieldOfView > 0 ? HorzFieldOfView : HorizontalFOV;
	OutVertical = VertFieldOfView > 0 ? VertFieldOfView : FMath::Min(180.0 / (FinalVerticalSteps) * (1 + OverlapPercentage * 0.01), 150);
}

FSceneView* UStereoSphere::GetSceneViewForSampleState(FSceneViewFamily* ViewFamily, FMoviePipelineRenderPassMetrics& InOutSampleState, IViewCalcPayload* OptPayload)
{

	check(OptPayload);
	FPanoPane* PanoPane = (FPanoPane*)OptPayload;

	APlayerController* LocalPlayerController = GetPipeline()->GetWorld()->GetFirstPlayerController();

	int32 PaneSizeX = PanoPane->Resolution.X;
	int32 PaneSizeY = PanoPane->Resolution.Y;

	FSceneViewInitOptions ViewInitOptions;
	ViewInitOptions.ViewFamily = ViewFamily;

	ViewInitOptions.ViewOrigin = PanoPane->CameraLocation;
	ViewInitOptions.SetViewRectangle(FIntRect(FIntPoint(0, 0), FIntPoint(PaneSizeX, PaneSizeY)));

	ViewInitOptions.ViewRotationMatrix = FInverseRotationMatrix(FRotator(PanoPane->CameraRotation));
	ViewInitOptions.ViewRotationMatrix = ViewInitOptions.ViewRotationMatrix * FMatrix(
		FPlane(0, 0, 1, 0),
		FPlane(1, 0, 0, 0),
		FPlane(0, 1, 0, 0),
		FPlane(0, 0, 0, 1));
	ViewInitOptions.ViewActor = LocalPlayerController ? LocalPlayerController->GetViewTarget() : nullptr;

	float ViewFOV = PanoPane->HorizontalFieldOfView;




	float DofSensorScale = 1.0f;


	{

		float MinZ = GNearClippingPlane;
		if (LocalPlayerController && LocalPlayerController->PlayerCameraManager)
		{
			float NearClipPlane = LocalPlayerController->PlayerCameraManager->GetCameraCacheView().PerspectiveNearClipPlane;
			MinZ = NearClipPlane > 0 ? NearClipPlane : MinZ;
		}

		PanoPane->NearClippingPlane = MinZ;



		const float MatrixFOV = FMath::Max(0.001f, ViewFOV) * (float)PI / 360.0f;
		static_assert((int32)ERHIZBuffer::IsInverted != 0, "ZBuffer should be inverted");

		float XAxisMultiplier = 1.f;
		float YAxisMultiplier = 1.f;
		if (PaneSizeX > PaneSizeY)
		{

			XAxisMultiplier = PaneSizeX / (float)PaneSizeY;
		}
		else
		{

			YAxisMultiplier = PaneSizeY / (float)PaneSizeX;
		}

		FMatrix BaseProjMatrix = FReversedZPerspectiveMatrix(
			MatrixFOV,
			XAxisMultiplier,
			YAxisMultiplier,
			MinZ
		);

		if (PanoPane->EyeIndex >= 0 && SurroundingType == ESurroundingType::OmniDirectional)
		{
			float HalfEyeOffset = PanoPane->EyeSeparation * 0.5f;

			float FlipValue = bFlipEyes ? -1 : 1;


			float ProjectionOffset = PanoPane->EyeIndex == 0
				? -HalfEyeOffset / PanoPane->EyeConvergenceDistance * FlipValue
				: HalfEyeOffset / PanoPane->EyeConvergenceDistance * FlipValue;
			BaseProjMatrix.M[2][0] = ProjectionOffset;
		}

		ViewInitOptions.ProjectionMatrix = BaseProjMatrix;
	}

	ViewInitOptions.SceneViewStateInterface = GetSceneViewStateInterface(OptPayload);
	ViewInitOptions.FOV = ViewFOV;

	FSceneView* View = new FSceneView(ViewInitOptions);
	ViewFamily->Views.Add(View);
	View->ViewLocation = PanoPane->CameraLocation;
	View->ViewRotation = PanoPane->CameraRotation;

	View->PreviousViewTransform = FTransform(PanoPane->PrevCameraRotation, PanoPane->PrevCameraLocation);
	View->StartFinalPostprocessSettings(View->ViewLocation);
	BlendPostProcessSettings(View, InOutSampleState, OptPayload);

	if (bEnableDepthOfField)
	{
		View->FinalPostProcessSettings.DepthOfFieldSensorWidth *= DofSensorScale;
	}
	else
	{
		View->FinalPostProcessSettings.DepthOfFieldSensorWidth = 0.0f;
	}

	View->EndFinalPostprocessSettings(ViewInitOptions);

	return View;
}

FIntPoint UStereoSphere::GetPayloadPaneResolution(const FIntPoint& InSize, IViewCalcPayload* OptPayload) const
{
	if (OptPayload)
	{
		FPanoPane* PanoPane = (FPanoPane*)OptPayload;
		return PanoPane->Resolution;
	}
	return InSize;
}


TWeakObjectPtr<UTextureRenderTarget2D> UStereoSphere::GetOrCreateViewRenderTarget(const FIntPoint& InSize, IViewCalcPayload* OptPayload)
{
	return Super::GetOrCreateViewRenderTarget(GetPayloadPaneResolution(InSize, OptPayload), OptPayload);
}


TSharedPtr<FMoviePipelineSurfaceQueue, ESPMode::ThreadSafe> UStereoSphere::GetOrCreateSurfaceQueue(const FIntPoint& InSize, IViewCalcPayload* OptPayload)
{
	return Super::GetOrCreateSurfaceQueue(GetPayloadPaneResolution(InSize, OptPayload), OptPayload);
}



bool UStereoSphere::IsActorInAnyStencilLayer(AActor* InActor) const
{

	bool bInLayer = false;

	if (IsUsingDataLayers())
	{

		for (FSoftObjectPath DataLayerAssetPath : DataLayers)
		{


			UDataLayerAsset* DataLayerAsset = Cast<UDataLayerAsset>(DataLayerAssetPath.TryLoad());

			if (DataLayerAsset)
			{

				bInLayer = !InActor->ContainsDataLayer(DataLayerAsset);


				if (!bInLayer)
				{
					break;
				}
			}
		}
	}
	else
	{

		for (const FActorLayer& AllLayer : ActorLayers)
		{

			bInLayer = !InActor->Layers.Contains(AllLayer.Name);

			if (!bInLayer)
			{
				break;
			}
		}
	}

	return bInLayer;
}


bool UStereoSphere::IsUsingDataLayers() const
{

	int32 NumDataLayers = 0;

	for (FSoftObjectPath DataLayerAssetPath : DataLayers)
	{


		UDataLayerAsset* DataLayerAsset = Cast<UDataLayerAsset>(DataLayerAssetPath.TryLoad());


		if (DataLayerAsset)
		{

			NumDataLayers++;
		}
	}

	return NumDataLayers > 0;
}

int32 UStereoSphere::GetNumStencilLayers() const
{
	if (IsUsingDataLayers())
	{

		int32 NumDataLayers = 0;

		for (FSoftObjectPath DataLayerAssetPath : DataLayers)
		{

			UDataLayerAsset* DataLayerAsset = Cast<UDataLayerAsset>(DataLayerAssetPath.TryLoad());

			if (DataLayerAsset)
			{

				NumDataLayers++;
			}
		}

		return NumDataLayers;
	}

	return ActorLayers.Num();
}

TArray<FString> UStereoSphere::GetStencilLayerNames() const
{
	return UniqueStencilLayerNames;
}

bool UStereoSphere::IsActorInLayer(AActor* InActor, int32 InLayerIndex) const
{

	if (IsUsingDataLayers())
	{

		FSoftObjectPath DataLayerAssetPath = GetValidDataLayerByIndex(InLayerIndex);
		UDataLayerAsset* DataLayerAsset = Cast<UDataLayerAsset>(DataLayerAssetPath.TryLoad());

		if (DataLayerAsset)
		{

			return InActor->ContainsDataLayer(DataLayerAsset);
		}
	}
	else
	{
		const FName& LayerName = ActorLayers[InLayerIndex].Name;
		return InActor->Layers.Contains(LayerName);

	}

	return false;
}

FSoftObjectPath UStereoSphere::GetValidDataLayerByIndex(const int32 InIndex) const
{
	int32 NumValidDataLayers = 0;
	for (FSoftObjectPath DataLayerAssetPath : DataLayers)
	{

		UDataLayerAsset* DataLayerAsset = Cast<UDataLayerAsset>(DataLayerAssetPath.TryLoad());
		if (DataLayerAsset)
		{

			if (InIndex == NumValidDataLayers)
			{
				return DataLayerAssetPath;
			}

			NumValidDataLayers++;
		}
	}

	return FSoftObjectPath();
}

FString UStereoSphere::GetCameraName() const
{

	UMoviePipelineExecutorShot* CurrentShot = GetPipeline()->GetActiveShotList()[GetPipeline()->GetCurrentShotIndex()];

	return CurrentShot->GetCameraName(0);
}

FString UStereoSphere::GetNameForPostProcessMaterial(const UMaterialInterface* InMaterial)
{
	FString MaterialName = InMaterial->GetName();


	const FPanoramicPostProcessPass* MatchingPass = Algo::FindByPredicate(AdditionalPostProcessMaterials, [InMaterial](const FPanoramicPostProcessPass& InPass) { return InPass.Material == InMaterial; });
	if (MatchingPass && !MatchingPass->Name.IsEmpty())
	{
		MaterialName = MatchingPass->Name;
	}

	return MaterialName;
}

void UStereoSphere::RenderSample_GameThreadImpl(const FMoviePipelineRenderPassMetrics& InSampleState)
{

	Super::RenderSample_GameThreadImpl(InSampleState);
	const FIntPoint PaneResolution = GetPaneResolution(InSampleState.BackbufferSize);
	FMoviePipelinePassIdentifier PanoPassIdentifier;
	PanoPassIdentifier.Name = PassIdentifier.Name;
	PanoPassIdentifier.CameraName = GetCameraName();

	int32 NumEyeRenders = bStereo ? 2 : 1;


	for (int32 EyeLoopIndex = 0; EyeLoopIndex < NumEyeRenders; EyeLoopIndex++)
	{
		for (int32 VerticalStepIndex = 0; VerticalStepIndex < FinalVerticalSteps; VerticalStepIndex++)
		{
			for (int32 HorizontalStepIndex = 0; HorizontalStepIndex < FinalHorizontalSteps; HorizontalStepIndex++)
			{
				FMoviePipelineRenderPassMetrics InOutSampleState = InSampleState;
				FPanoPane Pane;
				{

					FVector OriginalSequenceLocation = InSampleState.FrameInfo.CurrViewLocation;
					FVector PrevOriginalSequenceLocation = InSampleState.FrameInfo.PrevViewLocation;
					FRotator OriginalSequenceRotation = InSampleState.FrameInfo.CurrViewRotation;
					FRotator PrevOriginalSequenceRotation = InSampleState.FrameInfo.PrevViewRotation;
					FTransform OriginalSequenceTransform = FTransform(OriginalSequenceRotation, OriginalSequenceLocation, FVector(1.f, 1.f, 1.f));
					FTransform  PrevOriginalSequenceTransform = FTransform(PrevOriginalSequenceRotation, PrevOriginalSequenceLocation, FVector(1.f, 1.f, 1.f));

					int32 StereoIndex = bStereo ? EyeLoopIndex : -1;
					Pane.EyeIndex = StereoIndex;
					if (StereoIndex == -1)
					{
						Pane.OriginalCameraLocation = OriginalSequenceLocation;
						Pane.PrevOriginalCameraLocation = PrevOriginalSequenceLocation;
					}
					else
					{
						check(StereoIndex == 0 || StereoIndex == 1);
						float EyeOffset;
						if (SurroundingType == ESurroundingType::Hemisphere)
						{
							float FlipValue = bFlipEyes ? -1.0 : 1.0;
							EyeOffset = StereoIndex == 0 ? (-EyeSeparation / 2.f) * FlipValue : (EyeSeparation / 2.f) * FlipValue;
							Pane.OriginalCameraLocation = OriginalSequenceTransform.TransformPosition(FVector(0.0f, EyeOffset, 0.0f));
							Pane.PrevOriginalCameraLocation = PrevOriginalSequenceTransform.TransformPosition(FVector(0.0f, EyeOffset, 0.0f));
						}
						else
						{
							Pane.OriginalCameraLocation = OriginalSequenceLocation;
							Pane.PrevOriginalCameraLocation = PrevOriginalSequenceLocation;
						}
					}
					Pane.OriginalCameraRotation = OriginalSequenceRotation;
					Pane.PrevOriginalCameraRotation = PrevOriginalSequenceRotation;
					Pane.VerticalStepIndex = VerticalStepIndex;
					Pane.HorizontalStepIndex = HorizontalStepIndex;
					Pane.NumHorizontalSteps = FinalHorizontalSteps;
					Pane.NumVerticalSteps = FinalVerticalSteps;
					Pane.EyeSeparation = EyeSeparation;
					Pane.EyeConvergenceDistance = EyeConvergenceDistance;
					Pane.OverlapPercentage = OverlapPercentage / 100.f;

					FRotator TempRotation;
					MoviePipeline::Panoramic::GetCameraOrientationForStereo(Pane.PrevCameraLocation,
						Pane.PrevCameraRotation, TempRotation, Pane, true, Pane.EyeIndex, SurroundingType, bFlipEyes);
					MoviePipeline::Panoramic::GetCameraOrientationForStereo(Pane.CameraLocation,
						Pane.CameraRotation, Pane.RelativeRotation, Pane, false, Pane.EyeIndex, SurroundingType, bFlipEyes);
					GetFieldOfView(Pane.HorizontalFieldOfView, Pane.VerticalFieldOfView);


					Pane.Resolution = PaneResolution;
				}


				if (bRenderMainPass)
				{
					Pane.SceneViewIndex = 0;
					TSharedPtr<FSceneViewFamilyContext> ViewFamily = CalculateViewFamily(InOutSampleState, &Pane);
					EAntiAliasingMethod AAMethod = ViewFamily->Views[0]->AntiAliasingMethod;
					const bool bRequiresHistory = (AAMethod == EAntiAliasingMethod::AAM_TemporalAA) || (AAMethod == EAntiAliasingMethod::AAM_TSR);

					FSceneView* View = const_cast<FSceneView*>(ViewFamily->Views[0]);
					if (!bAllocateHistoryPerPane && bRequiresHistory)
					{

						UE_LOG(LogMovieRenderPipeline, Warning, TEXT("Stereo Spheres do not support TAA without enabling bAllocateHistoryPerPane! Forcing AntiAliasing off."));

						View->AntiAliasingMethod = EAntiAliasingMethod::AAM_None;
					}

					View->FinalPostProcessSettings.BufferVisualizationOverviewMaterials.Empty();
					View->FinalPostProcessSettings.BufferVisualizationPipes.Empty();

					for (UMaterialInterface* Material : ActivePostProcessMaterials)
					{
						if (Material)
						{
							View->FinalPostProcessSettings.BufferVisualizationOverviewMaterials.Add(Material);
						}
					}

					for (UMaterialInterface* VisMaterial : View->FinalPostProcessSettings.BufferVisualizationOverviewMaterials)
					{
						if (InOutSampleState.bDiscardResult)
						{
							continue;
						}

						FMoviePipelinePassIdentifier LayerPassIdentifier = FMoviePipelinePassIdentifier(PanoPassIdentifier.Name + GetNameForPostProcessMaterial(VisMaterial), GetCameraName());

						auto BufferPipe = MakeShared<FImagePixelPipe, ESPMode::ThreadSafe>();

						BufferPipe->bIsExpecting32BitPixelData = ActiveHighPrecisionPostProcessMaterials.Contains(VisMaterial);
						BufferPipe->AddEndpoint(MakeForwardingEndPoint(LayerPassIdentifier, Pane, InOutSampleState));
						View->FinalPostProcessSettings.BufferVisualizationPipes.Add(VisMaterial->GetFName(), BufferPipe);
					}
					int32 NumValidMaterials = View->FinalPostProcessSettings.BufferVisualizationPipes.Num();
					View->FinalPostProcessSettings.bBufferVisualizationDumpRequired = NumValidMaterials > 0;

					TWeakObjectPtr<UTextureRenderTarget2D> ViewRenderTarget = GetOrCreateViewRenderTarget(PaneResolution);
					check(ViewRenderTarget.IsValid());

					FRenderTarget* RenderTarget = ViewRenderTarget->GameThread_GetRenderTargetResource();
					check(RenderTarget);

					FCanvas Canvas = FCanvas(RenderTarget, nullptr, GetPipeline()->GetWorld(), ViewFamily->GetFeatureLevel(), FCanvas::CDM_DeferDrawing, 1.0f);
					GetRendererModule().BeginRenderingViewFamily(&Canvas, ViewFamily.Get());

					ENQUEUE_RENDER_COMMAND(TransitionTextureSRVState)(
						[RenderTarget](FRHICommandListImmediate& RHICmdList) mutable
						{

							RHICmdList.Transition(FRHITransitionInfo(RenderTarget->GetRenderTargetTexture(), ERHIAccess::RTV, ERHIAccess::SRVGraphicsPixel));
						});

					PostRendererSubmission(InOutSampleState, PanoPassIdentifier, GetOutputFileSortingOrder(), Pane, Canvas);
				}


				{
					struct FStencilValues
					{

						FStencilValues()

							: bRenderCustomDepth(false)

							, StencilMask(ERendererStencilMask::ERSM_Default)

							, CustomStencil(0)
						{
						}

						bool bRenderCustomDepth;

						ERendererStencilMask StencilMask;
						int32 CustomStencil;
					};

					TArray<FString> AllStencilLayerNames = GetStencilLayerNames();

					if (bAddDefaultLayer)
					{
						AllStencilLayerNames.Add(TEXT("DefaultLayer"));
					}

					TMap<UPrimitiveComponent*, FStencilValues> PreviousValues;

					if (AllStencilLayerNames.Num() > 0)
					{
						for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
						{
							AActor* Actor = *ActorItr;
							if (Actor)
							{

								for (UActorComponent* Component : Actor->GetComponents())
								{
									if (Component && Component->IsA<UPrimitiveComponent>())
									{

										UPrimitiveComponent* PrimitiveComponent = CastChecked<UPrimitiveComponent>(Component);

										FStencilValues& Values = PreviousValues.Add(PrimitiveComponent);
										Values.StencilMask = PrimitiveComponent->CustomDepthStencilWriteMask;
										Values.CustomStencil = PrimitiveComponent->CustomDepthStencilValue;
										Values.bRenderCustomDepth = PrimitiveComponent->bRenderCustomDepth;
									}
								}
							}
						}
					}

					for (int32 StencilLayerIndex = 0; StencilLayerIndex < AllStencilLayerNames.Num(); StencilLayerIndex++)
					{
						const FString& LayerName = AllStencilLayerNames[StencilLayerIndex];

						FMoviePipelinePassIdentifier LayerPassIdentifier = FMoviePipelinePassIdentifier(PanoPassIdentifier.Name + LayerName, PanoPassIdentifier.CameraName);


						for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
						{
							AActor* Actor = *ActorItr;
							if (Actor)
							{
								bool bInLayer = true;
								if (bAddDefaultLayer && LayerName == TEXT("DefaultLayer"))
								{


									bInLayer = IsActorInAnyStencilLayer(Actor);
								}

								else
								{
									bInLayer = IsActorInLayer(Actor, StencilLayerIndex);
								}

								for (UActorComponent* Component : Actor->GetComponents())
								{
									if (Component && Component->IsA<UPrimitiveComponent>())
									{

										UPrimitiveComponent* PrimitiveComponent = CastChecked<UPrimitiveComponent>(Component);


										PrimitiveComponent->SetCustomDepthStencilValue(bInLayer ? 1 : 0);
										PrimitiveComponent->SetCustomDepthStencilWriteMask(ERendererStencilMask::ERSM_Default);
										PrimitiveComponent->SetRenderCustomDepth(true);
									}
								}
							}
						}

						if (StencilLayerMaterial)
						{

							Pane.SceneViewIndex = StencilLayerIndex + (bRenderMainPass ? 1 : 0);

							TSharedPtr<FSceneViewFamilyContext> ViewFamily = CalculateViewFamily(InOutSampleState, &Pane);
							FSceneView* View = const_cast<FSceneView*>(ViewFamily->Views[0]);


							View->FinalPostProcessSettings.AddBlendable(StencilLayerMaterial, 1.0f);

							IBlendableInterface* BlendableInterface = Cast<IBlendableInterface>(StencilLayerMaterial);

							BlendableInterface->OverrideBlendableSettings(*View, 1.f);
							{
								TWeakObjectPtr<UTextureRenderTarget2D> ViewRenderTarget = GetOrCreateViewRenderTarget(InOutSampleState.BackbufferSize, (IViewCalcPayload*)(&Pane));

								check(ViewRenderTarget.IsValid());

								FRenderTarget* RenderTarget = ViewRenderTarget->GameThread_GetRenderTargetResource();

								check(RenderTarget);
								FCanvas Canvas = FCanvas(RenderTarget, nullptr, GetPipeline()->GetWorld(), View->GetFeatureLevel(), FCanvas::CDM_DeferDrawing, 1.0f);
								GetRendererModule().BeginRenderingViewFamily(&Canvas, ViewFamily.Get());
								ENQUEUE_RENDER_COMMAND(TransitionTextureSRVState)(
									[RenderTarget](FRHICommandListImmediate& RHICmdList) mutable
									{
										RHICmdList.Transition(FRHITransitionInfo(RenderTarget->GetRenderTargetTexture(), ERHIAccess::RTV, ERHIAccess::SRVGraphicsPixel));
									}
									);
								PostRendererSubmission(InOutSampleState, LayerPassIdentifier, GetOutputFileSortingOrder() + 1, Pane, Canvas);
							}
						}
					}
					for (TPair<UPrimitiveComponent*, FStencilValues>& KVP : PreviousValues)
					{
						KVP.Key->SetCustomDepthStencilValue(KVP.Value.CustomStencil);
						KVP.Key->SetCustomDepthStencilWriteMask(KVP.Value.StencilMask);
						KVP.Key->SetRenderCustomDepth(KVP.Value.bRenderCustomDepth);
					}
				}
			}
		}
	}
}

TFunction<void(TUniquePtr<FImagePixelData>&&)> UStereoSphere::MakeForwardingEndPoint(const FMoviePipelinePassIdentifier InPassIdentifier, FPanoPane& InPane, const FMoviePipelineRenderPassMetrics& InSampleState)
{
	TSharedPtr<FAccumulatorPool::FAccumulatorInstance, ESPMode::ThreadSafe> SampleAccumulator = nullptr;

	{
		SCOPE_CYCLE_COUNTER(STAT_MoviePipeline_WaitForAvailableAccumulator);
		FMoviePipelinePassIdentifier PanePassIdentifier = FMoviePipelinePassIdentifier(FString::Printf(TEXT("%s_%d_x%d_y%d"), *InPassIdentifier.Name, InPane.EyeIndex, InPane.HorizontalStepIndex, InPane.VerticalStepIndex));
		SampleAccumulator = AccumulatorPool->BlockAndGetAccumulator_GameThread(InSampleState.OutputState.OutputFrameNumber, PanePassIdentifier);
	}


	TSharedPtr<FPanoramicImagePixelDataPayload, ESPMode::ThreadSafe> FramePayload = MakeShared<FPanoramicImagePixelDataPayload, ESPMode::ThreadSafe>();
	FramePayload->PassIdentifier = InPassIdentifier;
	FramePayload->SampleState = InSampleState;
	FramePayload->SortingOrder = GetOutputFileSortingOrder() + 1;
	FramePayload->Pane = InPane;
	if (FramePayload->Pane.EyeIndex >= 0)
	{
		FramePayload->Debug_OverrideFilename = FString::Printf(TEXT("/%s_SS_%d_TS_%d_TileX_%d_TileY_%d_PaneX_%d_PaneY_%d_Eye_%d.%d"),
			*FramePayload->PassIdentifier.Name, FramePayload->SampleState.SpatialSampleIndex, FramePayload->SampleState.TemporalSampleIndex,
			FramePayload->SampleState.TileIndexes.X, FramePayload->SampleState.TileIndexes.Y, FramePayload->Pane.HorizontalStepIndex,
			FramePayload->Pane.VerticalStepIndex, FramePayload->Pane.EyeIndex, FramePayload->SampleState.OutputState.OutputFrameNumber);
	}
	else
	{
		FramePayload->Debug_OverrideFilename = FString::Printf(TEXT("/%s_SS_%d_TS_%d_TileX_%d_TileY_%d_PaneX_%d_PaneY_%d.%d"),
			*FramePayload->PassIdentifier.Name, FramePayload->SampleState.SpatialSampleIndex, FramePayload->SampleState.TemporalSampleIndex,
			FramePayload->SampleState.TileIndexes.X, FramePayload->SampleState.TileIndexes.Y, FramePayload->Pane.HorizontalStepIndex,
			FramePayload->Pane.VerticalStepIndex, FramePayload->SampleState.OutputState.OutputFrameNumber);
	}



	MoviePipeline::FImageSampleAccumulationArgs AccumulationArgs;
	{

		AccumulationArgs.OutputMerger = PanoramicOutputBlender;

		AccumulationArgs.ImageAccumulator = StaticCastSharedPtr<FImageOverlappedAccumulator>(SampleAccumulator->Accumulator);

		AccumulationArgs.bAccumulateAlpha = bAccumulatorIncludesAlpha;
	}


	auto Callback = [this, FramePayload, AccumulationArgs, SampleAccumulator](TUniquePtr<FImagePixelData>&& InPixelData)
		{
			TUniquePtr<FImagePixelData> PixelDataWithPayload = nullptr;
			switch (InPixelData->GetType())
			{
			case EImagePixelType::Color:
			{
				TImagePixelData<FColor>* SourceData = static_cast<TImagePixelData<FColor>*>(InPixelData.Get());
				PixelDataWithPayload = MakeUnique<TImagePixelData<FColor>>(InPixelData->GetSize(), MoveTemp(SourceData->Pixels), FramePayload);
				break;
			}
			case EImagePixelType::Float16:
			{
				TImagePixelData<FFloat16Color>* SourceData = static_cast<TImagePixelData<FFloat16Color>*>(InPixelData.Get());
				PixelDataWithPayload = MakeUnique<TImagePixelData<FFloat16Color>>(InPixelData->GetSize(), MoveTemp(SourceData->Pixels), FramePayload);
				break;
			}
			case EImagePixelType::Float32:
			{
				TImagePixelData<FLinearColor>* SourceData = static_cast<TImagePixelData<FLinearColor>*>(InPixelData.Get());
				PixelDataWithPayload = MakeUnique<TImagePixelData<FLinearColor>>(InPixelData->GetSize(), MoveTemp(SourceData->Pixels), FramePayload);
				break;
			}
			default:
				checkNoEntry();
			}

			bool bFinalSample = FramePayload->IsLastTile() && FramePayload->IsLastTemporalSample();

			FMoviePipelineBackgroundAccumulateTask Task;
			Task.LastCompletionEvent = SampleAccumulator->TaskPrereq;
			FGraphEventRef Event = Task.Execute([PixelData = MoveTemp(PixelDataWithPayload), AccumulationArgs, bFinalSample, SampleAccumulator]()mutable
				{
					MoviePipeline::AccumulateSample_TaskThread(MoveTemp(PixelData), AccumulationArgs);
					if (bFinalSample)
					{
						SampleAccumulator->bIsActive = false;
						SampleAccumulator->TaskPrereq = nullptr;
					}
				});
			SampleAccumulator->TaskPrereq = Event;
			this->OutstandingTasks.Add(Event);
		};
	return Callback;
}

void UStereoSphere::PostRendererSubmission(const FMoviePipelineRenderPassMetrics& InSampleState, const FMoviePipelinePassIdentifier InPassIdentifier, const int32 InSortingOrder, FPanoPane& InPane, FCanvas& InCanvas)
{


	if (InSampleState.bDiscardResult)
	{
		return;
	}





	TSharedPtr<FAccumulatorPool::FAccumulatorInstance, ESPMode::ThreadSafe> SampleAccumulator = nullptr;
	{
		SCOPE_CYCLE_COUNTER(STAT_MoviePipeline_WaitForAvailableAccumulator);

		FMoviePipelinePassIdentifier PanePassIdentifier = FMoviePipelinePassIdentifier(FString::Printf(TEXT("%s_eye%d_x%d_y%d"), *InPassIdentifier.Name, InPane.EyeIndex, InPane.HorizontalStepIndex, InPane.VerticalStepIndex));
		SampleAccumulator = AccumulatorPool->BlockAndGetAccumulator_GameThread(InSampleState.OutputState.OutputFrameNumber, PanePassIdentifier);
	}

	TSharedRef<FPanoramicImagePixelDataPayload, ESPMode::ThreadSafe> FramePayload = MakeShared<FPanoramicImagePixelDataPayload, ESPMode::ThreadSafe>();

	FramePayload->PassIdentifier = InPassIdentifier;
	FramePayload->SampleState = InSampleState;
	FramePayload->SortingOrder = InSortingOrder;
	FramePayload->Pane = InPane;

	if (FramePayload->Pane.EyeIndex >= 0)
	{
		FramePayload->Debug_OverrideFilename = FString::Printf(TEXT("/%s_SS_%d_TS_%d_TileX_%d_TileY_%d_PaneX_%d_PaneY_%d_Eye_%d.%d"),
			*FramePayload->PassIdentifier.Name, FramePayload->SampleState.SpatialSampleIndex, FramePayload->SampleState.TemporalSampleIndex,
			FramePayload->SampleState.TileIndexes.X, FramePayload->SampleState.TileIndexes.Y, FramePayload->Pane.HorizontalStepIndex,
			FramePayload->Pane.VerticalStepIndex, FramePayload->Pane.EyeIndex, FramePayload->SampleState.OutputState.OutputFrameNumber);
	}
	else
	{
		FramePayload->Debug_OverrideFilename = FString::Printf(TEXT("/%s_SS_%d_TS_%d_TileX_%d_TileY_%d_PaneX_%d_PaneY_%d.%d"),
			*FramePayload->PassIdentifier.Name, FramePayload->SampleState.SpatialSampleIndex, FramePayload->SampleState.TemporalSampleIndex,
			FramePayload->SampleState.TileIndexes.X, FramePayload->SampleState.TileIndexes.Y, FramePayload->Pane.HorizontalStepIndex,
			FramePayload->Pane.VerticalStepIndex, FramePayload->SampleState.OutputState.OutputFrameNumber);
	}

	TSharedPtr<FMoviePipelineSurfaceQueue, ESPMode::ThreadSafe> LocalSurfaceQueue = GetOrCreateSurfaceQueue(InSampleState.BackbufferSize, (IViewCalcPayload*)(&FramePayload->Pane));


	MoviePipeline::FImageSampleAccumulationArgs AccumulationArgs;
	{
		AccumulationArgs.OutputMerger = PanoramicOutputBlender;
		AccumulationArgs.ImageAccumulator = StaticCastSharedPtr<FImageOverlappedAccumulator>(SampleAccumulator->Accumulator);
		AccumulationArgs.bAccumulateAlpha = bAccumulatorIncludesAlpha;
	}

	auto Callback = [this, FramePayload, AccumulationArgs, SampleAccumulator](TUniquePtr<FImagePixelData>&& InPixelData)
		{
			bool bFinalSample = FramePayload->IsLastTile() && FramePayload->IsLastTemporalSample();

			FMoviePipelineBackgroundAccumulateTask Task;
			Task.LastCompletionEvent = SampleAccumulator->TaskPrereq;
			FGraphEventRef Event = Task.Execute([PixelData = MoveTemp(InPixelData), AccumulationArgs, bFinalSample, SampleAccumulator]() mutable
				{

					MoviePipeline::AccumulateSample_TaskThread(MoveTemp(PixelData), AccumulationArgs);
					if (bFinalSample)
					{

						SampleAccumulator->bIsActive = false;
						SampleAccumulator->TaskPrereq = nullptr;
					}
				});
			SampleAccumulator->TaskPrereq = Event;
			this->OutstandingTasks.Add(Event);
		};

	FRenderTarget* RenderTarget = InCanvas.GetRenderTarget();

	ENQUEUE_RENDER_COMMAND(CanvasRenderTargetResolveCommand)(
		[LocalSurfaceQueue, FramePayload, Callback, RenderTarget](FRHICommandListImmediate& RHICmdList) mutable
		{

			LocalSurfaceQueue->OnRenderTargetReady_RenderThread(RenderTarget->GetRenderTargetTexture(), FramePayload, MoveTemp(Callback));
		});
}

void UStereoSphere::UpdateTelemetry(FMoviePipelineShotRenderTelemetry* InTelemetry) const
{
	InTelemetry->bUsesPanoramic = true;
	InTelemetry->bUsesPPMs |= Algo::AnyOf(AdditionalPostProcessMaterials, [](const FPanoramicPostProcessPass& Pass) { return Pass.bEnabled; });
}



void UStereoSphere_PathTracer::SetupImpl(const MoviePipeline::FMoviePipelineRenderPassInitSettings& InPassInitSettings)
{
	if (!CheckIfPathTracerIsSupported())
	{
		UE_LOG(LogMovieRenderPipeline, Error, TEXT("Cannot render a Path Tracer, Path Tracer is not enabled by this project."));
		GetPipeline()->Shutdown(true);
		return;
	}
	Super::SetupImpl(InPassInitSettings);
}


void UStereoSphere_PathTracer::ValidateStateImpl()
{
	Super::ValidateStateImpl();
	PathTracerValidationImpl();
}

bool UStereoSphere::CheckIfPathTracerIsSupported() const
{
	bool bSupportsPathTracing = false;
	if (IsRayTracingEnabled())
	{
		IConsoleVariable* PathTracingCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.PathTracing"));
		if (PathTracingCVar)
		{
			bSupportsPathTracing = PathTracingCVar->GetInt() != 0;
		}
	}
	return bSupportsPathTracing;
}


void UStereoSphere::PathTracerValidationImpl()
{
	const bool bSupportsPathTracing = CheckIfPathTracerIsSupported();
	if (!bSupportsPathTracing)
	{
		const FText ValidationWarning = NSLOCTEXT("StereoSphere", "PathTracerValidation_Unsupported", "Path Tracing is currently not enabled for this project and this render pass will not work.");
		ValidationResults.Add(ValidationWarning);
		ValidationState = EMoviePipelineValidationState::Warnings;
	}
}





#if WITH_EDITOR
FText UStereoSphere::GetFooterText(UMoviePipelineExecutorJob* InJob) const
{
	FTextBuilder TextBuilder;
	if (bStereo)
	{
		TextBuilder.AppendLine(NSLOCTEXT(
			"StereoSphere",
			"StereoSphereSetting_FooterText_Stereo",
			"\nStereo Mode more OverlapPercentage will have a smoother effect, \n"
			"And more NumHorizontalSteps will have a smoother effect.\n"
			"If your can't output stereo frame, need change GI to Screen Space. \n"
		));
	}
	for (FPanoramicPostProcessPass AdditionalPass : AdditionalPostProcessMaterials)
	{

		if (AdditionalPass.bEnabled)
		{
			TextBuilder.AppendLine(NSLOCTEXT(
				"StereoSphere",
				"StereoSphereSetting_FooterText_Materials",
				"PostProcess Materials Layers does not support Anti-Aliasing.\n"
			));
			break;
		}
	}

	return TextBuilder.ToText();
}

FText UStereoSphere_PathTracer::GetDisplayText() const
{
	return NSLOCTEXT("StereoSphere", "StereoSphereSetting_PathTracer", "StereoSphere Path Tracer");
}

FText UStereoSphere_Unlit::GetDisplayText() const
{
	return NSLOCTEXT("StereoSphere", "StereoSphereSetting_Unlit", "StereoSphere (Unlit)");
}

FText UStereoSphere_DetailLighting::GetDisplayText() const
{
	return NSLOCTEXT("StereoSphere", "StereoSphereSetting_DetailLighting", "StereoSphere (Detail Lighting)");
}

FText UStereoSphere_LightingOnly::GetDisplayText() const
{
	return NSLOCTEXT("StereoSphere", "StereoSphereSetting_LightingOnly", "StereoSphere (Lighting Only)");
}

FText UStereoSphere_ReflectionsOnly::GetDisplayText() const
{
	return NSLOCTEXT("StereoSphere", "StereoSphereSetting_ReflectionsOnly", "StereoSphere (Reflections Only)");
}

#endif

#undef  LOCTEXT_NAMESPACE