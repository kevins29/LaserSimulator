// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PauseWidget.h"
#include "Components/Button.h"

void UPauseWidget::HideUI()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UPauseWidget::ShowUI()
{
	SetVisibility(ESlateVisibility::Visible);
	AddToViewport();

}

void UPauseWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ClosePauseWidget)
	{
		ClosePauseWidget->OnClicked.AddDynamic(this, &UPauseWidget::OnButtonCliked);
	}
}

void UPauseWidget::OnButtonCliked()
{
	HideUI();
}

