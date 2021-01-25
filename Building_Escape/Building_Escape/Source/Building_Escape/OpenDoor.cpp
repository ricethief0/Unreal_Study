// Copyright HJY20210121


#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	InitYaw = GetOwner()->GetActorRotation().Yaw;
	//DoorOpenAngle = GetOwner()->GetActorRotation().Yaw - 90.f;
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor(DeltaTime);
		DoorLastOpen = GetWorld()->GetTimeSeconds();
	}
	else if (PressurePlate)
	{
		if(DoorCloseDelay < GetWorld()->GetTimeSeconds()- DoorLastOpen)
			CloseDoor(DeltaTime);

	}
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	float CurruntYaw = GetOwner()->GetActorRotation().Yaw;
	CurruntYaw = FMath::Lerp(CurruntYaw, DoorOpenAngle, DeltaTime * 1.0f);
	FRotator yaw(0.f, CurruntYaw, 0.f);
	GetOwner()->SetActorRotation(yaw);
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	float CurruntYaw = GetOwner()->GetActorRotation().Yaw;
	CurruntYaw = FMath::Lerp(CurruntYaw, InitYaw, DeltaTime * 1.0f);
	FRotator yaw(0.f, CurruntYaw, 0.f);
	GetOwner()->SetActorRotation(yaw);
}

