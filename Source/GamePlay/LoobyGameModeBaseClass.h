// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/Character.h"
#include "SaveGameData.h"
#include "LoobyGameModeBaseClass.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAY_API ALoobyGameModeBaseClass : public AGameModeBase
{
	GENERATED_BODY()
	ALoobyGameModeBaseClass();

private:
	UPROPERTY( BlueprintReadWrite, VisibleAnywhere, Category = "SERVERSETTING", meta = (AllowPrivateAccess = "true"))
	bool bCanStart = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SERVERSETTING", meta = (AllowPrivateAccess = "true"))
	FText ServerName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SERVERSETTING", meta = (AllowPrivateAccess = "true"))
	int MaxPlayers;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SERVERSETTING", meta = (AllowPrivateAccess = "true"))
	int MapDataID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SERVERSETTING", meta = (AllowPrivateAccess = "true"))
	UTexture2D* GmImage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SERVERSETTING", meta = (AllowPrivateAccess = "true"))
	FText GmMapName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SERVERSETTING", meta = (AllowPrivateAccess = "true"))
	FText GmMapTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SERVERSETTING", meta = (AllowPrivateAccess = "true"))
	TArray<AActor*> AllPlayerStart;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BoolData", meta = (AllowPrivateAccess = "true"))
	TArray<bool> AvailableCharacters;
	protected:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps);
	virtual void OnPostLogin(AController* NewPlayer);
	virtual void Logout(AController* Exiting);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "POISITION", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AActor> PlayerStart;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PLAYERCHARACTER", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class APawn> PlayerCharacterClass;
public :
	UPROPERTY(replicated)
	TArray<FPlayerInfo> ConnectedPlayers;

	UPROPERTY(Replicated)
	TArray<APlayerController*> AllPlayerControllers;

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void SwapCharacter(APlayerController* PlayerController, ACharacter* Characterclass, bool ChangedStatus);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void RespawnCharacter(APlayerController* PlayerController);

	UFUNCTION(Server, Reliable)
	void EveryoneUpdate();

	UFUNCTION(Server, Reliable)
	void ServerUpdateGameSetting(UTexture2D* MapImage, const FText& Mapname, const FText& MapTime, int MapID);

	UFUNCTION()
	void AddKickedList();

	UFUNCTION()
	void CannotStartGame();

	UFUNCTION()
	void LaunchTheGame();
};
