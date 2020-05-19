// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor_Camera_Class.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFloor_Camera_Class::AFloor_Camera_Class()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloor_Camera_Class::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* The_Ship = UGameplayStatics::GetPlayerController(this, 0);
	The_Ship->SetViewTarget(Floor_Camera);
}

// Called every frame
void AFloor_Camera_Class::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



