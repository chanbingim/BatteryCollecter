// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayerController.h"
#include "Widget/LobbyGameHUD.h"
#include "GameInstanceBase.h"
#include "LoobyGameModeBaseClass.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Net/UnrealNetwork.h"

void ALobbyPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALobbyPlayerController, AllConnectedPlayerInfo);
}

void ALobbyPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UGameInstanceBase* MyInstance =  Cast<UGameInstanceBase>(UGameplayStatics::GetGameInstance(this));
	MyInstance->DestoryGameSession(this);
}

void ALobbyPlayerController::CheckSaveData()
{

}

void ALobbyPlayerController::Kicked_Implementation()
{
	GetWorld()->ServerTravel("/Game/Blueprint/AllLevels/MainMenu?listen");
	UGameInstanceBase* MyInstance = Cast<UGameInstanceBase>(UGameplayStatics::GetGameInstance(this));
	MyInstance->DestoryGameSession(this);
}

void ALobbyPlayerController::InitialSetUp_Implementation()
{
	CheckSaveData();
	CallUpdate(SettingPlayerData, false);
}

void ALobbyPlayerController::CallUpdate_Implementation(FPlayerInfo Info, bool ChangedStatus)
{
	SettingPlayerData = Info;
	ALoobyGameModeBaseClass* MyGameMode = Cast<ALoobyGameModeBaseClass>(UGameplayStatics::GetGameMode(this));

	MyGameMode->SwapCharacter(this,SettingPlayerData.PlayerCharacter,ChangedStatus);
	MyGameMode->EveryoneUpdate();
}

void ALobbyPlayerController::SettingLobbyMenu_Implementation(const FText& MenuName)
{
	SetShowMouseCursor(true);
	ALobbyGameHUD* LobbyHUD = Cast<ALobbyGameHUD>(GetHUD());
	UUserWidget* LobbyMenuWidget = LobbyHUD->LobbyMenuSetting(MenuName);

	UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(this,LobbyMenuWidget,EMouseLockMode::DoNotLock, true, false);
}

void ALobbyPlayerController::AddPlayerInfo_Implementation(const TArray<FPlayerInfo>& ConnectedPlayerInfo)
{
	AllConnectedPlayerInfo = ConnectedPlayerInfo;
	
	ALobbyGameHUD* LobbyHUD = Cast<ALobbyGameHUD>(GetHUD());
	LobbyHUD->UpdatePlayerListWindow(AllConnectedPlayerInfo);
}

void ALobbyPlayerController::UpdateLobbyMenuSetting_Implementation(UTexture2D* MapImage, const FText& MapName, const FText& MapTime)
{
	ALobbyGameHUD* LobbyHUD = Cast<ALobbyGameHUD>(GetHUD());
	LobbyHUD->UpdateLobbyMenu(MapImage, MapName, MapTime);
}

void ALobbyPlayerController::ShowLodingScreen_Implementation()
{
	ALobbyGameHUD* LobbyHUD = Cast<ALobbyGameHUD>(GetHUD());
	LobbyHUD->ShowLodingScreen();
}

void ALobbyPlayerController::UpdateNumberOfPlayer(int currentPlayer, int MaxPlayer)
{
	ALobbyGameHUD* LobbyHUD = Cast<ALobbyGameHUD>(GetHUD());
	LobbyHUD->ShowLodingScreen();
}