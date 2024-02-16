// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API ALobbyPlayerController : public APlayerController
{
	GENERATED_BODY()

private :
	UFUNCTION(Client, Reliable)
	virtual void InitialSetUp();

public:
	UFUNCTION()
	void CheckSaveData();
};
