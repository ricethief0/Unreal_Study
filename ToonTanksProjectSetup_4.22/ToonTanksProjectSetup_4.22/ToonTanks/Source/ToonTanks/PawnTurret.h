// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"


class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

public:
	//APawnTurret();
	virtual void Tick(float DeltaTime) override;
	virtual void HandleDestruction() override;
protected:
	virtual void BeginPlay() override;


private:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Combat",meta = (AllowPrivateAccess  = "true"))
	float FireRate = 2.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRange = 500.f;

	void CheckFireCondition();
	float ReturnDistanceToPlayer();
	FTimerHandle FireRateTimerHandle;
	APawnTank* PlayerPawn;
	
};
