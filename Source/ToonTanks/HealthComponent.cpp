// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "TankMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	health = maxHealth;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this,&UHealthComponent::DamageTaken);

	tankGameMode = Cast<ATankMode>(UGameplayStatics::GetGameMode(this));
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser)
{
	if(Damage <= 0.f) return;

	health -= Damage;
	UE_LOG(LogTemp,Warning,TEXT("Actor %s Health %f"),*DamagedActor->GetName(),health);

	if(health <= 0 && tankGameMode)
	{
		tankGameMode->onDestruction(DamagedActor);
	}
}


