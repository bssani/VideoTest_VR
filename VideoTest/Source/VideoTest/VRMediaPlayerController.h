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

    // ��Ÿ�� ���� IMC/IA (���� ���� C++������ �ּ� ����)
    UPROPERTY() UInputMappingContext* IMC_Runtime;
    UPROPERTY() UInputAction* IA_PlayPause;
    UPROPERTY() UInputAction* IA_ToggleHemisphere;
    UPROPERTY() UInputAction* IA_SeekForward;
    UPROPERTY() UInputAction* IA_SeekBackward;

    // ���� ��� ����
    UPROPERTY() AVRMediaSphere* MediaActor;

    // �ڵ鷯
    void OnPlayPauseStarted(const FInputActionInstance& Instance);
    void OnToggleHemisphereStarted(const FInputActionInstance& Instance);
    void OnSeekForwardStarted(const FInputActionInstance& Instance);
    void OnSeekBackwardStarted(const FInputActionInstance& Instance);

    AVRMediaSphere* FindMediaSphere() const;
};
