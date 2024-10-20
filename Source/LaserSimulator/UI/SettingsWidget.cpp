// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SettingsWidget.h"
#include "Components/Button.h"

void USettingsWidget::CloseUI()
{
	SetVisibility(ESlateVisibility::Hidden);
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}

void USettingsWidget::OpenUI()
{
	SetVisibility(ESlateVisibility::Visible);
	AddToViewport();

}

void USettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ClaseUIButton)
	{
		ClaseUIButton->OnClicked.AddDynamic(this, &USettingsWidget::OnButtonCliked);
	}
}

void USettingsWidget::OnButtonCliked()
{
	CloseUI();
}
