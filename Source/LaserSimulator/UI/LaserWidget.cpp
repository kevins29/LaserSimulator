// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/LaserWidget.h"
#include "Components/Button.h"

void ULaserWidget::CloseUI()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void ULaserWidget::OpenUI()
{
	SetVisibility(ESlateVisibility::Visible);
	AddToViewport();

}

void ULaserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CloseUIButton)
	{
		CloseUIButton->OnClicked.AddDynamic(this, &ULaserWidget::OnButtonCliked);
	}
}

void ULaserWidget::OnButtonCliked()
{
	CloseUI();
}