// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetBaseClass.generated.h"

class UButton;

USTRUCT(BlueprintType)
struct FMainMenu
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* FindButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* HostButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* OptionButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* QuitButton = nullptr;
};

/**
 * 
 */
UCLASS()
class WIDGET_API UUserWidgetBaseClass : public UUserWidget
{
	GENERATED_BODY()
private :
	UPROPERTY(VisibleAnywhere, Category = "Instance")
	class UGameInstanceBase* MyGameInstance;

	UFUNCTION()
	void CheckWidget();
protected :
	virtual void NativeOnInitialized();
	virtual void NativeConstruct() ;

public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMainMenu MainMenuEdit;

	UFUNCTION()
	void ClickFindButton();

	UFUNCTION()
	void ClickHostButton();

	UFUNCTION()
	void ClickOptionButton();

	UFUNCTION()
	void ClickQuitButton();
};
