// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid_Actor.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/CollisionProfile.h"
#include "Math/TransformNonVectorized.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/Engine.h"
#include "Math/UnrealMathUtility.h"

float Set_Hypotenuse;
float Random_Leg;
float Calculated_Leg;

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

	// sphere transformation to make it fit the asteroid better
	FRotator Sphere_Rotation = FRotator(0, 0, 0);
	FVector Sphere_Location = FVector(0, 0, 80.0);
	FVector Sphere_Scale = FVector(1.3, 1.3, 1.3);
	FTransform Sphere_All_Transforms = FTransform(Sphere_Rotation, Sphere_Location, Sphere_Scale);
	Asteroid_Collision_Sphere->SetRelativeTransform(Sphere_All_Transforms);
}

// Called when the game starts or when spawned
void AAsteroid_Actor::BeginPlay()
{
	Super::BeginPlay();

	// variables for vector calculations of the movement using pythagorean
	// the hypotenuse is constant so no matter the vector the object moves at the same speed, one of the legs is random to change the direction of the movement
	Set_Hypotenuse = 1; // c of the triangle - the linear speed at which the actor will move
	Random_Leg = FMath::RandRange(0.f, 1.f); // b of the triangle - the y of the vector
	Calculated_Leg = FMath::RoundHalfToEven((FMath::Sqrt(Set_Hypotenuse * Set_Hypotenuse - Random_Leg * Random_Leg))); // a of the triangle - the x of the vector

}

// Called every frame
void AAsteroid_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// asteroid movement
	FVector Offset = FVector(Calculated_Leg, Random_Leg, 0);
	AddActorWorldOffset(Offset);
}

void AAsteroid_Actor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		Destroy();
	}
}



