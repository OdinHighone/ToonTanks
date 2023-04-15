// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATankMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void onDestruction(AActor* DestroyedActor);

private:
	virtual void BeginPlay() override;

	class ATank* tankPointer = nullptr;
};
