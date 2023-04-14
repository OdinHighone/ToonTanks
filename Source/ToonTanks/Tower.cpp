// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"

#include "Kismet/GameplayStatics.h"

ATower::ATower()
{
	warningRange = 600.0f;
	fireRange = 300.f;
}

void ATower::checkFireRange()
{
	if(checkFireCondition())
	{
		fire();
	}
}

void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	float distance = FVector::Dist(GetActorLocation(),playerPointer->GetActorLocation());
	if(distance < warningRange)
	{
		rotateTurret(playerPointer->GetActorLocation());
	}
}

bool ATower::checkFireCondition()
{
	float distance = FVector::Dist(GetActorLocation(),playerPointer->GetActorLocation());
	if(distance < fireRange)
	{
		return true;
	}
	return false;
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(CurrentTimer,this,&ATower::checkFireRange,5.0f,true);
	playerPointer = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
}