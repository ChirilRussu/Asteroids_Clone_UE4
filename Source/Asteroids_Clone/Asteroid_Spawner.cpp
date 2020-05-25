// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid_Spawner.h"
#include "Components/StaticMeshComponent.h"



// Sets default values for this component's properties
UAsteroid_Spawner::UAsteroid_Spawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAsteroid_Spawner::BeginPlay()
{
	Super::BeginPlay();

	FVector Location = FVector(0, 0, 300);
	FRotator Rotation = FRotator(0, 0, 0);
	Spawn_Asteroid(Location, Rotation);

	
	
}


// Called every frame
void UAsteroid_Spawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAsteroid_Spawner::Spawn_Asteroid(FVector Location, FRotator Rotation)
{
	FActorSpawnParameters SpawnParameters;
	AActor* SpawnedAsteroidRef = GetWorld()->SpawnActor<AActor>(Spawned_Asteroids, Location, Rotation, SpawnParameters);
}