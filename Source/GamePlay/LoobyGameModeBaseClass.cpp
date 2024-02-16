// Fill out your copyright notice in the Description page of Project Settings.


#include "LoobyGameModeBaseClass.h"
#include "Net/UnrealNetwork.h"

ALoobyGameModeBaseClass::ALoobyGameModeBaseClass()
{

}

void ALoobyGameModeBaseClass::SwapCharacter_Implementation(APlayerController* PlayerController, ACharacter* Characterclass, bool ChangedStatus)
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		15.0f,
		FColor::Blue,
		FString(TEXT("Test Server"))
	);
}

void ALoobyGameModeBaseClass::EveryoneUpdate_Implementation()
{

}
