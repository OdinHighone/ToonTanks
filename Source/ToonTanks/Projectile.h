// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void onHit(UPrimitiveComponent* HitComp,AActor* OtherActor,UPrimitiveComponent* OtherComp,FVector NormalImpulse,const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	float damageAmount = 10.0f;
protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* bulletMesh;

	UPROPERTY(EditAnywhere)
	class UProjectileMovementComponent* projectileMovementComponent;

	UPROPERTY(EditDefaultsOnly)
	class UParticleSystem* onHitParticle;

	UPROPERTY(EditAnywhere)
	class UParticleSystemComponent* trailParticle;

	UPROPERTY(EditAnywhere)
	class USoundBase* hitSound;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UMatineeCameraShake> hitShake;
};
