// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SettingsWidget.h"
#include "Components/Button.h"

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
}

void USettingsWidget::OnButtonCliked()
{
	CloseUI();
}
