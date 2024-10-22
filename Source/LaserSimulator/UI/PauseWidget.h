// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseWidget.generated.h"

/**
 * 
 */
UCLASS()
class LASERSIMULATOR_API UPauseWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void HideUI();

	UFUNCTION(BlueprintCallable)
	void ShowUI();

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	class UButton* ClosePauseWidget;

	UFUNCTION()
	void OnButtonCliked();
	
};
