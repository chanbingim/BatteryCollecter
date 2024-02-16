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
	Super::Init();

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
		UUserWidget* CurrentWidget = BaseHUD->CheckWidgetArray(BaseHUD->CheckWidgetClass(EWidgetName::MainMenu));
		CurrentWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void UGameInstanceBase::ShowServerMenu()
{
	AGameHUDBase* BaseHUD = Cast<AGameHUDBase>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	
	if (BaseHUD)
	{
		UUserWidget* CurrentWidget = BaseHUD->CheckWidgetArray(BaseHUD->CheckWidgetClass(EWidgetName::ServerMenu));
		CurrentWidget->SetVisibility(ESlateVisibility::Visible);
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
		UUserWidget* CurrentWidget = BaseHUD->CheckWidgetArray(BaseHUD->CheckWidgetClass(EWidgetName::HostMenu));
		CurrentWidget->SetVisibility(ESlateVisibility::Visible);
	}
}



void UGameInstanceBase::ShowOptionMenu()
{
	AGameHUDBase* BaseHUD = Cast<AGameHUDBase>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());

	if (BaseHUD)
	{
		UUserWidget* CurrentWidget = BaseHUD->CheckWidgetArray(BaseHUD->CheckWidgetClass(EWidgetName::OptionMenu));
		CurrentWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void UGameInstanceBase::CreateGameSession()
{
	FName SessionName = UKismetStringLibrary::Conv_StringToName(SaveDataName.ToString());

	FOnlineSessionSettings SessionSetting;
	SessionSetting.bAllowJoinInProgress = true;
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
	UE_LOG(LogTemp, Warning, TEXT("Succed : %d"), bSucceded);
	if (bSucceded)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("Succed make Session"))
		);
		GetWorld()->ServerTravel("/Game/Blueprint/AllLevels/Lobby?listen");
	}
		
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
				AvailableSession = Result.Session;
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