// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LSCharacter.h"

// Sets default values
ALSCharacter::ALSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALSCharacter::OpenUI()
{

}

// Called every frame
void ALSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MovementDirection = FVector(InputMovement.X, InputMovement.Y, 0);
	AddMovementInput(MovementDirection);
	if (MovementDirection.Size2D() > 0)
	{
		LastMovementDirection = MovementDirection;
	}

}

// Called to bind functionality to input
void ALSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

