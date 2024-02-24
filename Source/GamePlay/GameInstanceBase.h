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
	int	NumberOfPlayer = 2;

	UPROPERTY(VisibleInstanceOnly, replicated, Category = "Server")
	bool bEnableLan;

	UPROPERTY(VisibleInstanceOnly, replicated, Category = "Server")
	FText ServerName;
protected :
	IOnlineSessionPtr SessionInterface;
	TSharedPtr<FOnlineSessionSearch> SessionSearch;

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps);
	virtual void OnCreateSessionComplete(FName Servername, bool bSucceded);
	virtual void OnFindSessionComplete(bool bSucceded);
	virtual void OnDestroySessionComplete(FName Servername, bool bSuccede);
	virtual void Init() override;
public:
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

	UFUNCTION()
	void ShowOptionMenu();

	UFUNCTION()
	void CreateGameSession();

	UFUNCTION()
	void JoinGameSession();

	UFUNCTION()
	void DestoryGameSession(APlayerController* Player);

	UFUNCTION(BlueprintCallable)
	FText GetPlayerSaveDataName() { return SaveDataName; }

	UFUNCTION()
	void SetSaveDataName(FText _Name) { SaveDataName = _Name; }
};
