// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ServerMenuClass.generated.h"

class UButton;
class UWidgetSwitcher;
class UTextBlock;

USTRUCT(BlueprintType)
struct FServerMenu
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* RightButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* LeftButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* AccpetButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* BackButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetSwitcher* Siwtcher = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextBlock* LanTextBlock = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextBlock* CountTextBlock = nullptr;
};

UCLASS()
class WIDGET_API UServerMenuClass : public UUserWidget
{
	GENERATED_BODY()
private :
	UPROPERTY(VisibleAnywhere, Category = "Instance")
	class UGameInstanceBase* MyGameInstance;

	UPROPERTY()
	bool bFindSession = false;

	UFUNCTION()
	void CheckWidget();

	UFUNCTION()
	void ClickedRightButton();

	UFUNCTION()
	void ClickedLeftButton();

	UFUNCTION()
	void ClickedBackButton();

	UFUNCTION()
	void DisplaySession();

	UFUNCTION()
	void ClickedAcceptButton();

	UFUNCTION()
	void TimerFunction();

	void SuccessFindSession();
	void FailureFindSession();

protected:
	virtual void NativeOnInitialized();
	virtual void NativeConstruct();
public :
	UPROPERTY()
	FTimerDynamicDelegate TimerDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FServerMenu ServerMenu;
};
