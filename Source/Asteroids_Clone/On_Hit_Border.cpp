// Fill out your copyright notice in the Description page of Project Settings.


#include "On_Hit_Border.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AOn_Hit_Border::AOn_Hit_Border()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Use a sphere as a simple collision representation
	Border_Hit_Component = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	Border_Hit_Component->SetSimulatePhysics(false);
	Border_Hit_Component->SetNotifyRigidBodyCollision(true);

	Border_Hit_Component->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	Border_Hit_Component->OnComponentHit.AddDynamic(this, &AOn_Hit_Border::On_Border_Hit);

	// Set as root component
	RootComponent = Border_Hit_Component;

}

// Called when the game starts or when spawned
void AOn_Hit_Border::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOn_Hit_Border::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOn_Hit_Border::On_Border_Hit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("I Hit: %s"), *OtherActor->GetName()));
		}
	}
}
