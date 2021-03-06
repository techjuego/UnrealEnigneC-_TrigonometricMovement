// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TrigonometricRotation.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UTrigonometricRotation : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTrigonometricRotation();
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trignometric Values")
		FVector MaxAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trignometric Values")
		FVector Frequency;

	AActor* Parent = GetOwner();
	float RunnningTime;

	UPROPERTY(VisibleAnywhere, Category = "Trignometric Values")
		FRotator StartRotation;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
