// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGameData.h"
#include "Net/UnrealNetwork.h"

void USaveGameData::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(USaveGameData, PlayerInfo);
}
