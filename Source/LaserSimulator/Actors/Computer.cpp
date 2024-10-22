// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Computer.h"
#include "Character/LSCharacter.h"
#include "UI/SettingsWidget.h"
#include "General/LSPlayerController.h"

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

	PlayerController = Cast<ALSPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (WSettings)
	{
		WidgetSettings = CreateWidget<USettingsWidget>(GetWorld(), WSettings);

		if (WidgetSettings)
		{
			WidgetSettings->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

// Called every frame
void AComputer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bIsInCharacterRange();

	if (WidgetSettings && PlayerController)
	{
		if (bIsComputerOn && !bIsInCharacterRange())
		{
			WidgetSettings->CloseUI();

			PlayerController->bShowMouseCursor = false;
		}
	}
}

void AComputer::PCInteract()
{
	if (!Character || !PlayerController)
		return;

	if (WidgetSettings && CanInteractWithPc)
	{
		bIsComputerOn = !bIsComputerOn;

		if (bIsComputerOn)
		{
			WidgetSettings->OpenUI();

			
			PlayerController->EnableMouseCursor();
			Character->bCanMoveCharacter = false;
		}
		else
		{
			WidgetSettings->CloseUI();

			CanInteractWithPc = false;
			
			PlayerController->DisableMouseCursor();
			Character->bCanMoveCharacter = true;

		}
	}
}

bool AComputer::bIsInCharacterRange()
{
	if (Character)
	{
		FVector CharaterLocation = Character->GetActorLocation();
		FVector LaserLocation = GetActorLocation();

		const float DistanceSqr = (CharaterLocation - LaserLocation).SizeSquared2D();

		return DistanceSqr <= (400 * 400) ? true : false;
	}

	return false;
}
