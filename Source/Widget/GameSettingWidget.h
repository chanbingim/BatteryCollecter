// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameSettingWidget.generated.h"

/**
 * 
 */
UCLASS()
class WIDGET_API UGameSettingWidget : public UUserWidget
{
	GENERATED_BODY()
public :
	UFUNCTION()
	void FillPlayerWindow();
};
