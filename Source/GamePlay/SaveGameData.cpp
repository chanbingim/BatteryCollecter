// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGameData.h"
#include "Net/UnrealNetwork.h"

void USaveGameData::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(USaveGameData, Info);
}

void USaveGameData::SetPlayerInfo(FPlayerInfo _Info)
{
	Info.PlayerCharacter = _Info.PlayerCharacter;
	Info.PlayerImage = _Info.PlayerImage;
	Info.PlayerName= FText::FromString(_Info.PlayerName.ToString());
	Info.PlayerStatus = FText::FromString(_Info.PlayerStatus.ToString());
}
