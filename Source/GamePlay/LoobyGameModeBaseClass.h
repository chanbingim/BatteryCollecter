// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LoobyGameModeBaseClass.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API ALoobyGameModeBaseClass : public AGameModeBase
{
	GENERATED_BODY()

	ALoobyGameModeBaseClass();
public :
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void SwapCharacter(APlayerController* PlayerController, ACharacter* Characterclass, bool ChangedStatus);

	UFUNCTION(Server, Reliable)
	void EveryoneUpdate();
};
