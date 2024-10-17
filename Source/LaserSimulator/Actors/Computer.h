// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Computer.generated.h"

UCLASS()
class LASERSIMULATOR_API AComputer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AComputer();

	UPROPERTY(Transient)
	class ALSCharacter* Character;

	UPROPERTY(Transient)
	bool CanInteractWithPc = false;

	UPROPERTY(Transient)
	bool bIsComputerOn = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PCinteract();

};
