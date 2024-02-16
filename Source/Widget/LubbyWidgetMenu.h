// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GamePlay/SaveGameData.h"
#include "LubbyWidgetMenu.generated.h"

/**
 * 
 */
UCLASS()
class WIDGET_API ULubbyWidgetMenu : public UUserWidget
{
	GENERATED_BODY()
protected :
	UFUNCTION(Client, Unreliable)
	virtual void UpdatePlayerWindow(FPlayerInfo Playerinfo);
public :
	UFUNCTION()
	void ClearPlayerList();

};
