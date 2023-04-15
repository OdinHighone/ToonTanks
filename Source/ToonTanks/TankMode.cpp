// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMode.h"

#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"

void ATankMode::onDestruction(AActor* DestroyedActor)
{
	if(DestroyedActor == tankPointer)
	{
		tankPointer->HandleDestruction();
		if(tankPointer->getPlayerControllerRef())
		{
			tankPointer->DisableInput(tankPointer->getPlayerControllerRef());
			tankPointer->getPlayerControllerRef()->bShowMouseCursor = false;
		}
	}
	else if(ATower* towerPointer = Cast<ATower>(DestroyedActor))
	{
		towerPointer->HandleDestruction();
	}
}

void ATankMode::BeginPlay()
{
	Super::BeginPlay();
	tankPointer = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
}
