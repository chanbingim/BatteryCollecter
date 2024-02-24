// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "LobbyGameHUD.generated.h"

#define LOCTEXT_NAMESPACE "MyNamespace"

UENUM(BlueprintType)
enum class ELobbyMenuName : uint8
{
	LobbyMenu,
	LodingScreen,
	ConnectedPlayer,
};
/**
 * 
 */
UCLASS()
class WIDGET_API ALobbyGameHUD : public AHUD
{
	GENERATED_BODY()
private:
	TArray<UUserWidget*> ActiveWidgetArray;

	UFUNCTION()
	UUserWidget* CheckWidgetArray(ELobbyMenuName Name);

	UFUNCTION()
	TSubclassOf<class UUserWidget> CheckWidgetClass(ELobbyMenuName Name);
protected:
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<class UUserWidget> LobbyMenuClass = nullptr;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<class UUserWidget> ConnectedPlayerClass = nullptr;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<class UUserWidget> LodingScreenClass = nullptr;
public :
	UFUNCTION()
	UUserWidget* LobbyMenuSetting(const FText& Name);

	UFUNCTION()
	UUserWidget* ConnectedPlayerSetting(FPlayerInfo ConnectedPlayerInfo);

	UFUNCTION()
	void UpdateLobbyMenu(UTexture2D* MapImage, const FText& MapName, const FText& MapTime);

	UFUNCTION()
	void UpdatePlayerListWindow(TArray<FPlayerInfo>& ConnectedPlayerInfo);

	UFUNCTION()
	void AddWidgetHUD(ELobbyMenuName Name);

	UFUNCTION()
	void RemoveWidgetHUD(ELobbyMenuName Name);

	UFUNCTION()
	void ShowLodingScreen();

	UFUNCTION()
	void UpdateNumberOfPlayer(int currentPlayer, int MaxPlayer);

	UFUNCTION()
	TSubclassOf<class UUserWidget> GetLobbyMenuClass() { return LobbyMenuClass; }
};
