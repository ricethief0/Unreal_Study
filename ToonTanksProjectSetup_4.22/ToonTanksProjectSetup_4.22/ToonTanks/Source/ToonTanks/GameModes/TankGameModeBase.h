// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

/**
 * 
 */
class APawnTank;
class APawnTurret;
UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void ActorDied(AActor* DeadActor);

protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameLoop")
		int32 StartDelay = 3;
private:
	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);
	APawnTank* PlayerTank;
	int32 TargetTurrets = 0;
	int32 GetTargetTurretCount();
	

};
