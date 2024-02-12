// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "GameInstanceBase.generated.h"

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

	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;

public:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps);

	UFUNCTION()
	void ShowMainMenu();

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

	IOnlineSessionPtr OnlineSessionInterface;

	UFUNCTION()
	void CreateGameSession();

	UFUNCTION()
	void JoinGameSession();

	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

	void OnFindSessionsComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
};
