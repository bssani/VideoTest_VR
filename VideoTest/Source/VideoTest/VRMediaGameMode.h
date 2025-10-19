#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VRMediaGameMode.generated.h"

UCLASS()
class VIDEOTEST_API AVRMediaGameMode : public AGameModeBase
{
    GENERATED_BODY()
public:
    AVRMediaGameMode();
    virtual void BeginPlay() override;
};
