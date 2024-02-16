// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidgetPool.h"
#include "GameHUDBase.generated.h"

UENUM(BlueprintType)
enum class EWidgetName : uint8
{
	MainMenu,
	HostMenu,
	ServerMenu,
	OptionMenu,
};

UCLASS()
class WIDGET_API AGameHUDBase : public AHUD
{
	GENERATED_BODY()

	AGameHUDBase();

	void GmaeBaseHudSetting();
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
	TArray<UUserWidget*> ActiveWidgetArray;
	FUserWidgetPool GameWidgetPool;

	UFUNCTION()
	void AddgWidget(EWidgetName Name);

	UFUNCTION()
	void RemoveArrayWidget(EWidgetName Name);

	UFUNCTION()
	void RemovePoolWidget(EWidgetName Name);

	UFUNCTION()
	UUserWidget* CheckWidgetPool(TSubclassOf<class UUserWidget> CheckWidget);

	UFUNCTION()
	UUserWidget* CheckWidgetArray(TSubclassOf<class UUserWidget> CheckWidget);

	UFUNCTION()
	TSubclassOf<class UUserWidget> CheckWidgetClass(EWidgetName Name);
};
