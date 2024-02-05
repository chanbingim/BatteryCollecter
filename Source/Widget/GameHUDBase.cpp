// Fill out your copyright notice in the Description page of Project Settings.

#include "GameHUDBase.h"
#include "UserWidgetBaseClass.h"

void AGameHUDBase::CreateMainMenuWidget()
{
	UUserWidget* MainMenuWidget = CheckWidgetPool(MainMenuClass);
	if (MainMenuClass == nullptr)
		return;

	if (MainMenuWidget == nullptr)
	{
		MainMenuWidget = GameWidgetPool.GetOrCreateInstance(MainMenuClass);
		MainMenuWidget->AddToViewport();
	}
	else
	{
		MainMenuWidget->AddToViewport();
	}

	GetOwningPlayerController()->bShowMouseCursor = true;
}

void AGameHUDBase::CreateWidget(EWidgetName Name)
{
	TSubclassOf<class UUserWidget> TempWidgetClass = CheckWidgetClass(Name);
	UUserWidget* TempWidget = CheckWidgetPool(TempWidgetClass);

	if (TempWidgetClass == nullptr)
		return;

	if (TempWidget == nullptr)
	{
		TempWidget = GameWidgetPool.GetOrCreateInstance(TempWidgetClass);
		TempWidget->AddToViewport();
	}
	else
	{
		TempWidget->AddToViewport();
	}
}

UUserWidget* AGameHUDBase::CheckWidgetPool(TSubclassOf<class UUserWidget> CheckWidget)
{
	TArray<UUserWidget*> ActiveWidgets = GameWidgetPool.GetActiveWidgets();
	for (UUserWidget* Widget : ActiveWidgets)
	{
		if (Widget->StaticClass() == MainMenuClass)
		{
			return Widget;
		}
	}
	return false;
}

TSubclassOf<class UUserWidget> AGameHUDBase::CheckWidgetClass(EWidgetName Name)
{
	switch (Name)
	{
	case EWidgetName::HostMenu:
		return HostMenuClass;
	case EWidgetName::ServerMenu:
		return ServerMenuClass;
	case EWidgetName::OptionMenu:
		return OptionMenuClass;
	default:
		return nullptr;
	}
}