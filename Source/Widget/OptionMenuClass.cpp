// Fill out your copyright notice in the Description page of Project Settings.


#include "OptionMenuClass.h"
#include "GameHUDBase.h"
#include "GamePlay/GameInstanceBase.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GamePlay/MultiGameModeBase.h"
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

	FText PlayerSettingName = MyGameInstance->GetPlayerSaveDataName();
	if (PlayerSettingName.ToString() != "")
	{
		OptionMenu.UserNameBox->SetText(PlayerSettingName);
	}
	else
	{
		OptionMenu.UserNameBox->SetText(FText::FromString("Enter Name"));
	}

	SaveGameCheck();
}

void UOptionMenuClass::SaveGameCheck()
{
	AMultiGameModeBase* MyGameMode = Cast<AMultiGameModeBase>(UGameplayStatics::GetGameMode(this));

	FText PlayerSettingName = MyGameInstance->GetPlayerSaveDataName();
	bool bCheck = UGameplayStatics::DoesSaveGameExist(PlayerSettingName.ToString(), 0);

	if (bCheck)
	{
		LoadGame();
	}
	else
	{
		SaveGame();
	}
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


	CharacterData.PlayerName = OptionMenu.UserNameBox->GetText();
	SaveGame();
	MyGameInstance->ShowMainMenu();
}

void UOptionMenuClass::ClickedRightButton()
{
	AvatorCount = UKismetMathLibrary::Clamp(AvatorCount + 1, 0, Avators.Num() - 1);
	OptionMenu.AvatorImage->SetBrushFromTexture(Avators[AvatorCount]);

	CharacterData.PlayerImage = Avators[AvatorCount];
}

void UOptionMenuClass::ClickedLeftButton()
{
	AvatorCount = UKismetMathLibrary::Clamp(AvatorCount - 1, 0, Avators.Num() - 1);
	OptionMenu.AvatorImage->SetBrushFromTexture(Avators[AvatorCount]);

	CharacterData.PlayerImage = Avators[AvatorCount];
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

void UOptionMenuClass::LoadGame()
{
	USaveGame* Data = UGameplayStatics::LoadGameFromSlot(OptionMenu.UserNameBox->GetText().ToString(), 0);
	USaveGameData* newSaveData = Cast<USaveGameData>(Data);

	CharacterData = newSaveData->GetPlayerInfo();
}

void UOptionMenuClass::SaveGame()
{
	AMultiGameModeBase* MyGameMode = Cast<AMultiGameModeBase>(UGameplayStatics::GetGameMode(this));

	if (MyGameMode->SaveDataInfo == nullptr)
	{
		USaveGame* Data = UGameplayStatics::CreateSaveGameObject(MyGameMode->SaveGameClass);
		USaveGameData* newSaveData = Cast<USaveGameData>(Data);

		MyGameMode->SaveDataInfo = newSaveData;
	}

	CharacterData.PlayerImage = Avators[AvatorCount];
	CharacterData.PlayerName = OptionMenu.UserNameBox->GetText();
	CharacterData.PlayerStatus = FText::FromString("");
	CharacterData.PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	if (MyGameMode->SaveDataInfo != nullptr)
		MyGameMode->SaveDataInfo->SetPlayerInfo(CharacterData);

	MyGameInstance->SetSaveDataName(OptionMenu.UserNameBox->GetText());

	UGameplayStatics::SaveGameToSlot(MyGameMode->SaveDataInfo, CharacterData.PlayerName.ToString(),0);
}