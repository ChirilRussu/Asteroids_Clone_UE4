// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "On_Hit_Border.generated.h"

UCLASS()
class ASTEROIDS_CLONE_API AOn_Hit_Border : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOn_Hit_Border();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* Border_Hit_Component;

	UFUNCTION()
	void On_Border_Hit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};


