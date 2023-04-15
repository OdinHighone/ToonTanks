// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* turretMesh;

	void rotateTurret(FVector destinationPoint);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void fire();
private:
	UPROPERTY(VisibleAnywhere)
	class UCapsuleComponent* capsuleComp;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* baseMesh;

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* projectileSpawnPoint;

	UPROPERTY(EditAnywhere,meta=(AllowPrivateAccess="true"))
	float rotateRate = 100.0f;

protected:

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AProjectile> projectile;

	void HandleDestruction();
};
