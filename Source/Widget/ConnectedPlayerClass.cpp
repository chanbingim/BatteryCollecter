// Fill out your copyright notice in the Description page of Project Settings.


#include "ConnectedPlayerClass.h"
#include "Net/UnrealNetwork.h"

void UConnectedPlayerClass::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UConnectedPlayerClass, PlayerInfo);
}

void UConnectedPlayerClass::NativeOnInitialized()
{
	Super::NativeOnInitialized();

}

void UConnectedPlayerClass::NativeConstruct()
{
	Super::NativeConstruct();

}
