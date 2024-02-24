// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/SaveGameData.h"
#include "Blueprint/UserWidget.h"
#include "ConnectedPlayerClass.generated.h"

/**
 * 
 */
UCLASS()
class WIDGET_API UConnectedPlayerClass : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps);
	virtual void NativeOnInitialized();
	virtual void NativeConstruct();
public :
	UPROPERTY(Replicated)
	FPlayerInfo PlayerInfo;
};
