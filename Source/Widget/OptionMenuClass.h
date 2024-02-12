// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GamePlay/SaveGameData.h"
#include "OptionMenuClass.generated.h"

class UImage;
class UButton;
class UEditableTextBox;

static FText SaveDataName;

USTRUCT(BlueprintType)
struct FOptionMenu{
	GENERATED_BODY()

public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UEditableTextBox* UserNameBox = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UImage* AvatorImage = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* RightButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* LeftButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* BackButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* AcceptButton = nullptr;
};


UCLASS()
class WIDGET_API UOptionMenuClass : public UUserWidget
{
	GENERATED_BODY()
private :
	int32 AvatorCount = 0;

	UPROPERTY()
	FPlayerInfo CharacterData;

	UPROPERTY(VisibleAnywhere, Category = "Instance")
	class UGameInstanceBase* MyGameInstance;

	UFUNCTION()
	void SaveGameCheck();

	UFUNCTION()
	void SetUpDisplay();

	UFUNCTION()
	void ChangedText(const FText& Text);

	UFUNCTION()
	void ClickedBackButton();

	UFUNCTION()
	void ClickedAcceptButton();

	UFUNCTION()
	void ClickedRightButton();

	UFUNCTION()
	void ClickedLeftButton();

	UFUNCTION()
	void CheckWidget();

	UFUNCTION()
	void LoadGame();

	UFUNCTION()
	void SaveGame();

protected :
	virtual void NativeOnInitialized();
	virtual void NativeConstruct();

public :

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UTexture2D *> Avators;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FOptionMenu OptionMenu;
};
