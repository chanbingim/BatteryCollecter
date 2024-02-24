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

private:
	UPROPERTY( BlueprintReadWrite, VisibleAnywhere, Category = "SERVERSETTING", meta = (AllowPrivateAccess = "true"))
	bool bCanStart = false;

protected:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps);
public :
	UPROPERTY(Replicated)
	TArray<APlayerController*> AllPlayerControllers;

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void SwapCharacter(APlayerController* PlayerController, ACharacter* Characterclass, bool ChangedStatus);

	UFUNCTION(Server, Reliable)
	void EveryoneUpdate();

	UFUNCTION()
	void LaunchTheGame();
};
