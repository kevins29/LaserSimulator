// Fill out your copyright notice in the Description page of Project Settings.


#include "General/LSPlayerController.h"
#include "Character/LSCharacter.h"


void ALSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MovementX", this, &ALSPlayerController::InputMovementX);
	InputComponent->BindAxis("MovementY", this, &ALSPlayerController::InputMovementY);

	InputComponent->BindAction("Interact",IE_Pressed, this, &ALSPlayerController::InputInteract);
}

void ALSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<ALSCharacter>(GetPawn());
}

void ALSPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALSPlayerController::InputMovementX(float Value)
{
	if (Character)
	{
		Character->InputMovement.X = Value;
	}
}

void ALSPlayerController::InputMovementY(float Value)
{
	if (Character)
	{
		Character->InputMovement.Y = Value;
	}
}

void ALSPlayerController::InputInteract()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("pressed"));
}
