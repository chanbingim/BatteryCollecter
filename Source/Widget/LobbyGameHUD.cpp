// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameHUD.h"
#include "Kismet/KismetTextLibrary.h"
#include "LubbyWidgetMenu.h"

void ALobbyGameHUD::AddWidgetHUD(ELobbyMenuName Name)
{
	UUserWidget* TempWidget = CheckWidgetArray(Name);

	if (TempWidget == nullptr)
	{
		TempWidget = CreateWidget<UUserWidget>(GetWorld(), LobbyMenuClass);
	}
	TempWidget->AddToViewport();
}

void ALobbyGameHUD::RemoveWidgetHUD(ELobbyMenuName Name)
{
	UUserWidget* TempWidget = CheckWidgetArray(Name);

	if (TempWidget != nullptr)
	{
		TempWidget->RemoveFromParent();
		ActiveWidgetArray.Remove(TempWidget);
	}
}

void ALobbyGameHUD::ShowLodingScreen()
{
	RemoveWidgetHUD(ELobbyMenuName::LobbyMenu);
	AddWidgetHUD(ELobbyMenuName::LodingScreen);
}

UUserWidget* ALobbyGameHUD::CheckWidgetArray(ELobbyMenuName Name)
{
	TSubclassOf<class UUserWidget> CheckWidget = CheckWidgetClass(Name);

	for (UUserWidget* Widget : ActiveWidgetArray)
	{
		if (Widget->GetClass() == CheckWidget)
		{
			return Widget;
		}
	}
	return nullptr;
}

TSubclassOf<class UUserWidget> ALobbyGameHUD::CheckWidgetClass(ELobbyMenuName Name)
{
	switch (Name)
	{
		case ELobbyMenuName::LobbyMenu :
			return LobbyMenuClass;
		case ELobbyMenuName::LodingScreen:
			return LodingScreenClass;
		case ELobbyMenuName::ConnectedPlayer:
			return ConnectedPlayerClass;
	}

	return nullptr;
}

UUserWidget* ALobbyGameHUD::LobbyMenuSetting(const FText& Name)
{
	UUserWidget* ActiveMenu = CheckWidgetArray(ELobbyMenuName::LobbyMenu);

	if (ActiveMenu == nullptr)
	{
		AddWidgetHUD(ELobbyMenuName::LobbyMenu);
	}
	ULubbyWidgetMenu* MenuWidget = Cast<ULubbyWidgetMenu>(ActiveMenu);
	MenuWidget->LobbyName = Name;

	return MenuWidget;
}

UUserWidget* ALobbyGameHUD::ConnectedPlayerSetting(FPlayerInfo ConnectedPlayerInfo)
{
	UUserWidget* ActiveMenu = CheckWidgetArray(ELobbyMenuName::ConnectedPlayer);

	if (ActiveMenu == nullptr)
	{
		AddWidgetHUD(ELobbyMenuName::ConnectedPlayer);
	}

	ULubbyWidgetMenu* ConnectedPlayerWidget = Cast<ULubbyWidgetMenu>(ActiveMenu);
	return ConnectedPlayerWidget;
}

void ALobbyGameHUD::UpdatePlayerListWindow(TArray<FPlayerInfo>& ConnectedPlayerInfo)
{
	UUserWidget* ActiveMenu = CheckWidgetArray(ELobbyMenuName::LobbyMenu);

	if (ActiveMenu != nullptr)
	{
		ULubbyWidgetMenu* MenuWidget = Cast<ULubbyWidgetMenu>(ActiveMenu);
		MenuWidget->ClearPlayerList();

		for (FPlayerInfo Data : ConnectedPlayerInfo)
		{
			MenuWidget->UpdatePlayerWindow(Data);
		}
	}
}

void ALobbyGameHUD::UpdateLobbyMenu(UTexture2D* MapImage, const FText& MapName, const FText& MapTime)
{
	UUserWidget* ActiveMenu = CheckWidgetArray(ELobbyMenuName::LobbyMenu);

	if (ActiveMenu != nullptr)
	{
		ULubbyWidgetMenu* MenuWidget = Cast<ULubbyWidgetMenu>(ActiveMenu);
		MenuWidget->LobbyImage = MapImage;
		MenuWidget->LobbyName = MapName;
		MenuWidget->LobbyTime = MapTime;
	}
}

void ALobbyGameHUD::UpdateNumberOfPlayer(int currentPlayer, int MaxPlayer)
{
	UUserWidget* ActiveMenu = CheckWidgetArray(ELobbyMenuName::LobbyMenu);

	if (ActiveMenu != nullptr)
	{
		ULubbyWidgetMenu* MenuWidget = Cast<ULubbyWidgetMenu>(ActiveMenu);
		MenuWidget->PlayerDisplay = FText::Format(LOCTEXT("ExampleFText","{0}/{1}"), currentPlayer, MaxPlayer);
	}
}