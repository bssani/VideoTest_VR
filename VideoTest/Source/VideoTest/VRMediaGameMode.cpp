#include "VRMediaGameMode.h"
#include "VRMediaPlayerController.h"
#include "VRMediaSphere.h"

AVRMediaGameMode::AVRMediaGameMode()
{
    PlayerControllerClass = AVRMediaPlayerController::StaticClass();
    DefaultPawnClass = nullptr; // HMD 뷰만 쓰면 Pawn 불필요
}

void AVRMediaGameMode::BeginPlay()
{
    Super::BeginPlay();
    //if (UWorld* World = GetWorld())
    //{
    //    FActorSpawnParameters Params;
    //    World->SpawnActor<AVRMediaSphere>(AVRMediaSphere::StaticClass(),
    //        FVector::ZeroVector, FRotator::ZeroRotator, Params);
    //}
}
