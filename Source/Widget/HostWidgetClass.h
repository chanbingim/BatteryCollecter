// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HostWidgetClass.generated.h"

class UButton;
class UTextBlock;
class UEditableTextBox;

USTRUCT(BlueprintType)
struct FHostMenu
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UEditableTextBox* EditableTextBox = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* DecreaseButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextBlock* ButtonText = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* IncreaseButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* DecreaseButton_2 = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextBlock* ButtonText_2 = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* IncreaseButton_2 = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* BackButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* AcceptButton = nullptr;
};

UCLASS()
class WIDGET_API UHostWidgetClass : public UUserWidget
{
	GENERATED_BODY()
private :
	UPROPERTY(VisibleAnywhere, Category = "Instance")
	class UGameInstanceBase* MyGameInstance;

	int32 PlayerOfNumber = 2;

	UFUNCTION()
	void CheckWidget();

	UFUNCTION()
	void AcceptButtonClicked();

	UFUNCTION()
	void BackButtonClicked();

	UFUNCTION()
	void DecreaseButtonClicked();

	UFUNCTION()
	void IncreaseButtonClicked();

	UFUNCTION()
	void Decrease2ButtonClicked();

	UFUNCTION()
	void Increase2ButtonClicked();
protected:
	virtual void NativeOnInitialized();
	virtual void NativeConstruct();
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FHostMenu HostMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxPlayerCount = 8;
};
