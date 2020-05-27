// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid_Actor.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/CollisionProfile.h"


// Sets default values
AAsteroid_Actor::AAsteroid_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Mesh component
	static ConstructorHelpers::FObjectFinder<UStaticMesh> AsteroidMesh(TEXT("/Game/Meshes/Asteroid.Asteroid"));
	Asteroid_Mesh_Component = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Asteroid_Mesh"));
	RootComponent = Asteroid_Mesh_Component;
	Asteroid_Mesh_Component->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	Asteroid_Mesh_Component->SetStaticMesh(AsteroidMesh.Object);
		
	// collision sphere
	Sphere_Radius = 100.0f;
	Asteroid_Collision_Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Asteroid Sphere Component"));
	Asteroid_Collision_Sphere->InitSphereRadius(Sphere_Radius);
	Asteroid_Collision_Sphere->SetCollisionProfileName("Trigger");
	Asteroid_Collision_Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAsteroid_Actor::OnOverlapBegin);
	Asteroid_Collision_Sphere->SetupAttachment(Asteroid_Mesh_Component);

}

// Called when the game starts or when spawned
void AAsteroid_Actor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AAsteroid_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// moves the actor
	FVector Offset = FVector(1, 0, 0);
	AddActorWorldOffset(Offset);
}

void AAsteroid_Actor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		Destroy();
	}
}



