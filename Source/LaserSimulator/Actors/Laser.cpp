// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Laser.h"
#include "Character/LSCharacter.h"
#include "Actors/Computer.h"
#include "UI/LaserWidget.h"
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
		WidgetSettings = CreateWidget<ULaserWidget>(GetWorld(), WSettings);

		if (WidgetSettings)
		{
			WidgetSettings->CloseUI();
		}
	}
}

// Called every frame
void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bIsCharacterOnRange();
	//BeginLaserEngraving();
}

void ALaser::LaserInteract()
{
	if (!Character)
		return;

	if (!PlayerController)
		return;

	if (WidgetSettings && Character->bIsTraceWithActor(this))
	{
		CanInteractWithLaser = !CanInteractWithLaser;

		if (CanInteractWithLaser)
		{
			WidgetSettings->OpenUI();
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Some debug message!"));
			PlayerController->EnableMouseCursor();
		}
		else
		{
			WidgetSettings->CloseUI();
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
			PlayerController->DisableMouseCursor();
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

		return DistanceSqr <= (200 * 200) ? true : false;
	}

	return false;
}

void ALaser::BeginLaserEngraving()
{
	if (PlayerController && WidgetSettings) 
	{
		if (!PlayerController->ExportedFilePath.IsEmpty())
		{
			WidgetSettings->SetExportedFile(PlayerController->ExportedFilePath);
		}
		
	}
}
