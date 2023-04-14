// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"
// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	OriginalLocation = GetOwner()->GetActorLocation();
	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// if(canMove)
	// {
	// 	FVector CurrentLocation = GetOwner()->GetActorLocation();
	// 	FVector TargetLocation = OriginalLocation + MoveOffset;
	// 	float Speed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;

	// 	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
	// 	GetOwner()->SetActorLocation(NewLocation);
	// }
	// else
	// 	UE_LOG(LogTemp, Warning, TEXT("Can't move"));


	//make the object rotate 360 degrees in 4 seconds
	if(canMove)
	{
		FRotator NewRotation = FRotator(0, 0, 0);
		NewRotation.Yaw = FMath::FInterpConstantTo(GetOwner()->GetActorRotation().Yaw, 360, DeltaTime, 90);
		GetOwner()->SetActorRotation(NewRotation);
	}

}