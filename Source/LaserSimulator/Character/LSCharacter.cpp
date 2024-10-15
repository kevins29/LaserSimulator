// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LSCharacter.h"
#include "Camera/LSCameraActor.h"

#include "Kismet/GameplayStatics.h"

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
	
	Camera = Cast<ALSCameraActor>(UGameplayStatics::GetActorOfClass(GetWorld(), ALSCameraActor::StaticClass()));
}

void ALSCharacter::OpenUI()
{

}

// Called every frame
void ALSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Camera) 
	{
		FRotator CameraRotation = Camera->GetActorRotation();

		//Set Charater MovementDirection based on the derection of the camera
		FVector ForwardDirection = FRotationMatrix(CameraRotation).GetUnitAxis(EAxis::X);
		FVector RightDirection = FRotationMatrix(CameraRotation).GetUnitAxis(EAxis::Y);

		FVector MovementDirection = (ForwardDirection * InputMovement.X) + (RightDirection * InputMovement.Y);
		AddMovementInput(MovementDirection);

		if (MovementDirection.Size2D() > 0)
		{
			LastMovementDirection = MovementDirection;
		}
	}
}

// Called to bind functionality to input
void ALSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

