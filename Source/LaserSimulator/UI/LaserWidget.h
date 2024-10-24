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

	UPROPERTY(Transient)
	FString ExportedFilePath;

public:

	UFUNCTION(BlueprintCallable)
	void CloseUI();

	UFUNCTION(BlueprintCallable)
	void OpenUI();

	UFUNCTION(BlueprintCallable)
	void SetExportedFile(FString InFilePath) 
	{
		ExportedFilePath = InFilePath;
	}

	UFUNCTION(BlueprintCallable)
	void StartEngraving();

	UPROPERTY(meta = (BindWidget))
	class UButton* CloseUIButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* StartEngravingButton;

	UFUNCTION()
	void OnButtonCliked();

protected:

	virtual void NativeConstruct() override;

	void SpawnEngravingWidget();
	
};
