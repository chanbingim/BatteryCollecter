// Fill out your copyright notice in the Description page of Project Settings.


#include "ServerMenuClass.h"
#include "GameHUDBase.h"
#include "GamePlay/GameInstanceBase.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetTextLibrary.h"
#include "Components/WidgetSwitcher.h"
#include "JoinSessionCallbackProxy.h"
#include "CreateSessionCallbackProxy.h"

void UServerMenuClass::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UServerMenuClass::NativeConstruct()
{
	Super::NativeConstruct();

	CheckWidget();
	MyGameInstance = Cast<UGameInstanceBase>(GetGameInstance());

	TimerDelegate.BindDynamic(this, &UServerMenuClass::TimerFunction);
}

void UServerMenuClass::CheckWidget()
{
	if (ServerMenu.AccpetButton == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind AcceptButton"))
		);
	}
	else
	{
		ServerMenu.AccpetButton->OnClicked.AddDynamic(this, &UServerMenuClass::ClickedAcceptButton);
	}

	if (ServerMenu.BackButton == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind BackButton"))
		);
	}
	else
	{
		ServerMenu.BackButton->OnClicked.AddDynamic(this, &UServerMenuClass::ClickedBackButton);
	}

	if (ServerMenu.RightButton == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind LeftButton"))
		);
	}
	else
	{
		ServerMenu.RightButton->OnClicked.AddDynamic(this, &UServerMenuClass::ClickedRightButton);
	}

	if (ServerMenu.LeftButton == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind RightButton"))
		);
	}
	else
	{
		ServerMenu.LeftButton->OnClicked.AddDynamic(this, &UServerMenuClass::ClickedLeftButton);
	}
}

void UServerMenuClass::ClickedRightButton()
{
	ServerMenu.LanTextBlock->SetText(FText::FromString("INTERNET"));
}

void UServerMenuClass::ClickedLeftButton()
{
	ServerMenu.LanTextBlock->SetText(FText::FromString("LAN"));
}

void UServerMenuClass::ClickedBackButton()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetOwningPlayerPawn()->GetController());
	AGameHUDBase* MyGameHUD = Cast<AGameHUDBase>(PlayerController->GetHUD());

	MyGameHUD->CheckWidgetArray(MyGameHUD->CheckWidgetClass(EWidgetName::ServerMenu))->SetVisibility(ESlateVisibility::Hidden);;
	MyGameInstance->ShowMainMenu();
}

void UServerMenuClass::ClickedAcceptButton()
{
	ServerMenu.Siwtcher->SetActiveWidgetIndex(0);
	
	SuccessFindSession();
}

void UServerMenuClass::DisplaySession()
{
	ServerMenu.Siwtcher->SetActiveWidgetIndex(1);
	FTimerHandle TimerHandle = UKismetSystemLibrary::K2_SetTimerDelegate(TimerDelegate, 1.0f, false);
}

void UServerMenuClass::SuccessFindSession()
{
	AGameHUDBase* MyGameHUD = Cast<AGameHUDBase>(GetOwningPlayer()->GetHUD());
	MyGameInstance->JoinGameSession();

	if (MyGameInstance->bFindSession)
	{
		ServerMenu.Siwtcher->SetActiveWidgetIndex(2);
		DisplaySession();
	}
	else
	{
		ServerMenu.Siwtcher->SetActiveWidgetIndex(0);
		
	}
}

void UServerMenuClass::FailureFindSession()
{
	ServerMenu.Siwtcher->SetActiveWidgetIndex(0);
}

void UServerMenuClass::TimerFunction()
{
	for (int i = 10; i >= 0; i--)
	{
		ServerMenu.CountTextBlock->SetText(UKismetTextLibrary::Conv_IntToText(i));
	}
}