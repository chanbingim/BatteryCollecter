// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSessionSettings.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "GameInstanceBase.generated.h"

static FText SaveDataName = FText::FromString("Enter Name");

UCLASS()
class GAMEPLAY_API UGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()

private :
	UPROPERTY(VisibleInstanceOnly,replicated, Category = "Server")
	int	NumberOfPlayer;

	UPROPERTY(VisibleInstanceOnly, replicated, Category = "Server")
	bool bEnableLan;

	UPROPERTY(VisibleInstanceOnly, replicated, Category = "Server")
	FText ServerName;
protected :
	IOnlineSessionPtr SessionInterface;
	TSharedPtr<FOnlineSessionSearch> SessionSearch;
	

	virtual void OnCreateSessionComplete(FName Servername, bool bSucceded);
	virtual void OnFindSessionComplete(bool bSucceded);
	virtual void Init();

public:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps);

	FOnlineSession AvailableSession;

	bool bFindSession = false;

	UFUNCTION()
	void ShowMainMenu();

	UFUNCTION()
	void ShowServerMenu();

	UFUNCTION()
	void LaunchLobby(int _NumberOfPlayers, bool _EnableLan, FText _Servername);

	UFUNCTION()
	void ShowLoadingScreen();

	UFUNCTION()
	void ShowHostMenu();

	UFUNCTION(BlueprintCallable)
	void SaveDataCheck();

	UFUNCTION()
	void ShowOptionMenu();

	UFUNCTION(BlueprintCallable)
	void CreateGameSession();

	UFUNCTION()
	void JoinGameSession();

	UFUNCTION(BlueprintCallable)
	FText GetPlayerSaveDataName() { return SaveDataName; }

	UFUNCTION()
	void SetSaveDataName(FText _Name) { SaveDataName = _Name; }
};
