// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LaserWidget.generated.h"

/**
 * 
 */
UCLASS()
class LASERSIMULATOR_API ULaserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void CloseUI();

	UFUNCTION(BlueprintCallable)
	void OpenUI();

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	class UButton* CloseUIButton;

	UFUNCTION()
	void OnButtonCliked();
	
};
