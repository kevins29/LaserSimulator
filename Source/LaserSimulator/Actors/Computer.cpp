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

}

void AComputer::PCinteract()
{
	if (!Character)
		return;

	if (Character->bIsTraceWithActor()) 
	{
		if (CanInteractWithPc)
		{
			bIsComputerOn = !bIsComputerOn;

			if (bIsComputerOn) 
			{
				if (GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, TEXT("TurnOnPC"));
			}
			else
			{
				if (GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("TurnOffPC"));
			}
			
		}
		
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, FString::Printf(TEXT("bIsComputerOn: %s"), bIsComputerOn ? TEXT("true") : TEXT("false")));
	}
}