// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	springArm->SetupAttachment(RootComponent);

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(springArm);

	speed = 250.0f;
	turnRate = 100.0f;
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Move"),this,&ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"),this,&ATank::Turn);
	PlayerInputComponent->BindAction(TEXT("Fire"),IE_Pressed,this,&ABasePawn::fire);
}

void ATank::Move(float Value)
{
	FVector MovementOffset = FVector::ZeroVector;
	MovementOffset.X = speed * Value * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(MovementOffset,true);
}

void ATank::Turn(float Value)
{
	FRotator RotationOffset = FRotator::ZeroRotator;
	RotationOffset.Yaw = turnRate * Value * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(RotationOffset,true);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	playerControllerReference = Cast<APlayerController>(GetController());
}

void ATank::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	FHitResult hitResult;

	if(playerControllerReference)
	{
		playerControllerReference->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,true,hitResult);
		rotateTurret(hitResult.ImpactPoint);
	}
}

void ATank::HandleDestruction()
{
	Super::HandleDestruction();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
}

