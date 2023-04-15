// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"

#include "DrawDebugHelpers.h"
#include "Projectile.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision Mesh"));
	RootComponent = capsuleComp;

	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	baseMesh->SetupAttachment(capsuleComp);

	turretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	turretMesh->SetupAttachment(baseMesh);

	projectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	projectileSpawnPoint->SetupAttachment(turretMesh);
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePawn::rotateTurret(FVector destinationPoint)
{
	FVector hitLocationVector =  destinationPoint - turretMesh->GetComponentLocation();
	FRotator hitLocationRotator = FRotator(0.f,hitLocationVector.Rotation().Yaw,0.f);

	hitLocationRotator=FMath::RInterpTo(turretMesh->GetComponentRotation(),hitLocationRotator,UGameplayStatics::GetWorldDeltaSeconds(this),rotateRate);
	turretMesh->SetWorldRotation(hitLocationRotator);
}

void ABasePawn::fire()
{
	AProjectile* projectileAccess = GetWorld()->SpawnActor<AProjectile>(projectile,projectileSpawnPoint->GetComponentLocation(),projectileSpawnPoint->GetComponentRotation());
	projectileAccess->SetOwner(this);
}

void ABasePawn::HandleDestruction()
{
	//TODO handle VIsuals and sound
}
