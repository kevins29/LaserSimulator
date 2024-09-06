// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/LSCameraActor.h"
#include "Character/LSCharacter.h"
#include "Kismet/GameplayStatics.h"

ALSCameraActor::ALSCameraActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALSCameraActor::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<ALSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void ALSCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Character)
	{
		FVector NewCameraLocation = GetActorLocation();
		NewCameraLocation.X = Character->GetActorLocation().X - XGap;

		SetActorLocation(NewCameraLocation);
	}
}
