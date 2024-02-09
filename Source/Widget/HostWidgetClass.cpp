// Fill out your copyright notice in the Description page of Project Settings.


#include "HostWidgetClass.h"
#include "GamePlay/GameInstanceBase.h"
#include "GameHUDBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetTextLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"

void UHostWidgetClass::NativeOnInitialized()
{
	Super::NativeOnInitialized();


}

void UHostWidgetClass::NativeConstruct()
{
	Super::NativeConstruct();

	CheckWidget();
	MyGameInstance = Cast<UGameInstanceBase>(GetGameInstance());
}

void UHostWidgetClass::CheckWidget()
{
	if (HostMenu.AcceptButton == nullptr)
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
		HostMenu.AcceptButton->OnClicked.AddDynamic(this, &UHostWidgetClass::AcceptButtonClicked);
	}

	if (HostMenu.BackButton == nullptr)
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
		HostMenu.BackButton->OnClicked.AddDynamic(this, &UHostWidgetClass::BackButtonClicked);
	}

	if (HostMenu.DecreaseButton == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind DecreaseButton"))
		);
	}
	else
	{
		HostMenu.DecreaseButton->OnClicked.AddDynamic(this, &UHostWidgetClass::DecreaseButtonClicked);
	}

	if (HostMenu.IncreaseButton == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind IncreaseButton"))
		);
	}
	else
	{
		HostMenu.IncreaseButton->OnClicked.AddDynamic(this, &UHostWidgetClass::IncreaseButtonClicked);
	}

	if (HostMenu.DecreaseButton_2 == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind Decrease2Button"))
		);
	}
	else
	{
		HostMenu.DecreaseButton_2->OnClicked.AddDynamic(this, &UHostWidgetClass::Decrease2ButtonClicked);
	}

	if (HostMenu.IncreaseButton_2 == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind Increase2Button"))
		);
	}
	else
	{
		HostMenu.IncreaseButton_2->OnClicked.AddDynamic(this, &UHostWidgetClass::Increase2ButtonClicked);
	}
}

void UHostWidgetClass::AcceptButtonClicked()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetOwningPlayerPawn()->GetController());
	AGameHUDBase* MyGameHUD = Cast<AGameHUDBase>(PlayerController->GetHUD());

	FText Name = HostMenu.EditableTextBox->GetText();
	bool EnableLan = false;

	if (HostMenu.ButtonText_2->GetText().ToString() == "LAN")
		EnableLan = true;

	MyGameHUD->RemovWidget(EWidgetName::HostMenu);
	MyGameInstance->LaunchLobby(PlayerOfNumber,EnableLan, Name);
}

void UHostWidgetClass::BackButtonClicked()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetOwningPlayerPawn()->GetController());
	AGameHUDBase* MyGameHUD = Cast<AGameHUDBase>(PlayerController->GetHUD());

	MyGameHUD->RemovWidget(EWidgetName::HostMenu);
	MyGameInstance->ShowMainMenu();
}

void UHostWidgetClass::DecreaseButtonClicked()
{
	PlayerOfNumber = UKismetMathLibrary::Clamp(PlayerOfNumber - 1,2,MaxPlayerCount);
	HostMenu.ButtonText->SetText(UKismetTextLibrary::Conv_IntToText(PlayerOfNumber));
}

void UHostWidgetClass::IncreaseButtonClicked()
{
	PlayerOfNumber = UKismetMathLibrary::Clamp(PlayerOfNumber + 1, 2, MaxPlayerCount);
	HostMenu.ButtonText->SetText(UKismetTextLibrary::Conv_IntToText(PlayerOfNumber));
}

void UHostWidgetClass::Decrease2ButtonClicked()
{
	HostMenu.ButtonText_2->SetText(FText::FromString("INTERNET"));
}

void UHostWidgetClass::Increase2ButtonClicked()
{
	HostMenu.ButtonText_2->SetText(FText::FromString("LAN"));
}