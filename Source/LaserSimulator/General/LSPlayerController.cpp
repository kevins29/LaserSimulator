// Fill out your copyright notice in the Description page of Project Settings.


#include "General/LSPlayerController.h"
#include "Character/LSCharacter.h"
#include "Actors/Computer.h"
#include "Actors/Laser.h"

#include "Kismet/GameplayStatics.h"


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
	Computer = Cast<AComputer>(UGameplayStatics::GetActorOfClass(GetWorld(), AComputer::StaticClass()));
	Laser = Cast<ALaser>(UGameplayStatics::GetActorOfClass(GetWorld(), ALaser::StaticClass()));
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
	if (Computer && Laser) 
	{
		Computer->PCinteract();
		
		if (Computer->bIsComputerOn) 
		{
			Laser->LaserInteract();
		}
	}
}
