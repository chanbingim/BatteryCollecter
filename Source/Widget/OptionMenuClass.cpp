// Fill out your copyright notice in the Description page of Project Settings.


#include "OptionMenuClass.h"
#include "GameHUDBase.h"
#include "GamePlay/GameInstanceBase.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"

void UOptionMenuClass::NativeOnInitialized()
{
	Super::NativeOnInitialized();

}

void UOptionMenuClass::NativeConstruct()
{
	Super::NativeConstruct();

	CheckWidget();
	MyGameInstance = Cast<UGameInstanceBase>(GetGameInstance());
}

void UOptionMenuClass::ClickedBackButton()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetOwningPlayerPawn()->GetController());
	AGameHUDBase* MyGameHUD = Cast<AGameHUDBase>(PlayerController->GetHUD());

	MyGameHUD->RemovWidget(EWidgetName::OptionMenu);
	MyGameInstance->ShowMainMenu();
}

void UOptionMenuClass::ClickedAcceptButton()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetOwningPlayerPawn()->GetController());
	AGameHUDBase* MyGameHUD = Cast<AGameHUDBase>(PlayerController->GetHUD());

	MyGameHUD->RemovWidget(EWidgetName::OptionMenu);
}

void UOptionMenuClass::ClickedRightButton()
{

}

void UOptionMenuClass::ClickedLeftButton()
{

}

void UOptionMenuClass::CheckWidget()
{
	if (OptionMenu.UserNameBox == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind UserNameBox"))
		);
	}

	if (OptionMenu.AvatorImage == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind AvatorImage"))
		);
	}

	if (OptionMenu.AcceptButton == nullptr)
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
		OptionMenu.AcceptButton->OnClicked.AddDynamic(this, &UOptionMenuClass::ClickedAcceptButton);
	}

	if (OptionMenu.BackButton == nullptr)
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
		OptionMenu.BackButton->OnClicked.AddDynamic(this, &UOptionMenuClass::ClickedBackButton);
	}

	if (OptionMenu.LeftButton == nullptr)
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
		OptionMenu.LeftButton->OnClicked.AddDynamic(this, &UOptionMenuClass::ClickedLeftButton);
	}

	if (OptionMenu.RightButton == nullptr)
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
		OptionMenu.RightButton->OnClicked.AddDynamic(this, &UOptionMenuClass::ClickedRightButton);
	}
}