// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

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


