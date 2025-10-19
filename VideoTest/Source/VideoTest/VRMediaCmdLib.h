// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VRMediaCmdLib.generated.h"

/**
 * 
 */
UCLASS()
class VIDEOTEST_API UVRMediaCmdLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintPure, Category = "VRMedia")
    static bool GetCmdOptions(FString& OutVideo, bool& bOutIs180, FString& OutStereo);
};
