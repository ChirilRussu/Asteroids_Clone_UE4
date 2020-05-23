// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid_Actor.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"



// Sets default values
AAsteroid_Actor::AAsteroid_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereRadius = 100.0f;

	MyCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("My Sphere Component"));
	MyCollisionSphere->InitSphereRadius(SphereRadius);
	MyCollisionSphere->SetCollisionProfileName("Trigger");
	RootComponent = MyCollisionSphere;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	MyMesh->SetupAttachment(RootComponent);

	MyCollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AAsteroid_Actor::OnOverlapBegin);

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


	DrawDebugSphere(GetWorld(), GetActorLocation(), SphereRadius, 20, FColor::Purple, false, -1, 0, 1);
}

void AAsteroid_Actor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		Destroy();
	}
}


