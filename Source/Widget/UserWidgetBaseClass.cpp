// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetBaseClass.h"
#include "GamePlay/GameInstanceBase.h"
#include "GameHUDBase.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/Button.h"

void UUserWidgetBaseClass::CheckWidget()
{
	if (MainMenuEdit.FindButton == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind FindButton"))
		);
	}
	else
	{
		MainMenuEdit.FindButton->OnClicked.AddDynamic(this, &UUserWidgetBaseClass::ClickFindButton);
	}

	if (MainMenuEdit.OptionButton == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind OptionButton"))
		);
	}
	else
	{
		MainMenuEdit.OptionButton->OnClicked.AddDynamic(this, &UUserWidgetBaseClass::ClickOptionButton);
	}

	if (MainMenuEdit.HostButton == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind HostButton"))
		);
	}
	else
	{
		MainMenuEdit.HostButton->OnClicked.AddDynamic(this, &UUserWidgetBaseClass::ClickHostButton);
	}

	if (MainMenuEdit.QuitButton == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.0f,
			FColor::Blue,
			FString(TEXT("None Bind QuitButton"))
		);
	}
	else
	{
		MainMenuEdit.QuitButton->OnClicked.AddDynamic(this, &UUserWidgetBaseClass::ClickQuitButton);
	}
}

void UUserWidgetBaseClass::NativeOnInitialized()
{
	Super::NativeOnInitialized();


}

void UUserWidgetBaseClass::NativeConstruct()
{
	Super::NativeConstruct();

	CheckWidget();
	MyGameInstance = Cast<UGameInstanceBase>(GetGameInstance());
}

void UUserWidgetBaseClass::ClickFindButton()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetOwningPlayerPawn()->GetController());
	AGameHUDBase* MyGameHUD = Cast<AGameHUDBase>(PlayerController->GetHUD());

	MyGameHUD->RemovWidget(EWidgetName::MainMenu);
	MyGameInstance->ShowServerMenu();
}

void UUserWidgetBaseClass::ClickHostButton()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetOwningPlayerPawn()->GetController());
	AGameHUDBase* MyGameHUD = Cast<AGameHUDBase>(PlayerController->GetHUD());

	MyGameHUD->RemovWidget(EWidgetName::MainMenu);
	MyGameInstance->ShowHostMenu();
}

void UUserWidgetBaseClass::ClickOptionButton()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetOwningPlayerPawn()->GetController());
	AGameHUDBase* MyGameHUD = Cast<AGameHUDBase>(PlayerController->GetHUD());

	MyGameHUD->RemovWidget(EWidgetName::MainMenu);
	MyGameInstance->ShowOptionMenu();
}

void UUserWidgetBaseClass::ClickQuitButton()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}
