// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SettingsWidget.h"
#include "General/LSPlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "ImageUtils.h"

void USettingsWidget::CloseUI()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void USettingsWidget::OpenUI()
{
	SetVisibility(ESlateVisibility::Visible);
	AddToViewport();

}

void USettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CloseUIButton)
	{
		CloseUIButton->OnClicked.AddDynamic(this, &USettingsWidget::OnButtonCliked);
	}

	if (OpenFileButton) 
	{
		OpenFileButton->OnClicked.AddDynamic(this, &USettingsWidget::OnButtonOpenFileCliked);
	}
}

void USettingsWidget::OnButtonCliked()
{
	CloseUI();
}

void USettingsWidget::OnButtonOpenFileCliked()
{
	ALSPlayerController* PlayerController = Cast<ALSPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (PlayerController) 
	{
		PlayerController->LoadImageFromPC(this);
	}
}

void USettingsWidget::UpdtadeImage(UTexture2D* LoadedTexture)
{
	if (LoadedTexture && ImageWidget) 
	{
		ImageWidget->SetBrushFromTexture(LoadedTexture);
	}
}
