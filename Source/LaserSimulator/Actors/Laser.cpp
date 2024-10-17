// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Laser.h"
#include "Character/LSCharacter.h"
#include "Actors/Computer.h"
#include "UI/SettingsWidget.h"
#include "General/LSPlayerController.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ALaser::ALaser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALaser::BeginPlay()
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
void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bIsCharacterOnRange();

	if (WidgetSettings && PlayerController) 
	{
		if (!bIsCharacterOnRange() && WidgetSettings->Visibility != ESlateVisibility::Hidden)
		{
			WidgetSettings->SetVisibility(ESlateVisibility::Hidden);
			WidgetSettings->RemoveFromParent();

			PlayerController->bShowMouseCursor = false;
		}
	}
}

void ALaser::LaserInteract()
{
	if (!Character)
		return;

	if (Character->bIsTraceWithActor()) 
	{
		if (CanInteractWithLaser && bIsCharacterOnRange())
		{
			if (WidgetSettings && PlayerController) 
			{
				if (WidgetSettings->Visibility != ESlateVisibility::Visible)
				{
					WidgetSettings->SetVisibility(ESlateVisibility::Visible);
					WidgetSettings->AddToViewport();

					PlayerController->bShowMouseCursor = true;
				}
			}
		}
	}
}

bool ALaser::bIsCharacterOnRange()
{
	if (Character) 
	{
		FVector CharaterLocation = Character->GetActorLocation();
		FVector LaserLocation = GetActorLocation();

		const float DistanceSqr = (CharaterLocation - LaserLocation).SizeSquared2D();

		if (DistanceSqr <= (200 * 200)) 
		{
			return true;
		}
	}

	return false;
}