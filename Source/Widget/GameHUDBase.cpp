// Fill out your copyright notice in the Description page of Project Settings.

#include "GameHUDBase.h"
#include "GamePlay/GameInstanceBase.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/UnrealString.h"
#include "UserWidgetBaseClass.h"

AGameHUDBase::AGameHUDBase()
{
	GameWidgetPool.SetWorld(GetWorld());
	GameWidgetPool.SetDefaultPlayerController(GetOwningPlayerController());
}

void AGameHUDBase::GmaeBaseHudSetting()
{
	AddgWidget(EWidgetName::MainMenu);
	AddgWidget(EWidgetName::HostMenu);
	AddgWidget(EWidgetName::ServerMenu);
	AddgWidget(EWidgetName::OptionMenu);

	for (UUserWidget* TempWidget : ActiveWidgetArray)
	{
		TempWidget->SetVisibility(ESlateVisibility::Hidden);
	}
	GetOwningPlayerController()->bShowMouseCursor = true;
}

void AGameHUDBase::BeginPlay()
{
	Super::BeginPlay();

	GmaeBaseHudSetting();
	UGameInstanceBase* MyGameInstance = Cast<UGameInstanceBase>(GetGameInstance());
	bool bCheck = UGameplayStatics::DoesSaveGameExist(MyGameInstance->GetPlayerSaveDataName().ToString(), 0);

	if (bCheck)
		CheckWidgetArray(CheckWidgetClass(EWidgetName::MainMenu))->SetVisibility(ESlateVisibility::Visible);
	else
		CheckWidgetArray(CheckWidgetClass(EWidgetName::HostMenu))->SetVisibility(ESlateVisibility::Visible);
}

void AGameHUDBase::AddgWidget(EWidgetName Name)
{
	TSubclassOf<class UUserWidget> TempWidgetClass = CheckWidgetClass(Name);
	UUserWidget* TempWidget = CheckWidgetArray(TempWidgetClass);

	if (TempWidgetClass == nullptr)
		return;

	if (TempWidget == nullptr)
	{
		TempWidget = CreateWidget<UUserWidget>(GetWorld(), TempWidgetClass);
		ActiveWidgetArray.Add(TempWidget);
	}
	TempWidget->AddToViewport();
}

void AGameHUDBase::RemoveArrayWidget(EWidgetName Name)
{
	TSubclassOf<class UUserWidget> TempWidgetClass = CheckWidgetClass(Name);
	UUserWidget* TempWidget = CheckWidgetArray(TempWidgetClass);

	if (TempWidget != nullptr)
	{
		TempWidget->RemoveFromParent();
		ActiveWidgetArray.Remove(TempWidget);
	}
}

void AGameHUDBase::RemovePoolWidget(EWidgetName Name)
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

UUserWidget* AGameHUDBase::CheckWidgetArray(TSubclassOf<class UUserWidget> CheckWidget)
{
	for (UUserWidget* Widget : ActiveWidgetArray)
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