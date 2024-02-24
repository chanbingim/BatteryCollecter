// Fill out your copyright notice in the Description page of Project Settings.


#include "LubbyWidgetMenu.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GamePlay/LoobyGameModeBaseClass.h"
#include "GameSettingWidget.h"
#include "LobbyGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "GamePlay/LobbyPlayerController.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"

bool ULubbyWidgetMenu::CheckWidget()
{
	if (LobbyMenu.ChatWindow == nullptr)
		return true;

	if (LobbyMenu.GameSettingButton == nullptr)
		return true;
	else
	{
		LobbyMenu.LeaveButton->OnClicked.AddDynamic(this, &ULubbyWidgetMenu::ClickedSettingButton);
	}

	if (LobbyMenu.SelectPlayerButton == nullptr)
		return true;
	else
	{
		LobbyMenu.LeaveButton->OnClicked.AddDynamic(this, &ULubbyWidgetMenu::ClickedSelectButton);
	}

	if (LobbyMenu.StartSessionButton == nullptr)
		return true;
	else
	{
		LobbyMenu.LeaveButton->OnClicked.AddDynamic(this, &ULubbyWidgetMenu::ClickedStartButton);
	}

	if (LobbyMenu.LeaveButton == nullptr)
		return true;
	else
	{
		LobbyMenu.LeaveButton->OnClicked.AddDynamic(this, &ULubbyWidgetMenu::ClickedLeaveButton);
	}

	if (LobbyMenu.MapNameText == nullptr)
		return true;

	if (LobbyMenu.MapTimeText == nullptr)
		return true;

	if (LobbyMenu.PlayerImage == nullptr)
		return true;

	if (LobbyMenu.PlayerOnline == nullptr)
		return true;

	if (LobbyMenu.SelectCharacter == nullptr)
		return true;

	if (LobbyMenu.StartSessionText == nullptr)
		return true;

		return false;
}

void ULubbyWidgetMenu::ClickedLeaveButton()
{

}

void ULubbyWidgetMenu::ClickedSettingButton()
{
	if (UKismetSystemLibrary::IsServer(this))
	{
		LobbyMenu.SetGameSetting->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		LobbyMenu.SetGameSetting->SetVisibility(ESlateVisibility::Visible);
		Cast<UGameSettingWidget>(LobbyMenu.SetGameSetting)->FillPlayerWindow();
	}
}

void ULubbyWidgetMenu::ClickedStartButton()
{
	ALoobyGameModeBaseClass * LobbyGameMode = Cast<ALoobyGameModeBaseClass>(UGameplayStatics::GetGameMode(this));

	if (UKismetSystemLibrary::IsServer(this))
	{
		TArray<APlayerController*> AllPlayer = LobbyGameMode->AllPlayerControllers;

		for (APlayerController* Player : AllPlayer)
		{
			ALobbyPlayerController* LobbyController = Cast<ALobbyPlayerController>(Player);
			LobbyController->ShowLodingScreen();
		}

		LobbyGameMode->LaunchTheGame();
	}
	else
	{
		UpdateStatus();
	}
}

void ULubbyWidgetMenu::ClickedSelectButton()
{
	if (UKismetSystemLibrary::IsServer(this))
	{

	}
	else
	{
		LobbyMenu.SelectCharacter->SetVisibility(ESlateVisibility::Visible);
		LobbyMenu.SelectCharacter->SetUserFocus(GetOwningPlayer());
	}
}

void ULubbyWidgetMenu::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ULubbyWidgetMenu, LobbyName);
	DOREPLIFETIME(ULubbyWidgetMenu, LobbyImage);
	DOREPLIFETIME(ULubbyWidgetMenu, PlayerDisplay);
	DOREPLIFETIME(ULubbyWidgetMenu, LobbyTime);
	DOREPLIFETIME(ULubbyWidgetMenu, ReadyStatus);
}

void ULubbyWidgetMenu::NativeOnInitialized()
{
	Super::NativeOnInitialized();


}

void ULubbyWidgetMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if(!CheckWidget())
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("Success Checking Widget"))
		);
	}

	MyPlayerController = Cast<ALobbyPlayerController>(GetOwningPlayer());
	
	if (UKismetSystemLibrary::IsServer(this))
	{
		LobbyMenu.StartSessionText->SetText(FText::FromString("StartSession"));
		MyPlayerController->SettingPlayerData.PlayerStatus = FText::FromString("Host");
	}
	else
	{
		LobbyMenu.StartSessionText->SetText(FText::FromString("ToggleReady"));
		LobbyMenu.SetGameSetting->RemoveFromParent();
	}
}

void ULubbyWidgetMenu::ClearPlayerList()
{
	LobbyMenu.PlayerWindow->ClearChildren();
}

void ULubbyWidgetMenu::UpdateStatus()
{
	if (bReadyCheck)
		ReadyStatus = FText::FromString("Ready");
	else
		ReadyStatus = FText::FromString("Not Ready");

	FPlayerInfo TempInfo;

	MyPlayerController = Cast<ALobbyPlayerController>(GetOwningPlayer());
	TempInfo.PlayerStatus = ReadyStatus;	
	MyPlayerController->CallUpdate(TempInfo,true);
}

void ULubbyWidgetMenu::UpdatePlayerWindow_Implementation(FPlayerInfo Playerinfo)
{
	ALobbyGameHUD* MyHUD = Cast<ALobbyGameHUD>(GetOwningPlayer()->GetHUD());
	UUserWidget* PlayerDataWidget = MyHUD->ConnectedPlayerSetting(Playerinfo);

	LobbyMenu.PlayerWindow->AddChild(PlayerDataWidget);
}