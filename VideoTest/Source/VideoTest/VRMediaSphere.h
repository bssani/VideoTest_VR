#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MediaPlayer.h"
#include "MediaSoundComponent.h"
#include "MediaTexture.h"
#include "FileMediaSource.h"
#include "VRMediaSphere.generated.h"

UENUM(BlueprintType)
enum class EVRStereoMode : uint8
{
    Mono        UMETA(DisplayName = "Mono"),
    SideBySide  UMETA(DisplayName = "SideBySide"),
    OverUnder   UMETA(DisplayName = "OverUnder")
};

UCLASS()
class VIDEOTEST_API AVRMediaSphere : public AActor
{
    GENERATED_BODY()
public:
    AVRMediaSphere(const FObjectInitializer& ObjectInitializer);

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

    // Components
    UPROPERTY(VisibleAnywhere, Category = "VRMedia|Components")
    UStaticMeshComponent* SphereMesh;

    UPROPERTY(VisibleAnywhere, Category = "VRMedia|Components")
    UMediaSoundComponent* MediaSound;

    // Runtime-created UObjects (BeginPlay에서 NewObject)
    UPROPERTY() UMediaPlayer* MediaPlayer;
    UPROPERTY() UMediaTexture* MediaTex;
    UPROPERTY() UFileMediaSource* FileSource;

    // Assets
    UPROPERTY(EditAnywhere, Category = "VRMedia|Mesh")
    UStaticMesh* FullSphereMesh;

    UPROPERTY(EditAnywhere, Category = "VRMedia|Mesh")
    UStaticMesh* HalfSphereMesh;

    UPROPERTY(EditAnywhere, Category = "VRMedia|Material")
    UMaterialInterface* BaseEquirectMaterial;

    UPROPERTY() UMaterialInstanceDynamic* MID;

    // Helpers
    void CreateMediaObjects();
    void InitMedia();
    bool OpenMedia(const FString& FilePath);

public:
    // Options
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VRMedia|Playback")
    FString VideoPath = TEXT("../../../VIDEOTEST/Content/VRMedia/Movies/demo_180.mp4");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VRMedia|Playback")
    bool bIs180 = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VRMedia|Playback")
    EVRStereoMode StereoMode = EVRStereoMode::Mono;

    // Controls (컨트롤러에서 호출)
    UFUNCTION(BlueprintCallable, Category = "VRMedia") void TogglePlayPause();
    UFUNCTION(BlueprintCallable, Category = "VRMedia") void ToggleHemisphere();
    UFUNCTION(BlueprintCallable, Category = "VRMedia") void SeekSeconds(int32 Seconds);

private:
    bool bRequestedPlay = false;
};
