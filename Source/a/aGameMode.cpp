// Copyright Epic Games, Inc. All Rights Reserved.

#include "aGameMode.h"
#include "aCharacter.h"
#include "UObject/ConstructorHelpers.h"

AaGameMode::AaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
