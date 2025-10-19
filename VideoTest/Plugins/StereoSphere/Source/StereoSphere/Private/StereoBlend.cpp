
#include "StereoBlend.h"
#include "StereoSphere.h"
#include "ImageWriteTask.h"
#include "MovieRenderPipelineDataTypes.h"

#define LOCTEXT_NAMESPACE "PanramicText"


FStereoBlend::FStereoBlend(TSharedPtr<MoviePipeline::IMoviePipelineOutputMerger> InOutputMerger, const FCombineSettings& CombineSettings, FIntPoint InOutputResolution)
	:OutputMerger(InOutputMerger)
{
	bStereo = CombineSettings.bStereo;
	SampingMethod = CombineSettings.SampingMethod;
	SurroundingType = CombineSettings.SurroundingType;
	AlignType = CombineSettings.AlignType;
	OutputEquirectangularMapSize = InOutputResolution;
}


static FLinearColor GetColorBilinearFiltered(const FImagePixelData* InSampleData, const FVector2D& InSamplePixelCoords, bool& OutClipped)
{

	FVector2D PixelCoordinateIndex = InSamplePixelCoords - 0.5f;
	FIntPoint PixelCoordinateCell = FIntPoint(FMath::FloorToInt32(PixelCoordinateIndex.X), FMath::FloorToInt32(PixelCoordinateIndex.Y));
	FVector2D Offset = PixelCoordinateIndex - PixelCoordinateCell;

	FIntPoint LowerLeftPixelIndex = PixelCoordinateCell;
	FIntPoint LowerRightPixelIndex = FIntPoint(LowerLeftPixelIndex + FIntPoint(1, 0));
	FIntPoint UpperLeftPixelIndex = FIntPoint(LowerLeftPixelIndex + FIntPoint(0, 1));
	FIntPoint UpperRightPixelIndex = FIntPoint(LowerLeftPixelIndex + FIntPoint(1, 1));


	auto ClampPixelCoords = [&](FIntPoint& InOutPixelCoords, const FIntPoint& InArraySize)
		{
			if (InOutPixelCoords.X > InArraySize.X - 1 ||
				InOutPixelCoords.Y > InArraySize.Y - 1 ||
				InOutPixelCoords.X < 0 ||
				InOutPixelCoords.Y < 0)
			{
				OutClipped = true;
			}
			InOutPixelCoords = FIntPoint(FMath::Clamp(InOutPixelCoords.X, 0, InArraySize.X - 1), FMath::Clamp(InOutPixelCoords.Y, 0, InArraySize.Y - 1));
		};

	ClampPixelCoords(LowerLeftPixelIndex, InSampleData->GetSize());
	ClampPixelCoords(LowerRightPixelIndex, InSampleData->GetSize());
	ClampPixelCoords(UpperLeftPixelIndex, InSampleData->GetSize());
	ClampPixelCoords(UpperRightPixelIndex, InSampleData->GetSize());



	FLinearColor LowerLeftPixelColor;
	FLinearColor LowerRightPixelColor;
	FLinearColor UpperLeftPixelColor;
	FLinearColor UpperRightPixelColor;

	int64 SizeInBytes = 0;
	const void* SrcRawDataPtr = nullptr;
	InSampleData->GetRawData(SrcRawDataPtr, SizeInBytes);


	switch (InSampleData->GetType())
	{
	case EImagePixelType::Color:
	{
		const FColor* ColorData = static_cast<const FColor*>(SrcRawDataPtr);
		LowerLeftPixelColor = FLinearColor(ColorData[LowerLeftPixelIndex.X + (LowerLeftPixelIndex.Y * InSampleData->GetSize().X)]);
		LowerRightPixelColor = FLinearColor(ColorData[LowerRightPixelIndex.X + (LowerRightPixelIndex.Y * InSampleData->GetSize().X)]);
		UpperLeftPixelColor = FLinearColor(ColorData[UpperLeftPixelIndex.X + (UpperLeftPixelIndex.Y * InSampleData->GetSize().X)]);
		UpperRightPixelColor = FLinearColor(ColorData[UpperRightPixelIndex.X + (UpperRightPixelIndex.Y * InSampleData->GetSize().X)]);
	}
	case EImagePixelType::Float16:
	{
		const FFloat16Color* ColorDataF16 = static_cast<const FFloat16Color*>(SrcRawDataPtr);
		LowerLeftPixelColor = FLinearColor(ColorDataF16[LowerLeftPixelIndex.X + (LowerLeftPixelIndex.Y * InSampleData->GetSize().X)]);
		LowerRightPixelColor = FLinearColor(ColorDataF16[LowerRightPixelIndex.X + (LowerRightPixelIndex.Y * InSampleData->GetSize().X)]);
		UpperLeftPixelColor = FLinearColor(ColorDataF16[UpperLeftPixelIndex.X + (UpperLeftPixelIndex.Y * InSampleData->GetSize().X)]);
		UpperRightPixelColor = FLinearColor(ColorDataF16[UpperRightPixelIndex.X + (UpperRightPixelIndex.Y * InSampleData->GetSize().X)]);
	}
	break;
	case EImagePixelType::Float32:
	{
		const FLinearColor* ColorDataF32 = static_cast<const FLinearColor*>(SrcRawDataPtr);
		LowerLeftPixelColor = ColorDataF32[LowerLeftPixelIndex.X + (LowerLeftPixelIndex.Y * InSampleData->GetSize().X)];
		LowerRightPixelColor = ColorDataF32[LowerRightPixelIndex.X + (LowerRightPixelIndex.Y * InSampleData->GetSize().X)];
		UpperLeftPixelColor = ColorDataF32[UpperLeftPixelIndex.X + (UpperLeftPixelIndex.Y * InSampleData->GetSize().X)];
		UpperRightPixelColor = ColorDataF32[UpperRightPixelIndex.X + (UpperRightPixelIndex.Y * InSampleData->GetSize().X)];
	}
	break;
	default:

		checkNoEntry();
	}


	FLinearColor InterpolatedPixelColor = FMath::BiLerp(LowerLeftPixelColor, LowerRightPixelColor, UpperLeftPixelColor, UpperRightPixelColor, Offset.X, Offset.Y);
	return InterpolatedPixelColor;
}

static FLinearColor GetPixelColor(const FImagePixelData* InSampleData, FIntPoint PixelCoordinate, bool& OutClipped)
{
	FLinearColor FinalColor;
	auto ClampPixelCoords = [&](FIntPoint& InOutPixelCoords, const FIntPoint& InArraySize)
		{
			if (InOutPixelCoords.X > InArraySize.X - 1 ||
				InOutPixelCoords.Y > InArraySize.Y - 1 ||
				InOutPixelCoords.X < 0 ||
				InOutPixelCoords.Y < 0)
			{
				OutClipped = true;
			}
			InOutPixelCoords = FIntPoint(FMath::Clamp(InOutPixelCoords.X, 0, InArraySize.X - 1), FMath::Clamp(InOutPixelCoords.Y, 0, InArraySize.Y - 1));
		};
	ClampPixelCoords(PixelCoordinate, InSampleData->GetSize());
	int64 SizeInBytes = 0;
	const void* SrcRawDataPtr = nullptr;
	InSampleData->GetRawData(SrcRawDataPtr, SizeInBytes);
	switch (InSampleData->GetType())
	{
	case EImagePixelType::Color:
	{
		const FColor* ColorData = static_cast<const FColor*>(SrcRawDataPtr);
		FinalColor = FLinearColor(ColorData[PixelCoordinate.X + (PixelCoordinate.Y * InSampleData->GetSize().X)]);
	}
	break;
	case EImagePixelType::Float16:
	{
		const FFloat16Color* ColorDataF16 = static_cast<const FFloat16Color*>(SrcRawDataPtr);
		FinalColor = FLinearColor(ColorDataF16[PixelCoordinate.X + (PixelCoordinate.Y * InSampleData->GetSize().X)]);
	}
	break;
	case EImagePixelType::Float32:
	{
		const FLinearColor* ColorDataF32 = static_cast<const FLinearColor*>(SrcRawDataPtr);
		FinalColor = ColorDataF32[PixelCoordinate.X + (PixelCoordinate.Y + InSampleData->GetSize().X)];
	}
	break;
	default:
		check(0);
	}
	return FinalColor;
}


static FLinearColor GetColorBicubicFiltered(const FImagePixelData* InSampleData, const FVector2D& InSamplePixelCoords, bool& OutClipped)
{
	FVector2D PixelCoordinateIndex = InSamplePixelCoords - 0.5f;
	FIntPoint PixelCoordinateCell = FIntPoint(FMath::FloorToInt32(PixelCoordinateIndex.X), FMath::FloorToInt32(PixelCoordinateIndex.Y));
	FVector2D Offset = PixelCoordinateIndex - PixelCoordinateCell;
	FLinearColor PixelSplineX[4][4]{};
	for (int32 s = 0; s < 4; s++)
	{
		for (int32 x = 0; x < 4; x++)
		{
			PixelSplineX[s][x] = GetPixelColor(InSampleData, PixelCoordinateCell + FIntPoint(x - 1, s - 1), OutClipped);
		}
	}

	FVector2D VT = Offset;
	FVector2D VTT = VT * VT;
	FVector2D VTTT = VTT * VT;

	FVector2D VQ1 = 0.5f * (-VTTT + 2.0f * VTT - VT);
	FVector2D VQ2 = 0.5f * (3.0f * VTTT - 5.0f * VTT + FVector2d(2.0f, 2.f));
	FVector2D VQ3 = 0.5f * (-3.0f * VTTT + 4.0f * VTT + VT);
	FVector2D VQ4 = 0.5f * (VTTT - VTT);

	FLinearColor PixelSplineY[4]{};
	for (int32 s = 0; s < 4; s++)
	{
		PixelSplineY[s] = (PixelSplineX[s][0] * VQ1.X + PixelSplineX[s][1] * VQ2.X + PixelSplineX[s][2] * VQ3.X + PixelSplineX[s][3] * VQ4.X);
	}
	FLinearColor InterpolatedPixelColor = (PixelSplineY[0] * VQ1.Y + PixelSplineY[1] * VQ2.Y + PixelSplineY[2] * VQ3.Y + PixelSplineY[3] * VQ4.Y).GetClamped();;
	return InterpolatedPixelColor;
}


DECLARE_CYCLE_STAT(TEXT("STAT_MoviePipeline_PanoBlend"), STAT_MoviePipeline_PanoBlend, STATGROUP_MoviePipeline);


void FStereoBlend::OnCompleteRenderPassDataAvailable_AnyThread(TUniquePtr<FImagePixelData>&& InData)
{
	SCOPE_CYCLE_COUNTER(STAT_MoviePipeline_PanoBlend);






	TSharedPtr<FPanoramicImageOutputMap> PanoramicImageOutputMap = nullptr;

	TSharedPtr<FPanoramicOutputFrame> OutputFrame = nullptr;

	TSharedPtr<FPanoramicBlendData> BlendDataTarget = nullptr;


	FPanoramicImagePixelDataPayload* DataPayload = InData->GetPayload<FPanoramicImagePixelDataPayload>();
	check(DataPayload);


	FIntPoint SampleSize = DataPayload->Pane.Resolution;
	FRotator SampleRotation = DataPayload->Pane.RelativeRotation;

	const float SampleHalfHorizontalFoVDegrees = 0.5f * DataPayload->Pane.HorizontalFieldOfView;
	const float SampleHalfVerticalFoVDegrees = 0.5f * DataPayload->Pane.VerticalFieldOfView;

	const float SampleHalfHorizontalFoVCosine = FMath::Cos(FMath::DegreesToRadians(SampleHalfHorizontalFoVDegrees));
	const float SampleHalfVerticalFoVCosine = FMath::Cos(FMath::DegreesToRadians(SampleHalfVerticalFoVDegrees));

	const float SampleYawRad = FMath::DegreesToRadians(SampleRotation.Yaw);
	const float SamplePitchRad = FMath::DegreesToRadians(SampleRotation.Pitch);

	const FVector SampleDirectionOnTheta = FVector(FMath::Cos(SampleYawRad), FMath::Sin(SampleYawRad), 0);
	const FVector SampleDirectionOnPhi = FVector(FMath::Cos(SamplePitchRad), 0.f, FMath::Sin(SamplePitchRad));


	const FMatrix SampleProjectionMatrix = FReversedZPerspectiveMatrix(FMath::DegreesToRadians(SampleHalfHorizontalFoVDegrees), SampleSize.X, SampleSize.Y, DataPayload->Pane.NearClippingPlane);




	float EquiRectMapThetaStep;
	const float EquiRectMapPhiStep = 180.f / (float)OutputEquirectangularMapSize.Y;
	int32 PixelIndexHorzMinBound;
	int32 PixelIndexHorzMaxBound;
	int32 PixelIndexVertMinBound;
	int32 PixelIndexVertMaxBound;
	if (SurroundingType == ESurroundingType::OmniDirectional)
	{
		EquiRectMapThetaStep = 360.f / (float)OutputEquirectangularMapSize.X;
	}
	else
	{
		EquiRectMapThetaStep = 180.f / (float)OutputEquirectangularMapSize.X;
	}

	if (bStereo && SurroundingType == ESurroundingType::OmniDirectional)
	{
		float SampleYawMin = SampleRotation.Yaw - SampleHalfHorizontalFoVDegrees;
		float SampleYawMax = SampleRotation.Yaw + SampleHalfHorizontalFoVDegrees;
		PixelIndexHorzMinBound = FMath::FloorToInt(((SampleYawMin)+180.f) / EquiRectMapThetaStep);
		PixelIndexHorzMaxBound = FMath::FloorToInt(((SampleYawMax)+180.f) / EquiRectMapThetaStep);
		float SamplePitchMin = FMath::Max(SampleRotation.Pitch - SampleHalfVerticalFoVDegrees, -90.f);
		float SamplePitchMax = FMath::Min(SampleRotation.Pitch + SampleHalfVerticalFoVDegrees, 90.f);
		PixelIndexVertMinBound = FMath::Max((OutputEquirectangularMapSize.Y) - FMath::FloorToInt((SamplePitchMax + 90.f) / EquiRectMapPhiStep), 0);
		PixelIndexVertMaxBound = FMath::Min((OutputEquirectangularMapSize.Y) - FMath::FloorToInt((SamplePitchMin + 90.f) / EquiRectMapPhiStep), OutputEquirectangularMapSize.Y);
	}
	else
	{


		PixelIndexHorzMinBound = 0;
		PixelIndexHorzMaxBound = OutputEquirectangularMapSize.X;

		float SamplePitchMin = FMath::Max(SampleRotation.Pitch - SampleHalfVerticalFoVDegrees, -90.f);
		float SamplePitchMax = FMath::Min(SampleRotation.Pitch + SampleHalfVerticalFoVDegrees, 90.f);
		PixelIndexVertMinBound = FMath::Max((OutputEquirectangularMapSize.Y) - FMath::FloorToInt((SamplePitchMax + 90.f) / EquiRectMapPhiStep), 0);
		PixelIndexVertMaxBound = FMath::Min((OutputEquirectangularMapSize.Y) - FMath::FloorToInt((SamplePitchMin + 90.f) / EquiRectMapPhiStep), OutputEquirectangularMapSize.Y);
	}


	{
		FScopeLock ScopeLock(&GlobalQueueDataMutex);
		for (TPair<FMoviePipelineFrameOutputState, TSharedPtr<FPanoramicImageOutputMap>>& KVP : PendingData)
		{

			if (KVP.Key.OutputFrameNumber == DataPayload->SampleState.OutputState.OutputFrameNumber)
			{

				PanoramicImageOutputMap = KVP.Value;
			}
		}

		if (!PanoramicImageOutputMap)
		{

			PanoramicImageOutputMap = PendingData.Add(DataPayload->SampleState.OutputState, MakeShared<FPanoramicImageOutputMap>());
		}

		for (TPair<FMoviePipelinePassIdentifier, TSharedPtr<FPanoramicOutputFrame>>& KVP : PanoramicImageOutputMap->ImageOutputData)
		{

			if (KVP.Key == DataPayload->PassIdentifier)
			{
				OutputFrame = KVP.Value;
			}
		}

		if (!OutputFrame)
		{
			OutputFrame = PanoramicImageOutputMap->ImageOutputData.Add(DataPayload->PassIdentifier, MakeShared<FPanoramicOutputFrame>());
			int32 EyeMultiplier = DataPayload->Pane.EyeIndex == -1 ? 1 : 2;
			int32 TotalSampleCount = DataPayload->Pane.NumHorizontalSteps * DataPayload->Pane.NumVerticalSteps * EyeMultiplier;
			OutputFrame->NumSamplesTotal = TotalSampleCount;
			{

				LLM_SCOPE_BYNAME(TEXT("MoviePipeline/PanoBlendFrameOutput"));


				OutputFrame->OutputEquirectangularMap.SetNumZeroed(OutputEquirectangularMapSize.X * OutputEquirectangularMapSize.Y * EyeMultiplier);
				OutputFrame->BlenderMaskArray.SetNumZeroed(OutputEquirectangularMapSize.X * OutputEquirectangularMapSize.Y * EyeMultiplier);
			}
		}
	}


	check(OutputFrame);
	{
		FScopeLock ScopeLock(&GlobalQueueDataMutex);
		BlendDataTarget = MakeShared<FPanoramicBlendData>();
		BlendDataTarget->EyeIndex = DataPayload->Pane.EyeIndex;
		BlendDataTarget->bFinished = false;
		BlendDataTarget->OriginalDataPayload = StaticCastSharedRef<FPanoramicImagePixelDataPayload>(DataPayload->Copy());

		TArray<TSharedPtr<FPanoramicBlendData>>& EyeArray = OutputFrame->BlendedData.FindOrAdd(DataPayload->Pane.EyeIndex);
		EyeArray.Add(BlendDataTarget);
	}



	int32 CountY = PixelIndexVertMaxBound - PixelIndexVertMinBound;
	ParallelFor(CountY, [PixelIndexHorzMinBound, PixelIndexHorzMaxBound, PixelIndexVertMinBound, EquiRectMapThetaStep,
		EquiRectMapPhiStep, SampleRotation, SampleDirectionOnTheta, SampleDirectionOnPhi, SampleHalfHorizontalFoVCosine, SampleHalfVerticalFoVCosine,
		SampleProjectionMatrix, SampleSize,
		Size = this->OutputEquirectangularMapSize, Type = this->SurroundingType, Stereo = this->bStereo, Align = this->AlignType,
		&InData, BlendDataTarget, DataPayload, &OutputFrame](int32 PixelIndexY)
		{
			for (int32 X = PixelIndexHorzMinBound; X < PixelIndexHorzMaxBound; X++)
			{
				const int32 OutputPixelX = ((X % Size.X) + Size.X) % Size.X;
				const int32 OutputPixelY = PixelIndexY + PixelIndexVertMinBound;
				float Theta;

				if (Type == ESurroundingType::Hemisphere)
				{
					Theta = EquiRectMapThetaStep * (((float)OutputPixelX) + 0.5f) - 90.f;
				}
				else
				{
					Theta = EquiRectMapThetaStep * (((float)OutputPixelX) + 0.5f) - 180.f;
				}

				const float Phi = EquiRectMapPhiStep * (((float)Size.Y - OutputPixelY) + 0.5f) - 90.f;

				const float ThetaDeg = FMath::DegreesToRadians(Theta);
				const float PhiDeg = FMath::DegreesToRadians(Phi);
				const FVector OutputDirection(FMath::Cos(PhiDeg) * FMath::Cos(ThetaDeg), FMath::Cos(PhiDeg) * FMath::Sin(ThetaDeg), FMath::Sin(PhiDeg));

				FVector4 DirectionInSampleWorldSpace = FVector4(SampleRotation.UnrotateVector(OutputDirection), 1.0f);

				float WeightTheta;
				float WeightPhi;
				if (Stereo && Type == ESurroundingType::OmniDirectional)
				{
					const FVector OutputDirectionTheta = FVector(FMath::Cos(ThetaDeg), FMath::Sin(ThetaDeg), 0);
					const FVector OutputDirectionPhi = FVector(FMath::Cos(PhiDeg), 0.f, FMath::Sin(PhiDeg));
					const float DirectionThetaDot = FVector::DotProduct(OutputDirectionTheta, SampleDirectionOnTheta);
					const float DirectionPhiDot = FVector::DotProduct(OutputDirectionPhi, SampleDirectionOnPhi);
					WeightTheta = FMath::Max(DirectionThetaDot - SampleHalfHorizontalFoVCosine, 0.0f) / (1.0f - SampleHalfHorizontalFoVCosine);
					WeightPhi = FMath::Max(DirectionPhiDot - SampleHalfVerticalFoVCosine, 0.0f) / (1.0f - SampleHalfVerticalFoVCosine);
				}
				else
				{
					FRotator DirectionRotator = DirectionInSampleWorldSpace.Rotation();
					float DirectionYaw = FMath::DegreesToRadians(DirectionRotator.Yaw);
					float DirectionPitch = FMath::DegreesToRadians(DirectionRotator.Pitch);
					WeightTheta = FMath::Max(FMath::Cos(DirectionYaw) - SampleHalfHorizontalFoVCosine, 0.0f) / (1.0f - SampleHalfHorizontalFoVCosine);
					WeightPhi = FMath::Max(FMath::Cos(DirectionPitch) - SampleHalfVerticalFoVCosine, 0.0f) / (1.0f - SampleHalfVerticalFoVCosine);
				}
				const float SampleWeight = WeightTheta * WeightPhi;
				const float SampleWeightSquared = SampleWeight * SampleWeight;

				if (SampleWeightSquared > KINDA_SMALL_NUMBER)
				{
					static const FMatrix UnrealCoordinateConversion = FMatrix(
						FPlane(0, 0, 1, 0),
						FPlane(1, 0, 0, 0),
						FPlane(0, 1, 0, 0),
						FPlane(0, 0, 0, 1));
					DirectionInSampleWorldSpace = UnrealCoordinateConversion.TransformFVector4(DirectionInSampleWorldSpace);
					FVector4 DirectionInSampleClipSpace = SampleProjectionMatrix.TransformFVector4(DirectionInSampleWorldSpace);
					FVector DirectionInSampleNDSpace = FVector(DirectionInSampleClipSpace) / DirectionInSampleClipSpace.W;


					FVector2D DirectionInSampleScreenSpace = ((FVector2D(DirectionInSampleNDSpace) + 1.0f) / 2.0f) * FVector2D(SampleSize.X, SampleSize.Y);


					DirectionInSampleScreenSpace.Y = ((float)SampleSize.Y - DirectionInSampleScreenSpace.Y) - 1.0f;

					bool bClipped = false;
					FLinearColor SampleColor = GetColorBilinearFiltered(InData.Get(), DirectionInSampleScreenSpace, bClipped);
					if (!bClipped)
					{
						int32 EyeOffset = 0;
						if (DataPayload->Pane.EyeIndex != -1)
						{
							if (Align == EAlignType::Top_Bottom)
							{
								EyeOffset = (Size.X * Size.Y) * BlendDataTarget->OriginalDataPayload->Pane.EyeIndex;
							}
							else
							{
								EyeOffset = Size.X * BlendDataTarget->OriginalDataPayload->Pane.EyeIndex;
							}
						}
						int32 DestIndex;
						if (Align == EAlignType::Top_Bottom)
						{
							DestIndex = OutputPixelX + (OutputPixelY * Size.X);
						}
						else
						{
							DestIndex = OutputPixelX + (OutputPixelY * Size.X * 2);
						}
						OutputFrame->OutputEquirectangularMap[DestIndex + EyeOffset] += SampleColor * SampleWeightSquared;
						OutputFrame->BlenderMaskArray[DestIndex + EyeOffset] += SampleWeightSquared;;
					}
				}
			}
		});



	bool bIsLastSample = false;
	{
		FScopeLock ScopeLock(&GlobalQueueDataMutex);

		BlendDataTarget->bFinished = true;


		int32 NumFinishedSamples = 0;


		for (TPair<int32, TArray<TSharedPtr<FPanoramicBlendData>>>& KVP : OutputFrame->BlendedData)
		{

			for (int32 Index = 0; Index < KVP.Value.Num(); Index++)
			{
				NumFinishedSamples += KVP.Value[Index]->bFinished ? 1 : 0;
			}
		}
		bIsLastSample = NumFinishedSamples == OutputFrame->NumSamplesTotal;
	}


	if (bIsLastSample)
	{
		{

			for (int32 PixelIndex = 0; PixelIndex < OutputFrame->OutputEquirectangularMap.Num(); PixelIndex++)
			{
				FLinearColor& Pixel = OutputFrame->OutputEquirectangularMap[PixelIndex];
				float& AlphaNum = OutputFrame->BlenderMaskArray[PixelIndex];
				Pixel.R /= AlphaNum;
				Pixel.G /= AlphaNum;
				Pixel.B /= AlphaNum;
				Pixel.A /= AlphaNum;
			}
		}
		TSharedRef<FImagePixelDataPayload, ESPMode::ThreadSafe> NewPayload = DataPayload->Copy();

		int32 OutputSizeX;
		int32 OutputSizeY;
		if (AlignType == EAlignType::Top_Bottom)
		{
			OutputSizeX = OutputEquirectangularMapSize.X;
			OutputSizeY = DataPayload->Pane.EyeIndex >= 0 ? OutputEquirectangularMapSize.Y * 2 : OutputEquirectangularMapSize.Y;
		}
		else
		{
			OutputSizeX = DataPayload->Pane.EyeIndex >= 0 ? OutputEquirectangularMapSize.X * 2 : OutputEquirectangularMapSize.X;
			OutputSizeY = OutputEquirectangularMapSize.Y;
		}

		TUniquePtr<TImagePixelData<FLinearColor>> FinalPixelData = MakeUnique<TImagePixelData<FLinearColor>>(FIntPoint(OutputSizeX, OutputSizeY), TArray64<FLinearColor>(MoveTemp(OutputFrame->OutputEquirectangularMap)), NewPayload);

		if (ensure(OutputMerger.IsValid()))
		{
			OutputMerger.Pin()->OnCompleteRenderPassDataAvailable_AnyThread(MoveTemp(FinalPixelData));
		}

		PanoramicImageOutputMap->ImageOutputData.Remove(DataPayload->PassIdentifier);
		if (PanoramicImageOutputMap->ImageOutputData.Num() == 0)
		{
			PendingData.Remove(DataPayload->SampleState.OutputState);
		}
	}
}

void FStereoBlend::OnSingleSampleDataAvailable_AnyThread(TUniquePtr<FImagePixelData>&& InData)
{

	ensure(OutputMerger.IsValid());

	OutputMerger.Pin()->OnSingleSampleDataAvailable_AnyThread(MoveTemp(InData));
}





static FMoviePipelineMergerOutputFrame MoviePipelineDummyOutputFrame;
FMoviePipelineMergerOutputFrame& FStereoBlend::QueueOutputFrame_GameThread(const FMoviePipelineFrameOutputState& CachedOutputState)
{
	check(0);
	return  MoviePipelineDummyOutputFrame;
}

void FStereoBlend::AbandonOutstandingWork()
{

	check(0);
}

FStereoBlend::~FStereoBlend()
{
	PendingData.Empty(0);
}

#undef LOCTEXT_NAMESPACE