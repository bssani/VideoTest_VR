
#pragma once

#include "MoviePipelineImagePassBase.h"
#include "MovieRenderPipelineDataTypes.h"
#include "StereoSphere.h"


struct FImagePixelData;
class UMoviePipeline;

class FStereoBlend : public MoviePipeline::IMoviePipelineOutputMerger
{
public:
	FStereoBlend(TSharedPtr<MoviePipeline::IMoviePipelineOutputMerger> InOutputMerger, const FCombineSettings& CombineSettings, const FIntPoint InOutputResolution);
	~FStereoBlend();

public:
	virtual FMoviePipelineMergerOutputFrame& QueueOutputFrame_GameThread(const FMoviePipelineFrameOutputState& CachedOutputState) override;
	virtual void OnCompleteRenderPassDataAvailable_AnyThread(TUniquePtr<FImagePixelData>&& InData) override;
	virtual void OnSingleSampleDataAvailable_AnyThread(TUniquePtr<FImagePixelData>&& InData) override;
	virtual void AbandonOutstandingWork() override;
	virtual int32 GetNumOutstandingFrames() const override
	{
		UE_LOG(LogMovieRenderPipeline, Warning, TEXT("have been done!"));
		return PendingData.Num();
	}


private:
	struct FPanoramicBlendData
	{
		bool bFinished;
		int32 EyeIndex;
		TSharedPtr<struct FPanoramicImagePixelDataPayload> OriginalDataPayload;
	};


	struct FPanoramicOutputFrame
	{

		TMap<int32, TArray<TSharedPtr<FPanoramicBlendData>>> BlendedData;


		int32 NumSamplesTotal;


		TArray<FLinearColor> OutputEquirectangularMap;

		TArray<float> BlenderMaskArray;
	};


	struct FPanoramicImageOutputMap
	{
		TMap<FMoviePipelinePassIdentifier, TSharedPtr<FPanoramicOutputFrame>> ImageOutputData;
	};

	TMap<FMoviePipelineFrameOutputState, TSharedPtr<FPanoramicImageOutputMap>> PendingData;


	FCriticalSection GlobalQueueDataMutex;


	FIntPoint OutputEquirectangularMapSize;


	TWeakPtr<MoviePipeline::IMoviePipelineOutputMerger> OutputMerger;


	ETextureSampingMethod SampingMethod;
	ESurroundingType SurroundingType;
	EAlignType AlignType;
	bool bStereo;

};