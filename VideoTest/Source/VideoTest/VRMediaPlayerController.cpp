#include "VRMediaPlayerController.h"
#include "VRMediaSphere.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "EngineUtils.h"
#include "InputCoreTypes.h"

AVRMediaPlayerController::AVRMediaPlayerController()
{
    bShowMouseCursor = false;
}

void AVRMediaPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // ��� ���� (������ 1�� �ִٰ� ����)
    MediaActor = FindMediaSphere();

    // 1) ��Ÿ�� IMC/IA ����
    IMC_Runtime = NewObject<UInputMappingContext>(this, TEXT("IMC_VRMedia_Runtime"));

    IA_PlayPause = NewObject<UInputAction>(this, TEXT("IA_PlayPause"));
    IA_ToggleHemisphere = NewObject<UInputAction>(this, TEXT("IA_ToggleHemisphere"));
    IA_SeekForward = NewObject<UInputAction>(this, TEXT("IA_SeekForward"));
    IA_SeekBackward = NewObject<UInputAction>(this, TEXT("IA_SeekBackward"));

    IA_PlayPause->ValueType = EInputActionValueType::Boolean;
    IA_ToggleHemisphere->ValueType = EInputActionValueType::Boolean;
    IA_SeekForward->ValueType = EInputActionValueType::Boolean;
    IA_SeekBackward->ValueType = EInputActionValueType::Boolean;

    // 2) Ű ���� (�ʿ� �� VR ��Ʈ�ѷ��� ��ü)
    IMC_Runtime->MapKey(IA_PlayPause, EKeys::SpaceBar);
    IMC_Runtime->MapKey(IA_ToggleHemisphere, EKeys::One);     // '1'
    IMC_Runtime->MapKey(IA_SeekForward, EKeys::Right);
    IMC_Runtime->MapKey(IA_SeekBackward, EKeys::Left);

    // 3) LocalPlayer Subsystem�� IMC �߰�
    if (ULocalPlayer* LP = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsys = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            Subsys->ClearAllMappings();
            Subsys->AddMappingContext(IMC_Runtime, 0);
        }
    }

    // 4) ���ε�
    if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
    {
        EIC->BindAction(IA_PlayPause, ETriggerEvent::Started, this, &AVRMediaPlayerController::OnPlayPauseStarted);
        EIC->BindAction(IA_ToggleHemisphere, ETriggerEvent::Started, this, &AVRMediaPlayerController::OnToggleHemisphereStarted);
        EIC->BindAction(IA_SeekForward, ETriggerEvent::Started, this, &AVRMediaPlayerController::OnSeekForwardStarted);
        EIC->BindAction(IA_SeekBackward, ETriggerEvent::Started, this, &AVRMediaPlayerController::OnSeekBackwardStarted);
    }
}

AVRMediaSphere* AVRMediaPlayerController::FindMediaSphere() const
{
    for (TActorIterator<AVRMediaSphere> It(GetWorld()); It; ++It)
    {
        return *It;
    }
    return nullptr;
}

void AVRMediaPlayerController::OnPlayPauseStarted(const FInputActionInstance&)
{
    if (MediaActor) MediaActor->TogglePlayPause();
}

void AVRMediaPlayerController::OnToggleHemisphereStarted(const FInputActionInstance&)
{
    if (MediaActor) MediaActor->ToggleHemisphere();
}

void AVRMediaPlayerController::OnSeekForwardStarted(const FInputActionInstance&)
{
    if (MediaActor) MediaActor->SeekSeconds(+5);
}

void AVRMediaPlayerController::OnSeekBackwardStarted(const FInputActionInstance&)
{
    if (MediaActor) MediaActor->SeekSeconds(-5);
}
