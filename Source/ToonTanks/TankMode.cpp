// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMode.h"

#include "gamePlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"

void ATankMode::onDestruction(AActor* DestroyedActor)
{
	if(DestroyedActor == tankPointer)
	{
		tankPointer->HandleDestruction();
		if(gamePlayerController)
		{
			gamePlayerController->setPlayerInputState(false);
			gameOver(false);
		}
	}
	else if(ATower* towerPointer = Cast<ATower>(DestroyedActor))
	{
		towerPointer->HandleDestruction();
		totalTowers--;
		if(totalTowers==0)
		{
			gameOver(true);
		}
	}
}

void ATankMode::BeginPlay()
{
	Super::BeginPlay();
	gameStart();

	TArray<AActor*> towers;
	UGameplayStatics::GetAllActorsOfClass(this,ATower::StaticClass(),towers);
	totalTowers = towers.Num();
}

void ATankMode::gameStart()
{
	startGameWidget();
	
	tankPointer = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
	gamePlayerController = Cast<AgamePlayerController>(UGameplayStatics::GetPlayerController(this,0));

	if(gamePlayerController)
	{
		gamePlayerController->setPlayerInputState(false);

		FTimerHandle startTimer;
		FTimerDelegate timerFunctionHandler = FTimerDelegate::CreateUObject(gamePlayerController,&AgamePlayerController::setPlayerInputState,true);
		GetWorldTimerManager().SetTimer(startTimer,timerFunctionHandler,startTime,false);
	}
}
