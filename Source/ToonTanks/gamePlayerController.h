// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "gamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AgamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void setPlayerInputState(bool state);
};
