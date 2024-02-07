// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstanceBase.h"
#include "OnlineSubsystem.h"
#include "MultiGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "OnlineSessionSettings.h"
#include "Net/UnrealNetwork.h"
#include "Widget/GameHUDBase.h"


void UGameInstanceBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UGameInstanceBase, NumberOfPlayer);
	DOREPLIFETIME(UGameInstanceBase, bEnableLan);
	DOREPLIFETIME(UGameInstanceBase, ServerName);
}

void UGameInstanceBase::ShowMainMenu()
{
	AGameHUDBase* BaseHUD = Cast<AGameHUDBase>(UGameplayStatics::GetPlayerController(this,0)->GetHUD());
	
	if (BaseHUD)
	{
		BaseHUD->CreateMainMenuWidget();
	}
		
}

void UGameInstanceBase::LaunchLobby(int _NumberOfPlayers, bool _EnableLan, FText _Servername)
{
	NumberOfPlayer = _NumberOfPlayers;
	bEnableLan = _EnableLan;
	ServerName = _Servername;

	ShowLoadingScreen();
	CreateGameSession();
}

void UGameInstanceBase::ShowLoadingScreen()
{

}

void UGameInstanceBase::CreateGameSession()
{
	if (OnlineSessionInterface.IsValid() == false)
	{
		return;
	}
	
	auto ExistingSession = OnlineSessionInterface->GetNamedSession(NAME_GameSession);
	if (ExistingSession != nullptr)
	{
		OnlineSessionInterface->DestroySession(NAME_GameSession);
	}

	OnlineSessionInterface->AddOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegate);

	TSharedPtr<FOnlineSessionSettings> SessionSettings = MakeShareable(new FOnlineSessionSettings());
	SessionSettings->bIsLANMatch = false;
	SessionSettings->NumPublicConnections = 4;
	SessionSettings->bAllowJoinInProgress = true;

	//���� SessionSettings�� �����ϴ� Session�� �����Ѵ�.
	OnlineSessionInterface->CreateSession(UGameplayStatics::GetPlayerControllerID(UGameplayStatics::GetPlayerController(this, 0)), NAME_GameSession, *SessionSettings);//���� SessionSettings�� �����ϴ� Session�� �����Ѵ�
}

void UGameInstanceBase::JoinGameSession()
{
	ShowLoadingScreen();

}

void UGameInstanceBase::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
	//Session ������ ������ ���
	if (bWasSuccessful)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				15.0f,
				FColor::Blue,
				FString::Printf(TEXT("Created session: %s"), *SessionName.ToString())
			);

			UGameplayStatics::OpenLevel(this, FName(TEXT("Lobby")), true, "listen");
		}
	}
	//Session ������ ������ ���
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				15.f,
				FColor::Red,
				FString(TEXT("Failed to create session!"))
			);
		}
	}
}

void UGameInstanceBase::OnFindSessionsComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{

}
