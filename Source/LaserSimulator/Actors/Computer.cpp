// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Computer.h"
#include "Character/LSCharacter.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AComputer::AComputer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AComputer::BeginPlay()
{
	Super::BeginPlay();
	
	Character = Cast<ALSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void AComputer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SearchCharacterOnRadius();
}

void AComputer::SearchCharacterOnRadius()
{
	if (Character)
	{
		const float DistanceSqr = (GetActorLocation() - Character->GetActorLocation()).SizeSquared2D();

		if (DistanceSqr <= (500 * 500))
		{
			Character->OpenUI();
		}
	}
}