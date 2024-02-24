// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GamePlay/SaveGameData.h"
#include "LubbyWidgetMenu.generated.h"

class UButton;
class UTextBlock;
class UVerticalBox;
class UImage;

USTRUCT(BlueprintType)
struct FLobbyMenu
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UImage* PlayerImage = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextBlock* MapNameText = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextBlock* MapTimeText = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextBlock* PlayerOnline = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* StartSessionButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextBlock* StartSessionText = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* GameSettingButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* SelectPlayerButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UButton* LeaveButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* ChatWindow = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* SelectCharacter = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* SetGameSetting = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UVerticalBox* PlayerWindow = nullptr;
};

/**
 * 
 */
UCLASS()
class WIDGET_API ULubbyWidgetMenu : public UUserWidget
{
	GENERATED_BODY()
private :
	UPROPERTY()
	class ALobbyPlayerController* MyPlayerController = nullptr;

	UPROPERTY()
	bool bReadyCheck = false;

	UFUNCTION()
	bool CheckWidget();

	UFUNCTION()
	void ClickedLeaveButton();

	UFUNCTION()
	void ClickedSettingButton();

	UFUNCTION()
	void ClickedStartButton();

	UFUNCTION()
	void ClickedSelectButton();

protected :
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps);
	virtual void NativeOnInitialized();
	virtual void NativeConstruct();
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLobbyMenu LobbyMenu;

	UPROPERTY(VisibleAnywhere, replicated, Category = "Server")
	UTexture2D* LobbyImage;

	UPROPERTY(VisibleAnywhere, replicated, Category = "Server")
	FText LobbyName;

	UPROPERTY(VisibleAnywhere, replicated, Category = "Server")
	FText PlayerDisplay;

	UPROPERTY(VisibleAnywhere, replicated, Category = "Server")
	FText LobbyTime;

	UPROPERTY(VisibleAnywhere, replicated, Category = "Server")
	FText ReadyStatus;

	UFUNCTION(Client, Unreliable)
	virtual void UpdatePlayerWindow(FPlayerInfo Playerinfo);

	UFUNCTION()
	void ClearPlayerList();

	UFUNCTION()
	void UpdateStatus();
};
