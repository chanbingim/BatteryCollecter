// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveGameData.generated.h"

USTRUCT(BlueprintType)
struct FPlayerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Info")
	FText PlayerName = FText::FromString("");

	UPROPERTY(EditAnywhere, Category = "Info")
	UTexture2D* PlayerImage = nullptr;

	UPROPERTY(EditAnywhere, Category = "Info")
	ACharacter* PlayerCharacter = nullptr;

	UPROPERTY(EditAnywhere, Category = "Info")
	FText PlayerStatus = FText::FromString("");
};

UCLASS()
class GAMEPLAY_API USaveGameData : public USaveGame
{
	GENERATED_BODY()
private :
	UPROPERTY(VisibleInstanceOnly, replicated, Category = "Server")
	FPlayerInfo Info;

protected :
	 virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps);

public :
	void SetPlayerInfo(FPlayerInfo _Info);
	FORCEINLINE FPlayerInfo GetPlayerInfo() { return Info; }
};
