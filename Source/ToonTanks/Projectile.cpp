// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet"));
	RootComponent = bulletMesh;

	projectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("movement component"));
	projectileMovementComponent->InitialSpeed = 1000.f;
	projectileMovementComponent->MaxSpeed = 1000.f;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bulletMesh->OnComponentHit.AddDynamic(this,&AProjectile::onHit);
}

void AProjectile::onHit(UPrimitiveComponent* HitComp,AActor* OtherActor,UPrimitiveComponent* OtherComp,FVector NormalImpulse,const FHitResult& Hit)
{
	AActor* myOwner = GetOwner();
	if(myOwner==nullptr) return;

	if(OtherActor && OtherActor != myOwner && OtherActor != this)
	{
		UGameplayStatics::ApplyDamage(OtherActor,damageAmount,myOwner->GetInstigatorController(),myOwner,UDamageType::StaticClass());
		Destroy();
	}
}


