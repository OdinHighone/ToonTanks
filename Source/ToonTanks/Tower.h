// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

private:
	ATower();

protected:
	float warningRange = 0;
	float fireRange = 0;
	void checkFireRange();
	class ATank* playerPointer = nullptr;

	virtual void Tick(float DeltaSeconds) override;

	bool checkFireCondition();

	virtual void BeginPlay() override;

public:
	FTimerHandle CurrentTimer;

	void HandleDestruction();
};
