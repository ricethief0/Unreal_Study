// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTank.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"


 //Called when the game starts or when spawned
void APawnTank::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerRef = Cast<APlayerController>(GetController());
	
}

void APawnTank::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

APawnTank::APawnTank()
{
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Rotate();
	Move(); 
	//aplayercontroller 에 대해서 알아보기 
	//GethitResultUnderCursor함수에 대해서도 알아보기 
	// FHitResult에 대해서도 알아보기 
	// ImpcatPoint에 대해서도 알아보기 
	//이 밑에 구현으로 인해 마우스에 따라 터렛이 회전함. 

	if(PlayerControllerRef)
	{
		FHitResult TraceHitResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECC_Visibility, false, TraceHitResult);
		
		
		FVector HitLocation = TraceHitResult.ImpactPoint;
		RotateTurret(HitLocation);
	}

}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&APawnTank::CalculateMoveInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalculateRotateInput);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APawnTank::Fire);
		/*PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &APawnTank::BeginCrouch);
		PlayerInputComponent->BindAction("Crouch", IE_Released, this, &APawnTank::LeaveCrouch);*/


}

void APawnTank::CalculateMoveInput(float Value)
{
	MoveDirection = FVector(Value*MoveSpeed*GetWorld()->DeltaTimeSeconds,0,0);
}

void APawnTank::CalculateRotateInput(float Value)
{
	float RotateAmount = Value * RotateSpeed * GetWorld()->DeltaTimeSeconds;
	FRotator Rotation = FRotator(0, RotateAmount, 0);
	RotationDirection = FQuat(Rotation);
}

void APawnTank::Move()
{
	AddActorLocalOffset(MoveDirection, true);
}

void APawnTank::Rotate()
{
	AddActorLocalRotation(RotationDirection, true);
}
