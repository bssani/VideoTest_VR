#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "VRMediaPlayerController.generated.h"

class AVRMediaSphere;

UCLASS()
class VIDEOTEST_API AVRMediaPlayerController : public APlayerController
{
    GENERATED_BODY()
public:
    AVRMediaPlayerController();

protected:
    virtual void BeginPlay() override;

    // 런타임 생성 IMC/IA (에셋 없이 C++만으로 최소 구성)
    UPROPERTY() UInputMappingContext* IMC_Runtime;
    UPROPERTY() UInputAction* IA_PlayPause;
    UPROPERTY() UInputAction* IA_ToggleHemisphere;
    UPROPERTY() UInputAction* IA_SeekForward;
    UPROPERTY() UInputAction* IA_SeekBackward;

    // 제어 대상 액터
    UPROPERTY() AVRMediaSphere* MediaActor;

    // 핸들러
    void OnPlayPauseStarted(const FInputActionInstance& Instance);
    void OnToggleHemisphereStarted(const FInputActionInstance& Instance);
    void OnSeekForwardStarted(const FInputActionInstance& Instance);
    void OnSeekBackwardStarted(const FInputActionInstance& Instance);

    AVRMediaSphere* FindMediaSphere() const;
};
