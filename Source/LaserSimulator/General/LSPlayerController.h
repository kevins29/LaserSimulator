// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LSPlayerController.generated.h"

class USettingsWidget;

/**
 * 
 */
UCLASS()
class LASERSIMULATOR_API ALSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	void InputMovementX(float Value);
	void InputMovementY(float Value);

	void InteractWithObject();

	UFUNCTION(BlueprintCallable)
	void DisableMouseCursor();

	UFUNCTION(BlueprintCallable)
	void EnableMouseCursor();

	void InputPauseMenu();
	
	void LoadImageFromPC(USettingsWidget* InWidget);

	FVector2D InputMovement = FVector2D::ZeroVector;

	bool bShouldCreateWidget = true;

	bool bCanStartEngraving = false;

	FString ExportedFilePath;


public:
	class ALSCharacter* Character = nullptr;

	UPROPERTY(Transient)
	class AComputer* Computer;

	UPROPERTY(Transient)
	class ALaser* Laser;

	UPROPERTY(Transient)
	class ALaserSimulatorManager* LaserManager;

	FString OpenFileDialogue();
	UTexture2D* LoadedTextureFromFile(const FString& FilePath);

private:

	virtual void Tick(float DeltaTime) override;
	void SetupInputComponent() override;
	virtual void BeginPlay() override;

	
};
