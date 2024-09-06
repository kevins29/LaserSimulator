// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "LSCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class LASERSIMULATOR_API ALSCameraActor : public ACameraActor
{
	GENERATED_BODY()
	

public:

	ALSCameraActor();

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	float XGap = 700;

protected:

	UPROPERTY(Transient)
	class ALSCharacter* Character;


private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
