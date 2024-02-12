// Fill out your ccopyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MultiGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API AMultiGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	AMultiGameModeBase();

public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class USaveGameData> SaveGameClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USaveGameData* SaveDataInfo = nullptr;
};
