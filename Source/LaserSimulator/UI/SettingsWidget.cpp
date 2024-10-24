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

	if (CloseUIButton && OpenFileButton && ExportFileButton && CutFileButton && GrabFileButton)
	{
		CloseUIButton->OnClicked.AddDynamic(this, &USettingsWidget::OnButtonCliked);
		OpenFileButton->OnClicked.AddDynamic(this, &USettingsWidget::OnButtonOpenFileCliked);
		ExportFileButton->OnClicked.AddDynamic(this, &USettingsWidget::ExportFile);
		CutFileButton->OnClicked.AddDynamic(this, &USettingsWidget::CutFile);
		GrabFileButton->OnClicked.AddDynamic(this, &USettingsWidget::GrabFile);
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
		bCanExportFile = true;
	}
}

void USettingsWidget::ExportFile()
{
	ALSPlayerController* PlayerController = Cast<ALSPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (PlayerController)
	{
		if (bCanExportFile)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("File was exported"));
			PlayerController->bCanStartEngraving = true;
		}
		else 
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Dont have file"));
		}
	}
	bCanExportFile = false;
}

void USettingsWidget::GrabFile()
{
	ALSPlayerController* PlayerController = Cast<ALSPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (PlayerController) 
	{
		if (!PlayerController->ExportedFilePath.IsEmpty()) 
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Debes seleccionar un archivo"));
		}
		else 
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Debes seleccionar un archivo"));
		}
	}
}

void USettingsWidget::CutFile()
{
	ALSPlayerController* PlayerController = Cast<ALSPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (PlayerController)
	{
		if (!PlayerController->ExportedFilePath.IsEmpty())
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("El archivo es para cortar"));
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Debes seleccionar un archivo"));
		}
	}
}
