// Fill out your copyright notice in the Description page of Project Settings.


#include "LoobyGameModeBaseClass.h"
#include "Kismet/GamePlayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "LobbyPlayerController.h"
#include "GameInstanceBase.h"
#include "Net/UnrealNetwork.h"

ALoobyGameModeBaseClass::ALoobyGameModeBaseClass()
{
	for (int i = 0; i < 9; i++)
	{
		AvailableCharacters.Add(false);
	}
}

void ALoobyGameModeBaseClass::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALoobyGameModeBaseClass, AllPlayerControllers);
	DOREPLIFETIME(ALoobyGameModeBaseClass, ConnectedPlayers);
}

void ALoobyGameModeBaseClass::OnPostLogin(AController* NewPlayer)
{
	Super::OnPostLogin(NewPlayer);

	if (HasAuthority())
	{
		APlayerController* NewPlayerController = Cast<APlayerController>(NewPlayer);
		AllPlayerControllers.Add(NewPlayerController);
		
		UGameplayStatics::GetAllActorsOfClass(this, PlayerStart, AllPlayerStart);

		UGameInstanceBase* MyInstance = Cast<UGameInstanceBase>(UGameplayStatics::GetGameInstance(this));
		ServerName = MyInstance->ServerName;
		MaxPlayers = MyInstance->NumberOfPlayer;

		ALobbyPlayerController* LobbyPlayer = Cast<ALobbyPlayerController>(NewPlayer);
		LobbyPlayer->InitialSetUp();
		LobbyPlayer->SettingLobbyMenu(ServerName);
		LobbyPlayer->UpdateLobbyMenuSetting(GmImage,GmMapName,GmMapTime);
		RespawnCharacter(NewPlayerController);
	}
	else
	{

	}
}

void ALoobyGameModeBaseClass::Logout(AController* Exiting)
{
	Super::Logout(Exiting);


}

void ALoobyGameModeBaseClass::RespawnCharacter_Implementation(APlayerController* PlayerController)
{
	APawn* Player = PlayerController->GetPawn();

	if (Player)
	{
		Player->Destroy();
	}

	FActorSpawnParameters SpawnParameter;
	int SpawnPointIndex = 0;
	if (AllPlayerStart.Num() > 0)
	{
		SpawnPointIndex = UKismetMathLibrary::RandomIntegerInRange(0, AllPlayerStart.Num());
	}

	APawn* SpawnActor = GetWorld()->SpawnActor<APawn>(PlayerCharacterClass, AllPlayerStart[SpawnPointIndex]->GetActorTransform(), SpawnParameter);
	PlayerController->Possess(SpawnActor);
	EveryoneUpdate();
}

void ALoobyGameModeBaseClass::ServerUpdateGameSetting_Implementation(UTexture2D* MapImage, const FText& Mapname, const FText& MapTime, int MapID)
{
	for (APlayerController* PlayerController : AllPlayerControllers)
	{
		ALobbyPlayerController* LobbyController = Cast<ALobbyPlayerController>(PlayerController);
		LobbyController->UpdateLobbyMenuSetting(MapImage, Mapname, MapTime);
	}
}

void ALoobyGameModeBaseClass::AddKickedList()
{

}

void ALoobyGameModeBaseClass::CannotStartGame()
{

}

void ALoobyGameModeBaseClass::LaunchTheGame()
{
	switch(MapDataID)
	{
	case 1:
		UGameplayStatics::GetPlayerController(this, 0)->ConsoleCommand("servertravel/Game/Maps/Arena01");
		break;
	case 2:
		UGameplayStatics::GetPlayerController(this, 0)->ConsoleCommand("servertravel/Game/Maps/Arena02");
		break;
	}
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
	int CurrentPlayers = AllPlayerControllers.Num();

	TArray<FPlayerInfo> TempDataAry;
	

	if (CurrentPlayers > 0)
	{
		for (APlayerController* PlayerController : AllPlayerControllers)
		{
			ALobbyPlayerController* LobbyController = Cast<ALobbyPlayerController>(PlayerController);
			TempDataAry.Add(LobbyController->SettingPlayerData);
			LobbyController->UpdateNumberOfPlayer(CurrentPlayers, MaxPlayers);
		}

		for (APlayerController* PlayerController : AllPlayerControllers)
		{
			ALobbyPlayerController* LobbyController = Cast<ALobbyPlayerController>(PlayerController);
			LobbyController->AddPlayerInfo(TempDataAry);
			LobbyController->UpdateAvailableCharacter(AvailableCharacters);
			AddKickedList();
		}

		for (FPlayerInfo PlayerInfo : TempDataAry)
		{
			if (PlayerInfo.PlayerCharacter == Cast<ACharacter>(PlayerCharacterClass))
			{
				bCanStart = false;
			}
			else
				bCanStart = true;
		}
	}

	ConnectedPlayers = TempDataAry;
}
