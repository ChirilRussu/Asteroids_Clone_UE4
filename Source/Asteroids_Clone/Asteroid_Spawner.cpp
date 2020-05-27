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
	
	
	
	
	int Number_Of_Asteroids = 5;
	for (int32 Asteroid_Increment = 0; Asteroid_Increment < Number_Of_Asteroids; Asteroid_Increment++)
	{
		// selects near which border the asteroid will spawn
		int Border_Spawn_Selection = FMath::RandRange(0, 3); // clockwise starting top
		
		// top
		if (Border_Spawn_Selection == 0) 
		{
			int Random_Location_X = 1300.0;
			int Random_Location_Y = FMath::RandRange(-2000, 2000);
			FVector Location = FVector(Random_Location_X, Random_Location_Y, 290.0);
			FRotator Rotation = FRotator(0, 0, 0);
			Spawn_Asteroid(Location, Rotation);
		}

		// right
		else if (Border_Spawn_Selection == 1)
		{
			int Random_Location_X = FMath::RandRange(-1300, 1300);
			int Random_Location_Y = 2300.0;
			FVector Location = FVector(Random_Location_X, Random_Location_Y, 290.0);
			FRotator Rotation = FRotator(0, 0, 0);
			Spawn_Asteroid(Location, Rotation);
		}

		// bottom
		else if (Border_Spawn_Selection == 2)
		{
			int Random_Location_X = -1300.0;
			int Random_Location_Y = FMath::RandRange(-2000, 2000);
			FVector Location = FVector(Random_Location_X, Random_Location_Y, 290.0);
			FRotator Rotation = FRotator(0, 0, 0);
			Spawn_Asteroid(Location, Rotation);
		}

		// left
		else if (Border_Spawn_Selection == 3)
		{
			int Random_Location_X = FMath::RandRange(-1300, 1300);
			int Random_Location_Y = -2300.0;
			FVector Location = FVector(Random_Location_X, Random_Location_Y, 290.0);
			FRotator Rotation = FRotator(0, 0, 0);
			Spawn_Asteroid(Location, Rotation);
		}
	}
}


// Called every frame
void UAsteroid_Spawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// somehow check that some number of asteroid instances exist and spawn more if needed
	// or somehow pass a check from asteroid_actor after any asteroid is destroyed
	/*
	if (!IsValid(Spawned_Asteroids)) 
	{
		// logic from begin play goes here
	}
	*/
}
	

void UAsteroid_Spawner::Spawn_Asteroid(FVector Location, FRotator Rotation)
{
	FActorSpawnParameters SpawnParameters;
	AActor* SpawnedAsteroidRef = GetWorld()->SpawnActor<AActor>(Spawned_Asteroids, Location, Rotation, SpawnParameters);
		
}