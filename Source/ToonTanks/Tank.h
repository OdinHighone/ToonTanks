// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

protected:
	ATank();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
private:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* springArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* camera;

	UPROPERTY(EditAnywhere,meta=(AllowPrivateAccess = "true"))
	float speed = 0;

	UPROPERTY(EditAnywhere,meta=(AllowPrivateAccess = "true"))
	float turnRate = 0;
	
	class APlayerController* playerControllerReference = nullptr;

protected:
	void Move(float Value);
	void Turn(float Value);

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void HandleDestruction();

	APlayerController* getPlayerControllerRef(){ return playerControllerReference;}
};
