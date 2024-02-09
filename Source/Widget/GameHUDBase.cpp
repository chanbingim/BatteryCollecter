// Fill out your copyright notice in the Description page of Project Settings.

#include "GameHUDBase.h"
#include "UserWidgetBaseClass.h"

AGameHUDBase::AGameHUDBase()
{
	GameWidgetPool.SetWorld(GetWorld());
	GameWidgetPool.SetDefaultPlayerController(GetOwningPlayerController());
}

void AGameHUDBase::BeginPlay()
{
	Super::BeginPlay();

	
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

void AGameHUDBase::RemovWidget(EWidgetName Name)
{
	TSubclassOf<class UUserWidget> TempWidgetClass = CheckWidgetClass(Name);
	UUserWidget* TempWidget = CheckWidgetPool(TempWidgetClass);

	if (TempWidget != nullptr)
	{
		TempWidget->RemoveFromParent();
		GameWidgetPool.Release(TempWidget);
	}
}

UUserWidget* AGameHUDBase::CheckWidgetPool(TSubclassOf<class UUserWidget> CheckWidget)
{
	TArray<UUserWidget*> ActiveWidgets = GameWidgetPool.GetActiveWidgets();
	for (UUserWidget* Widget : ActiveWidgets)
	{
		if (Widget->GetClass() == CheckWidget)
		{
			return Widget;
		}
	}
	return nullptr;
}

TSubclassOf<class UUserWidget> AGameHUDBase::CheckWidgetClass(EWidgetName Name)
{
	switch (Name)
	{
	case EWidgetName::MainMenu:
		return MainMenuClass;
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