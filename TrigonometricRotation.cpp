// Fill out your copyright notice in the Description page of Project Settings.


#include "TrigonometricRotation.h"

// Sets default values for this component's properties
UTrigonometricRotation::UTrigonometricRotation()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Parent = GetOwner();
	
	// ...
}


// Called when the game starts
void UTrigonometricRotation::BeginPlay()
{
	Super::BeginPlay();
StartRotation = Parent->GetActorRotation();
	// ...
	
}


// Called every frame
void UTrigonometricRotation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
if (Parent)
	{
		float x = MaxAngle.X * FMath::Sin(Frequency.X * RunnningTime) +StartRotation.Roll;
		float y = MaxAngle.Y * FMath::Sin(Frequency.Y * RunnningTime) + StartRotation.Pitch;
		float z = MaxAngle.Z * FMath::Sin(Frequency.Z * RunnningTime) +StartRotation.Yaw;
		Parent->SetActorRotation(FRotator(y, z, x));
		RunnningTime += DeltaTime;
	}
	// ...
}

