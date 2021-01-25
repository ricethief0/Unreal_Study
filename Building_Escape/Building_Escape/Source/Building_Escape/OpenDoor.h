// Copyright HJY20210121

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
private:
	UPROPERTY(EditAnywhere)
	float DoorOpenAngle ;
	float InitYaw;
	float DoorLastOpen =0.f;
	float DoorCloseDelay = 2.f;



	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;
	UPROPERTY(EditAnywhere)
	AActor* ActorThatOpens;
	//float InitYaw;
};
	