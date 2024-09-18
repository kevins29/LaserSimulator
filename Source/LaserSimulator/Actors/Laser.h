// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Laser.generated.h"

UCLASS()
class LASERSIMULATOR_API ALaser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaser();

	UPROPERTY(Transient)
	class ALSCharacter* Character;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SearchCharacterInRadius();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
