// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamePlay/SaveGameData.h"
#include "LobbyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API ALobbyPlayerController : public APlayerController
{
	GENERATED_BODY()

private :
	
protected:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps);

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:
	UPROPERTY()
	FPlayerInfo SettingPlayerData;

	UPROPERTY(VisibleAnywhere, replicated, Category = "Server")
	TArray<FPlayerInfo> AllConnectedPlayerInfo;

	UFUNCTION(Client, Reliable)
	virtual void InitialSetUp();

	UFUNCTION(Server, Reliable)
	virtual void CallUpdate(FPlayerInfo Info, bool ChangedStatus);

	UFUNCTION(Client, Reliable)
	virtual void SettingLobbyMenu(const FText& MenuName);

	UFUNCTION(Client, Reliable)
	virtual void UpdateLobbyMenuSetting(UTexture2D* MapImage, const FText& MapName, const FText& MapTime);

	UFUNCTION(Client, Reliable)
	virtual void AddPlayerInfo(const TArray<FPlayerInfo>& ConnectedPlayerInfo);

	UFUNCTION(Client, Reliable)
	virtual void ShowLodingScreen();

	UFUNCTION()
	void UpdateNumberOfPlayer(int currentPlayer, int MaxPlayer);

	UFUNCTION()
	void CheckSaveData();

	UFUNCTION(Client, Reliable)
	virtual void Kicked();
};