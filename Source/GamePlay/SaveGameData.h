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
	FText PlayerName;

	UPROPERTY(EditAnywhere, Category = "Info")
	UTexture2D* PlayerImage;

	UPROPERTY(EditAnywhere, Category = "Info")
	ACharacter* PlayerCharacter;

	UPROPERTY(EditAnywhere, Category = "Info")
	UTexture2D* PlayerCharacterImage;

	UPROPERTY(EditAnywhere, Category = "Info")
	FText PlayerStatus;
};

UCLASS()
class GAMEPLAY_API USaveGameData : public USaveGame
{
	GENERATED_BODY()
protected :
	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps);

public :
	UPROPERTY(VisibleInstanceOnly, replicated, Category = "Server")
	FPlayerInfo PlayerInfo;
};
