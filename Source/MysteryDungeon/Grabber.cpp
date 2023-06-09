// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "CollisionShape.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Draw a debug line
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrab;

	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 0, 0, 10);


	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRarius);

	FHitResult Hit;
	
	bool hasHit = GetWorld()->SweepSingleByChannel(Hit, Start, End, FQuat::Identity, ECC_GameTraceChannel2, Sphere);

	//print the hit actor name

	if (hasHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *Hit.GetActor()->GetActorNameOrLabel());
		
	}	
	else
		//print no actor hit
		UE_LOG(LogTemp, Warning, TEXT("No actor hit"));
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Display, TEXT("Release"));
}