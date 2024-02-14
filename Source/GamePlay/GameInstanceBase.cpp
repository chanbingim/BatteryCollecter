// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstanceBase.h"
#include "OnlineSubsystem.h"
#include "MultiGameModeBase.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "Widget/GameHUDBase.h"

void UGameInstanceBase::Init()
{
	if (IOnlineSubsystem* SubSystem = IOnlineSubsystem::Get())
	{
		SessionInterface = SubSystem->GetSessionInterface();

		if (SessionInterface.IsValid())
		{
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UGameInstanceBase::OnCreateSessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UGameInstanceBase::OnFindSessionComplete);
		}
	}
}

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
		BaseHUD->CreateWidget(EWidgetName::MainMenu);
	}
}

void UGameInstanceBase::ShowServerMenu()
{
	AGameHUDBase* BaseHUD = Cast<AGameHUDBase>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	
	if (BaseHUD)
	{
		BaseHUD->CreateWidget(EWidgetName::ServerMenu);
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

void UGameInstanceBase::ShowHostMenu()
{
	AGameHUDBase* BaseHUD = Cast<AGameHUDBase>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());

	if (BaseHUD)
	{
		BaseHUD->CreateWidget(EWidgetName::HostMenu);
	}
}

void UGameInstanceBase::SaveDataCheck()
{
	bool bCheck = UGameplayStatics::DoesSaveGameExist(SaveDataName.ToString(), 0);

	if (bCheck)
	{
		ShowMainMenu();
	}
	else
	{
		ShowOptionMenu();
		UGameplayStatics::GetPlayerController(this, 0)->bShowMouseCursor = true;
	}
}

void UGameInstanceBase::ShowOptionMenu()
{
	AGameHUDBase* BaseHUD = Cast<AGameHUDBase>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());

	if (BaseHUD)
	{
		BaseHUD->CreateWidget(EWidgetName::OptionMenu);
	}
}

void UGameInstanceBase::CreateGameSession()
{
	FName SessionName = UKismetStringLibrary::Conv_StringToName(SaveDataName.ToString());
	FOnlineSessionSettings SessionSetting;
	SessionSetting.bAllowInvites = true;
	SessionSetting.bIsDedicated = false;
	SessionSetting.bIsLANMatch = bEnableLan;
	SessionSetting.bShouldAdvertise = true;
	SessionSetting.bUsesPresence = true;
	SessionSetting.NumPublicConnections = NumberOfPlayer;

	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	SessionInterface->CreateSession(*LocalPlayer->GetPreferredUniqueNetId(),SessionName,SessionSetting);
}

void UGameInstanceBase::OnCreateSessionComplete(FName Servername, bool bSucceded)
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		15.0f,
		FColor::Blue,
		FString(TEXT("Succed make Session"))
	);
}

void UGameInstanceBase::OnFindSessionComplete(bool bSucceded)
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		15.0f,
		FColor::Blue,
		FString(TEXT("Find Session"))
	);

	if (bSucceded)
	{
		bFindSession = true;
		TArray<FOnlineSessionSearchResult> SearchResults = SessionSearch->SearchResults;

		for (FOnlineSessionSearchResult Result : SearchResults)
		{
			if (Result.Session.SessionSettings.NumPublicConnections != Result.Session.SessionSettings.NumPublicConnections - Result.Session.NumOpenPublicConnections)
			{
				//AvailableSession = Result.Session;
			}
		}
	}
}

void UGameInstanceBase::JoinGameSession()
{
	ShowLoadingScreen();
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	SessionSearch->bIsLanQuery = true;
	SessionSearch->MaxSearchResults = 1000;
	SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);

	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	SessionInterface->FindSessions(*LocalPlayer->GetPreferredUniqueNetId(), SessionSearch.ToSharedRef());
}