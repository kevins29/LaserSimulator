// Fill out your copyright notice in the Description page of Project Settings.


#include "General/LSPlayerController.h"
#include "Character/LSCharacter.h"
#include "Managers/LaserSimulatorManager.h"
#include "Actors/Computer.h"
#include "Actors/Laser.h"

#include "Kismet/GameplayStatics.h"


void ALSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MovementX", this, &ALSPlayerController::InputMovementX);
	InputComponent->BindAxis("MovementY", this, &ALSPlayerController::InputMovementY);

	InputComponent->BindAction("Interact",IE_Pressed, this, &ALSPlayerController::InputInteract);
	InputComponent->BindAction("Pause", IE_Pressed, this, &ALSPlayerController::InputPauseMenu);
}

void ALSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<ALSCharacter>(GetPawn());
	Computer = Cast<AComputer>(UGameplayStatics::GetActorOfClass(GetWorld(), AComputer::StaticClass()));
	Laser = Cast<ALaser>(UGameplayStatics::GetActorOfClass(GetWorld(), ALaser::StaticClass()));
	LaserManager = Cast<ALaserSimulatorManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ALaserSimulatorManager::StaticClass()));
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
		Computer->PCInteract();
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("InteractWithPc"));
		
		if (Computer->bIsComputerOn) 
		{
			Laser->LaserInteract();
		}
	}
}

void ALSPlayerController::DisableMouseCursor()
{
	bShowMouseCursor = false;

	SetInputMode(FInputModeGameOnly());

	SetIgnoreLookInput(false);
	SetIgnoreMoveInput(false);
}

void ALSPlayerController::EnableMouseCursor()
{
	bShowMouseCursor = true;

	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputMode);

	SetIgnoreLookInput(false);
	SetIgnoreMoveInput(false);
}

void ALSPlayerController::InputPauseMenu()
{
	if (LaserManager) 
	{
		if (!bShouldCreateWidget)
		{
			LaserManager->OpenPauseUI();
			
			bShouldCreateWidget = true;
		}
		else if (bShouldCreateWidget) 
		{
			LaserManager->ClosePauseUI();
			
			bShouldCreateWidget = false;
		}
	}
}
