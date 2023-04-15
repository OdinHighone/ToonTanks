// Fill out your copyright notice in the Description page of Project Settings.


#include "gamePlayerController.h"

void AgamePlayerController::setPlayerInputState(bool state)
{
	if(state)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}
	bShowMouseCursor = state;
}
