// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LSPlayerController.generated.h"

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
	
	FVector2D InputMovement = FVector2D::ZeroVector;


public:
	class ALSCharacter* Character = nullptr;

private:

	virtual void Tick(float DeltaTime) override;
	void SetupInputComponent() override;
	virtual void BeginPlay() override;

};