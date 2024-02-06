// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidgetPool.h"
#include "GameHUDBase.generated.h"

UENUM(BlueprintType)
enum class EWidgetName : uint8
{
	HostMenu,
	ServerMenu,
	OptionMenu,
};

UCLASS()
class WIDGET_API AGameHUDBase : public AHUD
{
	GENERATED_BODY()

	AGameHUDBase();
protected:
	virtual void BeginPlay();

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<class UUserWidget> MainMenuClass = nullptr;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<class UUserWidget> HostMenuClass = nullptr;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<class UUserWidget> ServerMenuClass = nullptr;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<class UUserWidget> OptionMenuClass = nullptr;

public:
	FUserWidgetPool GameWidgetPool;

	UFUNCTION()
	void CreateMainMenuWidget();

	UFUNCTION()
	void CreateWidget(EWidgetName Name);

	UFUNCTION()
	UUserWidget* CheckWidgetPool(TSubclassOf<class UUserWidget> CheckWidget);

	UFUNCTION()
	TSubclassOf<class UUserWidget> CheckWidgetClass(EWidgetName Name);
};
