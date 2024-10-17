// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractComponent.generated.h"

USTRUCT(BlueprintType)
struct FInteractableInfo
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditInstanceOnly)
	float DistanceToInteract = 0.f;

	UPROPERTY(EditInstanceOnly)
	FString ActorName = "";

	UPROPERTY(EditInstanceOnly)
	TSubclassOf<class UInteractableWidget> InteractableUI;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LASERSIMULATOR_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractComponent();

	UPROPERTY(EditInstanceOnly)
	TArray<FInteractableInfo> InteracInfo;

	UPROPERTY(Transient)
	TArray<AActor *> ActorList;

	UPROPERTY(Transient)
	class ALSCharacter* Character;

	UPROPERTY(Transient)
	class UInteractableWidget* UI;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	void ShowUI();
};
